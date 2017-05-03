#include "../std_lib_facilities.h"

int main(){
	int square = 0;
	int current = 1;
	int sum = 0;
	int required = 0;
	cout<<"Please enter how many grains of rice are needed.\n";
	cin>>required;
	while (sum < required){
		if(square==0){
			++square; // square = 1
			sum+=current; // sum = 1
		}
		else{
			++square;
			current*=2;
			sum+=current;
		}
	}
	cout<<"You need "<<square<<" squares.\n";
}