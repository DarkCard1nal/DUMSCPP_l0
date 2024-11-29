# DUMSCPP_l0

_Created for the course "Development using modern C++ standards" V. N. Karazin Kharkiv National University_

"PreprocessorCommands" CMake linux program using C++17 standard.

---

# Preprocessor Commands in C++

## Overview

This project demonstrates the use of C++ preprocessor directives for automating tasks like logging, function generation, and computation. The goal is to understand the functionality of the C++ preprocessor and its capabilities. While preprocessing is a necessary part of any C++ program, its extensive use—such as for complex macros—should generally be avoided due to maintenance and debugging challenges. This project focuses on experimenting with macros to illustrate their power and limitations.

### Key Preprocessor Macros Implemented

1. **`LOG`**: 
   A logging macro that takes two parameters: `status` and `message`, and prints them in the format:
   ```
   STATUS: Message
   ```
   Example:
   ```cpp
   LOG(INFO, "Program starting");
   // Output: INFO: Program starting
   ```

2. **Function Auto-Generation**:
   The macro `GENERATE_PRINT_FUNCTION` automatically creates functions like `printHello()` or `printWorld()` that print specific messages.
   Example:
   ```cpp
   GENERATE_PRINT_FUNCTION(Hello)
   printHello(); // Output: Hello!
   ```

3. **`DO_SECRET_OPERATION`**:
   A macro that performs a "secret operation" between two numbers, defined by the `SECRET_OPERATION` macro. For instance:
   ```cpp
   #define SECRET_OPERATION MULTIPLY
   DO_SECRET_OPERATION(7, 8); // Output: Result: 56
   ```

4. **`SUMUP`**:
   A macro that calculates the sum of natural numbers from 1 to `end`, added to an initial value `start`. Example:
   ```cpp
   std::cout << SUMUP(0, 10); // Output: 55
   ```

5. **`FIBONACCI`**:
   A macro that calculates the `N`-th Fibonacci number using an iterative approach.
   Example:
   ```cpp
   std::cout << FIBONACCI(12); // Output: 144
   ```

---

## Code Explanation

### Logging Macro: `LOG`
```cpp
#define LOG(status, message) std::cout << #status ": " << message << std::endl;
```
- Converts the parameter `status` to a string and prints a formatted message.
- Example: `LOG(INFO, "Starting...")` outputs `INFO: Starting...`.

### Function Generation: `GENERATE_PRINT_FUNCTION`
```cpp
#define GENERATE_PRINT_FUNCTION(name)         \
    void print##name() {                      \
        std::cout << #name "!" << std::endl;  \
    }
```
- Dynamically generates functions like `printHello()` or `printWorld()` at compile time.
- Example: 
  ```cpp
  GENERATE_PRINT_FUNCTION(Hello)
  printHello(); // Output: Hello!
  ```

### Secret Operation Macro: `DO_SECRET_OPERATION`
```cpp
#define DO_SECRET_OPERATION(a, b)                             \
    std::cout << "Result: " << (SECRET_OPERATION(a, b)) << std::endl;
```
- Performs an operation defined by the macro `SECRET_OPERATION`. This operation could be `ADD`, `MULTIPLY`, etc.
- Example:
  ```cpp
  #define SECRET_OPERATION MULTIPLY
  DO_SECRET_OPERATION(7, 8); // Output: Result: 56
  ```

### Sum of Natural Numbers: `SUMUP`
```cpp
#define SUMUP(start, end) ([]() -> int {        \
    int sum = (start);                          \
    for (int i = 1; i <= (end); ++i) {          \
        sum += i;                               \
    }                                           \
    return sum;                                 \
}())
```
- Computes the sum of natural numbers from `1` to `end`, starting with an initial value `start`.
- Example: `SUMUP(0, 10)` outputs `55`.

### Fibonacci Numbers: `FIBONACCI`
```cpp
#define FIBONACCI(n) ([](int N) -> int {        \
    if (N == 0) return 0;                       \
    if (N == 1) return 1;                       \
    int fib1 = 0, fib2 = 1, result = 0;         \
    for (int i = 2; i <= N; ++i) {              \
        result = fib1 + fib2;                   \
        fib1 = fib2;                            \
        fib2 = result;                          \
    }                                           \
    return result;                              \
}(n))
```
- Calculates the `N`-th Fibonacci number using an iterative approach.
- Example: `FIBONACCI(12)` outputs `144`.

---

## Main Function

The `main` function demonstrates the usage of these macros:

```cpp
#define SECRET_OPERATION MULTIPLY

int main() {
    LOG(INFO, "Program starting");

    // Auto-generated functions
    printHello();
    printWorld();

    LOG(DEBUG, "Hello World printed");

    // Perform secret operation
    DO_SECRET_OPERATION(7, 8);

    // Compute the sum of numbers
    std::cout << "SUMUP(0, 10): " << SUMUP(0, 10) << std::endl;

    // Compute the 12th Fibonacci number
    std::cout << "FIBONACCI(12): " << FIBONACCI(12) << std::endl;

    LOG(INFO, "Program finished");

    return 0;
}
```

---

## Sample Output

```
INFO: Program starting
Hello!
World!
DEBUG: Hello World printed
Result: 56
SUMUP(0, 10): 55
FIBONACCI(12): 144
INFO: Program finished
```

---

## Notes on Preprocessor Use
- The preprocessor is powerful for automating tasks but should be used sparingly.
- Complex macros can make code harder to debug and maintain.
- Use standard conventions (e.g., uppercase names for macros) for readability.
