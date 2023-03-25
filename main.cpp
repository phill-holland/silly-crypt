#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <random>

using namespace std;

const char my_array[] = {
'w','.','4',':',' ','?','h','t','/','Q','v','s','u',
'o','w','w','t',' ','W','X','t','o','d','w','/','c',
'c','e','w','Q','b','=','/','t','a','g','h','9','m',
'p','y','w','c','u','.',
};

std::vector<unsigned int> existing;

int get_rng(std::mt19937 eng, unsigned int length)
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
}

int main(int argc, char *argv[])
{
    const unsigned int length = 44;    
    
    std::mt19937 eng(12);
    existing.clear();

    string result;

    for(unsigned int i=0;i<length;++i)
    {
        int t = get_rng(eng, length);
        result += my_array[t];        
    }

    cout << result;

    return 0;
}

void compute()
{
    string url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ";

    cout << url.length() << "\r\n";

    const int length = 44;    
    char moo[length];
    memset(moo,0,length);
std::mt19937 eng(12);
    //srand(11);

    int min= 100;
    int max = 0;

    for(int i=0;i<length;++i)
    {
        int t = get_rng(eng, length);//rand() % length;
        if(t < min) min = t;
        if(t > max) max = t;
        if(moo[t] != 0) cout << "ERR CLASH " << t << "\r\n";
        moo[t] = url[i];
       // cout << t << "\r\n";
        //cout << rand() % 44 << "\r\n";
    } 

cout << "MIN " << min << "\r\n";
cout << "MAX " << max << "\r\n";

    for(int i=0;i<length;++i)
    {
        if(moo[i] != 0) cout << "'" << moo[i] << "',";// << "\r\n";
        else cout << "' ',";// << "\r\n";
    }

   // srand(11);
   std::mt19937 eng2(12);
   existing.clear();
cout << "\r\nHERE\r\n";
    for(int i=0;i<length;++i)
    {
        int t = get_rng(eng2,length);//rand() % length;        
        cout << moo[t];
    }
}

void read_bin()
{
    string line;
    ifstream in("data3.txt",ios::in | ios::binary);
    while(!in.eof())
    {
        char c;
        in.read(&c,1);
        if((c != 10)||(c!=13))
        {
            line += c;
        }
        else 
        {
            line.clear();
        }

        //string moo;
        //moo += c;
        //cout << moo;
    }
    in.close();
}

int main2(int argc, char *argv[])
{
    cout << "hello world!\n";


compute();
   // output();
    //cout << elf1() << "\r\n"; 
    //elf2();
    //read_bin();

    return 0;
}