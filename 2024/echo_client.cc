#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>
#include "echo.pb.h"
int main()
{
    brpc::Channel ch;
    ch.Init("127.0.0.1:8848",nullptr);
    example::EchoService_Stub stub(&ch);
    while(1)
    {
        example::EchoRequest request;
        example::EchoResponse response;
        brpc::Controller ctl;
        request.set_message("111");
        stub.Echo(&ctl,&request,&response,nullptr);
        std::cout<<response.message()<<std::endl;
        sleep(1);
    }
    return 0;
}
