#include "../std_lib_facilities.h"

// Maximum that can be calculated for int are 31 grains (sum 2147483647)

// Maximum that can be calculated for double are 64 grains (sum 1.84467e19)

int main(){
	double square = 0;
	double current = 1;
	double sum = 0;
	double total = 64;
	cout<<"Number of rice grains in 64 squares.\n\n";
	while (square < total){
		if (square==0){
			++square;
			sum+=current;
			cout<<"Square "<<square<<", Current "<<current<<", Sum "<<sum<<'\n';
		}
		else{
			++square;
			current*=2;
			sum+=current;
			cout<<"Square "<<square<<", Current "<<current<<", Sum "<<sum<<'\n';
		}
	}
}