/* Copyright (C) 1999-2024 Free Software Foundation, Inc.
   This file is part of the GNU LIBICONV Library.
   For MSVC build of libiconv 1.18 */

#ifndef _LIBICONV_H
#define _LIBICONV_H

#ifdef __cplusplus
extern "C" {
#endif

#define _LIBICONV_VERSION 0x0112    /* version number: (major<<8) + minor */

#if defined(LIBICONV_DLL) && (defined(_WIN32) || defined(__CYGWIN__))
# if defined(BUILDING_LIBICONV)
#  define LIBICONV_DLL_EXPORTED __declspec(dllexport)
# else
#  define LIBICONV_DLL_EXPORTED __declspec(dllimport)
# endif
#else
# define LIBICONV_DLL_EXPORTED
#endif

extern LIBICONV_DLL_EXPORTED int _libiconv_version;

#ifdef __cplusplus
}
#endif

/* Define iconv_t ourselves. */
#undef iconv_t
#define iconv_t libiconv_t
typedef void* iconv_t;

/* Get size_t declaration. */
#include <stddef.h>

/* Get errno declaration and values. */
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Allocates descriptor for code conversion from encoding 'fromcode' to
   encoding 'tocode'. */
#define iconv_open libiconv_open
extern LIBICONV_DLL_EXPORTED iconv_t iconv_open (const char* tocode, const char* fromcode);

/* Converts, using conversion descriptor 'cd', at most '*inbytesleft' bytes
   starting at '*inbuf', writing at most '*outbytesleft' bytes starting at
   '*outbuf'. */
#define iconv libiconv
extern LIBICONV_DLL_EXPORTED size_t iconv (iconv_t cd, const char* * inbuf, size_t *inbytesleft, char* * outbuf, size_t *outbytesleft);

/* Frees resources allocated for conversion descriptor 'cd'. */
#define iconv_close libiconv_close
extern LIBICONV_DLL_EXPORTED int iconv_close (iconv_t cd);

#ifdef __cplusplus
}
#endif

/* Nonstandard extensions. */

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

/* A type that holds all memory needed by a conversion descriptor.
   A pointer to such an object can be used as iconv_t. */
typedef struct {
  void* dummy1[28];
  mbstate_t dummy2;
} iconv_allocation_t;

/* Allocates descriptor for code conversion from encoding 'fromcode' to
   encoding 'tocode' into preallocated memory. */
#define iconv_open_into libiconv_open_into
extern LIBICONV_DLL_EXPORTED int iconv_open_into (const char* tocode, const char* fromcode,
                            iconv_allocation_t* resultp);

/* Control of attributes. */
#define iconvctl libiconvctl
extern LIBICONV_DLL_EXPORTED int iconvctl (iconv_t cd, int request, void* argument);

/* Hook performed after every successful conversion of a Unicode character. */
typedef void (*iconv_unicode_char_hook) (unsigned int uc, void* data);
/* Hook performed after every successful conversion of a wide character. */
typedef void (*iconv_wide_char_hook) (wchar_t wc, void* data);
/* Set of hooks. */
struct iconv_hooks {
  iconv_unicode_char_hook uc_hook;
  iconv_wide_char_hook wc_hook;
  void* data;
};

/* Fallback function.  Invoked when a small number of bytes could not be
   converted to a Unicode character. */
typedef void (*iconv_unicode_mb_to_uc_fallback)
             (const char* inbuf, size_t inbufsize,
              void (*write_replacement) (const unsigned int *buf, size_t buflen,
                                         void* callback_arg),
              void* callback_arg,
              void* data);
/* Fallback function.  Invoked when a Unicode character could not be converted
   to the target encoding. */
typedef void (*iconv_unicode_uc_to_mb_fallback)
             (unsigned int code,
              void (*write_replacement) (const char *buf, size_t buflen,
                                         void* callback_arg),
              void* callback_arg,
              void* data);
/* Fallback function.  Invoked when a number of bytes could not be converted to
   a wide character. */
typedef void (*iconv_wchar_mb_to_wc_fallback)
             (const char* inbuf, size_t inbufsize,
              void (*write_replacement) (const wchar_t *buf, size_t buflen,
                                         void* callback_arg),
              void* callback_arg,
              void* data);
/* Fallback function.  Invoked when a wide character could not be converted to
   the target encoding. */
typedef void (*iconv_wchar_wc_to_mb_fallback)
             (wchar_t code,
              void (*write_replacement) (const char *buf, size_t buflen,
                                         void* callback_arg),
              void* callback_arg,
              void* data);

/* Set of fallbacks. */
struct iconv_fallbacks {
  iconv_unicode_mb_to_uc_fallback mb_to_uc_fallback;
  iconv_unicode_uc_to_mb_fallback uc_to_mb_fallback;
  iconv_wchar_mb_to_wc_fallback mb_to_wc_fallback;
  iconv_wchar_wc_to_mb_fallback wc_to_mb_fallback;
  void* data;
};

/* Surfaces.
   The concept of surfaces is described in the 'recode' manual. */
#define ICONV_SURFACE_NONE             0
/* In EBCDIC encodings, 0x15 (which encodes the "newline function", see the
   Unicode standard, chapter 5) maps to U+000A instead of U+0085.  This is
   for interoperability with C programs and Unix environments on z/OS. */
#define ICONV_SURFACE_EBCDIC_ZOS_UNIX  1

/* Requests for iconvctl. */
#define ICONV_TRIVIALP                    0  /* int *argument */
#define ICONV_GET_TRANSLITERATE           1  /* int *argument */
#define ICONV_SET_TRANSLITERATE           2  /* const int *argument */
#define ICONV_GET_DISCARD_ILSEQ           3  /* int *argument */
#define ICONV_SET_DISCARD_ILSEQ           4  /* const int *argument */
#define ICONV_SET_HOOKS                   5  /* const struct iconv_hooks *argument */
#define ICONV_SET_FALLBACKS               6  /* const struct iconv_fallbacks *argument */
#define ICONV_GET_FROM_SURFACE            7  /* unsigned int *argument */
#define ICONV_SET_FROM_SURFACE            8  /* const unsigned int *argument */
#define ICONV_GET_TO_SURFACE              9  /* unsigned int *argument */
#define ICONV_SET_TO_SURFACE             10  /* const unsigned int *argument */
#define ICONV_GET_DISCARD_INVALID        11  /* int *argument */
#define ICONV_SET_DISCARD_INVALID        12  /* const int *argument */
#define ICONV_GET_DISCARD_NON_IDENTICAL  13  /* int *argument */
#define ICONV_SET_DISCARD_NON_IDENTICAL  14  /* const int *argument */

/* Listing of locale independent encodings. */
#define iconvlist libiconvlist
extern LIBICONV_DLL_EXPORTED void iconvlist (int (*do_one) (unsigned int namescount,
                                      const char * const * names,
                                      void* data),
                       void* data);

/* Canonicalize an encoding name. */
#define iconv_canonicalize libiconv_canonicalize
extern LIBICONV_DLL_EXPORTED const char * iconv_canonicalize (const char * name);

/* Support for relocatable packages. */

/* Sets the original and the current installation prefix of the package. */
extern LIBICONV_DLL_EXPORTED void libiconv_set_relocation_prefix (const char *orig_prefix,
                                            const char *curr_prefix);

#ifdef __cplusplus
}
#endif

#endif /* _LIBICONV_H */
