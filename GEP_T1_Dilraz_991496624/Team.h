

#pragma once
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Team
{
private:
	string teamName;
	float cashAvailable;
	float cashspent;
	Player* players;
	int purchasedPlayers;
	float cumulativeSkillRating;

public:
	//constructor: takes in one argument to initialize player
	Team() {}
	Team(string pname, float cash) { teamName = pname, cashAvailable = cash; }
	//destructor
	~Team() { }

	string GetTeamName() { return teamName; }
	float GetCashAvailable() { return cashAvailable; }
	float GetCashSpent() { return cashspent; }
	int GetPurchasedPlayers() { return purchasedPlayers; }
	float GetCumulativeSkillRating() { return cumulativeSkillRating; }



	void PrintTeamProperties()
	{
		cout << "\nCash available:   $" << cashAvailable << " | Cash Spent: $" << cashspent 
			<< " | Players Purchased: " << purchasedPlayers << endl;
			

	}

	void addPurchasedPlayers()
	{
		purchasedPlayers += 1;
	}
	void addCashSpent(int price)
	{
		cashspent += price;
	}
	
	void ReduceCashAvailable(float price)
	{
		cashAvailable = cashAvailable - price;
	}

	bool canBuy(Player* players,int totalPlayers)
	{
		for (int i = 0;i < totalPlayers;i++)
		{
			if (!(cashAvailable > players[i].GetpurchasePrice()))
			{
				return false;
				
			}
		}
		return true;
	}

	void calculateSkill(vector<Player> purchased,int total)
	{
		int skill=0;
		for (int i = 0;i < total;i++)
		{
			skill += purchased[i].GetskillRating();
		}
		cumulativeSkillRating = skill;
	}


};
