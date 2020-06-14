#include "../header/vectorContainer.hpp"

VectorContainer::VectorContainer() : Container() {}

void VectorContainer::set_sort_function(Sort* sortFunction) { sort_function = sortFunction; }

void VectorContainer::add_element(Base* element) { v.push_back(element); }

void VectorContainer::print() { for(auto i:v) std::cout << i->stringify() << std::endl; }

void VectorContainer::sort() { if(!sort_function) throw "Null pointer exception!"; sort_function->sort(this); }

void VectorContainer::swap(int i, int j) { Base* temp = v[i]; v[i] = v[j]; v[j] = temp; }

Base* VectorContainer::at(int i) { return v[i]; }

int VectorContainer::size() { return v.size(); }
