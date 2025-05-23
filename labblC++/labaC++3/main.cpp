#include <iostream>
#include <string>
#include <vector>
#include <clocale>

class Контакт {
protected:
    std::string имя;
    std::string телефон;
    std::string адрес;

public:
    // Конструктор без параметров
    Контакт() : имя("Неизвестно"), телефон("Неизвестно"), адрес("Неизвестно") {
        std::cout << "Вызван конструктор Контакт без параметров" << std::endl;
    }

    // Конструктор с параметрами
    Контакт(const std::string& _имя, const std::string& _телефон, const std::string& _адрес)
        : имя(_имя), телефон(_телефон), адрес(_адрес) {
        std::cout << "Вызван конструктор Контакт с параметрами: " << имя << std::endl;
    }

    // Конструктор копирования
    Контакт(const Контакт& другой)
        : имя(другой.имя + "_копия"), телефон(другой.телефон), адрес(другой.адрес) {
        std::cout << "Вызван конструктор копирования Контакт для: " << имя << std::endl;
    }

    // Виртуальный деструктор
    virtual ~Контакт() {
        std::cout << "Вызван деструктор Контакт для: " << имя << std::endl;
    }

    // Геттер для имени
    std::string getИмя() const {
        return имя;
    }

    // Виртуальный метод вывода
    virtual void показать() const {
        std::cout << "Имя: " << имя << ", Телефон: " << телефон << ", Адрес: " << адрес << std::endl;
    }

    // Метод ввода данных
    virtual void ввести() {
        std::cout << "Введите имя: ";
        std::getline(std::cin, имя);
        std::cout << "Введите телефон: ";
        std::getline(std::cin, телефон);
        std::cout << "Введите адрес: ";
        std::getline(std::cin, адрес);
    }
};

// Перегрузка оператора << для Контакт
std::ostream& operator<<(std::ostream& os, const Контакт& контакт) {
    контакт.показать();
    return os;
}

class РабочийКонтакт : public Контакт {
private:
    std::string должность;
    std::string компания;

public:
    // Конструктор без параметров
    РабочийКонтакт() : Контакт(), должность("Неизвестно"), компания("Неизвестно") {
        std::cout << "Вызван конструктор РабочийКонтакт без параметров" << std::endl;
    }

    // Конструктор с параметрами
    РабочийКонтакт(const std::string& _имя, const std::string& _телефон, const std::string& _адрес,
        const std::string& _должность, const std::string& _компания)
        : Контакт(_имя, _телефон, _адрес), должность(_должность), компания(_компания) {
        std::cout << "Вызван конструктор РабочийКонтакт с параметрами: " << _имя << std::endl;
    }

    // Конструктор копирования
    РабочийКонтакт(const РабочийКонтакт& другой)
        : Контакт(другой), должность(другой.должность + "_копия"), компания(другой.компания) {
        std::cout << "Вызван конструктор копирования РабочийКонтакт для: " << getИмя() << std::endl;
    }

    // Деструктор
    ~РабочийКонтакт() override {
        std::cout << "Вызван деструктор РабочийКонтакт для: " << getИмя() << std::endl;
    }

    // Переопределённый метод вывода
    void показать() const override {
        Контакт::показать();
        std::cout << "Должность: " << должность << ", Компания: " << компания << std::endl;
    }

    // Метод ввода данных
    void ввести() override {
        Контакт::ввести();
        std::cout << "Введите должность: ";
        std::getline(std::cin, должность);
        std::cout << "Введите компанию: ";
        std::getline(std::cin, компания);
    }
};

// Перегрузка оператора << для РабочийКонтакт
std::ostream& operator<<(std::ostream& os, const РабочийКонтакт& контакт) {
    контакт.показать();
    return os;
}

class ЛичныйКонтакт : public Контакт {
private:
    std::string датаРождения;
    std::string email;

public:
    // Конструктор без параметров
    ЛичныйКонтакт() : Контакт(), датаРождения("Неизвестно"), email("Неизвестно") {
        std::cout << "Вызван конструктор ЛичныйКонтакт без параметров" << std::endl;
    }

