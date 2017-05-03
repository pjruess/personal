#include "../std_lib_facilities.h"

int area(int length, int width){
	return length*width;
}

int main(){
	int s1 = narrow_cast<int>(area(999999,999999999));
	cout<<s1<<'\n';
}