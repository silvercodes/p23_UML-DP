#include <iostream>
#include <sstream>

//class IRenderable
//{
//public:
//    virtual void render() = 0;
//};
//
//
//class TextBox: public IRenderable
//{
//private:
//    int w;
//    int h;
//
//public:
//    TextBox(int w, int h):
//        w{w},
//        h{h}
//    {}
//
//    virtual void render() override
//    {
//        std::cout << "TextBox: w: " << this->w << " h: " << this->h << '\n';
//    }
//};
//
//
//class Decorator: public IRenderable
//{
//private:
//    IRenderable* item;
//public:
//    Decorator(IRenderable* item):
//        item{item}
//    {}
//    virtual void render() override
//    {
//        item->render();
//    }
//};
//
//class BorderDecorator : public Decorator
//{
//public:
//    BorderDecorator(IRenderable* item):
//        Decorator{item}
//    {}
//    
//    virtual void render() override
//    {
//        Decorator::render();
//        std::cout << "Border decorator\n";
//    }
//};
//
//class ColoredBorderDecorator : public Decorator
//{
//private:
//    std::string color;
//public:
//    ColoredBorderDecorator(IRenderable* item, std::string color) :
//        Decorator{ item },
//        color{color}
//    {}
//
//    virtual void render() override
//    {
//        Decorator::render();
//        std::cout << color << " border\n";
//    }
//};
//
//class WithScrollDecorator : public Decorator
//{
//public:
//    WithScrollDecorator(IRenderable* item) :
//        Decorator{ item }
//    {}
//
//    virtual void render() override
//    {
//        Decorator::render();
//        std::cout << "scroll\n";
//    }
//};
//
//
//
//
//
//
//
//int main()
//{
//    /*TextBox* tb = new TextBox{180, 60};
//    tb->render();*/
//
//    /*IRenderable* tb = new TextBox{180, 60};
//    tb->render();*/
//
//
//    /*TextBox* tb = new TextBox{ 180, 60 };
//    BorderDecorator* decorator = new BorderDecorator(tb);
//
//    decorator->render();*/
//
//
//
//   /* TextBox* tb = new TextBox{ 180, 60 };
//    IRenderable* decorator = new BorderDecorator(tb);
//
//    decorator->render();*/
//
//
//    IRenderable* item = new ColoredBorderDecorator(new ColoredBorderDecorator(new TextBox{180, 60}, "red"), "blue");
//    item = new WithScrollDecorator(item);
//
//
//    item->render();
// }






// TASK
// Написать мини-приложение для пиццерии на основе паттерна Decorator
// 1. Пицца может 3-х разных размеров
// 2. Пицца имеет название (много)
// 3. Возможные ингридиенты: помидоры, сыр, грибы, сырный бортик ...
// Функционал: 
//			создать любую пиццу из ингридиентов, 
//			узнать стоимость пиццы
//			напечатать чек (состав + стоимость)


