#include "../std_lib_facilities.h"

int main(){
	vector<double> distances;
	double sum = 0;
	double smallest = 0;
	double largest = 0;
	double previous = 0;
	cout<<"Please enter variable route distances.\n";
	for (double temp; cin>>temp; sum+=temp){
		distances.push_back(temp);
		if (sum == 0) smallest = temp, largest = temp;
		if (temp < previous) smallest = temp; 
		if (temp > previous) largest = temp;
		previous = temp;
	}
	double mean = sum/distances.size();
	cout<<"Sum of distances: "<<sum<<'\n'
		<<"Smallest distance: "<<smallest<<'\n'
		<<"Largest distance: "<<largest<<'\n'
		<<"Mean distance: "<<mean<<'\n';

}