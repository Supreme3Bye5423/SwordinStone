#include "knight2.h"

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

}

bool ArmyKnights::fight(BaseOpponent*opponent)
{

}

ArmyKnights::ArmyKnights(const string & file_armyknights)
{

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

/* * * BEGIN implementation of class KnightAdventure * * */

KnightAdventure::KnightAdventure(){

}

KnightAdventure:: ~KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

void KnightAdventure::loadArmyKnights(const string & file_ArmyKnights)
{

}

void KnightAdventure::loadEvents(const string & file_Events)
{
    events = new Events(file_Events);
}

void KnightAdventure::run()
{

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
    //new 
    ifstream openfile;
    openfile.open(file_Events);
    openfile >> this -> num_of_events;
    this -> events = new int[this -> num_of_events];
    for (int i = 0; i < this -> num_of_events; i++)
    {
        openfile >> this -> events[i];
        cout << this -> events[i];
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