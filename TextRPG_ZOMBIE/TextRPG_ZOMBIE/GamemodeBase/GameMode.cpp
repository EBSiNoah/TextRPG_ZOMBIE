//#include "../Character.h"
//#include "../ZombieFactory.h"
//#include "../Shop.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//void Opening() {
//	//������
//	cout << "================" << endl;
//	cout << "    �����̵�    " << endl;
//	cout << "================" << endl;
//	cout << "����� ������ �������Դϴ�. ��Ƴ��� ���ؼ� ������ �¼� �ο켼��" << endl;
//}
//
//void CreateCharacter() {
//	string playerName;
//	int choice;
//	cout << " ����� ĳ���� �̸��� �Է��ϼ���: ";
//	cin >> playerName;
//	while (1) { // job test
//		cout << "���� ����(1. ����, 2. ����2) : ";
//		cin >> choice;
//		if (choice == 1)
//		{
//			player = Character(playerName, "����", 30, 80);
//			break;
//		}
//		else if (choice == 2)
//		{
//			player = Character(playerName, "����2", 20, 150);
//			break;
//		}
//		else cout << "���Է��ϼ�";
//	}
//}


//class Monster {
//private:
//	string name;
//	int hp;
//	int attackPower;
//
//	void printStatus() {
//		cout << "����" << name << " ����,  ü��: " << hp << ", ���ݷ�: " << attackPower << endl;
//	}
//};

//����
//void battle(Character& player, Zombie& zombie) {
//	cout << "���� �����ƽ��ϴ�. ������ ���۵˴ϴ�." << endl;
//	zombie.printStatus();
//
//	int turn = 1;
//	while (player.hp > 0 && zombie.hp > 0) {
//		cout << "[�� " << turn++ << "]" << endl;
//
//		zombie.hp -= player.attackPower;
//		if (zombie.hp <= 0) {
//			cout << player.name << "�� " << zombie.name << "��(��) óġ�߽��ϴ�!" << endl;
//			player.gainExp(zombie.expReward);
//			player.gainGold(zombie.goldReward);
//		}
//		cout << player.name << "�� " << zombie.name << "��(��) �����߽��ϴ�! "
//			<< zombie.name << " ü��: " << zombie.hp << endl;
//
//		player.hp -= zombie.attackPower;
//		if (player.hp <= 0) {
//			cout << player.name << " ü���� 0�� �Ǿ����ϴ�. ���� ����!" << endl;
//		}
//		cout << zombie.name << "��(��) " << player.name << "��(��) �����߽��ϴ�! "
//			<< player.name << " ü��: " << player.hp << endl;
//	}
//}


//class Shop {
//public:
//	void displayItems() {
//		cout << "������ ���� ���� ȯ���մϴ�." << endl;
//	}
//};

//int main() {
//	Character player;
//	Opening(); // ������
//	CreateCharacter(); // ĳ���� ���� (�г���, ����)
//	// ��Ʋ
//	// ���ø޴� (����, ����, ����)
//	// ��������
//	
	
	







	//battle();

	//���� �޴�
//	while {
//		cout << " =====�޴�â===== " << endl;
//		cout << " 1. ���� ���� " << endl;
//		cout << " 2. ���� " << endl;
//		cout << " 3. ���� Ȯ�� " << endl;
//		cout << " 0. ���� ���� " << endl;
//		cout << " ����: ";
//
//		int choice;
//		cin >> choice;
//	}
//
//	if (choice == 1) {
//		cout << "������ �����մϴ�." << endl;
//	}
//	else if (choice == 2) {
//		cout << "������ ���� ���� ȯ���մϴ�." << endl;
//	}
//	else if (choice == 3) {
//		player.printStatus();
//	}
//	else if (choice == 0) {
//		cout << "������ �����մϴ�." << endl;
//		break;
//	}
//	else {
//		cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���." << endl;
//	}
//}
//
//
////����
//if (playerHp > 0) {
//	cout << "�����մϴ�, " << playerName << "��! ����� ������" << bossmonsterName << "��(��) ����ġ�� ������ �����ڰ� �Ǽ̽��ϴ�." << endl;
//}
//else {
//	cout << "��Ÿ������" << playerName << "���� �������� �й��ϼ̽��ϴ�...." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "." << endl;
//	cout << "������ �����ڴ� �������ϴ�." << endl;
//
//}

//return 0;
//}