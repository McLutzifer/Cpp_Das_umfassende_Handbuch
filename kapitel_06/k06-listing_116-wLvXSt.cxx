#include <vector>
#include <iostream>                        // cout, endl
int main() {
    std::vector qus{1,4,9,16,25};
    for(int idx=0; idx<qus.size(); ++idx)  // size enthält die Anzahl
        std::cout << qus[idx] << " ";      // [idx] oder at(idx) holt ein Element
    std::cout << std::endl;
}

