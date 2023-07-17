#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << right << setw(3) <<  "Fahr" << ' ' << "Celcius" << endl;
    for (int i=0; i <= 300; i+=20){
        double celciius = double (i - 32)*5/9;
        cout << right << setw(3)<<  i;
        cout << fixed << setprecision(1) << setw(9) << celciius << endl;
    }
    return 0;
}
