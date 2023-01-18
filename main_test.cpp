#include "vector.hpp"
#include "rbt.hpp"
#include "vectorIterator.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "is_integral.hpp"
#include "styling.h"
#include <map>
#include <string>
#include <string_view>

#if defined(STD) 
#include <vector>
#define namespace std
#else
#include "vector.hpp"
#include "vectorIterator.hpp"
#define namespace ft
#endif

void leak_test(int flag)
{
    if (flag != 1)
        return ;
    std::vector<int> myvector;
    std::vector<int> copyvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    copyvector = myvector;

    std::cout << "myvector contains:";
    std::cout << "size: " << (int) myvector.size() << '\n';
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.clear();
    myvector.push_back (10);
    myvector.push_back (20);

    std::cout << "myvector contains:";
    std::cout << "size: " << (int) myvector.size() << '\n';
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
    std::cout << '\n';

    std::cout << "copyvector contains:";
    std::cout << "size: " << (int) copyvector.size() << '\n';
    std::cout << "capacity: " << (int) copyvector.capacity() << '\n';
    for (unsigned i=0; i<copyvector.size(); i++)
    std::cout << ' ' << copyvector[i];
    std::cout << '\n';


    // int arr[] = {1, 2, 3, 4, 5};

    std::vector<int> v1(5);
    std::vector<int> vtest(5);


    /* assigned value to vector v1 */
    for (size_t i = 0; i < v1.size(); ++i)
        v1[i] = i + 1;
    for (size_t i = 0; i < v1.size(); ++i)
        vtest[i] = i + 5.5;
    v1.reserve(6);
    v1.reserve(1);
    cout << "Capicity " << v1.capacity() << endl;
    cout << "Size " << v1.size() << endl;

    // int arr2[] = {1, 2, 3, 4, 5};

    // std::vector<int> v2(v1.begin(), vtest.end());

    for (size_t i = 0; i < v1.size(); ++i)
        cout << v1[i] << endl;
    copyvector.clear();
    copyvector.push_back (10);
    copyvector.push_back (20);

    std::cout << "copyvector contains:";
    std::cout << "size: " << (int) copyvector.size() << '\n';
    std::cout << "capacity: " << (int) copyvector.capacity() << '\n';
    for (unsigned i=0; i<copyvector.size(); i++)
    std::cout << ' ' << copyvector[i];
    std::cout << '\n';
    // system("leaks Vector");
}

void resize_test(int flag)
{
    if (flag != 1)
        return ;

    std::vector<int> myvector;
    cout << myvector[0] << endl; // SEGFAULT
    // set some initial content:
    for (int i=1;i<10;i++) 
        myvector.push_back(i);
    cout << "Size of real vector: " << myvector.size() << endl;
    cout << "Capacity of my vector: " << myvector.capacity() << endl;

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    cout << "Size of real vector: " << myvector.size() << endl;
    cout << "Capacity of my vector: " << myvector.capacity() << endl;

    std::cout << "myvector contains:";
    for (int i=0;i<12;i++)
        std::cout << ' ' << myvector[i];
    // cout << myvector[15] << endl; // CONTAINER OVERFLOW fk
    // cout << myvector[20] << endl; // HEAP BUFFER OVERFLOW fk
    std::cout << '\n';
}

