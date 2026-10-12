#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>

class bigint {
	public :
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& obj);
		bigint &operator=(const bigint &obj);
		~bigint();
		bigint operator+(const bigint &obj) const;
		bigint operator-(const bigint &obj) const;
		bigint operator+=(const bigint &obj);
		bigint operator++(int);
		bigint operator++();
		bigint operator<<(int n) const;
		bigint operator<<=(int n);
		bigint operator>>=(const bigint &obj);
		bool operator>(const bigint &obj);
		bool operator<(const bigint &obj);
		bool operator>=(const bigint &obj);
		bool operator<=(const bigint &obj);
		bool operator!=(const bigint &obj);
		bool operator==(const bigint &obj);
		friend std::ostream &operator<<(std::ostream &os, const bigint &obj);
	private:
		std::string data;
};