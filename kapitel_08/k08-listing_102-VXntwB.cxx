#include <iostream>
#include <tuple> // make_tuple

auto mkTpl() {
    return std::make_tuple(2, 'b', 3.14); // tuple<int,char,double>
}

struct Point {
    int x, y;
};

int main() {
    // Strukuriertes Binden eines C-Arrays
    int ungerade[5] = { 1,3,7,9,11 };
    auto [ eins, zwei, drei, vier, fuenf ] = ungerade;
    // Strukuriertes Binden eines Tupels
    auto [ two, bee, pi ] = mkTpl();
    // Strukuriertes Binden einer Struktur
    Point p0{  10, 15 };
    auto [ the_x, the_y ] = p0;
}

