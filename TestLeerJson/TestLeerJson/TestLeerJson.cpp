// TestLeerJson.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <json/json.h> //https://github.com/open-source-parsers/jsoncpp
#include <vector>

using namespace std;

class Character {
public:

    int life = 0;
    int coins = 0;
    std::string name = "";
    std::vector<string>* weapons = new std::vector<string>();

    /// <summary>
    /// Create a Character object from a Json::Value
    /// </summary>
    /// <param name="jsonValue"></param>
    /// <returns></returns>
    static Character* Parse(Json::Value jsonValue)
    {
        //
        Character* newCharacter = new Character();
        try
        {
            /*newCharacter->life = jsonValue["Character"]["life"].asInt();
            newCharacter->coins = jsonValue["Character"]["coins"].asInt();
            newCharacter->name = jsonValue["Character"]["name"].asString();*/
            newCharacter->life = jsonValue["life"].asInt();
            newCharacter->coins = jsonValue["coins"].asInt();
            newCharacter->name = jsonValue["name"].asString();

            Json::Value weaponsArray = Json::Value(Json::arrayValue);
            weaponsArray = jsonValue["weapons"];

            for (int i = 0; i < weaponsArray.size(); i++)
            {
                Json::Value Weaponjson = weaponsArray[i].asString();
                Weapon* newweapon = weapon::Parse(Weaponjson);

                newCharacter->weapons->push_back(weapon);
            }

            return newCharacter;
        }
        catch (const std::exception&)
        {
            delete newCharacter;
            return nullptr;
        }
    }

    /// <summary>
    /// Create a Json::Value object from a Character
    /// </summary>
    /// <returns></returns>
    Json::Value ToJsonValue()
    {
        Json::Value jsonValue;
        /*jsonValue["Character"]["life"] = this->life;
        jsonValue["Character"]["coins"] = this->coins;
        jsonValue["Character"]["name"] = this->name;*/
        jsonValue["life"] = this->life;
        jsonValue["coins"] = this->coins;
        jsonValue["name"] = this->name;

        Json::Value weaponsArray = Json::Value(Json::arrayValue);

        for (std::string weapon : *this->weapons)
        {
            weaponsArray.append(weapon);
        }
        //jsonValue["Character"]["weapons"] = weaponsArray;
        jsonValue["weapons"] = weaponsArray;

        return jsonValue;
    }
};

int main()
{
    std::ifstream* jsonReadFile = new std::ifstream("Character.json", std::ifstream::binary); //We open the file from which we want to read

    if (!jsonReadFile->fail()) //Let's check if it has been opened correctly
    {
        Json::Value jsonValue; //We initialize the variable that stores the JSON in the form of an object
        *jsonReadFile >> jsonValue; //We load the text inside the object
        jsonReadFile->close(); //We close the file so that it does not stay open. Important!!

        //std::cout << jsonValue;

        //Character* newChar = Character::Parse(jsonValue); //   We call the static function that helps us to create an object from a JsonValue
        Character* newChar = Character::Parse(jsonValue["Character"]); //We call the static function that helps us to create an object from a JsonValue
        if (newChar != nullptr) //The above function will return a nullptr if it failed for something
        {
            newChar->coins += 5; //We add 5 to the coins

            Json::Value newJsonValue; //We declare a new JsonValue object
            newJsonValue["Character"] = newChar->ToJsonValue(); //We call a function that transforms the object into a JSON Value

            //std::cout << newJsonValue;

            std::ofstream* jsonWriteFile = new std::ofstream("Character.json", std::ifstream::binary); //We open a file in write mode

            if (!jsonWriteFile->fail()) //Let's check if it has been opened correctly
            {
                *jsonWriteFile << newJsonValue; //We write to the file
                jsonWriteFile->close(); //We close the file so that it does not stay open. Important!!
            }
        }
    }
}

/// <summary>
/// Dumb function to create the file if you have it empty
/// </summary>
void CreateBaseChar()
{
    Character* newChar = new Character();
    newChar->life = 10;
    newChar->coins = 0;
    newChar->name = "Capitana Test";
    newChar->weapons->push_back("Sword");
    newChar->weapons->push_back("Lance");

    Json::Value newJsonValue; //We declare a new JsonValue object
    newJsonValue["Character"] = newChar->ToJsonValue(); //We call a function that transforms the object into a JSON Value
    std::ofstream* jsonWriteFile = new std::ofstream("Character.json", std::ifstream::binary); //We open a file in write mode

    if (!jsonWriteFile->fail()) //Let's check if it has been opened correctly
    {
        *jsonWriteFile << newJsonValue; //We write to the file
        jsonWriteFile->close(); //We close the file so that it does not stay open. Important!!
    }
}