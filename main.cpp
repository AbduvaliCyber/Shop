#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Soat {
    string model;
    double narx;
    string tur;
    string brend;
    int miqdor;
};

vector<Soat> magazin;

void soatQoshish() {
    Soat s;
    cout << "Model nomi: ";
    cin >> s.model;
    cout << "Narxi ($): ";
    cin >> s.narx;
    cout << "Turi (aqlli/mexanik/raqamli): ";
    cin >> s.tur;
    cout << "Brendi: ";
    cin >> s.brend;
    cout << "Miqdori: ";
    cin >> s.miqdor;
    magazin.push_back(s);
    cout << "Soat muvaffaqiyatli qo'shildi!\n";
}

void roYxatniKorish() {
    cout << "\n--- Magazin Soatlari ---\n";
    for (size_t i = 0; i < magazin.size(); ++i) {
        cout << i + 1 << ". " << magazin[i].model
             << " | Narx: $" << magazin[i].narx
             << " | Turi: " << magazin[i].tur
             << " | Brend: " << magazin[i].brend
             << " | Miqdor: " << magazin[i].miqdor << endl;
    }
}

void soatQidirish() {
    string model;
    cout << "Qidirilayotgan model nomi: ";
    cin >> model;
    bool topildi = false;

    for (const auto& s : magazin) {
        if (s.model == model) {
            cout << "Topildi: " << s.model
                 << " | Narx: $" << s.narx
                 << " | Turi: " << s.tur
                 << " | Brend: " << s.brend
                 << " | Miqdor: " << s.miqdor << endl;
            topildi = true;
            break;
        }
    }

    if (!topildi) {
        cout << "Soat topilmadi.\n";
    }
}

int main() {
    int tanlov;

    do {
        cout << "\n1. Soat qo'shish\n";
        cout << "2. Ro'yxatni ko'rish\n";
        cout << "3. Soat qidirish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> tanlov;

        switch (tanlov) {
            case 1: soatQoshish(); break;
            case 2: roYxatniKorish(); break;
            case 3: soatQidirish(); break;
            case 0: cout << "Dastur yakunlandi.\n"; break;
            default: cout << "Noto‘g‘ri tanlov!\n";
        }

    } while (tanlov != 0);

    return 0;
}
