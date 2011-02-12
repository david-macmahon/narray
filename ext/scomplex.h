#ifndef M_PI_2
#define M_PI_2         1.57079632679489661923  /* pi/2 */
#endif
#ifndef M_LOG2E
#define M_LOG2E        1.4426950408889634074   /* log_2 e */
#endif
#ifndef M_LOG10E
#define M_LOG10E       0.43429448190325182765  /* log_10 e */
#endif
#ifndef M_LN2
#define M_LN2          0.69314718055994530942  /* log_e 2 */
#endif
#ifndef M_LN10
#define M_LN10         2.30258509299404568402  /* log_e 10 */
#endif

#ifndef DBL_EPSILON
#define DBL_EPSILON 2.2204460492503131e-16
#endif

EXTERN double round(double);
EXTERN double log2(double);
EXTERN double exp2(double);
EXTERN double exp10(double);

#define r_abs(x)   abs(x)
#define r_sqrt(x)  sqrt(x)
#define r_exp(x)   exp(x)
#define r_log(x)   log(x)
#define r_sin(x)   sin(x)
#define r_cos(x)   cos(x)
#define r_sinh(x)  sinh(x)
#define r_cosh(x)  cosh(x)
#define r_tanh(x)  tanh(x)
#define r_atan2(y,x)  atan2(y,x)
#define r_hypot(x,y)  hypot(x,y)

typedef scomplex dtype;
typedef float rtype;

#include "complex.h"

static inline dtype c_from_dcomplex(dcomplex x) {
    dtype z;
    REAL(z) = REAL(x);
    IMAG(z) = IMAG(x);
    return z;
}

/* --------------------------- */

#define m_zero c_zero()
#define m_one  c_one()

#define m_num_to_data(x) NUM2COMP(x)
#define m_data_to_num(x) COMP2NUM(x)

#define m_from_double(x) c_new(x,0)
#define m_from_real(x)   c_new(x,0)
#define m_from_dcomplex(x) c_from_dcomplex(x)

#define m_extract(x) COMP2NUM(*(dtype*)x)

#define m_real(x)  REAL(x)
#define m_imag(x)  IMAG(x)
#define m_set_real(x,y)  c_set_real(x,y)
#define m_set_imag(x,y)  c_set_imag(x,y)

#define m_add(x,y) c_add(x,y)
#define m_sub(x,y) c_sub(x,y)
#define m_mul(x,y) c_mul(x,y)
#define m_div(x,y) c_div(x,y)
#define m_mod(x,y) c_mod(x,y)
#define m_pow(x,y) c_pow(x,y)

#define m_minus(x)   c_minus(x)
#define m_inverse(x) c_inverse(x)
#define m_square(x)  c_square(x)
#define m_im(x)      c_im(x)

#define m_conj(x)  c_new(REAL(x),-IMAG(x))
#define m_abs(x)   c_abs(x)
#define m_arg(x)   atan2(IMAG(x),REAL(x))

#define m_eq(x,y) c_eq(x,y)
#define m_ne(x,y) c_ne(x,y)
#define m_neary_eq(x,y) c_nearly_eq(x,y)
//(fabs(x-y)<=(fabs(x)+fabs(y))*DBL_EPSILON*2)

#define m_isnan(x)    c_isnan(x)
#define m_isinf(x)    c_isinf(x)
#define m_isfinite(x) c_isfinite(x)

#define m_sum(x,y) {if (!c_isnan(x)) {y=c_add(x,y);}}
#define m_sum_init INT2FIX(0)

#define m_rand c_new(to_res53(gen_rand64()),to_res53(gen_rand64()))
#define m_rand_norm(a) rand_norm(a)

#define m_sprintf(s,x) sprintf(s,"%g%+gi",REAL(x),IMAG(x))

#define m_sqrt(x)    c_sqrt(x)
#define m_cbrt(x)    c_cbrt(x)
#define m_log(x)     c_log(x)
#define m_log2(x)    c_log2(x)
#define m_log10(x)   c_log10(x)
#define m_exp(x)     c_exp(x)
#define m_exp2(x)    c_exp2(x)
#define m_exp10(x)   c_exp10(x)
#define m_sin(x)     c_sin(x)
#define m_cos(x)     c_cos(x)
#define m_tan(x)     c_tan(x)
#define m_asin(x)    c_asin(x)
#define m_acos(x)    c_acos(x)
#define m_atan(x)    c_atan(x)
#define m_sinh(x)    c_sinh(x)
#define m_cosh(x)    c_cosh(x)
#define m_tanh(x)    c_tanh(x)
#define m_asinh(x)   c_asinh(x)
#define m_acosh(x)   c_acosh(x)
#define m_atanh(x)   c_atanh(x)
#define m_hypot(x,y) c_hypot(x,y)

