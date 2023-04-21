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

//Read armyKnight file

ArmyKnights::ArmyKnights(const string & file_armyknights)
{
    ifstream openfile;
    openfile.open(file_armyknights);
    int numberofKnight;
    openfile >> numberofKnight;
    for (int Knightquantity = 0; Knightquantity < numberofKnight; Knightquantity++)
    {
        
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

/* * * BEGIN implementation of class KnightAdventure * * */

KnightAdventure::KnightAdventure(){

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