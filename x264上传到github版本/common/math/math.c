#include <klib.h>

// Navy does not support floating point

#define LN2 0.6931471805599453
#define LN10 2.302585092994046
#define EXP 1e-7

double fabs(double x) {
  if(x < 0) x = 0 - x;
  return x;
}

double sin(double x) {
  assert(0);
}

double cos(double x) {
  assert(0);
}

double tan(double x) {
  assert(0);
}

double sqrt(double x) {
    if (0 == x)
        return x;
 
    double last = x, ret = x;
 
    for (;;) {
        last = 0.5 * (ret + x / ret);
        if (fabs(ret - last) < EXP)
            break;
        ret = last;
    }  
	return ret;
}


double log(double x) {
    double y, y2, r, num, lr, r1, x2;
	unsigned long den;
	int i, n, j;

	if (x <= 0) //无效的参数
	{
		return 0;
	}

	if (x == 1)
	{
		return 0;
	}

	j = 0;
	while (x < 1)
	{
		x *= 10;
		j++;
	}

	if (x > 1 && x < 2)
	{
		y = (x - 1) / (x + 1);
		y2 = y * y;

		r = 0;
		num = y;
		den = 1;

		do {
			lr = r;
			r += num / den;
			num *= y2;
			den += 2;
		} while (lr != r);

		return (r * 2 - j * LN10);
	}
	else
	{
		i = 0;
		n = 1;
		den = 2;

		while (x > 2)
		{
			x /= 2;
			i++;
		}

		x = (x - 1) / (x + 1);
		x2 = x * x;
		r1 = 2 * x;
		r = 0;

		while (r1 > 1E-15)
		{
			r += r1;
			n += den;
			x *= x2;
			r1 = 2 * x / n;
		}

		return (r + LN2 * i - j * LN10);
	}
}

double exp(double x)
{
    x = 1.0 + x/256;
    x *= x; x *= x; x *= x; x *= x;
    x *= x; x *= x; x *= x; x *= x;
    return x;
}

double pow(double x, double y) {
	double result = 1.0;
	int exponent = (int)y;

	if(y == 0)
	{
		return 1.0;		// 任何数的0次幂都为1
	}

	// 计算整数幂
	if(exponent > 0)
	{
		for(int i = 0; i < exponent; i++)
		{
			result *= x;
		}
	}
	else if(exponent < 0)
	{
		for(int i = 0; i > exponent; i--)
		{
			result /= x;
		}
	}
	
	// 处理小数幂
	if(y != exponent)
	{
		result *= exp(y * log(fabs(x)));
	}
	
	return result;
}

double floor(double x) {
	// double y = x;
	if( (*( ( (int *) &x)+1) & 0x80000000)  != 0) //或者if(x<0)
		return (float)((int)x)-1;
	else
		return (float)((int)x);
}

double ceil(double x) {
   	// double y = x;
    if( (*( ( (int *) &x)+1) & 0x80000000) != 0)//或者if(x<0)
        return (float)((int)x);
    else                 //讨论非负的情况。
   	{
        if(x == 0)
        	return (float)((int)x);
        else
        	return (float)((int)x) + 1;
   	}
}

double round(double x) {
	return (x > 0.0) ? floor(x + 0.5) : ceil(x - 0.5);
}


uint64_t __make_mantissa_base8(const char *__tagp) {
  uint64_t __r = 0;
  while (*__tagp != '\0') {
    char __tmp = *__tagp;

    if (__tmp >= '0' && __tmp <= '7')
      __r = (__r * 8u) + __tmp - '0';
    else
      return 0;

    ++__tagp;
  }

  return __r;
}

uint64_t __make_mantissa_base10(const char *__tagp) {
  uint64_t __r = 0;
  while (*__tagp != '\0') {
    char __tmp = *__tagp;

    if (__tmp >= '0' && __tmp <= '9')
      __r = (__r * 10u) + __tmp - '0';
    else
      return 0;

    ++__tagp;
  }

  return __r;
}

uint64_t __make_mantissa_base16(const char *__tagp) {
  uint64_t __r = 0;
  while (*__tagp != '\0') {
    char __tmp = *__tagp;

    if (__tmp >= '0' && __tmp <= '9')
      __r = (__r * 16u) + __tmp - '0';
    else if (__tmp >= 'a' && __tmp <= 'f')
      __r = (__r * 16u) + __tmp - 'a' + 10;
    else if (__tmp >= 'A' && __tmp <= 'F')
      __r = (__r * 16u) + __tmp - 'A' + 10;
    else
      return 0;

    ++__tagp;
  }

  return __r;
}

uint64_t __make_mantissa(const char *__tagp) {
  if (*__tagp == '0') {
    ++__tagp;

    if (*__tagp == 'x' || *__tagp == 'X')
      return __make_mantissa_base16(__tagp);
    else
      return __make_mantissa_base8(__tagp);
  }

  return __make_mantissa_base10(__tagp);
}

double nan(const char *__tagp) {
  union {
    double val;
    struct ieee_double {
      uint64_t mantissa : 51;
      uint32_t quiet : 1;
      uint32_t exponent : 11;
      uint32_t sign : 1;
    } bits;
  } __tmp;
  assert(sizeof(__tmp.val) == sizeof(__tmp.bits));

  __tmp.bits.sign = 0u;
  __tmp.bits.exponent = 2047u;//~0u;
  __tmp.bits.quiet = 1u;
  __tmp.bits.mantissa = __make_mantissa(__tagp);

  return __tmp.val;

}





