#include"aqt.h"
//��Ҫ����һ�������˶����Ȩ����Ϣ���ڽ���

//Ĭ�Ϲ���
ArlTable::ArlTable()
{
	this->m_key = 0;
	this->m_Role = "0";
	this->m_Money = 0;
}

//��ʼ������ȡ�ļ����ݲ��Ҵ洢��vector������
void ArlTable::InitVAT()
{
	this->vAT.clear();
	ifstream ifs;
	ifs.open(STAFFAUIN, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	ArlTable a;
	while (ifs >> a.m_key && ifs >> a.m_Role && ifs >> a.m_Money && ifs >> a.m_Num)
	{
		this->vAT.push_back(a);
	}
	ifs.close();
}

//չʾ��Ϣ
void ArlTable::ShowInfo()
{
	this->InitVAT();
	int i=0;
	cout << "�����˶����Ȩ�����£�" << endl;
	for (vector<ArlTable>::iterator it = this->vAT.begin(); it != this->vAT.end(); it++)
	{
		cout << it->m_key << " " << it->m_Role << " " << it->m_Money <<" " << it->m_Num << endl;
		i++;
	}
	cout << "���ƹ���" << i << "��������Ա" << endl;
	system("pause");
	system("cls");
}

//����vector��Ϣ����ȡ���ļ���
void ArlTable::SaveVAT(vector<ArlTable>a)
{
	ofstream ofs;
	ofs.open(STAFFAUIN, ios::out);
	for (vector<ArlTable>::iterator it = this->vAT.begin(); it != this->vAT.end(); it++)
	{
		ofs<< it->m_key << " " << it->m_Role << " " << it->m_Money << " "<<it->m_Num << endl;
	}
	ofs.close();
}

//��ȡ�����Ĵ�С
int ArlTable::GetVATSize()
{
	this->InitVAT();
	int size = this->vAT.size();
	return size;
}

//��ȡ����ʱ�����Ϣ
int ArlTable::GetVATnum()
{
	this->InitVAT();
	if (this->vAT.size() == 0)
	{
		return 1;
	}
	int ret = this->vAT.rbegin()->m_key + 1;
	return ret;
}

//��ӹ���Ա��ʱ��ͬ��������Ȩ��
void ArlTable::AddVAT(string role, int money, string num)
{
	ofstream ofs;
	ofs.open(STAFFAUIN, ios::app);
	int key=this->GetVATnum();
	ofs << key << " " << role << " " << money << " " << num << endl;
	ofs.close();
	cout << "��ӵ���Ȩ���гɹ���" << endl;
}