

class Weapon {
public:
    enum Type { Unknown = 0, Sword = 1, Lance = 2 };
    Type type = Unknown;

    int damage = 0;
    int range = 0;


    virtual void Parse(Json::Value jsonValue) {

        try {
            Type newtype = (Type)jsonValue["type"], asInt();

            switch (type)
            {
            case Weapon::Unknown:
                break;
                case Weapon::Sword::Parse(jsonValue);
                break;
                case Weapon::Lance::Parse(jsonValue);
                break;

            }
        }
        catch (const std::exception&)
        {
            return nullptr;
        }
    };
    virtual Json::Value ToJsonValue() = 0;
};