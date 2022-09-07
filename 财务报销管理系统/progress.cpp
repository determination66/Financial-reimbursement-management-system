#include"progress.h"

//Ĭ�Ϲ���
Progress::Progress()
{
	this->m_Pnum=0;//�ᵥ���

	this->m_Num="0";//����

	this->m_Pmoney=0;//�ᵥ���

	this->m_Date="2022/1/1";//�ᵥ����

	this->m_State="��ʼ";//״̬

	this->m_Dealer="000";//������
}

//�вι���
Progress::Progress(int pnum, string num, int money, string date, string state, string dealer)
{
	//�������   �ᵥ��	  �ᵥ���	   �ᵥ����	   ״̬	������
	this->m_Pnum = pnum; this->m_Num = num;
	this->m_Pmoney = money; this->m_Date = date;
	this->m_State = state; this->m_Dealer = dealer;
}

//��ʼ������������Ա����
void Progress::InitVector()
{
	this->vPro.clear();
	ifstream ifs;
	ifs.open(PERSONINFO, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Progress p;
	/*int m_Pnum; �ᵥ���string m_Num; ����int m_Pmoney;//�ᵥ���
	string m_Date; �ᵥ���� string m_State; ״̬ int m_Dealer;//������*/
	while (ifs >> p.m_Pnum && ifs >> p.m_Num && ifs >>
		p.m_Pmoney && ifs >> p.m_Date && ifs >> p.m_State && ifs >> p.m_Dealer)
	{
		this->vPro.push_back(p);
	}
	ifs.close();
}

//��ѯ��չ��Ϣ
void Progress::ShowPro()
{
	this->InitVector();
	/*int m_Pnum;//�ᵥ���

	int m_Num;//����

	int m_Pmoney;//�ᵥ���

	string m_Date;//�ᵥ����

	string m_State;//״̬

	int m_Dealer;//������
*/
	cout << "���н�չ����Ϣ���£�" << endl;
	for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
	{
		cout << "��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
			" �ᵥ���Ϊ��" << it->m_Pmoney<< " �ᵥ����Ϊ��" << it->m_Date 
			<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
	}
	cout << "���ƣ�" << this->GetVproSize() << "��������Ϣ" << endl;
	system("pause");
	system("cls");
}

//��ȡ��ǰ���ڵĺ���
string Progress::GetDate()
{
	time_t now = time(&now);
	struct tm ti;
	localtime_s(&ti, &now);
	string ret;
	ret = to_string(ti.tm_year + 1900) + "/" +
		to_string(ti.tm_mon + 1) + "/" + to_string(ti.tm_mday);
	return ret;
}

//��ȡ�����Ĵ�С
int Progress::GetVproSize()
{
	this->InitVector();
	int ret=this->vPro.size();
	return ret;
}

//����ʱ��ȡ�����Ϣ
int Progress::GetVpronum()
{
	this->InitVector();
	if (this->vPro.size() == 0)
	{
		return 20220001;
	}
	int num = vPro.rbegin()->m_Pnum + 1;
	return num;
}

//�洢������Ϣ
void Progress::SaveVProgress(vector<Progress>p)
{
	ofstream ofs;
	ofs.open(PERSONINFO, ios::out);
	for (vector<Progress>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs << it->m_Pnum << " " << it->m_Num << " " << it->m_Pmoney << 
			" " << it->m_Date << " " << it->m_State<<" " << it->m_Dealer << endl;
	}
	ofs.close();
}

//������ѯ��Ϣ
void Progress::ShowConInfo()
{
	cout << "ֻ�ܸ����ᵥ��Ų�ѯ���߹��Ų�ѯ��" << endl;
	cout << "1.�ᵥ��Ų�ѯ 2.���Ų�ѯ 0.ȡ������" << endl;
	cout << "����������ѡ��" << endl;
	string choice;
	cin >> choice;
	if (choice == "1")
	{
		cout << "��������Ҫ��ѯ���ᵥ��ţ�" << endl;
		int Pnum=0;//�ᵥ��Ϣ
		cin >> Pnum;
		this->InitVector();

		for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
		{
			if (it->m_Pnum == Pnum)//��ѯ����
			{
				cout << "�ᵥ���Ϊ��" << it->m_Pnum << " ����Ϊ��" << it->m_Num << " �ᵥ���Ϊ��" << it->m_Pmoney
					<< " �ᵥ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "δ��ѯ����ؽ�����������������ȷ�ԣ�" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == "2")
	{
		cout << "��������Ҫ��ѯ�Ĺ��ţ�" << endl;
		string num;
		cin >> num;
		this->InitVector();
		if (!this->IsExist(num))
		{
			cout << "���˺���ʱû�б�����Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		int i = 1;
		for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
		{
			if (it->m_Num == num)//��ѯ����
			{
				cout<<"��"<<i << "��������ᵥ���Ϊ��" << it->m_Pnum << " ����Ϊ��" << it->m_Num << " �ᵥ���Ϊ��" << it->m_Pmoney
					<< " �ᵥ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}
		}
		system("pause");
		system("cls");
	}
	else if (choice == "0")
	{
		system("cls");
	}
	else
	{
		cout << "���������Ϣ����" ;
		system("pause");
		system("cls");
	}
}

//���ݹ����жϽ����Ƿ����
bool Progress::IsExist(string num)
{
	for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
	{
		if (it->m_Num == num)//��ѯ����
		{
			return true;
		}
	}
	return false;
}