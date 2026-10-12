#include "set.hpp"

set::set(searchable_bag &obj): bag(obj) {}

void set::insert (int n)
{
	if (!bag.has(n))
		bag.insert(n);
}

void set::insert (int *array, int size)
{
	for (int i = 0; i < size; i++)
		if (!bag.has(array[i]))
			bag.insert(array[i]);
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

bool set::has(int n) const
{
	return (bag.has(n));
}

searchable_bag &set::get_bag()
{
	return (bag);
}