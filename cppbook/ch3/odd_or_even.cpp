#include "../std_lib_facilities.h"

int main(){
	int num = 0;
	cout<<"Please enter a value to check whether it is odd or even.\n";
	cin>>num;
	if (num % 2 == 0){
		cout<<"The number "<<num<<" is even.\n";
	}
	else{
		cout<<"The number "<<num<<" is odd.\n";

	}
}