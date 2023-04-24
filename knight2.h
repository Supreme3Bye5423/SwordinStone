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

enum ItemType {/* TODO: */};

class BaseBag {
    public:

        struct Item
        {
            BaseItem *Stuff;
            Item *next;
        };

        struct Link_list
        {
            Item *First = nullptr;
            Item *Last = nullptr;
        };
    public:
        virtual bool insertFirst(BaseItem * item);
        virtual BaseItem * get(ItemType itemType);
        virtual string toString() const;
        void bagCreate(Link_list & list);
};

class BaseOpponent
{
    public:
        int id;
        int gil;
        int baseDamage;
        int level0;
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
    BaseBag * bag;
    KnightType knightType;
    int maxInvent;
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
    int returnMaxinvent();
    void addGil(int gilAdd);
    KnightType returnType();

    void changeStat(int id, int hp, int level, int gil, int antidote, int phoenixdownI);
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
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent, ArmyKnights *armyKnights);
    bool adventure (Events * events, int run);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};
enum itemID {ANTIDOTE = 0, PHOENIXDI, PHOENIXDII, PHOENIXDIII, PHOENIXDIV};
class BaseItem {
    public:
        itemID ID;
    public:
        virtual bool canUse ( BaseKnight * knight ) = 0;
        virtual void use ( BaseKnight * knight ) = 0;
};

class Events {
public:
    int num_of_events;
    int * events;
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
        MadBear(int gil, int baseDamage, int level0);
};

class Bandit:public BaseOpponent
{
    public:
        Bandit(int gil, int baseDamage, int level0);
};

class LordLupin:public BaseOpponent
{
    public:
        LordLupin(int gil, int baseDamage, int level0);
};

class Elf:public BaseOpponent
{
    public:
        Elf(int gil, int baseDamage, int level0);
};

class Troll:public BaseOpponent
{
    public:
        Troll(int gil, int baseDamage, int level0);
};

#endif // __KNIGHT2_H__