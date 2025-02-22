//searching - set union and intersection 
//adding products and users
//saving the database 
//handling carts 
#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "user.h"
#include "product.h"
#include "util.h"
#include "datastore.h"
#include <string>
#include <set>
#include <vector>
#include <map> 

class MyDataStore : public DataStore {

public:
    MyDataStore(); //default constructor 

    //destructor 
    ~MyDataStore(); 

   //adding products and users 
    void addUser(User* user); //takes in pointer to user object
    void addProduct(Product *product); //takes in pointer to product

//search of products based on list of keyword items 
   std::vector<Product*> search(std::vector<std::string>& terms, int type);

   //database 
   void dump(std::ostream& file);

   //cart
   ////add last item user is searching to the cart... 
   void addItem(std::string userName, Product* p); 
   void buyCart(std::string userName); //void
   void showCart(std::string userName);  //void

private:
  //vector of products to store all products 
  std::vector<Product*> products_;

  //store results of last search (most recent search result)
  std::vector<Product*> lastSearchRes_; 

  //map to map users in system to map username to user
  std::map<std::string, User*> users_; 

  //map to map keyword to set of products which contain keyword
  std::map<std::string, std::set<Product*>> keysProducts;

  //map username to list of products in cart 
  std::map<std::string, std::vector<Product*>> carts_; 


}; 
#endif 






