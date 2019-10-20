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
Основным классом является класс комната(в общаге), имеющий поле - номер комнаты, три поля студентов проживающих в комнате и целочисленое поле - кол - во нарушений по поводу состояния комнаты.
Реализовать метод, вычисляющий рейтинг рейтинг комнаты("Успешность комнаты").
Реализовать метод, определяющий будет ли вызвана комната на студ совет и кто из студентов должен там присутствовать.
*/
class Room{
    private:
        int num;
        Occupier occupiers[3];
        int violations;
    public:
        Room(){}
        Room(int num, Occupier occupier1, Occupier occupier2, Occupier occupier3, int violations)
        {
            this->num = num;
            this->occupiers[0] = occupier1;
            this->occupiers[1] = occupier2;
            this->occupiers[2] = occupier3;
            this->violations = violations;
        }
        ~Room(){}
        void Display()
        {
            cout << "Room's number: " << num << endl;
            cout << "\tstudents: \n";
            for(int i = 0; i < 3; i++)
            {
                occupiers[i].Display();
            }
            cout << "violations in room = " << violations << endl;
        }
        int rating()
        {
            return (occupiers[0].rating() + occupiers[1].rating() + occupiers[2].rating()) / 3;
        }
        bool studentCouncil()
        {
            cout << "\tstudent council decision:\n";
            if(rating() < 25 )
            {
                cout << "Yes\n";
                cout << "bad students: \n";
                for(int i = 0; i < 3; i++)
                {
                    if(occupiers[i].rating() < 25)
                        occupiers[i].Display();
                }
                return true;
            }
            cout << "No\n";
            return false;
        }
};


int main()
{
    setlocale(0, "");

    cout << "\tchecking methods of the class Occupier:\n";
    Occupier occupier1("Aleksey", 1, 1, 3), occupier2("Aleksandr", 3, 2, 4), occupier3("Sergey", 2, 1, 3);
    occupier1.Display();
    cout << "rating = " << occupier1.rating() << endl;
    occupier2.Display();
    cout << "rating = " << occupier2.rating() << endl;
    occupier3.Display();
    cout << "rating = " << occupier3.rating() << endl;

//////////////////////////////
    cout << "\tchecking methods of the class Room:\n";
    Room room(71, occupier1, occupier2, occupier3, 3);
    room.Display();
    cout << "Room's rating = " << room.rating() << endl;
    room.studentCouncil();
    return 0;
}
