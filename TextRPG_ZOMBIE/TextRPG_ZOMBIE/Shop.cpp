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
    cout << "구입을 원하는 자원 번호를 입력해주세요(취소: -1): ";
    string num; cin >> num;
    int item_idx = validateInput(num, 0, itemList.size() - 1);
    if (item_idx == -1)
    {
        return;
    }

    cout << "현재 보유 금액 : " << character.getMoney() << "  ||  " << itemList[item_idx].getName() << "자원 구매 개수를 입력해주세요 : ";
    cin >> num;
    int item_amount = validateInput(num, 1, 100);
    if (item_amount == -1) {
        return;
    }
    if (character.getMoney() >= item_amount * itemList[item_idx].getPrice())
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
    string num;
    cout << "판매를 원하는 자원 번호를 입력해주세요: ";
    cin >> num;

    int item_idx = validateInput(num, 0, itemList.size() - 1);
    if (item_idx == -1) {
        return;
    }

    if (character.getInventory()[item_idx].second > 0)
    {
        cout << "현재 " << itemList[item_idx].getName() << " 보유 개수: "
            << character.getInventory()[item_idx].second
            << " || 자원 판매 개수를 입력해주세요: ";
        cin >> num;

        int item_amount = validateInput(num, 1, character.getInventory()[item_idx].second);
        if (item_amount == -1) {
            return;
        }

        character.gainMoney(itemList[item_idx].getPrice() * 0.6 * item_amount);
        character.deleteItem(item_idx, item_amount);
        cout << "남은 돈 : " << character.getMoney();
        Sleep(1000);
        system("cls");
    }
}

int Shop::validateInput(const string& input, int min, int max) {
    try {
        if (input.empty() ||
            (!std::all_of(input.begin(), input.end(), ::isdigit) &&
                !(input[0] == '-' && input.size() > 1 && std::all_of(input.begin() + 1, input.end(), ::isdigit))))
        {
            throw invalid_argument("잘못된 입력입니다. 숫자를 입력해주세요.");
        }

        if (input.length() > 10) {
            throw out_of_range("입력값이 너무 큽니다.");
        }

        int value = stoi(input);

        if (value < min) {
            throw out_of_range("음수나 0은 입력할 수 없습니다.");
        }
        if (value > max) {
            throw out_of_range("값을 확인해 주세요.");
        }

        return value; 
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
        Sleep(1000);
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
        Sleep(1000);
    }
    return -1;
}

Shop::~Shop()
{
    //cout << setw(10) << "물자 거래소가 종료되었습니다. " << endl;
    //cout << "========================================================" << endl;

}