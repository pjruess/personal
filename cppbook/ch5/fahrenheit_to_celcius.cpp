#include "../std_lib_facilities.h"

class Bad_temp{};

class Bad_units{};

double ctof(double c)
{
	if (c < -273.15) throw Bad_temp{};
	double f = 9.0/5 * c + 32;
	return f;
}

double ftoc(double f)
{
	if (f < -459.67) throw Bad_temp{};
	double c = (f - 32) * 5.0/9;
	return c;
}

int main()
try{
	cout<<"Input a temperature in celcius (c) or fahrenheit (f) to be converted...\n";
	double t = 0;
	char u = 0;
	double result = 0;
	cin>>t>>u;
	if (u != 'c' && u != 'f') throw Bad_units{};
	switch (u){
	case 'c':
		result = ctof(t);
		cout<<result<<"f\n";
		break;
	case 'f': 
		result = ftoc(t);
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