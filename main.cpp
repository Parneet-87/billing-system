#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // for std::setprecision
using namespace std;
struct Item {
 string name;
 int quantity;
 float price;
};
void printBill(const vector<Item>& items) {
 float total = 0;
 cout << "\n--- Bill ---\n";
 cout << left << setw(20) << "Item Name" 
 << setw(10) << "Quantity"
 << setw(10) << "Price" 
 << setw(10) << "Total" << endl;
 for (const auto& item : items) {
 float itemTotal = item.quantity * item.price;
 cout << left << setw(20) << item.name 
 << setw(10) << item.quantity 
 << setw(10) << fixed << setprecision(2) << item.price 
 << setw(10) << itemTotal << endl;
 total += itemTotal;
 }
 cout << "-------------------------------------------\n";
 cout << "Total Amount: " << fixed << setprecision(2) << 
total << endl;
}
int main() {
 vector<Item> items;
 char choice;
 do {
 Item newItem;
 cout << "Enter item name: ";
 cin >> newItem.name;
 cout << "Enter quantity: ";
 cin >> newItem.quantity;
 cout << "Enter price: ";
 cin >> newItem.price;
 items.push_back(newItem);
 cout << "Do you want to add another item? (y/n): ";
 cin >> choice;
 } while (choice == 'y' || choice == 'Y');
 printBill(items);
 return 0;
}