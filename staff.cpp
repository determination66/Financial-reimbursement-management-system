#include"staff.h"
#include"myvector.h"

//Ĭ�Ϲ���
Staff::Staff()
{
	this->m_role = 0;

}

//�вι���
Staff::Staff(string num, string id, string password, string rname, string phonenum, int role)
{
	this->m_Num = num;
	this->m_Id = id;
	this->m_Password = password;
	this->m_RealName = rname;
	this->m_PhoneNum = phonenum;
	this->m_role = role;
}

//ÿ����ĳ������������˵�
void Staff::OperMenu()
{
	while (true)
	{
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ������Ա��¼��************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.��ѯ��Ϣ                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.�޸���Ϣ                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.������Ϣ                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.ע    ��                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;
		switch (choice)
		{
		case 1:
			this->Oper1Menu();
			break;
		case 2://�޸���Ϣ
			this->ChangeInfo();
			break;
		case 3://������Ϣ
			this->AprovePerson();
			break;
		case 0://ע��
			system("cls");
			ms.ShowMainMenu();
			break;
		default:	
			cout << "������������������" << endl;
			//����������������½���ѭ������˵�
			system("pause");
			system("cls");
			break;
		}
	}
}

//����ְ��
string Staff::GetRole()
{
	switch (this->m_role)
	{
	case 1:
		return "��������";
	case 2:
		return "��������";
	case 3:
		return "��������";
	case 4:
		return "���Ÿ�����";
	default:
		return "����";
	}
}

//�����������Ȩ
int Staff::GetCheckMoney()
{
	switch(this->m_role)
	{
	case 1:
		return 100000;
	case 2:
		return 100000;
	case 3:
		return 50000;
	case 4:
		return 50000;
	default:
		return 0;
	}
}

//����ֽ���1������ѯ����
void Staff::Oper1Menu()
{
	system("cls");
	while (true)
	{
		cout << "************************************��ӭ������Ա�����ѯ���棡************************************" << endl;
		cout << endl << endl;
		//չʾ�ֲ˵�1����Ϣ
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  1.�� �� �� �� Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  2.��  ��  ��  Ա                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  3.��    ��    Ա                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  4.��  ��  ��  Ա                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  5.��  ��  ��  Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  0.�� �� �� һ ��                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://��ѯ��������Ϣ
			this->ShowApproval();
			break;
		case 2://������Ա��Ϣ
		this->ShowStaffInfo();
			break;
		case 3://����Ա��Ϣ
			this->ShowAdminInfo();
			break;
		case 4://������Ա��Ϣ
			this->ShowPersonInfo();
			break;
		case 5://��ѯ������Ϣ
			this->ShowOwnInfo();
			system("pause");
			system("cls");
			break;
		case 0://���ص���һ��
			system("cls");
			this->OperMenu();
			break;
		default:
			cout << "������������������" << endl;
			//����������������½���ѭ������˵�
			system("pause");
			system("cls");
			break;
		}
	}
}

//չʾ��������Ա����Ϣ,ֻչʾ��ȷ�Χ�ڵ�������Ϣ
void Staff::ShowApproval()
{
	if (!this->IsExistAprove())
	{
		cout << "����ǰû�д�������Ϣ��";
		system("pause"); system("cls");
		return;
	}
	Progress p;
	p.InitVector();
	int i=1;//��ʾ������չʾ���еļ���
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "����")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//���Ÿ�������������
			{
				cout<<"��"<<i<<"���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}
			else if (it->m_Pmoney>50000&&it->m_Pmoney <= 100000 && this->m_role == 2)//�������ܵĴ�������Ϣ
			{
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}
		}
		else if (it->m_State == "��������")
		{
			if (it->m_Pmoney <= 50000 && this->m_role ==3)//����������������
			{
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 1)//�������ܵĴ�������Ϣ
			{
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}
		}
	}
	system("pause");
	system("cls");
}

