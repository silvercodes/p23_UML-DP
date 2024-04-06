#include <iostream>
#include <unordered_map>
#include <vector>


class IPrototype
{
public:
    virtual IPrototype* clone() = 0;
    virtual void Render() = 0;

    virtual ~IPrototype()
    {}
};


class Tree: public IPrototype
{
    //
    //
    //
    //
public:
    virtual IPrototype* clone() override
    {
        return new Tree{};
    }
    virtual void Render() override
    {
        std::cout << "Tree: " << this << '\n';
    }
};

class Stone : public IPrototype
{

public:
    virtual IPrototype* clone() override
    {
        return new Stone{};
    }
    virtual void Render() override
    {
        std::cout << "Stone: " << this << '\n';
    }
};


enum PROTO_ID
{
    TREE,
    STONE,
};

class PrototypeRepository
{
public:
    std::unordered_map<PROTO_ID, IPrototype*> store;

    void init()
    {
        store = {
            {PROTO_ID::TREE, new Tree{}},
            {PROTO_ID::STONE, new Stone{}},
        };
    }

    IPrototype* getClone(PROTO_ID id)
    {
        return this->store[id]->clone();                    // :-)
    }
};



int main()
{
    //Tree* tree = new Tree{};
    //tree->Render();

    //IPrototype* clone;
    //for (int i{}; i < 10; ++i)
    //{
    //    clone = tree->clone();
    //    clone->Render();

    //    // delete clone;
    //}


    PrototypeRepository* repo = new PrototypeRepository{};
    repo->init();

    std::vector<IPrototype*> models;

    for (int i{}; i < 50; ++i)
        models.push_back(repo->getClone(PROTO_ID::TREE));

    for (IPrototype* t : models)
        t->Render();
}

