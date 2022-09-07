#include"myvector.h"

//初始化容器报销人员
void MyVector::InitVPer()
{
	this->vPer.clear();
	ifstream ifs;
	ifs.open(PERSON_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Person test;
	while (ifs >> test.m_Num && ifs >> test.m_Id && ifs >> test.m_Password && ifs >> test.m_RealName&& ifs >> test.m_PhoneNum)
	{
		this->vPer.push_back(test);
	}
	//cout << "报销人员人数" << this->vPer.size() << endl;
	ifs.close();
}

//审批人员
void MyVector::InitVSta()
{
	//初始化审批人员容器
	this->vSta.clear();
	ifstream ifs;
	ifs.open(STAFF_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Staff test;//工号 账号 密码 真实姓名 电话 职责
	while (ifs >> test.m_Num && ifs >> test.m_Id && ifs >> test.m_Password && ifs >> test.m_RealName && ifs >> test.m_PhoneNum&&ifs>>test.m_role)
	{
		this->vSta.push_back(test);
	}
	ifs.close();
}

//管理员
void MyVector::InitVAdm()
{
	//初始化管理员容器,为添加去重复做铺垫
	//清空容器内部
	this->vAdm.clear();
	ifstream ifs;
	ifs.open(ADMIN_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Admin test;
	while (ifs >> test.m_Id && ifs >> test.m_Password)
	{
		this->vAdm.push_back(test);

	}
	ifs.close();
}

//存储报销人员信息
void MyVector::SaveVPer(vector<Person>p)
{
	ofstream ofs;
	ofs.open(PERSON_FILE, ios::out);
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Id << " " << it->m_Password <<
			" " << it->m_RealName << " " << it->m_PhoneNum<< endl;
	}
	ofs.close();
}

//存储审批人员信息
void MyVector::SaveVSta(vector<Staff>p)
{

	ofstream ofs;
	ofs.open(STAFF_FILE, ios::out);
	for (vector<Staff>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs << it->m_Num << " " << it->m_Id << " " << it->m_Password <<
			" " << it->m_RealName << " " << it->m_PhoneNum <<" "<<it->m_role << endl;
	}

	ofs.close();
}

//存储管理员信息
void MyVector::SaveVAdm(vector<Admin>p)
{
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out);
	for (vector<Admin>::iterator it = p.begin(); it != p.end(); it++)
	{
		ofs <<  it->m_Id << " " << it->m_Password << endl;
	}
	ofs.close();
}

//判断工号是否重复，为创建新信息做铺垫
bool MyVector::IsRepeat(string num, int type)//工号 类型
{
	if (type == 1)//报销人员
	{
		this->InitVPer();
		for (vector<Person>::iterator it = this->vPer.begin(); it != this->vPer.end(); it++)
		{
			if (it->m_Num == num)
			{
				return true;//有重复工号
			}
		}
	}
	else if (type == 2)//审批人员
	{
		this->InitVSta();
		for (vector<Staff>::iterator it = this->vSta.begin(); it != this->vSta.end(); it++)
		{
			if (it->m_Num == num)
			{
				return true;//有重复工号
			}
		}
	}
	else 
	{
		this->InitVAdm();
		for (vector<Admin>::iterator it = this->vAdm.begin(); it != this->vAdm.end(); it++)
		{
			if (it->m_Id == num)
				return true;
		}
	}
	return false;
}

//展示已有工号
void MyVector::Showid(int type)
{
	if (type == 1)//报销人员
	{
		this->InitVPer();
		cout << "当前已存在的工号如下：" << endl;
		for (vector<Person>::iterator it=this->vPer.begin();it!=this->vPer.end();it++)
		{
			cout <<it->m_Num << ",";
		}
	}
	else if (type == 2)
	{
		this->InitVSta();
		cout << "当前已存在的工号如下：" << endl;
		for (auto it = this->vSta.begin(); it != this->vSta.end(); it++)
		{
			cout << it->m_Num << ",";
		}
	}
	else
	{
		this->InitVAdm();
		cout << "当前已有的管理员id如下：" << endl;
		for (auto it = this->vAdm.begin(); it != this->vAdm.end(); it++)
		{
			cout << it->m_Id << ",";
		}
	}
}