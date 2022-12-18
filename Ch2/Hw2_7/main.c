/*
#include<stdio.h>============================================================================
*/
/*
 * stdio.h
 *
 * Definitions of types and prototypes of functions for operations on
 * standard input and standard output streams.
 *
 * $Id: stdio.h,v cfaff99b541a 2017/05/24 22:11:33 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2005, 2007-2010, 2014-2017, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * NOTE: The file manipulation functions provided by Microsoft seem to
 * work with either slash (/) or backslash (\) as the directory separator;
 * (this is consistent with Microsoft's own documentation, on MSDN).
 *
 */
#ifndef _STDIO_H
#pragma GCC system_header

/* When including <wchar.h>, some of the definitions and declarations
 * which are nominally provided in <stdio.h> must be duplicated.  Rather
 * than require duplicated maintenance effort, we provide for partial
 * inclusion of <stdio.h> by <wchar.h>; only when not included in
 * this partial fashion...
 */
#ifndef __WCHAR_H_SOURCED__
 /*
  * ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <stdio.h> itself.
  */
#define _STDIO_H
#endif

/* All the headers include this file.
 */
#include <_mingw.h>

#ifndef RC_INVOKED
/* POSIX stipulates that the following set of types, (as identified by
 * __need_TYPENAME macros), shall be defined consistently with <stddef.h>;
 * by defining the appropriate __need_TYPENAME macros, we may selectively
 * obtain the required definitions by inclusion of <stddef.h>, WITHOUT
 * automatic exposure of any of its additional content.
 */
#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#define __need_wint_t
#include <stddef.h>

#if _POSIX_C_SOURCE >= 200809L
 /* Similarly, for types defined in <sys/types.h>, (which are explicitly
  * dependent on the POSIX.1-2008 feature test)...
  */
# define __need_off_t
# define __need_ssize_t
#endif
#if !(defined __STRICT_ANSI__ || defined (__NO_MINGW_LFS)) \
 && defined (__MSVCRT__)
 /* ...while this is required to support our fseeko64() and ftello64()
  * implementations, (neither of which is in any way standardized)...
  */
# define __need___off64_t
#endif
/* It is sufficient to test for just one define from each of the two
 * preceding groups...
 */
#if defined __need_off_t || defined __need___off64_t
 /* ...to identify a requirement for selective inclusion of one or more
  * of these type definitions from "sys/types.h"; (note that we use the
  * #include "..." form here, to ensure that we get the correct header
  * file, relative to the location of this <stdio.h>).
  */
# include "sys/types.h"
#endif

#ifndef __VALIST
 /* Also similarly, for the va_list type, defined in "stdarg.h"
  */
# if defined __GNUC__ && __GNUC__ >= 3
#  define __need___va_list
#  include "stdarg.h"
#  define __VALIST __builtin_va_list
# else
#  define __VALIST char *
# endif
#endif
#endif	/* ! RC_INVOKED */

#ifdef _STDIO_H
/* Flags for the iobuf structure
 */
#define _IOREAD 	1	/* currently reading */
#define _IOWRT		2	/* currently writing */
#define _IORW	   0x0080	/* opened as "r+w" */

/* The three standard file pointers provided by the run time library.
 * NOTE: These will go to the bit-bucket silently in GUI applications!
 */
#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

/* Returned by various functions on end of file condition or error.
 */
#define EOF	      (-1)

#endif	/* _STDIO_H */

/* The maximum length of a file name.  It may be better to use the Windows'
 * GetVolumeInformation() function in preference to this constant, but hey,
 * this works!  Note that <io.h> also defines it, but we don't guard it, so
 * that the compiler has a chance to catch inconsistencies.
 *
 * FIXME: Right now, we define this unconditionally for both full <stdio.h>
 * inclusion, and for partial inclusion on behalf of <wchar.h>, (which needs
 * it for some non-ANSI structure declarations).  The conditions under which
 * <wchar.h> needs this require review, because defining it as a consequence
 * of including <wchar.h> alone may violate strict ANSI conformity.
 */
#define FILENAME_MAX  (260)

#ifdef _STDIO_H
/* The maximum number of files that may be open at once. I have set this to
 * a conservative number. The actual value may be higher.
 */
#define FOPEN_MAX      (20)

/* After creating this many names, tmpnam and tmpfile return NULL
 */
#define TMP_MAX      32767

/* Tmpnam, tmpfile and, sometimes, _tempnam try to create
 * temp files in the root directory of the current drive
 * (not in pwd, as suggested by some older MS doc's).
 * Redefining these macros does not effect the CRT functions.
 */
#define _P_tmpdir   "\\"
#ifndef __STRICT_ANSI__
#define P_tmpdir _P_tmpdir
#endif
#define _wP_tmpdir  L"\\"

/* The maximum size of name (including NUL) that will be put in the user
 * supplied buffer caName for tmpnam.
 * Inferred from the size of the static buffer returned by tmpnam
 * when passed a NULL argument. May actually be smaller.
 */
#define L_tmpnam (16)

#define _IOFBF		0x0000	/* full buffered */
#define _IOLBF		0x0040	/* line buffered */
#define _IONBF		0x0004	/* not buffered */

#define _IOMYBUF	0x0008	/* stdio malloc()'d buffer */
#define _IOEOF		0x0010	/* EOF reached on read */
#define _IOERR		0x0020	/* I/O error from system */
#define _IOSTRG 	0x0040	/* Strange or no file descriptor */
#ifdef _POSIX_SOURCE
# define _IOAPPEND	0x0200
#endif

/* The buffer size as used by setbuf such that it is equivalent to
 * (void) setvbuf(fileSetBuffer, caBuffer, _IOFBF, BUFSIZ).
 */
#define BUFSIZ		   512

/* Constants for nOrigin indicating the position relative to which fseek
 * sets the file position.  Defined unconditionally since ISO and POSIX
 * say they are defined here.
 */
#define SEEK_SET	     0
#define SEEK_CUR	     1
#define SEEK_END	     2

#endif	/* _STDIO_H */

#ifndef RC_INVOKED
#if ! (defined _STDIO_H && defined _WCHAR_H)
/* The structure underlying the FILE type; this should be defined when
 * including either <stdio.h> or <wchar.h>.  If both header include guards
 * are now in place, then we must currently be including <stdio.h> in its
 * own right, having already processed this block during a prior partial
 * inclusion by <wchar.h>; there is no need to process it a second time.
 *
 * Some believe that nobody in their right mind should make use of the
 * internals of this structure. Provided by Pedro A. Aranda Gutiirrez
 * <paag@tid.es>.
 */
typedef struct _iobuf
{
  char	*_ptr;
  int	 _cnt;
  char	*_base;
  int	 _flag;
  int	 _file;
  int	 _charbuf;
  int	 _bufsiz;
  char	*_tmpfname;
} FILE;

#endif  /* ! (_STDIO_H && _WCHAR_H) */
#ifdef _STDIO_H
/* Content to be exposed only when including <stdio.h> in its own right;
 * these will not be exposed when __WCHAR_H_SOURCE__ is defined, as will
 * be the case when <stdio.h> is included indirectly, by <wchar.h>
 *
 *
 * The standard file handles
 */
#ifndef __DECLSPEC_SUPPORTED

extern FILE (*_imp___iob)[];	/* A pointer to an array of FILE */

#define _iob (*_imp___iob)	/* An array of FILE */

#else /* __DECLSPEC_SUPPORTED */

__MINGW_IMPORT FILE _iob[];	/* An array of FILE imported from DLL. */

#endif /* __DECLSPEC_SUPPORTED */

#define stdin	(&_iob[STDIN_FILENO])
#define stdout	(&_iob[STDOUT_FILENO])
#define stderr	(&_iob[STDERR_FILENO])

/* Need to close the current _STDIO_H specific block here...
 */
#endif
/* ...because, we need this regardless of the inclusion mode...
 */
_BEGIN_C_DECLS

