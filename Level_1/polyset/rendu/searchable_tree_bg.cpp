#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj): tree_bag(obj) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &obj)
{
	if (this == &obj)
		return (*this);
	this->tree_bag::operator=(obj);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int x) const
{
	node *tree_copy = tree;
	while (tree_copy)
	{
		if (tree_copy->value == x)
			return true;
		else if (tree_copy->value < x)
			tree_copy = tree_copy->r;
		else
			tree_copy = tree_copy->l;
	}
	return (false);
}