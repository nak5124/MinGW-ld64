/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009, 2010 by the mingw-w64 project

 See the AUTHORS file for the list of contributors to the mingw-w64 project.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#define _GNU_SOURCE
#include <math.h>
#include <complex.h>

#if defined(_NEW_COMPLEX_FLOAT)
# define __FLT_TYPE	        float
# define __FLT_ABI(N)	      N##f
# define __FLT_CST(N)	      N##F
# define __FLT_EPSILON      __FLT_EPSILON__
# define __FLT_NAN	        NAN
# define __FLT_HUGE_VAL	    HUGE_VALF
# define __FLT_PI	          M_PI
# define __FLT_PI_2	        M_PI_2
# define __FLT_PI_4	        M_PI_4
# define __FLT_PI_3_4	      (M_PI - M_PI_4)
# define __FLT_LOG10E       0.434294481903251828F
# define __FLT_REPORT(NAME) NAME "f"
# define __FLT_IMP(N)       __imp_##N##f
#elif defined(_NEW_COMPLEX_DOUBLE)
# define __FLT_TYPE	        double
# define __FLT_ABI(N)	      N
# define __FLT_EPSILON      __DBL_EPSILON__
# define __FLT_CST(N)	      N
# define __FLT_NAN	        __builtin_nan("")
# define __FLT_HUGE_VAL	    HUGE_VAL
# define __FLT_PI	          M_PI
# define __FLT_PI_2	        M_PI_2
# define __FLT_PI_4	        M_PI_4
# define __FLT_PI_3_4	      (M_PI - M_PI_4)
# define __FLT_LOG10E       4.34294481903251827651E-1
# define __FLT_REPORT(NAME)	NAME
# define __FLT_IMP(N)       __imp_##N
#else
# error "Unknown complex number type"
#endif
