#include <iostream>
#include <stdio.h>

using namespace std;

class Rect
{
	int width;
	int breath;

	public :
	Rect(int w, int b)
	{
		width =w;
		breath=b;
	}

	friend int add (Rect r);
	friend class Area;
};

class Area
{
	public :
		Area(Rect r)
		{
			cout<<r.width*r.breath<<endl;
		}
		
};
int add (Rect a)
{
	return a.width*a.breath;
}

int main()
{
	Rect r(2,4);
	Area a(r);
	cout <<add(r)<<endl;
}
