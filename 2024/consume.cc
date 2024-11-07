#include<ev.h>
#include<amqpcpp.h>
#include<amqpcpp/libev.h>
#include<openssl/ssl.h>
#include<openssl/opensslv.h>
void callback(AMQP::TcpChannel* chann, const AMQP::Message& mess,uint64_t tag,bool re)
{
     std::string body;
     body.assign(mess.body(),mess.bodySize());
     std::cout<<body<<std::endl;
     chann->ack(tag);
}
int main()
{
    //实例化事件监控句柄
    auto* p=EV_DEFAULT;
    //将amp与事件监控关联起来
    AMQP::LibEvHandler hander(p);
    //实例化链接
    AMQP::Address addr("amqp://root:pin0014,.tx3@127.0.0.1:5672");
    AMQP::TcpConnection con(&hander,addr);
    //实例化信道
    AMQP::TcpChannel channel(&con);
    //声明交换机
    channel.declareExchange("test-exchange",AMQP::ExchangeType::direct).onError([](const char* message){std::cout<<"交换机创建失败"<<std::endl;exit(0);}).onSuccess([](){std::cout<<"交换机创建成功"<<std::endl;});
    //声明队列
    channel.declareQueue("test-queue").onError([](const char* message){std::cout<<"队列创建失败"<<std::endl;exit(0);}).onSuccess([](){std::cout<<"队列创建成功"<<std::endl;});
    //绑定交换机和队列
    channel.bindQueue("test-exchange","test-queue","key").onError([](const char* message){std::cout<<"绑定失败"<<std::endl;exit(0);}).onSuccess([](){std::cout<<"绑定成功"<<std::endl;});
    //订阅
    auto call =std::bind(callback,&channel,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
    channel.consume("test-queue","consume-tag").onReceived(call).onError([](const char* message){std::cout<<"订阅失败"<<std::endl;exit(0);}).onSuccess([](){std::cout<<"订阅成功"<<std::endl;});

    ev_run(p);
    return 0;
}
