#include "AccessSQLTool.h"

#include <iostream>
AccessSQLTool::AccessSQLTool() :m_pConnection(NULL), m_pCommand(NULL), m_pRecord(NULL)
{
}


AccessSQLTool::~AccessSQLTool()
{
}

bool AccessSQLTool::ConnectToSQL()
{
	::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConnect = "DRIVER=Microsoft Access Driver (*accdb,*.mdb);FIL={MS Access};DBQ=D:\\test.accdb;UID=;";
		m_pConnection->Open(strConnect, "", "", adModeUnknown);

		if (m_pConnection->State == adStateOpen)
			printf("connect to access sql successfully");

		return true;
	}
	catch (_com_error & e)
	{
		std::cout << e.Description() << std::endl;

		return false;
	}
	
}