    // Конструктор с параметрами
    ЛичныйКонтакт(const std::string& _имя, const std::string& _телефон, const std::string& _адрес,
        const std::string& _датаРождения, const std::string& _email)
        : Контакт(_имя, _телефон, _адрес), датаРождения(_датаРождения), email(_email) {
        std::cout << "Вызван конструктор ЛичныйКонтакт с параметрами: " << _имя << std::endl;
    }

    // Конструктор копирования
    ЛичныйКонтакт(const ЛичныйКонтакт& другой)
        : Контакт(другой), датаРождения(другой.датаРождения + "_копия"), email(другой.email) {
        std::cout << "Вызван конструктор копирования ЛичныйКонтакт для: " << getИмя() << std::endl;
    }

    // Деструктор
    ~ЛичныйКонтакт() override {
        std::cout << "Вызван деструктор ЛичныйКонтакт для: " << getИмя() << std::endl;
    }

    // Переопределённый метод вывода
    void показать() const override {
        Контакт::показать();
        std::cout << "Дата рождения: " << датаРождения << ", Email: " << email << std::endl;
    }

    // Метод ввода данных
    void ввести() override {
        Контакт::ввести();
        std::cout << "Введите дату рождения: ";
        std::getline(std::cin, датаРождения);
        std::cout << "Введите email: ";
        std::getline(std::cin, email);
    }
};

// Перегрузка оператора << для ЛичныйКонтакт
std::ostream& operator<<(std::ostream& os, const ЛичныйКонтакт& контакт) {
    контакт.показать();
    return os;
}

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");

    std::cout << "\n=== Демонстрация объектов без массива ===\n";

    // Создание объектов базового класса
    Контакт контакт1("Алексей", "+7-999-123-45-67", "ул. Ленина, 1");
    std::cout << контакт1;

    // Создание объектов классов-наследников
    РабочийКонтакт рабочий1("Иван", "+7-999-234-56-78", "ул. Мира, 10", "Менеджер", "ООО Ромашка");
    std::cout << рабочий1;

    ЛичныйКонтакт личный1("Мария", "+7-999-345-67-89", "пр. Победы, 5", "01.01.1990", "maria@example.com");
    std::cout << личный1;

    // Ввод данных для нового объекта
    ЛичныйКонтакт личный2;
    личный2.ввести();
    std::cout << личный2;

    std::cout << "\n=== Массив типа Контакт* ===\n";

    // Создание массива указателей на базовый класс
    Контакт* массивКонтактов[4];
    массивКонтактов[0] = new Контакт("Петр", "+7-999-456-78-90", "ул. Советская, 15");
    массивКонтактов[1] = new РабочийКонтакт("Ольга", "+7-999-567-89-01", "ул. Центральная, 20", "Программист", "ООО Код");
    массивКонтактов[2] = new ЛичныйКонтакт("Анна", "+7-999-678-90-12", "пр. Свободы, 25", "15.05.1985", "anna@example.com");
    массивКонтактов[3] = new Контакт("Сергей", "+7-999-789-01-23", "ул. Лесная, 30");

    // Цикл вывода данных
    for (int i = 0; i < 4; ++i) {
        std::cout << *массивКонтактов[i];
        std::cout << "-------------------" << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < 4; ++i) {
        delete массивКонтактов[i];
    }

    std::cout << "\n=== Массив типа ЛичныйКонтакт ===\n";

    // Создание массива объектов ЛичныйКонтакт
    ЛичныйКонтакт массивЛичных[2];
    массивЛичных[0] = ЛичныйКонтакт("Елена", "+7-999-890-12-34", "ул. Парковая, 35", "20.03.1995", "elena@example.com");
    массивЛичных[1] = ЛичныйКонтакт("Дмитрий", "+7-999-901-23-45", "пр. Мира, 40", "10.07.1980", "dmitry@example.com");

    // Цикл вывода данных
    for (int i = 0; i < 2; ++i) {
        std::cout << массивЛичных[i];
        std::cout << "-------------------" << std::endl;
    }

    std::cout << "\n=== Конец программы ===\n";

    return 0;
}