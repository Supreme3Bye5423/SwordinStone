#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

class Events;
class BaseKnight;
class ArmyKnights;
class BaseItem;
class BaseOpponent;
class BaseBag;
class KnightAdventure;
class Paladin;
class Lancelot;
class Dragon;
class Normal;
class BaseOpponent;
class MadBear;
class Bandit;
class LordLupin;
class Elf;
class Troll;
class Tornbery;
class cardQueen;
class Antidote;
class PhoenixDI;
class PhoenixDII;
class PhoenixDIII;
class PhoenixDIV;
class Antidote;
class PhoenixDI;
class PhoenixDII;
class PhoenixDIII;
class PhoenixDIV;
class Ultimecia;

struct Item
{
    BaseItem *Stuff;
    Item *next;
};

enum ItemType {ANTIDOTE = 0, PHOENIXDI, PHOENIXDII, PHOENIXDIII, PHOENIXDIV};

class BaseBag {
public:
    struct Link_list
    {
        Item *First = nullptr;
        Item *Last = nullptr;
    };
    Link_list list;
    int maxInvent;
    int numofItem = 0;
    int antidote = 0;
    int PhoenixI = 0;
    int PhoenixII = 0;
    int PhoenixIII = 0;
    int PhoenixIV = 0;
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
    void addHead(ItemType ID, int maxIvent);
    bool canAdd(BaseItem *item);
    void item_to_Head(ItemType ID);
    void eraseItem();
    void firstAdd(ItemType ID);
};

class BaseOpponent
{
    public:
        int id;
        int gil;
        int baseDamage;
        int level0;
    public:
        int level0Calc(int eventRun, int eventID);
};

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight 
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    double baseDame;
    KnightType knightType;
    BaseBag * bag;
public:
    int countItem = 0;
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    int returnLevel();
    int returnid();
    int returnhp();
    int returnmaxhp();
    int returngil();
    int returnantidote();
    int returnphoenixdownI();
    double returnbaseDame();
    BaseBag *returnBag();
    void addGil(int gilAdd);
    KnightType returnType();
    void firstAdd();
    void useotPhoenix(BaseKnight *lastKnight);
    void changeHP(int HP);
    void changeLevel(int level);
    void changeGil(int gil);
    bool revKnight();
};

class ArmyKnights 
{
public:
    int numberofKnight;
    BaseKnight ** Knight;
    bool PaladinShield = false;
    bool LancelotSpear = false;
    bool GuinevereHair = false;
    bool ExcaliburSword = false;
    int meetOmega = 0;
    int meetHades = 0;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
    void killastKnight();
    void Fight1to5(BaseOpponent *opponent);
    void FightTornbery(BaseOpponent *opponent);
    void FightQueen(BaseOpponent *opponent);
    void meetNina();
    bool fightOmega(BaseOpponent *opponent);
    bool fightHades(BaseOpponent *opponent);
    void fightUltimecia(Ultimecia *opponent);
    void killKnightindex(int index);
    void addPhoenixII();
    void addPhoenixIII();
    void addPhoenixIV();
};
class BaseItem {
    public:
        ItemType itemID;
    public:
         virtual bool canUse ( BaseKnight * knight ) = 0;
         virtual void use ( BaseKnight * knight ) = 0;
};

class Events {
public:
    int num_of_events;
    int * events;
    int eventNow = 0;
public:
    Events(const string & file_Events);
    void Durian(ArmyKnights *armyKnights);
    ~Events();
    int count() const;
    int get(int i) const;
};

class KnightAdventure 
{
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:
    void loadArmyKnights(const string & file_ArmyKnights);
    void loadEvents(const string & file_Events);
    void run();
};

//Different type of Knight

class Paladin:public BaseKnight
{
    public:
        Paladin(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Paladin();
};

class Lancelot:public BaseKnight
{
    public:
        Lancelot(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Lancelot();
};

class Dragon:public BaseKnight
{
    public:
        Dragon(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Dragon();
};

class Normal:public BaseKnight
{
    public:
        Normal(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Normal();
};

//Different type of opponent

class MadBear:public BaseOpponent
{
    public:
        MadBear(int level0);
};

class Bandit:public BaseOpponent
{
    public:
        Bandit(int level0);
};

class LordLupin:public BaseOpponent
{
    public:
        LordLupin(int level0);
};

class Elf:public BaseOpponent
{
    public:
        Elf(int level0);
};

class Troll:public BaseOpponent
{
    public:
        Troll(int level0);
};

class Tornbery:public BaseOpponent
{
    public:
        Tornbery(int level0);
        void Curse(BaseKnight *lastKnight);
};

class cardQueen:public BaseOpponent
{
    public:
        cardQueen(int level0);
};

class Omega:public BaseOpponent
{
    public:
        Omega();
};

class Hades:public BaseOpponent
{
    public:
        Hades();
};

class Ultimecia:public BaseOpponent
{
    public:
        int hp;
    public:
        Ultimecia();
};

//Different type of potion
class Antidote : public BaseItem
{
    public:
    Antidote();
        bool canUse ( BaseKnight * knight );
        void use ( BaseKnight * knight );
};

class PhoenixDI:public BaseItem
{
    public:
        PhoenixDI();
         bool canUse ( BaseKnight * knight );
         void use ( BaseKnight * knight );
};

class PhoenixDII:public BaseItem
{
    public:
         bool canUse ( BaseKnight * knight );
         void use ( BaseKnight * knight );
         PhoenixDII();
};

class PhoenixDIII:public BaseItem
{
    public:
         bool canUse ( BaseKnight * knight );
         void use ( BaseKnight * knight );
         PhoenixDIII();
};

class PhoenixDIV:public BaseItem
{
    public:
         bool canUse ( BaseKnight * knight );
         void use ( BaseKnight * knight );
         PhoenixDIV();
};

#endif // __KNIGHT2_H__