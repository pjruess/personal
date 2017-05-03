#include "../std_lib_facilities.h"

int main()
{
	string recip_name = " ";
	string friend_name = " ";
	char friend_sex = 0;
	int recip_age = 0;
	cout<<"Please enter name of recipient\n";
	cin>>recip_name;
	cout<<"Please enter name of friend\n";
	cin>>friend_name;
	cout<<"Please enter friend's sex\n";
	cin>>friend_sex;
	cout<<"Please enter age of recipient\n";
	cin>>recip_age;
	if (recip_age<0 or recip_age>110){
		simple_error("You must be joking...");
	}

	cout<<"Dear "<<recip_name<<",\n"
		<<"    How are you? It's been a while. Miss you. "
		<<"Have you seen "<<friend_name<<" lately? ";
	if (friend_sex == 'm')
	{
		cout<<"If you see "<<friend_name<<" tell him to call me. ";
	}
	if (friend_sex == 'f')
	{
		cout<<"If you see "<<friend_name<<" tell her to call me. ";
	}
	cout<<"I hear you just had a birthday and you are "<<recip_age<<" years old. ";
	if (recip_age<12){
		cout<<"You will be "<<recip_age+1<<" next year! ";
	}
	if (recip_age==17){
		cout<<"Next year you will be able to vote! ";
	}
	if (recip_age>70){
		cout<<"I hope you are enjoying retirement. ";
	}
	cout<<"\nYours sincerely, \n\n\nPaul\n";
}