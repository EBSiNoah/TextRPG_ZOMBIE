#include "Item.h"
#include "Character.h"

// 생성자 구현 (초기화 값을 넣거나, 기본값 설정)
ItemSetting::ItemSetting(ItemType type)
    : Name(""), itemtype(type), Price(0), Explain(""), UseType(0)
{
    switch (itemtype)
    {
    case Morphine:
        Name = "모르핀";
<<<<<<< HEAD
        Price = 80;
        Explain = "체력 +150";
=======
        Price = 50;
        Explain = "체력 +50";
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        UseType = 1;
        break;

    case Epinephrine:
        Name = "에피네프린";
<<<<<<< HEAD
        Price = 110;
=======
        Price = 60;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        Explain = "공격력 +10";
        UseType = 0;
        break;

    case Methylamphetamine:
        Name = "메스암페타민";
<<<<<<< HEAD
        Price = 300;
        Explain = "공격력 +32";
=======
        Price = 70;
        Explain = "공격력 +50";
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        UseType = 0;
        break;

    case Fentanyl:
        Name = "펜타닐";
<<<<<<< HEAD
        Price = 150;
        Explain = "최대 체력 -80, 체력 +5000(약물 오용 주의)";
=======
        Price = 80;
        Explain = "최대 체력 -30, 체력 +5000(약물 오용 주의)";
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        UseType = 1;
        break;

    case Revital:
        Name = "레비탈";
<<<<<<< HEAD
        Price = 500;
        Explain = "최대 체력 +300";
=======
        Price = 100;
        Explain = "최대 체력 +80";
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        UseType = 0;
        break;

    case WoodenSword:
        Name = "목검";
<<<<<<< HEAD
        Price = 155;
=======
        Price = 75;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        Explain = "3턴 동안 공격력 2배";
        UseType = 1;
        break;

    case Shield:
        Name = "일회용 방패";
<<<<<<< HEAD
        Price = 240;
=======
        Price = 70;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        Explain = "피해 방어(1회용)";
        UseType = 0;
        break;

    case Vaccine:
        Name = "바이러스 백신";
<<<<<<< HEAD
        Price = 80;
=======
        Price = 50;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        Explain = "감염 상태 회복";
        UseType = 1;
        break;
    }
}

void ItemSetting::use(Character* chara)
{
    int key = static_cast<int>(itemtype);

    // 캐릭터 인벤토리
    vector<pair<const int, const int>> inv = chara->getInventory();

    // 아이템의 현재 소지 개수 체크
    int count = 0;
    bool found = false;
    for (const auto& p : inv)
    {
        if (p.first == key)
        {
            count = p.second;
            found = true;
            break;
        }
    }

    // 아이템이 없거나 수량이 0일경우 종료
    if (!found || count < 1)
        return;

    // 아이템 사용시 갯수 -1
    chara->setInventory(key, count - 1);

    switch (itemtype)
    {
    case Morphine:
<<<<<<< HEAD
        cout << "체력 150 회복!";
        chara->HP += 150;
=======
        cout << "체력 50 회복!";
        chara->HP += 50;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        if (chara->HP > chara->MaxHP)
            chara->HP = chara->MaxHP;
        break;

    case Epinephrine:
        cout << "공격력 10 증가!";
        chara->AttackPower += 10;
        break;

    case Methylamphetamine:
<<<<<<< HEAD
        cout << "공격력 32 증가!";
        chara->AttackPower += 32;
=======
        cout << "공격력 50 증가!";
        chara->AttackPower += 50;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        break;

    case Fentanyl:
        if (chara->MaxHP < 81)
        {
<<<<<<< HEAD
            // 최대 체력이 80이하라면 최대 체력을 1로 만듭니다.
=======
            // 최대 체력이 30이하라면 최대 체력을 1로 만듭니다.
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
            chara->MaxHP = 1;
            cout << "약물 오용으로 최대 체력이 1이 되었습니다." << endl;
            chara->HP += 5000;
            if (chara->HP > chara->MaxHP)
                chara->HP = chara->MaxHP;
        }
        else
        {
<<<<<<< HEAD
            cout << "최대 체력 80 감소, 체력 5000 회복!" << endl;
            chara->MaxHP -= 80;
=======
            cout << "최대 체력 30 감소, 체력 5000 회복!" << endl;
            chara->MaxHP -= 30;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
            chara->HP += 5000;
            if (chara->HP > chara->MaxHP)
                chara->HP = chara->MaxHP;
        }
        break;

    case Revital:
<<<<<<< HEAD
        cout << "최대 체력 300 증가!";
        chara->MaxHP += 300;
        chara->HP += 300;
=======
        cout << "최대 체력 80 증가!";
        chara->MaxHP += 80;
        chara->HP += 80;
>>>>>>> b3c63030d30d158ca10ff1b6014214d9f240a7bb
        break;

    case WoodenSword:
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


bool ItemSetting::ShieldCheck(Character* chara, int inputAttackPower)
{
    // 캐릭터 인벤토리 가져오기
    auto inventory = chara->getInventory();

    // 일회용 방패를 찾는다
    // (enum 값이 Shield 이고, inventory에서는 <itemIndex, amount> 형태)
    // Shield의 enum 값이 6 이므로 (ItemType::Shield)
    int shieldKey = static_cast<int>(ItemType::Shield);

    // 방패가 1개 이상 있는지 확인
    for (auto& item : inventory)
    {
        if (item.first == shieldKey && item.second > 0)
        {
            // 현재 체력과 공격력을 비교
            if (chara->getHP() <= inputAttackPower)
            {
                // 방패 사용 => 개수 -1
                chara->setInventory(shieldKey, item.second - 1);

                // 방패 사용 시 피해 무효화
                cout << chara->Name << "이(가) 일회용 방패를 사용하여 피해를 방어했습니다!" << endl;
                return true;
            }
            break;
        }
    }
    // 방패를 사용할 상황이 아니면 false
    return false;
}