#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int n;
std::mutex mutexZero;
std::condition_variable cv;
int counter = 1;
bool isZeroPrinted = false;

void PrintOdd() {
    while (counter < n) {
        std::unique_lock<std::mutex> lock(mutexZero);
        cv.wait(lock, [] { return (counter % 2 != 0 && isZeroPrinted ); });

        if (counter < n) {
            std::cout << counter++;
            isZeroPrinted = false;
            cv.notify_all(); // Notify the other threads
        }
        else
            break;
    }
}

void PrintEven() {
    while (counter < n) {
        std::unique_lock<std::mutex> lock(mutexZero);
        cv.wait(lock, [] { return (counter % 2 == 0 && isZeroPrinted); });

        if (counter < n) {
            std::cout << counter++;
            isZeroPrinted = false;
            cv.notify_all(); // Notify the other threads
        }
        else
            break;
    }
}

void PrintZero() {

    for (int i = 0; i < n; ++i) {
        std::unique_lock<std::mutex> lock(mutexZero);
        cv.wait(lock, [] { return (!isZeroPrinted ); });
        std::cout << "0";
        isZeroPrinted = true;
        cv.notify_all();
    }
}

int main() {
    std::cout << "Enter range of n numbers: ";
    std::cin >> n;
    
    std::thread thread3(PrintZero);
    std::thread thread1(PrintOdd);
    std::thread thread2(PrintEven);

    thread3.join();
    thread1.join();
    thread2.join();

    std::cout << std::endl; // Print a newline after the series

    return 0;
}
