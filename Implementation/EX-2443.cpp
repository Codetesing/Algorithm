#include <iostream> 
using namespace std;
int main()
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * (count - i) - 1; j++)
            cout << "*";
        cout << "\n";
    }
}
