#include <iostream>                // cout
int main() {
    for(int x=1; x<20; x+=1) {     // äußere for-Schleife
        for(int y=1; y<20; y+=1) { // innere for-Schleife
            int prod = x*y;
            if(prod>=100) {
                break;             // raus aus innerer y-Schleife
            }
            std::cout << prod << " ";
        } /* Ende for y */
        // Ziel von break
    } /* Ende for x */             // erste wirkliche Zeile nach break
    std::cout << "\n";
}

