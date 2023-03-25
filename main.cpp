#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <random>
#include "enc.h"

using namespace std;

int main(int argc, char *argv[])
{  
    const int seed = 12;

    sillycrypt::enc d("https://www.youtube.com/watch?v=dQw4w9WgXcQ", seed);
    d.save("data.bin");

    cout << d.data << "\r\n";

    d.load("data.bin");
    string result = d.decode(seed);
    cout << result << "\r\n";

    return 0;
}