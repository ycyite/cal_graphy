#pragma once
using namespace std;

class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	//获得当前日期
	CString today();

	//存档写入数据
	void writeFile(CString,CString);

	//根据图形读入存档文件路径
	int readPath(CString);

	//返回文件名的日期字串
	CString returnFile(int);

	//根据图形和日期读取文件
	void readFile(CString, CString);

	//返回数据字串
	CString returnData(int);

	//分割数据字串为数组
	void readData(CString);

	//根据位置返回数据到编辑框
	CString returnSplitStr(int);
	
private:
	//存档文件夹路径
	CString filePath;

	//存档文件列表
	CString* fileList;

	//存档字串列表
	CString* thisFile;

	//分割的存档字串列表
	CString* strList;
};
