#include "../std_lib_facilities.h"

int main()
{
	int i = 97;
	for (char c='a'; c<='z'; ++c, ++i) {
		cout<<c<<'\t'<<i<<'\n';
	}
	for (char c='A'; c<='Z'; ++c, ++i) {
		cout<<c<<'\t'<<i<<'\n';
	}

}