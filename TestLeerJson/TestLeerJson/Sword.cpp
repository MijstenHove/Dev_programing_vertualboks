#include "Sword.h"


Sword::Sword() {





}

Sword* Sword::Parse(Json::Value ToJsonValue) 
{

    Sword* newSword = new Sword();

    newSword->type = (Type)JsonValue["type"].asInt();


}