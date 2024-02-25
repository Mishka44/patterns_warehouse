#include <iostream>
#include <Windows.h>



class House_strategy{
public:
   virtual void make_strategy() = 0;
};

class Strategy_BF : public House_strategy {
public:
    void make_strategy() override{
        std::cout << "Стратегия для большого предмета из фуры" << "\n";
    }
};

class Strategy_SF : public House_strategy {
public:
    void make_strategy() override {
        std::cout << "Стратегия для маленького предмета из фуры" << "\n";
    }
};

class Strategy_BG: public House_strategy {
public:
    void make_strategy() override {
        std::cout << "Стратегия для большого предмета из газели" << "\n";
    }
};

class Strategy_SG : public House_strategy {
public:
    void make_strategy() override{
        std::cout << "Стратегия для маленького предмета из газели" << "\n";
    }
};

class Warehouse {
public:
    Warehouse()=  default;
    Warehouse(House_strategy *obj): strategy(obj){}
    void setStrategy(House_strategy* strategy) {
        this->strategy = strategy;
    }
    void executeStrategy() {
        strategy->make_strategy();
    }

private :
    int space;
    std::string name;
    House_strategy *strategy;

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout << "Пример паттерна стратегия для разгрузки машины на складе:" << "\n";
    Strategy_BF bf;
    Strategy_BG bg;
    Warehouse warehouse(&bg);
    warehouse.executeStrategy();
    warehouse.setStrategy(&bf);
    warehouse.executeStrategy();

    

}


