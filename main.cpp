#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Noutbuk {
    string model;
    double narx;
    int ram;       // GB
    int xotira;    // GB
    int miqdor;
};

vector<Noutbuk> magazin;

void noutbukQoshish() {
    Noutbuk n;
    cout << "Model nomi: ";
    cin >> n.model;
    cout << "Narxi ($): ";
    cin >> n.narx;
    cout << "Operativ xotira (RAM, GB): ";
    cin >> n.ram;
    cout << "Xotira hajmi (SSD/HDD, GB): ";
    cin >> n.xotira;
    cout << "Miqdori: ";
    cin >> n.miqdor;
    magazin.push_back(n);
    cout << "Noutbuk muvaffaqiyatli qo'shildi!\n";
}

void roYxatniKorish() {
    cout << "\n--- Magazin Noutbuklari ---\n";
    for (size_t i = 0; i < magazin.size(); ++i) {
        cout << i + 1 << ". " << magazin[i].model
             << " | Narx: $" << magazin[i].narx
             << " | RAM: " << magazin[i].ram << "GB"
             << " | Xotira: " << magazin[i].xotira << "GB"
             << " | Miqdor: " << magazin[i].miqdor << endl;
    }
}

void noutbukQidirish() {
    string model;
    cout << "Qidirilayotgan model nomi: ";
    cin >> model;
    bool topildi = false;

    for (const auto& n : magazin) {
        if (n.model == model) {
            cout << "Topildi: " << n.model
                 << " | Narx: $" << n.narx
                 << " | RAM: " << n.ram << "GB"
                 << " | Xotira: " << n.xotira << "GB"
                 << " | Miqdor: " << n.miqdor << endl;
            topildi = true;
            break;
        }
    }

    if (!topildi) {
        cout << "Noutbuk topilmadi.\n";
    }
}

int main() {
    int tanlov;

    do {
        cout << "\n1. Noutbuk qo'shish\n";
        cout << "2. Ro'yxatni ko'rish\n";
        cout << "3. Noutbuk qidirish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> tanlov;

        switch (tanlov) {
            case 1: noutbukQoshish(); break;
            case 2: roYxatniKorish(); break;
            case 3: noutbukQidirish(); break;
            case 0: cout << "Dastur yakunlandi.\n"; break;
            default: cout << "Noto‘g‘ri tanlov!\n";
        }

    } while (tanlov != 0);

    return 0;
}
