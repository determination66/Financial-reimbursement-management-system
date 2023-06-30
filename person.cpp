#include"person.h"
#include"myvector.h"
#include<map>

//Ĭ�Ϲ���
Person::Person() {}

//���� �˺� ���� ��ʵ���� �绰 �вι���
Person::Person(string num, string id, string password, string rname, string phone)//�вι���
{
	this->m_Num = num;
	this->m_Id = id;
	this->m_Password = password;
	this->m_RealName = rname;
	this->m_PhoneNum = phone;
}

//չʾ��������
void Person::OperMenu() 
{
	while (true)
	{
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ������Ա��¼��************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1.�� ѯ ��  Ϣ                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2.�� �� ��  Ϣ                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3.�� �� ��  ��                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0.ע        ��                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;//��������
		switch (choice)
		{
		case 1://��ѯ������Ϣ
			this->Oper1Mune();
			break;
		case 2://�޸���Ϣ
			this->ChangeInfo();
			break;
		case 3://��������
			this->Oper3Mune();
			break;
		//case 3://���뱨��
		//	this->ApplyChart();
		//	break;
		//case 4://ȡ������
		//	this->CancelChart();
		//	break;
		//case 5://���ո���
		//	this->PayMoney();
		//	break;
		case 0:
			ms.ShowMainMenu();
			break;
		default:	cout << "������������������" << endl;
			//����������������½���ѭ������˵�
			system("pause");
			system("cls");
			break;
		}
	}
}

//չʾ�ֲ˵�1������ѯ����
void Person::Oper1Mune()
{
	
	while (true)
	{
		system("cls");
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ������Ա��ѯ��************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1. ��  ��  ��  Ϣ                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2. ��  ��  ��  ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3. �� �� �� Ȩ ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   4. ��  ��  ��  ѯ                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0. �� �� �� һ ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		ArlTable a;
		Progress p;
		switch (choice)
		{
		case 1://��ѯ������Ϣ
			this->ShowOwnInfo();
			system("pause");
			system("cls");
			break;
		case 2:// 2. ��  ��  ��  ��
			this->ShowOwnProgress();
			break;
		case 3:
			//���洴����һ��ArlTable���һ������ a
			a.ShowInfo();
			break;
		case 4://������ѯ
			p.ShowConInfo();
			break;
		case 0:
			system("cls");
			this->OperMenu();
			break;
		default:	cout << "������������������" << endl;
			//����������������½���ѭ������˵�
			system("pause");
			system("cls");
			break;
		}
	}
}

//չʾ�ֲ˵�3��������
void Person::Oper3Mune()
{
	while(true)
	{
		system("cls");
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ�����뱨��������棡************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1. ��  ��  ��  ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2. ȡ  ��  ��  ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3. ��  ��  ��  ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0. �� �� �� һ ��                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			this->ApplyChart();
			break;
		case 2:
			this->CancelChart();
		    break;
		case 3:
			this->PayMoney();
			break;
		case 0:
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

//���뱨����Ϣ�����ҽ������ļ���
void Person::ApplyChart()
{
	int money = 0;
	cout << "��������Ҫ�ᵥ�Ľ�" << endl;
	cout << "�����룾0Ԫ����������������!!!" << endl;
	do
	{ 
	cin >> money; 
	} while (money <=0);
	
	Progress p;
	//int num=p.GetVproSize();
	//�ᵥ���   ����   �ᵥ���   �ᵥ����   ״̬  ������ �ֱ���и�ֵ
	p.m_Pnum =p.GetVpronum(); p.m_Num = this->m_Num;
	p.m_Pmoney = money; p.m_Date = p.GetDate(); p.m_State = "����";
	p.m_Dealer = this->m_Num;
	ofstream ofs;
	ofs.open(PERSONINFO, ios::out | ios::app);
	ofs << p.m_Pnum << " " << p.m_Num << " " << p.m_Pmoney << " "
		<< p.m_Date << " " << p.m_State << " " << p.m_Dealer<<endl;
	ofs.close();
	cout << "�ɹ����룡";
	system("pause");
	system("cls");
}

//�޸��˺���Ϣ,ֻ�ܸ��˺�����͵绰
void Person::ChangeInfo()
{
	//cout << "ֻ���޸��˺ţ�����͵绰����!..." << endl;
	system("cls");
	cout << "************************************��ӭ�����޸Ľ��棡************************************" << endl;
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
	v.InitVPer();
	int j = 0;
	for (vector<Person>::iterator it = v.vPer.begin(); it != v.vPer.end(); it++)
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
						v.vPer.erase(v.vPer.begin() + j);
						v.vPer.insert(v.vPer.begin() + j, *this);
						v.SaveVPer(v.vPer);
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
				system("pause");
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
						v.vPer.erase(v.vPer.begin() + j);
						//�����������޸ĺ����vector������Ӧλ����
						v.vPer.insert(v.vPer.begin() + j, *this);
						v.SaveVPer(v.vPer);
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
				system("pause");
			}
			else if (choice == "3")
			{
				string phone;
				cout << "�����������µ绰���룺"; cin >> phone;
					//���� �˺� ���� ��ʵ���� �绰
				    this->m_PhoneNum = phone;
					v.vPer.erase(v.vPer.begin() + j);
					v.vPer.insert(v.vPer.begin() + j, *this);
					v.SaveVPer(v.vPer);
					cout << "�绰�޸ĳɹ�!";
					system("pause");
			}
			else if(choice == "0");//ȡ������
			else
			{
				cout << "����ѡ�����!" << endl;
				system("pause");
			}
			//system("pause");
			system("cls");
			return;
		}
		j++;
	}
}

