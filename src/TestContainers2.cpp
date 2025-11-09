#include "../include/SyntacticSugar.hpp"

int main() 
{
    printline("=== 🧪 Ejemplo: Contenedores Azucarados ===", endline);

    // --------------------------------------------------
    // 1. array_of(T) → vector dinámico con acceso por índice
    // --------------------------------------------------
    printline("1. array_of(int): acceso rápido por índice");
    // array_of(int) numbers = new_array(int);
    array_of(int) numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    printline("   • Primer elemento: ", numbers[0]);
    printline("   • Tamaño: ", numbers.size());
    printline("   • Elementos:");
    for (int x : numbers) 
    {
        print("     - ", x, " | ");
    }
    print(endline); // línea vacía

    // --------------------------------------------------
    // 2. list_of(T) → lista doblemente enlazada (inserción eficiente)
    // --------------------------------------------------
    printline("2. list_of(string): inserción al inicio y final");
    // list_of(string) names = new_list(string);
    list_of(string) names;
    names.push_back("Carlos");
    names.push_front("Ana");      // ✅ eficiente en lista
    names.push_back("Beatriz");

    printline("   • Nombres (orden de inserción):");
    for (const auto& name : names) 
    {
        printline("     - ", name);
    }
    printline("   • Cantidad: ", names.size());

    // --------------------------------------------------
    // 3. dict_of(K,V) → diccionario (clave-valor)
    // --------------------------------------------------
    printline("3. dict_of(string, int): conteo de ocurrencias");
    dict_of(string, int) wordCount;

    vector<string> words = {"hola", "mundo", "hola", "cpp", "mundo", "hola"};
    for (const auto& word : words) 
    {
        wordCount[word]++;  // ✅ operator[] crea entrada si no existe
    }

    printline("   • Frecuencia de palabras:");
    for (const auto& kv : wordCount) 
    {
        printline("     - '", kv.first, "': ", kv.second, " veces");
    }

    // Búsqueda segura
    string query = "cpp";
    // if (wordCount.contains(query))
    if(wordCount.find("admin") != wordCount.end()) 
    {
        printline("   • '", query, "' aparece ", wordCount.at(query), " veces");
    } 
    else
    {
        printline("   • '", query, "' no encontrado");
    }

    // --------------------------------------------------
    // 4. set_of(T) → conjunto sin duplicados
    // --------------------------------------------------
    printline("4. set_of(string): nombres únicos");
    // set_of(string) uniqueUsers = new_set(string);
    set_of(string) uniqueUsers;
    uniqueUsers.insert("admin");
    uniqueUsers.insert("user1");
    uniqueUsers.insert("admin");  // ✅ se ignora (ya existe)
    uniqueUsers.insert("user2");

    printline("   • Usuarios únicos (", uniqueUsers.size(), "):");
    for (const auto& user : uniqueUsers)
    {
        printline("     - ", user);
    }

    // Verificación de existencia
    // if (uniqueUsers.contains("admin"))
    if(uniqueUsers.find("admin") != uniqueUsers.end())
    {
        printline("   • 'admin' está en el conjunto ✅");
    }

    // --------------------------------------------------
    // 5. Integración: procesamiento de datos
    // --------------------------------------------------
    printline("\n=== 🧩 Integración: Registro de actividades ===");
    
    // Datos: (usuario, acción, tiempo)
    struct LogEntry
    {
        string user;
        string action;
        int timestamp;
    };

    array_of(LogEntry) logs;
    logs.push_back({"Ana", "login", 100});
    logs.push_back({"Carlos", "edit", 105});
    logs.push_back({"Ana", "save", 110});
    logs.push_back({"Beatriz", "login", 115});

    // Contar acciones por usuario
    // dict_of(string, int) actionsByUser = new_dict(string, int);
    dict_of(string, int) actionsByUser;
    // Registrar usuarios únicos
    // set_of(string) activeUsers = new_set(string);
    set_of(string) activeUsers;

    for (const auto& log : logs)
    {
        actionsByUser[log.user]++;   // incrementa contador
        activeUsers.insert(log.user); // agrega sin duplicados
    }

    printline("   • Acciones por usuario:");
    for (const auto& kv : actionsByUser)
    {
        printline("     - ", kv.first, ": ", kv.second, " acción(es)");
    }

    printline("   • Usuarios activos (", activeUsers.size(), "): ", endline);
    for (const auto& user : activeUsers)
    {
        print("     ", user, " | ");
    }
    print(endline);

    printline("✅ Ejemplo completado. ¡Todo funciona con sintaxis limpia!", endline);
    return 0;
}