// Array.tpp
template <typename T>
Array<T>::Array()
    : _array(NULL), _size(0)
{
}


template <typename T>
Array<T>::Array(std::size_t size)
    : _array(new T[size]), _size(size)
{
}

template <typename T>
Array<T>::Array(const Array& other)
    : _array(new T[other._size]), _size(other._size)
{
    for (std::size_t i = 0; i < _size; ++i)
    {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] mData;
}

Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

T& Array::operator[](unsigned int index)
{
  if ( index >= _size )
    throw std::out_of_range("Index out of range");

  return _array[index];
}

const T& Array::operator[](unsigned int index) const
{
  if ( index >= _size )
    throw std::out_of_range("Index out of range");

  return _array[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return mSize;
}

