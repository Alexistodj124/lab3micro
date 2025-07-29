#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if (b == 0) throw runtime_error("Error. División por cero");
    return a / b;
}

int potencia(int a, int b) {
    int resultado = 1;
    for (int i = 0; i < b; ++i) resultado *= a;
    return resultado;
}

int modulo(int a, int b) {
    if (b == 0) throw runtime_error("Error. Módulo por cero");
    return a % b;
}

void decodificarInstruccion(const string& instruccion) {
    unsigned char byte = 0;

    // Convertimos la cadena binaria a un byte
    for (int i = 0; i < 8; ++i) {
        byte <<= 1;
        if (instruccion[i] == '1') byte |= 1;
    }

    int opcode = (byte >> 5) & 0b111;     // bits 7-5
    int mod = (byte >> 4) & 0b1;          // bit 4
    int A = (byte >> 2) & 0b11;           // bits 3-2
    int B = byte & 0b11;                  // bits 1-0

    cout << "  OPCODE: " << bitset<3>(opcode) << " ";
    cout << "(";
    switch (opcode) {
        case 0: cout << "Suma"; break;
        case 1: cout << "Resta"; break;
        case 2: cout << "Multiplicación"; break;
        case 3: cout << "División entera"; break;
        case 5: cout << "Potencia"; break;
        case 6: cout << "Módulo"; break;
        default: cout << "Inválido"; break;
    }
    cout << ")" << endl;

    cout << "  MOD: " << mod << " (" << (mod ? "Invertir" : "Directo") << " operandos)" << endl;
    cout << "  A: " << bitset<2>(A) << " (" << A << ")  B: " << bitset<2>(B) << " (" << B << ")" << endl;

    if (opcode != 0 && opcode != 1 && opcode != 2 && opcode != 3 && opcode != 5 && opcode != 6) {
        cout << "Error: Código de operación inválido." << endl;
        return;
    }

    if (mod) swap(A, B); // aplicar MOD

    try {
        int resultado = 0;
        switch (opcode) {
            case 0: resultado = suma(A, B); break;
            case 1: resultado = resta(A, B); break;
            case 2: resultado = multiplicacion(A, B); break;
            case 3: resultado = division(A, B); break;
            case 5: resultado = potencia(A, B); break;
            case 6: resultado = modulo(A, B); break;
        }
        cout << "Resultado: " << resultado << endl;
    } catch (const exception& e) {
        cout << "" << e.what() << endl;
    }
}

// Validación de 8 bits
bool esBinarioValido(const string& instruccion) {
    if (instruccion.length() != 8) return false;
    for (char c : instruccion) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

// Dividir la línea en instrucciones
vector<string> separarInstrucciones(const string& linea) {
    vector<string> instrucciones;
    stringstream ss(linea);
    string palabra;
    while (ss >> palabra) {
        instrucciones.push_back(palabra);
    }
    return instrucciones;
}

int main() {
    cout << "Ingrese las instrucciones binarias (mínimo 3, separadas por espacios): ";
    string lineaEntrada;
    getline(cin, lineaEntrada);

    vector<string> instrucciones = separarInstrucciones(lineaEntrada);

    if (instrucciones.size() < 3) {
        cout << "Error: Debes ingresar al menos 3 instrucciones de 8 bits." << endl;
        return 1;
    }

    for (size_t i = 0; i < instrucciones.size(); i++) {
        cout << "\nInstrucción " << i + 1 << ": " << instrucciones[i] << endl;
        if (!esBinarioValido(instrucciones[i])) {
            cout << "Error: Instrucción inválida (debe tener exactamente 8 bits con 0s y 1s)." << endl;
            continue;
        }
        decodificarInstruccion(instrucciones[i]);
    }

    return 0;
}
