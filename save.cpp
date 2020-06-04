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
	//����·��
	CString path = filePath + shape + _T("/") + today();

	//׼���ִ�
	CString str;
	str =  info + _T("\n");

	//д���ִ�
	CStdioFile file;
	file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	file.SeekToEnd();
	file.WriteString(str);

	file.Close();
}

int SaveFile::readPath(CString shape)
{
	//�ļ���·�������û���򴴽�
	CString path = filePath + shape;
	CreateDirectory((LPCTSTR)path, NULL);

	//���û�н�����ļ��򴴽�
	readFile(shape,today());

	fileList = new CString[100];
	//��ȡ�ļ������ļ�����
	CFileFind find;
	bool ret = find.FindFile(path + _T("/*.*"));  //�����ļ�                 
	int fileNum = 0;
	while (ret)
	{
		ret = find.FindNextFile();
		if (find.IsDots() || find.IsDirectory())
			continue;
		//�������ļ��������б�
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
	//����·��
	CString path = filePath + shape + _T("/") + date;

	thisFile = new CString[100];
	//���ж�����н�
	CString midStr;

	//���ж���
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
	//�ָ��н�
	CString str;
	//�ָ�������
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