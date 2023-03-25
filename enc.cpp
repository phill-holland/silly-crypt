#include "enc.h"
#include <iostream>
#include <fstream>

bool sillycrypt::enc::encode(std::string source, int seed)
{    
    if(source.length() == 0) return false;

    enc temp;
    
    std::mt19937 eng(seed);
    
    temp.length = source.length();
    std::unordered_map<int, char> map;

    int min = INT32_MAX;
    int max = INT32_MIN;

    std::vector<unsigned int> existing;

    for(int i=0; i< temp.length; ++i)
    {
        int t = get(eng, existing, (unsigned int)temp.length);

        if(t < min) min = t;
        if(t > max) max = t;

        map[t] = source[i];
    } 

    if((min != INT32_MAX)&&(max != INT32_MIN))
    {
        for(int i = min; i <= max; ++i)
        {
            temp.data.push_back(map[i]);
        }
    }

    (*this) = temp;

    return true;
}

std::string sillycrypt::enc::decode(int seed)
{
    std::string result;
    
    if(length <= 0) return result;
    if(data.length() == 0) return result;

    std::vector<unsigned int> existing;

    std::mt19937 eng(seed);
   
    for(int i=0; i < data.length() ; ++i)
    {
        int t = get(eng, existing, length);
        result.push_back(data[t]);
    }

    return result;
}

unsigned int sillycrypt::enc::get(std::mt19937 eng, std::vector<unsigned int> &existing, unsigned int length)
{
    std::vector<unsigned int>::iterator it;

    unsigned int q;

    do 
    {
        q = std::uniform_int_distribution<unsigned int>{0, length}(eng);
        it = std::find(existing.begin(), existing.end(), q);
    } while (it != existing.end());

    existing.push_back(q);

    return q;
};

bool sillycrypt::enc::load(std::string filename)
{
    enc temp;

    std::ifstream in(filename);
    int count = 0;

    for(std::string line; getline(in, line);)
    {
        if(count == 0) temp.length = stoi(line);
        else if(count == 1) temp.data = line;
        else break;

        ++count;
    }

    in.close();

    (*this) = temp;

    return count == 2;
}

bool sillycrypt::enc::save(std::string filename)
{
    if(data.length() == 0) return false;
    if(length <= 0) return false;

    std::ofstream out(filename);

    out << length << std::endl;
    out << data << std::endl;

    out.close();

    return true;
}