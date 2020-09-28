#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	string playerName;
	int skillRating;
	float purchasePrice;

public:
	//constructor: takes in one argument to initialize player
	Player() {}
	Player(string pname,int skills,float price) { playerName = pname, skillRating = skills, purchasePrice=price;}
	//destructor
	~Player() { }

	string GetPlayerName() { return playerName; }
	int GetskillRating() { return skillRating; }
	float GetpurchasePrice() { return purchasePrice; }
	


	void PrintPlayerProperties()
	{
		cout << "\nName: " << playerName << " | Skill Rating: "
			<< skillRating
			<< " | Purchase Price: $"
			<< purchasePrice << endl;

	}

	float AssignPurchasePrice(int skillR)
	{
		
		return (GEP::RandomRange(100, 200) + 500) * skillR;
	}

	
	

};
