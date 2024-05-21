#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Device {
    public:
    std::string producent;
    std::string model;
    int rok_produkcji;
    Device(std::string produce,std::string model, int rok_produkcji)
    :producent(produce),model(model),rok_produkcji(rok_produkcji){};

    void getBasicData()
    {
        std::cout<<producent<<", "<<rok_produkcji<<", ";
    }
    virtual ~Device() = default;	
};
class Monitor : public Device {
public:
    double przekatna;
    Monitor(std::string producent, std::string model, int rok_produkcji, double przekatna)
        : Device(producent, model, rok_produkcji), przekatna(przekatna) {}
};
class Pc : public Device{
    public:
double taktowanie;
Pc(std::string producent, std::string model, int rok_produkcji, double taktowanie) 
:Device(producent, model ,rok_produkcji),taktowanie(taktowanie){};

};


class Mobile : public Device {
    double rozdzielczosc;
public:
    Mobile(std::string producent, std::string model, int rok_produkcji, double rozdzielczosc)
    :Device(producent, model, rok_produkcji),rozdzielczosc(rozdzielczosc){}

    double getCamerResolution() {
        return rozdzielczosc;
    }
};

int main() {
    std::vector<std::unique_ptr<Device>> devices;
    devices.push_back(std::make_unique<Monitor>("Samsung", "XYZ123", 2021, 27.5)); 
    devices.push_back(std::make_unique<Pc>("Dell", "ABC456", 2020, 3.2)); 
    devices.push_back(std::make_unique<Mobile>("Apple", "iPhone 12", 2021, 12.0));

    for (const auto& device : devices) {
        device->getBasicData();
        if (Mobile* mobile = dynamic_cast<Mobile*>(device.get())) {
            std::cout << "rozdzelczosc: " << mobile->getCamerResolution() << ", model: " << mobile->model << std::endl;
        } else if (Pc* pc = dynamic_cast<Pc*>(device.get())) {
            std::cout << "taktowanie: " << pc->taktowanie << ", model: " << pc->model <<", brak aparatu"<< std::endl;
        } else if (Monitor* monitor = dynamic_cast<Monitor*>(device.get())) {
            std::cout << "przekatna: " << monitor->przekatna << ", model: " << monitor->model <<", brak aparatu"<< std::endl;
        } 
    }
return 0;
}