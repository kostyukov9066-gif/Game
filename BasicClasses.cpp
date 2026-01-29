#include "BasicClasses.h"

bool Warrior::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (Npc::Save())
        {
            cout << "сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "сохранение не удалось" << endl;
        return false;
    }

};
bool Warrior::Load()
{
    ifstream loadSystem("save.bin", ios::binary);

    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "связь с базой нарушена\nПамять утерена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));

    }
    else
    {
        cout << "связь с базой нарушена\nПамять утерена" << endl;
        return false;
    }
    loadSystem.close();
    return true;


};
Warrior::Warrior() //конструктор по умолчанию, когда нет аргументов
{
    name = "воин";
    health = 25;
    damage = 4;
}

Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Warrior::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Warrior::Create()
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Warrior::operator == (const Warrior& warrior) const
{
    return (warrior.damage == this->damage) &&
        (warrior.health == this->health) &&
        (warrior.strenght == this->strenght);
}
Warrior& Warrior::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        return *this;
    }

}

Warrior::~Warrior() 
{
    cout << name << " Пал в бою" << endl;
}

Wizard::Spell::Spell(string name, unsigned short damage,
    unsigned short price, bool isCurse, int timeCast)
    : name(name), damage(damage), price(price),
    isCurse(isCurse), timeCast(timeCast)
{
}

unsigned short Wizard::Spell::CastSpell()
{
    return 0;
}

bool Wizard::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "сохранение не удалось" << endl;
        return false;
    }
}
bool Wizard::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "связь с базой нарушена\nПамять утерена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "связь с базой нарушена\nПамять утерена" << endl;
        return false;
    }
}
void Wizard::GetInfo() //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные заклинания в книге заклинаний - ";

}
void Wizard::GetSpellInfo()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " Заклинание: " << spells[i].GetName()
            << ", Урон: " << spells[i].GetDamage()
            << ", Цена: " << spells[i].GetPrice() << endl;
    }
}

void Wizard::Create()
{
    cout << "Вы создали волшебника" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();

}
bool Wizard::operator == (const Wizard& wizard) const
{
    return ((wizard.damage == this->damage) && (wizard.health == this->health)
        && (wizard.intellect == this->intellect));
}
void Wizard::operator = (Npc npc)
{
    this->name = npc.GetName();
    this->name = npc.GetHealth();
    this->name = npc.GetDamage();
    this->name = npc.GetLvl();
}

Wizard::~Wizard() //деструктор всегда без аргументов
{
    cout << name << " испустил дух" << endl;
}

Paladin::Paladin()
{
    name = "паладин";
    health = 35;
    damage = 3;
    strenght = 27;
    intellect = 15;
}
void Paladin::GetInfo()
{
    cout << "Имя - " << name << endl;
    cout << "Здоровье - " << health << endl;
    cout << "Урон - " << damage << endl;
    cout << "Сила - " << strenght << endl;
    cout << "Интеллект - " << intellect << endl;
}

void Paladin::Create()
{
    cout << "Вы создали паладина" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();  
}

bool Paladin::operator == (const Paladin& paladin) const
{
    return (paladin.damage == this->damage) &&
        (paladin.health == this->health) &&
        (paladin.strenght == this->strenght) &&
        (paladin.intellect == this->intellect);
}

Paladin& Paladin::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        this->strenght = 27;  
        this->intellect = 15; 
    }
    return *this;
}
bool Paladin::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
        saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "Сохранение не удалось" << endl;
        return false;
    }
}

bool Paladin::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Связь с небом нарушена\nПамять утерена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "Связь с небом нарушена\nПамять утерена" << endl;
        return false;
    }
}
