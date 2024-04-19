#include <iostream>


class ICore
{
public:
    virtual void sendToUser(std::string message) = 0;
};

class TelegramCore : public ICore
{
public:
    virtual void sendToUser(std::string message) override
    {
        std::cout << "Telegram --> " << message << '\n';
    }
};

class EmailCore : public ICore
{
public:
    virtual void sendToUser(std::string message) override
    {
        std::cout << "Email --> " << message << '\n';
    }
};



class INotifier
{
public:
    virtual void setCore(ICore* core) = 0;
    virtual void send(std::string message) = 0;
};

class SpamNotifier : public INotifier
{
private:
    ICore* core;
public:
    SpamNotifier(ICore* core):
        core{core}
    {}
    virtual void setCore(ICore* core) override
    {
        this->core = core;
    }
    virtual void send(std::string message) override
    {
        core->sendToUser(message);                      // :-)
    }
};



int main()
{
    INotifier* notifier = new SpamNotifier{ new TelegramCore{} };
    notifier->send("hello from Vasia");

    notifier->setCore(new EmailCore{});
    notifier->send("hello from Vasia");
}

