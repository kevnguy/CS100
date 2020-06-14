#include "./header/iterator.hpp"
#include "./header/visitor.hpp"

#include "./header/op.hpp"
#include "./header/rand.hpp"
#include "./header/mult.hpp"
#include "./header/div.hpp"
#include "./header/sub.hpp"
#include "./header/pow.hpp"
#include "./header/add.hpp"
#include "./header/abs.hpp"
#include "./header/trunc.hpp"
#include "./header/paren.hpp"
#include "./header/ceil.hpp"
#include "./header/floor.hpp"

#include <iostream>

int main(){
     Base* CeilAdd = new Ceil(new Add(2.5,1));
     Base* ParenTruncPow = new Paren(new Trunc(new Pow(CeilAdd,2)));
     Base* AbsSub = new Abs(new Sub(ParenTruncPow,800));
     Base* FloorAbsDiv = new Floor(new Abs(new Div(4.5,-2.2)));
     Base* test = new Paren(new Mult(AbsSub, FloorAbsDiv));

     int counter = 0;
     Iterator* it = new PreorderIterator(test);
     CountVisitor* v = new CountVisitor();
     it->first();
     while(!it->is_done()){
        Base* temp = it->current();
        temp->accept(v);
	counter++;
        it->next();
     }
     std::cout << "The resulting tree is: " << test->stringify() << std::endl;
     std::cout << "It has: " << counter << " types of nodes" << std::endl;

     return 0;

}
