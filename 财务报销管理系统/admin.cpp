#include"admin.h"
#include"myvector.h"

//默认构造
Admin::Admin() {}

//有参构造
Admin::Admin(string id, string password)
{
	this->m_Id = id;
	this->m_Password = password;
}

//每个类的抽象函数，操作菜单
void Admin::OperMenu()
{
	while(true)
	{ 
		system("cls");
		//展示菜单的信息
		cout << "************************************欢迎管理员登录！************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.查询信息                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.添加账号                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.删除信息                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.注    销                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择: " ;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;
		switch (choice)
		{
		case 1://查询信息
			this->Oper1Menu();	
			break;
		case 2://添加账号
			this->AddPerson();
			break;
		case 3:
			this->Oper4Menu();
			break;
		case 0://注销账号，返回到上一级
			system("cls");
			ms.ShowMainMenu();
			break;
		default:	
			cout << "输入有误，请重新输入" << endl;
			//按任意键，清屏重新进入循环输出菜单
			system("pause");
			system("cls");
			break;
		}
	}
}

//展示管理员的信息
void Admin::ShowAdminInfo()
{
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Admin a;
	while (ifs >> a.m_Id && ifs >>a.m_Password)
	{
		cout << "账号为:" << a.m_Id<<" 密码为："<<a.m_Password << endl;
    }
	ifs.close();
	system("pause");
	system("cls");
}

