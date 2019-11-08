#include <iostream>


int main() {

// const int myConst1; //uninitialized const ‘myConst1’
const int myConst1 = 100;
const int myConst2 = 200;
const int* pMyConst;

std::cout << "=====myConst1 = 100=====" << std::endl;
std::cout << myConst1 << std::endl;
std::cout << "___________________________________________________" << std::endl;
std::cout << "=====myConst2 = 200=====" << std::endl;
std::cout << myConst2 << std::endl;
std::cout << "___________________________________________________" << std::endl;
std::cout << "=====pMyConst=====" << std::endl; // it print 0 befor I declear it
std::cout << "0" << std::endl; // onece I declear it, the zero will change.
std::cout << "___________________________________________________" << std::endl;

// init pointer
pMyConst = &myConst2;

std::cout << "=====pMyConst = &myConst2=====" << std::endl;
std::cout << pMyConst << std::endl;
std::cout << "___________________________________________________" << std::endl;

// change integer
// myConst2 = myConst2 + 5;

std::cout << "=====myConst2 = myConst2 + 5=====" << std::endl;
std::cout << "Adding 5 to myConst2 will not \n compile because it is const" << std::endl;
std::cout << "___________________________________________________" << std::endl;


// change integer using pointer
// *pMyConst = myConst1 + 1;

std::cout << "=====*pMyConst = myConst1 + 1=====" << std::endl;
std::cout << "Adding 1 to pointer pMyConst will \n not compile because it is const" << std::endl;
std::cout << "___________________________________________________" << std::endl;

int myInt_3;
int myInt_4 = 400;
int* const cpMyInt_3 = &myInt_3;

std::cout << "=====myInt_3=====" << std::endl;
std::cout << myInt_3 << std::endl;
std::cout << "___________________________________________________" << std::endl;

std::cout << "=====myInt_4=====" << std::endl;
std::cout << myInt_4 << std::endl;
std::cout << "___________________________________________________" << std::endl;

std::cout << "=====cpMyInt_3=====" << std::endl;
std::cout << cpMyInt_3 << std::endl;
std::cout << "___________________________________________________" << std::endl;

// initialize the pointer
//int* const cpMyInt_4;

std::cout << "=====cpMyInt_4=====" << std::endl;
std::cout << "(int* const cpMyInt_4) will not compile \n because of uninitialized const ‘cpMyInt_4’" << std::endl;
std::cout << "___________________________________________________" << std::endl;

int* const cpMyInt_4 = &myInt_4;

std::cout << "=====cpMyInt_4=====" << std::endl;
std::cout << cpMyInt_4 << std::endl;
std::cout << &cpMyInt_4 << std::endl;
std::cout << *cpMyInt_4 << std::endl;
std::cout << "___________________________________________________" << std::endl;


// initialize integer
myInt_3 = 300;

std::cout << "=====myInt_3=====" << std::endl;
std::cout << myInt_3 << std::endl;

// change the integer
myInt_4 = myInt_4 + 5;

std::cout << "=====cpMyInt_4=====" << std::endl;
std::cout << cpMyInt_4 << std::endl;
std::cout << &cpMyInt_4 << std::endl;
std::cout << *cpMyInt_4 << std::endl;

// change integer using pointer
*cpMyInt_3 = myInt_4;

std::cout << "=====*cpMyInt_3 = myInt_4=====" << std::endl;
std::cout << *cpMyInt_3 << std::endl;
std::cout << "___________________________________________________" << std::endl;

// change the pointer
//cpMyInt_3 = &myInt_4;

std::cout << "=====cpMyInt_3 = &myInt_4=====" << std::endl;
std::cout << "assignment of read-only variable ‘cpMyInt_3’" << std::endl;
std::cout << "___________________________________________________" << std::endl;

}