//��������
void Staff::AprovePerson()
{
	if (!this->IsExistAprove())
	{
		cout << "����ǰû�д�������Ϣ��";
		system("pause"); system("cls");
		return;
	}
	Progress p;
	p.InitVector();
	int i = 1;//��ʾ������չʾ���еļ���
	int j = 0;//�ҳ��±�
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "����")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//���Ÿ�������������
			{
				system("cls");
				cout << "************************************��ӭ����������************************************" << endl;
				cout << endl << endl;
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << endl;
				cout << "�����������Y/y��ͨ����N/n����ͨ����...,����P/p����ֹ���ز˵�" << endl;
				string c;//�ж�ͨ�����
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "ͨ����Ȼ������ڣ�״̬�������������ʹ����ˣ��󱣴�" << endl;
					//�������   �ᵥ��	  �ᵥ���	   �ᵥ����	   ״̬	������
					//��һ�ٲ��������޸���Ϣ�����Ѿ�����,��������򲻻��޸Ľ�չ
					string state="��������";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "n" || c == "N")
				{
					//cout << "��ͨ�������ڣ�״̬����������������,����" << endl;
					string state = "����";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "p" || c == "P")
				{
					system("cls");
					this->OperMenu();
				}
				else
				{
					cout << "�������"; system("pause");
				}
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 2)//�������ܵĴ�������Ϣ
			{
				system("cls");
				cout << "************************************��ӭ����������************************************" << endl;
				cout << endl << endl;
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << endl;
				cout << "�����������Y/y��ͨ����N/n����ͨ����...,����P/p����ֹ���ز˵�" << endl;
				string c;
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "ͨ����Ȼ������ڣ�״̬�������������ʹ����ˣ��󱣴�" << endl;
					string state = "��������";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "n" || c == "N")
				{
					//cout << "��ͨ�������ڣ�״̬����������������,����" << endl;
					string state = "����";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "p" || c == "P")
				{
					system("cls");
					this->OperMenu();
				}
				else
				{
					cout << "�������"; system("pause");
				}
				i++;
			}
		}
		else if (it->m_State == "��������")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 3)//����������������
			{
				system("cls");
				cout << "************************************��ӭ����������************************************" << endl;
				cout << endl << endl;
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				cout << "�����������Y/y��ͨ����N/n����ͨ����...,����P/p����ֹ���ز˵�" << endl;
				string c;//ѡy/n��
				cin >> c;
				if (c == "y" || c == "Y")
				{
					/*cout << "ͨ����Ȼ������ڣ�״̬�������������ʹ����ˣ��󱣴�" << endl;	*/
					string state = "��������";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "n" || c == "N")
				{
					//cout << "��ͨ�������ڣ�״̬����������������,����" << endl;
					string state = "����";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "p" || c == "P")
				{
					system("cls");
					this->OperMenu();
				}
				else
				{
					cout << "�������"; system("cls");
				}
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 1)//�������ܵĴ�������Ϣ
			{
				system("cls");
				cout << "************************************��ӭ����������************************************" << endl;
				cout << endl << endl;
				cout << "��" << i << "���� ��������ţ�" << it->m_Pnum << " ����Ϊ��" << it->m_Num <<
					" �ᵥ���Ϊ��" << it->m_Pmoney << " �ᵥ����Ϊ��" << it->m_Date
					<< " ״̬Ϊ��" << it->m_State<< endl;
				cout << "�����������Y/y��ͨ����N/n����ͨ����...,����P/p����ֹ���ز˵�" << endl;
				string c;
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "ͨ����Ȼ������ڣ�״̬�������������ʹ����ˣ��󱣴�" << endl;
					string state = "��������";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "n" || c == "N")
				{
					//cout << "��ͨ�������ڣ�״̬����������������,����" << endl;
					string state = "����";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);
				}
				else if (c == "p" || c == "P")
				{
					system("cls");
					this->OperMenu();
				}
				else
				{
					cout << "�������"; system("pause");
				}
				i++;
			}
		}
		j++;
	}
	system("pause");
	system("cls");
}

//�ж��Ƿ����������Ϣ
bool Staff::IsExistAprove()
{
	Progress p;
	p.InitVector();
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "����")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//���Ÿ�������������
			{
				return true;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 2)
			{
				return true;
			}
		}
		else if (it->m_State == "��������")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 3)
			{
				return true;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 1)
			{
				return true;
			}
		}
	}
	return false;
}