//展示报销人员信息
void Admin::ShowPersonInfo()
{
	ifstream ifs;
	ifs.open(PERSON_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	cout << "报销人员的所有信息如下：" << endl;
	//工号 账号 密码 姓名 电话
	string num; string id; string password; string rname; string phone;
	while (ifs >>num && ifs >>id && ifs >>password&& ifs >>rname && ifs >>phone)
	{
		cout << "工号为:" <<num << " 账号为:" << id<<" 密码为："<<password << " 姓名为:" << rname << " 电话为:" << phone << endl;
	}
	ifs.close();
}

//展示审批人员信息
void Admin::ShowStaffInfo()
{
	ifstream ifs;
	ifs.open(STAFF_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Staff s;
	cout << "审批人员的所有信息如下：" << endl;
	while (ifs >> s.m_Num && ifs>> s.m_Id && ifs >>s.m_Password&& ifs >> s.m_RealName&& ifs >>s.m_PhoneNum&&ifs>>s.m_role)
	{
		cout << "工号为:" <<s.m_Num<< " 账号为:" << s.m_Id <<" 密码为："<<s.m_Password << " 姓名为:" << s.m_RealName << " 电话为:" <<
			s.m_PhoneNum<<	" 职责为:" << s.GetRole() <<" 审批额度为：" << s.GetCheckMoney() << endl;
	}
	ifs.close();
}

//展示分菜单1——查询界面信息
void Admin::Oper1Menu()
{
	while (true)
	{
		system("cls");
		//展示菜单的信息
		cout << "************************************欢迎管理员进入查询界面！************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1. 管理员信息                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.审批人员信息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.报销人员信息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    4.查询报销进展                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    5.  条件查询                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0. 返回上一级                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您要查询的的选择: "<<endl;
		int choice = 0;
		cin >> choice;
		Progress p;
		switch (choice)
		{
		case 1://查询管理员信息 
			this->ShowAdminInfo();
			break;
		case 2://查询审批人员信息
			this->ShowStaffInfo();
			system("pause");
			system("cls");
			break;
		case 3://查询报销人员信息
			this->ShowPersonInfo();
			system("pause");
			system("cls");
			break;
		case 4://查询报销进展
			p.ShowPro();
			break;
		case 5://根据条件进行查询
			p.ShowConInfo();
			break;
		case 0://返回上一级  
			this->OperMenu();
			break;
		default://输入错误
			cout << "输入有误，请按任意键继续！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//添加用户(报销人员 和审批人员)
void Admin::AddPerson()
{
	string filename, username, password;
	ofstream ofs;
	int select = 0;
	while (true)
	{
		//这一部分运行是成功的，在结束后可以试试switch语句
		cout << "1:添加报销人员\t2:添加工作人员：" << endl;
		cout << "3:添加管理员\t0:取消操作:" << endl;
		cout << "请输入添加账号的类型：" << endl;
		cin >> select;//选项
		MyVector v;
		if (select == 1)//添加报销人员
		{
			filename = PERSON_FILE;
			ofs.open(filename, ios::out | ios::app);
			string id;
			v.Showid(1);
			cout << "请输入工号:" << endl;
			cin >> id;//工号
			bool ret = v.IsRepeat(id, 1);
	
			if (!ret)
			{
				cout << "请输入账号：" << endl;
				cin >> username;//账号
				cout << "请输入密码:" << endl;
				cin >> password;//密码

				string name;//姓名
				cout << "请输入姓名:" << endl;
				cin >> name;
				string phone;//电话
				cout << "请输入电话号码:" << endl;
				cin >> phone;
				ofs << id << " " << username << " " << password << " " << name << " " << phone << endl;
				ofs.close();
				cout << "成功添加一名报销人员!" << endl;
				v.InitVPer();
				v.SaveVPer(v.vPer);
			}
			else
			{
				cout << "工号重复，请按任意键继续：" << endl;
			}
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)//添加工作人员
		{
			filename = STAFF_FILE;
			ofs.open(filename, ios::out | ios::app);
			Staff s;
			v.Showid(2);
			cout << "请输入工号:" << endl;
			cin >> s.m_Num;//工号
			bool ret=v.IsRepeat(s.m_Num,2);
	
			if (!ret)
			{
				cout << "请输入账号：" << endl;
				cin >> s.m_Id;//账号
				cout << "请输入密码:" << endl;
				cin >> s.m_Password;//密码
				cout << "请输入姓名:" << endl;
				cin >> s.m_RealName;
				cout << "请输入电话号码:" << endl;
				cin >> s.m_PhoneNum;
				cout << "1:财务主管\t2:部门主管" << endl;
				cout << "3:财务副主管\t4:部门副主管" << endl;
				cout << "请输入职责对应的编号：(输入其他数字，请重新输入...)" << endl;
				do {
					cin >> s.m_role;
				   } while (s.m_role<1 ||s.m_role>4);
				ofs << s.m_Num << " " << s.m_Id << " " << s.m_Password
					<< " " << s.m_RealName << " " << s.m_PhoneNum << " " <<
					s.m_role << endl;
				ofs.close();
				v.InitVSta();
				v.SaveVSta(v.vSta);
				//在这里添加到信息表中，还要添加到授权表,比较重要
				cout << "成功添加一名审批人员" << endl;
				ArlTable a;
				a.AddVAT(s.GetRole(), s.GetCheckMoney(), s.m_Num);//添加到授权表中
			}
			else
			{
				cout << "工号重复，请按任意键继续：" << endl;
			}

			system("pause");
			system("cls");
			return;
		}
		else if (select == 3)//添加管理员
		{
			filename = ADMIN_FILE;
			ofs.open(filename, ios::out | ios::app);
			v.Showid(3);
			cout << "请输入账号：" << endl;
			cin >> username;
			bool ret = v.IsRepeat(username,3);

			if (!ret) //没有重复
			{
			cout << "请输入密码：" << endl;
			cin >> password;
			ofs << username << " " << password << endl;
			ofs.close();
			cout << "成功添加一名管理员！" << endl;
			//文件没有即使保存，目前还有一个小bug
			v.InitVAdm();
			v.SaveVAdm(v.vAdm);
			}
			else 
			{
				cout << "用户名重复，请按任意键继续：" << endl;
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
		else//输入错误
		{
			cout << "输入有误，请按任意键继续！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//展示删除信息4的分页面
void Admin::Oper4Menu()
{
	while (true)
	{
		system("cls");
		//展示菜单的信息
		cout << "************************************欢迎管理员登录！************************************" << endl;
		cout << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.报销人员信息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.审批人员信息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0. 返回上一级                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您要删除的选择: " << endl;
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
		case 0://返回上一级  
			this->OperMenu();
			break;
		default://输入错误
			cout << "输入有误，请按任意键继续！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//删除人员信息
void Admin::DeletePerson(int type)
{
	MyVector v;

	if (type == 1)//删除报销人员信息
	{
		this->ShowPersonInfo();
		cout << "请输入您要删除账号的工号:" << endl;
		string num;//选项
		cin >> num;
		//删除报销人员信息
		//然后进行显示信息
			v.InitVPer();
		for (vector<Person>::iterator it = v.vPer.begin(); it != v.vPer.end(); it++)
		{
			if (num == it->m_Num)
			{
				/*cout << "您要删除的报销人员信息为:"<<endl<<"工号" << it->m_Num << " 账号为：" 
					<< it->m_Id << " 密码为:" << it->m_Password<< " 姓名为:" << it->m_RealName 
					<< " 电话为:" << it->m_PhoneNum << endl;*/
				cout << "您确认信息，是否要进行删除  请输入Y/y代表是,N/n代表否" << endl;
				cout << "删除后将会在报销人员信息和进度信息中删除..." << endl;
				string b;//输出选择
				cin >> b;
				if (b == "Y" || b == "y")//那么就开启删除模式，删除该账号信息和进度信息
				{
					v.vPer.erase(it);
					v.SaveVPer(v.vPer);//删除信息
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
					cout << "操作完毕，已成功删除！" << endl;
				}
				else if (b == "N" || b == "n")
				{
					cout << "已取消删除" << endl;
				}
				else
				{
					cout << "您的输入有误，已取消删除!" << endl;
				}
				system("pause"); system("cls"); return;
			}
		}
		cout << "未查询到此报销人员！" << endl;
	}
	//删除审批人员信息
	else
	{
		this->ShowStaffInfo();
		cout << "请输入您要删除账号的工号:" << endl;
		string num;//选项
		cin >> num;

        v.InitVSta();
		for (vector<Staff>::iterator it = v.vSta.begin(); it != v.vSta.end(); it++)
		{
			if (num == it->m_Num)//显示信息
			{
				/*Staff s(it->m_Num, it->m_Id, it->m_Password, it->m_RealName, it->m_PhoneNum, it->m_role);
				cout << "您将要删除的信息为:" << endl;
				s.ShowOwnInfo();*/
				cout << "您确认信息，是否要进行删除  请输入Y/y代表是,N/n代表否" << endl;
				cout << "删除后将会在报销人员信息和授权表中删除..." << endl;
				string b;//输出选择
				cin >> b;
				if (b == "Y" || b == "y")//那么就开启删除模式，删除该账号信息和进度信息
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
					cout << "操作完毕!" << endl;
				}
				else if (b == "N" || b == "n")
				{
					cout << "已取消删除！" << endl;
				}
				else
				{
					cout << "您的输入有误，已取消删除!" << endl;
				}
				system("pause"); system("cls"); return;
			}
		}
		cout << "未查询到此审批人员！" << endl;
	}
	system("pause");
	system("cls");
	return;
}