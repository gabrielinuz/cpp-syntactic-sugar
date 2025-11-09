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

//En parámetros de funciones (muy común y educativo)
void logMessage(const_ref_of(string) msg) {  // → const string& msg
    printline("[LOG] ", msg);
}

void toUpperCase(ref_of(string) text) {  // → string& text
    for (char& c : text) c = std::toupper(c);
}

int main() 
{   
    printline("#################################################################");
    printline("Pruebas con Array: ");
    array_of(string) names;
    names.push_back("ana");
    names.push_back("carlos");

    for (const_ref_of(auto) name : names) 
    {
        printline(" - ", name);
    }

    printline("#################################################################");
    print("Variables inmutables: ");
    const_of(int) max_retries = 5;      // → const int max_retries = 5;
    const_ref_of(auto) first = names.at(0);  // → const auto& first = ...   
    printline("funcionan bien.");

    printline("#################################################################");
    printline("Pruebas con Interfaces: ");
    // Creación de runner con azúcar
    shared(IRunner) runner = new_shared(HelloWorldRunner);
    executeRunner(runner);
    return 0;
}