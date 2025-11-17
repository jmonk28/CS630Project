#include <iostream>
#include <chrono>

int main() {

    long long sum = 0;
    long long n = 984600000LL;

    std::cout << "Program starting...\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Start time: "
              << std::chrono::duration<double>(start.time_since_epoch()).count()
              << "\n";

    for (long long i = 1; i <= n; i++) {
        sum += i;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "End time: "
              << std::chrono::duration<double>(end.time_since_epoch()).count()
              << "\n";

    double elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << "Time elapsed: " << elapsed << " seconds\n";
    std::cout << "Sum: " << sum;

    return 0;
}
