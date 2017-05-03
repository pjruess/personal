#include "../std_lib_facilities.h"

int main(){
	double a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0;
	double root = 0, part1 = 0, part2 = 0;
	bool i_value = false;
	double quadratic = 0;
	cout<<"\nPlease input quadratic values a, b, and c.\n";
	cin>>a>>b>>c;
	root = b*b-4*a*c;
	part1 = -b/(2*a);
	part2 = sqrt(abs(root))/(2*a);
	if (root<0)
	{
		i_value = true;
	}
	if (i_value)
	{
		cout<<"Quadratic for "<<a<<" x^2 + "<<b<<" x + "<<c<<" = 0 is...\n"
			<<"x1 = "<<part1<<" + "<<part2<<"i\n"
			<<"x2 = "<<part1<<" - "<<part2<<"i\n";
	}
	if (!i_value)
	{
		cout<<"Quadratic for "<<a<<" x^2 + "<<b<<" x + "<<c<<" = 0 is...\n"
			<<"x1 = "<<part1+part2<<"\n"
			<<"x2 = "<<part1-part2<<"\n";
	}
}