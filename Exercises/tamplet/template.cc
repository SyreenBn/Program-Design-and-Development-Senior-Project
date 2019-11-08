#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

class ArenaEntity {
public:
  ArenaEntity(int r=10) : radius(r) {}
  void Print() {
    std::cout << "Entity with radius " << radius << std::endl;
  }
private:
  int radius;
};

// A polymorphic swap function for any type of object
template<typename T>
void MySwap( T& x, T& y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}

// A polymorphic class holding an [x,y] position of any type
template<class T>
class Position {
public:
  Position(T x=0, T y=0) : x_(x), y_(y) {}
  friend std::ostream& operator<<(std::ostream& os, const Position& p) {
    return os << "[" << p.x_ << ", " << p.y_ << "]";
  }
  // >>>> ADD SETTERS AND GETTERS
  T get_Xposition(void){return x_; }
  T get_Yposition(void){return y_; }
  void set_Xposition(T a) { x_ = a; }
  void set_Yposition(T a) { y_ = a; }
  // >>>>> OVERLOAD OPERATORS + and - binary operators as member functions.
  // T operator- (T a, T b){ return T (a - b);}
  // T operator+ (T a, T b){ return T (a + b);}

private:
  T x_;
  T y_;
};

// >>>>> CREATE AN ARRAY TEMPLATE that takes type and number of elements
// template<class T, int N> 
// >>>>> OVERLOAD operator []. Do a check on index to be in range
// >>>>> METHODS to push and pop



int main(void) {
  // -----------------------------------------------------------------
  // Demonstration of the use of the template Vector and its iterator
  std::vector<class ArenaEntity*> entities_;
  entities_.push_back(new ArenaEntity(20));
  entities_.push_back(new ArenaEntity(25));

  for (std::vector<class ArenaEntity*>::iterator ent = entities_.begin();
  ent != entities_.end();
  ++ent ) {
    (*ent)->Print();
  }

  // This is the same as above, except with the convenience of auto typing
  std::cout << std::endl;
  for (auto ent : entities_) {
    ent->Print();
  }

  // -----------------------------------------------------------------
  // Demonstration of the use of template for function overloading
  int intA;
  int intB;
  float floatA, floatB;
  char charA, charB;
  intA = 10;
  intB = 20;
  floatA = 2.5; floatB = 10.5;
  charA = 'a'; charB = 'b';

  std::cout << std::endl;
  std::cout << "int A,B: [" << intA << ", " << intB << "]" << std::endl;
  std::cout << "float A,B: [" << floatA << ", " << floatB << "]" << std::endl;
  std::cout << "char A,B: [" << charA << ", " << charB << "]" << std::endl;
  MySwap(intA,intB);
  MySwap(floatA,floatB);
  MySwap(charA,charB);
  std::cout << std::endl;
  std::cout << "int A,B: [" << intA << ", " << intB << "]" << std::endl;
  std::cout << "float A,B: [" << floatA << ", " << floatB << "]" << std::endl;
  std::cout << "char A,B: [" << charA << ", " << charB << "]" << std::endl;


  // -----------------------------------------------------------------
  // Demonstration of the use of template for class definition
  Position<int> intPos(10,10);
  Position<float> floatPos(1.5,1.5);
  Position<char> charPos('A','B');
  std::cout << std::endl;
  std::cout << intPos << std::endl;
  std::cout << floatPos << std::endl;
  std::cout << charPos << std::endl;

  Position<int> intPos2(20,20);
  //intPos2.set_x(30);
  //std::cout << intPos+intPos2 << std::endl;

  // -----------------------------------------------------------------
  // Demonstration of the use of template for class ARRAY


}
