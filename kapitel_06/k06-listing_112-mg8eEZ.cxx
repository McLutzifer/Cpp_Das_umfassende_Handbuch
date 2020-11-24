#include <array>
#include <iostream>
constexpr size_t MONATE = 12; /* Monate im Jahr */
int main() {
    std::array<unsigned,MONATE> mtage = {     // okay mit einer Konstante
        31,28,31,30,31,30,31,31,30,31,30,31};
    unsigned alter = 0;
    std::cout << "Wie alt sind Sie? "; std::cin >> alter;
    std::array<int,alter> lebensjahre;       // Arraygröße geht nicht per Variable
}

