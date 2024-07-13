#include<winsock2.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
const string serverip="47.121.132.64";
uint16_t port=8848;
SOCKET listenfd;
struct sockaddr_in server;
int main()
{
    WSADATA w;
    int ret=WSAStartup(MAKEWORD(2,2),&w);
    if(ret!=0)
    {
        cout<<"wsastartup error"<<endl;
        return 1;
    }
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd==INVALID_SOCKET)
    {
        cout<<"socket error"<<endl;
        WSACleanup();
        return 1;
    }
    listen(listenfd,16);
    server.sin_family=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=inet_addr(serverip.c_str());
    int n=connect(listenfd,(struct sockaddr*)&server,sizeof(server));
    if(n==SOCKET_ERROR)
    {
        cout<<"connect error"<<endl;
        WSACleanup();
        return 1;
    }
    while(1)
    {
        string str;
        getline(cin,str);
        if(str=="quit") break;
        int n=send(listenfd,str.c_str(),str.size(),0);
        if(n>0)
        {
            char buff[1024]={0};
            int n=recv(listenfd,buff,sizeof(buff)-1,0);
            if(n>0)
            {
                cout<<buff<<endl;
            }
        }
    }
    return 0;
}