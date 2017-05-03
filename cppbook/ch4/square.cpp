#include "../std_lib_facilities.h"

int square(int x)
{
	int result = 0;
	for (int i=0; i<x; ++i)
		result+=x;
	return result;
}
int main(){
	for (int num = 1; num < 100; ++num)
		cout<<num<<'\t'<<square(num)<<'\n';
}