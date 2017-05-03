#include "../std_lib_facilities.h"

class N_too_large{};

int sum_numbers(int n, vector<int> numbers)
{
	if (n > numbers.size()) throw N_too_large{};
	int sum = 0;
	for (int i = 0; i < n; ++i) sum+=numbers[i];
	return sum;
}

void error(string s)
{
	throw runtime_error(s);
}

int main()
try {
	int n = 0;
	vector<int> numbers;
	cout<<"Please enter the number of values you want to sum: \n";
	cin>>n;
	if (!cin) error("N must be an integer");
	if (n < 0) error("N must be a positive number"); 
	cout<<"\nPlease enter a vector of integers (type '|' to stop): \n";
	for (int temp; cin>>temp; ) numbers.push_back(temp);
	int sum = sum_numbers(n,numbers);
	cout<<"The sum of the first "<<n<<" integers is "<<sum<<'\n';
} catch (N_too_large) {
	cout<<"N must be less than or equal to number of integers provided\n";
} catch (runtime_error&e) {
	cerr<<"runtime error: "<<e.what()<<'\n';
}
