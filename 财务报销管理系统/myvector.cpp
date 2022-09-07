#include"myvector.h"

//��ʼ������������Ա
void MyVector::InitVPer()
{
	this->vPer.clear();
	ifstream ifs;
	ifs.open(PERSON_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Person test;
	while (ifs >> test.m_Num && ifs >> test.m_Id && ifs >> test.m_Password && ifs >> test.m_RealName&& ifs >> test.m_PhoneNum)
	{
		this->vPer.push_back(test);
	}
	//cout << "������Ա����" << this->vPer.size() << endl;
	ifs.close();
}

//������Ա
void MyVector::InitVSta()
{
	//��ʼ��������Ա����
	this->vSta.clear();
	ifstream ifs;
	ifs.open(STAFF_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Staff test;//���� �˺� ���� ��ʵ���� �绰 ְ��
	while (ifs >> test.m_Num && ifs >> test.m_Id && ifs >> test.m_Password && ifs >> test.m_RealName && ifs >> test.m_PhoneNum&&ifs>>test.m_role)
	{
		this->vSta.push_back(test);
	}
	ifs.close();
}

//����Ա
void MyVector::InitVAdm()
{
	//��ʼ������Ա����,Ϊ���ȥ�ظ����̵�
	//��������ڲ�
	this->vAdm.clear();
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Admin test;
	while (ifs >> test.m_Id && ifs >> test.m_Password)
	{
		this->vAdm.push_back(test);

	}
	ifs.close();
}

//�洢������Ա��Ϣ
void MyVector::SaveVPer(vector<Person>p)
{
	ofstream ofs;
	ofs.open(PERSON_FILE, ios::out);
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Id << " " << it->m_Password <<
			" " << it->m_RealName << " " << it->m_PhoneNum<< endl;
	}
	ofs.close();
}

//�洢������Ա��Ϣ
void MyVector::SaveVSta(vector<Staff>p)
{

	ofstream ofs;
	ofs.open(STAFF_FILE, ios::out);
	for (vector<Staff>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Id << " " << it->m_Password <<
			" " << it->m_RealName << " " << it->m_PhoneNum <<" "<<it->m_role << endl;
	}

	ofs.close();
}

//�洢����Ա��Ϣ
void MyVector::SaveVAdm(vector<Admin>p)
{
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out);
	for (vector<Admin>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs <<  it->m_Id << " " << it->m_Password << endl;
	}
	ofs.close();
}

//�жϹ����Ƿ��ظ���Ϊ��������Ϣ���̵�
bool MyVector::IsRepeat(string num, int type)//���� ����
{
	if (type == 1)//������Ա
	{
		this->InitVPer();
		for (vector<Person>::iterator it = this->vPer.begin(); it != this->vPer.end(); it++)
		{
			if (it->m_Num == num)
			{
				return true;//���ظ�����
			}
		}
	}
	else if (type == 2)//������Ա
	{
		this->InitVSta();
		for (vector<Staff>::iterator it = this->vSta.begin(); it != this->vSta.end(); it++)
		{
			if (it->m_Num == num)
			{
				return true;//���ظ�����
			}
		}
	}
	else 
	{
		this->InitVAdm();
		for (vector<Admin>::iterator it = this->vAdm.begin(); it != this->vAdm.end(); it++)
		{
			if (it->m_Id == num)
				return true;
		}
	}
	return false;
}

//չʾ���й���
void MyVector::Showid(int type)
{
	if (type == 1)//������Ա
	{
		this->InitVPer();
		cout << "��ǰ�Ѵ��ڵĹ������£�" << endl;
		for (vector<Person>::iterator it=this->vPer.begin();it!=this->vPer.end();it++)
		{
			cout <<it->m_Num << ",";
		}
	}
	else if (type == 2)
	{
		this->InitVSta();
		cout << "��ǰ�Ѵ��ڵĹ������£�" << endl;
		for (auto it = this->vSta.begin(); it != this->vSta.end(); it++)
		{
			cout << it->m_Num << ",";
		}
	}
	else
	{
		this->InitVAdm();
		cout << "��ǰ���еĹ���Աid���£�" << endl;
		for (auto it = this->vAdm.begin(); it != this->vAdm.end(); it++)
		{
			cout << it->m_Id << ",";
		}
	}
}