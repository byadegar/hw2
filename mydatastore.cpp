#include "mydatastore.h"
#include <iomanip> 
#include <string>
#include <set>
#include <vector>
#include <map> 
#include <iostream>

using namespace std; 

//1 - constructor and destructor 
MyDataStore::MyDataStore(){} //nothing to manually initialize 
MyDataStore::~MyDataStore(){
  //have to destroy the dynamic memory we allocated in the program
  //User* and Product*
  //go through users map and products vector to delete all 
  for (map<string, User*>::iterator iterate = users_.begin(); iterate != users_.end(); iterate++){
    delete iterate->second; //releases the memory it points to (value)
  }
  for (vector<Product*>::iterator iterate = products_.begin(); iterate != products_.end(); iterate++){
    delete *iterate; //deletes product pointer stored in the vector
  }

}
//add user 
void MyDataStore::addUser(User* user){
  //add a new user to the map of usernames
  users_[user->getName()] = user; 
  //is this all i have to do **double check
}
//takes in pointer to product - this is good
void MyDataStore::addProduct(Product *product) {
  //gather all of that product's key words into kw
  std::set<std::string> keyWordsHold = product->keywords(); 
  //store product in pain list of products we already have
  products_.push_back(product);  

//go through each keyword in set to associate w product
  for(set<string>::iterator iterate = keyWordsHold.begin(); iterate != keyWordsHold.end(); ++iterate){
    std::string lowerKey = convToLower(*iterate);
    keysProducts[lowerKey].insert(product); //access set of products w those keywords to put product 
  }


}

  //search for products based on list of keywords using and / or 
  //will return vector w matching products
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  //first need to initialize an empty set to store the results that match
  set<Product*> storeMatchProducts; 

  //AND search 
  if (type == 0){
    for (vector<string>::iterator iterate = terms.begin(); iterate != terms.end(); ++iterate){
      std::string lowerTerm = convToLower(*iterate);
      //first iteration, theres union bc theres no intersection
      if (iterate == terms.begin()){
        storeMatchProducts = keysProducts[lowerTerm];
        }else{
          //now fill with intersection bc we have the sets 
          storeMatchProducts = setIntersection(storeMatchProducts, keysProducts[lowerTerm]); 
        }
      }
  }
      else if (type == 1){
        //UNION of all products
        for (vector<string>::iterator iterate = terms.begin(); iterate != terms.end(); ++iterate){
          std::string lowerTerm = convToLower(*iterate);
          storeMatchProducts = setUnion(storeMatchProducts, keysProducts[lowerTerm]);
        }
      }

  
  //lastSearchRes_.assign(storeMatchProducts.begin(), storeMatchProducts.end()); 
  //convert set to vector 
  vector<Product*> searchRes(storeMatchProducts.begin(), storeMatchProducts.end());
  return searchRes; 

}

//dump entire product and user database to output stream file
void MyDataStore::dump(std::ostream& file){

  //1 - hold all unique product pointers 
  set<Product*> uniqueProducts; 
  for (map<string, set<Product*> >::iterator iterate = keysProducts.begin(); iterate != keysProducts.end(); iterate++){
    uniqueProducts = setUnion(uniqueProducts, iterate->second); //union combining the sets of products from keyword w unique ones
  }
  file << "<products>" << endl; 
  for (set<Product*>::iterator iterate = uniqueProducts.begin(); iterate != uniqueProducts.end(); iterate++){
    (*iterate)->dump(file); //dump all products
  }
  file << "</products>" << endl; //end of product dump

  file << "<users>" << endl; //userdump
  for (map<string, User*>::iterator iterate = users_.begin(); iterate != users_.end(); iterate++){
    iterate->second->dump(file); 
  }
  file << "</users>" << endl;  //end user dump 

}

//add the item at that index to the cart
void MyDataStore::addItem(std::string userName, Product* p){
  //can only add to cart if the username exists and so does index
  //first check if it would be valid to add 
  if (users_.find(userName) != users_.end()){
    //in here means you have the ability to add it so u can
    carts_[userName].push_back(p);
    //std::cout << "User: " << userName << " added item: " << p << " to cart.\n";
  }
  else {
    cout << "Invalid request" << endl; 
  }
}



void MyDataStore::buyCart(std::string userName){
  if (users_.find(userName) != users_.end()){
    //has to exist to match up cart 
    User* curUser = users_[userName]; 
    vector<Product*>::iterator iterate = carts_[userName].begin(); 
    while (iterate != carts_[userName].end()){ //iterate trhrough each product in user cart
      Product* currProd(*iterate); //current product, deref to point at current product in cart
      if (currProd->getQty() > 0 && currProd->getPrice () <= curUser->getBalance()){
        //if statement checks if prodyct CAN be purchased (in stock, can pay)
        //vector<Product*>::iterator temp = iterate; //store current before modify cart so we don't lost
        currProd->subtractQty(1); //minus one of stock
        curUser->deductAmount(currProd->getPrice()); //deduct price from user balance
        iterate = carts_[userName].erase(iterate); //remove purchased product from cart
      }
      else {
        iterate++; //just move on 
      }
    }
  }
  else{
    cout <<"Invalid username" << endl; 
  }
}

void MyDataStore::showCart(std::string userName){
  //need to know if there's actually a valid user 
  if (users_.find(userName) != users_.end()){
    //yay you found it
    vector<Product*> cartCurr = carts_[userName]; 
    int i = 1; //counter for user to see their items numerically
    for (std::vector<Product*>::iterator iterate = cartCurr.begin(); iterate != cartCurr.end(); ++iterate){
      cout << "Item " << i << endl;
      cout << (*iterate)->displayString() << endl; 
      i++; 
    }

  } //you never found the cart bc not a valid/associated user
  else{
    cout << "Invalid username" << endl; 
  }
}




