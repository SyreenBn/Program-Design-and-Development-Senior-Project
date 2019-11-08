// A class for a single element in a cart
class CartEntry {
public:
  float price;
  int quantity;
  CartEntry( float p=0, int q=0);
};

// A collection of elements in a cart
// CartContents "has a" CartEntry - using composition
class CartContents{
public:
  int itemCount; // number of elements in cart
  CartEntry* items;
};

// An order is the combination of a cart and tax
// different states apply different salesTax rates.
class Order {
private:
  CartContents cart;
  float salesTax;
public:
  Order(CartContents cart, float salesTax);
  float OrderTotal();
};
//------------------------------------------------------------------------------
#include "cart.h"
CartEntry::CartEntry( float p, int q) {
  price = p;
  quantity = q;
}
Order::Order( CartContents c, float s ) {
  cart = c;
  salesTax = s;
}
float Order::OrderTotal() {
  float cartTotal = 0;
  for (int i=0; i < cart.itemCount; i++) {
    cartTotal += cart.items[i].price * cart.items[i].quantity;
  }
  cartTotal += cartTotal * salesTax;
  return cartTotal;
}
//------------------------------------------------------------------------------
#include <iostream>
#include "cart.h"
int main() {
  // Create an array of CartEntry's to put in the cart
  // Arbitrary values for price and quantity
  CartEntry inCart[8];
  for (int i=0; i<8; i++) {
    inCart[i].price = i*2;
    inCart[i].quantity = i;
  }
  // Place the CartEntry array in a CartContents
  CartContents purchases;
  purchases.items = inCart;
  purchases.itemCount = 8;
  // Make this an order with associated tax
  Order order1(purchases, .077);
  // Get total price of order
  std::cout << '$' << order1.OrderTotal() << std::endl;
  return 0;
}
//------------------------------------------------------------------------------
// 5 -> 64.62
// 8 -> 301.56
// 3 -> 10.77
