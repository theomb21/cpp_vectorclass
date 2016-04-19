#ifndef TUPLE_HPP_
#define TUPLE_HPP_

#include <stdio.h>
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;



/* Alias-Declaration of alias-template-type 'TupleType*' as 'Tuple' */
template <typename TupleType>
using Tuple = TupleType *;


/* Template function to create an instantiation of type 'Tuple'.
 * Requires Dimension n and template specialization of 'TupleType'
 * to allocate memory for n entries of type 'TupleType' (initialized 0)
 * and return Pointer to first element (i.e. 'Tuple' of dimension n) */
template <typename TupleType>
Tuple<TupleType> Tuple_Create(unsigned int n)       /* Level 1 function */
{
    Tuple<TupleType> t;

    assert(n >= 1);
    t = (Tuple<TupleType>) new TupleType [n];
    assert(t != nullptr);
    return t;
}


/* Template function to destroy an instantiation of type 'Tuple'.
 * Requires template specialization of 'TupleType' to deallocate
 * memory for all entries of type 'TupleType' given by 'Tuple' */
template <typename TupleType>
void Tuple_Destroy(Tuple<TupleType> v)    /* Level 1 function */
{

    assert(v != nullptr);
    delete(v); /* ?? is the memory completely deallocated for
    all n elements or just for the first one (the one pointed to) */
    v = nullptr;
}


#endif
