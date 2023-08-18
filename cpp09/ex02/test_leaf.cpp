#include "Leaf.hpp"
#include <cassert>

void test_leaf_default_constructor()
{
	Leaf l;
	assert(l.getValue() == 0);
} 

void test_leaf_copy_construct()
{
	Leaf l1(1);
	Leaf l2(l1);
	assert(l2.getValue() == 1);
}

void test_leaf_clone()
{
	Leaf l1(1);
	BasePair *l2 = l1.clone();
	Leaf* l3 = dynamic_cast<Leaf*>(l2);
	assert(l3->getValue() == 1);
}

void test_leaf_get_value()
{
	Leaf l(1);
	assert(l.getValue() == 1);
}

void test_leaf_set_value()
{
	Leaf l(1);
	l.setValue(2);
	assert(l.getValue() == 2);
}

void test_leaf_print()
{
	Leaf l(1);
	l.print();
	std::cout << std::endl;
	Leaf l2;
	l2.print();
}

int main()
{
	test_leaf_default_constructor();
	test_leaf_copy_construct();
	test_leaf_clone();
	test_leaf_get_value();
	test_leaf_set_value();
	test_leaf_print();
	return 0;
}
