//
// Created by Hugo-Jean Egu on 21/04/2020.
//

#ifndef EXERCICE1_WARRIOR_H
#define EXERCICE1_WARRIOR_H
#pragma once

using namespace std;

class Warrior {

protected:
    int _hp;
    int _initialHp;
    int _dmg;
    string _weapon;
    bool _buckler;
    int _bucklerDurability;
    bool _blowOneTimeOfTwo;
    bool _armor;
    int _count;
    string _type;
    int _typeCount;

public:

    Warrior(int hp, int dmg, string weapon) {
        _hp = hp;
        _dmg = dmg;
        _buckler = false;
        _bucklerDurability = 0;
        _weapon = weapon;
        _armor = false;
        _count = 0;
    }

    Warrior(int hp, int dmg, string weapon, string type) {
        _hp = hp;
        _initialHp = hp;
        _dmg = dmg;
        _buckler = false;
        _bucklerDurability = 0;
        _weapon = weapon;
        _armor = false;
        _count = 0;
        _type = type;
        _typeCount = 2;
    }

    void Equip(const string stuff) {
        if(stuff == "buckler") {
            this->setBuckler(true);
            this->setBucklerDurability(3);
        }
        if (stuff == "armor") {
            this->setDmg(this->getDmg()-1);
            this->setArmor(true);
        }
        if (stuff == "axe") {
            this->setWeapon("Axe");
        }
    }

    void ExecuteAttackIfBlowNotAvailable(Warrior *pWarrior, int dmg) {

        if(this->getType() == "Vicious" && this->getTypeCount() > 0) {
            dmg += 20;
            this->setTypeCount(this->getTypeCount()-1);
        }

        if(pWarrior->getType() == "Veteran" && pWarrior->HitPoints() < (pWarrior->getInitialHp()*0.3)) {
            dmg = dmg*2;
        }

        if(pWarrior->isArmor()) {
            dmg -= 3;
        }

        if (dmg >= pWarrior->HitPoints()) {
            pWarrior->setHp(0);
        } else {
            pWarrior->setHp(pWarrior->HitPoints() - dmg);
        }
    }

    void executeAttackCheck(Warrior *pWarrior, int dmg) {
        if(pWarrior->isBuckler()) {
            if (pWarrior->isBlowOneTimeOfTwo()) {
                if(pWarrior->getBucklerDurability() == 0) {
                    pWarrior->setBuckler(false);
                    ExecuteAttackIfBlowNotAvailable(pWarrior, dmg);
                }
                else if (pWarrior->getBucklerDurability() > 0 && (pWarrior->getWeapon() == "Great Sword" || pWarrior->getWeapon() == "Sword") && this->getWeapon() == "Axe") {
                    pWarrior->setBucklerDurability(pWarrior->getBucklerDurability()-1);
                }
                pWarrior->setBlowOneTimeOfTwo(false);
            }
            else {
                ExecuteAttackIfBlowNotAvailable(pWarrior, dmg);
                pWarrior->setBlowOneTimeOfTwo(true);
            }
        } else {
            ExecuteAttackIfBlowNotAvailable(pWarrior, dmg);
        }
    }

    void executeAttack(Warrior *pWarrior, int dmg) {
        if (this->getWeapon() == "Great Sword" && dmg == 12) {
            if (getCount() % 3 != 0) {
                executeAttackCheck(pWarrior, dmg);
            }
            setCount(getCount()+1);
        } else {
            executeAttackCheck(pWarrior, dmg);
        }
    }

    void receiveAttack(int dmg) {
        executeAttack(this, dmg);
    }

    void attack(Warrior *pWarrior, int dmg) {
        executeAttack(pWarrior, dmg);
    }

    void Engage(Warrior &warrior) {
        while (warrior.HitPoints() > 0 && this->HitPoints() > 0) {
            warrior.receiveAttack(this->_dmg);
            warrior.attack(this, warrior.getDmg());
        }
    }

    int HitPoints() const {
        return _hp;
    }

    void setHp(int hp) {
        Warrior::_hp = hp;
    }

    int getCount() const {
        return _count;
    }

    void setCount(int count) {
        Warrior::_count = count;
    }

    int getDmg() const {
        return _dmg;
    }

    void setDmg(int dmg) {
        Warrior::_dmg = dmg;
    }

    const string &getWeapon() const {
        return _weapon;
    }

    void setWeapon(const string &weapon) {
        _weapon = weapon;
    }

    bool isBuckler() const {
        return _buckler;
    }

    void setBuckler(bool buckler) {
        _buckler = buckler;
    }

    int getBucklerDurability() const {
        return _bucklerDurability;
    }

    void setBucklerDurability(int bucklerDurability) {
        _bucklerDurability = bucklerDurability;
    }

    bool isBlowOneTimeOfTwo() const {
        return _blowOneTimeOfTwo;
    }

    void setBlowOneTimeOfTwo(bool timeAttack) {
        _blowOneTimeOfTwo = timeAttack;
    }

    bool isArmor() const {
        return _armor;
    }

    void setArmor(bool armor) {
        _armor = armor;
    }

    const string &getType() const {
        return _type;
    }

    void setType(const string &type) {
        _type = type;
    }

    int getTypeCount() const {
        return _typeCount;
    }

    void setTypeCount(int typeCount) {
        _typeCount = typeCount;
    }

    int getInitialHp() const {
        return _initialHp;
    }

    void setInitialHp(int initialHp) {
        _initialHp = initialHp;
    }

};

#endif //EXERCICE1_WARRIOR_H