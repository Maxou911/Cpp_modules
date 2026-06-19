# Cpp_modules

# 42 — C++ Modules (CPP00 → CPP09)

> **Language:** C++98  
> **Compilation:** `c++ -Wall -Wextra -Werror -std=c++98`  
> **Standard:** Orthodox Canonical Form required from CPP04 onward

---

## Table of Contents

- [CPP00 — Introduction to C++](#cpp00--introduction-to-c)
- [CPP01 — Memory, Pointers & References](#cpp01--memory-pointers--references)
- [CPP02 — Canonical Form & Operator Overloading](#cpp02--canonical-form--operator-overloading)
- [CPP03 — Inheritance](#cpp03--inheritance)
- [CPP04 — Polymorphism & Interfaces](#cpp04--polymorphism--interfaces)
- [CPP05 — Exceptions](#cpp05--exceptions)
- [CPP06 — C++ Casts](#cpp06--c-casts)
- [CPP07 — Templates](#cpp07--templates)
- [CPP08 — STL Containers](#cpp08--stl-containers)
- [CPP09 — Advanced STL Algorithms](#cpp09--advanced-stl-algorithms)

---

## CPP00 — Introduction to C++

### Concepts covered

- Namespaces and scope resolution
- Classes and objects: declaration, definition, instantiation
- Member functions and attributes
- C++ I/O streams: `std::cin`, `std::cout`, `std::cerr`
- Member initialization lists

### Key points

The transition from C to C++ begins here. The focus is on understanding the class system, encapsulation, and replacing C-style I/O with C++ streams. `std::string` is preferred over raw C strings, and `std::cout` is expected over `printf`.

---

## CPP01 — Memory, Pointers & References

### Concepts covered

- Dynamic memory allocation: `new` / `delete` (and array forms `new[]` / `delete[]`)
- Difference between a **pointer** and a **reference**
- Pass by reference vs. pass by value
- Pointers to class members
- `const` qualifiers

### Key points

A reference is an alias — it can never be `NULL` and cannot be rebound after initialization. A pointer is a variable holding an address — it can be `NULL` and can be reassigned. Always prefer references when `NULL` is not a valid state. Never return a reference to a local variable, as it will be destroyed when the function returns.

---

## CPP02 — Canonical Form & Operator Overloading

### Concepts covered

- **Orthodox Canonical Form (OCF)** — four mandatory functions
- Arithmetic, comparison, and stream operator overloading
- Fixed-point number representation

### Orthodox Canonical Form

Every class must implement the following four elements:

| Element | Purpose |
|---|---|
| Default constructor | Creates an object with default state |
| Copy constructor | Creates a new object as a copy of another |
| Copy assignment operator | Copies the state of one object into an existing one |
| Destructor | Cleans up resources when the object is destroyed |

### Key points

Operator overloading allows user-defined types to behave like built-in types with natural syntax. The stream insertion operator (`<<`) should be implemented as a `friend` function to allow access to private members while keeping the left-hand side as `std::ostream`.

---

## CPP03 — Inheritance

### Concepts covered

- Simple and multiple inheritance
- `public`, `protected`, and `private` inheritance
- Explicit base class constructor calls
- Method overriding (without polymorphism)
- The **Diamond Problem** and virtual inheritance

### Key points

Inheritance allows a class to reuse the interface and implementation of another. The base class constructor must be called explicitly in the derived class's initialization list. When two classes inherit from the same base and a third inherits from both, member data is duplicated — this is the Diamond Problem. Virtual inheritance resolves this by ensuring only one copy of the base class exists in the hierarchy.

---

## CPP04 — Polymorphism & Interfaces

### Concepts covered

- Virtual functions and the vtable mechanism
- Virtual destructors (mandatory when using polymorphism)
- **Abstract classes** and pure virtual methods
- Interfaces (fully abstract classes)
- Deep copy vs. shallow copy

### Key points

A virtual function allows the correct method to be called at runtime based on the actual type of the object, even when accessed through a base class pointer. A pure virtual method has no implementation in the base class and forces derived classes to provide one — making the base class abstract and non-instantiable.

The destructor must be virtual in any class intended to be used polymorphically; otherwise, deleting a derived object through a base pointer causes undefined behavior.

When a class holds a pointer to a heap-allocated resource, the default copy constructor and assignment operator perform a shallow copy (copying the pointer address). This leads to double-free errors. A **deep copy** allocates new memory and copies the pointed-to data instead.

---

## CPP05 — Exceptions

### Concepts covered

- `try` / `catch` / `throw` mechanism
- Custom exception classes inheriting from `std::exception`
- Exception hierarchies
- Exception safety guarantees (basic, strong, no-throw)

### Key points

Exceptions provide a structured way to handle error conditions without relying on return codes. Custom exception classes should inherit from `std::exception` and override the `what()` method to return a descriptive error message.

Always catch exceptions by reference to avoid object slicing. When multiple exception types are possible, order `catch` blocks from most specific to most general. The `std::exception` catch should always be last as a fallback.

---

## CPP06 — C++ Casts

### Concepts covered

- `static_cast` — compile-time checked conversions
- `dynamic_cast` — safe runtime downcasting (requires at least one virtual method)
- `reinterpret_cast` — raw bit reinterpretation

### Cast summary

| Cast | When to use | Safety |
|---|---|---|
| `static_cast` | Numeric conversions, known up/downcasts | Compile-time |
| `dynamic_cast` | Uncertain polymorphic downcast | Runtime (returns `nullptr` on failure) |
| `reinterpret_cast` | Pointer ↔ integer, raw serialization | None |
| `const_cast` | Removing `const` in exceptional cases | None |

### Key points

C-style casts (`(Type)value`) should never be used in C++ — they are ambiguous and bypass type safety. C++ casts make the programmer's intent explicit and allow the compiler and runtime to enforce safety where possible. `dynamic_cast` is the only cast that can fail gracefully at runtime, returning `nullptr` for pointer types or throwing `std::bad_cast` for references.

---

## CPP07 — Templates

### Concepts covered

- Function templates
- Class templates
- Template specialization
- `typename` vs. `class` keyword

### Key points

Templates allow writing generic code that works with any type without sacrificing type safety. The compiler generates a concrete implementation for each type used at instantiation. In C++98, the full template definition (including the implementation) must be visible at the point of instantiation — typically placed in the `.hpp` or in a `.tpp` file included from it.

Template specialization allows providing a custom implementation for a specific type when the generic version would be incorrect or suboptimal.

---

## CPP08 — STL Containers

### Concepts covered

- Sequential containers: `std::vector`, `std::list`, `std::deque`
- Associative containers: `std::map`, `std::set`
- Iterators and their categories
- STL algorithms: `std::find`, `std::sort`
- `std::stack` container adaptor

### Key points

The STL provides a collection of generic, reusable containers and algorithms. Iterators act as a common interface between containers and algorithms, decoupling them. Choosing the right container depends on the access pattern: `std::vector` for random access, `std::list` for frequent insertions/deletions in the middle, `std::map` for key-value lookups.

Container adaptors like `std::stack` and `std::queue` restrict the interface of an underlying container to enforce a specific access pattern (LIFO, FIFO).

---

## CPP09 — Advanced STL Algorithms

### Concepts covered

- File parsing and data processing (e.g. stock price database)
- `std::map` for O(log n) key-based access
- `std::stack` for RPN calculator
- `std::deque`, `std::vector` and the **Ford-Johnson algorithm** (merge-insertion sort)
- Performance comparison between containers

### Key points

This module applies STL knowledge to real algorithmic problems. The Bitcoin Exchange exercise reinforces map lookups with `lower_bound` for nearest-date queries. The RPN Calculator uses a stack to evaluate postfix expressions. The PmergeMe exercise implements the Ford-Johnson merge-insertion sort — one of the most comparison-efficient sorting algorithms — on both `std::vector` and `std::deque`, comparing their real-world performance.

---

## General Rules (all modules)

- Compile with: `c++ -Wall -Wextra -Werror -std=c++98`
- No `malloc` / `free` — use `new` / `delete`
- No forbidden C functions (refer to each subject)
- One class per pair of `.hpp` / `.cpp` files
- Orthodox Canonical Form is mandatory from CPP02 onward
- No memory leaks tolerated — check with `valgrind`
- All headers must be protected with include guards

---

*Modules completed as part of the 42 school C++ curriculum — CPP00 to CPP09.*
