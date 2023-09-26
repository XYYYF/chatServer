#include "db.h"

#include <muduo/base/Logging.h>

// 数据库配置信息
static string server = "localhost";
static string user = "root";
static string password = "123456";
static string dbname = "chat";

// 初始化数据库连接
MySQL::MySQL()
{
    _conn = mysql_init(nullptr);
}
// 释放数据库连接
MySQL::~MySQL()
{
    if(_conn != nullptr)
    {
        mysql_close(_conn);
        LOG_INFO << "destroy close success!";
    }
    else
    {
        LOG_INFO << "destroy close fail";
    }
}
// 连接数据库
bool MySQL::connect()
{
    MYSQL *p = mysql_real_connect(_conn,server.c_str(),user.c_str(),
                password.c_str(),dbname.c_str(),3306,nullptr,0);
    // 连接成功
    if(p != nullptr)
    {
        // 设置代码支持中文
        mysql_query(_conn,"set names gbk");
        LOG_INFO << "connect database success";
    }
    else
    {
        LOG_INFO << "connect database fail";
    }
    return p;
}
// 更新操作
bool MySQL::update(string sql)
{
    if(mysql_query(_conn,sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" <<sql << "update fail";
        return false;
    }
    LOG_INFO << "update success";
    return true;
}
// 查询操作
MYSQL_RES* MySQL::query(string sql)
{
    if(mysql_query(_conn,sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":" << sql << "query fail";
        return nullptr;
    }
    LOG_INFO << "query success";
    return mysql_use_result(_conn);
}

// 获取连接
MYSQL* MySQL::getConnection()
{
    return _conn;
}