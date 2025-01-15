# 프로젝트 좀보이드

프로젝트 제작 기간 : 2025.1.9(목) ~ 2025.1.15(수)

## 프로젝트 소개

**프롤로그**

...

**좀보이드란?**

게임 흐름도 이미지 삽입

자동 전투 매커니즘을 가진 로그라이크 게임입니다.

캐릭터 생성을 하고 전투와 상점 방문을 반복하며 마지막 스테이지까지 살아남는 것이 목표입니다.

게임은 스테이지 별로 진행되며 전투 한번과 상점방문 한번이 하나의 스테이지입니다.

10스테이지로 구성되어 있으며 플레이어 레벨에 따라 다른 좀비가 랜덤하게 출몰합니다.

상점에는 각종 의약품, 전투에 도움되는 아이템들이 있으며, 현재 상황과 이어질 전투의 양상을 예측해 소지한 재화로 적절한 선택을 해야 합니다

10스테이지 까지 모두 끝나면 플레이어가 승리하게 되며, 그 이전에 사망하면 패배하게 됩니다.

## 프로젝트 목표

- 객체지향 프로그래밍
  - class 로 객체를 생성하는 것에 대한 이해와 상속을 통한 다형성, 서로 다른 class 끼리의 데이터 흐름을 파악하고 숙달한다.
- 협업
  - 작성한 class diagram 을 바탕으로 구현된 서로 다른 작업물을 하나로 합치며 의도된 결과물이 나오도록 숙달한다.
- 창의력
  - 필수과제와 도전과제에서 더 나아가 게임을 꾸미고, 재미를 더하고, 특별함을 추가하는 과정을 경험한다.

## 주요 컨텐츠
- 게임 플레이 및 UI
- 캐릭터 생성
- 좀비 생성
- 상점 이용
- 전투

## 주요 기능
- Actor class
<pre>```cpp  class Actor{  private:  string Name;  int AttackPower;  int HP;  int MaxHP;  public:  Actor();  Actor(string inputName, int inputAttackPower, int inputMaxHP);  virtual int Attack();  virtual void onHit(int inputAttackPower);  bool isDead();  void printStatus();  };```</pre>
- Character class
- Various Zombie class
- Item class
- Shop class
- GameMode class

## 프로젝트 로직
이미지 삽입

## 기술 기록
- Actor class 를 상속한 Character 와 zombie class
- Item class 를 Character, Zombie 와 Shop class 에서 사용하는 방법
- GameMode 로 게임의 흐름 제어

## 트러블 슈팅
...

## 기술 스택
- Programming Language
  - C++
- IDE
  - Visual studio
- Platform
  - Window console
- Version Control System
  - GitHub

## 관련 링크
- [팀 노션](https://teamsparta.notion.site/2-17-1762dc3ef514814d941de95c7f349bb4)
