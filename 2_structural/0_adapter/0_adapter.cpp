#include <iostream>

class RealSensor
{
public:
    float getSpeedInMiles()
    {
        return 180;
    }
    float getHeightInFoots()
    {
        return 33000;
    }
};


class ISensorAdapter
{
public:
    virtual float getSpeed() = 0;
    virtual float getHeight() = 0;
    virtual ~ISensorAdapter() {}
};

class MetricAdapter : public ISensorAdapter
{
private:
    RealSensor* sensor;
public:
    MetricAdapter(RealSensor* sensor)
        :sensor{sensor}
    {}
    virtual float getSpeed() override
    {
        return sensor->getSpeedInMiles() * 1.61;
    }
    virtual float getHeight() override
    {
        return sensor->getHeightInFoots() * 0.305;
    }
};


void client(ISensorAdapter* adapter)
{
    std::cout << "speed: " << adapter->getSpeed() << '\n';
    std::cout << "height: " << adapter->getHeight() << '\n';
}

int main()
{
    client(new MetricAdapter(new RealSensor()));
}

