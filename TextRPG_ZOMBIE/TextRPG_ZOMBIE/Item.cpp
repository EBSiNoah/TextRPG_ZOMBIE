#include "Item.h"
#include "Character.h"

// 생성자 구현 (초기화 값을 넣거나, 기본값 설정)
ItemSetting::ItemSetting(ItemType type)
    : Name(""), itemtype(type), Price(0)
{
    switch (itemtype)
    {
    case Morphine:
        Name = "모르핀";
        Price = 50;
        break;

    case Epinephrine:
        Name = "에피네프린";
        Price = 60;
        break;

    case Methylamphetamine:
        Name = "메스암페타민";
        Price = 70;
        break;

    case Fentanyl:
        Name = "펜타닐";
        Price = 80;
        break;

    case Revital:
        Name = "레비탈";
        Price = 100;
        break;

    case WoodenSword:
        Name = "목검";
        Price = 75;
        break;

    case Shield:
        Name = "일회용 방패";
        Price = 70;
        break;

    case Vaccine:
        Name = "바이러스 백신";
        Price = 50;
        break;
    }
}

void ItemSetting::use(Character* chara)
{
    //CurrentStack을 캐릭터 인벤토리의 소지갯수로 변경
    //if (CurrentStack < 1)
        //return;
    // 아이템 사용 후 감소
    //--CurrentStack;

    switch (itemtype)
    {
    case Morphine:
        cout << "체력 50 회복!";
        chara->HP += 50;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Epinephrine:
        cout << "공격력 10 증가!";
        chara->AttackPower += 10;
        break;

    case Methylamphetamine:
        cout << "공격력 50 증가!";
        chara->AttackPower += 50;
        break;

        // 체력 30 이하일때 펜타닐 복용 예외처리
    case Fentanyl:
        cout << "최대 체력 30 감소, 체력 5000 회복!";
        chara->MaxHP -= 30;
        chara->HP += 5000;
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Revital:
        cout << "최대 체력 80 증가!";
        chara->MaxHP += 80;
        chara->HP += 80;
        break;

    case WoodenSword:
        // 목검 효과: boostedTurns를 3으로 설정 (3턴 동안 효과)
        if (chara->getBoostedTurns() == 0) 
        {
            chara->setBoostedTurns(3);
            cout << "3턴 동안 공격력이 2배로 증가합니다!" << endl;
        }
        break;

    case Shield:

        break;

    case Vaccine:
        if (chara->getCondition() == "건강") 
        {
            cout << "감염 상태가 아닙니다." << endl;
        }
        else if (chara->getCondition() == "감염") 
        {
            chara->setCondition("건강");
            cout << "감염 상태가 회복되었습니다!" << endl;
        }
        break;
    }
}