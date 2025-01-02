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
			for (const auto& entry : holdings) {
				const  string& ticker = entry.first;
				int quantity = entry.second;
				float price = stocks.at(ticker).price;
				float value = price * quantity;
				totalValue += value;
				cout << left << setw(10) << ticker << setw(15) << stocks.at(ticker).name << setw(10) << quantity << setw(10) << price << setw(10) << value << endl;
			}
			cout << "\nTotal Portfolio Value: $" << fixed << setprecision(2) <<totalValue << endl;
		}
};

// Display available stocks
void displayStocks(const map<string, Stock>& stocks) {
	cout << "\nAvailable Stocks: ";
	cout << left << setw(10) << "Ticker" << setw(15) << "Company" << setw(10) << "Price" << endl;
	for  (const auto& stock : stocks) {
		cout << left << setw(10) << stock.first << setw(15) << stock.second.name << setw(10) << stock.second.price << endl;
		
	}
}

//Main function to simulate stock trading
int main() {
	srand(time(0)); //// Seed for random number generation
	
