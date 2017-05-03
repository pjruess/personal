#include "../std_lib_facilities.h"

int main(){
	string num = " ";
	int value = 0;
	cout<<"Please enter a string number between zero and four: \n";
	cin>>num;
	if (num!="zero" and num!="one" and num!="two" and num!="three" and num!="four"){
		simple_error("I do not know that number. Please try again.\n");
	}
	if (num=="one"){
		value = 1;
	}
	if (num=="two"){
		value = 2;
	}
	if (num=="three"){
		value = 3;
	}
	if (num=="four"){
		value = 4;
	}
	cout<<"The number "<<num<<" is "<<value<<'\n';
}