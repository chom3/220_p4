#include <stddef.h>

#include "fn-trace.h"
#include "x86-32_lde.h"

/** Return all function info's callable directly or indirectly from function
 *  whose address is rootFn.
 */
FnInfos *
new_fn_infos(void *rootFn)
{
  if (FnsData.data.address == rootFn)
    {
      return FnInfo.data;
    }
  return;
}

/** Free all resources occupied by fnInfos. fnInfos must have been
 *  returned by new_fn_infos().  It is not ok to use to fnInfos after
 *  this call.
 */
void
free_fn_infos(FnInfos *fnInfos)
{
}

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
FnInfo *
next_fn_info(const FnInfos *fnInfos, const FnInfo *lastFnInfo)
{
  return NULL;
}