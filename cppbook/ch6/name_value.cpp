#include "../std_lib_facilities.h"

class Name_value {
	string name;
	double value;
	Name_value(string na, double val)
	:name(na), value(val) { }
};

cout<<"Please enter a name-and-value pair (ie. Joe 22)";
vector<Name_value> name_val;
string n;
value v;
while (cin>>n>>v)
name_val.pushback(Name_value(n,v));

for (name : ) // need to print out name \t value pairs after program termination. 