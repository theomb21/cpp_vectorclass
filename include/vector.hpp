#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <assert.h>
#include "tuple.hpp"

/* Template class 'Vector' to simulate n-dimensional Vectors of Type 'VectorType'.
 * Private Members are: dimension n, Tuple of Type 'VectorType' called 'values' */
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


#endif
