#include "../include/SyntacticSugar.hpp"

int main() 
{
    // Contenedores con . 
    array_of(int) numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    printline("Primero: ", numbers.at(0));
    printline("Tamaño: ", numbers.size());

    dict_of(string, int) counts;
    counts.insert({"a", 1});
    counts.insert({"b", 2});
    if (counts.find("a") != counts.end()) 
    {
        printline("a = ", counts.at("a"));
    }

    list_of(string) names;
    names.push_back("Ana");
    names.push_front("Carlos");
    // for (const auto name : names) // +2 copias, +2 destructores extra
    for (const auto& name : names) // Solo 2 constructores, 2 destructores
    { 
        printline(" - ", name);
    }

    return 0;
}