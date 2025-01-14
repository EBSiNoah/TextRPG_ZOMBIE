#include "Item.h"

// 생성자 구현 (초기화 값을 넣거나, 기본값 설정)
Items::Items(ItemType type)
    : Name(""), itemtype(type), Price(0), CurrentStack(0), MaxStack(0)
{
    switch (itemtype)
    {
    case Morphine:
        Name = "모르핀";
        Price = 50;
        MaxStack = 5;
        break;

    case Epinephrine:
        Name = "에피네프린";
        Price = 60;
        MaxStack = 1;
        break;

    case Methylamphetamine:
        Name = "메스암페타민";
        Price = 70;
        MaxStack = 1;
        break;

    case Fentanyl:
        Name = "펜타닐";
        Price = 80;
        MaxStack = 2;
        break;

    case Revital:
        Name = "레비탈";
        Price = 100;
        MaxStack = 1;
        break;
    }
}

void Items::use(Character* chara)
{
    if (CurrentStack < 1)
        return;
    // 아이템 사용 후 감소
    --CurrentStack;

    switch (itemtype)
    {
    case Morphine:
        cout << "사용: 모르핀, 체력 50 회복.";
        chara->HP += 50;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Epinephrine:
        cout << "사용: 에피네프린, 공격력 10 증가.";
        chara->AttackPower += 10;
        break;

    case Methylamphetamine:
        cout << "사용: 메스암페타민, 공격력 50 증가.";
        chara->AttackPower += 50;
        break;

        // 체력 30 이하일때 펜타닐 복용 예외처리
    case Fentanyl:
        cout << "사용: 펜타닐, 최대 체력 30 감소, 체력 5000 회복";
        chara->MaxHP -= 30;
        chara->HP += 5000;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Revital:
        cout << "사용: 레비탈, 최대 체력 80 증가";
        chara->MaxHP += 80;
        chara->HP += 80;
        break;
    }
}