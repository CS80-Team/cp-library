#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<T, null_type, CUSTUM_COMPARE, rb_tree_tag, tree_order_statistics_node_update>;

void erase_set(ordered_set &os, int v) {
    // Number of elements less than v
    int rank = os.order_of_key(v);

    auto it = os.find_by_order(rank);
    os.erase(it);
}

// Returns iterator to 0-th
// largest element in the set
cout << *S.find_by_order(0) << " ";

// Returns iterator to 2-nd
// largest element in the set
cout << *S.find_by_order(2);
