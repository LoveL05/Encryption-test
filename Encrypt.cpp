#include <iostream>
#include <string>

using namespace std;

const string secret = "LoVe";
int main()
{
    string hello;
    cout << "Input string: ";
    cin >> hello;
    string res;
    string res2;
    for (int i = 0; i < hello.length(); i++)
    {
        res += secret.c_str()[i % secret.length()] ^ hello.c_str()[i];
    }

    cout << res << endl;

    for (int i = 0; i < hello.length(); i++)
    {
        res2 += secret.c_str()[i % secret.length()] ^ res.c_str()[i];
    }
    cout << res2 << endl;



}