#ifdef _STDIO_H
/* ...then revert to _STDIO_H specific mode, to declare...
 *
 *
 * File Operations
 */
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fopen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * freopen (const char *, const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fflush (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fclose (FILE *);

/* Note: Microsoft also declares remove & rename (but not their wide char
 * variants) in <io.h>; since duplicate prototypes are acceptable, provided
 * they are consistent, we simply declare them here anyway, while allowing
 * the compiler to check consistency as appropriate.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    remove (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rename (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * tmpfile (void);
_CRTIMP __cdecl __MINGW_NOTHROW  char * tmpnam (char *);

#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  char *_tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _unlink (const char *);

#if __MSVCRT_VERSION__>=__MSVCR80_DLL
/* The following pair of non-ANSI functions require a non-free version of
 * the Microsoft runtime; neither is provided by any MSVCRT.DLL variant.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void  _lock_file(FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void  _unlock_file(FILE *);
#endif

#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  char * tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    unlink (const char *);
#endif
#endif /* __STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  int    setvbuf (FILE *, char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void   setbuf (FILE *, char *);

/* Formatted Output
 *
 * MSVCRT implementations are not ANSI C99 conformant...
 * we offer conforming alternatives from libmingwex.a
 */
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_mingw_printf(F,A) __attribute__((__format__(__mingw_printf__,F,A)))

#if __GNUC__ >= 6
/* From GCC-6 onwards, we will provide customized -Wformat
 * handling, via our own mingw_printf format category...
 */
#define __Wformat(F)		__Wformat_##F __mingw_##F

#else	/* __GNUC__ < 6 */
/* ...whereas, for earlier GCC, we preserve the status quo,
 * offering no -Wformat checking for those functions which
 * replace the MSVCRT.DLL versions...
 */
#define __Wformat(F)		__mingw_##F
/*
 * ...while degrading to gnu_printf checking for snprintf()
 * and vsnprintf(), (which are ALWAYS MinGW.org variants).
 */
#define __mingw_printf__	__gnu_printf__
#endif

/* The following convenience macros specify the appropriate
 * -Wformat checking for MSVCRT.DLL replacement functions...
 */
#define __Wformat_printf	__Wformat_mingw_printf(1,2)
#define __Wformat_fprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_sprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_vprintf	__Wformat_mingw_printf(1,0)
#define __Wformat_vfprintf	__Wformat_mingw_printf(2,0)
#define __Wformat_vsprintf	__Wformat_mingw_printf(2,0)
/*
 * ...while this pair are specific to the two MinGW.org
 * only functions.
 */
#define __Wformat_snprintf	__Wformat_mingw_printf(3,4)
#define __Wformat_vsnprintf	__Wformat_mingw_printf(3,0)

extern int __mingw_stdio_redirect__(fprintf)(FILE*, const char*, ...);
extern int __mingw_stdio_redirect__(printf)(const char*, ...);
extern int __mingw_stdio_redirect__(sprintf)(char*, const char*, ...);
extern int __mingw_stdio_redirect__(snprintf)(char*, size_t, const char*, ...);
extern int __mingw_stdio_redirect__(vfprintf)(FILE*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vprintf)(const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsprintf)(char*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsnprintf)(char*, size_t, const char*, __VALIST);

/* When using these C99 conforming alternatives, we may wish to support
 * some of Microsoft's quirky formatting options, even when they violate
 * strict C99 conformance.
 */
#define _MSVC_PRINTF_QUIRKS		0x0100U
#define _QUERY_MSVC_PRINTF_QUIRKS	~0U, 0U
#define _DISABLE_MSVC_PRINTF_QUIRKS	~_MSVC_PRINTF_QUIRKS, 0U
#define _ENABLE_MSVC_PRINTF_QUIRKS	~0U, _MSVC_PRINTF_QUIRKS

/* Those quirks which conflict with ANSI C99 specified behaviour are
 * disabled by default; use the following function, like this:
 *
 *   _mingw_output_format_control( _ENABLE_MSVC_PRINTF_QUIRKS );
 *
 * to enable them, like this:
 *
 *   state = _mingw_output_format_control( _QUERY_MSVC_PRINTF_QUIRKS )
 *		& _MSVC_PRINTF_QUIRKS;
 *
 * to ascertain the currently active enabled state, or like this:
 *
 *   _mingw_output_format_control( _DISABLE_MSVC_PRINTF_QUIRKS );
 *
 * to disable them again.
 */
extern unsigned int _mingw_output_format_control( unsigned int, unsigned int );

#if __USE_MINGW_ANSI_STDIO
/* User has expressed a preference for C99 conformance...
 */
# undef __mingw_stdio_redirect__
# ifdef __cplusplus
/* For C++ we use inline implementations, to avoid interference
 * with namespace qualification, which may result from using #defines.
 */
#  define __mingw_stdio_redirect__  inline __cdecl __MINGW_NOTHROW

# elif defined __GNUC__
/* FIXME: Is there any GCC version prerequisite here?
 *
 * We also prefer inline implementations for C, when we can be confident
 * that the GNU specific __inline__ mechanism is supported.
 */
#  define __mingw_stdio_redirect__  static __inline__ __cdecl __MINGW_NOTHROW

# else
/* Can't use inlines; fall back on module local static stubs.
 */
#  define __mingw_stdio_redirect__  static __cdecl __MINGW_NOTHROW
# endif

__mingw_stdio_redirect__
int fprintf (FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int sprintf (char *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int vfprintf (FILE *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vfprintf( __stream, __format, __local_argv );
}

__mingw_stdio_redirect__
int vprintf (const char *__format, __VALIST __local_argv)
{
  return __mingw_vprintf( __format, __local_argv );
}

__mingw_stdio_redirect__
int vsprintf (char *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vsprintf( __stream, __format, __local_argv );
}

#else	/* !__USE_MINGW_ANSI_STDIO */
/* Default configuration: simply direct all calls to MSVCRT...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int fprintf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int printf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int sprintf (char *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int vfprintf (FILE *, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vprintf (const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vsprintf (char *, const char *, __VALIST);

#endif
/* Regardless of user preference, always offer these alternative
 * entry points, for direct access to the MSVCRT implementations,
 * with ms_printf -Wformat checking in each case.
 */
#undef  __Wformat
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_msvcrt_printf(F,A) __attribute__((__format__(__ms_printf__,F,A)))
#define __Wformat(F) __Wformat_ms_##F __msvcrt_##F

#define __Wformat_ms_printf	__Wformat_msvcrt_printf(1,2)
#define __Wformat_ms_fprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_sprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_vprintf	__Wformat_msvcrt_printf(1,0)
#define __Wformat_ms_vfprintf	__Wformat_msvcrt_printf(2,0)
#define __Wformat_ms_vsprintf	__Wformat_msvcrt_printf(2,0)

_CRTIMP int __mingw_stdio_redirect__(fprintf)(FILE *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(printf)(const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(sprintf)(char *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(vfprintf)(FILE *, const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vprintf)(const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vsprintf)(char *, const char *, __VALIST);

#undef  __mingw_stdio_redirect__
#undef  __Wformat

/* The following three ALWAYS refer to the MSVCRT implementations...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _snprintf (char *, size_t, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vsnprintf (char *, size_t, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vscprintf (const char *, __VALIST);

#ifdef _ISOC99_SOURCE
/* Microsoft does not provide implementations for the following,
 * which are required by C99.  Note in particular that Microsoft's
 * corresponding implementations of _snprintf() and _vsnprintf() are
 * NOT compatible with C99, but the following are; if you want the
 * MSVCRT behaviour, you MUST use the Microsoft "uglified" names.
 */
__cdecl __MINGW_NOTHROW __Wformat_snprintf
int snprintf (char *, size_t, const char *, ...);

__cdecl __MINGW_NOTHROW __Wformat_vsnprintf
int vsnprintf (char *, size_t, const char *, __VALIST);

__cdecl __MINGW_NOTHROW
int vscanf (const char * __restrict__, __VALIST);

__cdecl __MINGW_NOTHROW
int vfscanf (FILE * __restrict__, const char * __restrict__, __VALIST);

__cdecl __MINGW_NOTHROW
int vsscanf (const char * __restrict__, const char * __restrict__, __VALIST);

#endif  /* _ISOC99_SOURCE */
#endif	/* <stdio.h> included in its own right */

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/*
 * In MSVCR80.DLL, (and its descendants), Microsoft introduced variants
 * of the printf() functions, with names qualified by an underscore prefix
 * and "_p" or "_p_l" suffixes; implemented in Microsoft's typically crass,
 * non-standard, and non-portable fashion, these provide support for access
 * to printf() arguments in random order, as was standardised by POSIX as a
 * feature of the optional Extended Systems Interface (XSI) specification,
 * and is now required for conformity with the POSIX.1-2008 base standard.
 * Although these additional Microsoft functions were subsequently added
 * to MSVCRT.DLL, from Windows-Vista onward, and they are prototyped here,
 * MinGW applications are strenuously encouraged to avoid using them; a
 * much better alternative is to "#define _XOPEN_SOURCE 700" before any
 * system header is included, then use POSIX standard printf() functions
 * instead; this is both portable to many non-Windows platforms, and it
 * offers better compatibility with earlier Windows versions.
 */
#ifndef __have_typedef_locale_t
/* Note that some of the following require the opaque locale_t data type,
 * which we may obtain, by selective inclusion, from <locale.h>
 */
#define __need_locale_t
#include <locale.h>
#endif

#ifdef _STDIO_H
/* The following are to be declared only when <stdio.h> is explicitly
 * included; the first six are NOT dependent on locale_t...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p (const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p (FILE *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p (char *, size_t, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p (const char *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p (FILE *, const char *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p (char *, size_t, const char *, __VALIST);

/* ...whereas the following six DO depend on locale_t.
 *
 * CAVEAT: unless you are linking with non-free MSVCR80.DLL, or one
 * of its later derivatives, good luck trying to use these; see the
 * explanation in <locale.t>, as to why you may be unable to create,
 * or otherwise acquire a reference to, a locale_t object.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p_l (const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p_l (FILE *, const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p_l (char *, size_t, const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p_l (const char *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p_l (FILE *, const char *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p_l (char *, size_t, const char *, locale_t, __VALIST);

#endif	/* <stdio.h> included in its own right */
#endif	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */

#if ! (defined _STDIO_H && defined _WCHAR_H)
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/*
 * Wide character variants of the foregoing "positional parameter" printf()
 * functions; MSDN says that these should be declared when either <stdio.h>, or
 * <wchar.h> is included, so we make them selectively available to <wchar.h>,
 * but, just as in the foregoing, we advise against their use.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p (const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p (FILE *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p (wchar_t *, size_t, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p (const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p (FILE *, const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p (wchar_t *, size_t, const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p_l (const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p_l (FILE *, const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p_l (const wchar_t *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p_l (FILE *, const wchar_t *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, __VALIST);

#endif	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */
#endif	/* ! (defined _STDIO_H && defined _WCHAR_H) */
#ifdef _STDIO_H
/* Once again, back to <stdio.h> specific declarations.
 */
#if _POSIX_C_SOURCE >= 200809L
/* POSIX standard IEEE 1003.1-2008 added getdelim() and getline()
 */
__cdecl __MINGW_NOTHROW ssize_t
getdelim (char ** __restrict__, size_t * __restrict__, int, FILE * __restrict__);

__cdecl __MINGW_NOTHROW ssize_t
getline (char ** __restrict__, size_t * __restrict__, FILE * __restrict__);

#ifndef __NO_INLINE__
/* getline() is a trivial specialization of getdelim(), which may
 * be readily expressed by inline expansion.
 */
__CRT_ALIAS __LIBIMPL__(( FUNCTION = getline ))
__cdecl __MINGW_NOTHROW ssize_t getline
( char **__restrict__ __l, size_t *__restrict__ __n, FILE *__restrict__ __s )
{ return getdelim( __l, __n, '\n', __s ); }

#endif  /* !__NO_INLINE__ */
#endif  /* POSIX.1-2008 */

/* Formatted Input
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fscanf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    scanf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    sscanf (const char *, const char *, ...);

/* Character Input and Output Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * fgets (char *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputs (const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * gets (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    puts (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    ungetc (int, FILE *);

/* Traditionally, getc and putc are defined as macros. but the
 * standard doesn't say that they must be macros.  We use inline
 * functions here to allow the fast versions to be used in C++
 * with namespace qualification, eg., ::getc.
 *
 * NOTE: _filbuf and _flsbuf  are not thread-safe.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int   _filbuf (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _flsbuf (int, FILE *);

#if !defined _MT

__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int, FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int __c, FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    :  _flsbuf (__c, __F);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void)
{
  return (--stdin->_cnt >= 0)
    ?  (int) (unsigned char) *stdin->_ptr++
    : _filbuf (stdin);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int __c)
{
  return (--stdout->_cnt >= 0)
    ?  (int) (unsigned char) (*stdout->_ptr++ = (char)__c)
    :  _flsbuf (__c, stdout);}

#else  /* Use library functions.  */

_CRTIMP __cdecl __MINGW_NOTHROW  int    getc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    getchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putchar (int);

#endif

/* Direct Input and Output Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fread (void *, size_t, size_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fwrite (const void *, size_t, size_t, FILE *);

/* File Positioning Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fseek (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   ftell (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void   rewind (FILE *);

#if _WIN32_WINNT >= _WIN32_WINNT_VISTA || __MSVCRT_VERSION__ >= __MSVCR80_DLL
 /*
  * Microsoft introduced a number of variations on fseek() and ftell(),
  * beginning with MSVCR80.DLL; the bare _fseeki64() and _ftelli64() were
  * subsequently integrated into MSVCRT.DLL, from Vista onward...
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64 (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64 (FILE *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
 /*
  * ...while the "nolock" variants remain exclusive to MSVCR80.DLL, and
  * its later MSVC specific derivatives.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseek_nolock (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   _ftell_nolock (FILE *);

_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64_nolock (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64_nolock (FILE *);

#endif  /* MSVCR80.DLL and later derivatives ONLY */
#endif  /* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */

#ifdef __USE_MINGW_FSEEK
/* Workaround for a limitation on Win9x where a file is not zero padded
 * on write, following a seek beyond the original end of file; these are
 * implemented in libmingwex.a
 */
__cdecl __MINGW_NOTHROW  int    __mingw_fseek (FILE *, long, int);
__cdecl __MINGW_NOTHROW  size_t __mingw_fwrite (const void *, size_t, size_t, FILE *);

#define fwrite(buffer, size, count, fp)  __mingw_fwrite(buffer, size, count, fp)
#define fseek(fp, offset, whence)        __mingw_fseek(fp, offset, whence)
#endif /* __USE_MINGW_FSEEK */

/* An opaque data type used for storing file positions... The contents of
 * this type are unknown, but we (the compiler) need to know the size
 * because the programmer using fgetpos and fsetpos will be setting aside
 * storage for fpos_t structres. Actually I tested using a byte array and
 * it is fairly evident that the fpos_t type is a long (in CRTDLL.DLL).
 * Perhaps an unsigned long? TODO? It's definitely a 64-bit number in
 * MSVCRT however, and for now `long long' will do.
 */
#ifdef __MSVCRT__
typedef long long  fpos_t;
#else
typedef long       fpos_t;
#endif

_CRTIMP __cdecl __MINGW_NOTHROW  int fgetpos (FILE *, fpos_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int fsetpos (FILE *, const fpos_t *);

/* Error Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int feof (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int ferror (FILE *);

#ifdef __cplusplus
inline __cdecl __MINGW_NOTHROW  int feof (FILE * __F){ return __F->_flag & _IOEOF; }
inline __cdecl __MINGW_NOTHROW  int ferror (FILE * __F){ return __F->_flag & _IOERR; }
#else
#define feof(__F)     ((__F)->_flag & _IOEOF)
#define ferror(__F)   ((__F)->_flag & _IOERR)
#endif

_CRTIMP __cdecl __MINGW_NOTHROW  void clearerr (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void perror (const char *);


#ifndef __STRICT_ANSI__
/*
 * Pipes
 */
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _pclose (FILE *);

#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE *  popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     pclose (FILE *);
#endif

/* Other Non ANSI functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _flushall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fileno (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fcloseall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fsopen (const char *, const char *, int);
#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getmaxstdio (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _setmaxstdio (int);
#endif

/* Microsoft introduced a capability in MSVCR80.DLL and later, to
 * set the minimum number of digits to be displayed in a printf()
 * floating point exponent; they retro-fitted this in MSVCRT.DLL,
 * from Windows-Vista onwards, but we provide our own wrappers in
 * libmingwex.a, which make it possible for us to emulate the API
 * for any version of MSVCRT.DLL (including WinXP and earlier).
 */
#define _TWO_DIGIT_EXPONENT    1

/* While Microsoft define the preceding manifest constant, they
 * appear to neglect to define its complement, (for restoration
 * of their default exponent display format); for orthogonality,
 * we will provide this regardless of Microsoft's negligence.
 */
#define _THREE_DIGIT_EXPONENT  0

/* Once again, unspecified by Microsoft, (and mostly redundant),
 * it is convenient to specify a combining mask for these.
 */
#define _EXPONENT_DIGIT_MASK  (_TWO_DIGIT_EXPONENT | _THREE_DIGIT_EXPONENT)

unsigned int __cdecl __mingw_get_output_format (void);
unsigned int __cdecl __mingw_set_output_format (unsigned int);

/* Also appearing for the first time in MSVCR80.DLL, and then also
 * retro-fitted to MSVCRT.DLL from Windows-Vista onwards, was this
 * pair of functions to control availability of "%n" formatting in
 * the MSVCRT.DLL printf() family of functions, for which we also
 * provide our own DLL version agnostic wrappers:
 */
int __cdecl __mingw_get_printf_count_output (void);
int __cdecl __mingw_set_printf_count_output (int);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* When the user declares that MSVCR80.DLL features are supported,
 * we simply expose the corresponding APIs...
 */
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _get_output_format (void);
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _set_output_format (unsigned int);

_CRTIMP __cdecl __MINGW_NOTHROW  int _get_printf_count_output (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int _set_printf_count_output (int);

#else
/* ...otherwise, we emulate the APIs, in a DLL version agnostic
 * manner, using our own implementation wrappers.
 */
__CRT_ALIAS unsigned int __cdecl _get_output_format (void)
{ return __mingw_get_output_format (); }

__CRT_ALIAS unsigned int __cdecl _set_output_format (unsigned int __style)
{ return __mingw_set_output_format (__style); }

/* When using our own printf() implementation, "%n" format is ALWAYS
 * supported, so we make this API a no-op, reporting it to be so; for
 * the alternative case, when using MSVCRT.DLL's printf(), we delegate
 * to our wrapper API implementation, which will invoke the API function
 * calls within the DLL, if they are available, or persistently report
 * the state of "%n" formatting as DISABLED if they are not.
 */
#if __USE_MINGW_ANSI_STDIO
/* Note that __USE_MINGW_ANSI_STDIO is not guaranteed to resolve to any
 * symbol which will represent a compilable logic state; map it to this
 * alternative which will, for the true state...
 */
# define __USE_MINGW_PRINTF  1
#else
/* ...and for the false.
 */
# define __USE_MINGW_PRINTF  0
#endif

__CRT_ALIAS int __cdecl _get_printf_count_output (void)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_get_printf_count_output (); }

__CRT_ALIAS int __cdecl _set_printf_count_output (int __mode)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_set_printf_count_output (__mode); }
#endif

#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fileno (FILE *);
#endif	/* !_NO_OLDNAMES */

#define _fileno(__F) ((__F)->_file)
#ifndef _NO_OLDNAMES
#define fileno(__F) ((__F)->_file)
#endif

#if defined (__MSVCRT__) && ! defined (__NO_MINGW_LFS)
__CRT_ALIAS FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char *, const char *);
__CRT_ALIAS __JMPSTUB__(( FUNCTION = fopen64, REMAPPED = fopen ))
FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char * filename, const char * mode)
{ return fopen (filename, mode); }

int __cdecl __MINGW_NOTHROW  fseeko64 (FILE *, __off64_t, int);

#ifdef __USE_MINGW_FSEEK
int __cdecl __MINGW_NOTHROW __mingw_fseeko64 (FILE *, __off64_t, int);
#define fseeko64(fp, offset, whence)  __mingw_fseeko64(fp, offset, whence)
#endif

__CRT_ALIAS __off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE *);
__CRT_ALIAS __LIBIMPL__(( FUNCTION = ftello64 ))
__off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE * stream)
{ fpos_t __pos; return (fgetpos(stream, &__pos)) ? -1LL : (__off64_t)(__pos); }

#endif	/* __MSVCRT__ && !__NO_MINGW_LFS */
#endif	/* !__STRICT_ANSI__ */
#endif	/* _STDIO_H */

#if ! (defined _STDIO_H && defined _WCHAR_H)
/* The following are declared when including either <stdio.h> or <wchar.h>.
 * If both header include guards are now in place, then we must currently be
 * including <stdio.h> in its own right, having already processed this block
 * during prior partial inclusion by <wchar.h>; there is no need to process
 * it a second time.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwprintf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wprintf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vfwprintf (FILE *, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _snwprintf (wchar_t *, size_t, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vscwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwscanf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wscanf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     swscanf (const wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwc (wchar_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  ungetwc (wchar_t, FILE *);

#ifndef __STRICT_ANSI__
/* These differ from the ISO C prototypes, which have a maxlen parameter (like snprintf).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int  swprintf (wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int  vswprintf (wchar_t *, const wchar_t *, __VALIST);
#endif

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * fgetws (wchar_t *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       fputws (const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwc (wint_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwchar (wint_t);

#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _getws (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _putws (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfdopen(int, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfopen (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfreopen (const wchar_t *, const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfsopen (const wchar_t *, const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtmpnam (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtempnam (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wrename (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wremove (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  void      _wperror (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wpopen (const wchar_t *, const wchar_t *);

#endif  /* !__STRICT_ANSI__ */
#endif	/* __MSVCRT__ */

#ifdef _ISOC99_SOURCE
__JMPSTUB__(( FUNCTION = snwprintf, DLLENTRY = _snwprintf ))
__cdecl __MINGW_NOTHROW  int snwprintf (wchar_t *, size_t, const wchar_t *, ...);
__cdecl __MINGW_NOTHROW  int vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);

#ifndef __NO_INLINE__
__CRT_INLINE __cdecl __MINGW_NOTHROW
__JMPSTUB__(( FUNCTION = vsnwprintf, DLLENTRY = _vsnwprintf ))
int vsnwprintf (wchar_t *__s, size_t __n, const wchar_t *__fmt, __VALIST __arg)
{ return _vsnwprintf ( __s, __n, __fmt, __arg); }
#endif

__cdecl __MINGW_NOTHROW  int  vwscanf (const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vfwscanf (FILE *__restrict__, const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vswscanf (const wchar_t *__restrict__, const wchar_t * __restrict__, __VALIST);

#endif  /* _ISOC99_SOURCE */
#endif  /* ! (_STDIO_H && _WCHAR_H) */

#if defined _STDIO_H && ! defined __STRICT_ANSI__
#if defined __MSVCRT__ && ! defined _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * wpopen (const wchar_t *, const wchar_t *);
#endif

/* Other non-ANSI wide character functions...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _putw (int, FILE *);

#ifndef _NO_OLDNAMES
/* ...and their original names, before Microsoft uglification...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int     getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     putw (int, FILE *);

#endif  /* !_NO_OLDNAMES */
#endif  /* !__STRICT_ANSI__ */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif  /* !_STDIO_H: $RCSfile: stdio.h,v $: end of file */

/*
#include<stdlib.h>============================================================================
*/
/*
 * stdlib.h
 *
 * ANSI/POSIX + Microsoft compatible standard library function prototypes,
 * associated macros, and manifest constant definitions.
 *
 * $Id: stdlib.h,v 2f3798017d64 2016/11/28 14:14:48 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2009, 2011, 2014-2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _STDLIB_H
#pragma GCC system_header

/* Some of the content of this header is made selectively accessible,
 * when indirectly included via <wchar.h>; only when we have established
 * that this inclusion is NOT via this selective method...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...do we define the repeat inclusion guard for <stdlib.h> itself.
  */
#define _STDLIB_H

/* All MinGW headers must include <_mingw.h>; if included via <wchar.h>,
 * we assume that this has been done already, otherwise we must attend to
 * it for <stdlib.h>.
 */
#include <_mingw.h>

#ifndef RC_INVOKED
#define __need_size_t
#define __need_wchar_t
#define __need_NULL
#include <stddef.h>
#endif /* RC_INVOKED */

/* RAND_MAX is the maximum value that may be returned by rand.
 * The minimum is zero.
 */
#define RAND_MAX	0x7FFF

/* These values may be used as exit status codes.
 */
#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

/* Definitions for path name functions.
 * NOTE: All of these values have simply been chosen to be conservatively
 * high.  Remember that with long file names we can no longer depend on
 * extensions being short.
 */
#ifndef __STRICT_ANSI__

#ifndef MAX_PATH
#define MAX_PATH	(260)
#endif

#define _MAX_PATH	MAX_PATH
#define _MAX_DRIVE	(3)
#define _MAX_DIR	256
#define _MAX_FNAME	256
#define _MAX_EXT	256

#endif	/* !__STRICT_ANSI__ */
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED

_BEGIN_C_DECLS

#ifdef _STDLIB_H
#if ! defined __STRICT_ANSI__
/* This seems like a convenient place to declare these variables, which
 * give programs using WinMain (or main for that matter) access to main-ish
 * argc and argv. environ is a pointer to a table of environment variables.
 * NOTE: Strings in _argv and environ are ANSI strings.
 */
extern int     _argc;
extern char  **_argv;

#ifdef __MSVCRT__
/* Imports from the runtime DLL, for the above variables.
 */
extern __cdecl __MINGW_NOTHROW  int       *__p___argc(void);
extern __cdecl __MINGW_NOTHROW  char    ***__p___argv(void);
extern __cdecl __MINGW_NOTHROW  wchar_t ***__p___wargv(void);

#define __argc (*__p___argc())
#define __argv (*__p___argv())
#define __wargv (*__p___wargv())

#else  /* ! __MSVCRT__ */

#ifndef __DECLSPEC_SUPPORTED

extern int    *_imp____argc_dll;
extern char ***_imp____argv_dll;

#define __argc (*_imp____argc_dll)
#define __argv (*_imp____argv_dll)

#else  /* __DECLSPEC_SUPPORTED */

__MINGW_IMPORT int    __argc_dll;
__MINGW_IMPORT char **__argv_dll;

#define __argc __argc_dll
#define __argv __argv_dll

#endif  /* __DECLSPEC_SUPPORTED */

#endif  /* __MSVCRT__ */
#endif  /* __STRICT_ANSI__ */

#ifndef MB_CUR_MAX
/* FIXME: also defined in <ctype.h>; should be factored out.
 */
#ifdef __DECLSPEC_SUPPORTED
# ifdef __MSVCRT__
#  define MB_CUR_MAX __mb_cur_max
   __MINGW_IMPORT int __mb_cur_max;
# else  /* ! __MSVCRT__ */
#  define MB_CUR_MAX __mb_cur_max_dll
   __MINGW_IMPORT int __mb_cur_max_dll;
# endif  /* ! __MSVCRT__ */

#else  /* ! __DECLSPEC_SUPPORTED */
# ifdef __MSVCRT__
   extern int* _imp____mb_cur_max;
#  define MB_CUR_MAX (*_imp____mb_cur_max)
# else  /* ! __MSVCRT__ */
   extern int*  _imp____mb_cur_max_dll;
#  define MB_CUR_MAX (*_imp____mb_cur_max_dll)
# endif  /* ! __MSVCRT__ */
#endif  /*  __DECLSPEC_SUPPORTED */
#endif  /* MB_CUR_MAX */

/* FIXME: Nominally in <errno.h>, Microsoft likes to declare errno
 * in <stdlib.h> as well; we should factor this out.
 */
#ifdef _UWIN
# undef errno
  extern int errno;
#else
_CRTIMP __cdecl __MINGW_NOTHROW  int *_errno(void);
# define errno  (*_errno())
#endif
_CRTIMP __cdecl __MINGW_NOTHROW  int *__doserrno(void);
#define _doserrno  (*__doserrno())

#if !defined (__STRICT_ANSI__)
/* Use environ from the DLL, not as a global.
 */
#ifdef __MSVCRT__
# define _environ  (*__p__environ())
extern _CRTIMP __cdecl __MINGW_NOTHROW  char ***__p__environ(void);
# define _wenviron  (*__p__wenviron())
extern _CRTIMP __cdecl __MINGW_NOTHROW  wchar_t ***__p__wenviron(void);

#else  /* ! __MSVCRT__ */
# ifndef __DECLSPEC_SUPPORTED
# define _environ (*_imp___environ_dll)
extern char ***_imp___environ_dll;

# else  /* __DECLSPEC_SUPPORTED */
# define _environ  _environ_dll
__MINGW_IMPORT char ** _environ_dll;
# endif  /* __DECLSPEC_SUPPORTED */
#endif  /* ! __MSVCRT__ */

#define environ _environ

#ifdef	__MSVCRT__
/* One of the MSVCRTxx libraries */

#ifndef __DECLSPEC_SUPPORTED
# define sys_nerr  (*_imp___sys_nerr)
extern int *_imp___sys_nerr;

#else /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT int _sys_nerr;

# ifndef _UWIN
# define sys_nerr  _sys_nerr
# endif  /* _UWIN */
#endif  /* __DECLSPEC_SUPPORTED */

#else  /* ! __MSVCRT__ */
/* CRTDLL run time library */

#ifndef __DECLSPEC_SUPPORTED
  extern int*	_imp___sys_nerr_dll;
# define sys_nerr	(*_imp___sys_nerr_dll)
#else  /* __DECLSPEC_SUPPORTED */
  __MINGW_IMPORT int	_sys_nerr_dll;
# define sys_nerr	_sys_nerr_dll
#endif  /* __DECLSPEC_SUPPORTED */

#endif  /* ! __MSVCRT__ */

#ifndef __DECLSPEC_SUPPORTED
#define sys_errlist  (*_imp___sys_errlist)
extern char ***_imp__sys_errlist;

#else  /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT char *_sys_errlist[];

#ifndef _UWIN
#define sys_errlist  _sys_errlist
#endif  /* _UWIN */
#endif  /* __DECLSPEC_SUPPORTED */

/* OS version and such constants.
 */
#ifdef	__MSVCRT__ /* MSVCRT.DLL and MSVCRxx.DLL variants */

extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__osver(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winver(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winmajor(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winminor(void);

#ifndef __DECLSPEC_SUPPORTED
# define _osver     (*__p__osver())
# define _winver    (*__p__winver())
# define _winmajor  (*__p__winmajor())
# define _winminor  (*__p__winminor())

#else /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT  unsigned int _osver;
__MINGW_IMPORT  unsigned int _winver;
__MINGW_IMPORT  unsigned int _winmajor;
__MINGW_IMPORT  unsigned int _winminor;
#endif  /* __DECLSPEC_SUPPORTED */

#else  /* ! __MSVCRT__; thus CRTDLL */
#ifndef __DECLSPEC_SUPPORTED

#define _osver	    (*_imp___osver_dll)
#define _winver    (*_imp___winver_dll)
#define _winmajor  (*_imp___winmajor_dll)
#define _winminor  (*_imp___winminor_dll)

extern unsigned int *_imp___osver_dll;
extern unsigned int *_imp___winver_dll;
extern unsigned int *_imp___winmajor_dll;
extern unsigned int *_imp___winminor_dll;

#else  /* __DECLSPEC_SUPPORTED */

#define _osver	    _osver_dll
#define _winver    _winver_dll
#define _winmajor  _winmajor_dll
#define _winminor  _winminor_dll

__MINGW_IMPORT unsigned int _osver_dll;
__MINGW_IMPORT unsigned int _winver_dll;
__MINGW_IMPORT unsigned int _winmajor_dll;
__MINGW_IMPORT unsigned int _winminor_dll;

#endif  /* __DECLSPEC_SUPPORTED */
#endif  /* CRTDLL */

#if defined  __MSVCRT__
/* Although _pgmptr is exported as DATA, be safe and use the access
 * function __p__pgmptr() to get it.
 */
#define _pgmptr  (*__p__pgmptr())
_CRTIMP __cdecl __MINGW_NOTHROW  char **__p__pgmptr(void);

#define _wpgmptr  (*__p__wpgmptr())
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t **__p__wpgmptr(void);

#else  /* ! __MSVCRT__; thus CRTDLL */

# ifndef __DECLSPEC_SUPPORTED
# define _pgmptr  (*_imp___pgmptr_dll)
extern char **__imp__pgmptr_dll;

# else  /* __DECLSPEC_SUPPORTED */

# define _pgmptr _pgmptr_dll
__MINGW_IMPORT  char *_pgmptr_dll;
/* no wide version in CRTDLL */

# endif /* __DECLSPEC_SUPPORTED */
#endif	/* CRTDLL */

/* This variable determines the default file mode.
 * TODO: Which flags work?
 */
#if !defined (__DECLSPEC_SUPPORTED) || defined (__IN_MINGW_RUNTIME)

#ifdef __MSVCRT__
#define _fmode  (*_imp___fmode)
extern int *_imp___fmode;
#else
/* CRTDLL */
#define _fmode  (*_imp___fmode_dll)
extern int *_imp___fmode_dll;
#endif

#else  /* __DECLSPEC_SUPPORTED */
#ifdef __MSVCRT__
__MINGW_IMPORT  int _fmode;

#else  /* ! __MSVCRT__ */
#define _fmode	_fmode_dll
__MINGW_IMPORT  int _fmode_dll;

#endif  /* !__MSVCRT__ */
#endif  /* __DECLSPEC_SUPPORTED */
#endif  /* !__STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  int atoi (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  long atol (const char *);

_CRTIMP __cdecl __MINGW_NOTHROW  double strtod (const char *, char **);
_CRTIMP __cdecl __MINGW_NOTHROW  double atof (const char *);

#if !defined (__STRICT_ANSI__)
_CRTIMP __cdecl __MINGW_NOTHROW  double _wtof (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wtoi (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  long _wtol (const wchar_t *);
#endif

#if __USE_MINGW_ANSI_STDIO
/* Microsoft's strtod() and atof() implementations, (in MSVCRT.DLL),
 * mishandle infinities and NaNs; on the basis that this conditional
 * exposes a more ISO-C conforming printf() I/O family implementaion,
 * we substitute a similarly more conforming implementation for each
 * of this pair of (somewhat related) functions.
 *
 * Note that we provide neither __JMPSTUB__ nor __LIBIMPL__ external
 * equivalents for either of these two inline functions, because they
 * would conflict with the runtime DLL implementations; users needing
 * an address reference for either must provide an equivalent of the
 * inline implementation, as non-inlined within their own code.
 */
extern __cdecl __MINGW_NOTHROW
double __strtod (const char *__restrict__, char **__restrict__);

__CRT_ALIAS __cdecl __MINGW_NOTHROW
double strtod (const char *__restrict__ __nptr, char **__restrict__ __endptr)
{ return __strtod( __nptr, __endptr ); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
double atof (const char *__nptr) { return __strtod( __nptr, NULL ); }

#endif  /* __USE_MINGW_ANSI_STDIO */

#ifdef _ISOC99_SOURCE
/* Irrespective of requested standards conformity, where MSVCRT.DLL
 * falls short, ISO-C99 offers this pair of alternative return type
 * specific variants of strtod(), which MSVCRT.DLL does not, but we
 * do, in libmingwex.a:
 */
__cdecl __MINGW_NOTHROW
float strtof (const char *__restrict__, char **__restrict__);

__cdecl __MINGW_NOTHROW
long double strtold (const char *__restrict__, char **__restrict__);
#endif  /* _ISOC99_SOURCE */

_CRTIMP __cdecl __MINGW_NOTHROW  long strtol (const char *, char **, int);
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long strtoul (const char *, char **, int);

#endif	/* _STDLIB_H only */
#if ! (defined _STDLIB_H && defined _WCHAR_H)
/* Prototypes which are to be declared both here, in <stdlib.h>,
 * and also in <wchar.h>; declare them here, such that they may be
 * selectively included by <wchar.h>.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
long wcstol (const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned long wcstoul (const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW  double wcstod (const wchar_t *, wchar_t **);

#ifdef _ISOC99_SOURCE
/* Variants on wcstod(), specified by ISO-C99; once again, MSVCRT.DLL
 * doesn't have them, but we offer them in libmingwex.a
 */
__cdecl __MINGW_NOTHROW
float wcstof (const wchar_t *__restrict__, wchar_t **__restrict__);

__cdecl __MINGW_NOTHROW
long double wcstold (const wchar_t *__restrict__, wchar_t **__restrict__);
#endif  /* _ISOC99_SOURCE */

#ifdef __MSVCRT__
#if __MSVCRT_VERSION__ >= __MSVCR70_DLL || _WIN32_WINNT >= _WIN32_WINNT_WINXP
/* This pair of wide character equivalents for ISO-C99's strtoll() and
 * strtoull() require either WinXP (or later), or a non-free MSVC runtime
 * from MSVCR70.DLL onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _wcstoi64(const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _wcstoui64(const wchar_t *, wchar_t **, int);

#endif	/* WinXP || MSVCR70.DLL || later */

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* ...while the following pair require Win-Vista (or later), or non-free
 * MSVCRT runtime from MSVCR80.DLL onwards; they also require...
 */
#ifndef __have_typedef_locale_t
/* ...this opaque data type, which we may obtain by selective inclusion
 * from <locale.h>.  (Note that this may render them unusable for users of
 * MSVCRT.DLL; see the explanation in <locale.h>, regarding the difficulty
 * in creating, or otherwise acquiring a reference to, a _locale_t object,
 * notwithstanding the availability of the functions in MSVCRT.DLL, from
 * the release of Win-Vista onwards).
 */
#define __need_locale_t
#include <locale.h>
#endif	/* !__have_typedef_locale_t */

_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _wcstoi64_l(const wchar_t *, wchar_t **, int, _locale_t);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _wcstoui64_l(const wchar_t *, wchar_t **, int, _locale_t);

#endif	/* Win-Vista || MSVCR80.DLL || later */

_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wgetenv (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wputenv (const wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _wsearchenv (const wchar_t *, const wchar_t *, wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW  int _wsystem (const wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _wmakepath (wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *,
    const wchar_t *
  );

_CRTIMP __cdecl __MINGW_NOTHROW
void _wsplitpath (const wchar_t *, wchar_t *, wchar_t *, wchar_t *, wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
wchar_t *_wfullpath (wchar_t *, const wchar_t *, size_t);

#endif	/* __MSVCRT__ */
#endif	/* _STDLIB_H || _WCHAR_H */

#ifdef _STDLIB_H  /* <stdlib.h> only */
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcstombs (char *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int wctomb (char *, wchar_t);

_CRTIMP __cdecl __MINGW_NOTHROW  int mblen (const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t mbstowcs (wchar_t *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int mbtowc (wchar_t *, const char *, size_t);

_CRTIMP __cdecl __MINGW_NOTHROW  int rand (void);
_CRTIMP __cdecl __MINGW_NOTHROW  void srand (unsigned int);

_CRTIMP __cdecl __MINGW_NOTHROW  void *calloc (size_t, size_t) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  void *malloc (size_t) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  void *realloc (void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void free (void *);
_CRTIMP __cdecl __MINGW_NOTHROW  void abort (void) __MINGW_ATTRIB_NORETURN;
_CRTIMP __cdecl __MINGW_NOTHROW  void exit (int) __MINGW_ATTRIB_NORETURN;

/* Note: this is in startup code, not imported directly from the runtime DLL
 */
int __cdecl __MINGW_NOTHROW atexit (void (*)(void));

_CRTIMP __cdecl __MINGW_NOTHROW  int system (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *getenv (const char *);

/* bsearch() and qsort() are declared both here, in <stdlib.h>, and in
 * non-ANSI header <search.h>; we reproduce these declarations in both,
 * with no attempt to guard them, so the compiler may verify that they
 * are consistent, if both headers are included.
 */
_CRTIMP __cdecl  void *bsearch
(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

_CRTIMP __cdecl  void qsort
(void *, size_t, size_t, int (*)(const void *, const void *));

_CRTIMP __cdecl __MINGW_NOTHROW  int abs (int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  long labs (long) __MINGW_ATTRIB_CONST;

/* div_t and ldiv_t are structures used to return the results of div()
 * and ldiv() functions.
 *
 * NOTE: div() and ldiv() appear not to work correctly unless
 *       -fno-pcc-struct-return is specified. This is included in the
 *       mingw32 specs file.
 */
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

_CRTIMP __cdecl __MINGW_NOTHROW  div_t div (int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  ldiv_t ldiv (long, long) __MINGW_ATTRIB_CONST;

#if !defined __STRICT_ANSI__ || (defined _ISOC99_SOURCE && !defined __NO_INLINE__)
/* Although not nominally valid in "__STRICT_ANSI__" mode, when compiling C99
 * source, we use Microsoft's _exit() function to facilitate our provision of
 * an inline implementation of ISO-C99's _Exit() function.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void _exit (int) __MINGW_ATTRIB_NORETURN;

#ifdef __MSVCRT__
/* Similarly, we use Microsoft's MSVCRT.DLL specific _atoi64() function,
 * to facilitate an inline implementation of ISO-C99's atoll() function.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _atoi64 (const char *);

#endif	/* __MSVCRT__ */
#endif	/* !__STRICT_ANSI__ || (_ISOC99_SOURCE && !__NO_INLINE__) */

#if !defined (__STRICT_ANSI__)
/* NOTE: Officially the three following functions are obsolete. The Win32 API
 *       functions SetErrorMode, Beep and Sleep are their replacements.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void _beep (unsigned int, unsigned int) __MINGW_ATTRIB_DEPRECATED;
/* Not to be confused with  _set_error_mode (int).  */
_CRTIMP __cdecl __MINGW_NOTHROW  void _seterrormode (int) __MINGW_ATTRIB_DEPRECATED;
_CRTIMP __cdecl __MINGW_NOTHROW  void _sleep (unsigned long) __MINGW_ATTRIB_DEPRECATED;

/* _onexit is a Microsoft extension. Use atexit for portability. */
/* Note: This is in startup code, not imported directly from dll */
typedef  int (* _onexit_t)(void);
__cdecl __MINGW_NOTHROW  _onexit_t _onexit( _onexit_t );

_CRTIMP __cdecl __MINGW_NOTHROW  int _putenv (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW
void _searchenv (const char *, const char *, char *);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_ecvt (double, int, int *, int *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_fcvt (double, int, int *, int *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_gcvt (double, int, char *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _makepath (char *, const char *, const char *, const char *, const char *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _splitpath (const char *, char *, char *, char *, char *);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_fullpath (char*, const char*, size_t);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_itoa (int, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_ltoa (long, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_ultoa(unsigned long, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_itow (int, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_ltow (long, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_ultow (unsigned long, wchar_t *, int);

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  char* _i64toa (__int64, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char* _ui64toa (unsigned __int64, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _wtoi64 (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t* _i64tow (__int64, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t* _ui64tow (unsigned __int64, wchar_t *, int);

_CRTIMP __cdecl __MINGW_NOTHROW  unsigned int (_rotl)(unsigned int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned int (_rotr)(unsigned int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long (_lrotl)(unsigned long, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long (_lrotr)(unsigned long, int) __MINGW_ATTRIB_CONST;

_CRTIMP __cdecl __MINGW_NOTHROW  int _set_error_mode (int);

# define _OUT_TO_DEFAULT	0
# define _OUT_TO_STDERR 	1
# define _OUT_TO_MSGBOX 	2
# define _REPORT_ERRMODE	3

# if __MSVCRT_VERSION__ >= __MSVCR80_DLL
#  ifndef _UINTPTR_T_DEFINED
#   define _UINTPTR_T_DEFINED
#   ifdef _WIN64
      typedef unsigned __int64 uintptr_t;
#   else
      typedef unsigned int uintptr_t;
#   endif
#  endif

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned int _set_abort_behavior (unsigned int, unsigned int);

/* These masks work with msvcr80.dll version 8.0.50215.44 (a beta release).
 */
#  define _WRITE_ABORT_MSG	1
#  define _CALL_REPORTFAULT	2

typedef void
(* _invalid_parameter_handler) (
    const wchar_t *,
    const wchar_t *,
    const wchar_t *,
    unsigned int,
    uintptr_t);
_invalid_parameter_handler _set_invalid_parameter_handler (_invalid_parameter_handler);

# endif /* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* __MSVCRT__ */

#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  int putenv (const char*);
_CRTIMP __cdecl __MINGW_NOTHROW  void searchenv (const char*, const char*, char*);

_CRTIMP __cdecl __MINGW_NOTHROW  char* itoa (int, char*, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char* ltoa (long, char*, int);

#ifndef _UWIN
_CRTIMP __cdecl __MINGW_NOTHROW  char* ecvt (double, int, int*, int*);
_CRTIMP __cdecl __MINGW_NOTHROW  char* fcvt (double, int, int*, int*);
_CRTIMP __cdecl __MINGW_NOTHROW  char* gcvt (double, int, char*);

#endif	/* ! _UWIN */
#endif	/* ! _NO_OLDNAMES */
#endif	/* ! __STRICT_ANSI__ */

#ifdef _ISOC99_SOURCE
/* Further APIs required to support ISO-C99, but missing from MSVCRT.DLL;
 * we provide them in libmingwex.a:
 *
 * ISO-C99 name for _exit()
 */
__cdecl __MINGW_NOTHROW  void _Exit(int) __MINGW_ATTRIB_NORETURN;

#ifndef __NO_INLINE__
__CRT_INLINE __JMPSTUB__(( FUNCTION = _Exit, REMAPPED = _exit ))
__cdecl __MINGW_NOTHROW  void _Exit( int __status ){ _exit (__status); }
#endif

typedef struct { long long quot, rem; } lldiv_t;
__cdecl __MINGW_NOTHROW  lldiv_t lldiv (long long, long long) __MINGW_ATTRIB_CONST;

__cdecl __MINGW_NOTHROW  long long llabs (long long);

#ifndef __NO_INLINE__
__CRT_INLINE
/* No JMPSTUB or LIBIMPL reference here -- we provide a free-standing
 * implementation, along with imaxabs(), in mingwex/imaxabs.c
 */
__cdecl __MINGW_NOTHROW  long long llabs( long long __j )
{ return __j >= 0 ? __j : -__j; }
#endif

__cdecl __MINGW_NOTHROW
long long strtoll (const char *__restrict__, char **__restrict, int);

__cdecl __MINGW_NOTHROW
unsigned long long strtoull (const char *__restrict__, char **__restrict__, int);

#ifdef __MSVCRT__
/* MSVCRT.DLL does not provide ISO-C99's atoll() function, but it does
 * provide an analogue, in _atoi64(); map it accordingly.
 */
__cdecl __MINGW_NOTHROW  long long atoll (const char *);

#ifndef __NO_INLINE__
__CRT_INLINE __JMPSTUB__(( FUNCTION = atoll, REMAPPED = _atoi64 ))
__cdecl __MINGW_NOTHROW  long long atoll (const char * _c){ return _atoi64 (_c); }
#endif

#endif  /* __MSVCRT__ */
#endif  /* _ISOC99_SOURCE */

#if defined __MSVCRT__ && ! defined __STRICT_ANSI__
#if __MSVCRT_VERSION__ >= __MSVCR70_DLL || _WIN32_WINNT >= _WIN32_WINNT_WINXP
/* Microsoft specific alternatives to ISO-C99 strtoll() and strtoull(); the
 * first pair require WinXP (or later) or non-free MSVCR70.DLL onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _strtoi64(const char*, char **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _strtoui64(const char*, char **, int);

#endif	/* WinXP || MSVCR70.DLL || later */
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* ...while the following pair require Win-Vista (or later), or non-free
 * MSVCR80.DLL onwards; (note that, like their wide character counterparts,
 * they may actually be unusable without MSVCR80.DLL onwards, because of
 * the difficulty in acquiring a reference to a _locale_t object).
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _strtoi64_l(const char *, char **, int, _locale_t);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _strtoui64_l(const char *, char **, int, _locale_t);

#endif	/* Win-Vista || MSVCR80.DLL || later */

/* Type long long analogues for MSVCRT.DLL specific type long functions;
 * none are actually provided by any version of MSVCRT.DLL, with names as
 * specified here, but rather as called by the inline functions used to
 * implement them, (i.e. the REMAPPED name specified in each__JMPSTUB__
 * function reference respectively).
 *
 * FIXME: Not one of these is specified by ISO-C99, nor by POSIX, either;
 * is there really any justification for us to specify them at all?  For
 * the time being, declare as deprecated; perhaps remove later?
 */
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  long long wtoll (const wchar_t *);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  char *lltoa (long long, char *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  char *ulltoa (unsigned long long , char *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  wchar_t *lltow (long long, wchar_t *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  wchar_t *ulltow (unsigned long long, wchar_t *, int);

#ifndef __NO_INLINE__
/* None of these functions would exist at all, without either these inline
 * implementations, or their respective __JMPSTUB__ equivalents.
 */
__CRT_INLINE __JMPSTUB__(( FUNCTION = lltoa, REMAPPED = _i64toa ))
__cdecl __MINGW_NOTHROW  char *lltoa (long long __n, char * __c, int __i)
{ return _i64toa (__n, __c, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = ulltoa, REMAPPED = _ui64toa ))
__cdecl __MINGW_NOTHROW  char *ulltoa (unsigned long long __n, char * __c, int __i)
{ return _ui64toa (__n, __c, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = wtoll, REMAPPED = _wtoi64 ))
__cdecl __MINGW_NOTHROW  long long wtoll (const wchar_t * __w){ return _wtoi64 (__w); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = lltow, REMAPPED = _i64tow ))
__cdecl __MINGW_NOTHROW  wchar_t *lltow (long long __n, wchar_t * __w, int __i)
{ return _i64tow (__n, __w, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = ulltow, REMAPPED = _ui64tow ))
__cdecl __MINGW_NOTHROW  wchar_t *ulltow (unsigned long long __n, wchar_t * __w, int __i)
{ return _ui64tow (__n, __w, __i); }

#endif  /* ! __NO_INLINE__ */
#endif  /* __MSVCRT__ && ! __STRICT_ANSI__ */

/* POSIX/BSD extensions in libmingwex.a; these should be exposed only on
 * the basis of appropriate POSIX or BSD specific feature tests...
 *
 * mkstemp(3) function support; added per feature request #2003.
 * POSIX wants _XOPEN_SOURCE >= 500, (implying _POSIX_C_SOURCE >= 200112L).
 */
#if _POSIX_C_SOURCE >= 200112L

__cdecl __MINGW_NOTHROW  int mkstemp (char *);
__cdecl __MINGW_NOTHROW  int __mingw_mkstemp (int, char *);

/* On POSIX platforms, programmers may adopt an idiom such as:
 *
 *   if( mkstemp( template ) >= 0 )
 *   { unlink( template );
 *     . . .
 *   }
 *
 * to ensure that a temporary file does NOT persist after it is
 * closed; MS-Windows does not allow such use of unlink(2), while
 * the file remains open.  Thus, MS-Windows programmers must take
 * extra care, to close and unlink temporary files AFTER use, if
 * similar behaviour is desired.
 *
 * To mitigate this MS-Windows limitation, we provide support for
 * an alternative, MinGW specific idiom:
 *
 *   #include <fcntl.h>
 *
 *   _MKSTEMP_SETMODE( _O_TEMPORARY );
 *   if( mkstemp( template ) >= 0 )
 *   {
 *     . . .
 *   }
 *
 * to achieve a similar effect to that of the above POSIX idiom; the
 * following macros are a MinGW specific extension, to facilite such
 * use of _O_TEMPORARY, (in addition to the POSIX required attributes),
 * when creating the temporary file.  Note that they require <fcntl.h>,
 * which <stdlib.h> should NOT automatically include; we leave it to
 * the user to explicitly include it, if using _MKSTEMP_SETMODE.
 */
#define _MKSTEMP_INVOKE       0
#define _MKSTEMP_DEFAULT     _O_CREAT | _O_EXCL | _O_RDWR
#define _MKSTEMP_SETMODE(M) __mingw_mkstemp( _MKSTEMP_DEFAULT | (M), NULL )

#ifndef _NO_OLDNAMES
#define MKSTEMP_SETMODE(M)  __mingw_mkstemp( _MKSTEMP_DEFAULT | (M), NULL )
#endif

__CRT_ALIAS __LIBIMPL__(( FUNCTION = mkstemp ))
__cdecl __MINGW_NOTHROW  int mkstemp (char *__filename_template)
{ return __mingw_mkstemp( _MKSTEMP_INVOKE, __filename_template ); }

#endif	/* _POSIX_C_SOURCE >= 200112L (for mkstemp()) */

/* mkdtemp(3) function support: added as adjunct to feature request #2003.
 * POSIX wants _XOPEN_SOURCE >= 700, (implying _POSIX_C_SOURCE >= 200809L).
 */
#if _POSIX_C_SOURCE >= 200809L

__cdecl __MINGW_NOTHROW  char *mkdtemp (char *);
__cdecl __MINGW_NOTHROW  char *__mingw_mkdtemp (char *);

__CRT_ALIAS __JMPSTUB__(( FUNCTION = mkdtemp ))
__cdecl __MINGW_NOTHROW  char *mkdtemp (char *__dirname_template)
{ return __mingw_mkdtemp( __dirname_template ); }

#endif	/* _POSIX_C_SOURCE >= 200809L (for mkdtemp()) */

#if _POSIX_C_SOURCE >= 200112L
/* setenv() and unsetenv() are also available, from POSIX.1-2001 onwards.
 */
__cdecl __MINGW_NOTHROW  int setenv( const char *, const char *, int );
__cdecl __MINGW_NOTHROW  int unsetenv( const char * );

__cdecl __MINGW_NOTHROW  int __mingw_setenv( const char *, const char *, int );

__CRT_ALIAS __JMPSTUB__(( FUNCTION = setenv ))
__cdecl __MINGW_NOTHROW  int setenv( const char *__n, const char *__v, int __f )
{ return __mingw_setenv( __n, __v, __f ); }

__CRT_ALIAS __LIBIMPL__(( FUNCTION = unsetenv ))
__cdecl __MINGW_NOTHROW  int unsetenv( const char *__name )
{ return __mingw_setenv( __name, NULL, 1 ); }

#endif	/* _POSIX_C_SOURCE >= 200112L (for setenv()) */
#endif	/* _STDLIB_H */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* ! _STDLIB_H: $RCSfile: stdlib.h,v $: end of file */

int main(){
    int num1, num2, num3;
    num1 = 6;
    num2 = 7;
    num3 = 24;
    printf("Number1 add number2 and number3 is: %d", num1 + num2 + num3);

    system("pause");
    return 0;

}
/*
c_cpp_properties中的"includePath"就是設定這些header要去哪裡找(會影響編譯的，並不是單純只是補全問題)，
並且編譯，(或者也可以在cmake中加入相關指令，雖然可以編譯過，但是可能會導置補全出現問題)
stdio跟stdlib都在"C:\MinGW\include"中，可以用ctrl+左鍵去尋找

#include就是把這一大段落取代成#include<stdio.h>，所以可以將#都認識成取代的意思(#define也是)
*/
