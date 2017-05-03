#include "../std_lib_facilities.h"

int main()
{
	vector<double> v;
	double median = 0;
	cout<<"Please enter a bunch of double numbers.\n";
	for (double value; cin>>value; ) v.push_back(value);
	sort(v);
	int size = v.size();
	if (size%2==0){
		int index1 = v[(size/2)-1];
		int index2 = v[size/2];
		median = (index1+index2)/2.0;
	}
	if (size%2==1) median = v[size/2];
	cout<<"Median is "<<median<<'\n';
}