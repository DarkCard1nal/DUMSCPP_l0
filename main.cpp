#include <iostream>

// LOG macro for logging
#define LOG(status, message) std::cout << #status ": " << message << std::endl;

// Macro to auto-generate print functions
#define GENERATE_PRINT_FUNCTION(name)         \
    void print##name() {                      \
        std::cout << #name "!" << std::endl;  \
    }

// Generate specific print functions
GENERATE_PRINT_FUNCTION(Hello)
GENERATE_PRINT_FUNCTION(World)

// Macro for secret operation
#define DO_SECRET_OPERATION(a, b)                             \
    std::cout << "Result: " << (SECRET_OPERATION(a, b)) << std::endl;

// Define ADD and MULTIPLY operations
#define ADD(a, b) ((a) + (b))
#define MULTIPLY(a, b) ((a) * (b))

// SUMUP macro to compute the sum of natural numbers
#define SUMUP(start, end) ([]() -> int {        \
    int sum = (start);                          \
    for (int i = 1; i <= (end); ++i) {          \
        sum += i;                               \
    }                                           \
    return sum;                                 \
}())

// Macro for Fibonacci numbers using recursion
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

int main()
{
	// Set the secret operation
#define SECRET_OPERATION MULTIPLY

	LOG(INFO, "Program starting");

	// Call auto-generated functions
	printHello();
	printWorld();

	LOG(DEBUG, "Hello World printed");

	// Perform the secret operation
	DO_SECRET_OPERATION(7, 8);

	// Calculate the sum of numbers
	std::cout << "SUMUP(0, 10): " << SUMUP(0, 10) << std::endl;

	// Calculate the 12th Fibonacci number
	std::cout << "FIBONACCI(12): " << FIBONACCI(12) << std::endl;

	LOG(INFO, "Program finished");

	return 0;
}
