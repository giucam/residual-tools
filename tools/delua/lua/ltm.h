/*
** $Id: ltm.h 905 2008-07-20 21:08:22Z aquadran $
** Tag methods
** See Copyright Notice in lua.h
*/

#ifndef ltm_h
#define ltm_h


#include "lobject.h"
#include "lstate.h"

/*
* WARNING: if you change the order of this enumeration,
* grep "ORDER IM"
*/
typedef enum {
  IM_GETTABLE = 0,
  IM_SETTABLE,
  IM_INDEX,
  IM_GETGLOBAL,
  IM_SETGLOBAL,
  IM_ADD,
  IM_SUB,
  IM_MUL,
  IM_DIV,
  IM_POW,
  IM_UNM,
  IM_LT,
  IM_LE,
  IM_GT,
  IM_GE,
  IM_CONCAT,
  IM_GC,
  IM_FUNCTION
} eIMS;
typedef int32 IMS;

#define IM_N 18


struct IM {
  TObject int_method[IM_N];
};


#define luaT_getim(tag,event) (&L->IMtable[-(tag)].int_method[event])
#define luaT_getimbyObj(o,e)  (luaT_getim(luaT_efectivetag(o),(e)))

extern const char *luaT_eventname[];


void luaT_init (void);
void luaT_realtag (int32 tag);
int32 luaT_efectivetag (TObject *o);
void luaT_settagmethod (int32 t, const char *event, TObject *func);
TObject *luaT_gettagmethod (int32 t, const char *event);
const char *luaT_travtagmethods (int32 (*fn)(TObject *));

void luaT_setfallback (void);  /* only if LUA_COMPAT2_5 */

#endif
