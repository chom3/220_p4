#ifndef _FN_TRACE_H
#define _FN_TRACE_H

/** Information associated with a function. */
typedef struct {
  void *address;        /** start address of function */
  unsigned length;      /** # of bytes taken by function code. */
  unsigned nInCalls;    /** # of direct calls to this function */
  unsigned nOutCalls;   /** # of direct function calls in function body */
} FnInfo;

/** FnInfos is an opaque struct FnsData which can be implemented as
 *  desired by an implementation. This struct will hold a collection
 *  of FnInfo's.
 */
struct {
  FnInfo data;
} FnsData;
typedef struct FnsData FnInfos;

/** Return all function info's callable directly or indirectly from function
 *  whose address is rootFn.
 */
FnInfos *new_fn_infos(void *rootFn);

/** Free all resources occupied by fnInfos. fnInfos must have been
 *  returned by new_fn_infos().  It is not ok to use to fnInfos after
 *  this call.
 */
void free_fn_infos(FnInfos *fnInfos);

/** Iterate over all FnInfo's in fnInfos.  Make initial call with NULL
 *  lastFnInfo.  Keep calling with return value as lastFnInfo, until
 *  next_fn_info() returns NULL.  Values must be returned sorted in
 *  increasing order by fnInfoP->address.
 *
 *  Sample iteration:
 *
 *  for (FnInfo *fnInfoP = next_fn_info(fnInfos, NULL); fnInfoP != NULL;
 *       fnInfoP = next_fn_info(fnInfos, fnInfoP)) {
 *    //body of iteration
 *  }
 *
 */
FnInfo *next_fn_info(const FnInfos *fnInfos, const FnInfo *lastFnInfo);

#endif //#ifndef _FN_TRACE_H