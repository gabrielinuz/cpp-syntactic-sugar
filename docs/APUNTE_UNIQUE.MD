# 📝 APUNTE: ¿Por qué no copiamos `unique_ptr`, y cuándo usar `&`, `&&`, o `*` con smart pointers?

> 🎓 *Material didáctico para estudiantes de Tecnicatura Superior en Análisis de Sistemas*  
> ✦ Por el Tecnólogo Educativo — para que entiendas no solo **cómo**, sino **por qué** ✦

---

## 🔑 1. El principio de *ownership* (posesión)

En C++, la memoria no se gestiona "mágicamente".  
Cada recurso (como un objeto en el *heap*) debe tener **un único responsable** de liberarlo.

| Smart pointer | Semántica | ¿Se puede copiar? |
|---------------|-----------|-------------------|
| `std::shared_ptr<T>` | **Varios** comparten la responsabilidad (cuenta referencias). | ✅ Sí (`refcount++`) |
| `std::unique_ptr<T>` | **Solo uno** es responsable. *Exclusividad garantizada*. | ❌ **No** (constructor de copia borrado) |

### Ejemplo: `unique_ptr` no se copia
```cpp
auto a = std::make_unique<int>(42);
auto b = a;               // ❌ ERROR de compilación
auto b = std::move(a);    // ✅ OK: "a" entrega la responsabilidad a "b"
// Ahora: a == nullptr, b posee el 42.