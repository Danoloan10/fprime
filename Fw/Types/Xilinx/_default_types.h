/*
 *  $Id$
 */

#ifndef _MACHINE__DEFAULT_TYPES_H
#define _MACHINE__DEFAULT_TYPES_H

#ifndef __GNUC_PREREQ
# if defined __GNUC__ && defined __GNUC_MINOR__
#  define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
# else
#  define __GNUC_PREREQ(maj, min) 0
# endif
#endif /* __GNUC_PREREQ */
/* Version with trailing underscores for BSD compatibility. */
#define	__GNUC_PREREQ__(ma, mi)	__GNUC_PREREQ(ma, mi)

/*
 * Guess on types by examining *_MIN / *_MAX defines.
 */
#if __GNUC_PREREQ (3, 3)
/* GCC >= 3.3.0 has __<val>__ implicitly defined. */
#define __EXP(x) __##x##__
#else
/* Fall back to POSIX versions from <limits.h> */
#define __EXP(x) x
#error "Version GCC <3.3.0 not supported"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ __int8_t;
typedef __UINT8_TYPE__ __uint8_t;
#define ___int8_t_defined 1
#elif __EXP(SCHAR_MAX) == 0x7f
typedef signed char __int8_t ;
typedef unsigned char __uint8_t ;
#define ___int8_t_defined 1
#endif

#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ __int16_t;
typedef __UINT16_TYPE__ __uint16_t;
#define ___int16_t_defined 1
#elif __EXP(INT_MAX) == 0x7fff
typedef signed int __int16_t;
typedef unsigned int __uint16_t;
#define ___int16_t_defined 1
#elif __EXP(SHRT_MAX) == 0x7fff
typedef signed short __int16_t;
typedef unsigned short __uint16_t;
#define ___int16_t_defined 1
#elif __EXP(SCHAR_MAX) == 0x7fff
typedef signed char __int16_t;
typedef unsigned char __uint16_t;
#define ___int16_t_defined 1
#endif

#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ __int32_t;
typedef __UINT32_TYPE__ __uint32_t;
#define ___int32_t_defined 1
#elif __EXP(INT_MAX) == 0x7fffffffL
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#define ___int32_t_defined 1
#elif __EXP(LONG_MAX) == 0x7fffffffL
typedef signed long __int32_t;
typedef unsigned long __uint32_t;
#define ___int32_t_defined 1
#elif __EXP(SHRT_MAX) == 0x7fffffffL
typedef signed short __int32_t;
typedef unsigned short __uint32_t;
#define ___int32_t_defined 1
#elif __EXP(SCHAR_MAX) == 0x7fffffffL
typedef signed char __int32_t;
typedef unsigned char __uint32_t;
#define ___int32_t_defined 1
#endif

#ifdef __INT64_TYPE__
typedef __INT64_TYPE__ __int64_t;
typedef __UINT64_TYPE__ __uint64_t;
#define ___int64_t_defined 1
#elif __EXP(LONG_MAX) > 0x7fffffff
typedef signed long __int64_t;
typedef unsigned long __uint64_t;
#define ___int64_t_defined 1

/* GCC has __LONG_LONG_MAX__ */
#elif  defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ > 0x7fffffff)
typedef signed long long __int64_t;
typedef unsigned long long __uint64_t;
#define ___int64_t_defined 1

/* POSIX mandates LLONG_MAX in <limits.h> */
#elif  defined(LLONG_MAX) && (LLONG_MAX > 0x7fffffff)
typedef signed long long __int64_t;
typedef unsigned long long __uint64_t;
#define ___int64_t_defined 1

#elif  __EXP(INT_MAX) > 0x7fffffff
typedef signed int __int64_t;
typedef unsigned int __uint64_t;
#define ___int64_t_defined 1
#endif

#ifdef __INT_LEAST8_TYPE__
typedef __INT_LEAST8_TYPE__ __int_least8_t;
typedef __UINT_LEAST8_TYPE__ __uint_least8_t;
#define ___int_least8_t_defined 1
#elif defined(___int8_t_defined)
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
#define ___int_least8_t_defined 1
#elif defined(___int16_t_defined)
typedef __int16_t __int_least8_t;
typedef __uint16_t __uint_least8_t;
#define ___int_least8_t_defined 1
#elif defined(___int32_t_defined)
typedef __int32_t __int_least8_t;
typedef __uint32_t __uint_least8_t;
#define ___int_least8_t_defined 1
#elif defined(___int64_t_defined)
typedef __int64_t __int_least8_t;
typedef __uint64_t __uint_least8_t;
#define ___int_least8_t_defined 1
#endif

#ifdef __INT_LEAST16_TYPE__
typedef __INT_LEAST16_TYPE__ __int_least16_t;
typedef __UINT_LEAST16_TYPE__ __uint_least16_t;
#define ___int_least16_t_defined 1
#elif defined(___int16_t_defined)
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
#define ___int_least16_t_defined 1
#elif defined(___int32_t_defined)
typedef __int32_t __int_least16_t;
typedef __uint32_t __uint_least16_t;
#define ___int_least16_t_defined 1
#elif defined(___int64_t_defined)
typedef __int64_t __int_least16_t;
typedef __uint64_t __uint_least16_t;
#define ___int_least16_t_defined 1
#endif

#ifdef __INT_LEAST32_TYPE__
typedef __INT_LEAST32_TYPE__ __int_least32_t;
typedef __UINT_LEAST32_TYPE__ __uint_least32_t;
#define ___int_least32_t_defined 1
#elif defined(___int32_t_defined)
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
#define ___int_least32_t_defined 1
#elif defined(___int64_t_defined)
typedef __int64_t __int_least32_t;
typedef __uint64_t __uint_least32_t;
#define ___int_least32_t_defined 1
#endif

#ifdef __INT_LEAST64_TYPE__
typedef __INT_LEAST64_TYPE__ __int_least64_t;
typedef __UINT_LEAST64_TYPE__ __uint_least64_t;
#define ___int_least64_t_defined 1
#elif defined(___int64_t_defined)
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
#define ___int_least64_t_defined 1
#endif

#ifdef __INTPTR_TYPE__
typedef __INTPTR_TYPE__ __intptr_t;
typedef __UINTPTR_TYPE__ __uintptr_t;
#elif defined(__PTRDIFF_TYPE__)
typedef __PTRDIFF_TYPE__ __intptr_t;
typedef unsigned __PTRDIFF_TYPE__ __uintptr_t;
#else
typedef long __intptr_t;
typedef unsigned long __uintptr_t;
#endif

#undef __EXP

#ifdef __cplusplus
}
#endif

#endif /* _MACHINE__DEFAULT_TYPES_H */
