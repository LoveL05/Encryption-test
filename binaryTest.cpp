#include "binaryTest.hpp"
#include <string>
#include <fstream>


using namespace std;

const string enc = "fsfse";
int main()
{
    string message = "Hello World!";

    string res;
    string res2;

    for (int i = 0; i < message.length(); i++)
    {
        res += enc.c_str()[i % enc.length()] ^ message.c_str()[i];
        printf("0x%02x %s", message[i], ((i + 1) % 16) ? " " : "\n");
    }

    cout << res << endl;

    for (int i = 0; i < res.length(); i++)
    {
        res2 += enc.c_str()[i % enc.length()] ^ res.c_str()[i];
    }

    cout << res2 << endl;

    FILE* f = fopen("namn.bin", "wb");

    fwrite(res.c_str(), 1, res.length(), f);

    fclose(f);
}
