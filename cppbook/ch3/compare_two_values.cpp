#include "../std_lib_facilities.h"

int main(){
	double val1 = 0;
	double val2 = 0;
	cout<<"Please enter two integer values\n";
	cin>>val1>>val2;
	if (val1<val2){
		cout<<val1<<" is smaller than "<<val2<<'\n';
		cout<<val2<<" is larger than "<<val1<<'\n';
	}
	if (val2<val1){
		cout<<val2<<" is smaller than "<<val1<<'\n';
		cout<<val1<<" is larger than "<<val2<<'\n';
	}
	if (val1==val2){
		cout<<val1<<" is equal to "<<val2<<'\n';
	}
	cout<<"Sum: "<<val1+val2<<'\n';
	cout<<"Difference: "<<abs(val1-val2)<<'\n';
	cout<<"Product: "<<val1*val2<<'\n';
	cout<<"Ratio of first over second: "<<val1/val2<<'\n';
	cout<<"Ratio of second over first: "<<val2/val1<<'\n';
}