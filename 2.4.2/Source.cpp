#include <iostream>
#include "Point.h"
#include "Css.h"
#include <memory>

using namespace std;


S_ptrDo pass_ownership(S_ptrDo pp) {
	// ownership will be transfered from sp1 to sp2
	return pp;
}
S_ptrDo init_empty_shared(S_ptrDo pp) {
	// This function inputs shared_ptr<Point> , and force to give up the ownership by calling reset(), then return nullptr 
	pp.reset();
	return nullptr;
}
int main() {
	shared_ptr<double> commonVal(new double(1.0));
	cout << "How many object share this pointer? : " << commonVal.use_count() << endl;	// it must be 1 
	{
		C1 myC1(commonVal);
		myC1.print();
		cout << "How many object share this pointer? : " << commonVal.use_count() << endl; // it must be 2
		C2 myC2(commonVal);
		myC2.print();
		cout << "How many object share this pointer? : " << commonVal.use_count() << endl;
	}
	// After hitting the scope

	cout << "How many object share this pointer? : " << commonVal.use_count() << endl;// it reduced down to 1 => ownerships are automatically released.
	// Also we can check this, by seeing the destructor messages. c1 and c2 destructors were called, before the final use_count()
	
	// Modified version of above
	S_ptrDo comVal(new Point(2.19,3.14));
	{
		C1_modifed modified1(comVal);
		cout << "Number of ownership shared : " << comVal.use_count() << endl;
		modified1.print();
		C2_modifed modified2(comVal);
		cout << "Number of ownership shared : " << comVal.use_count() << endl;
		modified2.print();

	}
	cout << "Number of ownership shared : " << comVal.use_count() << endl;

	cout << "---------------------------------------------" << endl;
	// Assining, copying and compare two shared pointers sp1 and sp2
	S_ptrDo sp1(new Point(1.2, 3.1));
	S_ptrDo sp2(new Point(0.0, 9.01));

	*sp1 = *sp2; // assigning pointers
	cout << "how many for sp1? "<<sp1.use_count() << endl;
	cout << "how many for sp2? " << sp2.use_count() << endl;
	
	sp1.swap(sp2);
	cout << "how many for sp1 after swap? " << sp1.use_count() << endl;
	cout << "how many for sp2 after swap? " << sp2.use_count() << endl;

	sp2=pass_ownership(sp1);	// since the move semantic called both shared ptr will have no sharing effect.

	cout << "how many for sp1? " << sp1.use_count() << endl;
	cout << "how many for sp2? " << sp2.use_count() << endl;

	// giving up the ownership
	
	sp1=init_empty_shared(sp1);
	cout <<"How many shared? after giving up and reinitialize as an empty? : "<< sp1.use_count() << endl;
}