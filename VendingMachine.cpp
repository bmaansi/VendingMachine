// Project: Vending Machine
// Maansi Bhardwaj
//
// Sept 19-26 2022
#include "VendingMachine.h"

//construtor with nothing passed
VendingMachine::VendingMachine() {
  this->foodName = "";
  this-> price   = 0.0;
  this->stock    = 0;
}

//construtor for the products
VendingMachine::VendingMachine(string foodName, double price, int stock) {
  this->foodName = foodName;
  this-> price   = price;
  this->stock    = stock;
}

//displays items, cost, and stock amount
void VendingMachine::Display(int itemNum) {
  cout << left << itemNum << ". " << setw(12) << getFoodName() 
       << right << setw(4) << "$" << fixed << setprecision(2) << getPrice();
  if (getStock() == 0){
    cout << right << setw(13) << "SOLD OUT" << endl;
  } else {
    cout << setw(7) << getStock() << " in stock" << endl;
    }
  
}

//user picks food and verfies input
int VendingMachine::PickFood() {
  int foodNum;
  
  cout << endl << "Pick an item:  ";
  cin >> foodNum;

  while (foodNum < 0 || foodNum > 5)
  {
    cout << "Not avaliable: ";
    cin >> foodNum;
  }
  return foodNum;
}

//User can pick amount of food and decreases
int VendingMachine::DecreaseStock() {
  //so nothing prints if the stock of something was
  //already 0
  if (getStock() == 0) {
    cout << "Item is SOLD OUT" << endl;
    return 0;
  }

  //user picks amount of food
  //out is the availble amount in stock
  int amount;
  cout << "Amount (1-" << getStock() << "): ";
  if (getStock() < 10) {cout << " ";}
  cin >> amount;

  //verifcation
  while (amount < 0 || amount > getStock())
  {
    cout << "Not avaliable: ";
    cin >> amount;
  }
  //decrements
  this->stock -= amount; 
  return amount;
}

//print the total during one purchase
double VendingMachine::TotalCost(int amount) {
  cout << "Your total is: $" << getPrice() * amount << endl << endl;
  return getPrice() * amount;
}

//user enters money
double VendingMachine::CheckOut(double total) {
  double money(0);
  
  cout << "Your total is $" << total << endl;
  cout << "Enter money:  $";
  cin >> money;

  //verifaction so no negative value is entered
  while (money < 0) {
    cout << "Enter money:  $";
    cin >> money;
  } 
  
  //if user gives less then the total
  //prompts user to enter money again
  while (money < total) {
    total -= money;
    cout << "You still owe $" << total << endl;
    cout << "Enter money:  $";
    cin >> money;
  }
  //if user gives more then the total
  //gives change back
  if (money > total) {
    cout << "Change back:  $" << money - total << endl;
    return money - total;
  }
  return 0;
}

//to display the products the user got
string VendingMachine::Reciept(int amount) {
  ostringstream out;
  
  if (amount == 0) {
    return "";
  }
  out << left << amount << " " << setw(12) << getFoodName() << right << setw(5) << " $" << fixed << setprecision(2) << amount * getPrice() << endl;
  return out.str();
}

//GETTERS
string VendingMachine::getFoodName() {
  return this->foodName;
}

double VendingMachine::getPrice() {
  return this->price;
}

int VendingMachine::getStock() {
  return this->stock;
}
