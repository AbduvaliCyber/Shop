#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahsulot {
    string nomi;
    double narxi;
    int miqdori;
};

vector<Mahsulot> magazin;

void mahsulotQoshish() {
    Mahsulot m;
    cout << "Mahsulot nomi: ";
    cin >> m.nomi;
    cout << "Narxi: ";
    cin >> m.narxi;
    cout << "Miqdori: ";
    cin >> m.miqdori;
    magazin.push_back(m);
    cout << "Mahsulot muvaffaqiyatli qo'shildi!\n";
}

void roYxatniKorish() {
    cout << "\n--- Magazin Mahsulotlari ---\n";
    for (size_t i = 0; i < magazin.size(); ++i) {
        cout << i + 1 << ". " << magazin[i].nomi
             << " | Narxi: " << magazin[i].narxi
             << " | Miqdori: " << magazin[i].miqdori << endl;
    }
}

void mahsulotQidirish() {
    string nom;
    cout << "Qidirilayotgan mahsulot nomi: ";
    cin >> nom;
    bool topildi = false;

    for (const auto& m : magazin) {
        if (m.nomi == nom) {
            cout << "Topildi: " << m.nomi
                 << " | Narxi: " << m.narxi
                 << " | Miqdori: " << m.miqdori << endl;
            topildi = true;
            break;
        }
    }

    if (!topildi) {
        cout << "Mahsulot topilmadi.\n";
    }
}

int main() {
    int tanlov;

    do {
        cout << "\n1. Mahsulot qo'shish\n";
        cout << "2. Ro'yxatni ko'rish\n";
        cout << "3. Mahsulot qidirish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> tanlov;

        switch (tanlov) {
            case 1: mahsulotQoshish(); break;
            case 2: roYxatniKorish(); break;
            case 3: mahsulotQidirish(); break;
            case 0: cout << "Dastur yakunlandi.\n"; break;
            default: cout << "Noto‘g‘ri tanlov!\n";
        }

    } while (tanlov != 0);

    return 0;
}
