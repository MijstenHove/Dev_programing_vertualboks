#include "Weapon.h"

class Weapon
{
    static void Weapon* Weapon::Parse(Json::Value jsonValue);
};

Weapon* Weapon::Parse(Json::Value ToJsonValue) {
    try
    {
        Type newtype = (type)jsonValue["type"].asint

            Weapon * newWeapon = nullptr;

        switch (newtype)
        {
        default:
            break;
        }

    }
    catch (const std::exception&)
    {

    }


}