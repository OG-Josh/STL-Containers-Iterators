// hw15.cpp
// to illustrate stl containers & iterators

/*************************************************************************
 * AUTHOR     : First Last
 * HW15       : stl containers & iterators
 * CLASS      : CS 1C
 * SECTION    : Date & Time
 *************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

// function & class definitions go into hw15.cpp:

// hw15.cpp

namespace hw15
{

//
// list conainter, iterator example code adapted from Chapter 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

template<typename Elem>
struct Link
{
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem val;     // the value
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) :
            val
            { v }, prev
            { p }, succ
            { s }
    {
    }
};

//--Q#3-------------------------------------------------------------------------

template<typename Elem>
class list
{
    // representation and implementation details
public:
    class iterator;         // forward declaration of member type: class iterator
    class const_iterator;  // forward declaration of member type: class const_iterator

    list() :
            first(new Link<Elem>()), last
            { first }
    {
    }
    ~list()
    {
        while (first != last)
        {
            Link<Elem> *next = first->succ;
            delete first;
            first = next;
        }
        delete last;
    }

    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element

    // add missing const iterators begin, end here

    const_iterator cbegin() const;  // constant iterator to first element
    const_iterator cend() const;  // constant iterator to one beyond last element

    iterator insert(iterator p, const Elem& v);  // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list

    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v);  // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();      // the first element
    Elem& back();       // the last element

    Link<Elem>* first;
    Link<Elem>* last;   // one-beyond-the-last link
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::iterator  // definition for class iterator
{
    Link<Elem>* curr;   // current node
public:
    iterator(Link<Elem>* p) :
            curr
            { p }
    {
    }
    iterator& operator++()  // forward
    {
        // ...
        // temp, replace when defining function
        // return nullptr; // included so that incomplete lab code will compile
        curr = curr->succ;
        return *this;
    }
    iterator& operator--()  // backwards
    {
        // ...
        // temp, replace when defining function
        //return nullptr; // included so that incomplete lab code will compile
        curr = curr->prev;
        return *this;
    }
    Elem& operator*()  // get value (dereference)
    {
        // ...
        // temp, replace when defining function
        //return nullptr; // included so that incomplete lab code will compile
        return curr->val;
    }

    bool operator==(const iterator& rhs) const  // lhs, rhs iterators point to the same node (equal)
    {
        // ...
        // temp, replace when defining function
        //return false; // included so that incomplete lab code will compile
        return curr == rhs.curr;
    }
    bool operator!=(const iterator& rhs) const  // lhs, rhs iterators do not point to the same node (not equal)
    {
        // ...
        // temp, replace when defining function
        //return false; // included so that incomplete lab code will compile
        return curr != rhs.curr;
    }
};

//--Q#4-------------------------------------------------------------------------

template<typename Elem>
class list<Elem>::const_iterator  // definition for class const_iterator
{
    const Link<Elem>* curr;   // current node
                              // node pointed to by curr is immutable (i.e. can't be changed)
                              // fine to modify curr pointer itself (i.e. pointer value stored in curr)
                              // refer to const correctness reading
public:

    // add missing constructor, overloaded ++, --, *, ==, != operators here

    const_iterator(Link<Elem>* p) :
            curr
            { p }
    {
    }
    const_iterator& operator++()  // forward
    {
        curr = curr->succ;
        return *this;
    }
    const_iterator& operator--()  // backwards
    {
        curr = curr->prev;
        return *this;
    }
    const Elem& operator*() const  // get value (dereference)
    {
        return curr->val;
    }

    bool operator==(const iterator& rhs) const  // lhs, rhs iterators point to the same node (equal)
    {
        return curr == rhs.curr;
    }
    bool operator!=(const iterator& rhs) const  // lhs, rhs iterators do not point to the same node (not equal)
    {
        return curr != rhs.curr;
    }
};

//------------------------------------------------------------------------------

template<typename Elem>
typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
{
    return iterator(first);
}

//--Q#3-------------------------------------------------------------------------

// constant iterator to first element

// ... add missing constant iterator begin here
template<typename Elem>
typename list<Elem>::const_iterator list<Elem>::cbegin() const
{
    return iterator(first);
}

//------------------------------------------------------------------------------

template<typename Elem>
typename list<Elem>::iterator list<Elem>::end()  // iterator to one beyond last element
{
    return iterator(last);
}

//--Q#3-------------------------------------------------------------------------

// constant iterator to last element

// ... add missing constant iterator end here
template<typename Elem>
typename list<Elem>::const_iterator list<Elem>::cend() const
{
    return iterator(this->last);
}
//------------------------------------------------------------------------------

template<typename Elem>
void list<Elem>::push_front(const Elem& v)  // insert v at front
{
    first = new Link<Elem>(v, 0, first);
}

//
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--Q#5-------------------------------------------------------------------------

double* low_doubles(double* first, double* last)
// return a pointer to the element in [first,last) that has the lowest value
{
    double l = -1;
    double* low;
    for (double* p = first; p != last; ++p)
        if (*p < l)
        {
            low = p;
            l = *p;
        }
    return low;
}

//--Q#5-------------------------------------------------------------------------

// implement templated low algorithm here

/**
 * low takes iterator arguments
 which point to the beginning, iterator first, and one past the
 end, iterator last, of a sequence of container elements. Take
 advantage of the type parameter iterator to eliminate local
 variables l and low in writing the low algorithm
 */
