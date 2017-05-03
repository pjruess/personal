#include "../std_lib_facilities.h"

int main()
{
	cout<<"Please enter an integer\n";
	int n;
	cin>>n;
	cout<<"n == "<<n
	<<"\nn+1 == "<<n+1
	<<"\nthree times n == "<<n*3
	<<"\ntwice n == "<<n+n
	<<"\nn squared == "<<n*n
	<<"\nhalf of n == "<<double(n)/2
	<<"\nsquare root of n == "<<sqrt(double(n))
	<<'\n';
}