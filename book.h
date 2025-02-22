#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class Book : public Product {
  public: 

    //constructors 
    Book(const std::string name, const std:: string author, const std:: string isbn, double price, int qty); 

    //destructor 
    ~Book(); 

    //return appropriate keywords to index Product
    std::set<std::string> keywords() const; 

    bool isMatch(std::vector<std::string>& searchTerms) const;

    std::string displayString() const; 

    //output the info in format
    void dump(std::ostream& os) const;

  private: //or protected??? 
    std::string author_; 
    std::string isbn_; 

}; 
#endif