template<typename T>
T low(T first, T last)
// return a pointer to the element in [first,last) that has the lowest value
{
    T low = first;
    auto l = *first;
    for (T p = first; p != last; ++p)
    {
        if (*p < l)
        {
            low = p;
            l = *p;
        }
    }
    return low;
}

//------------------------------------------------------------------------------

}// hw15

//------------------------------------------------------------------------------

using namespace hw15;

//
// list conainter, iterator example code adapted from Chapter 20.4
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int main()
{
    // console header
    cout << endl;
    cout << "************************************** " << endl;
    cout << "*           Running HW15             * " << endl;
    cout << "*      Programmed by First Last      * " << endl;
    cout << "*         CS1C Date & Time           * " << endl;
    cout << "************************************** " << endl;
    cout << endl;

    // Q#3,4 - containters & iterators

    list<int> myList;
    int x;
    while (cin >> x)
        myList.push_front(x);
    cout << "List: [ ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "]" << endl;
    // Q#5 - low_doubles algorithm

    double d[] =
    { 1, 2, 3, 4, 5, -99.25, 100, 10, 500.123, 5 };  // init array of doubles
    vector<double> v =
    { 1, 2, 3, 4, 5, -99.25, 100, 10, 500.123, 5 };  // init identical vector of doubles

    double* lowa = low_doubles(&d[0], &d[9]);  // min of array
    cout << endl << "low_doubles alg: double array min value is " << *lowa << endl << endl;

    double* middle = &v[0] + v.size() / 2;
    double* lowv1 = low_doubles(&v[0], middle);        // min of vector first half
    double* lowv2 = low_doubles(middle, &v[0] + v.size());  // min of vector second half
//    cout << "low_doubles alg: double vector min value first half is " << *lowv1 << endl;
//    cout << "low_doubles alg: double vector min value second half is " << *lowv2 << endl << endl;

            // Q#5 - low algorithm

    // NOTE: uncomment code below once low algorithm definition is complete

    lowa = low(&d[0], &d[9]);  // min of array
    cout << "low alg: double array min value is " << *lowa << endl << endl;

    lowv1 = low(&v[0], middle);          // min of vector first half
    lowv2 = low(middle, &v[0] + v.size());  // min of vector second half
    cout << "low alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low alg: double vector min value second half is " << *lowv2 << endl << endl;

    list<int>::iterator p = low(myList.begin(), myList.end());  // min of list
    if (p == myList.end())    // did we reach the end?
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << endl;

    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#1

// STL container is containers or container classes store objects and data.
// There are in total seven standard "first-class" container classes and three container adaptor classes and only seven header files that provide access to these containers or container adaptors.
// Two basic types of containers:
// - Sequences: vector, list, queue
// - Associative containers: set, multiset, map, multimap

// STL iterator are used to point at the memory addresses of STL containers.
// They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.
// Example:
// - begin() :- This function is used to return the beginning position of the container.
// - end() :- This function is used to return the after end position of the container.

// STL algorithm is defines a collection of functions especially designed to be used on ranges of elements.
// They act on containers and provide means for various operations for the contents of the containers
// Example:
// - Sorting:
// - Searching:

// Q#2
// Iterators are the mechanism that makes it possible to decouple algorithms from
// containers: algorithms are templates, and are parameterized by the type of iterator,
// so they are not restricted to a single type of container.  Consider, for example, how
// to write an algorithm that performs linear search through a range. This is the STL's
// find algorithm:
//template <class InputIterator, class T>
//InputIterator find(InputIterator first, InputIterator last, const T& value)
//{
//    while (first != last && *first != value)
//        ++first;
//    return first;
//}
//Find takes three arguments: two iterators that define a range, and a value to search
//for in that range. It examines each iterator in the range [first, last), proceeding
//from the beginning to the end, and stops either when it finds an iterator that points
//to value or when it reaches the end of the range

// Q#5
// What kinds of issues might arise?
// If this is list without allocated memory continues. So the ++p will can not reach the end.
// The algorithms can not work.

// In what ways are the algorithms low_doubles and low similar? different?
// The purpose of low_doubles and low similar was the same but apply the algorithms for another type of struct.
// low_doubles just can apply for array with all memory allocated continuous can not apply to all structure type.
// low algorithm can apply to all structure. Because this using iterator to traverse all element.
