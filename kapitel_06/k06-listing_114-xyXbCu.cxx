#include <vector>                    // Sie benötigen diesen Header
int main() {
    std::vector<int> quadrate{};     // leer initialisieren
    for(int idx = 0; idx<100; ++idx) {
        quadrate.push_back(idx*idx); // Anfügen eines Elements
    }
}

