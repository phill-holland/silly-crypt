#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <random>

#ifndef _SILLYCRYPT
#define _SILLYCRYPT

namespace sillycrypt
{
    class enc
    {
    public:
        int length;
        std::string data;

    public:
        enc() { clear(); }
        enc(std::string source, int seed) 
        { 
            encode(source, seed); 
        }

        void clear() 
        { 
            length = 0; 
            data.clear(); 
        }

    public:
        bool encode(std::string source, int seed);
        std::string decode(int seed);

    protected:
        unsigned int get(std::mt19937 eng, std::vector<unsigned int> &existing, unsigned int length);

    public:
        bool load(std::string filename);
        bool save(std::string filename);
    };
};

#endif