//#include "../Character.h"
//#include "../ZombieFactory.h"
//#include "../Shop.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//void Opening() {
//	//오프닝
//	cout << "================" << endl;
//	cout << "    좀보이드    " << endl;
//	cout << "================" << endl;
//	cout << "당신은 마지막 생존자입니다. 살아남기 위해서 좀비들과 맞서 싸우세요" << endl;
//}
//
//void CreateCharacter() {
//	string playerName;
//	int choice;
//	cout << " 당신의 캐릭터 이름을 입력하세요: ";
//	cin >> playerName;
//	while (1) { // job test
//		cout << "직업 선택(1. 군인, 2. 직업2) : ";
//		cin >> choice;
//		if (choice == 1)
//		{
//			player = Character(playerName, "군인", 30, 80);
//			break;
//		}
//		else if (choice == 2)
//		{
//			player = Character(playerName, "직업2", 20, 150);
//			break;
//		}
//		else cout << "재입력하쇼";
//	}
//}


//class Monster {
//private:
//	string name;
//	int hp;
//	int attackPower;
//
//	void printStatus() {
//		cout << "좀비" << name << " 등장,  체력: " << hp << ", 공격력: " << attackPower << endl;
//	}
//};

//전투
//void battle(Character& player, Zombie& zombie) {
//	cout << "좀비를 마주쳤습니다. 전투가 시작됩니다." << endl;
//	zombie.printStatus();
//
//	int turn = 1;
//	while (player.hp > 0 && zombie.hp > 0) {
//		cout << "[턴 " << turn++ << "]" << endl;
//
//		zombie.hp -= player.attackPower;
//		if (zombie.hp <= 0) {
//			cout << player.name << "가 " << zombie.name << "을(를) 처치했습니다!" << endl;
//			player.gainExp(zombie.expReward);
//			player.gainGold(zombie.goldReward);
//		}
//		cout << player.name << "가 " << zombie.name << "을(를) 공격했습니다! "
//			<< zombie.name << " 체력: " << zombie.hp << endl;
//
//		player.hp -= zombie.attackPower;
//		if (player.hp <= 0) {
//			cout << player.name << " 체력이 0이 되었습니다. 게임 오버!" << endl;
//		}
//		cout << zombie.name << "이(가) " << player.name << "을(를) 공격했습니다! "
//			<< player.name << " 체력: " << player.hp << endl;
//	}
//}


//class Shop {
//public:
//	void displayItems() {
//		cout << "상점에 오신 것을 환영합니다." << endl;
//	}
//};

//int main() {
//	Character player;
//	Opening(); // 오프닝
//	CreateCharacter(); // 캐릭터 생성 (닉네임, 직업)
//	// 배틀
//	// 선택메뉴 (전투, 상점, 상태)
//	// 엔딩문구
//	
	
	







	//battle();

	//선택 메뉴
//	while {
//		cout << " =====메뉴창===== " << endl;
//		cout << " 1. 전투 시작 " << endl;
//		cout << " 2. 상점 " << endl;
//		cout << " 3. 상태 확인 " << endl;
//		cout << " 0. 게임 종료 " << endl;
//		cout << " 선택: ";
//
//		int choice;
//		cin >> choice;
//	}
//
//	if (choice == 1) {
//		cout << "전투를 시작합니다." << endl;
//	}
//	else if (choice == 2) {
//		cout << "상점에 오신 것을 환영합니다." << endl;
//	}
//	else if (choice == 3) {
//		player.printStatus();
//	}
//	else if (choice == 0) {
//		cout << "게임을 종료합니다." << endl;
//		break;
//	}
//	else {
//		cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
//	}
//}
//
//
////엔딩
//if (playerHp > 0) {
//	cout << "축하합니다, " << playerName << "님! 당신은 마지막" << bossmonsterName << "을(를) 물리치고 마지막 생존자가 되셨습니다." << endl;
//}
//else {
//	cout << "안타깝지만" << playerName << "님은 전투에서 패배하셨습니다...." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "마지막 생존자는 없었습니다." << endl;
//
//}

//return 0;
//}