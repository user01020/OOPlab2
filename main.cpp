#include <iostream>
#include <locale.h>

using namespace std;

/*
1. Реализовать вспомогательный класс по варианту задания с указанными полями и методами. Должны быть также реализованы методы Init и Display.
 Продемонстрировать работу всех методов в main.
2. Создать основной класс по варианту задания, полями которого являются объекты вспомогательного класса.  Реализовать указанные методы.
В main продемонстрировать использование объектов основного класса. В основном классе должно быть строковое поле названия в виде массива char.
3. Придумать свой вариант задания для этой ЛР (аналогично представленным ниже вариантам) и реализовать его.
Чем интереснее и оригинальнее задание, тем выше оценка...
*/

/*
Вспомогательнй класс жилец комнаты, имеющий поле имя жильца, два целочисленных поля: долгов по суботникам и вахтам и целочисленое поле - кол - во прочих нарушений.
Реализовать метод, считающий рейтинг студента в общаге.
*/
class Occupier{
    private:
        string name;
        int hostelWorkDebts;
        int shiftWorkDebts;
        int violations;
    public:
        Occupier(){}
        Occupier(string name, int hostelWorkDebts, int shiftWorkDebts, int violations)
        {
            this->name = name;
            this->hostelWorkDebts = hostelWorkDebts;
            this->shiftWorkDebts = shiftWorkDebts;
            this->violations = violations;
        }
        ~Occupier(){}
        void Display()
        {
            cout << name << ":" << endl;
            cout << "hostelWorkDebts = " << hostelWorkDebts << endl;
            cout << "shiftWorkDebts = " << shiftWorkDebts << endl;
            cout << "violations = " << violations << endl;
        }
        int rating()
        {
            int rat = 100 - (hostelWorkDebts + shiftWorkDebts) * 10 - violations * 15;
            if (rat < 0) rat = 0;
            return rat;
        }
};
/*
Основным классом является класс комната(в общаге), имеющий поле - номер комнаты, три поля студентов проживающих в комнате и целочисленое поле - кол - во нарушений относительно состояния комнаты.
Реализовать метод, вычисляющий рейтинг рейтинг комнаты("Успешность комнаты"). Рейтинг вычисляется как средний балл по трем предметам.
Реализовать метод, определяющий будет ли вызвана комната на студ совет и кто из студентов должен там присутствовать.
*/



int main()
{
    setlocale(0, "");

    cout << "\tchecking methods of the class Subject:\n";
    Occupier occupier1("Aleksey", 1, 1, 0), occupier2("Aleksandr", 3, 2, 1), occupier3("Sergey", 0, 0, 3);
    occupier1.Display();
    cout << "rating = " << occupier1.rating() << endl;
    occupier2.Display();
    cout << "rating = " << occupier2.rating() << endl;
    occupier3.Display();
    cout << "rating = " << occupier3.rating() << endl;

//////////////////////////////

    return 0;
}
