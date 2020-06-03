#pragma once
using namespace std;

class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	void writeFile(CString,CString);
	int readPath(CString);
	CString returnFile(int);
	void readFile(CString, CString);
	CString returnData(int);
	void readData(CString);
	CString returnSplitStr(int);
	CString today();
private:
	CString filePath;
	CString* fileList;
	CString* thisFile;
	CString* strList;
};
