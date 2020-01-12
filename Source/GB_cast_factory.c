//------------------------------------------------------------------------------
// GB_cast_factory: return a pointer to a typecasting function
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2019, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// Returns a pointer to a function f(z,x,s) that copies its input x into its
// output z, casting as needed.  That is, it computes z = (type of z) x.
// s is the size for user-defined types, which can only be copied.

// If the operator is FIRST, SECOND, or PAIR, this function is called for the
// cast function on the unused argument, but the result is then unused. 

#include "GB.h"

GB_cast_function GB_cast_factory   // returns pointer to function to cast x to z
(
    const GB_Type_code code1,      // the type of z, the output value
    const GB_Type_code code2       // the type of x, the input value
)
{ 

    //--------------------------------------------------------------------------
    // define the worker for the switch factory
    //--------------------------------------------------------------------------

    // the worker selects a typecast function and returns it to the caller
    #define GB_WORKER(ignore1,ignore2,ztype,ignore3,xtype) \
        return (&GB_cast_ ## ztype ## _ ## xtype) ;

    //--------------------------------------------------------------------------
    // launch the switch factory
    //--------------------------------------------------------------------------

    // switch factory for two built-in types; user types are skipped.
    // no generic worker so the switch factory cannot be disabled.
    #include "GB_2type_factory.c"

    //--------------------------------------------------------------------------
    // user-defined types fall through the switch factory to here
    //--------------------------------------------------------------------------

    // if code1 or code2 are GB_UDT_code or GB_UCT_code
    return (&GB_copy_user_user) ;
}

