#include <iostream>
#include <set>
using namespace std;


ostream& operator<<(ostream& os, const multiset<int>& st){
    for (auto val : st)
      os << val << ", ";
    return os;
}

int main(){
    multiset<int> st;
    
    /* 
    st.insert(value): 
    Insert the value. st is sorted in ascending order. O(log N)
    */
    cout << "insert(value)" << endl;
    st.insert(2);
    st.insert(20);
    st.insert(4);
    st.insert(6);
    st.insert(2);
    st.insert(9);
    st.insert(4);
    cout << st << endl; // 2, 2, 4, 4, 6, 9, 20, 

    /* 
    st.erase(value): 
    Erase ALL value in st. O(log N)
    */
    cout << "erase(value)" << endl;
    int c = st.erase(2); 
    cout << c << endl; // 2
    c = st.erase(2);      
    cout << c << endl; // 0
    
    /* 
    st.erase(itr);
    itr: iterator 
    Erase position of itr in st. 
    Returns an iterator pointing to the next of the deleted element. O(1)
    */
    cout << "erase(itr)" << endl;
    multiset<int> st2{1, 2, 3, 4, 5, 6};
    for(auto itr = st2.begin(); itr != st2.end();) {
        if( *itr % 2 == 0 )      // if even
            itr = st2.erase(itr);       //  delete O(1)
        else
            ++itr;
    }
    cout << st2 << endl; // 1, 3, 5, 

    /* 
    st.erase(first, last);
    first, last: iterator 
    Erase value at position between first and last in st. 
    Returns an iterator pointing to the next of the deleted element. O((last - first) + log N)
    */
    cout << "erase(first, last)" << endl;
    multiset<int> st3{1, 2, 3, 4, 5, 6};
    st3.erase(++st3.begin(), --st3.end());
    cout << st3 << endl; // 1, 6, 

    /* 
    st.find(value): 
    Find the value in st.
    Return iterator of the position of the value. 
    O(log N)
    */
    cout << "find" << endl;
    multiset<int> st4{4, 5, 1, 2, 5, 5, 6, 77};
    auto itr = st4.find(5); 
    cout << *itr << endl; // 5
    itr--;
    cout << *itr << endl; // 4
    auto itr2 = st4.find(10); // return end() 
    cout << *itr2 << endl; // 8

    /* 
    st.lower_bound(value): 
    Search the value in st.
    And return an iterator to the first element greater than or equal to the value.
    O(log N)
    */
    cout << "lower_bound" << endl;
    multiset<int> st5{4, 5, 1, 2, 5, 5, 6, 77};
    itr = st5.lower_bound(5); 
    cout << *itr << endl; // 5
    itr--;
    cout << *itr << endl; // 4
    itr2 = st5.lower_bound(3);
    cout << *itr2 << endl; // 4
    itr2 = st5.lower_bound(78); // return end()
    cout << *itr2 << endl; // 8
    
    /* 
    st.upper_bound(value): 
    Search the value in st.
    And return an iterator to the first element greater than the value.
    O(log N)
    */
    cout << "upper_bound" << endl;
    multiset<int> st6{4, 5, 1, 2, 5, 5, 6, 77};
    itr = st5.upper_bound(5); 
    cout << *itr << endl; // 6
    itr--;
    cout << *itr << endl; // 5
    itr2 = st5.upper_bound(11); 
    cout << *itr2 << endl; // 77
    itr2 = st5.upper_bound(78); // return end()
    cout << *itr2 << endl; // 8

    /* 
    st.count(value): 
    Return the number of the value.
    O(log N)
    */
    cout << "count" << endl;
    multiset<int> st7{4, 5, 1, 2, 5, 5, 6, 77};
    cout << st5.count(5) << endl; // 3
    cout << st5.count(3) << endl; // 0

    /* 
    st.empty(): 
    Return whether the st is empty.
    O(1)
    */
    cout << "empty" << endl;
    st = {};
    cout << st.empty() << endl; // 1
    st = {45};
    cout << st.empty() << endl; // 0

    /* 
    st.size(): 
    Return size of st
    O(1)
    */
    cout << "size" << endl;
    st = {};
    cout << st.size() << endl; // 0
    st = {45, 44, 1};
    cout << st.size() << endl; // 3

    /* 
    st.clear(): 
    Delete all element of st
    O(N)
    */
    cout << "clear" << endl;
    st = {1, 3, 4, 5, 1, 1};
    cout << st.size() << endl; // 6
    st.clear();
    cout << st.size() << endl; // 0

    /* 
    st.swap(multiset&): 
    x.swap(y) swaps the contents of the multiset x and y
    O(1)
    */
    cout << "swap" << endl;
    multiset<int> x{1, 3, 4, 5, 1, 1};
    multiset<int> y{100, 21};
    x.swap(y);
    cout << x << endl; // 21, 100, 
    cout << y << endl; // 1, 1, 1, 3, 4, 5,

    /* 
    st.begin(), st.end():
    st.begin() returns the iterator the first element of st.
    st.end() returns the iterator the last element of st.
    */
    cout << "begin, end" << endl;
    st = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    for (auto itr = st.begin(); itr != st.end(); ++itr)
        cout << *itr << ", ";

    return 0;
}




