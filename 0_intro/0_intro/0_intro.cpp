#include <iostream>

// ООП
// Наследование
// Инкапсуляция
// Полиморфизм
// Абстракция


// Принципы хорошей разработки
// 1. Переиспользование кода
// 2. Расширяемость

// Правила (основные)
// 1. Инкапсуляция изменений
// 2. Программирование на интерфейсах
// 3. Композиция(агрегация) лучше, чем наследование

// SOLID
// S ---> Single Responsibility Principle
// O ---> Open / Closed principle
// L ---> Принцип подстановки Лисков
// I ---> Принцип разделения интерфейсов
// D ---> Принцип инверсии зависимости


class ILogger
{
public:
    virtual void read() = 0;
    virtual void write() = 0;
};

class ICompressor
{
public:
    virtual void zip() = 0;
};

class ISender
{
public:
    virtual void send() = 0;
};

class IEncoder
{
public:
    virtual void encode() = 0;
    virtual void decode() = 0;
};


class FileLogger: public ILogger, public ICompressor
{

};

class NetworkLogger: public ILogger, public ICompressor, public ISender, public IEncoder
{

};





















int main()
{
    std::cout << "Hello World!\n";
}

