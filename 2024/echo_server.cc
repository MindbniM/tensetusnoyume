#include <iostream>
#include <vector>
#include <string>
#include "echo.pb.h"
#include<brpc/server.h>
using namespace std;

namespace example
{
    class Server : public EchoService
    {
    public:
        virtual ~Server()
        {}
        virtual void Echo(::google::protobuf::RpcController* controller,const ::example::EchoRequest* request,::example::EchoResponse* response, ::google::protobuf::Closure* done)override
        {
            brpc::ClosureGuard cntl(done);
            response->set_message(request->message());
        }
};

}
int main()
{
    brpc::Server bser;
    example::Server ser;
    bser.AddService(&ser,brpc::SERVER_DOESNT_OWN_SERVICE);
    butil::EndPoint point;
    butil::str2endpoint("0.0.0.0:8848",&point);
    brpc::ServerOptions op;
    bser.Start(point,&op);
    bser.RunUntilAskedToQuit();
    return 0;
}

