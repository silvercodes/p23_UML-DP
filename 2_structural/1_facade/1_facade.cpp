#include <iostream>

class SmartLamp
{
public:
    void switchOn()
    {
        std::cout << "SmartLamp switched On\n";
    }
    void switchOff()
    {
        std::cout << "SmartLamp switched Off\n";
    }
};

class AC
{
public:
    void switchOn()
    {
        std::cout << "AC switched On\n";
    }
    void switchOff()
    {
        std::cout << "AC switched Off\n";
    }
};

class Teepot
{
public:
    void switchOn()
    {
        std::cout << "Teepot switched On\n";
    }
    void switchOff()
    {
        std::cout << "Teepot switched Off\n";
    }
};

// FACADE
class ControlBlockScenariosManager
{
private:
    SmartLamp* lamp;
    AC* ac;
    Teepot* teepot;

public:
    ControlBlockScenariosManager(SmartLamp* lamp, AC* ac, Teepot* teepot):
        lamp{lamp},
        ac{ac},
        teepot{teepot}
    {}

    void executeAwayScenario()
    {
        lamp->switchOff();
        ac->switchOff();
        teepot->switchOff();
    }

    void executeIncomeScenario()
    {
        lamp->switchOn();
        ac->switchOn();
        teepot->switchOn();
    }
};



int main()
{
    ControlBlockScenariosManager* manager = new ControlBlockScenariosManager(new SmartLamp{}, new AC{}, new Teepot{});

    manager->executeAwayScenario();
    manager->executeIncomeScenario();
}