/* 1. Assign member function */
void    assign_test(int flag)
{
    if (flag != 1)
        return ;

    /* Change test number for different test*/
    int test_num = 2;

    std::vector<int> vector(2,100);
    std::vector<int> vector2(5,200);
    std::vector<int> vector3(4,300);
    // ft::vector<int> vector4(6,300);

    /* (1) - Range assign */
    if (test_num == 1 || test_num == 3)
    {
        cout << TEL << "---- RANGE assign test -----" << endl;
        cout << ORG << "---Printing before assigning vector2---" <<  RESET << endl;
        for (std::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
        cout << "Before Size of vector2: " << vector2.size() << endl;
        cout << "Before Capacity of vector2: " << vector2.capacity() << endl;

        std::vector<int>::iterator it = vector3.begin();
        vector2.assign(it, vector3.end());


        cout << ORG << "---Printing after assigning vector2---" <<  RESET << endl;
        for (std::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
        cout << "After Size of vector2: " << vector2.size() << endl;
        cout << "After Capacity of vector2: " << vector2.capacity() << endl;

    }
    /* (2) - Fill assign */
    if (test_num == 2 || test_num == 3)
    {
        cout << TEL << "---- FILL assign test -----" << endl;
        cout << ORG << "---Printing before assigning vector2---" <<  RESET << endl;
        for (std::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
        cout << "Before Size of vector2: " << vector2.size() << endl;
        cout << "Before Capacity of vector2: " << vector2.capacity() << endl;

        vector2.assign(6, 420);

        cout << ORG << "---Printing after assigning vector2---" <<  RESET << endl;
        for (std::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
            cout << ' ' << *it;
        cout << '\n';
        cout << "After Size of vector2: " << vector2.size() << endl;
        cout << "After Capacity of vector2: " << vector2.capacity() << endl;

    }

}

void    swap_test(int flag)
{
    if (flag != 1)
        return ;
    cout << TEL << "----- swap test ----" << RESET << endl;
    ft::vector<int> vector(2,100);
    ft::vector<int> vector2(5,200);

    cout << ORG << "---Printing vector 1---" <<  RESET << endl;
    for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    cout << "Before Size of vector: " << vector.size() << endl;
    cout << "Before Capacity of vector: " << vector.capacity() << endl;
    cout << "Before Address of vector: " << &vector << endl;
    cout << ORG << "---Printing vector 2---" <<  RESET << endl;
    for (ft::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    cout << "Before Size of vector2: " << vector2.size() << endl;
    cout << "Before Capacity of vector2: " << vector2.capacity() << endl;
    cout << "Before Address of vector: " << &vector2 << endl;

    cout << BLU << "-------Swapping vector1 and vector2------" <<   RESET << endl;
    vector.swap(vector2);
    cout << ORG << "---Printing vector 1---" <<  RESET << endl;
    for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    cout << "After Size of vector: " << vector.size() << endl;
    cout << "After Capacity of vector: " << vector.capacity() << endl;
    cout << "After Address of vector: " << &vector << endl;

        cout << ORG << "---Printing vector 2---" <<  RESET << endl;
    for (ft::vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    cout << "After Size of vector2: " << vector2.size() << endl;
    cout << "After Capacity of vector2: " << vector2.capacity() << endl;
    cout << "After Address of vector2: " << &vector2 << endl;
}
void    is_integral_test(int flag)
{
    if (flag != 1)
        return ;
    cout << std::boolalpha;
    cout << "is_integral:" << endl;
    cout << "char: " << std::is_integral<char>::value << endl;
    cout << "int: " << ft::is_integral<int>::value << endl;
    cout << "float: " << ft::is_integral<float>::value << endl;
}

void    legit_vector_test(int flag)
{
    if (flag != 1)
        return ;
    
    ft::vector<int> realvector(1,100);
    std::vector<int> anothervector(3,20);
    std::vector<int> anothervector2(3,10);
    ft::vector<int> rangevector(anothervector2.begin(),anothervector.end());
    // std::vector<int> susvector(5, 69); // shoving 5 number 100s inside the vector;

    cout << "----------------Printing what the shit vector does----------" << endl;
    
    // realvector.pop_back(); // this cause the vector to overflow
    realvector.push_back(1); // push back causing leaks?
    // realvector.reserve(20);
    
    cout << "Start Size of real vector: " << realvector.size() << endl;
    cout << "Start Capacity of real vector: " << realvector.capacity() << endl;
    // realvetor.erase(realvector.begin() + 1);
    // realvector.erase(realvector.begin(), realvector.end() - 3);
    // realvector.insert(realvector.begin(), 100); // DONE 1st
    ft::vector<int>::iterator it = realvector.begin();
    cout<< "Before: " << *it << endl;
    realvector.insert(realvector.begin(), 3, 200); // Done 2nd
    // realvector.insert(realvector.begin() + 2, 4, 300); // Done 2nd
    // realvector.insert(realvector.begin(), anothervector.begin(), anothervector.end() - 1);
    // cout <<"AFTER: " << *it << endl;


    cout << "After Size of real vector: " << realvector.size() << endl;
    cout << "After Capacity of real vector: " << realvector.capacity() << endl;


    cout << "---Printing vector---" << endl;
    for (ft::vector<int>::iterator it = realvector.begin(); it != realvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    cout << "---Printing range vector---" << endl;
    for (ft::vector<int>::iterator it = rangevector.begin(); it != rangevector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    cout << "-----------------------------------------------------------" << endl;
    cout << "CHECK DESTRUCTOR" << endl;
    // system("leaks vector");
}

void    reverse_iterator_test(int flag) // DEAD
{
    if (flag != 1)
        return ;
    // ft::vector<int> myvector (5);  // 5 default-constructed ints
    // ft::vector<int>::reverse_iterator rit = myvector.rbegin();

    // int i=0;
    // for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
    // {
    //     *rit = ++i; // assigning
    //     cout << *rit << endl;
    // }

    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector.begin(); it < myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // // cout << "---Printing vector---" << endl;
    // // for (ft::vector<int>::iterator it = realvector.begin(); it != realvector.end(); ++it)
    // //     std::cout << ' ' << *it;
    // // for (ft::vector<int>::iterator it = realvector.begin(); it != realvector.end(); ++it)
    // //     std::cout << ' ' << *it;
    // std::cout << '\n';

    // cout << "-----------------------------------------------------------" << endl;

    // int num1 = 2;

    // ft::vector<int>::iterator it(&num1);
    // ft::vector<int>::iterator it2(&num1);

    // cout << *it << endl;
    // cout << *it2 << endl;

    // cout << std::boolalpha << endl;
    // cout << (it != it2) << endl;

    ft::vector<int>     vec(5,2);


    if (vec.rbegin() != vec.rbegin())
        cout << "not equal" << endl;
    else
        cout << " equal" << endl;

    // for (ft::vector<int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); i++)
    // {
    //     cout << *i << endl;
    // }
}

void    vector_operator_overload_test(int flag)
{
    if (flag != 1)
        return ;

    // std::Vector<int> derp; // DOESNT WORK BECAUSE OF THE CONST
    ft::vector<int> derp(5,100);
    int ptr[5] = {1,2,3,4,5};
    ft::vectorIterator<int> ptr2(ptr);
    ft::vectorIterator<int> ptr3(ptr);

    // derp._vector[0] = 1;
    derp.pop_back();
    // cout << derp._vector[6] << endl;

    cout << *ptr2 << endl;
    ptr2 += 2;
    cout << *ptr2 << endl;
    ptr2 -= 2;
    cout << *ptr2 << endl;
    ptr2 =  1 + ptr2;
    // ptr2 =  ptr2 - 1;

    // ptr2 = ptr2 - ptr2;
    cout << *ptr2 << endl;
    ptr2--;
    cout << *ptr2++ << endl;
    cout << *ptr2 << endl;
    cout << *ptr2 + *ptr3 << endl;
    ptr2 = ptr2 - 1;
    // if (ptr2 != ptr3)
    //     cout << "hi\n";
    // else
    //     cout << "bye\n";
}

void    member_functions_test(int flag)
{
    // consist of at and back
    if (flag != 1)
        return ;
    {
        cout << "Testing member function vect::at/back" << endl;
        std::vector<int> derp(1,100);
        cout << derp.at(2) << endl;
        cout << derp.back() << endl;

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = derp.begin() ; it != derp.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    // {
    //     ft::vector<int> myvector;

    //     // set some content in the vector:
    //     for (int i=0; i<100; i++) myvector.push_back(i);

    //     std::cout << "size: " << (int) myvector.size() << '\n';
    //     std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    //     std::cout << "max_size: " << (int) myvector.max_size() << '\n';
    // }


}

void    lexo_test(int flag)
{
    if (flag != 1)
        return ;
    int size = 5;
    int size2 = 4;
    int fill = 100;
    int fill2 = 200;

        // NOT DONE pls check thanks
    {
        cout << TEL << "––----- Lexographical operator test: std --------" << RESET << endl;

        std::vector<int> vector(size, fill);
        std::vector<int> vector2(size2,fill2);

        cout << ORG << "==" << RESET << endl;
        if (vector == vector2)
            cout << "Yes" << endl;
        else
            cout << "No " << endl;
        cout << ORG << "!=" << RESET << endl;
        if (vector != vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << "<" << RESET << endl;
        if (vector < vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
        cout << ORG << "<=" << RESET << endl;
        if (vector <= vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << ">" << RESET << endl;
        if (vector > vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << ">=" << RESET << endl;
        if (vector >= vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
     {
        cout << TEL << "––----- Lexographical operator test: ft --------" << RESET << endl;

        ft::vector<int> vector(size, fill);
        ft::vector<int> vector2(size2, fill2);

        cout << ORG << "==" << RESET << endl;
        if (vector == vector2)
            cout << "Yes" << endl;
        else
            cout << "No " << endl;
        cout << ORG << "!=" << RESET << endl;
        if (vector != vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << "<" << RESET << endl;
        if (vector < vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
        cout << ORG << "<=" << RESET << endl;
        if (vector <= vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << ">" << RESET << endl;
        if (vector > vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << ORG << ">=" << RESET << endl;
        if (vector >= vector2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

void    redblacktree(int flag)
{
    if (flag != 1)
        return ;
    
    ft::RBT<int> hi;
    // ft::Node<int> node(int, 'r', NULL, NULL, NULL);
    // ft::RBT<int>::Node hia;
    // RBT();
    hi.insert(5);
}

int main()
{
     /* Select 0 or 1 to enable the code above*/
    assign_test(0); // donezo
    swap_test(0);
    resize_test(0);
    legit_vector_test(0);
    is_integral_test(0);
    reverse_iterator_test(0);
    leak_test(0);
    vector_operator_overload_test(0);
    lexo_test(0);
    member_functions_test(0);
    redblacktree(1);

    // system("leaks vector");
}