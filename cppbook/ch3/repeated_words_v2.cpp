#include "../std_lib_facilities.h"

int main()
{
	string previous = " ";
	string current;
	int num_words = 0;
	int count = 0;
	while (cin>>current){
		++num_words;
		if (previous == current)
			// ++count;
			cout<<"Word number "<<num_words<<" repeated: "<<current<<'\n';
				// <<"Number of repeated words: "<<count<<'\n';
		previous = current;
	}
}