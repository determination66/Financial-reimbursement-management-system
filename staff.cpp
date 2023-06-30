#include"staff.h"
#include"myvector.h"

//默认构造
Staff::Staff()
{
	this->m_role = 0;

}

//有参构造
Staff::Staff(string num, string id, string password, string rname, string phonenum, int role)
{
	this->m_Num = num;
	this->m_Id = id;
	this->m_Password = password;
	this->m_RealName = rname;
	this->m_PhoneNum = phonenum;
	this->m_role = role;
}

//每个类的抽象函数，操作菜单
void Staff::OperMenu()
{
	while (true)
	{
		//展示菜单的信息
		cout << "************************************欢迎审批人员登录！************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    1.查询信息                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    2.修改信息                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    3.审批信息                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                    0.注    销                      |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择:" << endl;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;
		switch (choice)
		{
		case 1:
			this->Oper1Menu();
			break;
		case 2://修改信息
			this->ChangeInfo();
			break;
		case 3://审批信息
			this->AprovePerson();
			break;
		case 0://注销
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

//返回职责
string Staff::GetRole()
{
	switch (this->m_role)
	{
	case 1:
		return "财务主管";
	case 2:
		return "部门主管";
	case 3:
		return "财务副主管";
	case 4:
		return "部门副主管";
	default:
		return "错误";
	}
}

//返回最大额度授权
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

//进入分界面1——查询界面
void Staff::Oper1Menu()
{
	system("cls");
	while (true)
	{
		cout << "************************************欢迎审批人员进入查询界面！************************************" << endl;
		cout << endl << endl;
		//展示分菜单1的信息
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  1.待 审 批 信 息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  2.审  批  人  员                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  3.管    理    员                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  4.报  销  人  员                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  5.个  人  信  息                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                  0.返 回 上 一 级                  |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择:" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://查询待审批信息
			this->ShowApproval();
			break;
		case 2://审批人员信息
		this->ShowStaffInfo();
			break;
		case 3://管理员信息
			this->ShowAdminInfo();
			break;
		case 4://报销人员信息
			this->ShowPersonInfo();
			break;
		case 5://查询个人信息
			this->ShowOwnInfo();
			system("pause");
			system("cls");
			break;
		case 0://返回到上一级
			system("cls");
			this->OperMenu();
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

//展示待审批人员的信息,只展示额度范围内的所有信息
void Staff::ShowApproval()
{
	if (!this->IsExistAprove())
	{
		cout << "您当前没有待审批信息！";
		system("pause"); system("cls");
		return;
	}
	Progress p;
	p.InitVector();
	int i=1;//显示条数，展示其中的几条
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "创建")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//部门副主管审批审批
			{
				cout<<"第"<<i<<"条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				i++;
			}
			else if (it->m_Pmoney>50000&&it->m_Pmoney <= 100000 && this->m_role == 2)//部门主管的待审批信息
			{
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				i++;
			}
		}
		else if (it->m_State == "部门审批")
		{
			if (it->m_Pmoney <= 50000 && this->m_role ==3)//财务副主管审批审批
			{
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 1)//财务主管的待审批信息
			{
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				i++;
			}
		}
	}
	system("pause");
	system("cls");
}

//审批函数
void Staff::AprovePerson()
{
	if (!this->IsExistAprove())
	{
		cout << "您当前没有待审批信息！";
		system("pause"); system("cls");
		return;
	}
	Progress p;
	p.InitVector();
	int i = 1;//显示条数，展示其中的几条
	int j = 0;//找出下标
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "创建")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//部门副主管审批审批
			{
				system("cls");
				cout << "************************************欢迎进行审批！************************************" << endl;
				cout << endl << endl;
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << endl;
				cout << "请进行审批，Y/y（通过）N/n（不通过）...,输入P/p先终止返回菜单" << endl;
				string c;//判断通过与否
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "通过，然后改日期，状态（部门审批）和处理人，后保存" << endl;
					//报单编号   提单人	  提单金额	   提单日期	   状态	处理人
					//这一顿操作就是修改信息，我已经麻了,输入错误则不会修改进展
					string state="部门审批";
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
					//cout << "不通过，日期，状态（创建），处理人,保存" << endl;
					string state = "创建";
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
					cout << "输入错误！"; system("pause");
				}
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 2)//部门主管的待审批信息
			{
				system("cls");
				cout << "************************************欢迎进行审批！************************************" << endl;
				cout << endl << endl;
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << endl;
				cout << "请进行审批，Y/y（通过）N/n（不通过）...,输入P/p先终止返回菜单" << endl;
				string c;
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "通过，然后改日期，状态（部门审批）和处理人，后保存" << endl;
					string state = "部门审批";
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
					//cout << "不通过，日期，状态（创建），处理人,保存" << endl;
					string state = "创建";
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
					cout << "输入错误！"; system("pause");
				}
				i++;
			}
		}
		else if (it->m_State == "部门审批")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 3)//财务副主管审批审批
			{
				system("cls");
				cout << "************************************欢迎进行审批！************************************" << endl;
				cout << endl << endl;
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				cout << "请进行审批，Y/y（通过）N/n（不通过）...,输入P/p先终止返回菜单" << endl;
				string c;//选y/n的
				cin >> c;
				if (c == "y" || c == "Y")
				{
					/*cout << "通过，然后改日期，状态（财务审批）和处理人，后保存" << endl;	*/
					string state = "财务审批";
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
					//cout << "不通过，日期，状态（创建），处理人,保存" << endl;
					string state = "创建";
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
					cout << "输入错误！"; system("cls");
				}
				i++;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 1)//财务主管的待审批信息
			{
				system("cls");
				cout << "************************************欢迎进行审批！************************************" << endl;
				cout << endl << endl;
				cout << "第" << i << "条： 报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
					" 提单金额为：" << it->m_Pmoney << " 提单日期为：" << it->m_Date
					<< " 状态为：" << it->m_State<< endl;
				cout << "请进行审批，Y/y（通过）N/n（不通过）...,输入P/p先终止返回菜单" << endl;
				string c;
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "通过，然后改日期，状态（财务审批）和处理人，后保存" << endl;
					string state = "财务审批";
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
					//cout << "不通过，日期，状态（创建），处理人,保存" << endl;
					string state = "创建";
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
					cout << "输入错误！"; system("pause");
				}
				i++;
			}
		}
		j++;
	}
	system("pause");
	system("cls");
}

