#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "sort.hpp"

class SelectionSort : public Sort {
    public:
	SelectionSort() : Sort() {}
	void sort(Container* container);
};

#endif
