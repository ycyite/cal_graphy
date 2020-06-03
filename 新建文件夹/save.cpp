#include"pch.h"
#include"save.h"
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;
DateStr::DateStr()
{
}

DateStr::~DateStr()
{
}

CString DateStr::getToday()
{
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString dateStr = tm.Format("%Y年%m月%d日 %X");
	return dateStr;
}

SaveFile::SaveFile()
{
	fileTail = _T(".txt");
	filePath = _T("save/");
}

SaveFile::~SaveFile()
{
}

CString SaveFile::FullPath()
{
	CString D = filePath + fileName.getToday() + fileTail;
	return D;
}

void SaveFile::writeFile(CString writeStr)
{
	writeStr += _T("\n");
	CStdioFile file;
	file.Open(FullPath(), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	file.SeekToEnd();
	file.WriteString(writeStr);

	//Write( const void* lpBuf, UINT nCount )  lpBuf是写入数据的Buf指针，nCount是Buf里需要写入文件的字节数

	file.Close();
}

void SaveFile::readFile(CString thisFile)
{
	

	thisData = new SaveData[100];
	CString midStr;
	CStdioFile file;
	file.Open((filePath + thisFile), CFile::modeRead);
	//file.SeekToBegin();

	for (int i=0;file.ReadString(midStr);i++)
	{
		thisData[i].dataStr = midStr;
	}
	file.Close();
}

CString SaveFile::returnNum()
{
	dateList = new CString[100];
	//找个数
	CFileFind find;
	bool ret = find.FindFile(filePath + _T("/*.*"));  //所有文件                 
	fileNum = 0;
	while (ret)
	{
		ret = find.FindNextFile();
		if (find.IsDots() || find.IsDirectory())
			continue;
		dateList[fileNum] = find.GetFileName();
		fileNum++;
	}
	/*
	find.FindFile();
	dateList = new CString[fileNum];
	for (int i=0;i<fileNum;i++)
	{
		dateList[i] = find.GetFileName();
		find.FindNextFile();
	}
	*/

	//格式化
	CString num;
	num.Format(_T("%d"),fileNum);
	return (num);
}


SaveData::SaveData()
{
}

SaveData::~SaveData()
{
}