#include "vect2.hpp"

vect2::vect2()
{
	x = 0;
	y = 0;
}

vect2::vect2(int _x, int _y)
{
	x = _x;
	y = _y;
}

vect2::vect2(const vect2 &obj)
{
	x = obj.x;
	y = obj.y;
}

vect2 &vect2::operator=(const vect2 &obj)
{
	if (this == &obj)
		return (*this);
	x = obj.x;
	y = obj.y;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
	os << "{" << obj.x << ", "  << obj.y << "}";
	return os;
}

int &vect2::operator[](int i)
{
	if (i == 0)
		return (x);
	else
		return (y);
}

vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	std::cout<< copy.x << copy.y << "=======" << std::endl;
	x++;
	y++;
	return (copy);
}

vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	x--;
	y--;
	return (copy);
}

vect2 &vect2::operator++()
{
	x++;
	y++;
	return (*this);
}

vect2 &vect2::operator--()
{
	x--;
	y--;
	return (*this);
}

vect2 &vect2::operator+=(const vect2 &obj)
{
	x = x + obj.x;
	y = y + obj.y;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &obj)
{
	x = x - obj.x;
	y = y - obj.y;
	return (*this);
}
vect2 vect2::operator*(int n) const
{
	std::cout << "hello" << std::endl;
	vect2 copy(*this);
	std::cout << "before :" << copy << std::endl;
	copy.x = copy.x * n;
	copy.y = copy.y * n;
	std::cout << "after :" << copy << std::endl;
	return (copy);
}

vect2 vect2::operator+(const vect2 &obj) const
{
	std::cout << "hello2" << std::endl;
	vect2 copy(*this);
	std::cout << "before :" << copy << std::endl;
	copy.x = copy.x + obj.x;
	copy.y = copy.y + obj.y;
	std::cout << "after :" << copy << std::endl;
	return (copy);
}

vect2 vect2::operator+(int n) const
{
	vect2 copy(*this);
	copy.x = copy.x + n;
	copy.y = copy.y + n;
	return (copy);
}

vect2 operator*(int n, const vect2 &obj)
{
	vect2 copy(obj);
	copy.x = copy.x * n;
	copy.y = copy.y * n;
	return (copy);
}
vect2 &vect2::operator*=(int n)
{
	x = x * n;
	y = y * n;
	return (*this);
}

vect2 vect2::operator-(const vect2 &obj) const
{
	std::cout << "hello3" << std::endl;
	vect2 copy(*this);
	std::cout << "before :" << copy << std::endl;
	copy.x = copy.x + obj.x;
	copy.y = copy.y + obj.y;
	std::cout << "after :" << copy << std::endl;
	return (copy);
}

vect2 vect2::operator-()
{
	x = -x;
	y = -y;
	return (*this);
}

const int &vect2::operator[](int i) const
{
	if (i == 0)
		return (x);
	else
		return (y);
}

bool vect2::operator==(const vect2 &obj)
{
	return ((x == obj.x) && (y == obj.y));
}

bool vect2::operator!=(const vect2 &obj)
{
	return ((x != obj.x) && (y != obj.y));
}
