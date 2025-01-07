#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<numeric>
using namespace std;

// panti struct, pisis info
struct panti {
    string name;
    int age;
    string personality;
    bool isAdopted;

    panti(string n, int a, string p) : name(n), age(a), personality(p), isAdopted(false) {}
};

// panteritele pe care le avemm   -functie
void displayAvailableCats(const vector<panti>& cats) {
    cout << "\nPanteritele disponibile, cele mai frumoase si dragalase: \n";
    for (const auto& cat : cats) {
        if (!cat.isAdopted) {
            cout << "Nume: " << cat.name << ", Varsta: " << cat.age << ", Personalitate: " << cat.personality << "\n";
        }
    }
}

// addopta panterita dupa numele ei
void adoptCat(vector<panti>& cats, const string& catName) {
    auto it = find_if(cats.begin(), cats.end(), [&catName](const panti& cat) {
        return cat.name == catName && !cat.isAdopted;
    });

    if (it != cats.end()) {
        it->isAdopted = true;
        cout << "\nAcum ai si tu o panterita vevi, take care of herr! <3 " << it->name << ".\n";
    } else {
        cout << "\nsolly, " << catName << " pisicuta asta nu o avem, poate a fost adoptata deja.\n";
    }
}

// Function to suggest a cat based on user preferences
void suggestCat(const vector<panti>& cats) {
    int preference;
    cout << "\nCe fel de pisi panterita cute doresti?\n";
    cout << "1. Jucausa\n";
    cout << "2. calma\n";
    cout << "3. curioasa\n";
    cout << "4. aventuroasa\n";
    cout << "5. energica\n";
    cout << "Alege o varianta (1-5): ";
    cin >> preference;

    string preferredPersonality;
    switch (preference) {
        case 1: preferredPersonality = "Jucausa"; break;
        case 2: preferredPersonality = "calma"; break;
        case 3: preferredPersonality = "curioasa"; break;
        case 4: preferredPersonality = "aventuroasa"; break;
        case 5: preferredPersonality = "energicac"; break;
        default:
            cout << "\nOofi! Nu avem asa panterita.\n";
            return;
    }

    cout << "\nCred ca panterita asta ti s-ar potrivi:\n";
    bool found = false;
    for (const auto& cat : cats) {
        if (cat.personality == preferredPersonality && !cat.isAdopted) {
            cout << "Nume: " << cat.name << ", varsta: " << cat.age << ", Personalitate: " << cat.personality << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "\nNu avem pisicuta cu personalitatea asta. :((\n";
    }
}

// Main function
int main() {
    vector<panti> cats = {
        {"Panti", 2, "Jucausa"},
        {"Pisi", 1, "calma"},
        {"Sosi", 3, "curioasa"},
        {"Esteruca", 4, "Adventurous"},
        {"Panteritul", 2, "energica"}
    };

    int choice;
    do {
        cout << "\n--- Adoptie de panterite Bz rawr ---\n"<<endl;
        cout << "1. Vreau sa vad panteritele pe care le aveti\n";
        cout << "2. Ia acasica o panterita chiar acum\n";
        cout << "3. Ma acest mini quiz sa vezi daca avem vreo pisi care ti se potriveste\n";
        cout << "4. Exit\n";
        cout << "Deci? Ce alegi? ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableCats(cats);
                break;
            case 2: {
                string catName;
                cout << "\nScrie numele panteritei pe care o vrei: ";
                cin >> catName;
                adoptCat(cats, catName);
                break;
            }
            case 3:
                suggestCat(cats);
                break;
            case 4:
                cout << "\n Ne bucuram ca ai venit la adapostul nostru. kissy!\n";
                break;
            default:
                cout << "\nInvalid choice.... Daca vlei mai incealca.\n";
        }
    } while (choice != 4);
    cout << "   /\\_/\\  \n";
    cout << "  ( o.o ) \n";
    cout << "   > ^ <  \n";

    return 0;
}
