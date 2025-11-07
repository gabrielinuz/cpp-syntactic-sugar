#include "../include/SyntacticSugar.hpp"

interface ICalculable
{
    abstract_method(double, calculate);
};

class Suma implements ICalculable
{
    public:
        override_method(double, calculate) 
        {
            double a, b;
            input("Ingrese A: ", a, " y B: ", b);
            return a + b;
        }
};

int main()
{
    print("🧮 Calculadora básica", endline);
    
    auto calc = new_shared(Suma);
    double res = calc->calculate();
    
    printline("✅ Resultado: ", res);
    return 0;
}