#include <iostream>

class IArcher
{
public:
    virtual std::string getTitle() = 0;
    virtual ~IArcher()
    {}
};

class HumanArcher : public IArcher
{
    virtual std::string getTitle() override
    {
        return "Human Archer";
    }
    virtual ~HumanArcher()
    {}
};

class OrkArcher : public IArcher
{
    virtual std::string getTitle() override
    {
        return "Ork Archer";
    }
    virtual ~OrkArcher()
    {}
};


class IWarrior
{
public:
    virtual std::string getTitle() = 0;
    virtual ~IWarrior()
    {}
};

class HumanWarrior : public IWarrior
{
    virtual std::string getTitle() override
    {
        return "Human Warrior";
    }
    virtual ~HumanWarrior()
    {}
};

class OrkWarrior : public IWarrior
{
    virtual std::string getTitle() override
    {
        return "Ork Warrior";
    }
    virtual ~OrkWarrior()
    {}
};


class IMag
{
public:
    virtual std::string getTitle() = 0;
    virtual ~IMag()
    {}
};

class HumanMag : public IMag
{
public:
    virtual std::string getTitle() override
    {
        return "Human Mag";
    }
    virtual ~HumanMag()
    {}
};


class IFactory
{
public:
    virtual IArcher* createArcher() = 0;
    virtual IWarrior* createWarrior() = 0;
    virtual IMag* createMag() = 0;

    virtual ~IFactory() {};
};

class HumanFactory : public IFactory
{
    virtual IArcher* createArcher() override
    {
        return new HumanArcher{};
    }
    virtual IWarrior* createWarrior() override
    {
        return new HumanWarrior{};
    }
    virtual IMag* createMag() override
    {
        return new HumanMag{};
    }

    virtual ~HumanFactory()
    {}
};

class OrkFactory : public IFactory
{
    virtual IArcher* createArcher() override
    {
        return new OrkArcher{};
    }
    virtual IWarrior* createWarrior() override
    {
        return new OrkWarrior{};
    }
    virtual IMag* createMag() override
    {
        throw std::exception("Not implemented");
    }

    virtual ~OrkFactory()
    {}
};


void clientCode(IFactory* factory)
{
    IArcher* archer = factory->createArcher();
    IWarrior* warrior = factory->createWarrior();
    IMag* mag = factory->createMag();

    std::cout << archer->getTitle() << '\n';
    std::cout << warrior->getTitle() << '\n';
    std::cout << mag->getTitle() << '\n';
}


int main()
{
    IFactory* factory = new OrkFactory{};

    try
    {
        clientCode(factory);
    }
    catch (const std::exception& ex)
    {
        std::cout << "ERROR: " << ex.what() << '\n';
    }

    return 0;
}

