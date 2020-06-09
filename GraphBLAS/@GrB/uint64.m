function C = uint64 (G)
%UINT64 cast a GraphBLAS matrix to MATLAB full uint64 matrix.
% C = uint64 (G) typecasts the GrB matrix G to a MATLAB full uint64
% matrix.  The result C is full since MATLAB does not support sparse
% uint64 matrices.
%
% To typecast the matrix G to a GraphBLAS sparse uint64 matrix instead,
% use C = GrB (G, 'uint64').
%
% See also GrB, GrB/double, GrB/complex, GrB/single, GrB/logical, GrB/int8,
% GrB/int16, GrB/int32, GrB/int64, GrB/uint8, GrB/uint16, GrB/uint32.

% SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights
% Reserved. http://suitesparse.com.  See GraphBLAS/Doc/License.txt.

G = G.opaque ;
C = gbfull (G, 'uint64') ;

