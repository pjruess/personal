#include "../std_lib_facilities.h"

class Too_many_guesses{};

class Too_few_guesses{};

vector<int> bulls_and_cows(vector<int> guesses, vector<int> numbers)
{
	vector<int> bulls_cows;
	int bulls = 0, cows = 0;
	for (int i = 0; i < guesses.size(); ++i)
	{
		if (guesses[i] == numbers[i]) ++bulls;
		for (int num : numbers)
		{
			if (guesses[i] != numbers[i] && guesses[i] == num) ++cows;
		}
	}
	bulls_cows.push_back(bulls);
	bulls_cows.push_back(cows);
	return bulls_cows;
}

int main()
try {
	vector<int> numbers;
	bool win = false;
	int temp = 0;
	// int seed = 0;
	// cout<<"Please input any number: \n";
	// cin>>seed;
	// seed_randint(seed);
	for (int i = 0; i < 4; ++i) {
		numbers.push_back(randint(10)); // always inputs 0, 1, 8, 5
	}
	while (!win) {
		cout<<"Please input four integer guesses: \n";
		vector<int> guesses = {};
		while (guesses.size() != numbers.size() && cin>>temp) {
			guesses.push_back(temp);
			cout<<"Guess added: "<<temp<<'\n';
		}
		if (guesses.size() < numbers.size()) throw Too_few_guesses{};
		if (guesses.size() > numbers.size()) throw Too_many_guesses{};
		vector<int> bulls_cows = bulls_and_cows(guesses, numbers);
		cout<<"Update... Bulls: "<<bulls_cows[0]<<", Cows: "<<bulls_cows[1]<<'\n';
		if (bulls_cows[0] != numbers.size()) {
			cout<<"You have found "<<bulls_cows[0]<<" bulls and "<<bulls_cows[1]<<" cows\n";
		}
		if (bulls_cows[0] == numbers.size()) {
			cout<<"You win!\n"
				<<"Try again? (y/n)\n";
			char c = 0;
			cin>>c;
			switch (c) {
			case 'y': 
				win = false;
				break;
			case 'n': 
				win = true;
				break;
			default: 
				cout<<"Character input not accepted";
				break;
			}
		}
	}
} catch (Too_few_guesses) {
	cerr<<"Too few guesses. Please try again.\n";
} catch (Too_many_guesses) {
	cerr<<"Too many guesses. Please try again.\n";
}