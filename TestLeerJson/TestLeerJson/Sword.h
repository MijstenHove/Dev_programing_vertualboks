#pragma once

#include "Weapon.h"
class Sword:
{
public:
    Sword();

    static Sword* Parse();

    Json::Value ToJsonValue();

}