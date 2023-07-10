#include "iter.hpp"

int main() {
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, printElement<int>);

    return 0;
}
