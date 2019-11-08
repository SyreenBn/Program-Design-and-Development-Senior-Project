// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const ;
  double getCharge() const;
  int getFrequentRenterPoints() const;

private:
  Movie _movie;
  int _daysRented;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
  : _movie( movie )
  , _daysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline const Movie& Rental::getMovie() const { return _movie; }

/*
* because the infomation of
* amountFor method was in custorer classs and uses information about the rental
* but not the customer.So, the method should be in the object whose data it uses.
* the method should be moved to rental. I copy the method over to the rental
* first, adjust it to fit into its new home which is rental class,
*/
double Rental::getCharge() const
{
  return _movie.getCharge( _daysRented );
}
int Rental::getFrequentRenterPoints() const{
  return _movie.getTotalFrequentRenterPoints();

}

#endif // RENTAL_H
