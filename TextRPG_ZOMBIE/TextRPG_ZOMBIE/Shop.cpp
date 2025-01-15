#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iomanip>
#include <iostream>
using namespace std;


Shop::Shop()
{
    for (int i = 0; i < Max; ++i) {
        Shop::itemList.emplace_back(static_cast<ItemType>(i));
    }
    // 아이템 리스트의 뒤에 계속 아이템 저장
    // 반복문의 int를 ItemType로 변경하여 ItemSetting 객체 생성 후 벡터에 저장
}

void Shop::displayItems(Character& character)
{
        

    cout << setw(30) << "물자 거래소" << endl;
    cout << "========================================================" << endl;
    cout << setw(4) << "번호";
    cout << setw(15) << "아이템";
    cout << setw(10) << "구매가격";
    cout << setw(10) << "판매가격" << endl;
    cout << "========================================================" << endl;

    for (const auto& item : itemList) {
        cout << setw(4) << item.getItemType();
        cout << setw(15) << item.getName();
        cout << setw(10) << item.getPrice();
        cout << setw(10) << item.getPrice() * 0.6;
        cout << endl;
    }
    
    cout << "========================================================" << endl;

    int shop_idx;
    cout << setw(10) << "1. 자원 구입   2. 자원 판매   3. 현재 자원" << endl;
    cout << " 점검 생존을 위해 선택하세요. : ";
    cin >> shop_idx;
    switch (shop_idx) {
    case 1:
        buyItem(character);
        break;
    case 2:
        sellItem(character);
        break;
    default:
        break;
        
    }
}

void Shop::buyItem(Character& character)
{
    int item_idx;
    int item_amount;
    cout << "구입을 원하는 자원 번호를 입력해주세요: ";
    cin >> item_idx;

    if (item_idx < 0)
    {
        cout << "해당 자원이 존재하지 않습니다." << endl;
        return;
    }

    cout << itemList[item_idx].getName() << "자원 구매 개수를 입력해주세요: ";
    cin >> item_amount;

    if (character.getMoney() > item_amount * itemList[item_idx].getPrice())
    {
        //character.addItem(itemList[item_idx].getName(), item_amount);
       //character.payMoney(itemList[item_idx].getPrice());
    }
    else
    {
        cout << "가진 돈 보다 많은 돈을 지불할 수 없습니다." << endl;
    }


    cout << itemList[item_idx].getName() << "자원을 "/* << character.getInventory(item_idx)*/ << "개 보유중입니다." << endl;


}
void Shop::sellItem(Character& character)
{
    int item_idx;
    int item_amount;
    cout << "판매를 원하는 자원 번호를 입력해주세요: ";
    cin >> item_idx;

    if (item_idx < 0)
    {
        cout << "해당 자원이 존재하지 않습니다." << endl;
        return;
    }

    if (/*character.getInventory(item_idx) > 0*/true)
    {
        cout << itemList[item_idx].getName() << "자원 판매 개수를 입력해주세요: ";
        cin >> item_amount;

        if (/*character.getInventory(item_idx) > item_amount*/true)
        {
            cout << "보유중인 자원보다 더 많은 자원을 판매할 수 없습니다." << endl;
            return;
        }

        character.gainMoney(itemList[item_idx].getPrice() * 0.6);
        // 인벤토리에서 삭제 추가
        cout << "남은 돈 : " << character.getMoney();
    }
    else
    {
        cout << "보유 하지 않은 아이템을 판매할 수 없습니다." << endl;
    }
    
}

Shop::~Shop()
{
    cout << "   물자 거래소가 종료되었습니다. " << endl;
    cout << "========================================================" << endl;
}