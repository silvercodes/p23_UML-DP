#include <iostream>
#include <vector>


class IGraphic
{
public:
    virtual void render() = 0;
    virtual ~IGraphic() {}
};


class Triangle: public IGraphic
{
public:
    virtual void render() override
    {
        std::cout << "triangle\n";
    }
};


class Mesh: public IGraphic
{
private:
    std::vector<IGraphic*> list;

public:
    virtual void render() override
    {
        std::cout << "Mesh\n";

        for (IGraphic* g : list)                // :-)
            g->render();
    }

    void add(IGraphic* g)
    {
        this->list.push_back(g);
    }
};



int main()
{
    Triangle* a = new Triangle{};
    Triangle* b = new Triangle{};
    Triangle* c = new Triangle{};
    Triangle* d = new Triangle{};
    Triangle* e = new Triangle{};
    Triangle* f = new Triangle{};


    Mesh* r = new Mesh{};
    r->add(a);
    r->add(b);

    Mesh* q = new Mesh{};
    q->add(c);
    q->add(d);
    q->add(e);

    Mesh* k = new Mesh{};
    k->add(f);
    k->add(r);
    k->add(q);

    k->render();

}

