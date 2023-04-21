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
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent
{
    public:
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
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    KnightType returnType();
};

class ArmyKnights 
{
public:
    int numberofKnight;
    BaseKnight ** Knight;
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
};

class BaseItem {
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
        bool fight(BaseOpponent * opponent);
};

class Lancelot:public BaseKnight
{
    public:
        Lancelot(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Lancelot();
        bool fight(BaseOpponent * opponent);
};

class Dragon:public BaseKnight
{
    public:
        Dragon(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Dragon();
        bool fight(BaseOpponent * opponent);
};

class Normal:public BaseKnight
{
    public:
        Normal(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
        ~Normal();
        bool fight(BaseOpponent * opponent);
};

//Different type of opponent

class MadBear:public BaseOpponent
{
    public:
        MadBear(int gil, int baseDamage, int level0);
        ~MadBear();
};

class Bandit:public BaseOpponent
{
    public:
        Bandit(int gil, int baseDamage, int level0);
        ~Bandit();
};

class LordLupin:public BaseOpponent
{
    public:
        LordLupin(int gil, int baseDamage, int level0);
        ~LordLupin();
};

class Elf:public BaseOpponent
{
    public:
        Elf(int gil, int baseDamage, int level0);
        ~Elf();
};

class Troll:public BaseOpponent
{
    public:
        Troll(int gil, int baseDamage, int level0);
        ~Troll();
};

#endif // __KNIGHT2_H__