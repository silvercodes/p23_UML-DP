#include <iostream>

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






