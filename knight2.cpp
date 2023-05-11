#include "knight2.h"

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
    bool check = maxHP == 888 ? true : false;
    return check;
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

BaseItem *BaseBag::get(ItemType itemType)
{
    Item *searching = list.First;
    while (searching != nullptr)
    {
        if (searching->Stuff->itemID == itemType)
        {
            return searching->Stuff;
        }
        searching = searching->next;
    }
    return nullptr;
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
    Item *temp;
    temp = list.First;
    list.First = list.First->next;
    delete temp;
    numofItem--;
}

bool BaseBag::canAdd(BaseItem *item)
{
    if (numofItem < maxInvent || maxInvent == -1)
    {
        if (item->itemID == 0)
        {
            bool check = antidote < 5 ? true : false;
            return check;
        }
        else if (item->itemID == 1)
        {
            bool check = PhoenixI < 5 ? true : false;
            return check;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void BaseBag::item_to_Head(ItemType ID)
{
   Item *searching;
   BaseItem *index = get(ID);
   searching = list.First;
   while (searching != NULL) {
       if (searching->Stuff->itemID == ID) {
           break;
       }
       searching = searching->next;
   }
   BaseItem * tempItem = list.First -> Stuff;
   list.First -> Stuff = searching -> Stuff;
   searching -> Stuff = tempItem;
   eraseItem();
   tempItem = nullptr;
   delete tempItem;
}

 bool BaseBag::insertFirst(BaseItem * item)
 {
    Item *itemInsert;
    itemInsert = new Item;
    if (canAdd(item) == true)
    {
        if (item->itemID == 0){
            BaseItem * temp = new Antidote();
            itemInsert->Stuff = item;
            antidote++;
        }
        else if (item->itemID == 1)
        {
            BaseItem * temp = new PhoenixDI();
            itemInsert->Stuff = temp;
            PhoenixI++;
        }
        else if (item->itemID == 2)
        {
            BaseItem * temp = new PhoenixDII();
            itemInsert->Stuff = temp;
            PhoenixII++;
        }
        else if (item->itemID == 3)
        {
            BaseItem * temp = new PhoenixDIII();
            itemInsert->Stuff = temp;
            PhoenixIII++;
        }
        else
        {
            BaseItem * temp = new PhoenixDIV();
            itemInsert->Stuff = temp;
            PhoenixIV++;
        }
        if (list.First == NULL)
        {
            list.First = itemInsert;
            itemInsert->next = nullptr;
            list.Last = itemInsert;
            itemInsert = nullptr;
            delete itemInsert;
        }
        else
        {
            itemInsert -> next = list.First;
            list.First = itemInsert;
            itemInsert = nullptr;
            delete itemInsert;
        }
        numofItem++;
        return true;
    }
    return false;
 }

string BaseBag::toString() const
{
    string typeString[5] = {"Antidote", "PhoenixI", "PhoenixII", "PhoenixIII", "PhoenixIV"};
    string s(""), temp("");
    Item *Searching = list.First;
    int count = 0;
    while (Searching != NULL)
    {
        if (count == numofItem - 1) temp = temp + typeString[Searching->Stuff->itemID];
        else temp = temp + typeString[Searching->Stuff->itemID] + ',';
        Searching = Searching->next;
        count++;
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

bool BaseKnight::revKnight()
{
    Item * item = bag -> list.First;
    while (item != nullptr && item -> Stuff -> itemID == ANTIDOTE){
        item = item -> next;
    }
    if (item != nullptr){
        item -> Stuff ->use(this);
        bag->item_to_Head(item->Stuff->itemID);
    }
    if (hp > 0) return true;
    else if (gil >= 100 && hp < 0)
    {
        hp = maxhp / 2;
        gil -= 100;
        return true;
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

void BaseKnight::firstAdd()
{
    for (int i = 0; i < phoenixdownI; i++)
    {
        if (i == 5)
        {
            break;
        }
        BaseItem *item;
        item = new PhoenixDI();
        bag->insertFirst(item);
        item = nullptr;
        delete item;
    }
    if (knightType != DRAGON)
    {
        for (int i = 0; i < antidote; i++)
        {
            if (i == 5)
            {
                break;
            }
            BaseItem *item;
            item = new Antidote();
            bag->insertFirst(item);
            item = nullptr;
            delete item;
        }
    }
}

void BaseKnight::useotPhoenix(BaseKnight *lastKnight)
{
    Item *searching;
    if (lastKnight -> hp < lastKnight -> maxhp /4)
    {
        searching = bag->list.First;
        while (searching != NULL)
        {
            if (searching->Stuff->itemID == 2 || searching->Stuff->itemID == 3 || searching->Stuff->itemID == 4)
            {
                break;
            }
            searching = searching->next;
        }
        if (searching != nullptr)
        {
            searching->Stuff->use(lastKnight);
            lastKnight->bag->item_to_Head(searching->Stuff->itemID);
        }
        searching = nullptr;
        delete searching;
    }
    else if (lastKnight -> hp < lastKnight -> maxhp / 3)
    {
        searching = bag->list.First;
        while (searching != NULL)
        {
            if (searching->Stuff->itemID == 3 || searching->Stuff->itemID == 4)
            {
                break;
            }
            searching = searching->next;
        }
        if (searching != nullptr)
        {
            searching->Stuff->use(lastKnight);
            lastKnight->bag->item_to_Head(searching->Stuff->itemID);
        }
        searching = nullptr;
        delete searching;
    }
    else if (hp < maxhp/2)
    {
        searching = bag->list.First;
        while (searching != NULL)
        {
            if (searching->Stuff->itemID == 4)
            {
                break;
            }
            searching = searching->next;
        }
        if (searching != nullptr)
        {
            searching->Stuff->use(lastKnight);
            lastKnight->bag->item_to_Head(searching->Stuff->itemID);
        }
        searching = nullptr;
        delete searching;
    }
}

double BaseKnight::returnbaseDame()
{
    return this -> baseDame;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */

void ArmyKnights::addPhoenixIV()
{
    BaseItem *item;
    item = new PhoenixDIV();
    int index = numberofKnight - 1;
    for(index; index >= 0; index--)
    {
        if(Knight[index]->returnBag()->canAdd(item) == true)
        {
            break;
        }
    }
    if (index >= 0)
    {
        Knight[index]->returnBag()->insertFirst(item);
    }
    item = nullptr;
    delete item;
}

void ArmyKnights::addPhoenixIII()
{
    BaseItem *item;
    item = new PhoenixDIII();
    int index = numberofKnight - 1;
    for(index; index >= 0; index--)
    {
        if(Knight[index]->returnBag()->canAdd(item) == true)
        {
            break;
        }
    }
    if (index >= 0)
    {
        Knight[index]->returnBag()->insertFirst(item);
    }
    item = nullptr;
    delete item;
}

void ArmyKnights::addPhoenixII()
{
    BaseItem *item;
    item = new PhoenixDII();
    int index = numberofKnight - 1;
    for(index; index >= 0; index--)
    {
        if(Knight[index]->returnBag()->canAdd(item) == true)
        {
            break;
        }
    }
    if (index >= 0)
    {
        Knight[index]->returnBag()->insertFirst(item);
    }
    item = nullptr;
    delete item;
}

void ArmyKnights::killKnightindex(int index)
{
    if (index == numberofKnight - 1)
    {
        killastKnight();
    }
    else
    {
        BaseKnight **newKnight, **temp;
        newKnight = new BaseKnight * [numberofKnight - 1];
        for (int i = 0; i < index; i++)
        {
            newKnight[i] = Knight[i];
        }
        for (int i = index; i < numberofKnight - 1; i++)
        {
            newKnight[i] = Knight[i+1];
        }
        numberofKnight--;
        temp = Knight;
        Knight = newKnight;
        delete temp;
        newKnight = nullptr;
        delete newKnight;
    }
}

void ArmyKnights::fightUltimecia(Ultimecia *opponent)
{
    if (ExcaliburSword != true)
    {
        if (PaladinShield == true && LancelotSpear == true && GuinevereHair == true)
        {
            int temp = numberofKnight;
            for(int i = temp - 1; i >= 0; i--)
            {
                if (Knight[i]->returnType() != NORMAL)
                {
                    int Dame = Knight[i]->returnbaseDame() * Knight[i]->returnhp() * Knight[i]->returnLevel();
                    opponent->hp -= Dame;
                    if (opponent->hp > 0)
                    {
                        killKnightindex(i);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (opponent->hp > 0)
            {
                int temp = numberofKnight;
                for(int i = 0; i < temp; i++)
                {
                    killastKnight();
                }
            }
        }
        else
        {
            int temp = numberofKnight;
            for (int i = 0; i < temp; i++)
            {
                killastKnight();
            }
        }
    }
    else
    {
        opponent->hp = 0;
    }
}

bool ArmyKnights::fightHades(BaseOpponent *opponent)
{
    if ((lastKnight()->returnLevel() == 10) || (lastKnight()->returnType() == PALADIN && lastKnight()->returnLevel() >= 8))
    {
        if (PaladinShield != true)
        {
            PaladinShield = true;
        }
        return true;
    }
    else
    {
        lastKnight()->changeHP(0);
        return false;
    }
}

void ArmyKnights::meetNina()
{
    if (lastKnight()->returnhp() < lastKnight()->returnmaxhp()/3)
    {
        if (lastKnight()->returngil() >= 50)
        {
            lastKnight()->changeHP(lastKnight()->returnhp() + lastKnight()->returnmaxhp()/5);
            if (lastKnight()->returnType() != PALADIN)
            {
                lastKnight()->changeGil(lastKnight()->returngil() - 50);
            }
        }
    }
}

void ArmyKnights::FightQueen(BaseOpponent *opponent)
{
    if (lastKnight()->returnLevel() >= opponent->level0)
    {
        int i = numberofKnight - 1, Money;
        Money = lastKnight()->returngil();
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
    if (lastKnight()->returnType() == PALADIN || lastKnight()->returnType() == LANCELOT || lastKnight()->returnLevel() >= opponent->level0)
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
        lastKnight()->changeHP(newHP);
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

bool ArmyKnights::fightOmega(BaseOpponent *opponent)
{
    if ((lastKnight()->returnhp() == lastKnight()->returnmaxhp() && lastKnight()->returnLevel() == 10) || (lastKnight()->returnType() == DRAGON))
    {
        lastKnight()->changeGil(999);
        lastKnight()->changeLevel(10);
        return true;
    }
    else
    {
        lastKnight()->changeHP(0);
        return false;
    }
}

bool ArmyKnights::fight(BaseOpponent * opponent)
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
        if (fightOmega(opponent) == true)
        {
            meetOmega = 1;
        }
    }
    else if (opponent->id == 11)
    {
        if (fightHades(opponent) == true)
        {
            meetHades = 1;
        }
    }
    else if (opponent->id == 99)
    {
        Ultimecia *evilWitch;
        evilWitch = new Ultimecia();
        fightUltimecia(evilWitch);
    }
    //Check last Knight
    if (opponent->id != 99)
    {
        if (lastKnight()->returnhp() > 0)
        {
            lastKnight()->useotPhoenix(lastKnight());
            return true;
        }
        else
        {
            bool check = lastKnight()->revKnight();
            if (check == true)
            {
                return true;
            }
            else
            {
                killastKnight();
                return false;
            }
        }
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

bool ArmyKnights::adventure(Events * events)
{
    if (events->eventNow == events->num_of_events - 1)
    {
        return true;
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
    this->baseDame = 0.06;
    bag = new BaseBag();
    this -> bag -> maxInvent = -1;
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
    this->baseDame = 0.05;
    bag = new BaseBag();
    this -> bag -> maxInvent = 16;
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
    this->baseDame = 0.075;
    bag = new BaseBag();
    this -> bag -> maxInvent = 14;
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
    bag = new BaseBag();
    this -> bag -> maxInvent = 19;
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

Omega::Omega()
{
    this -> id = 10;
}

Hades::Hades()
{
    this -> id = 11;
}

Ultimecia::Ultimecia()
{
    this -> id = 99;
    this -> hp = 5000;
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
    BaseKnight * lastKnight;
    lastKnight = armyKnights->lastKnight();
    bool checkCont;
    for (int run = 0; run < events -> num_of_events; run++)
    {
        events->eventNow = run;
        switch(events -> events[run])
        {
            case 1:
            {
                MadBear *Bear;
                Bear = new MadBear(Bear->level0Calc(run, 1));
                armyKnights->fight(Bear);
                delete Bear;
                break;
            }
            case 2:
            {
                Bandit *Theft;
                Theft = new Bandit(Theft->level0Calc(run, 2));
                armyKnights ->fight(Theft);
                delete Theft;
                break;
            }
            case 3:
            {
                LordLupin *Lord;
                Lord = new LordLupin(Lord->level0Calc(run, 3));
                armyKnights -> fight(Lord);
                delete Lord;
                break;
            }
            case 4:
            {
                Elf *magicCreture;
                magicCreture = new Elf(magicCreture->level0Calc(run, 4));
                armyKnights -> fight(magicCreture);
                delete magicCreture;
                break;
            }
            case 5:
            {
                Troll *Bigguy;
                Bigguy = new Troll(Bigguy->level0Calc(run, 5));
                armyKnights->fight(Bigguy);
                delete Bigguy;
                break;
            }
            case 6:
            {
                BaseOpponent *Ghost;
                Ghost = new Tornbery(Ghost->level0Calc(run,6));
                armyKnights->fight(Ghost);
                delete Ghost;
                break;
            }
            case 7:
            {
                cardQueen *Queen;
                Queen = new cardQueen(Queen->level0Calc(run, 7));
                armyKnights->fight(Queen);
                delete Queen;
                break;
            }
            case 8:
            {
                armyKnights->meetNina();
                armyKnights->lastKnight()->useotPhoenix(armyKnights->lastKnight());
                break;
            }
            case 9:
            {
                events->Durian(armyKnights);
                break;
            }
            case 10:
            {
                if (armyKnights->meetOmega == 0)
                {
                    Omega *Acient_weapon;
                    Acient_weapon = new Omega();
                    armyKnights->fight(Acient_weapon);
                    delete Acient_weapon;
                }
                break;
            }
            case 11:
            {
                if (armyKnights->meetHades == 0)
                {
                    Hades *God;
                    God = new Hades();
                    armyKnights->fight(God);
                    delete God;
                }
                break;
            }
            case 112:
            {
                armyKnights->addPhoenixII();
                break;
            }
            case 113:
            {
                armyKnights->addPhoenixIII();
                break;
            }
            case 114:
            {
                armyKnights->addPhoenixIV();
                break;
            }
            case 95:
            {
                if (armyKnights->PaladinShield != true)
                {
                    armyKnights->PaladinShield = true;
                }
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
                BaseOpponent *Evilwitch;
                Evilwitch = new Ultimecia();
                armyKnights->fight(Evilwitch);
                delete Evilwitch;
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
        if (armyKnights->adventure(events) == true)
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
    return this -> eventNow;
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
        BaseItem *index;
        index = lastKnight->returnBag()->get(ANTIDOTE);
        index->use(lastKnight);
        lastKnight->returnBag()->item_to_Head(ANTIDOTE);
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


/***BEGIN all subclass of BaseItem***/

//PhoenixI
PhoenixDI::PhoenixDI()
{
    itemID = PHOENIXDI;
}

bool PhoenixDI::canUse(BaseKnight *knight)
{
    return (knight->returnhp() <= 0) && (knight->returnBag()->PhoenixI > 0);
}

void PhoenixDI::use(BaseKnight *knight)
{
    if (canUse(knight) == true)
    {
        knight->changeHP(knight->returnmaxhp());
    }
}

//PhoenixII
PhoenixDII::PhoenixDII()
{
    itemID = PHOENIXDII;
}

bool PhoenixDII::canUse(BaseKnight *knight)
{
    return (knight->returnhp() < knight->returnmaxhp()/4) && (knight->returnBag()->PhoenixII > 0);
}

void PhoenixDII::use(BaseKnight *knight)
{
    if (canUse(knight) == true)
    {
        knight->changeHP(knight->returnmaxhp());
    }
}

//PhoenixIII
PhoenixDIII::PhoenixDIII()
{
    itemID = PHOENIXDIII;
}

bool PhoenixDIII::canUse(BaseKnight *knight)
{
    return (knight->returnhp() < knight->returnmaxhp() / 3) || (knight->returnhp() <= 0) && (knight->returnBag()->PhoenixIII > 0);
}

void PhoenixDIII::use(BaseKnight *knight)
{
    if (canUse(knight) == true)
    {
        if (knight->returnhp() <= 0)
        {
            knight->changeHP(knight->returnmaxhp()/3);
        }
        else
        {
            knight->changeHP(knight->returnhp() + knight->returnmaxhp()/4);
        }
    }
}

//PhoenixIV
PhoenixDIV::PhoenixDIV()
{
    itemID = PHOENIXDIV;
}

bool PhoenixDIV::canUse(BaseKnight *knight)
{
    return (knight->returnhp() <= 0) || (knight->returnhp() < knight->returnmaxhp() / 2) && (knight->returnBag()->PhoenixIV > 0);
}

void PhoenixDIV::use(BaseKnight *knight)
{
    if (canUse(knight) == true)
    {
        if (knight->returnhp() <= 0)
        {
            knight->changeHP(knight->returnmaxhp()/2);
        }
        else
        {
            knight->changeHP(knight->returnhp() + knight->returnmaxhp()/5);
        }
    }
}

//Antidote
Antidote::Antidote()
{
    itemID = ANTIDOTE;
}

bool Antidote::canUse(BaseKnight *knight)
{
    return knight->returnBag()->antidote > 0;
}

void Antidote::use(BaseKnight *knight)
{
    if (canUse(knight) == true)
    {

    }
}

/***END all subclass of BaseItem***/