#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

class Clothing : public Product {
  public: 

    //constructors 
    Clothing(const std::string name, const std:: string size, const std:: string brand, double price, int qty); 

    //destructor 
    ~Clothing(); 

    //return appropriate keywords to index Product
    std::set<std::string> keywords() const; 

    bool isMatch(std::vector<std::string>& searchTerms) const;

    std::string displayString() const; 

    //output the info in format
    void dump(std::ostream& os) const;

  private: //or protected??? 
    std::string size_; 
    std::string brand_; 

}; 
#endif