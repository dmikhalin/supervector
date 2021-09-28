#include <iostream>
#include "supervector.h"

using namespace std;

int main()
{
    int n, k;
    cout << "Input vector size:\n";
    cin >> n;
    SuperVector<int> a(n), b(n);
    cout << "Input elements of the first vector:\n";
    cin >> a;
    cout << "Input elements of the second vector:\n";
    cin >> b;
    cout << "Input an integer for multiplication:\n";
    cin >> k;

    cout << "Sum of vectors: " << a + b << endl;
    cout << "First vector multiplied by a number: " << a * k << endl;
}
