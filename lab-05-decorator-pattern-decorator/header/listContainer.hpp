#ifndef LIST_CONTAINER
#define LIST_CONTAINER

#include "container.hpp"
#include "selectionSort.hpp"
#include "bubbleSort.hpp"
#include <list>
#include <iostream>
#include <stdexcept>
class ListContainer : public Container {
    private:
	std::list<Base*> L;
    public:
	ListContainer();
	void set_sort_function(Sort* sort_functio);
	void add_element(Base* element);
	void print();
	void sort();
	void swap(int i, int j);
	Base* at(int i);
	int size();
};
#endif
