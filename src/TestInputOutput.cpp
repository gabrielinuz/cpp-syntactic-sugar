#include "../include/SyntacticSugar.hpp"

int main() 
{
    std::string nombre;
    int edad;
    double altura;

    print("=== Registro de usuario ===", endline);
    
    input("Nombre: ", nombre);
    input("Edad: ", edad);
    input("Altura (m): ", altura);

    print(endline);  // línea vacía
    print("✅ Usuario registrado:", endline);
    print("  Nombre: ", nombre, endline);
    print("  Edad: ", edad, " años", endline);
    print("  Altura: ", altura, " m", endline);

    // También combinado:
    int a, b;
    input("Ingrese un número: ", a, " y otro: ", b);
    printline("Suma: ", a + b);

    return 0;
}