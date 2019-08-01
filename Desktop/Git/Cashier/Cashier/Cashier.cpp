/*
#include<vector>
#include<string>
#include<iostream>
#include"MySQL.h"
using namespace std;


class MySQL
{
public:
MySQL();
bool ConnectMySql(const char* host,// 主机名称
const char* user, // 用户名
const char* passward, // 密码
const char* dbName, // 数据库名
int port=3306); // 端口号：默认为3306
~MySQL();
bool Insert(const string& strSQL);
bool Delete(const string& strSQL);
bool Update(const string& strSQL);
size_t GetCount(const string& strSQL);
vector<vector<string>> Select(const string& strSQL); // 切换数据库
bool SelectDB(const string& daName);
private:
MYSQL* _mySql; // mysql连接的实例对象
std::string _dbName;
vector<string> _tables;
};
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MySQL::MySQL()
{
// 初始化mySql
_mySql = mysql_init(nullptr);
}
bool MySQL::ConnectMySql(const char* host, const char* user, const char* passward, const char* dbName, int port)
{
// 连接mySql数据库
if (!mysql_real_connect(_mySql, host, user, passward, dbName, port,NULL,0))
{
return false;
}
//c++连接mysql时，比如查询语句中含有中文，或者得到结果中含有中文，经常出现编译出错或乱码问 题。
//VS编译器默认使用gbk编码。 如果将mysql设置为utf-8编码，则需要先将c++中的各种中文字符串转为utf-8编码输入mysql，
//得到 的结果为utf-8编码，需要转为gbk才能正常显示。转来转去很麻烦。 
mysql_query(_mySql, "set names 'gbk'");
return true;
	}
	bool MySQL::SelectDB(const string& dbName)
	{
		if (mysql_select_db(_mySql, dbName.c_str()))
		{
			return false;
		}
		return true;
	}
	bool MySQL::Insert(const string& strSql)
	{
		// 执行sql语句
		if (mysql_query(_mySql, strSql.c_str()))
		{
			return false;
		}
		return true;
	}
	bool MySQL::Update(const string& strSQL)
	{
		// 执行sql语句 
		if (mysql_query(_mySql, strSQL.c_str()))
		{
			return false;
		}
		return true;
	}
	vector<vector<string>> MySQL::Select(const string& sql)
	{
		vector<vector<string>> vRet;
		// 指定指定SQL语句 
		if (mysql_query(_mySql, sql.c_str()))
		{
			string vsRet(mysql_error(_mySql));
			return vRet;
		}
		// 检索完整的数据集到客户端 
		MYSQL_RES *res = mysql_store_result(_mySql);
		if (res == NULL)
		{
			return vRet;
		}
		// 用来保存结果集中行的信息 
		MYSQL_ROW rows;
		// 结果集中总共有多少行数据 
		int num_fields = mysql_num_fields(res);
		while (rows = mysql_fetch_row(res))
		{
			int i = 0; vector<string> vItem;
			vItem.resize(num_fields);
			for (i = 0; i < num_fields; i++)
			{
				vItem[i] = rows[i];
			}
			vRet.push_back(vItem);
		}
		const char* str = mysql_error(_mySql);
		mysql_free_result(res); return vRet;
	}
	size_t MySQL::GetCount(const string& strSQL)
	{
		// 指定指定SQL语句 
		if (mysql_query(_mySql, strSQL.c_str()))
		{
			return 0;
		}
		// 检索完整的数据集到客户端 
		MYSQL_RES *res = mysql_store_result(_mySql);
		if (res == NULL)
		{
			return 0;
		}
		return mysql_num_fields(res);
	}
	bool MySQL::Delete(const string& strSQL)
	{
		// 执行sql语句 
		if (mysql_query(_mySql, strSQL.c_str()))
		{
			return false;
		}
		return true;
	}
	MySQL::~MySQL()
	{
		mysql_close(_mySql);
	}


	int main()
	{
		cout << sizeof(char*) << endl;
		return 0;
	}
*/




#include"Winsock2.h"
#include "MySQL.h"
#include<iostream>
using namespace std;

MySQL::MySQL(){
	_mySQL = mysql_init(nullptr);
}
bool MySQL::ConnectMySQL(const char* host, const char* user, const char* passward, const char* dbname){
	if (!mysql_real_connect(_mySQL, host, user, passward, dbname, 3306, nullptr, 0))
	{
		cout << "数据库连接失败" << endl;
		return false;
	}
	/*
	第一个参数：本地连接（初始化的返回值）
	第二个参数：用户名（本地连接）
	第三个参数：密码（用户名）
	第四个参数：当前数据库名字
	第五个参数：端口号
	第六个参数：套接字（用不到）
	第七个参数：客户端方式（用不到）

	c++连接mysql时，比如查询语句中含有中文，或者得到结果中含有中文，经常出现编译出错或乱码问 题。
	VS编译器默认使用gbk编码。 如果将mysql设置为utf-8编码，则需要先将c++中的各种中文字符串转为utf-8编码输入mysql，
	得到 的结果为utf-8编码，需要转为gbk才能正常显示。转来转去很麻烦。
	*/
	mysql_query(_mySQL, "set names 'gbk'");
	return true;
}

vector<vector<string>> MySQL::Select(const string& strSQL){
	vector<vector<string>> vvRet;
	if (mysql_query(_mySQL, strSQL.c_str())){
		//SQL响应失败
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	//获取查询的记录
	MYSQL_RES * mySQLRes = mysql_store_result(_mySQL);
	if (nullptr == mySQLRes){
		cout << mysql_error(_mySQL) << endl;
		return vvRet;
	}
	//获取记录中的多少个字段e
	int itemCount = mysql_num_fields(mySQLRes);
	MYSQL_ROW mysqlRow;
	while (mysqlRow = mysql_fetch_row(mySQLRes)){
		//获取一行内容
		vector<string> vItem;
		for (size_t i = 0; i < itemCount; ++i){
			vItem.push_back(mysqlRow[i]);
		}
		vvRet.push_back(vItem);
	}
	mysql_free_result(mySQLRes);
	return vvRet;
}

bool MySQL::Insert(const string& strSQL){
	if (mysql_query(_mySQL, strSQL.c_str())){
		//SQL响应失败
		cout << mysql_error(_mySQL) << endl;
		return false;
	}
	return true;
}
MySQL::~MySQL(){

}
