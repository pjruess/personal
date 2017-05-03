#include "../std_lib_facilities.h"

int main(){
	vector<string> numstrs = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	vector<int> numints = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string request = "";
	cout<<"Please input a number in string (ie. zero) format.\n";
	cin>>request;
	// for (int i = 0; i<numstrs.size(); ++i)
		// if (numstrs[i]==request) cout<<"The string "<<request<<" correlates to "<<numints[i];
	for (int i = 0; i<numstrs.size(); ++i)
		if (numstrs[i]==request){
			int tempreq=numints[i];
			cout<<"The integer "<<tempreq<<" correlates to "<<numstrs[i];
		}
	cout<<'\n';
}