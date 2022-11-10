// Project: Vending Machine
// Maansi Bhardwaj
//
// Sept 19-26 2022

#include "VendingMachine.h"

int main() {
  //variables 
  int    pickFood(0);
  int    amount(0);
  double total(0.0);
  double changeBack(0.0);
  char   goAgain('y');
  char   getReciept('y');
  string reciept("");

  //initilization 
  VendingMachine vm;
  VendingMachine vm1("Potato Chips", 2.00, 13);
  VendingMachine vm2("Snickers", 2.50, 8);
  VendingMachine vm3("M&Ms", 1.50, 10);
  VendingMachine vm4("Hot Cheetos", 2.50, 6);
  VendingMachine vm5("Pepsi", 1.75, 12);
  
  printf("\033c");
  
  do {
    cout << "------------VENDING MACHINE------------" << endl;
    //To display the choices and 0 to exit
    vm1.Display(1);
    vm2.Display(2);
    vm3.Display(3);
    vm4.Display(4);
    vm5.Display(5);
    cout << "0. Checkout" << endl;

    //pick food and will break
    pickFood = vm.PickFood();
    if (pickFood == 0) {
      printf("\033c");
      break;
      }

    //switch statement to decrease stock and total amount
    //based on what the user picks
    switch (pickFood) {
      case 1: 
        amount = vm1.DecreaseStock();
        total += vm1.TotalCost(amount);
        reciept += vm1.Reciept(amount);
        break;
      case 2: 
        amount = vm2.DecreaseStock();
        total += vm2.TotalCost(amount);
        reciept += vm2.Reciept(amount);
        break;
      case 3: 
        amount = vm3.DecreaseStock();
        total += vm3.TotalCost(amount);
        reciept += vm3.Reciept(amount);
        break;
      case 4: 
        amount = vm4.DecreaseStock();
        total += vm4.TotalCost(amount);
        reciept += vm4.Reciept(amount);
        break;
      case 5: 
        amount = vm5.DecreaseStock();
        total += vm5.TotalCost(amount);
        reciept += vm5.Reciept(amount);
        break;
    }
  
    //ask user to buy again
    cout << "Buy again (y/n): ";
    cin >> goAgain;
    cout << endl;
   printf("\033c");
  } while(goAgain == 'y' || goAgain == 'Y');
  
  changeBack = vm.CheckOut(total);
  
  cout << "\nGet reciept (y/n): ";
  cin >> getReciept;
  if (getReciept == 'y' || getReciept == 'Y') {
    printf("\033c");
    cout << "--------RECIEPT--------" << endl;
    cout << reciept; 
    cout << "-----------------------" << endl;
    cout << "Total:" << setw(13) << "$" << total << endl;
    cout << "Change:" << setw(12) << "$" << changeBack << endl;
  } else {
    printf("\033c");
    }
}
