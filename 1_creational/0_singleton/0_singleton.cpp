#include <iostream>


//class DbConnection
//{
//private:
//    static DbConnection* instance;
//
//    DbConnection()
//    {}
//
//public:
//    static DbConnection* getInctance()
//    {
//        if (DbConnection::instance == nullptr)
//            DbConnection::instance = new DbConnection();
//
//        return DbConnection::instance;
//    }
//
//    DbConnection(const DbConnection&) = delete;
//    DbConnection& operator=(const DbConnection&) = delete;
//
//    void connect()
//    {
//        std::cout << "connect()\n";
//    }
//};
//
//DbConnection* DbConnection::instance = nullptr;
//
//
//int main()
//{
//    DbConnection* conn1 = DbConnection::getInctance();
//    DbConnection* conn2 = DbConnection::getInctance();
//    DbConnection* conn3 = DbConnection::getInctance();
//
//    std::cout << conn1 << '\n';
//    std::cout << conn2 << '\n';
//    std::cout << conn3 << '\n';
//
//    // DbConnection* hackDb = new DbConnection{ *conn1 };  :-(
//    // std::cout << hackDb << '\n';
//}





class IRenderable
{
public:
	virtual std::string getInfo() = 0;
};

class Unit : public IRenderable
{
public:
	std::string getInfo() override
	{
		return "Unit info";
	}
};

class Tree : public IRenderable
{
public:
	std::string getInfo() override
	{
		return "Tree info";
	}
};


class Renderer
{
private:
	static Renderer* instance;
	Renderer()
	{}
public:
	static Renderer* getInstance()
	{
		if (Renderer::instance == nullptr)
			Renderer::instance = new Renderer{};

		return Renderer::instance;
	}

	void Render(IRenderable* renderable)
	{
		std::cout << renderable->getInfo() << '\n';
	}
};

Renderer* Renderer::instance = nullptr;



int main()
{
	Renderer* renderer = Renderer::getInstance();
	std::cout << renderer << '\n';
	renderer->Render(new Unit());

	Renderer* renderer2 = Renderer::getInstance();
	std::cout << renderer2 << '\n';
	renderer->Render(new Tree());
}


