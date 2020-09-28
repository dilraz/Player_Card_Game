#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Random.h"
#include "Player.h"
class PlayerPoolGenerator
{

private:
	Player* players;
	int totalPlayers;

public:
	PlayerPoolGenerator(){}
	PlayerPoolGenerator(int numOfPlayers){
		totalPlayers = numOfPlayers;
	}
	~PlayerPoolGenerator(){}

	

	static string RandomNameGenerator(){
		
		string name = "";
		name += 'A' + GEP::RandomRange(0, 25);
		name += ". ";
		for(int i=0;i<3;i++){
		char c = 'A' + GEP::RandomRange(0, 25);
		name += c;
		}
		return name;
	}

	Player* GeneratePlayers()
	{
		players = new Player[totalPlayers];
		for (int i = 0;i < totalPlayers;i++)
		{
			int skill = GEP::RandomRange(20, 100);
			players[i] = Player(RandomNameGenerator(),skill,players[i].AssignPurchasePrice(skill));
			
		}
		
		return players;
	}

	void displayPool()
	{
		cout << "****** PLAYER CARDS *******\n\n";
		for (int i = 0;i < totalPlayers;i++)
		{
			
			cout << i+1 << ". Player Name: " << players[i].GetPlayerName() 
				<< " | Skill Rating: " << players[i].GetskillRating() << " | Purchase Price: $" << players[i].GetpurchasePrice() << endl;
		}
	}
	void displayPlayer(int i)
	{
		cout <<  "-> Player Name: " << players[i].GetPlayerName()
			<< "\n-> Skill Rating: " << players[i].GetskillRating() << "\n-> Purchase Price: $" << players[i].GetpurchasePrice() << endl;
	}



};