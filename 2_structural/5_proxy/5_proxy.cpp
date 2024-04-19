#include <iostream>
#include <fstream>

class ILogger
{
public:
    virtual void log(std::string message) = 0;
};


class FileLogger : public ILogger
{
private:
    std::string filePath;
public:
    FileLogger(std::string filePath):
        filePath{filePath}
    {}
    virtual void log(std::string message) override
    {
        std::ofstream file;
        file.open(this->filePath, std::ios::app);

        time_t now = time(0);
        char str[26];
        ctime_s(str, sizeof str, &now);

        file << str << '\t';
        file << message << "\n\n";

        file.close();
    }
};


class IService
{
public:
    virtual std::string execute() = 0;
};

class Service : public IService
{
public:
    virtual std::string execute() override
    {
        return "Data from service";
    }
};

class ProxyServer : public IService
{
private:
    IService* service;
    ILogger* logger;

public:
    ProxyServer(IService* service, ILogger* logger):
        service{service},
        logger{logger}
    {}

    virtual std::string execute() override
    {
        std::string data = service->execute();

        logger->log(data);

        return data;
    }
};


int main()
{
    IService* service = new ProxyServer{ new Service{}, new FileLogger{"log.txt"} };

    std::string data = service->execute();
    std::cout << "DATA: " << data << '\n';


}

