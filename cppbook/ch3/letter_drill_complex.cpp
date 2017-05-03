#include "../std_lib_facilities.h"

int main()
{
	string recip_name = " ";
	int counter = 0;
	cout<<"Please enter name of recipient\n";
	cin>>recip_name;
	if (cin.get() == '\n')
		++counter;
		cout<<counter;

	string letter_body;
	cout<<"Please enter body of letter\n";
	if (counter > 0)
		while (cin.get() == '\n')
			cin>>letter_body;
			cout<<"Dear "<<recip_name<<",\n"
				<<"    "<<letter_body<<'\n';
}