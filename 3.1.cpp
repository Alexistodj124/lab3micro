#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int numeros[3];

    cout << "Ingrese 3 números enteros:" << endl;

    // Entrada y validación
    for (int i = 0; i < 3; i++) {
        cout << "Número " << (i + 1) << ": ";
        cin >> numeros[i];
    }

    // Proceso:
    sort(numeros, numeros + 3);

    // Salida:
    cout << "\nNúmeros en orden ascendente:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
