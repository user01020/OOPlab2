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
        Subject(string name,int lec_hours, int pract_hours)
        {
            this->name = name;
            this->lec_hours = lec_hours;
            this->pract_hours = pract_hours;

        }
        ~Subject()
        {}
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

class Student{
    private:
        string name;
        Subject subject[3] = {Subject("", 0, 0), Subject("", 0, 0), Subject("", 0, 0)};
        int subjectScores[3];
    public:
        Student(string name, Subject subject1, Subject subject2, Subject subject3, int subScore1, int subScore2, int subScore3)
        {
            this->name = name;
            this->subject[0] = subject1;
            this->subject[1] = subject2;
            this->subject[2] = subject3;
            this->subjectScores[0] = subScore1;
            this->subjectScores[1] = subScore2;
            this->subjectScores[2] = subScore3;
        }
        ~Student()
        {}
        void Display()
        {
            //cout << "Subject name\tSubject Scores\n";
            cout << this->name << ":\n";
            cout << "\tsubjects:\n";
            for(int i = 0; i < 3; i++)
            {
                this->subject[i].Display();
                cout << "rating in subject - " << subjectScores[i] << endl;
            }
        }
        float rating()
        {
            return (subjectScores[0] + subjectScores[1] + subjectScores[2]) / 3;
        }
        Subject maxHoursSubject()
        {
            Subject max("", 0, 0);
            max = subject[0];
            for(int i = 1; i < 3; i++)
            {
                if (subject[i].all_hours() > max.all_hours())
                    max = subject[i];
            }
            return max;
        }
};

int main()
{
    cout << "\tchecking the operation of the class Subject:\n";
    Subject maths("Maths", 2, 3), physics("Physics", 3, 6), philosophy("Philosophy", 4, 10);
    maths.Display();
    physics.Display();
    philosophy.Display();
    int mathsHours = maths.all_hours();
    cout << "all math   s hours = " << mathsHours << endl;
//////////////////////////////
    cout << "\tchecking the operation of the class Student:\n";
    Student student("Volodia", maths, physics, philosophy, 65, 70, 40);
    student.Display();
    float studentRating = student.rating();
    Subject max_hours_subject = student.maxHoursSubject();
    cout << "\tstudent rating = " << studentRating << endl;
    cout << "\tmost horses subject:" << endl;
    max_hours_subject.Display();
    return 0;
}
