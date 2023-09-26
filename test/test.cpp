#include "muduo/net/EventLoop.h"
#include "muduo/net/TcpServer.h"
#include <functional>
#include <iostream>

using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

/**
 * 1. 创建TcpServer对象
 * 2. 创建EventLoop事件循环对象指针
 * 3. 根据TcpServer的构造函数 确定 chatServer的构造函数
 * 4. 在类中注册 创建用户连接 和 处理读写事件 的回调函数
 * 5. 设置合适的服务端线程数量，muduo库会自动分配IO线程和worker线程
 * 6. 开启事件循环
 * 
**/
class chatServer
{
public:
    chatServer(EventLoop *loop,                                 // 事件循环
                const InetAddress &listenAddr,                  // IP + Port
                const string &nameArg)                          // 服务器的名字
            : _server(loop,listenAddr,nameArg), _loop(loop)
    {
        // 注册创建用户线程
        _server.setConnectionCallback(std::bind(&chatServer::onConnection,this,_1));

        // 注册处理读写事件线程
        _server.setMessageCallback(std::bind(&chatServer::onMessage,this,_1,_2,_3));

        //设置服务器的线程数量 1个IO线程  3个worker线程
        _server.setThreadNum(4);

    }

    //开启事件循环
    void start()
    {
        _server.start();
    }
private:
    // 处理用户的连接创建和断开
    void onConnection(const TcpConnectionPtr &conn)
    {
        if(conn->connected())
        {
            cout << conn->peerAddress().toIpPort() << " -> " << conn->localAddress().toIpPort() << " start::online" << endl;
        }
        else
        {
            cout << conn->peerAddress().toIpPort() << " -> " << conn->localAddress().toIpPort() << " start::offline " << endl;
            conn->shutdown();   //close(fd);
            // _loop->quit();
        }
    }

    // 处理读写事件 epoll listenfd accept
    void onMessage(const TcpConnectionPtr &conn,   // 连接
                    Buffer *buffer,                // 缓存区
                    Timestamp time)             // 接收到数据的时间信息
    {
        string buf = buffer->retrieveAllAsString();
        cout << "recv data:" << buf << " time: " << time.toString() << endl;
        conn->send(buf);
    }

    TcpServer _server;
    EventLoop *_loop;
};

int main()
{
    EventLoop loop; // epoll
    InetAddress addr("127.0.0.1",6000);
    chatServer server(&loop,addr,"chatServer");

    server.start();   // listenfd epoll_ctl -> epoll
    loop.loop();      // epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件等

    return 0;
}
