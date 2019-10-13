#include <iostream>
//#include "Main_Header.h"
//int const G = 10;
struct dot
{
	float x;
	float y;
};
struct circle
{
	dot coord;
	float r;
};
struct square
{
	dot coord;
	float a;
};
float area(circle circle)
{
	return 3.1415926 * circle.r * circle.r;
}
float area(square square)
{
	return square.a * square.a;
}
//bool is_same_dot(dot a, dot b) {}

bool operator == (dot lhs, dot rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y) { return true; }
	else { return false; }
}
bool operator != (dot lhs, dot rhs)
{
	return !(lhs == rhs);
}
dot operator *(dot d, float n)
{
	return dot{ d.x * n, d.y * n };
}
int add(int x, int y)
{
	return x + y;
}
int main()
{
	dot d{ 1,2 };
	//setlocale(0, "");
	//lem::connection_test();
	std::cout << area(circle{ {0 ,0}, 8.0 }) << std::endl;
	std::cout << area(square{ {0 ,0}, 8.0 }) << std::endl;
	std::cout << (dot{ 0,0 } == dot{ 0,0 }) << std::endl;
	std::cout << (d*3).x << ' '<<(d*3).y << std::endl;
	return 0;
}