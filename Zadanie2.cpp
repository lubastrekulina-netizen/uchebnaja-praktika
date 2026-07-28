#include <iostream>
#include <string>
#include <clocale>

// Базовый класс
class Vehicle {
protected:
    std::string brand;
    int speed;

public:
    // Конструктор базового класса
    Vehicle(std::string b, int s) : brand(b), speed(s) {}

    // 1. Обычный метод базового класса (наследуется как есть)
    void showBaseInfo() {
        std::cout << "Транспортное средство марки: " << brand << std::endl;
    }

    // 2. Виртуальный метод для демонстрации полиморфизма
    virtual void startEngine() {
        std::cout << "[Базовый класс] Двигатель " << brand << " запущен с характерным шумом (ДВС)." << std::endl;
    }

    // Виртуальный деструктор (обязателен при наличии виртуальных методов)
    virtual ~Vehicle() {}
};

// Производный класс
class ElectricCar : public Vehicle {
private:
    int batteryCapacity; // Специфичное поле производного класса

public:
    // Конструктор производного класса (вызывает конструктор базового)
    ElectricCar(std::string b, int s, int battery) 
        : Vehicle(b, s), batteryCapacity(battery) {}

    // 3. Переопределение виртуального метода базового класса (Override)
    void startEngine() override {
        std::cout << "[Производный класс] " << brand << " бесшумно активирован. Готов к поездке (Электромотор)." << std::endl;
    }

    // 4. Уникальный метод производного класса (отсутствует в базовом)
    void chargeBattery() {
        std::cout << "[Производный класс] Подключение к зарядной станции. Емкость батареи: " 
                  << batteryCapacity << " кВт*ч." << std::endl;
    }
};

int main() {
    // Настройка локализации для корректного вывода кириллицы
    std::setlocale(LC_ALL, "Russian");

    std::cout << "=== 1. Работа с объектом БАЗОВОГО класса ===" << std::endl;
    Vehicle myGasCar("Toyota", 180);
    myGasCar.showBaseInfo(); // Вызов обычного метода
    myGasCar.startEngine();  // Вызов базовой реализации виртуального метода

    std::cout << "\n=== 2. Работа с объектом ПРОИЗВОДНОГО класса ===" << std::endl;
    ElectricCar myTesla("Tesla Model S", 250, 100);
    myTesla.showBaseInfo();   // Вызов унаследованного метода базового класса
    myTesla.startEngine();    // Вызов переопределенного метода
    myTesla.chargeBattery();  // Вызов собственного уникального метода

    std::cout << "\n=== 3. Демонстрация полиморфизма (Указатель базового класса на объект потомка) ===" << std::endl;
    // Создаем указатель типа Vehicle*, но инициализируем его объектом ElectricCar
    Vehicle* polyVehicle = new ElectricCar("Audi e-tron", 200, 95);
    
    // Вызовется метод производного класса благодаря ключевому слову virtual
    polyVehicle->startEngine(); 

    // Очистка памяти
    delete polyVehicle;

    return 0;
}
