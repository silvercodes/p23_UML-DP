#include <iostream>

class IBike
{
public:
    virtual std::string getTitle() = 0;
};

class SportBike : public IBike
{
public:
    virtual std::string getTitle() override
    {
        return "Sport bike";
    }
};

class ElectroBike : public IBike
{
public:
    virtual std::string getTitle() override
    {
        return "Electro bike";
    }
};

class EnduroBike : public IBike
{
public:
    virtual std::string getTitle() override
    {
        return "Enduro bike";
    }
};

class HarleyBike : public IBike
{
public:
    virtual std::string getTitle() override
    {
        return "Harley bike";
    }
};


class Creator                          // CREATOR
{
public:
    //
    //
    virtual IBike* createBike() = 0;                // FACTORY METHOD
    void go()
    {
        IBike* bike = this->createBike();
        std::cout << bike->getTitle() << '\n';
    }
    //
    //
};

class SportBikeCreator : public Creator
{
public:
    virtual IBike* createBike() override            // FACTORY METHOD
    {
        return new SportBike{};
    }
};

class ElectroBikeCreator : public Creator
{
public:
    virtual IBike* createBike() override            // FACTORY METHOD
    {
        return new ElectroBike{};
    }
};

class EnduroBikeCreator : public Creator
{
public:
    virtual IBike* createBike() override            // FACTORY METHOD
    {
        return new EnduroBike{};
    }
};

class HarleyBikeCreator : public Creator
{
public:
    virtual IBike* createBike() override            // FACTORY METHOD
    {
        return new HarleyBike{};
    }
};



enum BType
{
    SPORT,
    ELECTRO,
    ENDURO,
    HARLEY,
};

class Game
{
public:
    Creator* creator = nullptr;

    void setCreator(BType btype)
    {
        switch (btype)
        {
        case BType::SPORT:
            this->creator = new SportBikeCreator{};
            break;
        case BType::ELECTRO:
            this->creator = new ElectroBikeCreator{};
            break;
        case BType::ENDURO:
            this->creator = new EnduroBikeCreator{};
            break;
        case BType::HARLEY:
            this->creator = new HarleyBikeCreator{};
            break;
        default:
            throw new std::runtime_error("Runtime error...");
        }
    }

    void start()
    {
        this->creator->go();
    }
};


int main()
{
    Game* game = new Game{};

    game->setCreator(BType::HARLEY);

    game->start();
}

