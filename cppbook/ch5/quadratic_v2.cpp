#include "../std_lib_facilities.h"

class No_real_roots{};

int roots(double a, double b, double c)
{
	double discriminant = b*b - 4*a*c;
	if (discriminant < 0) throw No_real_roots{};
	if (discriminant == 0) return 1;
	if (discriminant > 0) return 2;
}

int main()
try{
	double a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0;
	double num_roots = 0, part1 = 0, part2 = 0;
	double quadratic = 0;
	cout<<"\nPlease input quadratic values a, b, and c for: ax^2 + bx + c = 0\n";
	cin>>a>>b>>c;
	num_roots = roots(a,b,c);
	part1 = -b/(2*a);
	part2 = sqrt(abs(b*b - 4*a*c))/(2*a);
	if (num_roots == 1)
	{
		cout<<"There is one real root for "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0\n"
			<<"Real root x = "<<part1<<'\n';
	}
	if (num_roots == 2)
	{
		cout<<"There are two real roots for "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0\n"
			<<"Real root x1 = "<<part1+part2<<'\n'
			<<"Real root x2 = "<<part1-part2<<'\n';
	}
	if (num_roots == 0)
	{
		cout<<"There are two imaginary roots for "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0\n"
			<<"Imaginary root x1 = "<<part1<<" + "<<part2<<"i\n"
			<<"Imaginary root x2 = "<<part1<<" - "<<part2<<"i\n";
	}
}
catch (No_real_roots){
	cout<<"There are no real roots for the quadratic provided\n";
}