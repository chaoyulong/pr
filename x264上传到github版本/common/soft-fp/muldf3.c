#include "soft-fp.h"
#include "double.h"

DFtype
__muldf3 (DFtype a, DFtype b)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_D (B);
  FP_DECL_D (R);
  DFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_D (A, a);
  FP_UNPACK_D (B, b);
  FP_MUL_D (R, A, B);
  FP_PACK_D (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
