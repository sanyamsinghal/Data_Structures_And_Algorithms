/*
    Policy based Data Structure is just like a advancement of set present in C++ STL
    But with 2 added functionalities which makes it super efficient and useful.

    (i) find_by_order(k) :- Passing a value k it return the iterator to value of kth largest element supposing if the numbers will be 
                            arranged in sorted order.
        -> It is 0-based index. So find_by_order(0) is the largest element among them                       
        -> Time complexity :- O(logN)

    (ii) order_by_key(num) :- Passing a number num, it will tell us the number of elements that are less than that present
                              out set.
        ->Time Complexity:- O(logN)
        ->If the number is not present it will tell the index at which it will be present if it was there in the input.

        for eg:- 1, 3, 4, 10, 15            (the numbers will be stored in some order like this)
        i)so order_by_key(10) will return 3 i.e. the index of 10 and the number less than this
        ii) but if order_by_key(11) is called then, it will return 4 because if it was present then it will be at that
            index only. It will be like 1, 3, 4, 10, (11)* , 15


*/

/*
    Header Files are:-
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;

    typedef tree<int, null_type, less<int>, rb_tree_tag,    
                tree_order_statistics_node_update>
                PBDS;


*/