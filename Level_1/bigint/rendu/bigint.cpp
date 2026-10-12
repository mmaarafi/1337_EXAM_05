#include "bigint.hpp"

bigint::bigint()
{
	data = "0";
}

bigint::bigint(unsigned int n)
{
	data = std::to_string(n);
}

bigint::bigint(const bigint& obj)
{
	data = obj.data;
}

bigint &bigint::operator=(const bigint &obj)
{
	if (this == &obj)
		return (*this);
	data = obj.data;
	return (*this);
}

bigint::~bigint() {}

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
	os << obj.data;
	return (os);
}

std::string addition(std::string copy1, std::string copy2)
{
	std::string result;
	int carry = 0;
	int res;

	std::reverse(copy1.begin(), copy1.end());
	std::reverse(copy2.begin(), copy2.end());

	for (int i = 0; i < copy1.size() || i < copy2.size() || carry; i++)
	{
		int digit1  = (i < copy1.size()) ? (copy1[i] - '0') : 0;
		int digit2  = (i < copy2.size()) ? (copy2[i] - '0') : 0;

		if (carry == 0)
			res = digit1 + digit2;
		else
		{
			res = digit1 + digit2 + carry;
			carry = 0;
		}
		if (res < 10)
		{
			char c = res + '0';
			result += c;
		}
		else
		{
			char c = (res % 10) + '0';
			result+= c;
			carry = 1;
		}
	}
	std::reverse(result.begin(), result.end());
	return result;
}


bigint bigint::operator+(const bigint &obj) const
{
	bigint result;
	result.data = addition(data, obj.data);
	return result;
}

bigint bigint::operator+=(const bigint &obj)
{
	this->data = addition(data, obj.data);
	return (*this);
}

bigint bigint::operator++(int)
{
	bigint copy(*this);
	data = addition(data, "1");
	return (copy);
}

bigint bigint::operator++()
{
	data = addition(data, "1");
	return (*this);
}

bigint bigint::operator<<(int n) const
{
	bigint copy(*this);
	for (int i = 0; i < n; i++)
		copy.data+='0';
	return (copy);
}

bigint bigint::operator<<=(int n)
{
	for (int i = 0; i < n; i++)
		data+='0';
	return (*this);
}

bigint bigint::operator>>=(const bigint &obj)
{
	int shift_amount = atoi(obj.data.c_str());

	if (shift_amount >= data.size())
	{
		data = "0";
	}
	else
	{
		for (int i = 0; i < shift_amount; i++)
			data.pop_back();
	}
	return (*this);
}

bool bigint::operator>(const bigint &obj)
{
	if (data.size() != obj.data.size())
		return (data.size() > obj.data.size());
	return (data > obj.data);
}

bool bigint::operator<(const bigint &obj)
{
	if (data.size() != obj.data.size())
		return (data.size() < obj.data.size());
	return (data < obj.data);
}

bool bigint::operator>=(const bigint &obj)
{
	if (data.size() != obj.data.size())
		return (data.size() >= obj.data.size());
	return (data >= obj.data);
}

bool bigint::operator<=(const bigint &obj)
{
	if (data.size() != obj.data.size())
		return (data.size() <= obj.data.size());
	return (data <= obj.data);
}

bool bigint::operator!=(const bigint &obj)
{
	if (data != obj.data)
		return (true);
	return false;
}

bool bigint::operator==(const bigint &obj)
{
	if (data.size() == obj.data.size())
		return (data.size() == obj.data.size());
	return (data == obj.data);
}

bigint bigint::operator-(const bigint &obj) const
{
	bigint a(0);
	return a;
}