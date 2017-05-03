#include "../std_lib_facilities.h"

int main(){
	int pennies = 0, nickels = 0, dimes = 0, quarters = 0, dollars = 0;
	double cents = 0;
	cout<<"How many pennies do you have?\n";
	cin>>pennies;
	cout<<"How many nickels do you have?\n";
	cin>>nickels;
	cout<<"How many dimes do you have?\n";
	cin>>dimes;
	cout<<"How many quarters do you have?\n";
	cin>>quarters;
	cout<<"How many dollars do you have?\n";
	cin>>dollars;
	cents = pennies + 5*nickels + 10*dimes + 25*quarters + 100*dollars;
	if (pennies == 1){
		cout<<"You have "<<pennies<<" penny.\n";
	}
	else{
		cout<<"You have "<<pennies<<" pennies.\n";
	}
	if (nickels == 1){
		cout<<"You have "<<nickels<<" nickel.\n";
	}
	else{
		cout<<"You have "<<nickels<<" nickels.\n";
	}
	if (dimes == 1){
		cout<<"You have "<<dimes<<" dime.\n";
	}
	else{
		cout<<"You have "<<dimes<<" dimes.\n";
	}
	if (quarters == 1){
		cout<<"You have "<<quarters<<" quarter.\n";
	}
	else{
		cout<<"You have "<<quarters<<" quarters.\n";
	}
	if (dollars == 1){
		cout<<"You have "<<dollars<<" dollar.\n";
	}
	else{
		cout<<"You have "<<dollars<<" dollars.\n";
	}
	cout<<"You have "<<cents<<" cents.\n"
		<<"You have $"<<cents/100<<"!\n";
}