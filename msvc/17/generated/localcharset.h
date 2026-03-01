/* localcharset.h - For MSVC build of libiconv 1.18 */
#ifndef _LOCALCHARSET_H
#define _LOCALCHARSET_H

#ifdef __cplusplus
extern "C" {
#endif

/* Determine the current locale's character encoding, and canonicalize it
   into one of the canonical names listed in the manual. */
extern const char * locale_charset (void);

#ifdef __cplusplus
}
#endif

#endif /* _LOCALCHARSET_H */
