#pragma once
#include "MainClass.h"
#include "string"

class Warrior : public virtual Npc 
{
protected:  
    unsigned short strenght{ 31 };
    string weapons[4] = { "кинжал", "дубинка", "клинок", "меч" };
public:
    bool Save() override;
    bool Load() override;
    Warrior();
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo();
    void Create() override;

    bool operator == (const Warrior& warrior) const;
    Warrior& operator = (const Npc& npc);

    ~Warrior();
};

class Wizard : public virtual Npc
{

    class Spell
    {
    protected:
        string name{ "заклинание" };
        unsigned short damage{ 0 };
        unsigned short price{ 0 };
        bool isCurse{ false };
        int timeCast{ 0 };

    public:
        Spell(string name = "заклинание", unsigned short damage = 0,
        unsigned short price = 0, bool isCurse = false, int timeCast = 0);

        string GetName() const { return name; }
        unsigned short GetDamage() const { return damage; }
        unsigned short GetPrice() const { return price; }
        bool IsCurse() const { return isCurse; }
        int GetTimeCast() const { return timeCast; }

        unsigned short CastSpell();
    };
protected:
    unsigned short intellect = 27;
    Spell spells[5] = {
        Spell("Давление", 20,30,false,20),
        Spell("Священные цепи", 100,50,false,40),
        Spell("Окаменение", 15,30,false,35),
        Spell("Иллюзия", 5,20,false,60),
        Spell("Священый меч экскалибур", 1000,100,false,90),
    };
public:
    Wizard()
    {
        name = "Волшебник";
        health = 20;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo();
    void GetSpellInfo();
    void Create() override;
    bool operator == (const Wizard& wizard) const;
    void operator = (Npc npc);
    bool Save() override;
    bool Load() override;
    ~Wizard(); //деструктор всегда без аргументов
};

class Paladin : public Warrior, public Wizard
{
public:
    Paladin();
    void GetInfo();
    void Create() override;
    bool operator == (const Paladin& paladin) const;
    Paladin& operator = (const Npc& npc);
    bool Save() override;
    bool Load() override;
};
