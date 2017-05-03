#include "../std_lib_facilities.h"

int main(){
	string op = " ";
	double val1 = 0;
	double val2 = 0;
	cout<<"Please enter an operator and two operands (ie. + 100 3.14).\n";
	cin>>op>>val1>>val2;
	if (op == "+" or op == "plus"){
		cout<<val1<<" "<<op<<" "<<val2<<" = "<<val1+val2;
	}
	if (op == "-" or op == "minus"){
		cout<<val1<<" "<<op<<" "<<val2<<" = "<<val1-val2;
	}
	if (op == "*" or op == "mult"){
		cout<<val1<<" "<<op<<" "<<val2<<" = "<<val1*val2;
	}
	if (op == "/" or op == "div"){
		cout<<val1<<" "<<op<<" "<<val2<<" = "<<val1/val2;
	}
	cout<<'\n';
}