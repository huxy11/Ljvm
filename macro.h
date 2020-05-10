#ifndef __MACRO_H__
#define __MACRO_H__

#define _concat(a, b) a ## b
#define concat(a, b) _concat(a, b)
#define concat3(a, b, c) concat(concat(a, b), c)
#define concat4(a, b, c, d) concat3(concat(a, b), c, d)

#endif
