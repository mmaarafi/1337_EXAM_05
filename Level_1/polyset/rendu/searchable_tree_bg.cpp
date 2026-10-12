#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj): tree_bag(obj) {}
searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this == &other)
		return (*this);
	this->tree_bag::operator=(other);
	return (*this);
}
searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int n) const
{
	tree_bag::node *copy = this->tree;

	while (copy)
	{
		if (copy->value == n)
			return (true);
		else if (copy->value < n)
			copy = copy->r;
		else
			copy = copy->l;
	}
	return (false);
}