#include"pch.h"
#include"save.h"
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

SaveFile::SaveFile()
{
	filePath = _T("save/");
}

SaveFile::~SaveFile()
{
}

CString SaveFile::today()
{
	CString str;
	CTime tm;
	tm = CTime::GetCurrentTime();
	str = tm.Format("%Y.%m.%d");
	return str;
}

void SaveFile::writeFile(CString shape, CString info)
{
	//完整路径
	CString path = filePath + shape + _T("/") + today();

	//准备字串
	CString str;
	str =  info + _T("\n");

	//写入字串
	CStdioFile file;
	file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	file.SeekToEnd();
	file.WriteString(str);

	file.Close();
}

int SaveFile::readPath(CString shape)
{
	//文件夹路径，如果没有则创建
	CString path = filePath + shape;
	CreateDirectory((LPCTSTR)path, NULL);

	//如果没有今天的文件则创建
	readFile(shape,today());

	fileList = new CString[100];
	//读取文件夹下文件个数
	CFileFind find;
	bool ret = find.FindFile(path + _T("/*.*"));  //所有文件                 
	int fileNum = 0;
	while (ret)
	{
		ret = find.FindNextFile();
		if (find.IsDots() || find.IsDirectory())
			continue;
		//读到的文件名放入列表
		fileList[fileNum] = find.GetFileName();
		fileNum++;
	}

	return fileNum;
}
CString SaveFile::returnFile(int index)
{
	return fileList[index];
}
void SaveFile::readFile(CString shape,CString date)
{
	//完整路径
	CString path = filePath + shape + _T("/") + date;

	thisFile = new CString[100];
	//按行读入的中介
	CString midStr;

	//按行读入
	CStdioFile file;
	file.Open(path, CFile::modeCreate | CFile::modeRead | CFile::modeNoTruncate);
	file.SeekToBegin();

	for (int i = 0; file.ReadString(midStr); i++)
	{
		thisFile[i] = midStr;
	}

	file.Close();
}

CString SaveFile::returnData(int index)
{
	return thisFile[index];
}
void SaveFile::readData(CString fullStr)
{
	strList = new CString[17];
	//分割中介
	CString str;
	//分割存进数组
	for (int i=0;i<17;i++)
	{
		if (AfxExtractSubString(str, (LPCTSTR)fullStr, i, ','))
			strList[i] = str;
	}
}
CString SaveFile::returnSplitStr(int index)
{
	return strList[index];
}