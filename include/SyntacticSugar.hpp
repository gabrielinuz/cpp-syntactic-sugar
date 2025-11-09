// SyntacticSugar.hpp
// ✅ Todo con -> | C++11+ compatible | Educación realista
#ifndef SYNTACTIC_SUGAR_HPP
#define SYNTACTIC_SUGAR_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std; //aunque no es conveniente, no tenenmos que escribir std::
//--------------------------------------IO SECTION---------------------------------------//
// === Token especial para salto de línea ===
#define endline std::endl

/*std::endl hace flush + \n. En bucles, esto puede ralentizar. Una alternativa para bucles:*/
// #define newline '\n'   // solo salto, sin flush (más eficiente en bucles)

// === Macros de impresión (hasta 8 argumentos) ===
/*¿cuántas veces necesitás imprimir 9+ cosas en una sola línea en un entorno educativo? 😊
8 es un límite razonable (y rara vez se alcanza).*/
#define print(...)   do { PRINT_MACRO(__VA_ARGS__); } while(0)
#define printline(...)   do { PRINTLINE_MACRO(__VA_ARGS__); } while(0)
#define error(...)   do { ERROR_MACRO(__VA_ARGS__); } while(0)
#define input(...)   do { INPUT_MACRO(__VA_ARGS__); } while(0)

// === Dispatch por cantidad de argumentos ===
#define GET_9TH(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME

#define PRINT_MACRO(...)  GET_9TH(__VA_ARGS__, PRINT_8, PRINT_7, PRINT_6, PRINT_5, PRINT_4, PRINT_3, PRINT_2, PRINT_1)(__VA_ARGS__)
#define PRINTLINE_MACRO(...) GET_9TH(__VA_ARGS__, PRINTLINE_8, PRINTLINE_7, PRINTLINE_6, PRINTLINE_5, PRINTLINE_4, PRINTLINE_3, PRINTLINE_2, PRINTLINE_1)(__VA_ARGS__)
#define ERROR_MACRO(...)  GET_9TH(__VA_ARGS__, ERROR_8, ERROR_7, ERROR_6, ERROR_5, ERROR_4, ERROR_3, ERROR_2, ERROR_1)(__VA_ARGS__)
#define INPUT_MACRO(...)  GET_9TH(__VA_ARGS__, INPUT_8, INPUT_7, INPUT_6, INPUT_5, INPUT_4, INPUT_3, INPUT_2, INPUT_1)(__VA_ARGS__)

// === PRINT: std::cout << a << b << ... ===
#define PRINT_1(a)                     std::cout << a
#define PRINT_2(a,b)                   std::cout << a << b
#define PRINT_3(a,b,c)                 std::cout << a << b << c
#define PRINT_4(a,b,c,d)               std::cout << a << b << c << d
#define PRINT_5(a,b,c,d,e)             std::cout << a << b << c << d << e
#define PRINT_6(a,b,c,d,e,f)           std::cout << a << b << c << d << e << f
#define PRINT_7(a,b,c,d,e,f,g)         std::cout << a << b << c << d << e << f << g
#define PRINT_8(a,b,c,d,e,f,g,h)       std::cout << a << b << c << d << e << f << g << h

// === PRINTLINE: igual que PRINT, pero con std::endl al final ===
#define PRINTLINE_1(a)                     std::cout << a << std::endl
#define PRINTLINE_2(a,b)                   std::cout << a << b << std::endl
#define PRINTLINE_3(a,b,c)                 std::cout << a << b << c << std::endl
#define PRINTLINE_4(a,b,c,d)               std::cout << a << b << c << d << std::endl
#define PRINTLINE_5(a,b,c,d,e)             std::cout << a << b << c << d << e << std::endl
#define PRINTLINE_6(a,b,c,d,e,f)           std::cout << a << b << c << d << e << f << std::endl
#define PRINTLINE_7(a,b,c,d,e,f,g)         std::cout << a << b << c << d << e << f << g << std::endl
#define PRINTLINE_8(a,b,c,d,e,f,g,h)       std::cout << a << b << c << d << e << f << g << h << std::endl

