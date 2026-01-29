#pragma once
#include "MainClass.h"
#include <iostream>

class Evil : public Npc 
{ public:
    Evil(const std::string& name);
    Evil(const std::string& name, unsigned int health);
    Evil(const std::string& name, unsigned int health, float damage);
    void GetInfo();
};
