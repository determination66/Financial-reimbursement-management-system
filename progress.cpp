#include"progress.h"

//默认构造
Progress::Progress()
{
	this->m_Pnum=0;//提单编号

	this->m_Num="0";//工号

	this->m_Pmoney=0;//提单金额

	this->m_Date="2022/1/1";//提单日期

	this->m_State="初始";//状态

	this->m_Dealer="000";//处理人
}

//有参构造
Progress::Progress(int pnum, string num, int money, string date, string state, string dealer)
{
	//报单编号   提单人	  提单金额	   提单日期	   状态	处理人
	this->m_Pnum = pnum; this->m_Num = num;
	this->m_Pmoney = money; this->m_Date = date;
	this->m_State = state; this->m_Dealer = dealer;
}

//初始化容器报销人员进度
void Progress::InitVector()
{
	this->vPro.clear();
	ifstream ifs;
	ifs.open(PERSONINFO, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Progress p;
	/*int m_Pnum; 提单编号string m_Num; 工号int m_Pmoney;//提单金额
	string m_Date; 提单日期 string m_State; 状态 int m_Dealer;//处理人*/
	while (ifs >> p.m_Pnum && ifs >> p.m_Num && ifs >>
		p.m_Pmoney && ifs >> p.m_Date && ifs >> p.m_State && ifs >> p.m_Dealer)
	{
		this->vPro.push_back(p);
	}
	ifs.close();
}

//查询进展信息
void Progress::ShowPro()
{
	this->InitVector();
	/*int m_Pnum;//提单编号

	int m_Num;//工号

	int m_Pmoney;//提单金额

	string m_Date;//提单日期

	string m_State;//状态

	int m_Dealer;//处理人
*/
	cout << "所有进展的信息如下：" << endl;
	for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
	{
		cout << "报销单编号：" << it->m_Pnum << " 工号为：" << it->m_Num <<
			" 提单金额为：" << it->m_Pmoney<< " 提单日期为：" << it->m_Date 
			<< " 状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
	}
	cout << "共计：" << this->GetVproSize() << "条申请信息" << endl;
	system("pause");
	system("cls");
}

//获取当前日期的函数
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

//获取容器的大小
int Progress::GetVproSize()
{
	this->InitVector();
	int ret=this->vPro.size();
	return ret;
}

//创建时获取编号信息
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

//存储保存信息
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

//条件查询信息
void Progress::ShowConInfo()
{
	cout << "只能根据提单编号查询或者工号查询！" << endl;
	cout << "1.提单编号查询 2.工号查询 0.取消操作" << endl;
	cout << "请输入您的选择" << endl;
	string choice;
	cin >> choice;
	if (choice == "1")
	{
		cout << "请输入您要查询的提单编号：" << endl;
		int Pnum=0;//提单信息
		cin >> Pnum;
		this->InitVector();

		for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
		{
			if (it->m_Pnum == Pnum)//查询到了
			{
				cout << "提单编号为：" << it->m_Pnum << " 工号为：" << it->m_Num << " 提单金额为：" << it->m_Pmoney
					<< " 提单状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "未查询到相关结果！请检查您输入的正确性！" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == "2")
	{
		cout << "请输入您要查询的工号：" << endl;
		string num;
		cin >> num;
		this->InitVector();
		if (!this->IsExist(num))
		{
			cout << "此账号暂时没有报销信息！" << endl;
			system("pause");
			system("cls");
			return;
		}
		int i = 1;
		for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
		{
			if (it->m_Num == num)//查询到了
			{
				cout<<"第"<<i << "条结果：提单编号为：" << it->m_Pnum << " 工号为：" << it->m_Num << " 提单金额为：" << it->m_Pmoney
					<< " 提单状态为：" << it->m_State << " 处理人为：" << it->m_Dealer << endl;
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
		cout << "您输入的信息有误！" ;
		system("pause");
		system("cls");
	}
}

//根据工号判断进度是否存在
bool Progress::IsExist(string num)
{
	for (vector<Progress>::iterator it = this->vPro.begin(); it != this->vPro.end(); it++)
	{
		if (it->m_Num == num)//查询到了
		{
			return true;
		}
	}
	return false;
}