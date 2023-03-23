#include <iostream>

using namespace std;

class Rectangle
{
	int _width, _height;

	public :
		int area()
		{
			return _width * _height;
		}
		int getWidth()
		{
			cin>>_width;
			return _width;
		}
		int getHeight()
		{
			cin>>_height;
			return _height;
		}
		void setHeight(int height)
		{
			if(height !=0 && height >0)
			{
				_height=height;
			}
		}
		void setWidth(int width)
		{
			if(width!=0 && width>0)
			{
				_width=width;
			}
		}
};

int main()
{
	int a,b;
	Rectangle obj;
	obj.getWidth();
	obj.getHeight();
	obj.setWidth(a);
	obj.setHeight(b);

	cout<<obj.area()<<endl;
	return 0;
}
