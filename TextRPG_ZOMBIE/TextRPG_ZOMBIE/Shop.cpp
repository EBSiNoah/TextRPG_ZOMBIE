#include "Shop.h"
// #include "Character.h"
// #include "Itme.h"
#include <iomanip>
#include <iostream>
using namespace std;

Shop::Shop()
{
    int shop_idx;
    cout << "------------------------------------------------------------" << endl;
    cout << "           ��   ��           " << endl;
    displayItems();
    cout << "1.����   2. �Ǹ�   3. ������ǰ" << endl;
    cout << "� ���񽺸� �̿��Ͻðڽ��ϰ�? : ";
    cin >> shop_idx;
    switch (shop_idx)
        case 1:
            buyItem();
}

void Shop::displayItems(/*Character& character*/)
{
    // All_Item ������ ���� get�Լ�, set(Currnetstack��) �߰�
    cout << setw(15) << "������"
        << setw(10) << "���� ����"
        << setw(10) << "�Ǹ� ����"
        << setw(15) << "���� ����"
        << setw(15) << "�ִ� ����" << endl;
    cout << "------------------------------------------------------------" << endl;
    /*
    for (int i = 0; i < inventory.; ++i) {
        //All_Item* item = character.OwnedItems[i]; // ĳ������ ������ ����
        cout << setw(15) << item->getName()
            << setw(10) << item->getPrice()
            << setw(10) << item->getPrice() * 0.6
            << setw(15) << item->getCurrentStack()
            << setw(15) << item->getMaxStack() << endl;

    }
    */
    cout << "------------------------------------------------------------" << endl;
}

void Shop::buyItem()
{

}
void Shop::sellItem()
{

}

Shop::~Shop()
{
    cout << "   ������ ����Ǿ����ϴ�. " << endl;
    cout << "------------------------------------------------------------" << endl;
}