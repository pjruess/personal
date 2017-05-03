#include "../std_lib_facilities.h"

//read name and age

int main()
{
	cout<<"Please input first name and age\n";
	string first_name="???";
	double age_years=0;
	cin>>first_name>>age_years;
	cout<<"Hello, "<<first_name<<"(age "<<age_years*12<<" months)\n";
}