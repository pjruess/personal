#include "../std_lib_facilities.h"

int main()
{
	char c = 'a';
	int num = 97;
	while (c<='z') {
		cout<<c<<'\t'<<num<<'\n';
		++c, ++num;
	}
}