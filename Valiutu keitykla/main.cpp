#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string pavadinimas = "";
    double rezultatas = 0;
    double valiutos_kiekis = 0;
    int pasirinkimas = 0;
    // Valiutų kursai
    const double GBP_Bendras = 0.8593;
    const double GBP_Pirkti = 0.8450;
    const double GBP_Parduoti = 0.9060;
    const double USD_Bendras = 1.0713;
    const double USD_Pirkti = 1.0547;
    const double USD_Parduoti = 1.1309;
    const double INR_Bendras = 88.8260;
    const double INR_Pirkti = 85.2614;
    const double INR_Parduoti = 92.8334;
    int meniu_opcijos = 1;
    while (meniu_opcijos != 4) {
        cout << " 1. Valiutu kurso palyginimas "<<endl;
        cout << " 2. Valiutos pardavimas "<<endl;
        cout << " 3. Valiutos pirkimas "<<endl;
        cout << " 4. Iseiti "<<endl;
        cout << " Pasirinkite dominancia opcija "<<endl;

        cin >> meniu_opcijos;

        switch(meniu_opcijos) {
            case 1:
                cout  << " Pasirinkite Valiuta " << endl;
            cout << " 1. GBP " << endl;
            cout << " 2. USD " << endl;
            cout << " 3. INR " << endl;
            int valiuta;
            cin >> valiuta;
            cout << " Iveskite suma(EUR) " << endl;
            cin >> valiutos_kiekis;
            if (valiuta == 1) {
                rezultatas = GBP_Bendras * valiutos_kiekis;
                pavadinimas = "GBP";
            } else if (valiuta == 2) {
                rezultatas = USD_Bendras * valiutos_kiekis;
                pavadinimas = "USD";
            } else {
                rezultatas = INR_Bendras * valiutos_kiekis;
                pavadinimas = "INR";
            }
            cout << fixed << setprecision(2) << valiutos_kiekis << " EUR " << setprecision(2) << rezultatas << pavadinimas << endl;
            if(valiuta<=3)
                break;
            case 2:
                cout << " pasirinkite kokia valiuta noretumet parduoti " << endl;
            cout << " 1. GBP " << endl;
            cout << " 2. USD " << endl;
            cout << " 3. INR " << endl;
            cin >> valiuta;
            if (valiuta == 1) {
                pavadinimas = "GBP ";
                cout << " Iveskite suma kuria noretumet parduoti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis / GBP_Parduoti;
            } else if (valiuta == 2) {
                pavadinimas = "USD ";
                cout << " Iveskite suma kuria noretumet parduoti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis / USD_Parduoti;
            }else if (valiuta ==3){
                pavadinimas = "INR ";
                cout << " Iveskite suma kuria noretumet parduoti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis / INR_Parduoti ;
            }
            else {
                cout << "klaida" << endl;
                break;
            }
            if(valiuta<=3)
                cout << " pardavete: " << fixed << setprecision(2) << valiutos_kiekis << " " << pavadinimas << "uz " << rezultatas << " EUR "<< endl;
            break;
            case 3:
                cout << " pasirinkite kokia valiuta noretumet isigyti " << endl;
            cout << " 1. GBP " << endl;
            cout << " 2. USD " << endl;
            cout << " 3. INR " << endl;
            cin >> valiuta;
            if (valiuta == 1) {
                pavadinimas = "GBP";
                cout << " Iveskite suma kuria noretumet isigyti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis /GBP_Pirkti ;
            } else if (valiuta == 2) {
                pavadinimas = "USD";
                cout << " Iveskite suma kuria noretumet isigyti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis /USD_Pirkti ;
            }
            else if(valiuta ==3) {
                pavadinimas ="INR";
                cout << " Iveskite suma kuria noretumet isigyti " << pavadinimas << endl;
                cin >> valiutos_kiekis;
                rezultatas = valiutos_kiekis /INR_Pirkti ;
            }
            else {
                cout << "klaida" << endl;
                break;
            }
            if(valiuta<=3)
                cout << " Isigyjote: "<< fixed << setprecision(2) << valiutos_kiekis << " " << pavadinimas << " uz " << fixed << setprecision(2) << rezultatas  << " EUR " << endl;
            break;
            default:
                cout << " Nera tokio pasirinkimo. Iveskite is naujo "<< endl;
            break;
            case 4:
                cout << " Jus isejote is programos " << endl;
            break;
        }
    }
        return 0;
}
