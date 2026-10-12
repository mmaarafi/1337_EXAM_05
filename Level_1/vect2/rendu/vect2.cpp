#include "vect2.hpp"

std::ostream &operator<<(std::ostream &os, const vect2 &obj2)
{
	os << "{" << obj2.x << ", " << obj2.y << "}";
	return (os);
}

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

vect2::~vect2() {}

int &vect2::operator[](int i)
{
	if (i == 0)
		return x;
	else
		return y;
}

vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	x++;
	y++;
	return (copy);
}

vect2 &vect2::operator++()
{
	x++;
	y++;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	x--;
	y--;
	return (copy);
}


vect2 &vect2::operator--()
{
	x--;
	y--;
	return (*this);
}

vect2 &vect2::operator-=(const vect2 &obj)
{
	x -= obj.x;
	y -= obj.y;
	return (*this);
}

vect2 &vect2::operator+=(const vect2 &obj)
{
	x += obj.x;
	y += obj.y;
	return (*this);
}

vect2 vect2::operator+(const vect2 &obj) const
{
	vect2 copy(*this);
	copy.x += obj.x;
	copy.y += obj.y;
	return (copy);
}

vect2 vect2::operator*(int n) const
{
	vect2 copy(*this);
	copy.x *= n;
	copy.y *= n;
	return (copy);
}

vect2 operator*(int n, const vect2 &obj)
{
	vect2 copy(obj);
	copy.x *= n;
	copy.y *= n;
	return (copy);
}

vect2 vect2::operator*=(int n)
{
	x *= n;
	y *= n;
	return (*this);
}

vect2 vect2::operator-(const vect2 &obj) const
{
	vect2 copy(*this);
	copy.x -= obj.x;
	copy.y -= obj.y;
	return (copy);
}

vect2 vect2::operator-() const
{
	vect2 copy(*this);
	copy.x = -copy.x;
	copy.y = -copy.y;
	return (copy);
}

const int &vect2::operator[](int i) const
{
	if (i == 0)
		return x;
	else
		return y;
}

bool vect2::operator==(const vect2 &obj) const
{
	if (x == obj.x && y == obj.y)
		return (true);
	else
		return (false);
}

bool vect2::operator!=(const vect2 &obj) const
{
	if (x != obj.x || y != obj.y)
		return (true);
	else
		return (false);
}
