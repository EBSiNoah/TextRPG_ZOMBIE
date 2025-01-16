#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>
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
    string shop_idx = "";
    while (shop_idx != "3") {
        cout << setw(35) << "물자 거래소";
        cout << "                  보유 골드 : " << character.getMoney() << endl;
        cout << "============================================================================================" << endl;
        cout << setw(10) << "번호";
        cout << setw(15) << "아이템";
        cout << setw(10) << "구매가격";
        cout << setw(10) << "판매가격";
        cout << setw(10) << "보유개수";
        cout << setw(10) << "     아이템효과" << endl;
        cout << "============================================================================================" << endl;

        for (int i = 0; i < ItemType::Max; ++i) {
            cout << setw(10) << itemList[i].getItemType();
            cout << setw(15) << itemList[i].getName();
            cout << setw(10) << itemList[i].getPrice();
            cout << setw(10) << itemList[i].getPrice() * 0.6;
            cout << setw(10) << character.getInventory()[i].second;
            cout << "     " << itemList[i].getExplain();
            cout << endl;
        }
        cout << "============================================================================================" << endl;
        cout << setw(10) << "1. 자원 구입   2. 자원 판매  3. 메뉴로 돌아가기" << endl;
        cout << " 점검 생존을 위해 선택하세요. : ";
        cin >> shop_idx;

        if (shop_idx == "1")
        {
            buyItem(character);
            system("cls");
        }
        else if (shop_idx == "2")
        {
            sellItem(character);
            system("cls");
        }
        else if (shop_idx == "3")
        {
            cout << "메뉴로 돌아갑니다..." << endl;
            Sleep(1000); 
            system("cls");
            break; 
        }
        else
        {
            cout << "잘못 입력 하셨습니다.";
            Sleep(1000);
            system("cls");
        }
    }

}

void Shop::buyItem(Character& character)
{
    int item_idx;
    int item_amount;
    cout << "구입을 원하는 자원 번호를 입력해주세요(취소: -1): ";
    cin >> item_idx;

    if (item_idx == -1)
    {
        return;
    }
    else if (item_idx < 0 || item_idx >= itemList.size())
    {
        cout << "아이템 목록에 있는 아이템만 구매할 수 있습니다." << endl;
        return;
    }

    cout << "현재 보유 금액 : " << character.getMoney() << "  ||  " << itemList[item_idx].getName() << "자원 구매 개수를 입력해주세요 : ";
    cin >> item_amount;

    if (item_amount == 0)
    {
        return;
    }
    else if (character.getMoney() >= item_amount * itemList[item_idx].getPrice())
    {
        if (itemList[item_idx].getUseType() == 0)
        {
            character.payMoney(itemList[item_idx].getPrice() * item_amount);
            character.addItem(item_idx, item_amount);
            ItemSetting item(static_cast<ItemType>(item_idx));
            for (int i = 0; i < item_amount; i++) {
                item.use(&character);
            }
            cout << "아이템을 사용했습니다! " << "(" << itemList[item_idx].getExplain() << ")" << endl;
            Sleep(3000);
        }
        else
        {
            character.addItem(item_idx, item_amount);
            character.payMoney(itemList[item_idx].getPrice() * item_amount);
            cout << "보유 중인 " << itemList[item_idx].getName() << " : " << character.getInventory()[item_idx].second
                << " || 남은 돈 : " << character.getMoney() << endl;
            Sleep(2000);
        }

    }
    else
    {
        cout << "가진 돈 보다 많은 돈을 지불할 수 없습니다." << endl;
        Sleep(1000);
    }
    system("cls");

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
        Sleep(1000);
        return;
    }

    if (character.getInventory()[item_idx].second > 0)
    {
        cout << "현재" << itemList[item_idx].getName() << " 보유 개수 : " << character.getInventory()[item_idx].second << " || 자원 판매 개수를 입력해주세요 : ";
        cin >> item_amount;

        if (character.getInventory()[item_idx].second < item_amount)
        {
            cout << "보유중인 자원보다 더 많은 자원을 판매할 수 없습니다." << endl;
            Sleep(1000);
            return;
        }

        character.gainMoney(itemList[item_idx].getPrice() * 0.6 * item_amount);
        character.deleteItem(item_idx, item_amount);
        cout << "남은 돈 : " << character.getMoney();
        Sleep(1000);
    }
    else
    {
        cout << "보유 하지 않은 아이템을 판매할 수 없습니다." << endl;
        Sleep(1000);
    }
    system("cls");
}

Shop::~Shop()
{
    //cout << setw(10) << "물자 거래소가 종료되었습니다. " << endl;
    //cout << "========================================================" << endl;

}