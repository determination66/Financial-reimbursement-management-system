#include"person.h"
#include"myvector.h"
#include<map>

//默认构造
Person::Person() {}

//工号 账号 密码 真实姓名 电话 有参构造
Person::Person(string num, string id, string password, string rname, string phone)//有参构造
{
	this->m_Num = num;
	this->m_Id = id;
	this->m_Password = password;
	this->m_RealName = rname;
	this->m_PhoneNum = phone;
}

//展示操作界面
void Person::OperMenu() 
{
	while (true)
	{
		//展示菜单的信息
		cout << "************************************欢迎报销人员登录！************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1.查 询 信  息                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2.修 改 信  息                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3.报 销 处  理                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0.注        销                   |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择:" << endl;
		int choice = 0;
		cin >> choice;
		ManageSystem ms;//后续调用
		switch (choice)
		{
		case 1://查询个人信息
			this->Oper1Mune();
			break;
		case 2://修改信息
			this->ChangeInfo();
			break;
		case 3://报销处理
			this->Oper3Mune();
			break;
		//case 3://申请报表
		//	this->ApplyChart();
		//	break;
		//case 4://取消申请
		//	this->CancelChart();
		//	break;
		//case 5://最终付款
		//	this->PayMoney();
		//	break;
		case 0:
			ms.ShowMainMenu();
			break;
		default:	cout << "输入有误，请重新输入" << endl;
			//按任意键，清屏重新进入循环输出菜单
			system("pause");
			system("cls");
			break;
		}
	}
}

//展示分菜单1——查询界面
void Person::Oper1Mune()
{
	
	while (true)
	{
		system("cls");
		//展示菜单的信息
		cout << "************************************欢迎报销人员查询！************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1. 个  人  信  息                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2. 个  人  进  度                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3. 审 批 授 权 表                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   4. 条  件  查  询                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0. 返 回 上 一 级                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择:" << endl;
		int choice = 0;
		cin >> choice;
		ArlTable a;
		Progress p;
		switch (choice)
		{
		case 1://查询个人信息
			this->ShowOwnInfo();
			system("pause");
			system("cls");
			break;
		case 2:// 2. 个  人  进  度
			this->ShowOwnProgress();
			break;
		case 3:
			//上面创建了一个ArlTable类的一个对象 a
			a.ShowInfo();
			break;
		case 4://条件查询
			p.ShowConInfo();
			break;
		case 0:
			system("cls");
			this->OperMenu();
			break;
		default:	cout << "输入有误，请重新输入" << endl;
			//按任意键，清屏重新进入循环输出菜单
			system("pause");
			system("cls");
			break;
		}
	}
}

//展示分菜单3——报销
void Person::Oper3Mune()
{
	while(true)
	{
		system("cls");
		//展示菜单的信息
		cout << "************************************欢迎您进入报销处理界面！************************************" << endl;
		cout << endl << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   1. 申  请  报  表                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   2. 取  消  申  请                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   3. 最  终  付  款                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t|                   0. 返 回 上 一 级                |" << endl;
		cout << "\t\t|                                                    |" << endl;
		cout << "\t\t ----------------------------------------------------" << endl;
		cout << "请输入您的选择:" << endl;
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
			cout << "输入有误，请重新输入" << endl;
			//按任意键，清屏重新进入循环输出菜单
			system("pause");
			system("cls");
			break;
		}
	}
}

//申请报表信息，并且交互到文件中
void Person::ApplyChart()
{
	int money = 0;
	cout << "请输入您要提单的金额：" << endl;
	cout << "金额必须＞0元，否责请重新输入!!!" << endl;
	do
	{ 
	cin >> money; 
	} while (money <=0);
	
	Progress p;
	//int num=p.GetVproSize();
	//提单编号   工号   提单金额   提单日期   状态  处理人 分别进行赋值
	p.m_Pnum =p.GetVpronum(); p.m_Num = this->m_Num;
	p.m_Pmoney = money; p.m_Date = p.GetDate(); p.m_State = "创建";
	p.m_Dealer = this->m_Num;
	ofstream ofs;
	ofs.open(PERSONINFO, ios::out | ios::app);
	ofs << p.m_Pnum << " " << p.m_Num << " " << p.m_Pmoney << " "
		<< p.m_Date << " " << p.m_State << " " << p.m_Dealer<<endl;
	ofs.close();
	cout << "成功申请！";
	system("pause");
	system("cls");
}

