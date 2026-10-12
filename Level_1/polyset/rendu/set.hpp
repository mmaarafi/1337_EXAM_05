#pragma once

#include "bag.hpp"
#include "searchable_bag.hpp"

class set {
	public :
		set(searchable_bag &obj);
		virtual void insert (int n);
		virtual void insert (int *array, int size);
		virtual void print() const;
		virtual void clear();
		virtual bool has(int n) const;
		searchable_bag &get_bag();
	private:
		searchable_bag &bag;
};