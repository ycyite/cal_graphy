#pragma once
using namespace std;
class DateStr
{
public:
	DateStr();
	~DateStr();
	CString getToday();
};

class SaveData
{
public:
	SaveData();
	~SaveData();
	CString geoStr;
	CString dataStr;

private:

};

class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	void writeFile(CString);
	void readFile(CString);
	CString returnNum();
	CString* dateList;
	CString fileTail;
	SaveData* thisData;
	CString FullPath();
	DateStr fileName;
private:
	
	CString filePath;
	
	int fileNum = 0;
};
