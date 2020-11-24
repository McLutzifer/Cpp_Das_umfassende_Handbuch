#include <iostream> // cout

template<typename T>
void speicher(T x) {
    if constexpr(sizeof(T) > 4) {
       std::cout << "Braucht viel Speicher: " << x << " \n";
    }
}

constexpr auto DEBUG = true;
int main() {
    if constexpr(DEBUG) {
        std::cout << "Debug ist an.\n";
    }
    speicher<long long>(44LL);
}

