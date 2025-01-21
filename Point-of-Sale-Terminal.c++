#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;
int main() {
	// user input
	string input;
	//cost from input
	string costIn;
	//payment from input
	string paidIn;
	//where the space is in input
	int space = 0;
	//cost
	float cost = 0;
	//payment
	float paid = 0;
	//first tax amount
	float tax1 = 0;
	//second tax amount
	float tax2 = 0;
	//change
	float change = 0;
	//tax function
	float tax(float,float);
	//round to nearest 5 function
	float round5(float);

	//input
	cout << "Enter price and bill: ";
	getline(cin,input);
	//find the space
	space = input.find(" ");
	//get cost and payment
	costIn = input.substr(0,space);
	paidIn = input.substr(space+1, input.length() - costIn.length() - 1);
	//convert cost and payment to float
	cost = stof(costIn);
	paid = stof(paidIn);
	//convert payment to dollers
	paid = paid/25.00;
	//Item price
	cout << "Item price: " << setw(10) << setprecision(4) << cost << endl;
	//tax 1 and new price
	tax1 = ceil(tax(cost,.05) * 100)/100;
	cost += tax1;
	cout << "Tax 1: " << setw(15) << tax1 << endl;
	//tax 2 and new price
	tax2 = ceil(tax(cost,.09975)*100)/100;
	cost += tax2;
	cout << "Tax 2: " << setw(15) << tax2 << endl;
	cout << "Your total " << setw(11) << cost << endl;
	//payment
	cout << "You paid with $" << paid <<endl;
	//rounded item price
	cost = round5(cost);
	cout << "Rounded item price $" << setw(1) << setprecision(6) << cost <<endl;
	change = paid-cost;
	//change and ammount of bills
	cout << "Your change: $" << setprecision(5) << change << endl;
	int count = 0;
	while(1){
		if(change >= 10.00){
			count++;
			change = change - 10.00;
		}
		else break;
	}
	cout << setw(2) << setprecision(4) << "$" << 10.00 << ": " << count << endl;
	count = 0;
	while(1){
		if(change >= 5.00){
			count++;
			change = change - 5.00;
		}
		else break;
	}
	cout << setw(2) << setprecision(4) << 5.00 << ": " << count << endl;
	count = 0;
	while(1){
		if(change >= 1.00){
			count++;
			change = change - 1.00;
		}
		else break;
	}
	cout << setw(2) << setprecision(4) << 1.00 << ": " << count << endl;
	count = 0;
	while(1){
		if(change >= 0.25){
			count++;
			change = change - 0.25;
		}
		else break;
	}
	cout << setw(2) << 0.25 << ": " << count << endl;
	count = 0;
	while(1){
		if(change >= 0.10){
			count++;
			change = change - 0.10;
		}
		else break;
	}
	cout << setw(2) << setprecision(4) << 0.10 << ": " << count << endl;
	count = 0;
	while(1){
		if(change >= 0.05){
			count++;
			change = change - 0.05;
		}
		else break;
	}
	cout << setw(2) << 0.05 << ": " << count << endl;
	count = 0;
	

	return 0;
}
//calculate tax
float tax(float cost, float percent) {
	return cost*percent;
}
//round to nearcest 5 cents
float round5(float cost){
	return (round(cost*20.00))/20.00;

}
