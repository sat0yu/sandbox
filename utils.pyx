#coding: utf-8;
import numpy as np
cimport numpy as np

DTYPE_int = np.int
DTYPE_float = np.float
ctypedef np.int_t DTYPE_int_t
ctypedef np.float_t DTYPE_float_t

# ex.) np.ndarray[DTYPE_int_t, ndim=2]

cpdef int factorial(int n):
    if n > 1:
        return n*factorial(n-1)
    elif n == 0 or n == 1:
        return 1
    else:
        raise ValueError("invalid value.")

cpdef np.ndarray[DTYPE_int_t, ndim=1] numToFactoradic(int n, int d=0):
    cdef int _d = 1
    while factorial(d+1) <= n:
        d += 1
    d = _d if d == 0 else d
    if _d > d:
        raise ValueError()
    # ex.) when given n is 8, d is 3 beacuse 3! < 8 < 4!

    cdef int f
    cdef np.ndarray[DTYPE_int_t, ndim=1] digit = np.zeros(d, dtype=np.int)
    while d > 0:
        f = factorial(d)
        digit[d-1] = n / f
        n = n % f
        d -= 1
    # ex.) when given n is 8, digit is [1,1,0]
    #      -> 8 = 1*3! + 1*2! + 0*1!

    # N-digits could represent (N+1)!-pattern
    return digit

cpdef int factoradicToNum(np.ndarray[DTYPE_int_t, ndim=1] digit):
    cdef int i, n = 0
    for i in range(len(digit)):
        n += digit[i] * factorial(i+1)
    return n

cpdef object factoradicToPermitation(object A, np.ndarray[DTYPE_int_t, ndim=1] digit):
    cdef object P = []
    cdef int l = len(digit)
    while l > 0:
        P.append( A[ digit[l-1] ] )
        del A[ digit[l-1] ]
        l -= 1
    P.append( A[0] )
    return P
