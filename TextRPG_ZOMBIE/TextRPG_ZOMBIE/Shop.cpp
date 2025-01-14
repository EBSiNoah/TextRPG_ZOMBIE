#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iomanip>
#include <iostream>
using namespace std;

Shop::Shop(Character* character) : character(character)
{
    int shop_idx;
    cout << "============================" << endl;
    cout << "          상   점           " << endl;
    displayItems();
    cout << "     1. 구매   2. 판매  "<< endl;
    cout << "어떤 서비스를 이용하시겠습니가? : ";
    cin >> shop_idx;
    switch (shop_idx) 
    {
    case 1:
        buyItem();
        break;
    case 2:
        sellItem();
        break;
    default:
        cout << "일치하는 번호가 없습니다." << endl;
    }
        

}

void Shop::displayItems()
{

   //..Items& item = Inventory.item; 

    cout << setw(4) << "번호";
    cout << setw(15) << "아이템";
    cout << setw(10) << "구매 가격";
    cout << setw(10) << "판매 가격";
    cout << setw(15) << "현재 보유"; 
    cout << setw(15) << "최대 보유" << endl;
    cout << "============================" << endl;

    for (int i = 0; i < ItemType::Max; ++i) {
        // 아이템 접근방법을 알게되면 수정하겠습니다
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
void Shop::sellItem()
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
    character = nullptr;
}