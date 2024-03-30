#include <iostream>


class DbConnection
{
private:
    static DbConnection* instance;

    DbConnection()
    {}

public:
    static DbConnection* getInctance()
    {
        if (DbConnection::instance == nullptr)
            DbConnection::instance = new DbConnection();

        return DbConnection::instance;
    }



    void connect()
    {
        std::cout << "connect()\n";
    }
};

DbConnection* DbConnection::instance = nullptr;







int main()
{
    DbConnection* conn1 = DbConnection::getInctance();
    DbConnection* conn2 = DbConnection::getInctance();
    DbConnection* conn3 = DbConnection::getInctance();

    std::cout << conn1 << '\n';
    std::cout << conn2 << '\n';
    std::cout << conn3 << '\n';

    DbConnection* hackDb = new DbConnection{ *conn1 };
    std::cout << hackDb << '\n';
}

