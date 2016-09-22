#pragma once
#include "AbstractSQL.h"
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
class AccessSQLTool :
	public AbstractSQL
{
public:
	AccessSQLTool();
	virtual bool ConnectToSQL();
	virtual ~AccessSQLTool();

private:
	_ConnectionPtr m_pConnection;
	_CommandPtr    m_pCommand;
	_RecordsetPtr  m_pRecord;
};

