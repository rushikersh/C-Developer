#include <iostream>

using namespace std;

class Point
{
	int x,y;

	public:
	Point (int a,int b):x(a),y(b){}
	Point (){}
	Point(const Point &T)
	{
		x=T.x;
		y=T.y;
	}
	Point operator + (Point & T)
	{
		Point q;
		q.x=x+T.x;
		q.y=y+T.y;
		return q;
	}

	void display()
	{
		cout<<x<<" "<<y<<endl;
	}
};

inline void Print()
{
	cout<<"print\n";
}
int main()
{
	Point P1(2,4),P2(4,7);
	Point P3=P1+P2;
	Point P4=P2;
	P2.display();
	P3.display();
	P4.display();
	Print();
}
