#include "../std_lib_facilities.h"

int main(){
	constexpr double colombianpesos_to_dollars = 0.00033;
	constexpr double dong_to_dollars = 0.000045;
	constexpr double pounds_to_dollars = 1.44;
	constexpr double euros_to_dollars = 1.13;

	double money = 0;
	char unit = 0;

	cout<<"Please enter money value to convert to dollars, including units.\n";
	cin>>money>>unit;

	switch (unit) {
	case 'c':
		cout<<money<<" Colombian pesos = $"<<money*colombianpesos_to_dollars<<'\n';
		break;
	case 'd': 
		cout<<money<<" Vietnamese dong = $"<<money*dong_to_dollars<<'\n';
		break;
	case 'p':
		cout<<money<<" British pounds = $"<<money*pounds_to_dollars<<'\n';	
		break;
	case 'e':
		cout<<money<<" European euros = $"<<money*euros_to_dollars<<'\n';	
		break;
	default:
		cout<<"Sorry, I don't know that conversion. Please try again.\n";
		break;
	}
}