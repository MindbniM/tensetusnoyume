[toc]

---
# 前言
&nbsp;&nbsp;&nbsp;&nbsp;协程（Coroutine）是一种"轻量级线程, 用户态线程"，允许在执行过程中暂停和恢复执行，从而实现更加灵活的控制流程。与线程不同，协程在用户空间由程序自身调度，不需要操作系统的调度器介入, 我们使用ucontext实现一个简单的协程类
# 协程基础知识
## 协程上下文
&nbsp;&nbsp;&nbsp;&nbsp;协程则可以执⾏到⼀半就退出（称为yield），但此时协程并未真正结束，只是暂时让出CPU执⾏权，在后⾯适当的时机协程可以重新恢复运⾏（称为resume），在这段时间⾥其他的协程可以获得CPU并运⾏, 协程能够半路yield、再重新resume的关键是协程存储了函数在yield时间点的执⾏状态，这个状态称为协程上下⽂
## 对称协程与⾮对称协程
&nbsp;&nbsp;&nbsp;&nbsp;对称协程，协程可以不受限制地将控制权交给任何其他协程。任何⼀个协程都是相互独⽴且平等的，调度权可以在任意协程之间转移。
&nbsp;&nbsp;&nbsp;&nbsp;⾮对称协程，是指协程之间存在类似堆栈的调⽤⽅-被调⽤⽅关系。协程出让调度权的⽬标只能是它的调⽤者
## 有栈协程与⽆栈协程
- **有栈协程**：⽤独⽴的执⾏栈来保存协程的上下⽂信息。当协程被挂起时，栈协程会保存当前执⾏状态（例如函数调⽤栈、局部变量等），并将控制权交还给调度器。当协程被恢复时，栈协程会将之前保存的执⾏状态恢复，从上次挂起的地⽅继续执⾏。类似于内核态线程的实现，不同协程间切换还是要切换对应的栈上下⽂，只是不⽤陷⼊内核⽽已
- **⽆栈协程**：它不需要独⽴的执⾏栈来保存协程的上下⽂信息，协程的上下⽂都放到公共内存中，当协程被挂起时，⽆栈协程会将协程的状态保存在堆上的数据结构中，并将控制权交还给调度器。当协程被恢复时，⽆栈协程会将之前保存的状态从堆中取出，并从上次挂起的地⽅继续执⾏。协程切换时，使⽤状态机来切换，就不⽤切换对应的上下⽂了，因为都在堆⾥的。⽐有栈协程都要轻量许多
# ucontext库
## 接口熟悉
``` cpp
typedef struct ucontext_t {
 // 当前上下⽂结束后，下⼀个激活的上下⽂对象的指针，只在当前上下⽂是由makecontext创建时有效
 struct ucontext_t *uc_link;
 // 当前上下⽂的信号屏蔽掩码
 sigset_t uc_sigmask;
 // 当前上下⽂使⽤的栈内存空间，只在当前上下⽂是由makecontext创建时有效
 stack_t uc_stack;
 // 平台相关的上下⽂具体内容，包含寄存器的值
 mcontext_t uc_mcontext;
 ...
} ucontext_t;
// 获取当前的上下⽂
int getcontext(ucontext_t *ucp);
// 恢复ucp指向的上下⽂，这个函数不会返回，⽽是会跳转到ucp上下⽂对应的函数中执⾏，相当于变相调⽤了函数, 但这东西不会在函数结束后跳转设定的uc_link
int setcontext(const ucontext_t *ucp);
// 修改由getcontext获取到的上下⽂指针ucp，将其与⼀个函数func进⾏绑定，⽀持指定func运⾏时的参数，
// 在调⽤makecontext之前，必须⼿动给ucp分配⼀段内存空间，存储在ucp->uc_stack中，这段内存空间将作为func函数运⾏时的栈空间，
// 同时也可以指定ucp->uc_link，表示函数运⾏结束后恢复uc_link指向的上下⽂，
// 如果不赋值uc_link，那func函数结束时必须调⽤setcontext或swapcontext以重新指定⼀个有效的上下⽂，否则程序就跑⻜了
// makecontext执⾏完后，ucp就与函数func绑定了，调⽤setcontext或swapcontext激活ucp时，func就会被运⾏
void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...);
// 恢复ucp指向的上下⽂，同时将当前的上下⽂存储到oucp中，
// swapcontext也不会返回，⽽是会跳转到ucp上下⽂对应的函数中执⾏，相当于调⽤了函数, 在函数返回后, 回自动跳转设定的uc_link的上下文
int swapcontext(ucontext_t *oucp, const ucontext_t *ucp);
```
## 一个简单的函数切换
&nbsp;&nbsp;&nbsp;&nbsp;我们可以使用ucontext库变相调用函数
``` cpp
#include <iostream>
#include <ucontext.h>
#include <cstdlib>
using namespace std;

ucontext_t _main;
ucontext_t f;

void func() {
    cout << "func" << endl;
}
void FiberCreate(ucontext_t* f, void (*func)(), ucontext_t* next) {
    getcontext(f);
    void* s = malloc(1024 * 1024);  // 分配堆栈
    f->uc_stack.ss_sp = s;
    f->uc_stack.ss_size = 1024 * 1024;
    f->uc_link = next;  // 设置返回上下文为 next
    makecontext(f, func, 0);  // 设定函数
}
int main() {
    // 初始化 main 上下文
    getcontext(&_main);
    //设定返回main函数的上下文
    FiberCreate(&f, func, &_main);
    // 切换到 f
    swapcontext(&_main, &f);
    cout << "Main" << endl;

    free(f.uc_stack.ss_sp);
    return 0;
}

```
## 自动调用
&nbsp;&nbsp;&nbsp;&nbsp;根据swapcontext会使得函数自动跳转设定的上下文, 我们可以设定一定的调用逻辑, **小心程序跑飞**
``` cpp
#include <iostream>
#include <ucontext.h>
#include <cstdlib>
using namespace std;

ucontext_t _main;
ucontext_t f1, f2, f3, f4;

void func001() {
    cout << "func001" << endl;
}
void func002() {
    cout << "func002" << endl;
}
void func003() {
    cout << "func003" << endl;
}
void func004() {
    cout << "func004" << endl;
}
void FiberCreate(ucontext_t* f, void (*func)(), ucontext_t* next) {
    getcontext(f);
    void* s = malloc(1024 * 1024);  // 分配堆栈
    f->uc_stack.ss_sp = s;
    f->uc_stack.ss_size = 1024 * 1024;
    f->uc_link = next;  // 设置返回上下文为 next
    makecontext(f, func, 0);  // 设定函数
}

int main() {
    // 初始化 main 上下文
    getcontext(&_main);
    FiberCreate(&f1, func001, &f2);
    FiberCreate(&f2, func002, &f3);
    FiberCreate(&f3, func003, &f4);
    FiberCreate(&f4, func004, &_main);  // f4 结束后返回 main
    // 切换到 f1
    swapcontext(&_main, &f1);
    cout << "Main" << endl;

    free(f1.uc_stack.ss_sp);
    free(f2.uc_stack.ss_sp);
    free(f3.uc_stack.ss_sp);
    free(f4.uc_stack.ss_sp);
    return 0;
}

```
# 协程类的实现
&nbsp;&nbsp;&nbsp;&nbsp;掌握上述基础后我们就可以实现一个简单的协程类了
**具体实现介绍**
- 无栈协程: 实现的是无栈协程, 协程的上下文保存在堆上
- 非对称协程: 实现的是非对称协程, 协程间不能自由切换, 必须和主协程交替切换
- 使用智能指针管理: 每一个协程对象都只能从堆上new, 继承std::enable_shared_from_this方便获得this的智能指针对象
[完整代码](https://github.com/MindbniM/Linux-Codelab/tree/main/Fiber)
## 接口
``` cpp
class Fiber : public std::enable_shared_from_this<Fiber>
{
public:
    using func_t=std::function<void()>;
    using ptr=std::shared_ptr<Fiber>;
    enum class state
    {
        INIT,   //初始化
        HOLD,   //挂起
        EXEC,   //运行
        TERM,   //结束
        READY,  //就绪
    };
public:
    Fiber(func_t cb,bool isrunInSchedule=true,uint32_t stack_size=128*1024);
    ~Fiber();
    //重置协程函数,重置状态INIT/TERM,复用栈空间
    void reset(func_t cb);
    //切换到当前协程运行
    void swapIn();
    //切换到后台运行
    void swapOut();
    //调用协程
    void call();
    //获取协程状态
    state getState(){ return m_s;}
public:
    //设置一个协程为当前协程
    static void SetThis(Fiber*f);
    //获取当前执行协程的智能指针
    static Fiber::ptr Get_this();
    //当前运行协程切换到后台, 并设置为Ready状态
    static void YeildtoReady();
    //当前运行协程切换到后台, 并设置为Hold状态
    static void YeildtoHold();
    //获取总协程数
    static uint64_t GetFiberNum();
    //协程执行的方法, 会在这里面执行回调函数
    static void MainFunc();
private:
    //用于创建主协程
    Fiber();
private:
    uint64_t m_id=0;            //协程id
    uint32_t m_stack_size=0;    //协程栈空间大小
    ucontext_t m_ctx;           //协程上下文
    void* m_stack=nullptr;      //协程使用的栈
    state m_s=state::INIT;      //协程状态
    func_t m_cb;                //协程具体回调
    bool m_runInSchedule;       //是否参与调度器调度
};
```
## 全局变量
``` cpp
//协程id
std::atomic<uint64_t> s_fiber_id(0);
//协程数量
std::atomic<uint64_t> s_fiber_num(0);
```
## 线程局部变量
&nbsp;&nbsp;&nbsp;&nbsp;每个线程记录自己的主协程和正在调度的协程, 方便切换
``` cpp
//线程当前执行的协程
thread_local Fiber* t_fiber=nullptr;
//线程的主协程
thread_local Fiber::ptr t_thread_fiber=nullptr;//using Fiber::ptr=std::shared_ptr<Fiber>;
```
## malloc封装
&nbsp;&nbsp;&nbsp;&nbsp;方便后面扩展内存申请方式或者使用内存池
``` cpp
class MallocStackAllocator
{
public:
static void* Alloc(size_t size) {
    return malloc(size);
}
static void Dealloc(void* vp, size_t size) {
    return free(vp);
}
};
```
## 协程切换
``` cpp
//切换到该协程执行
void Fiber::swapIn()
{
    SetThis(this);
    swapcontext(&t_thread_fiber->m_ctx,&m_ctx);
}   
//该协程切换到后台运行
void Fiber::swapOut()
{   
    SetThis(t_thread_fiber.get());
    swapcontext(&m_ctx,&t_thread_fiber->m_ctx);
}       
//手动调用协程, 需要提前自己先切换到主协程
void Fiber::call()
{
    m_s=state::EXEC;
    swapcontext(&t_thread_fiber->m_ctx,&m_ctx);
}
//切换回主协程并设置READY状态
void Fiber::YeildtoReady()
{
    Fiber::ptr p=Get_this();
    p->m_s=state::READY;
    p->swapOut();
}
//切换回主协程并设置HOLD状态
void Fiber::YeildtoHold()
{
    Fiber::ptr p=Get_this();
    p->m_s=state::HOLD;
    p->swapOut();
}
```

## 构造函数
``` cpp
Fiber::Fiber(func_t cb,bool isrunInSchedule,uint32_t stack_size):m_id(s_fiber_id++),m_stack_size(stack_size),m_cb(cb),m_runInSchedule(isrunInSchedule)                              
{   
    //协程数量增加
    ++s_fiber_num;
    //分配协程栈空间
    m_stack=StackAllocator::Alloc(m_stack_size);
    //初始化上下文
    getcontext(&m_ctx);
    m_ctx.uc_link=nullptr;
    m_ctx.uc_stack.ss_sp=m_stack;
    m_ctx.uc_stack.ss_size=m_stack_size;
    makecontext(&m_ctx,&Fiber::MainFunc,0);
    LOG_ROOT_INFO("create Fiber id:%d",m_id);//日志
}
//获取当前协程的智能指针
Fiber::ptr Fiber::Get_this()
{
    if(t_fiber!=nullptr)
    {
        //返回当前协程的指针指针对象
        return t_fiber->shared_from_this();
    }
    //如果当前线程没有协程, 就创建一个主协程
    Fiber::ptr main_fiber(new Fiber);
    t_thread_fiber=main_fiber;
    return main_fiber->shared_from_this();
}
//私有构造, 只用于创建主协程, 主协程不需要申请堆空间
Fiber::Fiber()
{
    SetThis(this);
    getcontext(&m_ctx);
    m_s=state::EXEC;
    m_id=s_fiber_id;
    ++s_fiber_num;
    ++s_fiber_id;
    LOG_ROOT_INFO("create main Fiber id:%d",m_id);
}

```
## 协程执行的方法
``` cpp
void Fiber::MainFunc()
{
    //获取当前协程的智能指针
    Fiber::ptr p=Get_this();
    //执行回调, 执行完后清理
    p->m_cb();
    p->m_cb=nullptr;
    p->m_s=state::TERM;
    auto cur=p.get();
    //之前获取了当前协程的智能指针, 现在手动让计数器--
    p.reset();
    //切换回主协程
    cur->swapOut();
}
```
# 测试
&nbsp;&nbsp;&nbsp;&nbsp;当然我们的协程总不能自己手动调来调去, 我们还需要协程调度器(关注后面的文章)
## 协程切换
&nbsp;&nbsp;&nbsp;&nbsp;看看能不能跑, 先简单使用一下
``` cpp
#include<iostream>
#include"Fiber.hpp"
using namespace MindbniM;
void func1()
{
    std::cout<<"func1"<<std::endl;
}
void func2()
{
    std::cout<<"func2"<<std::endl;
}
void func3()
{
    std::cout<<"func3"<<std::endl;                                                                                                      
}                         
int main()                
{                         
    //首先创建主协程      
    Fiber::Get_this();    
    Fiber::ptr f1=std::make_shared<Fiber>(func1);
    Fiber::ptr f2=std::make_shared<Fiber>(func2);
    Fiber::ptr f3=std::make_shared<Fiber>(func3);
    //切换到f1
    f1->swapIn();
    //切换到f2
    f2->swapIn();
    //切换到f3
    f3->swapIn();
    return 0;
}
```
## 手动切换+复用
&nbsp;&nbsp;&nbsp;&nbsp;协程一个优势就能可以复用空间
``` cpp
#include<iostream>
#include"Fiber.hpp"
using namespace MindbniM;
void func1()
{
    std::cout<<"func1"<<std::endl;
}
void func2()
{
    std::cout<<"func2"<<std::endl;
}
void func3()
{
    std::cout<<"func3"<<std::endl;
}
int main()
{
    //首先创建主协程
    Fiber::Get_this();
    Fiber::ptr f1=std::make_shared<Fiber>(func1);
    //试试手动切换
    //切换到f1
    Fiber::SetThis(f1.get());
    //执行f1
    f1->call();
    //切换回主协程
    f1->swapOut();
    //复用f1的空间
    f1->reset(func2);
    f1->swapIn();
    f1->reset(func3);
    f1->swapIn();
    return 0;
}
```







