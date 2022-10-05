#pragma once


#include"Weapon.h"

class Swort : public Weapon {
public:
    static Swort* Parse(Json::Value jsonValue) {

    } overide;
    virtual Json::Value ToJsonValue() = 0;
}