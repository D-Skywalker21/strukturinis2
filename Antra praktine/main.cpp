#include <iostream>
#include <random>
using namespace std;

 void (Balses_pribalses){
 }

int main() {
    //string pavadinimas;
    //int menu_options = 1;
    /// while(menu_options !=5) {
    //  cout << " 1. Balse ar priebalse? " << endl;
    //cout << " 2. Maziausias bendras daliklis " << endl;
    //cout << " 3. Zaidimas 1 - 100 " << endl;
    //cout << " 4. FizzBuzz " << endl;
    // cout << " 5. Iseiti"<< endl;
    // cout << " Pasirinkite jus dominancia opcija" << endl;
    // cin >> menu_options;
    // }
    int menu_options;
    do {
        cout << " Pasirinkite jus dominancia opcija" << endl;
        cin >> menu_options;

        switch (menu_options) {
            case 1:
                Balses_pribalses();
            break;
            case 2:
                Maziausias_bendras_daliklis();
            break;
            case 3:
                Zaidimas_1_100();
            break;
            case 4:
                FizzBuzz();
            break;
            case 5:
                cout << " Iseiti " << endl;
            break;
            default:
                cout << " Neteisingas pasirinkimas. Bandykite dar karta " << endl;
        }
    }while (menu_options !=5);
        return 0;

}
