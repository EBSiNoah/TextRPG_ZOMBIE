#include "MonsterDropItem.h"

void MonsterDropItem::dropItem(Character* chara)
{
    int droptable = RandomUtil::GetRandomInt(0, 100);
    int dropcheck = RandomUtil::GetRandomInt(0, 100);

    // 필수 구현과제: 30% 확률로 아이템 드랍
    // 30% 확률로 droptable에서 전리품 획득 유무 결정
    // 이후 각 아이템 드랍 확률
    // 모르핀 : 25%
    // 에피네프린 : 25%
    // 백신 : 20%
    // 메스암페타민 : 10%
    // 펜타닐 : 10%
    // 레비탈 : 10%
    chara->gainExp(chara->getLevel() * 50);
    if (droptable <= 30)
    {
        if (dropcheck <= 25)
        {
            // 모르핀 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Morphine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Morphine), count + 1);
            cout << "전리품으로 '모르핀'을 얻었습니다!" << endl;
        }
        else if (dropcheck <= 50)
        {
            // 에피네프린 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Epinephrine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Epinephrine), count + 1);
            cout << "전리품으로 '에피네프린'을 얻었습니다!" << endl;
        }
        else if (dropcheck <= 70)
        {
            // 백신 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Vaccine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Vaccine), count + 1);
            cout << "전리품으로 '에피네프린'을 얻었습니다!" << endl;
        }
        else if (dropcheck <= 80)
        {
            // 메스암페타민 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Methylamphetamine)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Methylamphetamine), count + 1);
            cout << "전리품으로 '메스암페타민'을 얻었습니다!" << endl;
        }
        else if (dropcheck <= 90)
        {
            // 펜타닐 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Fentanyl)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Fentanyl), count + 1);
            cout << "전리품으로 '펜타닐'을 얻었습니다!" << endl;
        }
        else if (dropcheck <= 100)
        {
            // 레비탈 드랍
            int count = 0;
            vector<pair<const int, const int>> inv = chara->getInventory();
            for (const auto& p : inv)
            {
                if (p.first == static_cast<int>(Revital)) 
                {
                    count = p.second;
                    break;
                }
            }
            chara->setInventory(static_cast<int>(Revital), count + 1);
            cout << "전리품으로 '레비탈'을 얻었습니다!" << endl;
        }
    }

}