// Array.tpp
template <typename T>
Array<T>::Array(std::size_t size)
    : mData(new T[size]), mSize(size)
{
}

template <typename T>
Array<T>::~Array()
{
    delete[] mData;
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
    return mData[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
    return mData[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return mSize;
}

