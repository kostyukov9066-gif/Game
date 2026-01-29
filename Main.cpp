#include <iostream>
#include "windows.h"
#include "MainClass.h"
#include "BasicClasses.h"
#include "Evil.h"

using namespace std;

enum class ValueQuality
{
    мусор, обычное, редкое, легендарное, мифическое // качество 
};

enum class WeaponClass
{
    Щит, Посох, Меч, лук, арбалет // оружие
};
enum class SpalloClass
{
    дождь_стрел, метеорит, торнадо, лозы, святая_молитва
};

enum class CharacterType
{
    UNKNOWN = 0,
    WARRIOR,
    WIZARD,
    PALADIN
};

struct Weapon
{
    string name{ "Оружие" };
    WeaponClass wclass = WeaponClass::Щит;
    unsigned int price{ 0 };
    string valueSite[5]{ "Щит","Посох","Меч","Лук","Арбалет" };
    string site{ NULL };
    unsigned short damage{ 1 };
    Weapon(WeaponClass wclass)
    {
        switch (wclass)
        {
        case WeaponClass::Щит:
            cout << "Щит\n";
            break;
        case WeaponClass::Посох:
            cout << "Посох\n";
            break;
        case WeaponClass::Меч:
            cout << "Меч\n";
            break;
        case WeaponClass::лук:
            cout << "Лук\n";
            break;
        case WeaponClass::арбалет:
            cout << "Арбалет\n";
            break;
        default:
            break;
        }
    };
};
struct Spallo
{
    string name{ "Магия" };
    SpalloClass sclass = SpalloClass::дождь_стрел;
    unsigned int price{ 0 };
    Spallo(SpalloClass sclass)
    {
        switch (sclass)
        {
        case SpalloClass::дождь_стрел:
            cout << "\n";
            break;
        case SpalloClass::метеорит:
            cout << "\n";
            break;
        case SpalloClass::торнадо:
            cout << "\n";
            break;
        case SpalloClass::лозы:
            cout << "\n";
            break;
        case SpalloClass::святая_молитва:
            cout << "\n";
            break;
        default:
            break;
        }
    };
};

struct Treasure //по умолчанию все внутри public
{
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::мусор;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::мусор:
            cout << "Плохое качество\n";
            break;
        case ValueQuality::обычное:
            cout << "Обычное качество\n";
            break;
        case ValueQuality::редкое:
            cout << "Хорошое качество\n";
            break;
        case ValueQuality::легендарное:
            cout << "Отличное качество\n";
            break;
        case ValueQuality::мифическое:
            cout << "Лучшее качество\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure //наследование по умолчанию public
{
    Cloth(ValueQuality quaity) : Treasure(quality) {};
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","наплечники" };
    string site{ NULL };
    unsigned short armor{ 1 };
};

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::WARRIOR:
        return make_unique<Warrior>();
        break;
    case CharacterType::WIZARD:
        return make_unique<Wizard>();
        break;
    case CharacterType::PALADIN:
        return make_unique<Paladin>();
        break;
    default:
        invalid_argument(" Неизвестный тип персонажа ");
        break;
    }
}

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player* player = new Player();

    cout << "Привет, путишественник\nПрисядь у костра, поведай о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";
    if (TestChoise(2, "Наверное ты ошибся, повтори снова\n"))
    {
        cout << "Какой у тебя класс?\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, "Такого еще не было в наших краях\nНе мог бы ты повторить\n"))
        {
        case 1:
            character = CreateCharacter(CharacterType::WARRIOR);
            break;
        case 2:
            character = CreateCharacter(CharacterType::WIZARD);
            break;
        case 3:
            character = CreateCharacter(CharacterType::PALADIN);
            break;
        }
        player->Create(move(character));
    }
    else
    {
        ifstream loadSystem("save.bin", ios::binary);
        if (!loadSystem.is_open())
        {
            {
                size_t nameLenght;
                loadSystem.read(reinterpret_cast<char*>(&nameLenght), sizeof(nameLenght));
                char* buffer = new char[nameLenght + 1];
                loadSystem.read(buffer, nameLenght);
                buffer[nameLenght] = '\0';

                return loadSystem.good();
            }
        }
    }
    
    return 0;
}

unsigned short GetChoice(unsigned short first, unsigned short last)
{
    unsigned short choice;
    cin >> choice;
    while (choice < first || choice > last) {
        cout << "Неверный ввод! Введите число от " << first << " до " << last;
        cout << endl;
        cin >> choice;
    }
    return choice;

}
