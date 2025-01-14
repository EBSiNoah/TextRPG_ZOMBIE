#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iomanip>
#include <iostream>
using namespace std;

Shop::Shop(Character* character) : character(character)
{
}

void Shop::displayMenu() {
    int shop_idx;
    cout << "============================" << endl;
    cout << "          ��   ��           " << endl;
    displayItems();
    cout << "1. ����   2. �Ǹ�   3. ���� ��ǰ" << endl;
    cout << "� ���񽺸� �̿��Ͻðڽ��ϱ�? : ";
    cin >> shop_idx;
    switch (shop_idx) {
    case 1:
        buyItem();
        break;
    case 2:
        sellItem();
        break;
    }
    default:
        cout << "��ġ�ϴ� ��ȣ�� �����ϴ�." << endl;
    }
        

}

void Shop::displayItems()
{

   //..Items& item = Inventory.item; 

    cout << setw(4) << "��ȣ";
    cout << setw(15) << "������";
    cout << setw(10) << "���� ����";
    cout << setw(10) << "�Ǹ� ����";
    cout << setw(15) << "���� ����"; 
    cout << setw(15) << "�ִ� ����" << endl;
    cout << "============================" << endl;

    for (int i = 0; i < ItemType::Max; ++i) {
        // ������ ���ٹ���� �˰ԵǸ� �����ϰڽ��ϴ�
        //cout << setw(15) << Inventory::item[i].getName();
         //cout << setw(10) << item[i].getPrice();
         //cout << setw(10) << Inventory::item[i]->getPrice() * 0.6;
        // cout << setw(15) << item[i]->getCurrentStack();
         //cout << setw(15) << Inventory::item->getMaxStack() << endl;

    }
    
    cout << "============================" << endl;
}

void Shop::buyItem()
{
    int item_idx;
    int item_amount;
    cout << "���Ÿ� ���ϴ� ������ ��ȣ�� �Է����ּ���: ";
    cin >> item_idx;

    if (item_idx < 0/* || item_idx>ItemList::Max*/)
    {
        cout << "�ش� �������� �������� �ʽ��ϴ�." << endl;
        return;
    }

    //cout << item->getMaxStack() << "������ ���� ������ �Է����ּ���: ";
    cin >> item_amount;

    if (item_amount <= 0 /*|| item_amount > item->getMaxStack() - item->getCurrentStack()*/)
    {
        cout << "�����Ϸ��� ������ �ִ� ���� ������ �ʰ��մϴ�." << endl;
        return;
    }

    //item[item_idx].CurrentStack++;
    //character->payMoney(getPrice());


}
void Shop::sellItem()
{
    int item_idx;
    int item_amount;
    cout << "�ǸŸ� ���ϴ� ������ ��ȣ�� �Է����ּ���: ";
    cin >> item_idx;

    if (item_idx < 0 /* || item_idx>ItemList::Max*/)
    {
        cout << "�ش� �������� �������� �ʽ��ϴ�." << endl;
        return;
    }

    //cout << item->getMaxStack() << "������ �Ǹ� ������ �Է����ּ���: ";
    cin >> item_amount;

    if (item_amount <= 0 /*|| item_amount > item->getCurrentStack()*/)
    {
        cout << "�Ǹ��Ϸ��� ������ ���� ������ ������ �ʰ��մϴ�." << endl;
        return;
    }

    //item[item_idx].CurrentStack--;
    //character->gainMoney(getPrice()*0.6);
}

Shop::~Shop()
{
    cout << "   ������ ����Ǿ����ϴ�. " << endl;
    cout << "============================" << endl;
    character = nullptr;
}