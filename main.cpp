#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;

    Student(int id, string name, float gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }

    void display() {
        cout << "ID: " << id << ", Ism: " << name << ", GPA: " << gpa << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;
        float gpa;

        cout << "Student ID sini kiriting: ";
        cin >> id;
        cout << "Student ismini kiriting: ";
        cin.ignore();
        getline(cin, name);
        cout << "Student GPA (baho) sini kiriting: ";
        cin >> gpa;

        students.push_back(Student(id, name, gpa));
        cout << "Student muvaffaqiyatli qo'shildi.\n";
    }

    void removeStudent() {
        int id;
        cout << "O'chirish uchun student ID sini kiriting: ";
        cin >> id;

        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                found = true;
                cout << "Student o'chirildi.\n";
                break;
            }
        }

        if (!found) {
            cout << "Bunday ID bilan student topilmadi.\n";
        }
    }

    void displayAll() {
        if (students.empty()) {
            cout << "Studentlar ro'yxati bo'sh.\n";
            return;
        }

        cout << "Studentlar ro'yxati:\n";
        for (Student s : students) {
            s.display();
        }
    }

    void topStudent() {
        if (students.empty()) {
            cout << "Hech qanday student yo'q.\n";
            return;
        }

        float maxGPA = -1.0;
        for (Student s : students) {
            if (s.gpa > maxGPA)
                maxGPA = s.gpa;
        }

        cout << "Eng yuqori GPA ga ega student(lar):\n";
        for (Student s : students) {
            if (s.gpa == maxGPA)
                s.display();
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n===== Student Boshqaruv Dasturi =====\n";
        cout << "1. Student qo‘shish\n";
        cout << "2. Studentni o‘chirish\n";
        cout << "3. Barcha studentlarni ko‘rish\n";
        cout << "4. Eng yaxshi student(lar)ni ko‘rish\n";
        cout << "5. Chiqish\n";
        cout << "Tanlang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.removeStudent();
                break;
            case 3:
                manager.displayAll();
                break;
            case 4:
                manager.topStudent();
                break;
            case 5:
                cout << "Dastur tugadi.\n";
                return 0;
            default:
                cout << "Noto‘g‘ri tanlov. Qayta urinib ko‘ring.\n";
        }
    }
}
