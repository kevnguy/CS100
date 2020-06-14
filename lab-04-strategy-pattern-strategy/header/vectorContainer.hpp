#ifndef VECTOR_CONTAINER
#define VECTOR_CONTAINER

#include "container.hpp"
#include "selectionSort.hpp"
#include "bubbleSort.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

class VectorContainer : public Container {
    private:
        std::vector<Base*> v;
    public:
        VectorContainer();
        void set_sort_function(Sort* sortFunction);
        void add_element(Base* element);
        void print();
        void sort();
        void swap(int i, int j);
        Base* at(int i);
        int size();
};

#endif
