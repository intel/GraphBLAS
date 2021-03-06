//------------------------------------------------------------------------------
// GB_Pending_realloc: reallocate a list of pending tuples
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// Reallocate a list of pending tuples.  If it fails, the list is freed.

#include "GB_Pending.h"

bool GB_Pending_realloc         // reallocate a list of pending tuples
(
    GB_Pending *PHandle,        // Pending tuple list to reallocate
    int64_t nnew                // # of new tuples to accomodate
)
{

    //--------------------------------------------------------------------------
    // check inputs
    //--------------------------------------------------------------------------

    ASSERT (PHandle != NULL) ;
    GB_Pending Pending = (*PHandle) ;

    //--------------------------------------------------------------------------
    // ensure the list can hold at least nnew more tuples
    //--------------------------------------------------------------------------

    int64_t newsize = nnew + Pending->n ;

    if (newsize > Pending->nmax)
    {

        //----------------------------------------------------------------------
        // double the size if the list is not large enough
        //----------------------------------------------------------------------

        newsize = GB_IMAX (newsize, 2 * Pending->nmax) ;

        //----------------------------------------------------------------------
        // reallocate the i,j,x arrays
        //----------------------------------------------------------------------

        bool ok1 = true ;
        bool ok2 = true ;
        bool ok3 = true ;

        Pending->i = GB_REALLOC (Pending->i, newsize, Pending->nmax, int64_t, &ok1) ;
        if (Pending->j != NULL)
        { 
            Pending->j = GB_REALLOC (Pending->j, newsize, Pending->nmax, int64_t, &ok2) ;
        }
        size_t s = Pending->size ;
        Pending->x = GB_REALLOC (Pending->x, newsize*s, (Pending->nmax)*s, GB_void, &ok3) ;

        if (!ok1 || !ok2 || !ok3)
        { 
            // out of memory
            GB_Pending_free (PHandle) ;
            return (false) ;
        }

        //----------------------------------------------------------------------
        // record the new size of the Pending tuple list
        //----------------------------------------------------------------------

        Pending->nmax = newsize ;
    }

    //--------------------------------------------------------------------------
    // return result
    //--------------------------------------------------------------------------

    return (true) ;
}

