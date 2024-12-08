# 前言
&nbsp;&nbsp;&nbsp;&nbsp;gflags与gtest是谷歌开源的框架, gflags是一个命令行标志处理库，用于解析和管理程序的命令行选项, gtest是测试框架, 用于编写单元测试
# gflags
&nbsp;&nbsp;&nbsp;&nbsp;gflags在我们的项目之中用于各种配置参数的处理, 比如各个服务的访问地址, 一些组件的配置, 使用gflags可以避免每次更改都要重新编译
## gflags的安装
&nbsp;&nbsp;&nbsp;&nbsp;可直接使用包管理工具安装, 也可源码安装
1. **使用包管理工具安装**
Ubuntu中可以
``` sh
apt-get install libgflags-dev
```
2. **使用源码安装**
先下载源码
``` sh
git clone https://github.com/gflags/gflags.git
```
使用cmake编译安装
``` sh
cd gflags
mkdir build
cd build
cmake ..
make
make install
```
然后系统库目录下应该就有gflags
``` sh
$ ls /usr/include/ | grep gflags
gflags
```
## gflags的使用 
&nbsp;&nbsp;&nbsp;&nbsp;使用gflags主要包含头文件<gflags/gflags.h>
我们可以使用gflags来解析命令行参数
**一个简单的示例**
``` cpp
#include<iostream>
#include<gflags/gflags.h>
using namespace std;
//使用DEFINE_type(name,value,text)可定义命令行参数, 比如下面这个就定义了一个类型为string 的str
DEFINE_string(str,"这是str","");
int main(int argc,char** argv)
{
    //解析命令行参数,前两个为main函数参数
    //第三个参数（remove_flags）：
    //如果设置为 true，则在解析完成后会从 argv 中移除已经识别的命令行标志，只保留未解析的参数。
    //如果设置为 false，则 argv 中的所有参数都会被保留，即使它们已经被解析为标志。
    //建议设置为true
    gflags::ParseCommandLineFlags(&argc,&argv,true);
    //使用FLAGS_name来使用这些参数
    cout<<FLAGS_str<<endl;
    return 0;
}
```
编译运行, 如果不指名就会用默认的值
``` sh
$ g++ test.cpp -o test -lgflags
$ ./test
这是str
```
可以指名值
``` sh
$ ./test -str="这不是str"
这不是str
```
当然 gfalgs还支持很多类型
``` cpp
DEFINE_bool
DEFINE_int32
DEFINE_int64
DEFINE_uint64
DEFINE_double
DEFINE_string
```
## 配置文件
&nbsp;&nbsp;&nbsp;&nbsp;当参数过多时, 我们可以用配置文件来更方便的设置参数
**示例**
test.cpp文件
``` cpp
#include<iostream>
#include<gflags/gflags.h>
using namespace std;
DEFINE_string(name,"zhangsan","");
DEFINE_int32(age,18,"");
DEFINE_string(desc,"这是一个人","");
int main(int argc,char** argv)
{
    gflags::ParseCommandLineFlags(&argc,&argv,true);
    cout<<FLAGS_name<<endl;
    cout<<FLAGS_age<<endl;
    cout<<FLAGS_desc<<endl;
    return 0;
}
```
test.config文件
``` txt
--name=lisi
--age=25
--desc=这是另一个人
```
直接运行
``` sh
$ ./test 
zhangsan
18
这是一个人
```
使用配置文件 --flagfile选项
``` sh
$ ./test --flagfile=test.config
lisi
25
这是另一个人
```
# gtest
&nbsp;&nbsp;&nbsp;&nbsp;gtest在我们的项目中主要用于测试, gtest提供的单元测试和断言功能简单好用
## gtest的安装
&nbsp;&nbsp;&nbsp;&nbsp;可直接使用包管理工具安装, 也可源码安装
1. **使用包管理工具安装**
Ubuntu中可以
``` sh
apt-get install libgtest-dev
```
2. **使用源码安装**
先下载源码
``` sh
git clone https://github.com/google/googletest.git
```
使用cmake编译安装
``` sh
cd googletest
mkdir build
cd build
cmake ..
make
make install
```
然后系统库目录下应该就有gtest
``` sh
$ ls /usr/include/ | grep gtest
gtest
```
## gtest的使用
&nbsp;&nbsp;&nbsp;&nbsp;使用gtest主要包含头文件<gtest/gtest.h>
**一个简单的示例**
``` cpp
#include<iostream>
#include <gtest/gtest.h>
//比如测试一个反转字符串的函数
std::string reverseStr(const std::string& str)
{
    int i=0;
    int n=str.size();
    std::string ret(str);
    while(i<n/2)
    {
        std::swap(ret[i],ret[n-i-1]);
    }
    return str;
}
TEST(StringTest,oddnumber ) {
    //这个宏判断两个值是否相等
    EXPECT_EQ(reverseStr("123"),"321");
}

TEST(SampleTest, evennumber) {
    EXPECT_EQ(reverseStr("1234"),"4321");
}

int main(int argc, char **argv) {
    //初始化
    testing::InitGoogleTest(&argc, argv);
    //开始测试
    return RUN_ALL_TESTS();
}
```
编译运行
``` sh
$ g++ test.cpp -o test -lgtest -lpthread
$ ./test 
[==========] Running 2 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from StringTest
[ RUN      ] StringTest.oddnumber
```
可见这两个测试都过了, 现在我们修改代码, 使其不正常
``` sh
$ ./test 
[==========] Running 2 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 1 test from StringTest
[ RUN      ] StringTest.oddnumber
test.cpp:12: Failure
Expected equality of these values:
  reverseStr("123")
    Which is: "123"
  "321"
[  FAILED  ] StringTest.oddnumber (0 ms)
[----------] 1 test from StringTest (0 ms total)

[----------] 1 test from SampleTest
[ RUN      ] SampleTest.evennumber
test.cpp:16: Failure
Expected equality of these values:
  reverseStr("1234")
    Which is: "1234"
  "4321"
[  FAILED  ] SampleTest.evennumber (0 ms)
[----------] 1 test from SampleTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 0 tests.
[  FAILED  ] 2 tests, listed below:
[  FAILED  ] StringTest.oddnumber
[  FAILED  ] SampleTest.evennumber

 2 FAILED TESTS
```
我们可以从中快速定位哪个测试没通过
### 断言
&nbsp;&nbsp;&nbsp;&nbsp;gtest提供了很多的断言来验证测试结果是否符合预期, 下面举例出一些非致命断言
基本断言
```
EXPECT_EQ	验证两个值是否相等。
EXPECT_NE	验证两个值是否不相等。
EXPECT_LT	验证左值是否小于右值。
EXPECT_LE	验证左值是否小于等于右值。
EXPECT_GT	验证左值是否大于右值。
EXPECT_GE	验证左值是否大于等于右值。
```
布尔断言
```
EXPECT_TRUE	验证表达式是否为 true。
EXPECT_FALSE	验证表达式是否为 false。
```
字符串断言
```
EXPECT_STREQ	验证两个 C 字符串是否相等。
EXPECT_STRNE	验证两个 C 字符串是否不相等。
EXPECT_STRCASEEQ	验证两个字符串在忽略大小写时是否相等。
EXPECT_STRCASENE	验证两个字符串在忽略大小写时是否不相等。
```
异常断言
```
EXPECT_THROW	验证表达式抛出指定类型的异常。
EXPECT_NO_THROW	验证表达式未抛出任何异常。
EXPECT_ANY_THROW	验证表达式抛出任意异常。
```