//��ѯ����Ա��Ϣ
void Staff::ShowAdminInfo()
{
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Admin a;
	while (ifs >> a.m_Id && ifs >> a.m_Password)
	{
		cout << "�˺�Ϊ:" << a.m_Id <<endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//��ѯ������Ա��Ϣ
void Staff::ShowPersonInfo()
{
	ifstream ifs;
	ifs.open(PERSON_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	cout << "������Ա��������Ϣ���£�" << endl;
	//���� �˺� ���� ���� �绰
	string num; string id; string password; string rname; string phone;
	while (ifs >> num && ifs >> id && ifs >> password && ifs >> rname && ifs >> phone)
	{
		cout << "����Ϊ:" << num << " �˺�Ϊ:" << id << " ����Ϊ��" << password << " ����Ϊ:" << rname << " �绰Ϊ:" << phone << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//��ѯ������Ա��Ϣ
void Staff::ShowStaffInfo()
{
	ifstream ifs;
	ifs.open(STAFF_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Staff s;
	cout << "������Ա��������Ϣ���£�" << endl;
	while (ifs >> s.m_Num && ifs >> s.m_Id && ifs >> s.m_Password && ifs >> s.m_RealName && ifs >> s.m_PhoneNum && ifs >> s.m_role)
	{
		cout << "����Ϊ:" << s.m_Num << " �˺�Ϊ:" << s.m_Id <<" ����Ϊ:" << s.m_RealName << " �绰Ϊ:" <<
			s.m_PhoneNum << " ְ��Ϊ:" << s.GetRole()<<" �������Ϊ��"<<s.GetCheckMoney() << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//��ѯ������Ϣ
void Staff::ShowOwnInfo()
{
	cout << "������Ϣ���£�" << endl;
	cout << "����Ϊ:" << this->m_Num << " �˺�Ϊ:" << this->m_Id
		<< " ����Ϊ:" << this->m_RealName << " �绰Ϊ:" << this->m_PhoneNum <<" ְ��Ϊ��"<<this->GetRole() << endl;
}

//�޸ĸ�����Ϣ
void Staff::ChangeInfo()
{
	//cout << "ֻ���޸��˺ţ�����͵绰����!..." << endl;
	system("cls");
	cout << "************************************��ӭ������Ա�����޸Ľ��棡************************************" << endl;
	cout << endl << endl;
	cout << "\t\t ----------------------------------------------------" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  1. ��  ��  ��  ��                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  2. ��  ��  ��  ��                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  3. ��  ��  ��  ��                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  0. ȡ  ��  ��  ��                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t ----------------------------------------------------" << endl;
	this->ShowOwnInfo();//չʾ������Ϣ
	cout << "��������Ҫ���е�ѡ��:";
	MyVector v;
	v.InitVSta();
	int j = 0;
	for (vector<Staff>::iterator it = v.vSta.begin(); it != v.vSta.end(); it++)
	{
		if (it->m_Num == this->m_Num)
		{
			string choice; //ѡ��
			cin >> choice;
			if (choice == "1")
			{
				string Oripsw;
				cout << "������ԭ����������ȷ��:"; cin >> Oripsw;
				if (Oripsw == this->m_Password)
				{
					string id1, id2;
					cout << "�������µ��˺�:"; cin >> id1;
					cout << "���ٴ�ȷ�����˺ţ�"; cin >> id2;
					if (id1 == id2)
					{
						//���� �˺� ���� ��ʵ���� �绰
						this->m_Id = id1;
						v.vSta.erase(v.vSta.begin() + j);
						v.vSta.insert(v.vSta.begin() + j, *this);
						v.SaveVSta(v.vSta);
						cout << "�˺��޸ĳɹ�!";
					}
					else
					{
						cout << "������������˺Ų�һ��!" << endl;
					}
				}
				else
				{
					cout << "�����֤ʧ��,�޷������޸ģ�";
				}
			}
			else if (choice == "2")
			{
				string Oripsw;
				cout << "������ԭ����������ȷ��:"; cin >> Oripsw;
				if (Oripsw == this->m_Password)
				{
					string psw1, psw2;
					cout << "�������µ�����:"; cin >> psw1;
					cout << "���ٴ�ȷ�������룺"; cin >> psw2;
					if (psw1 == psw2)
					{
						//���� �˺� ���� ��ʵ���� �绰
						this->m_Password = psw1;//������
						v.vSta.erase(v.vSta.begin() + j);
						//�����������޸ĺ����vector������Ӧλ����
						v.vSta.insert(v.vSta.begin() + j, *this);
						v.SaveVSta(v.vSta);
						cout << "�����޸ĳɹ�!" << endl;
					}
					else
					{
						cout << "��������������벻һ��!" << endl;
					}
				}
				else
				{
					cout << "�����֤ʧ��,�޷������޸ģ�";
				}
			}
			else if (choice == "3")
			{
				string phone;
				cout << "�����������µ绰���룺"; cin >> phone;
				//���� �˺� ���� ��ʵ���� �绰
				this->m_PhoneNum = phone;
				v.vSta.erase(v.vSta.begin() + j);
				v.vSta.insert(v.vSta.begin() + j, *this);
				v.SaveVSta(v.vSta);
				cout << "�绰�޸ĳɹ�!";
			}
			else if (choice == "0");//ȡ������
			else
			{
				cout << "����ѡ�����!" << endl;
			}
			system("pause");
			system("cls");
			return;
		}
		j++;
	}
}
