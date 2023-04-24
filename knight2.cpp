#include "knight2.h"

/***BEGIN killlastKnight***/

void killastKnight(BaseKnight *lastKnight,BaseKnight **&Knight, int &KnightQuantity)
{
    BaseKnight **newKnight;
    KnightQuantity--;
    newKnight = new BaseKnight*[KnightQuantity];
    for (int run = 0; run < KnightQuantity; run++)
    {
        newKnight[run] = Knight[run];
    }
    delete [] Knight;
    Knight = newKnight;
    newKnight = nullptr;
}

/***END killlastKnight***/

/***BEGIN revKnight***/

bool revKnight(BaseKnight *lastKnight, BaseKnight **&Knight, int &KnightQuantity)
{
    if (lastKnight -> returnhp() <= 0)
    {
        for (int run = KnightQuantity - 1; run >= 0; run--)
        {
            if (Knight[run] -> returnphoenixdownI() != 0)
            {
                Knight[run] -> changeStat(Knight[run]->returnid(), Knight[run]->returnhp(), Knight[run]->returnLevel(), Knight[run] -> returngil(), Knight[run] -> returnantidote(), Knight[run] -> returnphoenixdownI() - 1);
                lastKnight ->changeStat(Knight[run]->returnid(), Knight[run]->returnmaxhp(), Knight[run]->returnLevel(), Knight[run] -> returngil(), Knight[run] -> returnantidote(), Knight[run] -> returnphoenixdownI());
                return true;
            }
        }
        for (int run = KnightQuantity - 1; run >= 0; run--)
        {
            if (Knight[run] -> returngil() >= 100)
            {
                Knight[run] -> changeStat(Knight[run]->returnid(), Knight[run]->returnhp(), Knight[run]->returnLevel(), Knight[run] -> returngil() - 100, Knight[run] -> returnantidote(), Knight[run] -> returnphoenixdownI());
                lastKnight ->changeStat(Knight[run]->returnid(), (Knight[run]->returnmaxhp())/2, Knight[run]->returnLevel(), Knight[run] -> returngil(), Knight[run] -> returnantidote(), Knight[run] -> returnphoenixdownI());
                return true;
            }
        }
        killastKnight(lastKnight, Knight, KnightQuantity);
        return false;
    }
    else
    {
        return true;
    }
}

/***END revKnight***/

/***BEGIN checksurvivor***/

