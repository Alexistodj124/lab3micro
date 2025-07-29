#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int opcion;
    cout << "=== Decimal a ASCII ===" << endl;
    cout << "[1] Ver tabla ASCII completa" << endl;
    cout << "[2] Convertir número a carácter ASCII" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    if (opcion == 1) {
        // Mostrar tabla ASCII del 0 al 127
        cout << "\nTabla ASCII (0–127):\n";
        cout << setw(10) << "Decimal" << setw(10) << "ASCII" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i <= 127; i++) {
            cout << setw(10) << i << setw(10) << static_cast<char>(i) << endl;
        }
    } else if (opcion == 2) {
        int numero;
        cout << "Ingrese un número entre 0 y 127: ";
        cin >> numero;
        if (numero < 0 || numero > 127) {
            cout << "Error: número fuera de rango válido (0–127)." << endl;
        } else {
            cout << "El carácter ASCII es: '" << static_cast<char>(numero) << "'" << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
