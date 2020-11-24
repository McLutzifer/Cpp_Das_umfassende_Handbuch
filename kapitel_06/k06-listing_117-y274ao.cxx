#include <vector>
#include <iostream>                  // cout, endl
int main() {
    std::vector qus{1,4,9,16,25};
    for(auto it = qus.begin(); it!=qus.end(); ++it) // zwischen begin() und end()
        std::cout << *it << " ";    // mit *it kommen Sie vom Iterator zum Element
    std::cout << std::endl;
}

