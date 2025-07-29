#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    char sexo; // M o F
    double peso; // en kg
    double altura; // en metros
};

// Calcula el % de grasa corporal
double calcularGrasa(const Persona& p) {
    double imc = p.peso / (p.altura * p.altura);
    double grasa = 0.0;

    switch (p.sexo) {
        case 'M':
        case 'm':
            grasa = (1.20 * imc) + (0.23 * p.edad) - 16.2;
            break;
        case 'F':
        case 'f':
            grasa = (1.20 * imc) + (0.23 * p.edad) - 5.4;
            break;
        default:
            throw invalid_argument("Sexo inválido. Use M o F.");
    }

    return grasa;
}

int main() {
    Persona p;

    cout << "Ingrese nombre: ";
    getline(cin, p.nombre);

    cout << "Ingrese edad: ";
    cin >> p.edad;

    cout << "Ingrese sexo (M/F): ";
    cin >> p.sexo;

    cout << "Ingrese peso (kg): ";
    cin >> p.peso;

    cout << "Ingrese altura (m): ";
    cin >> p.altura;

    try {
        double grasa = calcularGrasa(p);

        cout << fixed << setprecision(2);
        cout << "\nReporte de Grasa Corporal\n";
        cout << "-----------------------------\n";
        cout << setw(10) << "Nombre: " << p.nombre << endl;
        cout << setw(10) << "Edad: " << p.edad << " años" << endl;
        cout << setw(10) << "Sexo: " << (toupper(p.sexo)) << endl;
        cout << setw(10) << "Peso: " << p.peso << " kg" << endl;
        cout << setw(10) << "Altura: " << p.altura << " m" << endl;
        cout << setw(10) << "Grasa corporal estimada: " << grasa << " %" << endl;

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
