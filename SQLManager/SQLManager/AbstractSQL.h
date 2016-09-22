#pragma once
class AbstractSQL
{
public:
	AbstractSQL() = default;
	virtual ~AbstractSQL();
	virtual bool ConnectToSQL(void) = 0;
	//virtual bool ExecuteSQL(const char * sql_msg) = 0;
	//virtual bool CloseSQL() = 0;
};