// === ERROR: std::cerr << a << b << ... ===
#define ERROR_1(a)                     std::cerr << a
#define ERROR_2(a,b)                   std::cerr << a << b
#define ERROR_3(a,b,c)                 std::cerr << a << b << c
#define ERROR_4(a,b,c,d)               std::cerr << a << b << c << d
#define ERROR_5(a,b,c,d,e)             std::cerr << a << b << c << d << e
#define ERROR_6(a,b,c,d,e,f)           std::cerr << a << b << c << d << e << f
#define ERROR_7(a,b,c,d,e,f,g)         std::cerr << a << b << c << d << e << f << g
#define ERROR_8(a,b,c,d,e,f,g,h)       std::cerr << a << b << c << d << e << f << g << h

// === INPUT: muestra prompts y lee variables ===
// Regla: argumentos pares → literales (prompt), impares → variables (a leer)
// Ej: input("Edad: ", edad) → std::cout << "Edad: "; std::cin >> edad;
#define INPUT_1(a)                     std::cin >> a
#define INPUT_2(a,b)                   std::cout << a; std::cin >> b
#define INPUT_3(a,b,c)                 std::cout << a; std::cin >> b; std::cout << c
#define INPUT_4(a,b,c,d)               std::cout << a; std::cin >> b; std::cout << c; std::cin >> d
#define INPUT_5(a,b,c,d,e)             std::cout << a; std::cin >> b; std::cout << c; std::cin >> d; std::cout << e
#define INPUT_6(a,b,c,d,e,f)           std::cout << a; std::cin >> b; std::cout << c; std::cin >> d; std::cout << e; std::cin >> f
#define INPUT_7(a,b,c,d,e,f,g)         std::cout << a; std::cin >> b; std::cout << c; std::cin >> d; std::cout << e; std::cin >> f; std::cout << g
#define INPUT_8(a,b,c,d,e,f,g,h)       std::cout << a; std::cin >> b; std::cout << c; std::cin >> d; std::cout << e; std::cin >> f; std::cout << g; std::cin >> h
//--------------------------------------END IO---------------------------------------//

//--------------------------------------CLASS SECTION---------------------------------------//
#define interface struct
#define abstract_class class
#define implements : public
#define extends : public

#define concrete_method(ret, name, ...) ret name(__VA_ARGS__)
#define override_method(ret, name, ...) ret name(__VA_ARGS__) override
#define virtual_method(ret, name, ...) virtual ret name(__VA_ARGS__)
#define abstract_method(ret, name, ...) virtual ret name(__VA_ARGS__) = 0
//--------------------------------------END CLASS---------------------------------------//

//--------------------------------------MEMORY & CONTAINERS---------------------------------------//
// Smart pointers
template<typename T> using shared_ref = std::shared_ptr<T>;
template<typename T> using unique_ref = std::unique_ptr<T>;

#define shared(T) shared_ref<T>
#define unique(T) unique_ref<T>

// Creación
#define new_shared(T, ...) std::make_shared<T>(__VA_ARGS__)
#define new_unique(T, ...) std::make_unique<T>(__VA_ARGS__)

// Contenedores: ¡directamente a contenedores STL!
template<typename T> using array_ref = std::vector<T>;
template<typename T> using list_ref = std::list<T>;
template<typename K, typename V> using dict_ref = std::unordered_map<K, V>;
template<typename T> using set_ref = std::unordered_set<T>;

#define array_of(T) array_ref<T>
#define list_of(T) list_ref<T>
#define dict_of(K, V) dict_ref<K, V>
#define set_of(T) set_ref<T>

//--------------------------------------END MEMORY & CONTAINERS---------------------------------------//

#endif // SYNTACTIC_SUGAR_HPP