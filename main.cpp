#include <iostream>

/*
1. Реализовать вспомогательный класс по варианту задания с указанными полями и методами. Должны быть также реализованы методы Init и Display.
 Продемонстрировать работу всех методов в main.
2. Создать основной класс по варианту задания, полями которого являются объекты вспомогательного класса.  Реализовать указанные методы.
В main продемонстрировать использование объектов основного класса. В основном классе должно быть строковое поле названия в виде массива char.

3. Придумать свой вариант задания для этой ЛР (аналогично представленным ниже вариантам) и реализовать его.
Чем интереснее и оригинальнее задание, тем выше оценка...
*/

/*Предмет, изучаемый студентом в семестре имеет 2 целых поля: - количество лекционных часов и часов на практические занятия.
Реализовать метод, вычисляющий общее число часов, при этом еще добавляется 30% от аудиторных  занятий на самостоятельную работу.
*/

using namespace std;

class Subject{
    private:
        string name;
        int lec_hours;
        int pract_hours;
    public:
        int all_hours()
        {
            return lec_hours + pract_hours + 0,3 * lec_hours;
        }
        Subject()
        {
            /*lec_hours = 2;
            pract_hours = 3;
            cout << "lec_hours = " << lec_hours << endl;
            cout << "pract_hours = " << pract_hours << endl;*/

        }
        ~Subject()
        {}
        void Init(string name,int lec_hours, int pract_hours)
        {
            this->name = name;
            this->lec_hours = lec_hours;
            this->pract_hours = pract_hours;
        }
        void Display()
        {
            cout << this->name << ":" << endl;
            cout << "lect hours = " << this->lec_hours << endl;
            cout << "pract hours = " << this->pract_hours << endl;
        }
};

/*
Основным классом является класс студент, имеющий три поля предметов и 3 целочисленных поля – баллы, набранные по этим предметам.
Реализовать метод, вычисляющий рейтинг студента. Рейтинг вычисляется как средний балл по трем предметам.
Реализовать метод, определяющий предмет с наибольшим числом часов.
*/


int main()
{
    Subject maths, physics, philosophy;
    maths.Init("Maths", 2, 3);
    physics.Init("Physics", 3, 6);
    philosophy.Init("Philosophy", 4, 10);
    maths.Display();
    physics.Display();
    philosophy.Display();
    int mathsHours = maths.all_hours();
    cout << "all maths hours = " << mathsHours << endl;
    return 0;
}
