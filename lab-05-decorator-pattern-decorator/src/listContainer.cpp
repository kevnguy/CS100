#include "../header/listContainer.hpp"

ListContainer::ListContainer() : Container() {}

void ListContainer::set_sort_function(Sort* sortFunction) {sort_function = sortFunction; }

void ListContainer::add_element(Base* element) {L.push_back(element);}

void ListContainer::print() { for(auto i:L) std::cout << i->stringify() << std::endl;}

void ListContainer::sort() {
	if(!sort_function) 
		throw "Null pointer exception!"; 
	sort_function->sort(this);
 }

void ListContainer::swap(int i, int j) { 
	auto temp = L.begin();
	std::advance(temp,i);
	auto temp2 = L.begin();
        std::advance(temp2,j);

	Base* temp3 = *temp;
	*temp = *temp2;
	*temp2 = temp3;
} 

Base* ListContainer::at(int i) {
            if(i >= L.size()){//not sure if this is needed 
                i = L.size()-1;//if trying to access value outside of list, returns last element instead
            }
            auto it = L.begin();
            std::advance(it,i);
            return  *it;
}

int ListContainer::size() {return L.size();}

