#include "../std_lib_facilities.h"

int is_prime(int value, vector<int> list)
{
	bool primeness = false;
	int track = 0;
	if (value == 2)
	{ 
		primeness = true;
		list.push_back(value);
	}
	if (value%2==1 && value!=1)
	{
		for (int prime : list)
		{
			if (value%prime != 0)
			{
				++track;
			}
		}
		if (track == list.size())
		{
			primeness = true; 
			list.push_back(value);
			track = 0; 
		}
	}
	return primeness;
}

int main()
{
	int first = 1;
	int last = 100;
	cout<<"\nPlease input a value to determine all primes between one and that value.\n";
	cin>>last;
	vector<int> primes;
	for (int current = first; current <= last; ++current)
	{
		if (is_prime(current, primes)==true)
		{
			primes.push_back(current);
			cout<<"New prime: "<<current<<'\n';
		}
	}
	cout<<"Primes between "<<first<<" and "<<last<<" are: ";
	for (int i = 0; i < primes.size(); ++i){
		cout<<primes[i]<<" ";
	}
	cout<<'\n';
}