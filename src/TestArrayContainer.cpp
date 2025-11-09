#include "../include/SyntacticSugar.hpp"

int main() 
{
    // Create a array of integers
    array_of(int) numbers;

    // Add elements to the array
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements
    printline("");
    printline("First element: ", numbers[0]);
    printline("Second element: ", numbers.at(1)); // Safe access

    // Iterate and print elements
    printline("All elements: ");
    for (int num : numbers) 
    {
        printline(num, " ");
    }
    print(endline);

    // Get the size
    printline("Array size: ", numbers.size());

    // También podemos inicializar con tamaño
    array_of(double) values(5, 3.14);
    printline("values[0] = ", values[0]);

    return 0;
}