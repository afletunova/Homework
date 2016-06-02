#pragma once

template <typename T>
/*!
 * \brief The SharedPointer class - class represent pointer implemented by counting the links to the allocated memory.
 */
class SharedPointer
{
public:
    SharedPointer(T *pointer);
    SharedPointer(const SharedPointer<T> &object);
    T &operator *() const;
    void operator =(const SharedPointer<T> &object);
    /*!
     * \brief get
     * \return pointer to the object
     */
    T *get() const;
    int useCount();
    ~SharedPointer();

private:
    /*!
     * \brief The Pointer class - internal pointer
     */
    class Pointer
    {
    public:
        Pointer()
            :pointer(nullptr), count(1)
        {}
        Pointer(T *pointer)
            :pointer(pointer), count(1)
        {}

        ~Pointer()
        {
            delete pointer;
        }

        T *pointer;
        int count;
    };

    void removePointer();
    Pointer *pointer;
};

template <typename T>
SharedPointer<T>::SharedPointer(T *pointer)
{
    this->pointer = new Pointer(pointer);
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &object)
{
    pointer = object.pointer;
    ++pointer->count;
}

template <typename T>
T &SharedPointer<T>::operator *() const
{
    return *(pointer->pointer);
}

template <typename T>
void SharedPointer<T>::operator =(const SharedPointer<T> &object)
{
    removePointer();
    pointer = object.pointer;
    ++pointer->count;
}

template <typename T>
T *SharedPointer<T>::get() const
{
    return pointer->pointer;
}

template <typename T>
int SharedPointer<T>::useCount()
{
    return pointer->count;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    removePointer();
}

template <typename T>
void SharedPointer<T>::removePointer()
{
    --pointer->count;
    if (pointer->count == 0)
    {
        delete pointer;
    }
}
