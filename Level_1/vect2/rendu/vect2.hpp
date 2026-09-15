#pragma once

#include <ostream>
#include <iostream>

class vect2 {
	public :
		vect2();
		vect2(int _x, int _y);
		vect2(const vect2 &obj);
		vect2 &operator=(const vect2 &obj);
		int &operator[](int i);
		const int &operator[](int i) const;
		vect2 &operator++();
		vect2 &operator--();
		vect2 operator++(int);
		vect2 operator--(int);
		vect2 &operator+=(const vect2 &obj);
		vect2 &operator-=(const vect2 &obj);
		vect2 operator*(int n) const;
		vect2 operator+(const vect2 &obj) const;
		vect2 operator+(int n) const;
		vect2 &operator*=(int n);
		vect2 operator-(const vect2 &obj) const;
		vect2 operator-();
		bool operator==(const vect2 &obj);
		bool operator!=(const vect2 &obj);
		friend std::ostream &operator<<(std::ostream &os, const vect2 &obj);
		friend vect2 operator*(int n, const vect2 &obj);
	private:
		int x;
		int y;
};


