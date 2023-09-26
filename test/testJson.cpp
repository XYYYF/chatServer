#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";
    
    return js.dump();
    //cout << sendBuf.c_str() << endl;
}

//json序列化示例2
string func2()
{
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello china"}, {"liu shuo", "hello world"}};

    return js.dump();
}

//json序列化示例3
string func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    return js.dump();
}

int main()
{
    string recvBuf = func1();
    json jsBuf = json::parse(recvBuf);
    cout << jsBuf["msg_type"] << endl;
    cout << jsBuf["from"] << endl;
    cout << jsBuf["to"] << endl;
    cout << jsBuf["msg"] << endl;
    cout << jsBuf["error"] << endl;

    cout << "------------" << endl;

    string recvBuf1 = func2();
    json jsBuf1 = json::parse(recvBuf1);
    cout << jsBuf1["id"] << endl;
    auto arr = jsBuf1["id"];
    cout << arr[2] << endl;

    auto msgjs = jsBuf1["msg"];
    cout << msgjs["zhang san"] << endl;
    cout << msgjs["liu shuo"] << endl;
    cout << msgjs["xiao bai"] << endl;

    cout << "------------" << endl;

    string recvBuf2 = func3();
    json jsBuf2 = json::parse(recvBuf2);
    vector<int> vec = jsBuf2["list"];
    for(auto num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    map<int,string> map = jsBuf2["path"];
    for(auto &p : map)
    {
        cout << p.first << " " << p.second;
    }
    cout << endl;

    return 0;
}