//修改账号信息,只能改账号密码和电话
void Person::ChangeInfo()
{
	//cout << "只能修改账号，密码和电话号码!..." << endl;
	system("cls");
	cout << "************************************欢迎进入修改界面！************************************" << endl;
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
	v.InitVPer();
	int j = 0;
	for (vector<Person>::iterator it = v.vPer.begin(); it != v.vPer.end(); it++)
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
						v.vPer.erase(v.vPer.begin() + j);
						v.vPer.insert(v.vPer.begin() + j, *this);
						v.SaveVPer(v.vPer);
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
				system("pause");
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
						v.vPer.erase(v.vPer.begin() + j);
						//把自身属性修改后插入vector容器相应位置中
						v.vPer.insert(v.vPer.begin() + j, *this);
						v.SaveVPer(v.vPer);
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
				system("pause");
			}
			else if (choice == "3")
			{
				string phone;
				cout << "请输入您的新电话号码："; cin >> phone;
					//工号 账号 密码 真实姓名 电话
				    this->m_PhoneNum = phone;
					v.vPer.erase(v.vPer.begin() + j);
					v.vPer.insert(v.vPer.begin() + j, *this);
					v.SaveVPer(v.vPer);
					cout << "电话修改成功!";
					system("pause");
			}
			else if(choice == "0");//取消操作
			else
			{
				cout << "输入选项错误!" << endl;
				system("pause");
			}
			//system("pause");
			system("cls");
			return;
		}
		j++;
	}
}

//查询个人进展
void Person::ShowOwnProgress()
{
	Progress p;
	p.InitVector();
	if (!this->IsProgress())
		cout << "您的记录为空，请按任意键继续..." << endl;
	else
	{
		cout << "您个人申报的信息如下：" << endl;
		int i=0;//用于计算有几条报销信息
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num)
			{
				cout <<"第"<<i << "条：提单编号为：" << it->m_Pnum << " 工号为：" << it->m_Num << " 提单金额为：" << it->m_Pmoney
					<<" 提单日期："<<it->m_Date << " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				i++;
			}		
		}
		cout << "总计有" << i << "条报销信息" << endl;
	}
	system("pause");
	system("cls");
}

//查询是否有申请的进展
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
		if (it->m_Num == this->m_Num&&it->m_State=="财务审批")
			return true;
	}
	return false;
}

//取消报表
void Person::CancelChart()
{
	Progress p;
	p.InitVector();
	if (!this->IsProgress()) {
		cout << "您的记录为空，请按任意键继续..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		//记录第几条
		int i = 1; int num = 0;
		map<int, int>m;
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num)
			{
				cout << "第" << i << "条:提单编号为：" << it->m_Pnum << " 工号为：" << it->m_Num << " 提单金额为：" << it->m_Pmoney
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				m.insert(make_pair(i,num));
				i++;	
			}
			num++;
		}
	/*	for (int m1 = 1; m1 < i; m1++)
		{
			cout << "测试代码！" << endl;
			cout << m[m1] << endl;

		}*/
		cout << "您想要取消哪一条,如果您输入0 则取消操作" << endl;
		int choice;//选择
		cin >> choice;
		if (choice > 0 && choice <= i - 1)
		{
			p.vPro.erase(p.vPro.begin() +m[choice]);
			p.SaveVProgress(p.vPro);
			cout << "删除成功！" << endl;
		}
		else if (choice == 0)
			cout<<"取消操作成功！";//取消操作
		else
		{
			cout << "输入错误,请按任意键继续：" << endl;
		}
			system("pause");
			system("cls");
			return;	
	}
}

//最终付款
void Person::PayMoney()
{
	Progress p;
	p.InitVector();
	if (!this->IsPay()) {
		cout << "您的记录为空，请按任意键继续..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		int i = 1; int j = 0;
		for (vector<Progress>::iterator it = p.vPro.begin(); it != p.vPro.end(); it++)
		{
			if (it->m_Num == this->m_Num && it->m_State == "财务审批")
			{
				cout << "第" << i << "条:提单编号为：" << it->m_Pnum << " 工号为：" << it->m_Num << " 提单金额为：" << it->m_Pmoney
					<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				cout << "您是否要付款？y/Y（是）\tn/N（不是）..." << endl;
				string c;//判断通过与否
				cin >> c;
				if (c == "y" || c == "Y")
				{
					//cout << "通过，然后改日期，状态（部门审批）和处理人，后保存" << endl;
					//报单编号   提单人	  提单金额	   提单日期	   状态	处理人
					//这一顿操作就是修改信息，我已经麻了,输入错误则不会修改进展
					string state = "付款结束";
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
					cout << "您输入错误，默认未付款，请先进行下一个的选项..." << endl;
				}
				i++;
				system("pause");
			}
			j++;
		}
	}
	system("cls");
}

//展示个人信息
void Person::ShowOwnInfo()
{
	cout << "您的信息如下：" << endl;
	cout << "工号为:" << this->m_Num << " 账号为:" << this->m_Id
					<< " 姓名为:" << this->m_RealName << " 电话为:" << this->m_PhoneNum << endl;
}