//��ѯ���˽�չ
void Person::ShowOwnProgress()
{
	Progress p;
	p.InitVector();
	if (!this->IsProgress())
		cout << "���ļ�¼Ϊ�գ��밴���������..." << endl;
	else
	{
		cout << "�������걨����Ϣ���£�" << endl;
		int i=0;//���ڼ����м���������Ϣ
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num)
			{
				cout <<"��"<<i << "�����ᵥ���Ϊ��" << it->m_Pnum << " ����Ϊ��" << it->m_Num << " �ᵥ���Ϊ��" << it->m_Pmoney
					<<" �ᵥ���ڣ�"<<it->m_Date << " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				i++;
			}		
		}
		cout << "�ܼ���" << i << "��������Ϣ" << endl;
	}
	system("pause");
	system("cls");
}

//��ѯ�Ƿ�������Ľ�չ
bool Person::IsProgress()
{
	Progress p;
	p.InitVector();
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_Num == this->m_Num)
			return true;
	}
	return false;
}

bool Person::IsPay()
{
	Progress p;
	p.InitVector();
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_Num == this->m_Num&&it->m_State=="��������")
			return true;
	}
	return false;
}

//ȡ������
void Person::CancelChart()
{
	Progress p;
	p.InitVector();
	if (!this->IsProgress()) {
		cout << "���ļ�¼Ϊ�գ��밴���������..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		//��¼�ڼ���
		int i = 1; int num = 0;
		map<int, int>m;
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num)
			{
				cout << "��" << i << "��:�ᵥ���Ϊ��" << it->m_Pnum << " ����Ϊ��" << it->m_Num << " �ᵥ���Ϊ��" << it->m_Pmoney
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				m.insert(make_pair(i,num));
				i++;	
			}
			num++;
		}
	/*	for (int m1 = 1; m1 < i; m1++)
		{
			cout << "���Դ��룡" << endl;
			cout << m[m1] << endl;

		}*/
		cout << "����Ҫȡ����һ��,���������0 ��ȡ������" << endl;
		int choice;//ѡ��
		cin >> choice;
		if (choice > 0 && choice <= i - 1)
		{
			p.vPro.erase(p.vPro.begin() +m[choice]);
			p.SaveVProgress(p.vPro);
			cout << "ɾ���ɹ���" << endl;
		}
		else if (choice == 0)
			cout<<"ȡ�������ɹ���";//ȡ������
		else
		{
			cout << "�������,�밴�����������" << endl;
		}
			system("pause");
			system("cls");
			return;	
	}
}

//���ո���
void Person::PayMoney()
{
	Progress p;
	p.InitVector();
	if (!this->IsPay()) {
		cout << "���ļ�¼Ϊ�գ��밴���������..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		int i = 1; int j = 0;
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num && it->m_State == "��������")
			{
				cout << "��" << i << "��:�ᵥ���Ϊ��" << it->m_Pnum << " ����Ϊ��" << it->m_Num << " �ᵥ���Ϊ��" << it->m_Pmoney
					<< " ״̬Ϊ��" << it->m_State << " ������Ϊ��" << it->m_Dealer << endl;
				cout << "���Ƿ�Ҫ���y/Y���ǣ�\tn/N�����ǣ�..." << endl;
				string c;//�ж�ͨ�����
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "ͨ����Ȼ������ڣ�״̬�������������ʹ����ˣ��󱣴�" << endl;
					//�������   �ᵥ��	  �ᵥ���	   �ᵥ����	   ״̬	������
					//��һ�ٲ��������޸���Ϣ�����Ѿ�����,��������򲻻��޸Ľ�չ
					string state = "�������";
					string date = p.GetDate();
					string dealer = this->m_Num;
					Progress p(it->m_Pnum, it->m_Num, it->m_Pmoney, date, state, dealer);
					p.InitVector();
					p.vPro.erase(p.vPro.begin() + j);
					p.vPro.insert(p.vPro.begin() + j, p);
					p.SaveVProgress(p.vPro);

				}
				else if (c == "n" || c == "N");
				else
				{
					cout << "���������Ĭ��δ������Ƚ�����һ����ѡ��..." << endl;
				}
				i++;
				system("pause");
			}
			j++;
		}
	}
	system("cls");
}

//չʾ������Ϣ
void Person::ShowOwnInfo()
{
	cout << "������Ϣ���£�" << endl;
	cout << "����Ϊ:" << this->m_Num << " �˺�Ϊ:" << this->m_Id
					<< " ����Ϊ:" << this->m_RealName << " �绰Ϊ:" << this->m_PhoneNum << endl;
}