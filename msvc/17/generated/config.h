/* config.h - Generated for MSVC build of libiconv 1.18 */
#ifndef LIBICONV_CONFIG_H
#define LIBICONV_CONFIG_H

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <langinfo.h> header file. */
/* #undef HAVE_LANGINFO_H */

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <io.h> header file. */
#define HAVE_IO_H 1

/* Define to 1 if you have the getc_unlocked() function. */
/* #undef HAVE_GETC_UNLOCKED */

/* Define if you have the mbrtowc() function. */
#define HAVE_MBRTOWC 1

/* Define if you have the wcrtomb() function. */
#define HAVE_WCRTOMB 1

/* Define to 1 if you have the mbsinit() function. */
/* #undef HAVE_MBSINIT */

/* Define to 1 if you have the setlocale() function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the memmove() function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if the machine's byte ordering is little endian. */
#define WORDS_LITTLEENDIAN 1

/* Define to 1 to enable a few rarely used encodings. */
/* #undef ENABLE_EXTRA */

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* For Windows DLL */
#if defined(_MSC_VER) && defined(DLL_EXPORT)
# define DLL_VARIABLE __declspec(dllimport)
#else
# define DLL_VARIABLE
#endif

/* Define to 'int' if <sys/types.h> doesn't define. */
/* #undef mode_t */

/* Define as a signed type of the same size as size_t. */
#if defined(_WIN32) && !defined(ssize_t)
# ifdef _WIN64
typedef long long ssize_t;
# else
typedef int ssize_t;
# endif
#endif

#endif /* LIBICONV_CONFIG_H */
