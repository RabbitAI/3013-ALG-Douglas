#include <iostream>

#define endl "\n";

using namespace std;

int main()
{
    int t = 0,
        a = 0, b = 0;

    cin >> t;

    if (t < 15)
    {
        for (int i = 0; i < t; ++i)
        {
            cin >> a >> b;

            if (a < b)
            {
                cout << "<\n";
            }
            else if (a > b)
            {
                cout << ">\n";
            }
            else if (a == b)
            {
                cout << "=\n";
            }
        }
    }

    return 0;
}