//判断是否存在审批信息
bool Staff::IsExistAprove()
{
	Progress p;
	p.InitVector();
	for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
	{
		if (it->m_State == "创建")
		{
			if (it->m_Pmoney <= 50000 && this->m_role == 4)//部门副主管审批审批
			{
				return true;
			}
			else if (it->m_Pmoney > 50000 && it->m_Pmoney <= 100000 && this->m_role == 2)
			{
				return true;
			}
		}
		else if (it->m_State == "部门审批")
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

//查询管理员信息
void Staff::ShowAdminInfo()
{
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Admin a;
	while (ifs >> a.m_Id && ifs >> a.m_Password)
	{
		cout << "账号为:" << a.m_Id <<endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//查询报销人员信息
void Staff::ShowPersonInfo()
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
	while (ifs >> num && ifs >> id && ifs >> password && ifs >> rname && ifs >> phone)
	{
		cout << "工号为:" << num << " 账号为:" << id << " 密码为：" << password << " 姓名为:" << rname << " 电话为:" << phone << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//查询审批人员信息
void Staff::ShowStaffInfo()
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
	while (ifs >> s.m_Num && ifs >> s.m_Id && ifs >> s.m_Password && ifs >> s.m_RealName && ifs >> s.m_PhoneNum && ifs >> s.m_role)
	{
		cout << "工号为:" << s.m_Num << " 账号为:" << s.m_Id <<" 姓名为:" << s.m_RealName << " 电话为:" <<
			s.m_PhoneNum << " 职责为:" << s.GetRole()<<" 审批额度为："<<s.GetCheckMoney() << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//查询个人信息
void Staff::ShowOwnInfo()
{
	cout << "您的信息如下：" << endl;
	cout << "工号为:" << this->m_Num << " 账号为:" << this->m_Id
		<< " 姓名为:" << this->m_RealName << " 电话为:" << this->m_PhoneNum <<" 职责为："<<this->GetRole() << endl;
}

//修改个人信息
void Staff::ChangeInfo()
{
	//cout << "只能修改账号，密码和电话号码!..." << endl;
	system("cls");
	cout << "************************************欢迎审批人员进入修改界面！************************************" << endl;
	cout << endl << endl;
	cout << "\t\t ----------------------------------------------------" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  1. 修  改  账  号                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  2. 修  改  密  码                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  3. 修  改  电  话                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t|                  0. 取  消  操  作                 |" << endl;
	cout << "\t\t|                                                    |" << endl;
	cout << "\t\t ----------------------------------------------------" << endl;
	this->ShowOwnInfo();//展示个人信息
	cout << "请输入您要进行的选择:";
	MyVector v;
	v.InitVSta();
	int j = 0;
	for (vector<Staff>::iterator it = v.vSta.begin(); it != v.vSta.end(); it++)
	{
		if (it->m_Num == this->m_Num)
		{
			string choice; //选择
			cin >> choice;
			if (choice == "1")
			{
				string Oripsw;
				cout << "请输入原密码进行身份确认:"; cin >> Oripsw;
				if (Oripsw == this->m_Password)
				{
					string id1, id2;
					cout << "请输入新的账号:"; cin >> id1;
					cout << "请再次确认新账号："; cin >> id2;
					if (id1 == id2)
					{
						//工号 账号 密码 真实姓名 电话
						this->m_Id = id1;
						v.vSta.erase(v.vSta.begin() + j);
						v.vSta.insert(v.vSta.begin() + j, *this);
						v.SaveVSta(v.vSta);
						cout << "账号修改成功!";
					}
					else
					{
						cout << "两次输入的新账号不一致!" << endl;
					}
				}
				else
				{
					cout << "身份验证失败,无法进行修改！";
				}
			}
			else if (choice == "2")
			{
				string Oripsw;
				cout << "请输入原密码进行身份确认:"; cin >> Oripsw;
				if (Oripsw == this->m_Password)
				{
					string psw1, psw2;
					cout << "请输入新的密码:"; cin >> psw1;
					cout << "请再次确认新密码："; cin >> psw2;
					if (psw1 == psw2)
					{
						//工号 账号 密码 真实姓名 电话
						this->m_Password = psw1;//新密码
						v.vSta.erase(v.vSta.begin() + j);
						//把自身属性修改后插入vector容器相应位置中
						v.vSta.insert(v.vSta.begin() + j, *this);
						v.SaveVSta(v.vSta);
						cout << "密码修改成功!" << endl;
					}
					else
					{
						cout << "两次输入的新密码不一致!" << endl;
					}
				}
				else
				{
					cout << "身份验证失败,无法进行修改！";
				}
			}
			else if (choice == "3")
			{
				string phone;
				cout << "请输入您的新电话号码："; cin >> phone;
				//工号 账号 密码 真实姓名 电话
				this->m_PhoneNum = phone;
				v.vSta.erase(v.vSta.begin() + j);
				v.vSta.insert(v.vSta.begin() + j, *this);
				v.SaveVSta(v.vSta);
				cout << "电话修改成功!";
			}
			else if (choice == "0");//取消操作
			else
			{
				cout << "输入选项错误!" << endl;
			}
			system("pause");
			system("cls");
			return;
		}
		j++;
	}
}
