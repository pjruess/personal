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
	int how_many = 0;
	cout<<"\nHow many primes would you like to find?\n";
	cin>>how_many;
	vector<int> primes;
	for (int current = first; primes.size() < how_many; ++current)
	{
		if (is_prime(current, primes)==true)
		{
			primes.push_back(current);
			cout<<"New prime: "<<current<<'\n';
		}
	}
	cout<<"First "<<how_many<<" primes are: ";
	for (int i = 0; i < primes.size(); ++i){
		cout<<primes[i]<<" ";
	}
	cout<<'\n';
}