//enum SIZE
//{
//	SMALL,
//	MEDIUM,
//	BIG,
//};
//
//class IBuilderable
//{
//public:
//	int mock = 1;								// TODO: for debug !!!
//	virtual void addToPrice(int price) = 0;
//	virtual int getTotalPrice() const = 0;
//	virtual void show() const = 0;
//};
//
//class Pizza: public IBuilderable
//{
//private:
//	std::string title;
//	SIZE size;
//	int basePrice;
//	int totalPrice;
//
//public:
//	Pizza(std::string title, SIZE size, int basePrice):
//		title{title},
//		size{size},
//		basePrice{basePrice},
//		totalPrice{basePrice}
//	{}
//
//	virtual void addToPrice(int price) override
//	{
//		this->totalPrice += price;
//	}
//
//	virtual int getTotalPrice() const override
//	{
//		return this->totalPrice;									// 5
//	}
//
//	virtual void show() const override
//	{
//		std::cout << "Title: " << this->title << '\n';
//		std::cout << "Base price: " << this->basePrice << '\n';
//		std::cout << "Total price: " << this->totalPrice << '\n';
//	}
//};
//
//
//
//class Decorator : public IBuilderable
//{
//private:
//	IBuilderable* item;
//public:
//	Decorator(IBuilderable* item):
//		item{item}
//	{}
//
//	virtual int getTotalPrice() const override					
//	{
//		return this->item->getTotalPrice();							// 2(8)		// 4(6)
//	}
//
//	virtual void show() const override
//	{
//		this->item->show();
//	}
//
//protected:
//	virtual void addToPrice(int price) override
//	{
//		this->item->addToPrice(price);
//	}
//};
//
//class TomatoDecorator : public Decorator
//{
//private:
//	int price;
//public:
//	TomatoDecorator(IBuilderable* item, int price = 30) :
//		Decorator{ item },
//		price{price}
//	{
//		Decorator::addToPrice(this->price);
//	}
//
//	virtual int getTotalPrice() const override
//	{
//		return Decorator::getTotalPrice();							// 3(7)
//	}
//
//	virtual void show() const override
//	{
//		Decorator::show();
//		std::cout << "tomatos: " << this->price << '\n';
//	}
//};
//
//class CheaseBorderDecorator : public Decorator
//{
//private:
//	int price;
//public:
//	CheaseBorderDecorator(IBuilderable* item, int price = 30) :
//		Decorator{ item },
//		price{ price }
//	{
//		Decorator::addToPrice(this->price);
//	}
//
//	virtual int getTotalPrice() const override						
//	{
//		return Decorator::getTotalPrice();							// 1(9)
//	}
//
//	virtual void show() const override
//	{
//		Decorator::show();
//		std::cout << "chease borders: " << this->price << '\n';
//	}
//};
//
//
//
//int main()
//{
//	Pizza* p = new Pizza{ "Margarita", SIZE::MEDIUM, 150 };
//
//	IBuilderable* dec = new TomatoDecorator{ p, 40 };
//	
//	dec = new CheaseBorderDecorator(dec, 50);
//	dec = new CheaseBorderDecorator(dec, 50);
//	dec = new CheaseBorderDecorator(dec, 50);
//
//	std::cout << dec->getTotalPrice();
//	std::cout << "\n\n";
//	dec->show();
//
//
//	return 0;
//}







// TASK


class ILoggable
{
public:
	virtual std::string getData() = 0;
};

class Fetcher: public ILoggable
{
private:
	std::string endpoint;

public:
	Fetcher(std::string& endpoint):
		endpoint{endpoint}
	{}
	virtual std::string getData() override
	{
		std::stringstream stream;
		stream << "Data from " << this->endpoint << ": <DATA>";

		return stream.str();
	}
};


class Decorator : public ILoggable
{
private:
	ILoggable* item;
public:
	Decorator(ILoggable* item):
		item{item}
	{}

	virtual std::string getData() override
	{
		return this->item->getData();
	}
};


enum LogLevel
{
	WARNING,
	ERROR,
	CRITICAL,
};

class WithFileLog : public Decorator
{
private:
	std::string filePath;
	LogLevel level;
public:
	
	WithFileLog(ILoggable* item, std::string& filePath, LogLevel level = LogLevel::WARNING):
		Decorator{item},
		filePath{filePath},
		level{level}
	{}

	virtual std::string getData() override
	{
		std::string data = Decorator::getData();

		// specific logic

		std::cout << "\nfile " << this->filePath <<  "\tFILE LOG --> ";
		std::cout << data;

		//

		return data;
	}
};

class WithTelegramLog : public Decorator
{
private:
	LogLevel level;
public:

	WithTelegramLog(ILoggable* item, LogLevel level = LogLevel::WARNING) :
		Decorator{ item },
		level{ level }
	{}

	virtual std::string getData() override
	{
		std::string data = Decorator::getData();

		// specific logic

		std::cout << "\ntelegram " << "\TELEGRAM LOG --> ";
		std::cout << data;

		//

		return data;
	}
};




int main()
{
	std::string endpoint = "https://google.com";
	Fetcher* fetcher = new Fetcher{ endpoint };

	/*Decorator* dec = new Decorator{ fetcher };*/
	//std::cout << dec->getData();

	std::string filePath = "log.txt";
	ILoggable* dec = new WithFileLog{ fetcher, filePath, LogLevel::ERROR};
	dec = new WithTelegramLog{ dec };


	std::cout << "\n\nD A T A: " << dec->getData();
	// std::cout << "\n\nD A T A: " << fetcher->getData();


	return 0;
}