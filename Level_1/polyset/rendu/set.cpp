#include "set.hpp"

set::set(searchable_bag &obj): _obj(obj){}

void set::insert (int n)
{
	_obj.insert(n);
}

void set::insert (int *array, int size)
{
	_obj.insert(array, size);
}

void set::print() const
{
	_obj.print();
}

void set::clear()
{
	_obj.clear();
}

bool set::has(int x) const
{
	return (_obj.has(x));
}

searchable_bag &set::get_bag()
{
	return (_obj);
}
