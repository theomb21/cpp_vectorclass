// #include "12.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

/* Alias-Declaration of alias-template-type 'TupleType*' as 'Tuple' */
template <typename TupleType>
using Tuple = TupleType *;

/* Template function to create an instantiation of type 'Tuple'. Requires Dimension n and template specialization of 'TupleType' to allocate memory for n entries of type 'TupleType' (initialized 0) and return Pointer to first element (i.e. 'Tuple' of dimension n) */
template <typename TupleType>
Tuple<TupleType> Tuple_Create(unsigned int n)       /* Level 1 function */
{
    
    Tuple<TupleType> t;
    
    assert(n >= 1);
    t = (Tuple<TupleType>) new TupleType [n];
    assert(t != nullptr);
    return t;
}

/* Template function to destroy an instantiation of type 'Tuple'. Requires template specialization of 'TupleType' to deallocate memory for all entries of type 'TupleType' given by 'Tuple' */
template <typename TupleType>
void Tuple_Destroy(Tuple<TupleType> v)    /* Level 1 function */
{
    
    assert(v != nullptr);
    delete(v); /* ?? is the memory completely deallocated for all n elements or just for the first one (the one pointed to) */
    v = nullptr;
}

/* Template class 'Vector' to simulate n-dimensional Vectors of Type 'VectorType'. Private Members are: dimension n, Tuple of Type 'VectorType' called 'values' */
template <typename VectorType>
class Vector
{
    unsigned int n; // dimension of Vector (i.e. number of its elements)
    Tuple<VectorType> values;   // Tuple containing values of each element
public:
    Vector (unsigned int); // Constructor (probably better suggested as 'inline')
    ~Vector() {Tuple_Destroy<VectorType> (values);} //Destructor
    VectorType & operator () (const VectorType & i) {return values[i];};
    VectorType operator () (const VectorType & i) const {return values[i];};
    
};

/* Construction of N dimensional Vector of Type 'VectorType' */
template <typename VectorType>
Vector<VectorType>::Vector (unsigned int N)
: n(N), values( Tuple_Create<VectorType> (n) ) {}

int main()
{
    Vector<int> x (4);
    cout << x(3) << endl;
    x(3) = 3;
    cout << x(3) << endl;
    return 0;
}
