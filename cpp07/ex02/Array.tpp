// Array.tpp
template <typename T>
Array<T>::Array()
    : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : _size(n), _array(new T[n])
{
  if ( n < 0 )
    throw std::invalid_argument("Size cannot lower than 0");
}

template <typename T>
Array<T>::Array(const Array& other)
    : _size(other._size), _array(new T[other._size])
{
    for (std::size_t i = 0; i < _size; ++i)
    {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
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

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
  if ( index >= _size )
    throw std::out_of_range("Index out of range");

  return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
  if ( index >= _size )
    throw std::out_of_range("Index out of range");

  return _array[index];
}

template <typename T>
std::size_t Array<T>::size() const
{
    return _size;
}

