#pragma once
using namespace std;

class SaveFile
{
public:
	SaveFile();
	~SaveFile();
	//��õ�ǰ����
	CString today();

	//�浵д������
	void writeFile(CString,CString);

	//����ͼ�ζ���浵�ļ�·��
	int readPath(CString);

	//�����ļ����������ִ�
	CString returnFile(int);

	//����ͼ�κ����ڶ�ȡ�ļ�
	void readFile(CString, CString);

	//���������ִ�
	CString returnData(int);

	//�ָ������ִ�Ϊ����
	void readData(CString);

	//����λ�÷������ݵ��༭��
	CString returnSplitStr(int);
	
private:
	//�浵�ļ���·��
	CString filePath;

	//�浵�ļ��б�
	CString* fileList;

	//�浵�ִ��б�
	CString* thisFile;

	//�ָ�Ĵ浵�ִ��б�
	CString* strList;
};
