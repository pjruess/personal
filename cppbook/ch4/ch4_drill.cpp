#include "../std_lib_facilities.h"

int main()
{
	double value = 0;
	double smallest = 0;
	double largest = 0;
	double sum = 0;
	int count = 0;
	bool unit_test = false;
	string unit = "";
	vector<string> units = {"cm", "m", "in", "ft"};
	vector<double> values;
	constexpr double m_to_cm = 100;
	constexpr double cm_to_in = 2.54;
	constexpr double in_to_ft = 12;
	while (cin>>value>>unit) {
		for (string item : units)
			if (unit == item) unit_test = true, unit = item;
		if (!unit_test) simple_error("Unit not accepted. Please try again\n");
		if (unit_test)
			if (unit == "cm") value = value/m_to_cm;
			if (unit == "in") value = value*cm_to_in/m_to_cm;
			if (unit == "ft") value = value*in_to_ft*cm_to_in/m_to_cm;
			if (value < smallest) {
				cout<<value<<" meters is the smallest number so far\n";
				smallest = value;
				unit_test = false;
			}
			if (value > largest) {
				cout<<value<<" meters is the largest number so far\n";
				largest = value;
				unit_test = false;
			}
		sum += value;
		++count;
		values.push_back(value);
	}
	cout<<"Sum of all values entered: "<<sum<<"m\n"
		<<"Number of values entered: "<<count<<'\n'
		<<"Values entered: ";
	sort(values);
	for (int i=0;i<values.size();++i)
		if (i == (values.size()-1)) cout<<values[i]<<"m\n";
	else cout<<values[i]<<"m, ";
}