#pragma once

#include "searchable_bag.hpp"

class set
{
	public :
		set(const searchable_bag &obj);
		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();
		bool has(int x) const;
		searchable_bag &get_bag();
};