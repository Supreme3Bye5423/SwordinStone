#include "knight2.h"

/***BEGIN level0 calculator***/

int level0(int eventRun, int eventID)
{
    return (eventRun + eventID) % 10 + 1;
}

/***END level0 calculator***/

/***BEGIN fight 1 - 5***/

void fight()
{
    
}

/***END fight 1 - 5***/

/***BEGIN function checking Knight type***/

//Check Paladin
bool paladinCheck(int maxHP)
{
    if (maxHP < 2) 
    {
        return false;
    }
    int squareRoot = (int) sqrt(maxHP);
    int i;
    for (i = 2; i <= squareRoot; i++) {
        if (maxHP % i == 0) {
            return false;
        }
    }
    return true;
}

//Check lancelot
bool lancelotCheck(int maxHP)
{
    if (maxHP == 888)
    {
        return true;
    }
    return false;
}

//Check dragon
bool dragonCheck(int maxHP)
{
    if (maxHP < 100 || maxHP > 999)
    {
        int * a, max = 0;
        a = new int [3];
        for (int i = 0; i < 3; i++)
        {
            a[i] = maxHP % 10;
            maxHP /= maxHP;
        }
        if (pow(a[0],2) + pow(a[1],2) == pow(a[2],2))
        {
            return true;
        }
        else if (pow(a[0],2) + pow(a[2],2) == pow(a[1],2))
        {
            return true;
        }
        else if (pow(a[1],2) + pow(a[2],2) == pow(a[0],2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/***END function checking Knight type****/

/* * * BEGIN implementation of class BaseBag * * */

bool BaseBag::insertFirst(BaseItem * item)
{

}

BaseItem* BaseBag::get(ItemType ItemType)
{

}

string BaseBag::toString() const
{

}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/*****/

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const 
{
    cout << (win ? "WIN" : "LOSE") << endl;
}

BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    BaseKnight * temp = nullptr;
    if (paladinCheck(maxhp) == true)
    {   
        temp = new Paladin(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if (lancelotCheck(maxhp) == true)
    {
        temp = new Lancelot(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else if (dragonCheck(maxhp) == true)
    {
        temp = new Dragon(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    else
    {
        temp = new Normal(id, maxhp, level, gil, antidote, phoenixdownI);
    }
    return temp;
}

KnightType BaseKnight::returnType()
{
    return this -> knightType;
}

//Read armyKnight file

ArmyKnights::ArmyKnights(const string & file_armyknights)
{
    ifstream openfile;
    openfile.open(file_armyknights);
    openfile >> this -> numberofKnight;
    int hp, maxhp, level, gil, antidote, phoenixDownI;
    Knight = new BaseKnight *[this -> numberofKnight];
    for (int Knightindex = 0; Knightindex < numberofKnight; Knightindex++)
    {
        openfile >> hp >> level >> phoenixDownI >> gil >> antidote;
        Knight[Knightindex] = BaseKnight::create(Knightindex + 1, hp, level, gil, antidote, phoenixDownI);
    }
}

ArmyKnights::~ArmyKnights()
{

}

bool ArmyKnights::adventure(Events * events)
{

}

int ArmyKnights::count() const
{

}

BaseKnight * ArmyKnights::lastKnight() const
{

}

bool ArmyKnights::hasPaladinShield() const
{

}

bool ArmyKnights::hasLancelotSpear() const
{

}

bool ArmyKnights::hasGuinevereHair() const
{

}

bool ArmyKnights::hasExcaliburSword() const
{
    
}


/* * * END implementation of class ArmyKnights * * */

/***BEGIN set new knight****/

Paladin::Paladin(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = maxhp;
    this -> maxhp = maxhp;
    this -> level = level;
    this -> gil = gil;
    this -> phoenixdownI = phoenixdownI;
    this -> antidote = antidote;
    this -> knightType = PALADIN;
}

Lancelot::Lancelot(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = maxhp;
    this -> maxhp = maxhp;
    this -> level = level;
    this -> gil = gil;
    this -> phoenixdownI = phoenixdownI;
    this -> antidote = antidote;
    this -> knightType = LANCELOT;
}

Dragon::Dragon(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = maxhp;
    this -> maxhp = maxhp;
    this -> level = level;
    this -> gil = gil;
    this -> phoenixdownI = phoenixdownI;
    this -> antidote = antidote;
    this -> knightType = DRAGON;
}

Normal::Normal(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = maxhp;
    this -> maxhp = maxhp;
    this -> level = level;
    this -> gil = gil;
    this -> phoenixdownI = phoenixdownI;
    this -> antidote = antidote;
    this -> knightType = NORMAL;
}

/***END set new knight****/

/***BEGIN set new Opponent ***/

MadBear::MadBear(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
}

Bandit::Bandit(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
}

LordLupin::LordLupin(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
}

Elf::Elf(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
}

Troll::Troll(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
}

/***END set new Opponent***/

/***BEGIN fight session ***/

bool Paladin::fight(BaseOpponent *opponent)
{

}

bool Lancelot::fight(BaseOpponent *opponent)
{
    
}

bool Dragon::fight(BaseOpponent *opponent)
{
    
}

bool Normal::fight(BaseOpponent *opponent)
{
    
}

/***END fight session ***/

/***BEGIN Define for ***/

/***END ***/

/* * * BEGIN implementation of class KnightAdventure * * */

KnightAdventure::KnightAdventure()
{

}

KnightAdventure:: ~KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

void KnightAdventure::loadArmyKnights(const string & file_ArmyKnights)
{
    armyKnights = new ArmyKnights(file_ArmyKnights);
}

void KnightAdventure::loadEvents(const string & file_Events)
{
    events = new Events(file_Events);
}


//Event run
void KnightAdventure::run()
{
    for (int run = 0; run < events -> num_of_events; run++)
    {
        switch(events -> events[run])
        {
            case 1:
            {
                MadBear *Bear;
                Bear = new MadBear(100,10,level0(run,events -> events[run]));
                //if (armyKnights -> Knight[armyKnights -> numberofKnight - 1] -> returnType() == )
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
            case 11:
            {
                break;
            }
            case 112:
            {
                break;
            }
            case 113:
            {
                break;
            }
            case 114:
            {
                break;
            }
            case 95:
            {
                break;
            }
            case 96:
            {
                break;
            }
            case 97:
            {
                break;
            }
            case 98:
            {
                break;
            }
            case 99:
            {
                break;
            }
        }
    }
}

/* * * END implementation of class KnightAdventure * * */

/***BEGIN implementation of class BaseItem***/

/*bool BaseItem::canUse(BaseKnight *knight)
{

}

void BaseItem::use(BaseKnight *knight)
{

}*/

// ***END implementation of class BaseItem***/


/***BEGIN implementation of class Events***/

Events::Events(const string & file_Events)
{
    //Đọc file
    ifstream openfile;
    openfile.open(file_Events);
    openfile >> this -> num_of_events;
    this -> events = new int[this -> num_of_events];
    for (int i = 0; i < this -> num_of_events; i++)
    {
        openfile >> this -> events[i];
    }
}

Events::~Events()
{
}

int Events::count() const
{

}

int Events::get(int i) const
{

}

/***END implementation of class Events***/