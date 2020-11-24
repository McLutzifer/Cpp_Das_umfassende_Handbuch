#include <iostream>
#include <bitset>

constexpr unsigned n_bits = sizeof(unsigned short)*8; // 8 Bit pro char
auto bits_umdrehen(unsigned val) -> unsigned short {
  unsigned short ret = 0;
  for (unsigned i = 0; i < n_bits; ++i ) {
    ret = (ret << 1) | (val & 1);    // eins zur Seite, unterstes evtl. setzen
    val >>= 1;                       // eins in die andere Richtung
  }
  return ret;
}
void zeig(unsigned short val) {
    std::bitset<n_bits> bits{val};
    std::cout << val << "=" << bits << " -> ";
    auto lav = bits_umdrehen(val);
    std::bitset<n_bits> stib{lav};
    std::cout << lav << "=" << stib << "\n";
}

int main() {
    zeig(36u);  // Ausgabe: 36=0000000000100100 -> 9216=0010010000000000
    zeig(199u); // Ausgabe: 199=0000000011000111 -> 58112=1110001100000000
    zeig(255u); // Ausgabe: 255=0000000011111111 -> 65280=1111111100000000
    zeig(256u); // Ausgabe: 256=0000000100000000 -> 128=0000000010000000
}

