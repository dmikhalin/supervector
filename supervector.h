#ifndef SUPERVECTOR_SUPERVECTOR_H
#define SUPERVECTOR_SUPERVECTOR_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename T>
class SuperVector
{
    int n;
    vector<T> data;
public:
    SuperVector(vector<T>);
    SuperVector(int n_);
    int size() const { return n; };
    const SuperVector operator+(const SuperVector&) const;
    const SuperVector operator*(T) const;
    T& operator[](int i) { return data[i]; };
    const T& operator[](int i) const { return data[i]; };
    template<typename Type> friend istream& operator>>(istream&, SuperVector<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, const SuperVector<Type>&);
};

template<typename T>
SuperVector<T>::SuperVector(vector<T> vect)
{
    data = vect;
    n = vect.size();
}

template<typename T>
SuperVector<T>::SuperVector(int n_)
{
    n = n_;
    data.assign(n, 0);
}

template<typename T>
const SuperVector<T> SuperVector<T>::operator+(const SuperVector& a) const
{
    if (a.size() != n)
        throw "Arrays have different sizes";
    vector<T> res(n);
    if (a.size() == n)
        for (int i = 0; i < n; ++i)
            res[i] = data[i] + a.data[i];
    return SuperVector(res);
}

template<typename T>
const SuperVector<T> SuperVector<T>::operator*(T k) const
{
    vector<T> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = data[i] * k;
    return SuperVector(res);
}

template<typename T>
ostream& operator<<(ostream& out, const SuperVector<T>& a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}

template<typename T>
istream &operator>>(istream& in, SuperVector<T>& a) {
    for (int i = 0; i < a.size(); ++i)
        in >> a[i];
    return in;
}

#endif //SUPERVECTOR_SUPERVECTOR_H
