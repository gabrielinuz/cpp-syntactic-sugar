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

void executeRunner(const_ref_of(shared(IRunner)) runner) 
{
    runner->run();  // ✅ OK: runner es const shared_ptr<IRunner>&
}

int main()
{
    printline("=== Sistema de Ejecución ===");
    
    // Creación con azúcar
    auto runner = new_shared(HelloWorldRunner);
    
    // Input simple
    string nombre;
    input("Ingrese su nombre: ", nombre);
    printline("Hola, ", nombre, " 👋");
    
    // Polimorfismo con alias
    shared(IRunner) r = runner;
    r->run();

    //Usar función para probar semántica de referencia constante:
    executeRunner(runner);
    
    printline("✅ Todo funcionó correctamente.");
    return 0;
}