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
		//_bstr_t strConnect = "DRIVER=Microsoft Access Driver (*accdb,*.mdb);FIL={MS Access};DBQ=D:\\test.accdb;UID=;";
	//	_bstr_t strConnect = "DRIVER=Microsoft Access Driver (*.mdb);FIL={MS Access};DBQ=D:\\test.mdb;UID=;";
		_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=920329;Persist Security Info=True;\
							 User ID = sa; Initial Catalog = mysystem; Data Source = localhost"; 
		m_pConnection->Open(strConnect, "", "", adModeUnknown);

		if (m_pConnection->State == adStateOpen)
		{
			std::cout << "connect to access sql successfully" << std::endl;
			m_pCommand.CreateInstance("ADODB.Command");
			m_pCommand->ActiveConnection = m_pConnection;
			return true;
		}
			

		return false;
	}
	catch (_com_error & e)
	{
		std::cout << e.Description() << std::endl;

		return false;
	}
	
}
bool AccessSQLTool::ExecuteSQL(const char * sql_msg)
{
	try
	{
		m_pCommand->CommandText = (_bstr_t)sql_msg;
		m_pCommand->Execute(NULL, NULL, 0);
		return true;
	}
	catch (_com_error & e)
	{
		std::cout << e.Description() << std::endl;

		return false;
	}
}
std::vector<std::list<std::string> > AccessSQLTool::QuerySQL(const char * sql_msg)
{
	std::vector <std::list<std::string> >  string_list;
	std::list<std::string> record_set;
	try
	{
		m_pCommand->CommandText = (_bstr_t)sql_msg;
		m_pRecord = m_pCommand->Execute(NULL, NULL, 0);
		if (0 == m_pRecord->GetRecordCount())
			return string_list;

		m_pRecord->MoveFirst();
		while (!m_pRecord->adoEOF)
		{
			for (int index = 0; index != m_pRecord->Fields->GetCount(); index ++)
			{
				std::string  tmp = (const char *)_bstr_t(m_pRecord->GetCollect(_variant_t(long(index))));
				record_set.push_back(tmp);
			}
			string_list.push_back(record_set);
			record_set.clear();
			m_pRecord->MoveNext();
		}
		
	}
	catch (_com_error & e)
	{
		std::cout << e.Description() << std::endl;

	}

	return string_list;

}
bool AccessSQLTool::CloseSQL()
{
	try
	{
		m_pConnection->Close();
		if (m_pConnection->State == adStateClosed)
		{
			std::cout << "Close SQL successfully" << std::endl;
			return true;
		}
			
		return false;
	}
	catch (_com_error & e)
	{
		std::cout << e.Description() << std::endl;

		return false;
	}
}