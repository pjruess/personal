#include "../std_lib_facilities.h"

class Bad_temp{};

class Bad_units{};

double ctok(double c)
{
	if (c < -273.15) throw Bad_temp{};
	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{
	if (k < 0) throw Bad_temp{};
	double c = k - 273.15;
	return c;
}

int main()
try{
	cout<<"Input a temperature in celcius (c) or kelvin (k) to be converted...\n";
	double t = 0;
	char u = 0;
	double result = 0;
	cin>>t>>u;
	if (u != 'c' && u != 'k') throw Bad_units{};
	switch (u){
	case 'c':
		result = ctok(t);
		cout<<result<<"k\n";
		break;
	case 'k': 
		result = ktoc(t);
		cout<<result<<"c\n";
		break;
	}
}
catch(Bad_temp){
	cout<<"Temperature input out of range. Please try again.\n";
}
catch(Bad_units){
	cout<<"Units not accepted. Please try again.\n";
}