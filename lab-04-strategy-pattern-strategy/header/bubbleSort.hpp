#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "sort.hpp"

class BubbleSort : public Sort {
	public:
	  BubbleSort() : Sort() {}
	  void sort(Container* container);
};
#endif
