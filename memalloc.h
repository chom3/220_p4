#ifndef _MEMALLOC_H
#define _MEMALLOC_H

#include <stdlib.h>

/** Ignore prototypes below, client code should only use macros defined
 *  below which automatically pull in client filename and line-number
 *  for error reporting.
 */

void *mallocChk(size_t size, const char *fileName, int lineNumber);

void *reallocChk(void *ptr, size_t size, const char *fileName, int lineNumber);

void *callocChk(size_t nmemb, size_t size, 
		const char *fileName, int lineNumber);

//imperative that these macros be defined *AFTER* prototypes above.
//These macros should be what is used by clients.

/** Return pointer to size bytes of memory on heap (similar to
 *  malloc()).  Terminate program with an error message if failure.
 */ 
#define mallocChk(size) mallocChk(size, __FILE__, __LINE__)


/** Return pointer to size bytes of memory on heap previously pointed
 *  to by ptr (similar to realloc()).  Terminate program with an error
 *  message if failure.
 */ 
#define reallocChk(ptr, size) reallocChk(ptr, size, __FILE__, __LINE__)

/** Return pointer to nmemb*size bytes of zero'd out memory on heap
 *  (similar to calloc()).  Terminate program with an error message if
 *  failure.
 */
#define callocChk(nmemb, size) callocChk(nmemb, size, __FILE__, __LINE__)

#endif /* #ifndef _MEMALLOC_H */
