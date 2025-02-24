#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  //create new empty set to store the intersection
  std::set<T> emptyset; 
  //iterate through each element of s1 and then check if stuff in s2 is also in there
  for(typename std::set<T>::iterator itr = s1.begin(); itr != s1.end(); ++itr){
    //check if that curr value of 2 exists in other set
    if (s2.find(*itr) != s2.end()){
      emptyset.insert(*itr); 
    }
  }
  return emptyset; //intersection set 
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  //create new union set 
  std::set<T> unionset = s1; 
  //needs all the elements to be in the new set
  for(typename std::set<T>::iterator itr = s2.begin(); itr != s2.end(); ++itr){
    //check if that curr value of 2 exists in other set
      unionset.insert(*itr); 
    }
  return unionset; 
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
