#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj): array_bag(obj) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this == &other)
		return (*this);
	this->array_bag::operator=(other);
	return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int n) const
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] == n)
			return (true);
	return (false);
}