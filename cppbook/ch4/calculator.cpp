#include "../std_lib_facilities.h"

int main(){
	double val1 = 0, val2 = 0;
	char oper = 0;
	double result = 0;
	cout<<"Please input two double values and an operation (ie. 3+4).\n";
	cin>>val1>>oper>>val2;
	switch (oper){
	case '+': 
		result = val1+val2;
		cout<<"The sum of "<<val1<<" and "<<val2<<" is "<<result<<'\n';
		break;
	case '-': 
		result = val1-val2;
		cout<<"The difference of "<<val1<<" and "<<val2<<" is "<<result<<'\n';
		break;
	case '*': 
		result = val1*val2;
		cout<<"The product of "<<val1<<" and "<<val2<<" is "<<result<<'\n';
		break;
	case '/': 
		result = val1/val2;
		cout<<"The quotient of "<<val1<<" and "<<val2<<" is "<<result<<'\n';
		break;
	default: 
		cout<<"The entry is not supported.\n";
	}
}