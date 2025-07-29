#include <iostream>
#include <iomanip>

using namespace std;

// Calculo de la utilidad total
double calcularUtilidad(int cantidad, double costo, double precio) {
    double utilidadPorUnidad = precio - costo;
    double utilidadTotal = utilidadPorUnidad * cantidad;
    return utilidadTotal;
}

int main() {
    int cantidad;
    double costo, precio;

    // Ingreso de datos
    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidad;
    if (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor que 0." << endl;
        return 1;
    }

    cout << "Ingrese el costo por unidad: Q";
    cin >> costo;
    if (costo <= 0) {
        cout << "Error: El costo debe ser mayor que 0." << endl;
        return 1;
    }

    cout << "Ingrese el precio de venta por unidad: Q";
    cin >> precio;
    if (precio <= 0) {
        cout << "Error: El precio debe ser mayor que 0." << endl;
        return 1;
    }

    // Utilidad
    double utilidad = calcularUtilidad(cantidad, costo, precio);

    cout << fixed << setprecision(2);
    cout << "Utilidad total: Q" << utilidad << endl;

    return 0;
}
