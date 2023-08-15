#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#include <vector>
#include <deque>

template <typename T>
static typename std::vector<T>::iterator binary_search(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last, T &val)
{
    while (std::distance(first, last) >= 2)
    {
        typename std::vector<T>::iterator middle = first + std::distance(first, last) / 2;
        if (val < *middle)
            last = middle; // Update last to middle, search in the left part
        else
            first = middle; // Update first to middle, search in the right part
    }

    if (val < *first)
        return first;
    else
        return last;
}

template <typename T>
static typename std::deque<T>::iterator binary_search(typename std::deque<T>::iterator first, typename std::deque<T>::iterator last, T &val)
{
    while (std::distance(first, last) >= 2)
    {
        typename std::deque<T>::iterator middle = first + std::distance(first, last) / 2;
        if (val < *middle)
            last = middle; // Update last to middle, search in the left part
        else
            first = middle; // Update first to middle, search in the right part
    }

    if (val < *first)
        return first;
    else
        return last;
}
#endif
