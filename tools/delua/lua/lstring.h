/*
** $Id: lstring.h 905 2008-07-20 21:08:22Z aquadran $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
*/

#ifndef lstring_h
#define lstring_h


#include "lobject.h"


void luaS_init (void);
TaggedString *luaS_createudata (void *udata, int32 tag);
TaggedString *luaS_collector (void);
void luaS_free (TaggedString *l);
TaggedString *luaS_newlstr (const char *str, int32 l);
TaggedString *luaS_new (const char *str);
TaggedString *luaS_newfixedstring (const char *str);
void luaS_rawsetglobal (TaggedString *ts, TObject *newval);
char *luaS_travsymbol (int32 (*fn)(TObject *));
int32 luaS_globaldefined (const char *name);
TaggedString *luaS_collectudata (void);
void luaS_freeall (void);

extern TaggedString EMPTY;
#define NUM_HASHS  61

#endif
