function [complex_binaryops complex_unaryops ] = gbtest_complex
%GBTEST_COMPLEX return list of complex operators

% SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights
% Reserved. http://suitesparse.com.  See GraphBLAS/Doc/License.txt.

complex_binaryops = {
    % x,y,z all the same type:
    '1st'
    '2nd'
    'pair'
    'any'
    '+'
    '-'
    'rminus'
    '*'
    '/'
    '\'
    'iseq'
    'isne'
    '=='
    '~='
    'pow'
    % x and y are real, z is complex:
    'cmplx'
    } ;

complex_unaryops = {
    % z and x are complex:
    'identity'     % z = x
    'ainv'         % z = -x
    'minv'         % z = 1/x
    'one'          % z = 1
    'sqrt'
    'log'
    'exp'
    'sin'
    'cos'
    'tan'
    'asin'
    'acos'
    'atan'
    'sinh'
    'cosh'
    'tanh'
    'asinh'
    'acosh'
    'atanh'
    'ceil'
    'floor'
    'round'
    'trunc'
    'exp2'
    'expm1'
    'log10'
    'log1p'
    'log2'
    'conj'
    % z is bool, x is complex
    'isinf'
    'isnan'
    'isfinite'
    % z is real, x is complex
    'abs'
    'real'
    'imag' 
    'angle' } ;
