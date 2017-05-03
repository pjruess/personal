#include "../std_lib_facilities.h"

int main(){
	cout<<"\nHello! Welcome to Rock Paper Scissors for one player.\n\n"
		<<"Please select r (rock), p (paper), or s (scissors): ";
	char player = 0;
	int turn = 1;
	int pscore = 0, cscore = 0;
	vector<char> computer = {'r','s','p','r','p','p','s','r','s','r','p','r','s','r','s','s','p','r','r'};
	while (cin>>player && turn < computer.size()){
		cout<<'\n';
		switch (player){
		case 'r': 
			if(computer[turn]=='r') cout<<"You tied!\n";
			if(computer[turn]=='p') cout<<"You lost!\n", ++cscore;
			if(computer[turn]=='s') cout<<"You won!\n", ++pscore;
			++turn;
			break;
		case 'p': 
			if(computer[turn]=='p') cout<<"You tied!\n";
			if(computer[turn]=='s') cout<<"You lost!\n", +cscore;
			if(computer[turn]=='r') cout<<"You won!\n", ++pscore;
			++turn;
			break;
		case 's':
			if(computer[turn]=='s') cout<<"You tied!\n";
			if(computer[turn]=='r') cout<<"You lost!\n", ++cscore;
			if(computer[turn]=='p') cout<<"You won!\n", ++pscore;
			++turn;
			break;
		default: 
			cout<<"You didn't select rock (r), paper (p), or scissors (s). Try again!\n";
			break;
		}
	cout<<"Player selected: "<<player<<'\n'
		<<"Computer selected: "<<computer[turn]<<'\n'
		<<"Current score...\n"
		<<"Player: "<<pscore<<'\t'<<"Computer: "<<cscore<<"\n\n"
		<<"Please enter another selection: ";
	}
}