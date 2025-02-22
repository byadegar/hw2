#include "book.h"
#include "util.h"
#include <sstream>
#include <iomanip>
//what other things do i need to include

using namespace std;
Book::Book(const std::string name, const std::string author, const std::string isbn, double price, int qty):
  Product("book", name, price, qty){
    author_ = author; 
    isbn_ = isbn; 
  }

Book::~Book(){} //will this destruct properly 

//return appropriate keywords to index Product
std::set<std::string> Book::keywords() const{
  //product, author, isbn (get keywords)
  
  std::set<std::string> bookNameWords = parseStringToWords(name_); 
  std::set<std::string> authorWords = parseStringToWords(author_);
  //isbn unique to each book 
  bookNameWords.insert(isbn_); 
  return setUnion(bookNameWords, authorWords);  // in util. h can i do it here im confused... 
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
  std::set<std::string> keyWords = keywords(); 

  for (unsigned int i = 0; i < searchTerms.size(); i++){ // go through every term
    if (keyWords.find(searchTerms[i]) != keyWords.end()){ //if its not end, it means it found it somewhwre
      return true; 
    }
  }
  return false;  //no match found

}

std::string Book::displayString() const{
  //finish this
  std::stringstream obj; 
  obj << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_ << "\n" <<
  std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.";  
  return obj.str(); 
}

//output the info in format
void Book::dump(std::ostream& os) const{
  //finish this code
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl; 
}