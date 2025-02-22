#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie : public Product {
  public: 

    //constructors 
    Movie(const std::string name, const std::string genre, const std::string rating, double price, int qty); 

    //destructor 
    ~Movie(); 

    //return appropriate keywords to index Product
    std::set<std::string> keywords() const; 

    bool isMatch(std::vector<std::string>& searchTerms) const;

    std::string displayString() const; 

    //output the info in format
    void dump(std::ostream& os) const;

  private: //or protected??? 
    std::string genre_; 
    std::string rating_; 

}; 
#endif