bool checkSurv(BaseKnight *lastKnight,ArmyKnights *armyKnights, BaseOpponent *Opponent,BaseKnight **&Knight, int &KnightQuantity)
{
    if (revKnight(lastKnight, Knight, KnightQuantity) == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/***END checksurvivor***/

/***BEGIN level0 calculator***/

int level0(int eventRun, int eventID)
{
    return (eventRun + eventID) % 10 + 1;
}

/***END level0 calculator***/

/***BEGIN fight 1 - 5***/

void fight1to5(ArmyKnights * armyKnights,BaseKnight * lastKnight, BaseOpponent *opponent)
{
    int levelKnight, HPKnight, newHP;
    levelKnight = lastKnight -> returnLevel();
    KnightType typeKnight;
    typeKnight = lastKnight -> returnType();
    HPKnight = lastKnight->returnhp();
    if (levelKnight >= opponent->level0 || typeKnight == LANCELOT || typeKnight == PALADIN)
    {
        int i = armyKnights->numberofKnight - 2, change = lastKnight->returngil() + opponent->gil - 999;
        if (change > 0)
        {
            lastKnight->addGil(999);
            while (change > 0 && i >= 0)
            {
                int temp = armyKnights->Knight[i]->returngil();
                armyKnights->Knight[i]->addGil(change);
                change = temp + change - 999;
                i--;
            }
        }
        else
        {
            lastKnight->addGil(opponent->gil);
        }
    }
    else 
    {
        newHP = HPKnight - opponent->baseDamage * (opponent->level0 - levelKnight);
        if (newHP > 0)
        {
            int i = armyKnights->numberofKnight - 2, change = lastKnight->returngil() + opponent->gil - 999;
            if (change > 0)
            {
                lastKnight->addGil(999);
                while (change > 0 && i >= 0)
                {
                    int temp = armyKnights->Knight[i]->returngil();
                    armyKnights->Knight[i]->addGil(change);
                    change = temp + change - 999;
                    i--;
                }
            }
            else
            {
                lastKnight->addGil(opponent->gil);
            }
        }
        else
        {
            lastKnight ->changeStat(lastKnight -> returnid(), newHP, levelKnight, lastKnight ->returngil(), lastKnight -> returnantidote(), lastKnight -> returnphoenixdownI());
        }
    }
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
    return "Update later";
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
        + "," //+ bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
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

int BaseKnight::returnLevel()
{
    return this -> level;
}

int BaseKnight::returnid()
{
    return this -> id;
}

int BaseKnight::returnhp()
{
    return this -> hp;
}

int BaseKnight::returnmaxhp()
{
    return this -> maxhp;
}

int BaseKnight::returngil()
{
    return this -> gil;
}

int BaseKnight::returnantidote()
{
    return this -> antidote;
}

int BaseKnight::returnphoenixdownI()
{
    return this -> phoenixdownI;
}

void BaseKnight::addGil(int gilAdd)
{
    this -> gil += gilAdd;
    if (this -> gil > 999)
    {
        this -> gil = 999;
    }
}

void BaseKnight::changeStat(int id, int hp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = hp;
    this -> level = level;
    this -> gil = gil;
    this -> antidote = antidote;
    this -> phoenixdownI = phoenixdownI;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) 
    {
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

bool ArmyKnights::fight(BaseOpponent * opponent, ArmyKnights *armyKnights)
{
    //Fighting
    if (opponent -> id <= 5)
    {
        fight1to5(armyKnights,this -> lastKnight(), opponent);
    }
    else if (opponent->id == 6)
    {

    }

    armyKnights->printInfo();

    //Stat checking
    if(checkSurv(this -> lastKnight(), armyKnights, opponent, armyKnights -> Knight, armyKnights -> numberofKnight) == false)
    {
        if (armyKnights->numberofKnight == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

BaseKnight * ArmyKnights::lastKnight() const
{
    if (this -> numberofKnight == 0)
    {
        return NULL;
    }
    else
    {
        return this -> Knight[this -> numberofKnight - 1];
    }
}

bool ArmyKnights::adventure(Events * events, int run)
{
    if (run == events->num_of_events - 1)
    {
        if (this -> numberofKnight > 0)
        {
            return true;
        }  
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int ArmyKnights::count() const
{
    return this ->numberofKnight;
}

bool ArmyKnights::hasPaladinShield() const
{
    return PaladinShield;
}

bool ArmyKnights::hasLancelotSpear() const
{
    return LancelotSpear;
}

bool ArmyKnights::hasGuinevereHair() const
{
    return GuinevereHair;
}

bool ArmyKnights::hasExcaliburSword() const
{
    return ExcaliburSword;
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
    this -> maxInvent = 16;
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
    this -> maxInvent = 14;
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
    this -> maxInvent = 19;
}

/***END set new knight****/

/***BEGIN set new Opponent ***/

MadBear::MadBear(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
    this -> id = 1;
}

Bandit::Bandit(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
    this -> id = 2;
}

LordLupin::LordLupin(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
    this -> id = 3;
}

Elf::Elf(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
    this -> id = 4;
}

Troll::Troll(int gil, int baseDamage, int level0)
{
    this -> gil = gil;
    this -> baseDamage = baseDamage;
    this -> level0 = level0;
    this -> id = 5;
}

/***END set new Opponent***/

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
    ArmyKnights * armyKnights;
    armyKnights = this -> armyKnights;
    BaseKnight * lastKnight;
    lastKnight = armyKnights->lastKnight();
    bool checkCont;
    for (int run = 0; run < events -> num_of_events; run++)
    {
        switch(events -> events[run])
        {
            case 1:
            {
                MadBear *Bear;
                Bear = new MadBear(100,10,level0(run,events -> events[run]));
                checkCont = armyKnights->fight(Bear,armyKnights);
                delete Bear;
                break;
            }
            case 2:
            {
                Bandit *Theft;
                Theft = new Bandit(150, 15, level0(run, events -> events[run]));
                checkCont = armyKnights ->fight(Theft, armyKnights);
                delete Theft;
                break;
            }
            case 3:
            {
                LordLupin *Lord;
                Lord = new LordLupin(450, 45, level0(run, events -> events[run]));
                checkCont = armyKnights -> fight(Lord, armyKnights);
                delete Lord;
                break;
            }
            case 4:
            {
                Elf *magicCreture;
                magicCreture = new Elf(750, 75, level0(run, events -> events[run]));
                checkCont = armyKnights -> fight(magicCreture, armyKnights);
                delete magicCreture;
                break;
            }
            case 5:
            {
                Troll *Bigguy;
                Bigguy = new Troll(800, 95, level0(run, events -> events[run]));
                checkCont = armyKnights->fight(Bigguy, armyKnights);
                delete Bigguy;
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
                events->Durian(armyKnights);
                armyKnights->printInfo();
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
                armyKnights->PaladinShield = true;
                armyKnights->printInfo();
                break;
            }
            case 96:
            {
                armyKnights->LancelotSpear = true;
                armyKnights->printInfo();
                break;
            }
            case 97:
            {
                armyKnights->GuinevereHair = true;
                armyKnights->printInfo();
                break;
            }
            case 98:
            {
                if (armyKnights->PaladinShield == true & armyKnights->LancelotSpear == true && armyKnights->GuinevereHair == true)
                {
                    armyKnights->ExcaliburSword = true;
                }
                armyKnights->printInfo();
                break;
            }
            case 99:
            {
                break;
            }
        }
        if (armyKnights->adventure(events, run) == true)
        {
            if (checkCont == true)
            {
                armyKnights->printResult(checkCont);
                break;
            }
            else
            {
                armyKnights->printResult(checkCont);
                break;
            }
        }
        else if (checkCont == false)
        {
            armyKnights->printResult(checkCont);
            break;
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
    return this ->num_of_events;
}

int Events::get(int i) const
{

}

void Events::Durian(ArmyKnights *armyKnights)
{
    for(int i = 0; i < armyKnights->numberofKnight; i++)
    {
        armyKnights->Knight[i]->changeStat(armyKnights->Knight[i]->returnid(), armyKnights->Knight[i]->returnmaxhp(),armyKnights->Knight[i]->returnLevel(), armyKnights->Knight[i]->returngil(), armyKnights->Knight[i]->returnantidote(), armyKnights->Knight[i]->returnphoenixdownI());
    }
}

/***END implementation of class Events***/