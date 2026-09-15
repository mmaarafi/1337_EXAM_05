#pragma once

#include "searchable_bag.hpp"

class set
{
	public :
		set(searchable_bag &obj);
		void insert (int n);
		void insert (int *array, int size);
		void print() const;
		void clear();
		bool has(int x) const;
		searchable_bag &get_bag();
	private:
		searchable_bag &_obj;
};
