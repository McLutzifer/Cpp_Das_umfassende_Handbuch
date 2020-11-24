int main() {
    int ungerade[5] = { 1,3,7,9,11 };
    auto &[ eins, zwei, drei, vier, fuenf ] = ungerade;
    auto &[ two, bee, pi ] = mkTpl();   // kein Binden an Tempwerte
    Point p0{  10, 15 };
    auto &[ the_x, the_y ] = p0;
}

