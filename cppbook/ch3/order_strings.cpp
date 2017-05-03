#include "../std_lib_facilities.h"

int main(){
	string a = " ", b = " ", c = " ";
	cout<<"Please enter three strings to be sorted alphabetically\n";
	cin>>a>>b>>c;
	if (a<b){
		if (a<c){
			if (b<c){
				cout<<a<<", "<<b<<", "<<c<<'\n';
			}
			else{
				cout<<a<<", "<<c<<", "<<b<<'\n';
			}
		}
		else{
			cout<<c<<", "<<a<<", "<<b<<'\n';
		}
	}
	else if(b<c){
		if(a<c){
			cout<<b<<", "<<a<<", "<<c<<'\n';
		}
		else{
			cout<<b<<", "<<c<<", "<<a<<'\n';
		}
	}
	else{
		cout<<c<<", "<<b<<", "<<a<<'\n';
	}
}