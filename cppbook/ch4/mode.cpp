#include "../std_lib_facilities.h"

// Determines the mode of a list of numbers. 
// Does not work if there are multiple modes. 

int main()
{
	vector<int> list;
	vector<int> new_list;
	bool in_counter = false;
	bool in_new_list = false;
	cout<<"\nPlease input a list of numbers to determine the mode.\n";
	for (int temp; cin>>temp; )
	{
		list.push_back(temp);
		if (new_list.size()==0)
		{
			new_list.push_back(temp); 
		}
		for (int item : new_list)
		{
			if (temp == item && new_list.size() > 0)
			{
				// cout<<"Temp: "<<temp<<'\n'
					// <<"Item: "<<item<<'\n';
				in_new_list = true;
			}
		}
		if (!in_new_list)
		{
			new_list.push_back(temp);
			cout<<"Added to new_list\n";
		}
		in_new_list = false;
	}

	vector<int> counter(new_list.size());
	int mode_freq = 0;
	int mode_index = 0;

	for (int i = 0; i < new_list.size(); ++i)
	{
		// cout<<"New list index i: "<<i<<'\n';
		for (int k = 0; k < list.size(); ++k)
		{
			// cout<<"Original list index k: "<<k<<'\n';
			if (new_list[i]==list[k])
			{
				++counter[i];
			}
		}
	}
	cout<<"\nList of unique numbers and values: \n";
	for (int item : new_list) cout<<item<<" "; cout<<'\n';
	for (int count : counter) cout<<count<<" "; cout<<'\n';

	for (int i = 0; i < counter.size(); ++i)
	{
		if (counter[i] > mode_freq)
		{
			mode_freq = counter[i];
			mode_index = i;
		}
	}
	cout<<"Mode is "<<new_list[mode_index]<<'\n';
}