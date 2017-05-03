#include "../std_lib_facilities.h"

int main()
{
	double input = 0;
	string units = " ";
	double conversion = 1.609;
	cout<<"Please enter value to be converted, with units (ie. mi or km)\n";
	cin>>input>>units;
	if (units=="mi"){
		cout<<input<<" "<<units<<" = "<<input*conversion<<" km\n";
	}
	if (units=="km"){
		cout<<input<<" "<<units<<" = "<<input/conversion<<" mi\n";
	}
}