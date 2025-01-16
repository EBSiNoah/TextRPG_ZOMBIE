#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Actor
{
//protected:
	
public:
	string Name;//Name of Actor object
	int AttackPower;//Attack power of Actor object
	int HP;//Current health point of Actor object
	int MaxHP;//Maximun health point of Actor object

	Actor();
	Actor(string inputName, int inputAttackPower, int inputMaxHP);

	virtual int Attack();
	virtual void onHit(int inputAttackPower);
	bool isDead();
	void printStatus();
};
