#include "AccessSQLTool.h"

int main(void)
{
	AccessSQLTool ac;
	ac.ConnectToSQL();
//	ac.ExecuteSQL("insert into mytable(name_str,id_str) values('dd','v')");

	std::vector <std::list<std::string> > vec;

	vec = ac.QuerySQL("select * from mytable");
	Sleep(2000);
	ac.CloseSQL();
	system("pause");
	return 0;
}