#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}
searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj): array_bag(obj) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &obj)
{
	if (this == &obj)
		return (*this);
	this->array_bag::operator=(obj);
	return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int x) const
{
	int i = 0;
	while (i < this->size)
	{
		if (x == (*this).data[i])
			return (true);
		i++;
	}
	return (false);
}