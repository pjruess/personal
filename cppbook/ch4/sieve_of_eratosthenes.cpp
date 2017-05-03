#include "../std_lib_facilities.h"

int main()
{
	int first = 1;
	int last = 100;
	cout<<"\nPlease input a value to search for all primes between one and that value.\n";
	cin>>last;
	vector<int> primes;
	vector<int> composites;
	int track = 0;
	bool check_prime = true;
	for (int current = first; current <= last; ++current)
	{
		if (current != 1)
		{
			for (int i = 0; i < composites.size(); ++i)
			{
				if (current == composites[i])
				{
					check_prime = false;
					break;
				}
			}
			if (check_prime)
			{
				primes.push_back(current);
				cout<<"New prime: "<<current<<'\n';
				for (int num = first; num <= last; ++num)
				{
					if (num != current && num%current == 0)
					{
						composites.push_back(num);
					}
				}
			}
			check_prime = true;
		}
	}
	cout<<"Primes between "<<first<<" and "<<last<<" are: ";
	for (int i = 0; i < primes.size(); ++i){
		cout<<primes[i]<<" ";
	}
	cout<<'\n';
}