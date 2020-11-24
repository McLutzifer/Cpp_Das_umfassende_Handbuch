#include <vector>
#include <iostream>                     // cout, endl
int main() {
    std::vector quadrate{1,4,9,16,25}; // gefüllt initialisieren
    for(int zahl : quadrate)  // zahl ist ein Quadrat nach dem anderen
        std::cout << zahl << " ";
    std::cout << std::endl;
}

