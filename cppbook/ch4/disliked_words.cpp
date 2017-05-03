#include "../std_lib_facilities.h"

int main()
{
	vector<string> words;
	vector<string> disliked = {"broccoli", "carrot", "pepper"};
	for (string temp; cin>>temp; )
		words.push_back(temp);
	for (string word : words)
	{
		for (string test : disliked)
			if (word == test)
			{
				word = "BLEEP";
			}
		cout<<word<<" ";
	}
	cout<<'\n';
}