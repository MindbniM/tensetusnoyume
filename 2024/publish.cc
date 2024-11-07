#include<ev.h>
#include<amqpcpp.h>
#include<amqpcpp/libev.h>
#include<openssl/ssl.h>
#include<openssl/opensslv.h>
int main()
{
    //实例化事件监控句柄
    auto* p=EV_DEFAULT;
    //将amp与事件监控关联起来
    AMQP::LibEvHandler handler(p);
    //实例化链接
    AMQP::Address addr("amqp://root:pin0014,.tx3@127.0.0.1:5672");
    AMQP::TcpConnection con(&handler,addr);
    //实例化信道
    AMQP::TcpChannel channel(&con);
    //声明交换机
    channel.declareExchange("test-exchange",AMQP::ExchangeType::direct).onError([](const char* message){std::cout<<"交换机创建失败"<<std::endl;}).onSuccess([](){std::cout<<"交换机创建成功"<<std::endl;});
    //声明队列
    channel.declareQueue("test-queue").onError([](const char* message){std::cout<<"队列创建失败"<<std::endl;}).onSuccess([](){std::cout<<"队列创建成功"<<std::endl;});
    //绑定交换机和队列
    channel.bindQueue("test-exchange","test-queue","key").onError([](const char* message){std::cout<<"绑定失败"<<std::endl;}).onSuccess([](){std::cout<<"绑定成功"<<std::endl;});
    for(int i=0;i<10;i++)
    {
        std::string str="hello"+std::to_string(i);
        bool ret=channel.publish("test-exchange","key",str);
        if(!ret)
        {
            std::cout<<"发送失败"<<std::endl;
        }
    }
    ev_run(p);
    return 0;
}
