#include "../std_lib_facilities.h"

// Write out the first n values of the Fibonacci sequence,
// where each value is the sum of the previous two numbers.
// Number must be below n = 46. 

class Length_zero{};

class Length_one{};

int main()
try{
	cout<<"Please input how many Fibonacci numbers you would like to list: ";
	int n = 0;
	cin>>n;
	vector<int> list {1,1};
	if (n == 0) throw Length_zero{};
	if (n == 1) throw Length_one{};
	for (int i = list.size(); i < n; ++i) {
		int sum = narrow_cast<int>(list[i-2] + list[i-1]);
		list.push_back(sum);
	}
	if (list.size() == n) {
		cout<<"Fibonacci sequence: ";
		for (int i = 0; i <= (list.size()-1); ++i) {
			if ( i == (list.size() - 1) ) cout<<list[i]<<'\n';
			else cout<<list[i]<<", ";
		}
	}
}

catch (Length_zero) {
	cout<<"Must input a value greater than zero.\n";
}

catch (Length_one) {
	cout<<"Fibonacci sequence: 1\n";
}