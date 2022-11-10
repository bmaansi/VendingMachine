// Project: Vending Machine
// Maansi Bhardwaj
//
// Sept 19-26 2022
#include <iostream>
#include <iomanip>
using namespace std;

class VendingMachine
{
  public:
    VendingMachine();
    VendingMachine(string foodName, double price, int stock);
    void Display(int itemNum);
    int DecreaseStock();
    int PickFood();
    double TotalCost(int amount);
    double CheckOut(double total);
    string Reciept(int amount);
    //Getters
    string getFoodName();
    double getPrice();
    int getStock();

  private:
    string foodName;
    double price;
    int stock;
};
