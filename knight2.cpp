#include "knight2.h";

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
    if (maxHP >= 100 && maxHP <= 999)
    {
        int a,b,c;
        a = maxHP % 10;
        maxHP /= 10;
        b = maxHP % 10;
        maxHP /= 10;
        c = maxHP;
        if (a <= 0 || b <= 0 || c <= 0)
        {
            return false;
        }
        if (pow(a,2) + pow(b,2) == pow(c,2) || pow(a,2) + pow(c,2) == pow(b,2) || pow(b,2) + pow(c,2) == pow(a,2))
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

/***END function checking Knight type****/

/* * * BEGIN implementation of class BaseBag * * */

void BaseBag::useItem(BaseKnight *lastKnight)
{
    if (list.First->Stuff->itemID == PHOENIXDI)
    {
        lastKnight->changeHP(lastKnight->returnmaxhp());
    }
    else if (list.First->Stuff->itemID == PHOENIXDII)
    {
        lastKnight->changeHP(lastKnight->returnmaxhp());
    }
    else if (list.First->Stuff->itemID == PHOENIXDIII)
    {
        if (lastKnight->returnhp() <= 0)
        {
            lastKnight->changeHP(lastKnight->returnmaxhp()/3);
        }
        else
        {
            lastKnight->changeHP(lastKnight->returnhp() + lastKnight->returnmaxhp()/4);
        }
    }
    else if (list.First->Stuff->itemID == PHOENIXDIV)
    {
        if (lastKnight->returnhp() <= 0)
        {
            lastKnight->changeHP(lastKnight->returnmaxhp()/2);
        }
        else
        {
            lastKnight->changeHP(lastKnight->returnhp() + lastKnight->returnmaxhp()/5);
        }
    }
}

void BaseBag::eraseItem()
{
    if (list.First->Stuff->itemID == ANTIDOTE)
    {
        antidote--;
    }
    else if (list.First->Stuff->itemID == PHOENIXDI)
    {
        PhoenixI--;
    }
    else if (list.First->Stuff->itemID == PHOENIXDII)
    {
        PhoenixII--;
    }
    else if (list.First->Stuff->itemID == PHOENIXDIII)
    {
        PhoenixIII--;
    }
    else if (list.First->Stuff->itemID == PHOENIXDIV)
    {
        PhoenixIV--;
    }
    list.First = list.First->next;
    numofItem--;
}

bool BaseBag::canAdd(ItemType ID, int maxInvent)
{
    if (numofItem < maxInvent || maxInvent == -1)
    {
        if (ID == ANTIDOTE)
        {
            if (antidote < 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (ID == PHOENIXDI)
        {
            if (PhoenixI < 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (ID == PHOENIXDII)
        {
            if (PhoenixII < 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (ID == PHOENIXDIII)
        {
            if (PhoenixIII < 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (ID == PHOENIXDIV)
        {
            if (PhoenixIV < 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else 
    {
        return false;
    }
}

void BaseBag::addHead(ItemType ID, int maxInvent)
{
    Item *item;
    item = new Item;
    if (ID == PHOENIXDI)
    {
        if (canAdd(ID, maxInvent) == true)
        {
            if (list.First == nullptr)
            {
                item->Stuff = new PhoenixDI;
                item->Stuff->itemID = PHOENIXDI;
                item->next = nullptr;
                list.First = item;
                list.Last = item;
                numofItem++;
                PhoenixI++;
            }
            else
            {
                item->Stuff = new PhoenixDI;
                item->Stuff->itemID = PHOENIXDI;
                item ->next = list.First;
                list.First = item;
                numofItem++;
                PhoenixI++;
            }
        }
    }
    else if (ID == ANTIDOTE)
    {
        if (canAdd(ID, maxInvent) == true)
        {
            if (list.First == nullptr)
            {
                item->Stuff = new Antidote;
                item->Stuff->itemID = ANTIDOTE;
                item->next = nullptr;
                list.First = item;
                list.Last = item;
                numofItem++;
                antidote++;
            }
            else
            {
                item->Stuff = new Antidote;
                item->Stuff->itemID = ANTIDOTE;
                item ->next = list.First;
                list.First = item;
                numofItem++;
                antidote++;
            }
        }
    }
    else if (ID == PHOENIXDII)
    {
        if (canAdd(ID, maxInvent) == true)
        {
            if (list.First == nullptr)
            {
                item->Stuff = new PhoenixDII;
                item->Stuff->itemID = PHOENIXDII;
                item->next = nullptr;
                list.First = item;
                list.Last = item;
                numofItem++;
                PhoenixII++;
            }
            else
            {
                item->Stuff = new PhoenixDII;
                item->Stuff->itemID = PHOENIXDII;
                item ->next = list.First;
                list.First = item;
                numofItem++;
                PhoenixII++;
            }
        }
    }
    else if (ID == PHOENIXDIII)
    {
        if (canAdd(ID, maxInvent) == true)
        {
            if (list.First == nullptr)
            {
                item->Stuff = new PhoenixDIII;
                item->Stuff->itemID = PHOENIXDII;
                item->next = nullptr;
                list.First = item;
                list.Last = item;
                numofItem++;
                PhoenixIII++;
            }
            else
            {
                item->Stuff = new PhoenixDIII;
                item->Stuff->itemID = PHOENIXDIII;
                item ->next = list.First;
                list.First = item;
                numofItem++;
                PhoenixIII++;
            }
        }
    }
    else if (ID == PHOENIXDIV)
    {
        if (canAdd(ID, maxInvent) == true)
        {
            if (list.First == nullptr)
            {
                item->Stuff = new PhoenixDIV;
                item->Stuff->itemID = PHOENIXDIV;
                item->next = nullptr;
                list.First = item;
                list.Last = item;
                numofItem++;
                PhoenixIV++;
            }
            else
            {
                item->Stuff = new PhoenixDIV;
                item->Stuff->itemID = PHOENIXDIV;
                item ->next = list.First;
                list.First = item;
                numofItem++;
                PhoenixIV++;
            }
        }
    }
}

void BaseBag::item_to_Head(int index)
{
   Item *check;
   if (numofItem > 1)
   {
        if (index != 0)
        {
            check = list.First;
            for(int i = 0; i < index; i++)
            {
                check = check->next;
            }
            BaseItem *temp;
            temp = list.First->Stuff;
            list.First->Stuff = check->Stuff;
            check->Stuff = temp;
            temp = nullptr;
            delete temp;
        }
   }
   check = nullptr;
   delete check;
}

// bool BaseBag::insertFirst(BaseItem * item)
// {

// }

// BaseItem* BaseBag::get(ItemType ItemType)
// {

// }

string BaseBag::toString() const
{
    string typeString[5] = {"Antidote", "PhoenixI", "PhoenixII", "PhoenixIII", "PhoenixIV"};
    string s(""), temp("");
    Item *Searching = list.First;
    while (Searching != NULL)
    {
        temp += "," + typeString[Searching->Stuff->itemID];
        Searching = Searching->next;
    }
    s += "Bag[count=" + to_string(numofItem) + ";" + temp + "]";
    return s;
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */

void BaseKnight::changeGil(int Gil)
{
    this->gil = Gil;
}

void BaseKnight::changeLevel(int level)
{
    if (level <= 10)
    {
        this -> level = level;
    }
    else
    {
        this -> level = 10;
    }
}

void BaseKnight::changeHP(int HP)
{
    if (HP > maxhp)
    {
        this -> hp = maxhp;
    }
    else
    {
        this -> hp = HP;
    }
}

bool BaseKnight::revKnight(BaseKnight *lastKnight, BaseKnight **&Knight, int &KnightQuantity)
{
    bool Check = false;
    Item *check;
    if (lastKnight->hp > 0)
    {
        return true;
    }
    while (lastKnight->bag->PhoenixI > 0 ||lastKnight->bag->PhoenixII > 0 || lastKnight->bag->PhoenixIII > 0 || lastKnight->bag->PhoenixIV > 0)
    {
        check = lastKnight->bag->list.First;
        int index = 0;
        bool temp = lastKnight->hp > 0 ? true : false, exists = false;   
        if (temp == true)
        {
            return true;
        }     
        while(check != nullptr)
        {
            if (check->Stuff->itemID == PHOENIXDI || check->Stuff->itemID == PHOENIXDII || check->Stuff->itemID == PHOENIXDIII || check->Stuff->itemID == PHOENIXDIV)
            {
                exists = true;
                break;
            }
            index++;
            check = check->next;
        }
        if (exists == true)
        {
            lastKnight->bag->item_to_Head(index);
            check = lastKnight->returnBag()->list.First;
            if (check->Stuff->itemID == PHOENIXDI)
            {
                lastKnight->bag->useItem(lastKnight);
                lastKnight->bag->eraseItem();
                return true;
            }
            else 
            {
                lastKnight->bag->useItem(lastKnight);
                lastKnight->bag->eraseItem();
            }
        }
        else
        {
            break;
        }
    }
    if (Check == true)
    {
        return true;
    }
    while (lastKnight->returngil() >= 100 && lastKnight->returnhp() <= 0)
    {
        lastKnight->changeHP(lastKnight->maxhp/2);
        lastKnight->changeGil(lastKnight->gil - 100);
        if (lastKnight->returnhp() > 0)
        {
            return true;
        }
    }
    return false;
}

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

BaseBag *BaseKnight::returnBag()
{
    return this -> bag;
}

int BaseKnight::returnMaxinvent()
{
    return this -> maxInvent;
}

void BaseKnight::firstAdd()
{
    if (phoenixdownI > 5)
    {
        for (int i = 0; i < 5; i++)
        {
            bag->addHead(PHOENIXDI,maxInvent);
        }
    }
    else
    {
        for (int i = 0; i < phoenixdownI; i++)
        {
            bag->addHead(PHOENIXDI, maxInvent);
        }
    }
    if (this -> knightType != DRAGON)
    {
        if (this -> antidote > 5)
        {
            for (int i = 0; i < 5; i++)
            {
                bag->addHead(ANTIDOTE, maxInvent);
            }
        }
        else
        {
            for (int i = 0; i < this->returnantidote(); i++)
            {
                bag->addHead(ANTIDOTE, maxInvent);
            }
        }
    }
}

void BaseKnight::useotPhoenix(BaseKnight *lastKnight)
{
    Item *check = bag->list.First;
    int index = 0;
    if (hp < maxhp / 4)
    {
        if (bag->PhoenixII > 0 || bag->PhoenixIII > 0 || bag->PhoenixIV > 0)
        {
            while (check != nullptr)
            {
                if (check->Stuff->itemID == PHOENIXDII || check->Stuff->itemID == PHOENIXDIII || check->Stuff->itemID == PHOENIXDIV)
                {
                    break;
                }
                index++;
                check = check->next;
            }
            bag->item_to_Head(index);
            bag->useItem(lastKnight);
            bag->eraseItem();
        }
    }
    else if (hp < maxhp/3)
    {
        if (bag->PhoenixIII > 0 || bag->PhoenixIV > 0)
        {
            while (check != nullptr)
            {
                if (check->Stuff->itemID == PHOENIXDIII || check->Stuff->itemID == PHOENIXDIV)
                {
                    break;
                }
                index++;
                check = check->next;
            }
            bag->item_to_Head(index);
            bag->useItem(lastKnight);
            bag->eraseItem();
        }
    }
    else if (hp > 0 && hp < maxhp/2)
    {
        if (bag->PhoenixIV > 0)
        {
            while (check != nullptr)
            {
                if (check->Stuff->itemID == PHOENIXDIV)
                {
                    break;
                }
                index++;
                check = check->next;
            }
            bag->item_to_Head(index);
            bag->useItem(lastKnight);
            bag->eraseItem();
        }
    }
}


/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */

void ArmyKnights::FightQueen(BaseOpponent *opponent)
{
    if (lastKnight()->returnLevel() >= opponent->level0)
    {
        int i = numberofKnight - 1, Money;
        Money = lastKnight()->returngil()*2;
        while (i >= 0)
        {
            if (999 - Knight[i]->returngil() >= Money)
            {
                Knight[i]->addGil(Money);
                break;
            }
            else
            {
                Money -= 999 - Knight[i]->returngil();
                Knight[i]->addGil(999 - Knight[i]->returngil());
            }
            i--;
        }
    }
    else
    {
        if (lastKnight()->returnType() != PALADIN)
        {
            lastKnight()->changeGil(lastKnight()->returngil()/2);
        }
    }
}

void ArmyKnights::killastKnight()
{
    BaseKnight **newKnight, **temp;
    newKnight = new BaseKnight*[numberofKnight - 1];
    for (int run = 0; run < numberofKnight - 1; run++)
    {
        newKnight[run] = Knight[run];
    }
    temp = Knight;
    Knight = newKnight;
    numberofKnight--;
    newKnight = nullptr;
    delete newKnight;
    delete temp;
}

void ArmyKnights::Fight1to5(BaseOpponent *opponent)
{
    if (lastKnight()->returnType() == PALADIN || lastKnight()->returnType() == LANCELOT || lastKnight()->returnLevel() > opponent->level0)
    {
        int i = numberofKnight - 1, Money;
        Money = opponent->gil;
        while (i >= 0)
        {
            if (999 - Knight[i]->returngil() >= Money)
            {
                Knight[i]->addGil(Money);
                break;
            }
            else
            {
                Money -= 999 - Knight[i]->returngil();
                Knight[i]->addGil(999 - Knight[i]->returngil());
            }
            i--;
        }
    }
    else
    {
        int newHP = lastKnight()->returnhp() - opponent->baseDamage*(opponent->level0 - lastKnight()->returnLevel());
        if (newHP > 0)
        {
            lastKnight()->changeHP(newHP);
            int i = numberofKnight - 1, Money;
            Money = opponent->gil;
            while (i >= 0)
            {
                if (999 - Knight[i]->returngil() >= Money)
                {
                    Knight[i]->addGil(Money);
                    break;
                }
                else
                {
                    Money -= 999 - Knight[i]->returngil();
                    Knight[i]->addGil(999 - Knight[i]->returngil());
                }
                i--;
            }
        }
        else
        {
            lastKnight()->changeHP(newHP);
        }
    }
}

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

void ArmyKnights::FightTornbery (BaseOpponent *ghost)
{
    Tornbery *temp;
    temp = new Tornbery(ghost->level0);
    if (lastKnight()->returnLevel() >= temp->level0)
    {
        lastKnight()->changeLevel(lastKnight()->returnLevel() + 1);
    }
    else 
    {
        if (lastKnight()->returnType() != DRAGON)
        {
            temp->Curse(lastKnight());
        }
    }
}

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
    if (opponent->id <= 5)
    {
        Fight1to5(opponent);
    }
    else if (opponent->id == 6)
    {
        FightTornbery(opponent);
    }
    else if (opponent->id == 7)
    {
        FightQueen(opponent);
    }
    else if (opponent->id == 10)
    {

    }
    else if (opponent->id == 11)
    {

    }
    else if (opponent->id == 99)
    {

    }
    //Check last Knight
    bool checkLKnight = lastKnight()->revKnight(lastKnight(), Knight, numberofKnight);
    if (checkLKnight == true)
    {
        lastKnight()->useotPhoenix(lastKnight());
        return true;
    }
    else
    {
        killastKnight();
        return false;
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
        if (numberofKnight > 0)
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
    return numberofKnight;
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
    this -> maxInvent = -1;
    bag = new BaseBag();
    firstAdd();
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
    bag = new BaseBag();
    firstAdd();
}

Dragon::Dragon(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this -> id = id;
    this -> hp = maxhp;
    this -> maxhp = maxhp;
    this -> level = level;
    this -> gil = gil;
    this -> phoenixdownI = phoenixdownI;
    this -> knightType = DRAGON;
    this -> maxInvent = 14;
    bag = new BaseBag();
    firstAdd();
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
    bag = new BaseBag();
    firstAdd();
}

/***END set new knight****/

/***BEGIN set new Opponent ***/

MadBear::MadBear(int level0)
{
    this -> gil = 100;
    this -> baseDamage = 10;
    this -> level0 = level0;
    this -> id = 1;
}

Bandit::Bandit(int level0)
{
    this -> gil = 150;
    this -> baseDamage = 15;
    this -> level0 = level0;
    this -> id = 2;
}

LordLupin::LordLupin(int level0)
{
    this -> gil = 450;
    this -> baseDamage = 45;
    this -> level0 = level0;
    this -> id = 3;
}

Elf::Elf(int level0)
{
    this -> gil = 750;
    this -> baseDamage = 75;
    this -> level0 = level0;
    this -> id = 4;
}

Troll::Troll(int level0)
{
    this -> gil = 800;
    this -> baseDamage = 95;
    this -> level0 = level0;
    this -> id = 5;
}

Tornbery::Tornbery(int level0)
{
    this -> id = 6;
    this -> level0 = level0;
}

cardQueen::cardQueen(int level0)
{
    this -> id = 7;
    this -> level0 = level0;
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
                Bear = new MadBear(Bear->level0Calc(run, 1));
                armyKnights->fight(Bear,armyKnights);
                delete Bear;
                break;
            }
            case 2:
            {
                Bandit *Theft;
                Theft = new Bandit(Theft->level0Calc(run, 2));
                armyKnights ->fight(Theft, armyKnights);
                delete Theft;
                break;
            }
            case 3:
            {
                LordLupin *Lord;
                Lord = new LordLupin(Lord->level0Calc(run, 3));
                armyKnights -> fight(Lord, armyKnights);
                delete Lord;
                break;
            }
            case 4:
            {
                Elf *magicCreture;
                magicCreture = new Elf(magicCreture->level0Calc(run, 4));
                armyKnights -> fight(magicCreture, armyKnights);
                delete magicCreture;
                break;
            }
            case 5:
            {
                Troll *Bigguy;
                Bigguy = new Troll(Bigguy->level0Calc(run, 5));
                armyKnights->fight(Bigguy, armyKnights);
                delete Bigguy;
                break;
            }
            case 6:
            {
                BaseOpponent *Ghost;
                Ghost = new Tornbery(Ghost->level0Calc(run,6));
                armyKnights->fight(Ghost, armyKnights);
                delete Ghost;
                break;
            }
            case 7:
            {
                cardQueen *Queen;
                Queen = new cardQueen(Queen->level0Calc(run, 7));
                armyKnights->fight(Queen, armyKnights);
                delete Queen;
                break;
            }
            case 8:
            {
                
                break;
            }
            case 9:
            {
                events->Durian(armyKnights);
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
                break;
            }
            case 96:
            {
                armyKnights->LancelotSpear = true;
                break;
            }
            case 97:
            {
                armyKnights->GuinevereHair = true;
                break;
            }
            case 98:
            {
                if (armyKnights->PaladinShield == true & armyKnights->LancelotSpear == true && armyKnights->GuinevereHair == true)
                {
                    armyKnights->ExcaliburSword = true;
                }
                break;
            }
            case 99:
            {
                break;
            }
        }
        checkCont = armyKnights->numberofKnight > 0 ? true : false;
        armyKnights->printInfo();
        if (checkCont == false)
        {
            armyKnights->printResult(false);
            break;
        }
        if (armyKnights->adventure(events, run) == true)
        {
            if (checkCont == true)
            {
                armyKnights->printResult(true);
                break;
            }
            else
            {
                armyKnights->printResult(false);
                break;
            }
        }
    }
}

/* * * END implementation of class KnightAdventure * * */

/***BEGIN implementation of class BaseItem***/

// bool BaseItem::canUse(BaseKnight *knight)
// {

// }

// void BaseItem::use(BaseKnight *knight)
// {

// }

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
    armyKnights->lastKnight()->changeHP(armyKnights->lastKnight()->returnmaxhp());
}

/***END implementation of class Events***/

/***BEGIN implementation of class BaseOpponent***/

int BaseOpponent::level0Calc(int eventRun, int eventID)
{
    return (eventRun + eventID) % 10 + 1;
}

void Tornbery::Curse(BaseKnight *lastKnight)
{
    if (lastKnight->returnBag()->antidote > 0)
    {
        Item *item = lastKnight->returnBag()->list.First;
        int index = 0;
        while (item != nullptr)
        {
            if (item->Stuff->itemID == ANTIDOTE)
            {
                break;
            }
            index++;
            item = item->next;
        }
        lastKnight->returnBag()->item_to_Head(index);
        lastKnight->returnBag()->eraseItem();
    }
    else
    {
        if (lastKnight->returnBag()->numofItem > 3)
        {
            for (int i = 0; i < 3; i++)
            {
                lastKnight->returnBag()->eraseItem();
            }
        }
        else
        {
            int temp = lastKnight->returnBag()->numofItem;
            for (int i = 0; i < temp; i++)
            {
                lastKnight->returnBag()->eraseItem();
            }
        }
        lastKnight->changeHP(lastKnight->returnhp() - 10);
    }
}

/***END implementation of class BaseOpponent***/