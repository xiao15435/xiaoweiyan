#include<iostream>
#include<iomanip>/
using namespace std;
struct point //坐标结构体
{
	int x;
	int y;
};

struct Rect
{
    public:
	int m_ID;
	int m_color;//输入0蓝色，1红色
	point m_left1;//左上角坐标
	int  m_width;
	int  m_height;
//以下是给各项数据赋值的函数,
	void input()
	{
		cin >> m_ID >> m_color >> m_left1.x;
			cin>>m_left1.y >> m_width >> m_height;
	}
};

class Armor
{
    public:
	Rect a;  //这里看上面，上面是Rect这种数据类型的设置,下面我将每个结果的计算和输出封装到一起了。
	void  Central_Point()
	{
		double l = (a.m_left1.x + a.m_width / 2);//x坐标
		double r = (a.m_left1.y + a.m_height / 2);//y坐标
		cout << "( " << l << "," << r << " ) ";

	}
	void Diagonal()
	{
		double result = (a.m_width * a.m_width) + (a.m_height * a.m_height);
		double  xlong = sqrt(result) ;//对角线长度,
		cout << "长度："<<fixed<<setprecision(2) << xlong << endl;
	}
	void Armor_Color()
	{
		if (a.m_color == 0)
		{
			cout << "蓝色" << endl;
		}
		else
		{
			cout << "红色" << endl;
		}
	}
	void Armor_Point()
	{//顺时针输出坐标
		cout << "( " << a.m_left1.x << "," << a.m_left1.y << ") ";
		cout << "( " << a.m_left1.x + a.m_width << "," << a.m_left1.y << ") ";
		cout << "( " << a.m_left1.x + a.m_width << "," << a.m_left1.y + a.m_height << " ) ";
		cout << "( " << a.m_left1.x << "," << a.m_left1.y + a.m_height << ") ";

	}


};
//以上是结构体和类的设置。
int main()
{
	Armor  armor{};    //设置一个装甲板变量，给变量赋值,调用Armor类里面的Rect a里面的赋值的函数
	armor.a.input();
	
	cout << "ID:" << armor.a.m_ID << "  颜色： "; 
	armor.Armor_Color();
	armor.Central_Point();
	armor.Diagonal();
	armor.Armor_Point();
	system("pause");
	return 0;
}   