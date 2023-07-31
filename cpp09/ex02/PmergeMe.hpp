#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <queue>
#include <string>

typedef long long ll;

struct ComparePair {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    }
};

std::vector<ll> fillVector(int argc, char *argv[]);
ll __strtoll(std::string s);
void printVector(std::vector<ll> v);
void printVectorPair(std::vector<std::pair<ll, ll> > v);
void printPriorityQueue(std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll> >, ComparePair> pq); 


#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <list>
#include <iterator>
#include <type_traits>
#include <vector>

////////////////////////////////////////////////////////////
// Iterator used to sort views of the collection

template <typename Iterator>
class group_iterator
{
    private:
        Iterator _it; //underlying iterator that the group_iterator is wrapping.
        std::size_t _size; //size of the group that the group_iterator is wrapping.

    public:
        ////////////////////////////////////////////////////////////
        // Constructors

        group_iterator() = default;

        group_iterator(Iterator it, std::size_t size):
            _it(it),
            _size(size)
        {}

        ////////////////////////////////////////////////////////////
        // Members access

        Iterator base() const //useful to work the base iterator without going through the group_iterator.
        {
            return _it;
        }

        std::size_t size() const
        {
            return _size;
        }

        ////////////////////////////////////////////////////////////
        // Element access

        typename std::iterator_traits<Iterator>::reference operator*() const
        {
            return _it[_size - 1];
        }

        typename std::iterator_traits<Iterator>::reference operator->() const
        {
            return &(operator*());
        }

        ////////////////////////////////////////////////////////////
        // Increment/decrement operators
        group_iterator& operator++()
        {
            _it += _size;
            return *this;
        }

       group_iterator operator++(int)
        {
            auto tmp = *this;
            operator++();
            return tmp;
        }

        group_iterator& operator--()
        {
            _it -= _size;
            return *this;
        }

        group_iterator operator--(int)
        {
            auto tmp = *this;
            operator--();
            return tmp;
        }

        group_iterator& operator+=(std::size_t increment)
        {
            _it += _size * increment;
            return *this;
        }

        group_iterator& operator-=(std::size_t increment)
        {
            _it -= _size * increment;
            return *this;
        }

        ////////////////////////////////////////////////////////////
        // Elements access operators

        typename std::iterator_traits<Iterator>::reference operator[](std::size_t pos)
        {
            return _it[pos * _size + _size - 1];
        }

        typename std::iterator_traits<Iterator>::const_reference operator[](std::size_t pos) const
        {
            return _it[pos * _size + _size - 1];
        }
};

template<typename Iterator1, typename Iterator2>
void iter_swap(group_iterator<Iterator1> lhs, group_iterator<Iterator2> rhs)// the elements must of the same size.
{
    std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base()); //swap each element in the first range with the corresponding element in the second range.
}

////////////////////////////////////////////////////////////
// Comparison operators

template<typename Iterator1, typename Iterator2>
bool operator==(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator!=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() != rhs.base();
}

////////////////////////////////////////////////////////////
// Relational operators

template<typename Iterator1, typename Iterator2>
bool operator<(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() < rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() <= rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() > rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base >= rhs.base();
}

////////////////////////////////////////////////////////////
// Arithmetic operators

template<typename Iterator>
group_iterator<Iterator> operator+(group_iterator<Iterator> it, std::size_t size)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator+(std::size_t size, group_iterator<Iterator> it)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator-(group_iterator<Iterator> it, std::size_t size)
{
    return it -= size;
}

template<typename Iterator>
typename group_iterator<Iterator>::difference_type operator-(const group_iterator<Iterator>& lhs, const group_iterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base()) / lhs.size();
}

////////////////////////////////////////////////////////////
// Construction function

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(Iterator it, std::size_t size)
{
    return { it, size };
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(group_iterator<Iterator> it, std::size_t size)
{
    return { it.base(), size * it.size() };
}

////////////////////////////////////////////////////////////
// Merge-insertion sort

template<
    typename RandomAccessIterator,
    typename Compare
>
auto merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last,
                               Compare compare)
{
    // Cache all the differences between a Jacobsthal number and its
    // predecessor that fit in 64 bits, starting with the difference
    // between the Jacobsthal numbers 4 and 3 (the previous ones are
    // unneeded)
    static const uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    typename std::iterator_traits<RandomAccessIterator>::difference_type size = std::distance(first, last);
    if (size < 2) return;

    // Whether there is a stray element not in a pair
    // at the end of the chain
    bool has_stray = (size % 2 != 0);

    ////////////////////////////////////////////////////////////
    // Group elements by pairs

    auto end = has_stray ? std::prev(last) : last;
    for (auto it = first ; it != end ; it += 2)
    {
        if (compare(it[1], it[0]))
        {
            iter_swap(it, it + 1);
        }
    }

    ////////////////////////////////////////////////////////////
    // Recursively sort the pairs by max

    merge_insertion_sort(
        make_group_iterator(first, 2),
        make_group_iterator(end, 2),
        compare
    );

    ////////////////////////////////////////////////////////////
    // Separate main chain and pend elements

    // Small node struct for pend elements
    struct node
    {
        RandomAccessIterator it;
        typename std::list<RandomAccessIterator>::iterator next;
    };

    // The first pend element is always part of the main chain,
    // so we can safely initialize the list with the first two
    // elements of the sequence
    std::list<RandomAccessIterator> chain = { first, std::next(first) };
    std::list<node> pend;

    for (auto it = first + 2 ; it != end ; it += 2)
    {
        auto tmp = chain.insert(chain.end(), std::next(it));
        pend.push_back({it, tmp});
    }

    // Add the last element to pend if it exists, when it
    // exists, it always has to be inserted in the full chain,
    // so giving it chain.end() as end insertion point is ok
    if (has_stray)
    {
        pend.push_back({end, chain.end()});
    }

    ////////////////////////////////////////////////////////////
    // Binary insertion into the main chain

    for (int k = 0 ; ; ++k)
    {
        // Find next index
        auto dist = jacobsthal_diff[k];
        if (dist >= pend.size()) break;
        auto it = pend.begin();
        std::advance(it, dist);

        while (true)
        {
            auto insertion_point = std::upper_bound(
                chain.begin(), it->next, it->it,
                [=](auto lhs, auto rhs) {
                    return compare(*lhs, *rhs);
                }
            );
            chain.insert(insertion_point, it->it);

            it = pend.erase(it);
            if (it == pend.begin()) break;
            --it;
        }
         }

    // If there are elements left, insert them too
    while (not pend.empty())
    {
        auto it = std::prev(pend.end());
        auto insertion_point = std::upper_bound(
            chain.begin(), it->next, it->it,
            [=](auto lhs, auto rhs) {
                return compare(*lhs, *rhs);
            }
        );
        chain.insert(insertion_point, it->it);
        pend.pop_back();
    }

    ////////////////////////////////////////////////////////////
    // Move values in order to a cache then back to origin

    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

    for (auto&& it: chain)
    {
        auto begin = it.base();
        auto end = begin + it.size();
        std::move(begin, end, std::back_inserter(cache));
    }
    std::move(cache.begin(), cache.end(), first.base());
}
#endif
