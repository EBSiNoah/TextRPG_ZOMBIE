#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iomanip>
#include <iostream>
using namespace std;

Shop::Shop()
{
    
}
/*
void Shop::displayMenu(character) {
    int shop_idx;
    cout << "========================================================" << endl;
    cout << setw(20)<<"상   점" << endl;
    displayItems();
    cout << setw(10)<<"1. 구매   2. 판매   3. 보유 물품" << endl; //다른이름으로 저장->인코딩하여저장->utf
    cout << " : ";
    cin >> shop_idx;
    switch (shop_idx) {
    case 1:
        buyItem();
        break;
    case 2:
        sellItem();
        break;
    case 3:
        displayItems();
        break;
    }
}
*/

void Shop::displayItems(Character& character)
{
    cout << setw(20) << "상   점" << endl;
    cout << "========================================================" << endl;
    cout << setw(4) << "번호";
    cout << setw(15) << "아이템";
    cout << setw(10) << "구매가격";
    cout << setw(10) << "판매가격";
    cout << setw(15) << "보유수"; 
    cout << "========================================================" << endl;

    for (int i = 0; i < ItemType::Max; ++i) {
        cout << setw(15) << i;
        //cout << setw(10) << ;
        //cout << setw(10) <<  * 0.6;
        //cout << setw(15) << ;
        //cout << setw(15) << << endl;
        cout << "*" << endl;

    }
    
    cout << "========================================================" << endl;

    int shop_idx;
    cout << setw(10) << "1. 구매   2. 판매   3. 보유 물품" << endl;
    cout << " : ";
    cin >> shop_idx;
    switch (shop_idx) {
    case 1:
        buyItem(character);
        break;
    case 2:
        sellItem(character);
        break;
    }
}

void Shop::buyItem(Character& character) //캐릭터 레퍼런스 받기, 아이템
{
    int item_idx;
    int item_amount;
    cout << "구매를 원하는 아이템 번호를 입력해주세요: ";
    cin >> item_idx;

    if (item_idx < 0/* || item_idx>ItemList::Max*/)
    {
        cout << "해당 아이템이 존재하지 않습니다." << endl;
        return;
    }

    //cout << item->getMaxStack() << "아이템 구매 개수를 입력해주세요: ";
    cin >> item_amount;

    if (item_amount <= 0 /*|| item_amount > item->getMaxStack() - item->getCurrentStack()*/)
    {
        cout << "구매하려는 개수가 최대 구매 개수를 초과합니다." << endl;
        return;
    }

    //item[item_idx].CurrentStack++;
    //character->payMoney(getPrice());


}
void Shop::sellItem(Character& character)
{
    int item_idx;
    int item_amount;
    cout << "판매를 원하는 아이템 번호를 입력해주세요: ";
    cin >> item_idx;

    if (item_idx < 0 /* || item_idx>ItemList::Max*/)
    {
        cout << "해당 아이템이 존재하지 않습니다." << endl;
        return;
    }

    //cout << item->getMaxStack() << "아이템 판매 개수를 입력해주세요: ";
    cin >> item_amount;

    if (item_amount <= 0 /*|| item_amount > item->getCurrentStack()*/)
    {
        cout << "판매하려는 개수가 보유 아이템 개수를 초과합니다." << endl;
        return;
    }

    //item[item_idx].CurrentStack--;
    //character->gainMoney(getPrice()*0.6);
}

Shop::~Shop()
{
    cout << "   상점이 종료되었습니다. " << endl;
    cout << "============================" << endl;
    //character = nullptr;
}