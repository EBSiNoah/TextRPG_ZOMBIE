//#include<iostream>
#include "Actor.h"
using namespace std;


Actor::Actor()
{
    Name = "Unreal";
    AttackPower = 0;
    HP = 0;
    MaxHP = 0;
}
Actor::Actor(string inputName, int inputAttackPower, int inputMaxHP)
{
    Name = inputName;
    AttackPower = inputAttackPower;
    HP = inputMaxHP;
    MaxHP = inputMaxHP;
}
int Actor::Attack()// 공격 메서드
{
    return AttackPower;
}
void Actor::onHit(int inputAttackPower) // 피격 메서드
{
    HP -= inputAttackPower;
}
bool Actor::isDead()// 사망 메서드
{
    return HP <= 0;
}
void Actor::printStatus()// 상태 출력 메서드
{
    cout << "Name : " << Name << endl;
    cout << "Attack power : " << AttackPower << endl;
    cout << "Current health point : " << HP << endl;
}