#include <vector>
class Image {
    std::vector<char> data_;
public:
    void load(const char* filename); // lädt Bilddaten
};

class Screen {
public:
    void show(Image& image);         // image sollte const sein
};

void paint(Screen &screen, const Image& image) {
     screen.show(image);
}

int main() {
    Image image {};
    image.load("peter.png");
    Screen screen {};
    paint(screen, image);
}

