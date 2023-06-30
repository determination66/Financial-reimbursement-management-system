#include"managesystem.h"//主要调用的cpp
#include"myvector.h"

//初始化一下，如果没有文件就创建，有的话不能动
ManageSystem::ManageSystem()
{}

//显示主菜单
void ManageSystem::ShowMainMenu()
{
	while (true)//循环输出主菜单
	{
		system("cls");
		cout << "*******************************欢迎来到财务报销管理系统！*******************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.报销人员                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.审批人员                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.管 理 员                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.退    出                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://报销人员
			this->MSOperMenu(1);
			break;
		case 2://审批人员
			this->MSOperMenu(2);
			break;
		case 3://管理人员
			ManageSystem::Login(3);
			break;
		case 0://退出
			cout << "欢迎下次再次使用！" << endl;
			exit(0);
		default://输入错误
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//登录界面
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
		cout << "文件打开失败" << endl;
		return;
	}
	//扫描的Num
	string Num; string Fid; string Fpassword;string Fname; string Fphone;
	Identify* person = NULL;//先创建一个父类指针，后面用多态展示界面
	if (type == 1)//普通用户（Person）
	{
		string num;	
		string id;
		string password;
		cout << "请输入你的工号：" << endl;
		cin >> num;
		cout << "请输入你的账号：" << endl;
		cin >> id;
		cout << "请输入你的密码：" << endl;
		cin >> password;
		//每一行扫描，判断和密码本一样就验证成功，否则验证失败
		while (ifs>>Num&&ifs >> Fid && ifs >> Fpassword&&ifs>>Fname&&ifs>>Fphone)
		{
			if (Num==num&&Fid == id && Fpassword == password)
			{
				cout << "报销人员身份验证成功！" << endl;
				system("pause");
				system("cls");
				//cout << Fname << " " << "测试代码！！！" << Fphone;
				person = new Person(num,id, password,Fname,Fphone);
				//进入管理员界面
				person->OperMenu();
			}
		}
	}
	else if (type == 2)//工作人员（staff）
	{
		string num;
		string id;
		string password;
		cout << "请输入你的工号：" << endl;
		cin >> num;
		cout << "请输入你的账号：" << endl;
		cin >> id;
		cout << "请输入你的密码：" << endl;
		cin >> password;
        int Frole;
		while (ifs >> Num&&ifs >> Fid && ifs >> Fpassword&&ifs>>Fname&&ifs>>Fphone&&ifs>>Frole)
		{
			if (num==Num&&Fid == id && Fpassword == password)
			{
				cout << "审批人员身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Staff(num,id, password,Fname,Fphone,Frole);
				//进入下一步
				person->OperMenu();
			}
		}
	}
	else//管理人员
	{
		string id;
		string password;
		cout << "请输入你的账号：" << endl ;
		cin >> id;
		cout << "请输入你的密码："<<endl;
		cin >> password;
		while (ifs >> Fid && ifs >> Fpassword)
		{
			//判断输入账号密码是否与密码本的相等
			if (Fid == id && Fpassword == password)
			{
				cout << "管理员身份验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Admin(id, password);
				//进入管理员界面
				person->OperMenu();
			}
		}
	}
	//身份验证失败
	cout<< "身份验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}

//分页面用于用户选择是否有账号
void ManageSystem::MSOperMenu(int num)
{
	system("cls");
	while (true)
	{
		cout << "*******************************欢迎进入登录界面!*******************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                1.已有账号，登录                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                2.没有账号，创建                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                0.返 回 上 一 项                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://登录进入菜单
			this->Login(num);
			break;
		case 2://创建账号页面
			this->Create(num);
			break;
		case 0://返回上一页面
			system("cls");
			this->ShowMainMenu();
			break;
		default://输入错误
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//创建一个账号
void ManageSystem::Create(int num)//num==1报销人员 其他审批人员，输出无权限
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
		cout << "审批人员无权限自己创建账号，请向管理员申请..." << endl;
		system("pause");
		system("cls");
		return;
	}

	string Num;
	string id;
	string password1; string password2;
    cout << "请输入您要创建的工号(3位数)：" << endl;
	cin >> Num;
	MyVector v;
	bool ret=v.IsRepeat(Num, 1);

	if (ret)
	{
		cout << "工号与原本工号重复！请重新输入..." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入您要创建的账号：" << endl;
	cin >> id;
	cout << "请输您的密码：" << endl;
	cin >> password1;
	cout << "请再次确认您的密码：" << endl;
	cin >> password2;
	if (password1 != password2)
	{
		cout << "您两次输入的密码不一致,请按任意键继续..." << endl;
		system("pause");
		system("cls");
		return;
	}
	string realname;//真实姓名
	string phonenum;//电话
	cout << "请输入您的真实姓名：" << endl;
	cin >> realname;
	cout << "请输您的电话号码：" << endl;
	cin >> phonenum;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	//将信息写入密码本中
	ofs << Num << " " << id << " " << password1 <<
		" " << realname << " " << phonenum << endl;
	cout << "您已成功创建了账号!请按任意键返回登录..." << endl;
	system("pause"); system("cls");
	this->MSOperMenu(1);
}

