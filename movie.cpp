#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

using namespace std;
Movie::Movie(const std::string name, const std::string genre, const std::string rating, double price, int qty):
  Product("movie", name, price, qty){
    genre_ = genre; 
    rating_ = rating; 
  }

Movie::~Movie(){} //will this destruct properly 

//return appropriate keywords to index Product
std::set<std::string> Movie::keywords() const{
    set<string> keywords = parseStringToWords(name_);

    set<string> wordsGenre = parseStringToWords(genre_);
    keywords.insert(wordsGenre.begin(), wordsGenre.end());
    if(rating_.length() >= 2) {
        keywords.insert(convToLower(rating_));
    }
    return keywords;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
  std::set<std::string> keyWords = keywords(); 

  for (int i = 0; i < searchTerms.size(); i++){ // go through every term
    if (keyWords.find(searchTerms[i]) != keyWords.end()){ //if its not end, it means it found it somewhwre
      return true; 
    }
  }
  return false;  //no match found

}

std::string Movie::displayString() const{

  std::stringstream s; 
  s << name_ << "\nGenre: " << genre_ << " Rating: " << rating_ << "\n" << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.";
  return s.str(); 
}

//output the info in format
void Movie::dump(std::ostream& os) const{
  //finish this code
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl; 

}
