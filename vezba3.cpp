#include <iostream>

using namespace std;

int main() 
{    
    int n;
    cin >> n;
    if (n>0)
    cout <<"Vnesen e pozitiven broj"<< endl;
    else if (n<0)
    cout <<"Vnesen e negativen broj"<< endl;
    else
    cout <<"Vnesen e brojot 0"<< endl;
    return 0;
}