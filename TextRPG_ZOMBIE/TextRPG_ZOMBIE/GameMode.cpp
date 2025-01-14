#include "Character.h"
#include "ZombieFactory.h"
#include "Shop.h"

#include <iostream>
#include <string>
using namespace std;

class Character {
private:
	string name;
	int hp;
	int attackPower;
	int exp;
	int gold;

	public
		void gainExp(int amount) { exp += amount; }
	void gainGold(int amount) { gold += amount; }
};

class Monster {
private:
	string name;
	int hp;
	int attackPower;

	void printStatus() {
		cout << "����" << name << " ����,  ü��: " << hp << ", ���ݷ�: " << attackPower << endl;
	}
};

//����
void battle(Character& player, Zombie& zombie) {
	cout << "���� �����ƽ��ϴ�. ������ ���۵˴ϴ�." << endl;
	zombie.printStatus();

	int turn = 1;
	while (player.hp > 0 && zombie.hp > 0) {
		cout << "[�� " << turn++ << "]" << endl;

		zombie.hp -= player.attackPower;
		if (zombie.hp <= 0) {
			cout << player.name << "�� " << zombie.name << "��(��) óġ�߽��ϴ�!" << endl;
			player.gainExp(zombie.expReward);
			player.gainGold(zombie.goldReward);
		}
		cout << player.name << "�� " << zombie.name << "��(��) �����߽��ϴ�! "
			<< zombie.name << " ü��: " << zombie.hp << endl;

		player.hp -= zombie.attackPower;
		if (player.hp <= 0) {
			cout << player.name << " ü���� 0�� �Ǿ����ϴ�. ���� ����!" << endl;
		}
		cout << zombie.name << "��(��) " << player.name << "��(��) �����߽��ϴ�! "
			<< player.name << " ü��: " << player.hp << endl;
	}
}

class ZombieFactory {
public:
	static Monster CreateZombie(int playerLever1) {
		string zombieName = "����";
		int hp = playerLever1 * 10;
		int attackPower = playerLever1 * 10;
		int expReward = playerLever1 * 10;
		int goldReward = playerLever1 * 10;
	}
}

class Shop {
public:
	void displayItems() {
		cout << "������ ���� ���� ȯ���մϴ�." << endl;
	}
};

int main() {
	//������
	cout << "================" << endl;
	cout << "    �����̵�    " << endl;
	cout << "================" << endl;
	cout << "����� ������ �������Դϴ�. ��Ƴ��� ���ؼ� ������ �¼� �ο켼��" << endl;

	//�÷��̾�
	string playerName, job;

	cout << " ����� ĳ���� �̸��� �Է��ϼ���: ";
	cin >> playerName;
	cout << " ������ �����ϼ��� (1. ����, 2. ����2): ";
	cin >> job;

	battle();

	//���� �޴�
	while {
		cout << " =====�޴�â===== " << endl;
		cout << " 1. ���� ���� " << endl;
		cout << " 2. ���� " << endl;
		cout << " 3. ���� Ȯ�� " << endl;
		cout << " 0. ���� ���� " << endl;
		cout << " ����: ";

		int choice;
		cin >> choice;
	}

	if (choice == 1) {
		cout << "������ �����մϴ�." << endl;
	}
	else if (choice == 2) {
		cout << "������ ���� ���� ȯ���մϴ�." << endl;
	}
	else if (choice == 3) {
		player.printStatus();
	}
	else if (choice == 0) {
		cout << "������ �����մϴ�." << endl;
		break;
	}
	else {
		cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���." << endl;
	}
}


//����
if (playerHp > 0) {
	cout << "�����մϴ�, " << playerName << "��! ����� ������" << bossmonsterName << "��(��) ����ġ�� ������ �����ڰ� �Ǽ̽��ϴ�." << endl;
}
else {
	cout << "��Ÿ������" << playerName << "���� �������� �й��ϼ̽��ϴ�...." << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "������ �����ڴ� �������ϴ�." << endl;

}

return 0;
}