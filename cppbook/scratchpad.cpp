#include "std_lib_facilities.h"

int main()
{
	vector<int> list = {1,2,3,4,5};
	int check = 0;
	for (int i = 0; i < list.size(); ++i)
	{
		if (!list[i]) ++check;
	}
	cout<<"Check: "<<check<<'\n';
}