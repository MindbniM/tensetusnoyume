#include <iostream>
#include <vector>
#include <string>
#include<elasticlient/client.h>
#include<cpr/cpr.h>
using namespace std;

int main() 
{
    elasticlient::Client cl({"http://127.0.0.1:9200/"});
    std::string search_body = R"({"query": { "match_all": {} } })";
    try
    {
        cpr::Response re=cl.search("user","_doc",search_body);
        cout<<re.status_code<<endl;
        cout<<re.text<<endl;
    }
    catch(std::exception& ex)
    {
        cout<<"请求失败"<<ex.what()<<endl;
        return -1;
    }
    return 0;
}

