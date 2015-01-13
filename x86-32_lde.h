#ifndef _X86_32_LDE_H
#define _X86_32_LDE_H

/** Length decoder for x86-32 instructions. Requires linking with
 *  libbeaengine.  See implementation file for details.
 */

/** Return length of x86-32 instruction pointed to by p.  Returns < 0
 *  on error.
 */
int get_op_length(void *p);

#endif //ifndef _X86_32_LDE_H