#pragma once
#include"log.hpp"
#include"etcd.hpp"
#include"channel.hpp"
#include"user.pb.h"
#include"base.pb.h"
#include<brpc/server.h>
#include"es_data.hpp"
#include"mysql_user.hpp"
#include"redis_data.hpp"
#include"dms.hpp"
namespace MindbniM
{
    class UserServiceImpl : public UserService
    {
    public:
        void UserRegisterReq(google::protobuf::RpcController* controller,const UserRegisterReq* req,UserRegisterRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void UserLogin(google::protobuf::RpcController* controller,const UserLoginReq* req,UserLoginRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void GetPhoneVerifyCode(google::protobuf::RpcController* controller,const PhoneVerifyCodeReq* req,PhoneVerifyCodeRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void PhoneRegister(google::protobuf::RpcController* controller,const PhoneRegisterReq* req,PhoneRegisterRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void PhoneLogin(google::protobuf::RpcController* controller,const PhoneLoginReq* req,PhoneLoginRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void GetUserInfo(google::protobuf::RpcController* controller,const GetUserInfoReq* req,GetUserInfoRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void GetMultiUserInfo(google::protobuf::RpcController* controller,const GetMultiUserInfoReq* req,GetMultiUserInfoRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void SetUserAvatar(google::protobuf::RpcController* controller,const SetUserAvatarReq* req,SetUserAvatarRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void SetUserNickname(google::protobuf::RpcController* controller,const SetUserNicknameReq* req,SetUserNicknameRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void SetUserDescription(google::protobuf::RpcController* controller,const SetUserDescriptionReq* req,SetUserDescriptionRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
        void SetUserPhoneNumber(google::protobuf::RpcController* controller,const SetUserPhoneNumberReq* req,SetUserPhoneNumberRsp* rsp,google::protobuf::Closure* done)
        {
            brpc::ClosureGuard guard(done);
        }
    private:
        UserTable::ptr _usertable;
        ESUser::ptr _esuser;

        Session::ptr _session;
        Status::ptr _status;
        Codes::ptr _codes;

        ServiceManager::ptr _service_manager;

        DMSClient::ptr _dms;
    };

    class UserServer
    {
    public:
        using ptr=std::shared_ptr<UserServer>;
        UserServer(Registry::ptr reg,std::shared_ptr<brpc::Server> rpc):_reg_client(reg),_rpc_server(rpc)
        {}
        void start()
        {
            _rpc_server->RunUntilAskedToQuit();
        }
    private:
        Registry::ptr _reg_client;
        Discovery::ptr _discover;
        std::shared_ptr<brpc::Server> _rpc_server;
        std::shared_ptr<odb::mysql::database> _mysql;
        std::shared_ptr<sw::redis::Redis> _redis;
        std::shared_ptr<elasticlient::Client> _es;
    };
    class UserServerBuild
    {
    public:
        void make_reg_object(const std::string& reg_host,const std::string& service_name,const std::string& service_host)
        {
            _reg_client=std::make_shared<Registry>(reg_host);
            _reg_client->registry(service_name,service_host);
        }
        void make_rpc_server(uint16_t port,int timeout,int thread_num)
        {
            _rpc_server=std::make_shared<brpc::Server>();
            UserServiceImpl* user_service=new UserServiceImpl;
            int ret=_rpc_server->AddService(user_service,brpc::ServiceOwnership::SERVER_OWNS_SERVICE);
            if(ret<0)
            {
                LOG_ROOT_ERROR<<"添加rpc服务失败";
                return ;
            }
            brpc::ServerOptions op;
            op.idle_timeout_sec=timeout;
            op.num_threads=thread_num;
            ret=_rpc_server->Start(port,&op);
            if(ret<0)
            {
                LOG_ROOT_ERROR<<"rpc服务启动失败";
                return ;
            }
        }
        UserServer::ptr newUserServer()
        {
            if(_reg_client==nullptr)
            {
                LOG_ROOT_ERROR<<"未初始化服务注册模块";
                abort();
            }
            if(_rpc_server==nullptr)
            {
                LOG_ROOT_ERROR<<"未初始化rpc服务器";
                abort();
            }
            return std::make_shared<UserServer>(_reg_client,_rpc_server);
        }
    private:
        Registry::ptr _reg_client;
        Discovery::ptr _discover;
        std::shared_ptr<brpc::Server> _rpc_server;
        std::shared_ptr<odb::mysql::database> _mysql;
        std::shared_ptr<sw::redis::Redis> _redis;
        std::shared_ptr<elasticlient::Client> _es;
    };
};