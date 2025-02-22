#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;
Clothing::Clothing(const std::string name, const std::string size, const std::string brand, double price, int qty):
  Product("clothing", name, price, qty){
    size_ = size; 
    brand_ = brand; 
  }

Clothing::~Clothing(){} //will this destruct properly 

//return appropriate keywords to index Product
std::set<std::string> Clothing::keywords() const{
  //size and brand
  
  std::set<std::string> clothingNameWords = parseStringToWords(name_); 
  std::set<std::string> brandWords = parseStringToWords(brand_);
  
  return setUnion(clothingNameWords, brandWords);  
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
  std::set<std::string> keyWords = keywords(); 

  for (unsigned int i = 0; i < searchTerms.size(); i++){ // go through every term
    if (keyWords.find(searchTerms[i]) != keyWords.end()){ //if its not end, it means it found it somewhwre
      return true; 
    }
  }
  return false;  //no match found

}

std::string Clothing::displayString() const{
  std::stringstream s; 
  s << name_ << "\nSize: " << size_ << " Brand: " << brand_ << "\n" << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.";
  return s.str(); 
}

//output the info in format
void Clothing::dump(std::ostream& os) const{
  //finish this code
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl; 

}