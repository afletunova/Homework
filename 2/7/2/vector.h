#pragma once

class OutOfRangeError
{};

template <int n>
class Vector
{
public:
    Vector(){}
    Vector(const Vector<n> &object);
    Vector(int *&array);
    int &operator [](const int index);
    int at(const int index) const;
    Vector operator +(const Vector<n> &object) const;
    Vector operator -(const Vector<n> &object) const;
    int operator *(const Vector<n> &object) const;
    bool operator ==(const Vector<n> &object) const;
    bool isNull() const;

private:
    int vector[n] = {};
};

template <int n>
Vector<n>::Vector(const Vector<n> &object)
{
    for (int i = 0; i < n; ++i)
    {
        vector[i] = object.at(i);
    }
}

template <int n>
Vector<n>::Vector(int *&array)
{
    for (int i = 0; i < n; ++i)
    {
        vector[i] = array[i];
    }
}

template <int n>
int &Vector<n>::operator [](const int index)
{
    if ((index < 0) || (index >= n))
    {
        throw OutOfRangeError();
    }
    return vector[index];
}

template <int n>
int Vector<n>::at(const int index) const
{
    if ((index < 0) || (index >= n))
    {
        throw OutOfRangeError();
    }
    return vector[index];
}

template <int n>
Vector<n> Vector<n>::operator +(const Vector<n> &object) const
{
    Vector<n> newVector;
    for (int i = 0; i < n; ++i)
    {
        newVector[i] = vector[i] + object[i];
    }
    return newVector;
}

template <int n>
Vector<n> Vector<n>::operator -(const Vector<n> &object) const
{
    Vector<n> newVector;
    for (int i = 0; i < n; ++i)
    {
        newVector[i] = vector[i] + object[i];
    }
    return newVector;
}

template <int n>
int Vector<n>::operator *(const Vector<n> &object) const
{
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result += (vector[i] * object[i]);
    }
    return result;
}

template <int n>
bool Vector<n>::operator ==(const Vector<n> &object) const
{
    for (int i = 0; i < n; ++i)
    {
        if (this->at(i) != object.at(i))
        {
            return false;
        }
    }
    return true;
}

template <int n>
bool Vector<n>::isNull() const
{
    bool isNull = false;
    for (int i = 0; i < n; ++i)
    {
        if (vector[i] == 0)
        {
            isNull = true;
            break;
        }
    }
    return isNull;
}

