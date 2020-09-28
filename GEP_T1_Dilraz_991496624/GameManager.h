#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "PlayerPoolGenerator.h"
#include "Team.h"

class GameManager
{
private:
	PlayerPoolGenerator* pool;
	Team* team;
	int totalPlayers;
	Player* players;
	vector<Player> purchasedPlayers;
	int remainingPlayers;
	int numPurchased;

public:
	 GameManager() {
		int numOfPlayers;
		cout << "How Many Player Cards Do you Want?\n";
		cin >> numOfPlayers;
		pool = new PlayerPoolGenerator(numOfPlayers);
		players = pool->GeneratePlayers();

		totalPlayers = numOfPlayers;
		remainingPlayers = numOfPlayers;

	}
	~GameManager() {}


	int Main()
	{

		setUpTeam();
		cout << "\nWelcome Team " << team->GetTeamName() << "! Your Cash Available is: $" << team->GetCashAvailable() << " Here are your player cards to choose from:\n\n";

		
		while (team->canBuy(players,totalPlayers))
		{
			pool->displayPool();
			cout << "\n";
			for(int x = 0;x<totalPlayers;x++){
				int choice;
				cout << "\n- - - - - - - - - - - - - - -\n";
				cout << "Number of Remaining Cards: " << remainingPlayers << endl;
				cout << "\n+++++++++++++++++++++++++\n" << "\nCARD #" << x + 1 << "/" << totalPlayers << endl;

				pool->displayPlayer(x);
				cout << "\n+++++++++++++++++++++++++\n";
				team->PrintTeamProperties();
				cout << "Buy Player (1) OR SKIP (2)\n";
				cin >> choice;
				if (team->GetCashAvailable() > players[x].GetpurchasePrice()) {
					if (choice == 1)
					{
						team->addPurchasedPlayers();
						remainingPlayers -= 1;
						purchasedPlayers.push_back(players[x]);
						team->ReduceCashAvailable(players[x].GetpurchasePrice());
						team->addCashSpent(players[x].GetpurchasePrice());
					}
				}
				else {
					cout << "\n- - - - - - - - - - - - - - -\n";
					cout << "\nYou Dont Have Enough Money!\n";
				}
					 if (choice == 2)
					{
						cout << "\nSkipping To the next card!\n";
					}
					

					
				}
				
		}
		team->calculateSkill(purchasedPlayers, team->GetPurchasedPlayers());
		float cashPerSkill = (team->GetCashSpent() / team->GetCumulativeSkillRating());
		cout << "\n\n*** " << team->GetTeamName() << "'s TEAM ***" << endl;
		for (int i = 0; i < purchasedPlayers.size();i++)
		{
			purchasedPlayers[i].PrintPlayerProperties();
		}
		cout << "\nCash Left: $" << team->GetCashAvailable() << " | Cash Spent: $" << team->GetCashSpent() << " | Average Skill Rating: "
			<< (team->GetCumulativeSkillRating() / team->GetPurchasedPlayers()) << "\n Average Cash Spent Per Skill Point: $" 
			<< cashPerSkill << endl;
		return 0;
	}


	void setUpTeam()
	{
		string name;
	
		cout << "Please Enter Your Team Name:\n";
		cin >> name;
		team = new Team(name, 100000);
	}



};