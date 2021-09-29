#include <iostream>
#include "supervector.h"

using namespace std;

int main()
{
    int n, m, k;
    cout << "Input first vector size:\n";
    cin >> n;
    SuperVector<int> a(n);
    cout << "Input elements of the first vector:\n";
    cin >> a;
    cout << "Input second vector size:\n";
    cin >> m;
    SuperVector<int> b(m);
    cout << "Input elements of the second vector:\n";
    cin >> b;
    cout << "Input an integer for multiplication:\n";
    cin >> k;

    try
    {
        cout << "Sum of vectors: " << a + b << endl;
    }
    catch (const char* msg)
    {
        cerr << "Exception caught: " << msg << endl;
    }

    cout << "First vector multiplied by a number: " << a * k << endl;
}
