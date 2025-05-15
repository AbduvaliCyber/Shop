#include <iostream>
#include <string>
using namespace std;

void showIntro() {
    cout << "=====================================" << endl;
    cout << "     WELCOME TO ABU-TECH SYSTEM      " << endl;
    cout << "=====================================" << endl;
    cout << "Innovating the future with technology" << endl << endl;
}

void showMenu() {
    cout << "----------- MAIN MENU -------------" << endl;
    cout << "1. About ABU-TECH" << endl;
    cout << "2. Services" << endl;
    cout << "3. Contact Us" << endl;
    cout << "0. Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select an option: ";
}

void about() {
    cout << "\nABU-TECH is a leading tech company specializing in:\n";
    cout << "- Software Development\n";
    cout << "- AI Solutions\n";
    cout << "- Web and Mobile Apps\n\n";
}

void services() {
    cout << "\nOur services include:\n";
    cout << "1. Custom Software Development\n";
    cout << "2. Machine Learning Projects\n";
    cout << "3. IT Consulting\n\n";
}

void contact() {
    cout << "\nContact us at:\n";
    cout << "Email: info@abu-tech.com\n";
    cout << "Phone: +998 90 123 45 67\n\n";
}

int main() {
    int choice;
    showIntro();

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                about();
                break;
            case 2:
                services();
                break;
            case 3:
                contact();
                break;
            case 0:
                cout << "\nThank you for visiting ABU-TECH!" << endl;
                break;
            default:
                cout << "\nInvalid option. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
