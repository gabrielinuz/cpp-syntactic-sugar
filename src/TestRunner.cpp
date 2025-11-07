#include "../include/SyntacticSugar.hpp"

interface IRunner
{
    abstract_method(void, run);
};

class HelloWorldRunner implements IRunner
{
public:
    override_method(void, run)
    {
        printline("🌟 ¡Hola desde un runner!");
    }
};

int main()
{
    printline("=== Sistema de Ejecución ===");
    
    // Creación con azúcar
    auto runner = new_shared(HelloWorldRunner);
    
    // Input simple
    std::string nombre;
    input("Ingrese su nombre: ", nombre);
    printline("Hola, ", nombre, " 👋");
    
    // Polimorfismo con alias
    shared(IRunner) r = runner;
    r->run();
    
    printline("✅ Todo funcionó correctamente.");
    return 0;
}