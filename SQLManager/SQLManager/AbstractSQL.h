#pragma once
#include <string>
#include <list>
#include <vector>
class AbstractSQL
{
public:
	AbstractSQL() = default;
	virtual ~AbstractSQL();
	virtual bool ConnectToSQL(void) = 0;
	virtual bool ExecuteSQL(const char * sql_msg) = 0;
	virtual std::vector<std::list<std::string> > QuerySQL(const char * sql_msg) = 0;
	virtual bool CloseSQL() = 0;
};

