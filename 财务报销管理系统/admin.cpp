#include"admin.h"
#include"myvector.h"

//Ĭ�Ϲ���
Admin::Admin() {}

//�вι���
Admin::Admin(string id, string password)
{
	this->m_Id = id;
	this->m_Password = password;
}

//ÿ����ĳ������������˵�
void Admin::OperMenu()
{
	while(true)
	{ 
		system("cls");
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ����Ա��¼��************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.��ѯ��Ϣ                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.����˺�                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.ɾ����Ϣ                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.ע    ��                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��: " ;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;
		switch (choice)
		{
		case 1://��ѯ��Ϣ
			this->Oper1Menu();	
			break;
		case 2://����˺�
			this->AddPerson();
			break;
		case 3:
			this->Oper4Menu();
			break;
		case 0://ע���˺ţ����ص���һ��
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

//չʾ����Ա����Ϣ
void Admin::ShowAdminInfo()
{
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Admin a;
	while (ifs >> a.m_Id && ifs >>a.m_Password)
	{
		cout << "�˺�Ϊ:" << a.m_Id<<" ����Ϊ��"<<a.m_Password << endl;
    }
	ifs.close();
	system("pause");
	system("cls");
}

//չʾ������Ա��Ϣ
void Admin::ShowPersonInfo()
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
	while (ifs >>num && ifs >>id && ifs >>password&& ifs >>rname && ifs >>phone)
	{
		cout << "����Ϊ:" <<num << " �˺�Ϊ:" << id<<" ����Ϊ��"<<password << " ����Ϊ:" << rname << " �绰Ϊ:" << phone << endl;
	}
	ifs.close();
}

//չʾ������Ա��Ϣ
void Admin::ShowStaffInfo()
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
	while (ifs >> s.m_Num && ifs>> s.m_Id && ifs >>s.m_Password&& ifs >> s.m_RealName&& ifs >>s.m_PhoneNum&&ifs>>s.m_role)
	{
		cout << "����Ϊ:" <<s.m_Num<< " �˺�Ϊ:" << s.m_Id <<" ����Ϊ��"<<s.m_Password << " ����Ϊ:" << s.m_RealName << " �绰Ϊ:" <<
			s.m_PhoneNum<<	" ְ��Ϊ:" << s.GetRole() <<" �������Ϊ��" << s.GetCheckMoney() << endl;
	}
	ifs.close();
}

//չʾ�ֲ˵�1������ѯ������Ϣ
void Admin::Oper1Menu()
{
	while (true)
	{
		system("cls");
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ����Ա�����ѯ���棡************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1. ����Ա��Ϣ                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.������Ա��Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.������Ա��Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    4.��ѯ������չ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    5.  ������ѯ                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0. ������һ��                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "��������Ҫ��ѯ�ĵ�ѡ��: "<<endl;
		int choice = 0;
		cin >> choice;
		Progress p;
		switch (choice)
		{
		case 1://��ѯ����Ա��Ϣ 
			this->ShowAdminInfo();
			break;
		case 2://��ѯ������Ա��Ϣ
			this->ShowStaffInfo();
			system("pause");
			system("cls");
			break;
		case 3://��ѯ������Ա��Ϣ
			this->ShowPersonInfo();
			system("pause");
			system("cls");
			break;
		case 4://��ѯ������չ
			p.ShowPro();
			break;
		case 5://�����������в�ѯ
			p.ShowConInfo();
			break;
		case 0://������һ��  
			this->OperMenu();
			break;
		default://�������
			cout << "���������밴�����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//����û�(������Ա ��������Ա)
void Admin::AddPerson()
{
	string filename, username, password;
	ofstream ofs;
	int select = 0;
	while (true)
	{
		//��һ���������ǳɹ��ģ��ڽ������������switch���
		cout << "1:��ӱ�����Ա\t2:��ӹ�����Ա��" << endl;
		cout << "3:��ӹ���Ա\t0:ȡ������:" << endl;
		cout << "����������˺ŵ����ͣ�" << endl;
		cin >> select;//ѡ��
		MyVector v;
		if (select == 1)//��ӱ�����Ա
		{
			filename = PERSON_FILE;
			ofs.open(filename, ios::out | ios::app);
			string id;
			v.Showid(1);
			cout << "�����빤��:" << endl;
			cin >> id;//����
			bool ret = v.IsRepeat(id, 1);
	
			if (!ret)
			{
				cout << "�������˺ţ�" << endl;
				cin >> username;//�˺�
				cout << "����������:" << endl;
				cin >> password;//����

				string name;//����
				cout << "����������:" << endl;
				cin >> name;
				string phone;//�绰
				cout << "������绰����:" << endl;
				cin >> phone;
				ofs << id << " " << username << " " << password << " " << name << " " << phone << endl;
				ofs.close();
				cout << "�ɹ����һ��������Ա!" << endl;
				v.InitVPer();
				v.SaveVPer(v.vPer);
			}
			else
			{
				cout << "�����ظ����밴�����������" << endl;
			}
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)//��ӹ�����Ա
		{
			filename = STAFF_FILE;
			ofs.open(filename, ios::out | ios::app);
			Staff s;
			v.Showid(2);
			cout << "�����빤��:" << endl;
			cin >> s.m_Num;//����
			bool ret=v.IsRepeat(s.m_Num,2);
	
			if (!ret)
			{
				cout << "�������˺ţ�" << endl;
				cin >> s.m_Id;//�˺�
				cout << "����������:" << endl;
				cin >> s.m_Password;//����
				cout << "����������:" << endl;
				cin >> s.m_RealName;
				cout << "������绰����:" << endl;
				cin >> s.m_PhoneNum;
				cout << "1:��������\t2:��������" << endl;
				cout << "3:��������\t4:���Ÿ�����" << endl;
				cout << "������ְ���Ӧ�ı�ţ�(�����������֣�����������...)" << endl;
				do {
					cin >> s.m_role;
				   } while (s.m_role<1 ||s.m_role>4);
				ofs << s.m_Num << " " << s.m_Id << " " << s.m_Password
					<< " " << s.m_RealName << " " << s.m_PhoneNum << " " <<
					s.m_role << endl;
				ofs.close();
				v.InitVSta();
				v.SaveVSta(v.vSta);
				//��������ӵ���Ϣ���У���Ҫ��ӵ���Ȩ��,�Ƚ���Ҫ
				cout << "�ɹ����һ��������Ա" << endl;
				ArlTable a;
				a.AddVAT(s.GetRole(), s.GetCheckMoney(), s.m_Num);//��ӵ���Ȩ����
			}
			else
			{
				cout << "�����ظ����밴�����������" << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 3)//��ӹ���Ա
		{
			filename = ADMIN_FILE;
			ofs.open(filename, ios::out | ios::app);
			v.Showid(3);
			cout << "�������˺ţ�" << endl;
			cin >> username;
			bool ret = v.IsRepeat(username,3);

			if (!ret) //û���ظ�
			{
			cout << "���������룺" << endl;
			cin >> password;
			ofs << username << " " << password << endl;
			ofs.close();
			cout << "�ɹ����һ������Ա��" << endl;
			//�ļ�û�м�ʹ���棬Ŀǰ����һ��Сbug
			v.InitVAdm();
			v.SaveVAdm(v.vAdm);
			}
			else 
			{
				cout << "�û����ظ����밴�����������" << endl;
			}
			system("pause");
			system("cls");
			return;
		}
		else if (select == 0)
		{
			system("pause");
			system("cls");
			return;
		}
		else//�������
		{
			cout << "���������밴�����������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//չʾɾ����Ϣ4�ķ�ҳ��
void Admin::Oper4Menu()
{
	while (true)
	{
		system("cls");
		//չʾ�˵�����Ϣ
		cout << "************************************��ӭ����Ա��¼��************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.������Ա��Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.������Ա��Ϣ                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0. ������һ��                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "��������Ҫɾ����ѡ��: " << endl;
		int choice = 0;
		cin >> choice;
		Progress p;
		switch (choice)
		{
		case 1:
			this->DeletePerson(1);
			break;
		case 2:
			this->DeletePerson(2);
			break;
		case 0://������һ��  
			this->OperMenu();
			break;
		default://�������
			cout << "���������밴�����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//ɾ����Ա��Ϣ
void Admin::DeletePerson(int type)
{
	MyVector v;

	if (type == 1)//ɾ��������Ա��Ϣ
	{
		this->ShowPersonInfo();
		cout << "��������Ҫɾ���˺ŵĹ���:" << endl;
		string num;//ѡ��
		cin >> num;
		//ɾ��������Ա��Ϣ
		//Ȼ�������ʾ��Ϣ
			v.InitVPer();
		for (vector<Person>::iterator it = v.vPer.begin(); it != v.vPer.end(); it++)
		{
			if (num == it->m_Num)
			{
				/*cout << "��Ҫɾ���ı�����Ա��ϢΪ:"<<endl<<"����" << it->m_Num << " �˺�Ϊ��" 
					<< it->m_Id << " ����Ϊ:" << it->m_Password<< " ����Ϊ:" << it->m_RealName 
					<< " �绰Ϊ:" << it->m_PhoneNum << endl;*/
				cout << "��ȷ����Ϣ���Ƿ�Ҫ����ɾ��  ������Y/y������,N/n�����" << endl;
				cout << "ɾ���󽫻��ڱ�����Ա��Ϣ�ͽ�����Ϣ��ɾ��..." << endl;
				string b;//���ѡ��
				cin >> b;
				if (b == "Y" || b == "y")//��ô�Ϳ���ɾ��ģʽ��ɾ�����˺���Ϣ�ͽ�����Ϣ
				{
					v.vPer.erase(it);
					v.SaveVPer(v.vPer);//ɾ����Ϣ
					Progress p;
					p.InitVector();
					for (vector<Progress>::iterator w = p.vPro.begin(); w != p.vPro.end();)
					{
						if (w->m_Num == num)
						{
							w = p.vPro.erase(w);
						}
						else w++;
					}
					p.SaveVProgress(p.vPro);
					cout << "������ϣ��ѳɹ�ɾ����" << endl;
				}
				else if (b == "N" || b == "n")
				{
					cout << "��ȡ��ɾ��" << endl;
				}
				else
				{
					cout << "��������������ȡ��ɾ��!" << endl;
				}
				system("pause"); system("cls"); return;
			}
		}
		cout << "δ��ѯ���˱�����Ա��" << endl;
	}
	//ɾ��������Ա��Ϣ
	else
	{
		this->ShowStaffInfo();
		cout << "��������Ҫɾ���˺ŵĹ���:" << endl;
		string num;//ѡ��
		cin >> num;

        v.InitVSta();
		for (vector<Staff>::iterator it = v.vSta.begin(); it != v.vSta.end(); it++)
		{
			if (num == it->m_Num)//��ʾ��Ϣ
			{
				/*Staff s(it->m_Num, it->m_Id, it->m_Password, it->m_RealName, it->m_PhoneNum, it->m_role);
				cout << "����Ҫɾ������ϢΪ:" << endl;
				s.ShowOwnInfo();*/
				cout << "��ȷ����Ϣ���Ƿ�Ҫ����ɾ��  ������Y/y������,N/n�����" << endl;
				cout << "ɾ���󽫻��ڱ�����Ա��Ϣ����Ȩ����ɾ��..." << endl;
				string b;//���ѡ��
				cin >> b;
				if (b == "Y" || b == "y")//��ô�Ϳ���ɾ��ģʽ��ɾ�����˺���Ϣ�ͽ�����Ϣ
				{
					v.vSta.erase(it); v.SaveVSta(v.vSta);
					ArlTable a; a.InitVAT();
					for (vector<ArlTable>::iterator it = a.vAT.begin(); it != a.vAT.end(); )
					{
						if (num == it->m_Num)
						{
							it = a.vAT.erase(it);
						}
						else it++;
					}
					a.SaveVAT(a.vAT);
					cout << "�������!" << endl;
				}
				else if (b == "N" || b == "n")
				{
					cout << "��ȡ��ɾ����" << endl;
				}
				else
				{
					cout << "��������������ȡ��ɾ��!" << endl;
				}
				system("pause"); system("cls"); return;
			}
		}
		cout << "δ��ѯ����������Ա��" << endl;
	}
	system("pause");
	system("cls");
	return;
}