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
    cout << "           상   점           " << endl;
    displayItems();
    cout << "1.구매   2. 판매   3. 보유물품" << endl;
    cout << "어떤 서비스를 이용하시겠습니가? : ";
    cin >> shop_idx;
    switch (shop_idx)
        case 1:
            buyItem();
}

void Shop::displayItems(/*Character& character*/)
{
    // All_Item 변수에 대한 get함수, set(Currnetstack만) 추가
    cout << setw(15) << "아이템"
        << setw(10) << "구매 가격"
        << setw(10) << "판매 가격"
        << setw(15) << "현재 보유"
        << setw(15) << "최대 보유" << endl;
    cout << "------------------------------------------------------------" << endl;
    /*
    for (int i = 0; i < inventory.; ++i) {
        //All_Item* item = character.OwnedItems[i]; // 캐릭터의 아이템 접근
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
    cout << "   상점이 종료되었습니다. " << endl;
    cout << "------------------------------------------------------------" << endl;
}