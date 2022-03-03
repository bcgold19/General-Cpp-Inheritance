#ifndef CSS_H
#define CSS_H

#include <iostream>
#include <memory>
using namespace std;
using S_ptrDo = shared_ptr<Point>;
class C1 {
private:
	shared_ptr<double> d;
public:
	C1(shared_ptr<double> value) :d(value) {}
	virtual ~C1() { cout << "C1 destructor called" << endl; }
	void print() const {
		cout << "What is inside in C1? : " << *d << endl;
	}

};

class C2 {
private:
	shared_ptr<double> d;
public:
	C2(shared_ptr<double> value) :d(value) {}
	virtual ~C2() { cout << "C2 destructor called" << endl; }
	void print() const {
		cout << "What is inside in C2? : " << *d << endl;
	}
};
class C1_modifed {
private:
	S_ptrDo d;
public:
	C1_modifed(S_ptrDo value) :d(value) {};
	virtual ~C1_modifed() { cout << "modified C1 destructor called" << endl; }
	void print()const {
		cout << "what is inside in modified c1? : " << *d << endl;
	}
};
class C2_modifed {
private:
	S_ptrDo d;
public:
	C2_modifed(S_ptrDo value) :d(value) {};
	virtual ~C2_modifed() { cout << "modified C2 destructor called" << endl; }
	void print()const {
		cout << "what is inside in modified c2? : " << *d << endl;
	}
};
#endif