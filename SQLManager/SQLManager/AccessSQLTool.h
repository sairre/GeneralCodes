#pragma once
#include "AbstractSQL.h"
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
class AccessSQLTool :
	public AbstractSQL
{
public:
	AccessSQLTool();
	virtual ~AccessSQLTool();
	virtual bool ConnectToSQL();
	virtual bool ExecuteSQL(const char * sql_msg);
	virtual std::vector<std::list<std::string> > QuerySQL(const char * sql_msg);
	virtual bool CloseSQL();

private:
	_ConnectionPtr m_pConnection;
	_CommandPtr    m_pCommand;
	_RecordsetPtr  m_pRecord;
};

