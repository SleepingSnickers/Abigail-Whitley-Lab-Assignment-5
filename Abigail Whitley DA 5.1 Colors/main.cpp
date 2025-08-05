#include "PicReader.h"
#include "Pixel.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<Pixel> pixels = PicReader::readPic("colors.txt");

    for (Pixel& p : pixels) {
        cout << p;
    }

    return 0;
}