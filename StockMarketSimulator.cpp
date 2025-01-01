#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

// Stock class to represent individual stock info
struct Stock {
	public:
		string name;
		float price;
		
		Stock(string name, float price) : name(name), price(price) {}
				
		void updatePrice() {
			float change = ((rand() % 100) - 50) / 100.0;
			price *= (1 + change);
			price = round(price * 100) / 100.0;
		}
};

// Portfolio class to manage user's stock holdings
struct Portfolio {
	public:
		map<string, int> holdings;
			
		// Buy stock (add to holdings)
		void buyStock(const string& ticker, int quantity) {
		holdings[ticker] += quantity;
		}
			
		// Sell stock (reduce holdings)
		void sellStock(const string& ticker, int quantity) {
			if (holdings[ticker] >= quantity) {
				holdings[ticker] -= quantity;
			} else {
				cout << "You don't have enough shares of " << ticker << " to sell.\n";
			}
		}
		
		// View portfolio with stock quantities and values
		void viewPortfolio(const map<string, Stock>& stocks) {
			float totalValue = 0;
			cout << "\nYour Portfolio: ";
			cout << left << setw(10) << "Ticker" << setw(15) << "Company" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Value" << endl;
