#include <iostream>
#include <random>
using namespace std;

bool Balse(char letter){
       char balse[]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
       for(int i=0;i<10;i++) {
        if(letter==balse[i]) {
         return true;
        }
       }
       return false;
      }

int BendrDal(int skaicius1, int skaicius2) {
 while (skaicius2 !=0) {
  int liekana = skaicius1 % skaicius2;
  skaicius1 = skaicius2;
  skaicius2 = liekana;
 }
 return skaicius1;
}
int main() {
    string pavadinimas;
    char letter;
    int menu_options = 1;
    while(menu_options !=5) {

     cout << " 1. Balse ar priebalse? " << endl;
     cout << " 2. Maziausias bendras daliklis " << endl;
     cout << " 3. Zaidimas 1 - 100 " << endl;
     cout << " 4. FizzBuzz " << endl;
     cout << " 5. Iseiti"<< endl;
     cout << " Pasirinkite jus dominancia opcija" << endl;
     cin >> menu_options;

     switch (menu_options) {

      case 1:
       cout << " Irasykite raide " << endl;
       cin >> letter;
      if(Balse(letter)) {
       cout << letter << " Yra balse. " << endl;
      }else {
       cout << letter << " Ya priebalse" << endl;
      }
      break;
      case 2:
       int skaicius1, skaicius2;

      cout << " Iveskite pirma skaiciu ";
      cin >> skaicius1;
      cout << " Iveskite antra skaiciu ";
      cin >> skaicius2;
      int DBD = BendrDal(skaicius1, skaicius2);
      cout << " Didziausias bendras daliklis : " << DBD << endl;


     }
    }


        return 0;

}
