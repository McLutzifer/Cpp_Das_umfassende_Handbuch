#include <iostream>
int main() {
    int idx = 4;
    goto mehr;                           // springe zu Label mehr
  drucke:                                // nächste Anweisung hat ein Label
    std::cout << idx << std::endl;
    idx = idx * 2;
  mehr:
    idx = idx + 3;
    if(idx < 20)
        goto drucke;                     // goto kann auch in einem if stehen
  ende:                                  // dies ist ein Label, wird aber nicht verwendet
    return 0;
}

