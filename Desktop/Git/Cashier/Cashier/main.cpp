#include <iostream>
using namespace std;

#include"MySQL.h"


int main()
{
	mysql_init(nullptr);
	MySQL mysql;
	mysql.ConnectMySQL("localhost", "root", "123", "sell");
	vector<vector<string>> vvRet = mysql.Select("select* from employee;");
	mysql.Insert("insert into employee values(5,'蓝忘机','男','1996-10-14',1400000,'员工',151000004,10040.00);");
	mysql.Insert("insert into employee values(6,'金陵','女','1996-10-15',1500000,'管理员',151000005,10050.00);");
	mysql.Select("select* from employee;");
	system("pause");
	return 0;
}
