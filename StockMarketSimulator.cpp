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
