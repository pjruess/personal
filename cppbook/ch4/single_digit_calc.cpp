#include "../std_lib_facilities.h"

int main(){
	vector<string> numstrs = {"zero", "one", "two", "three", "four",
							  "five", "six", "seven", "eight", "nine"};
	vector<string> numints = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string str1 = "", str2 = "";
	char oper = 0;
	int result = 0;
	int val1=0, val2=0;
	cout<<"Please input two single-digit values and an operation (ie. 3 + 4).\n";
	cin>>str1>>oper>>str2;
	for (int i=0; i<numstrs.size(); ++i)
		if (str1==numstrs[i] || str1==numints[i]) val1 = numbers[i];
	for (int i=0; i<numstrs.size(); ++i)
		if (str2==numstrs[i] || str2==numints[i]) val2 = numbers[i];
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