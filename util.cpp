#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
// std::set<std::string> parseStringToWords(string rawWords)
// {
//   //split at punctuation character 
//   //make case insensitive 
//   //words at least 2 characters long (ignore 1 character words)
//   set<string> wordsreturn; 
//   int index = 0; 
//   int start = 0; //track start index 

//   for (unsigned int i = 0; i < rawWords.length(); i++){
//     char c = rawWords[i]; //track current letter
//     if (!ispunct(c) && c != ' '){ // if character is not punct or space
//       //move to next index -- track it
//       index++;  //lengthh (more characters exist)
//     }
//     else {
//       if (index >= 2){
//         wordsreturn.insert(convToLower(rawWords.substr(start,index)));
//       }
//       //reset for the next word
//       index = 0; 
//       start = i + 1; //next start character
//     }
//   } 
//   if (index >= 2){ // last word/edge case
//     wordsreturn.insert(convToLower(rawWords.substr(start,index)));
//   }
//   return wordsreturn; 
// }
std::set<std::string> parseStringToWords(string rawWords){
  set<string> toReturn; 
  stringstream ss(rawWords);
  string word = ""; 
  while(ss>>word){
    int index = -1; //punctuation trcker
    for (int i =0; i < word.length(); i++){
      if (ispunct(word[i])){
        index = i;
        break; 
      }
    }
    if (index != -1){
      //found punctuation 
      string LHS = word.substr(0, index); 
      string RHS = word.substr(index+1); 
      if (LHS.length() >= 2){
        toReturn.insert(convToLower(LHS)); 
      }
      if (RHS.length() >= 2){
        toReturn.insert(convToLower(RHS)); 
      }
    }
    else{
      //check if full word 
      if (word.length() >= 2){
        toReturn.insert(convToLower(word)); 
      }
    }
  }
  return toReturn; 
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
