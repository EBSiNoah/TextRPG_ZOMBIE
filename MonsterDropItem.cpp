#include "MonsterDropItem.h"

void MonsterDropItem::dropItem(Inventory* Inven)
{
    int droptable = RandomUtil::GetRandomInt(0, 100);
   
    // 예시 드랍 테이블:
    // 0 ~ 30: Morphine  
    // 31 ~ 50: Epinephrine  
    // 51 ~ 60: Methylamphetamine  
    // 61 ~ 70: Fentanyl  
    // 71 ~ 75: Revital  
    // 76 ~ 100: 아무것도 드롭하지 않음

    if (droptable <= 30)
    {
        // 모르핀 드랍
        Inven->item[Morphine].setCurrentStack(Inven->item[Morphine].getCurrentStack() + 1);
        cout << "몬스터가 '모르핀'을 드롭했습니다!" << endl;
    }
    else if (droptable <= 50)
    {
        // 에피네프린 드랍
        Inven->item[Epinephrine].setCurrentStack(Inven->item[Epinephrine].getCurrentStack() + 1);
        cout << "몬스터가 '에피네프린'을 드롭했습니다!" << endl;
    }
    else if (droptable <= 60)
    {
        // 메스암페타민 드랍
        Inven->item[Methylamphetamine].setCurrentStack(Inven->item[Methylamphetamine].getCurrentStack() + 1);
        cout << "몬스터가 '메스암페타민'을 드롭했습니다!" << endl;
    }
    else if (droptable <= 70)
    {
        // 펜타닐 드랍
        Inven->item[Fentanyl].setCurrentStack(Inven->item[Fentanyl].getCurrentStack() + 1);
        cout << "몬스터가 '펜타닐'을 드롭했습니다!" << endl;
    }
    else if (droptable <= 75)
    {
        // 레비탈 드랍
        Inven->item[Revital].setCurrentStack(Inven->item[Revital].getCurrentStack() + 1);
        cout << "몬스터가 '레비탈'을 드롭했습니다!" << endl;
    }
}