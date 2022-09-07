#include"aqt.h"
//主要创建一个审批人额度授权的信息用于交互

//默认构造
ArlTable::ArlTable()
{
	this->m_key = 0;
	this->m_Role = "0";
	this->m_Money = 0;
}

//初始化，读取文件内容并且存储到vector容器中
void ArlTable::InitVAT()
{
	this->vAT.clear();
	ifstream ifs;
	ifs.open(STAFFAUIN, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	ArlTable a;
	while (ifs >> a.m_key && ifs >> a.m_Role && ifs >> a.m_Money && ifs >> a.m_Num)
	{
		this->vAT.push_back(a);
	}
	ifs.close();
}

//展示信息
void ArlTable::ShowInfo()
{
	this->InitVAT();
	int i=0;
	cout << "审批人额度授权表如下：" << endl;
	for (vector<ArlTable>::iterator it = this->vAT.begin(); it != this->vAT.end(); it++)
	{
		cout << it->m_key << " " << it->m_Role << " " << it->m_Money <<" " << it->m_Num << endl;
		i++;
	}
	cout << "共计共有" << i << "名审批人员" << endl;
	system("pause");
	system("cls");
}

//根据vector信息，存取到文件中
void ArlTable::SaveVAT(vector<ArlTable>a)
{
	ofstream ofs;
	ofs.open(STAFFAUIN, ios::out);
	for (vector<ArlTable>::iterator it = this->vAT.begin(); it != this->vAT.end(); it++)
	{
		ofs<< it->m_key << " " << it->m_Role << " " << it->m_Money << " "<<it->m_Num << endl;
	}
	ofs.close();
}

//获取容器的大小
int ArlTable::GetVATSize()
{
	this->InitVAT();
	int size = this->vAT.size();
	return size;
}

//获取创建时编号信息
int ArlTable::GetVATnum()
{
	this->InitVAT();
	if (this->vAT.size() == 0)
	{
		return 1;
	}
	int ret = this->vAT.rbegin()->m_key + 1;
	return ret;
}

//添加管理员的时候，同步更新授权表
void ArlTable::AddVAT(string role, int money, string num)
{
	ofstream ofs;
	ofs.open(STAFFAUIN, ios::app);
	int key=this->GetVATnum();
	ofs << key << " " << role << " " << money << " " << num << endl;
	ofs.close();
	cout << "添加到授权表中成功！" << endl;
}