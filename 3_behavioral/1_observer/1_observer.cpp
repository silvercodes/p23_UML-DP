#include <iostream>
#include <list>
#include <sstream>

class IObserver
{
public:
    virtual void update(std::string message) const = 0;
};

class IPublisher
{
protected:
    virtual void notifyObservers(std::string message) = 0;
public:
    virtual void subscribe(IObserver* observer) = 0;
    virtual void unsubscribe(IObserver* observer) = 0;
    
};



struct Product
{
    std::string title;
    int price;
};

class ShopDB: public IPublisher
{
private:
    std::list<IObserver*> observers;
    std::list<Product> products;

    virtual void notifyObservers(std::string message) override
    {
        for (const IObserver* observer : this->observers)
        {
            observer->update(message);
        }
    }

public:
    void addProduct(const Product& p)
    {
        products.push_back(p);

        if (!this->observers.empty())
        {
            std::stringstream stream;
            stream << "New product: " << p.title << ": " << p.price;

            notifyObservers(stream.str());
        }
    }

    virtual void subscribe(IObserver* observer) override
    {
        this->observers.push_back(observer);
    }
    virtual void unsubscribe(IObserver* observer) override
    {
        this->observers.remove(observer);
    }
    
};


class User: public IObserver
{
private:
    std::string email;
public:
    User(std::string email):
        email{email}
    {}

    virtual void update(std::string message) const override
    {
        std::cout << "User " << this->email << " received: " << message << '\n';
    }
};

class Company : public IObserver
{
private:
    std::string title;
public:
    Company(std::string title):
        title{title}
    {}

    virtual void update(std::string message) const override
    {
        std::cout << "Company " << this->title << " received: " << message << '\n';
    }
};



int main()
{
    ShopDB* shop = new ShopDB{};

    shop->subscribe(new User{ "vasia@mail.com" });
    shop->subscribe(new User{ "petya@mail.com" });
    shop->subscribe(new User{ "dima@mail.com" });
    
    
    shop->subscribe(new Company{ "Company_1" });
    shop->subscribe(new Company{ "Company_2" });


    shop->addProduct({ "apple", 80 });
    shop->addProduct({ "table", 2000 });




}

