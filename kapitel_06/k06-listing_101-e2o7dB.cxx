#include <iostream>
#include <string>
#include <string_view>

void zeige_mitte(std::string_view msg) {     // string_view ist ein guter Parameter
   auto mitte = msg.substr(2, msg.size()-4); // substr liefert string_view zurück
   std::cout << mitte << "\n";
}
int main() {
    using namespace std::literals;
    const std::string aaa = "##Etwas Text##"s;
    zeige_mitte(aaa);                        // Umwandlung in string_view
    auto bbb = "++Mehr Text++"sv;            // string_view als Literal
    zeige_mitte(bbb);
}

