#include"managesystem.h"//��Ҫ���õ�cpp
#include"myvector.h"

//��ʼ��һ�£����û���ļ��ʹ������еĻ����ܶ�
ManageSystem::ManageSystem()
{}

//��ʾ���˵�
void ManageSystem::ShowMainMenu()
{
	while (true)//ѭ��������˵�
	{
		system("cls");
		cout << "*******************************��ӭ��������������ϵͳ��*******************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.������Ա                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.������Ա                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.�� �� Ա                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.��    ��                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://������Ա
			this->MSOperMenu(1);
			break;
		case 2://������Ա
			this->MSOperMenu(2);
			break;
		case 3://������Ա
			ManageSystem::Login(3);
			break;
		case 0://�˳�
			cout << "��ӭ�´��ٴ�ʹ�ã�" << endl;
			exit(0);
		default://�������
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��¼����
void ManageSystem::Login(int type)
{
	ifstream ifs;
	string Name_File;
	if (type == 1)
	{
		Name_File = PERSON_FILE;
	}
	else if (type == 2)
	{
		Name_File = STAFF_FILE;
	}
	else
	{
		Name_File = ADMIN_FILE;
	}
	ifs.open(Name_File, ios::in);
	if (!(ifs.is_open()))
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//ɨ���Num
	string Num; string Fid; string Fpassword;string Fname; string Fphone;
	Identify* person = NULL;//�ȴ���һ������ָ�룬�����ö�̬չʾ����
	if (type == 1)//��ͨ�û���Person��
	{
		string num;	
		string id;
		string password;
		cout << "��������Ĺ��ţ�" << endl;
		cin >> num;
		cout << "����������˺ţ�" << endl;
		cin >> id;
		cout << "������������룺" << endl;
		cin >> password;
		//ÿһ��ɨ�裬�жϺ����뱾һ������֤�ɹ���������֤ʧ��
		while (ifs>>Num&&ifs >> Fid && ifs >> Fpassword&&ifs>>Fname&&ifs>>Fphone)
		{
			if (Num==num&&Fid == id && Fpassword == password)
			{
				cout << "������Ա�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				//cout << Fname << " " << "���Դ��룡����" << Fphone;
				person = new Person(num,id, password,Fname,Fphone);
				//�������Ա����
				person->OperMenu();
			}
		}
	}
	else if (type == 2)//������Ա��staff��
	{
		string num;
		string id;
		string password;
		cout << "��������Ĺ��ţ�" << endl;
		cin >> num;
		cout << "����������˺ţ�" << endl;
		cin >> id;
		cout << "������������룺" << endl;
		cin >> password;
        int Frole;
		while (ifs >> Num&&ifs >> Fid && ifs >> Fpassword&&ifs>>Fname&&ifs>>Fphone&&ifs>>Frole)
		{
			if (num==Num&&Fid == id && Fpassword == password)
			{
				cout << "������Ա�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Staff(num,id, password,Fname,Fphone,Frole);
				//������һ��
				person->OperMenu();
			}
		}
	}
	else//������Ա
	{
		string id;
		string password;
		cout << "����������˺ţ�" << endl ;
		cin >> id;
		cout << "������������룺"<<endl;
		cin >> password;
		while (ifs >> Fid && ifs >> Fpassword)
		{
			//�ж������˺������Ƿ������뱾�����
			if (Fid == id && Fpassword == password)
			{
				cout << "����Ա�����֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Admin(id, password);
				//�������Ա����
				person->OperMenu();
			}
		}
	}
	//�����֤ʧ��
	cout<< "�����֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

//��ҳ�������û�ѡ���Ƿ����˺�
void ManageSystem::MSOperMenu(int num)
{
	system("cls");
	while (true)
	{
		cout << "*******************************��ӭ�����¼����!*******************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                1.�����˺ţ���¼                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                2.û���˺ţ�����                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                0.�� �� �� һ ��                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "����������ѡ��: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://��¼����˵�
			this->Login(num);
			break;
		case 2://�����˺�ҳ��
			this->Create(num);
			break;
		case 0://������һҳ��
			system("cls");
			this->ShowMainMenu();
			break;
		default://�������
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//����һ���˺�
void ManageSystem::Create(int num)//num==1������Ա ����������Ա�������Ȩ��
{
	string filename;
	if (num == 1)
	{
		filename = PERSON_FILE;
		MyVector v;
		v.Showid(num);
	}
	else
	{
		cout << "������Ա��Ȩ���Լ������˺ţ��������Ա����..." << endl;
		system("pause");
		system("cls");
		return;
	}

	string Num;
	string id;
	string password1; string password2;
    cout << "��������Ҫ�����Ĺ���(3λ��)��" << endl;
	cin >> Num;
	MyVector v;
	bool ret=v.IsRepeat(Num, 1);

	if (ret)
	{
		cout << "������ԭ�������ظ�������������..." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��������Ҫ�������˺ţ�" << endl;
	cin >> id;
	cout << "�����������룺" << endl;
	cin >> password1;
	cout << "���ٴ�ȷ���������룺" << endl;
	cin >> password2;
	if (password1 != password2)
	{
		cout << "��������������벻һ��,�밴���������..." << endl;
		system("pause");
		system("cls");
		return;
	}
	string realname;//��ʵ����
	string phonenum;//�绰
	cout << "������������ʵ������" << endl;
	cin >> realname;
	cout << "�������ĵ绰���룺" << endl;
	cin >> phonenum;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	//����Ϣд�����뱾��
	ofs << Num << " " << id << " " << password1 <<
		" " << realname << " " << phonenum << endl;
	cout << "���ѳɹ��������˺�!�밴��������ص�¼..." << endl;
	system("pause"); system("cls");
	this->MSOperMenu(1);
}

