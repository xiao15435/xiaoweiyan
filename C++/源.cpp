#include<iostream>
#include<iomanip>/
using namespace std;
struct point //����ṹ��
{
	int x;
	int y;
};

struct Rect
{
    public:
	int m_ID;
	int m_color;//����0��ɫ��1��ɫ
	point m_left1;//���Ͻ�����
	int  m_width;
	int  m_height;
//�����Ǹ��������ݸ�ֵ�ĺ���,
	void input()
	{
		cin >> m_ID >> m_color >> m_left1.x;
			cin>>m_left1.y >> m_width >> m_height;
	}
};

class Armor
{
    public:
	Rect a;  //���￴���棬������Rect�����������͵�����,�����ҽ�ÿ������ļ���������װ��һ���ˡ�
	void  Central_Point()
	{
		double l = (a.m_left1.x + a.m_width / 2);//x����
		double r = (a.m_left1.y + a.m_height / 2);//y����
		cout << "( " << l << "," << r << " ) ";

	}
	void Diagonal()
	{
		double result = (a.m_width * a.m_width) + (a.m_height * a.m_height);
		double  xlong = sqrt(result) ;//�Խ��߳���,
		cout << "���ȣ�"<<fixed<<setprecision(2) << xlong << endl;
	}
	void Armor_Color()
	{
		if (a.m_color == 0)
		{
			cout << "��ɫ" << endl;
		}
		else
		{
			cout << "��ɫ" << endl;
		}
	}
	void Armor_Point()
	{//˳ʱ���������
		cout << "( " << a.m_left1.x << "," << a.m_left1.y << ") ";
		cout << "( " << a.m_left1.x + a.m_width << "," << a.m_left1.y << ") ";
		cout << "( " << a.m_left1.x + a.m_width << "," << a.m_left1.y + a.m_height << " ) ";
		cout << "( " << a.m_left1.x << "," << a.m_left1.y + a.m_height << ") ";

	}


};
//�����ǽṹ���������á�
int main()
{
	Armor  armor{};    //����һ��װ�װ��������������ֵ,����Armor�������Rect a����ĸ�ֵ�ĺ���
	armor.a.input();
	
	cout << "ID:" << armor.a.m_ID << "  ��ɫ�� "; 
	armor.Armor_Color();
	armor.Central_Point();
	armor.Diagonal();
	armor.Armor_Point();
	system("pause");
	return 0;
}   