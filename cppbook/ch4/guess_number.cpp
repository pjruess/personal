#include "../std_lib_facilities.h"

// Not functioning properly

int main(){
	int guess;
	int high = 100;
	int low = 1;
	char reply = 0;
	cout<<"Please think of a number between "<<low<<" and "<<high<<".\n\n";
	guess = (high-low)/2;

	while (high-low!=1) {
		cout<<"Is your number less than "<<guess<<" (y/n)?\n";
		cin>>reply;
		if (reply=='y') {
			high = guess;
			guess -= (high-low)/2;
		}
		else if (reply=='n') {
			low = guess;
			guess += (high-low)/2;
		}
		else cout<<"Did not input y or n. Please try again.\n";
	}
	if (high == 2) guess = 1;
	cout<<"Your number is: "<<guess<<'\n';
}