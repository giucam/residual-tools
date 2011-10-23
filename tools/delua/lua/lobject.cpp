/*
** $Id: lobject.cpp 906 2008-07-20 21:18:18Z aquadran $
** Some generic functions over Lua objects
** See Copyright Notice in lua.h
*/

#include "lobject.h"
#include "lua.h"


const char *luaO_typenames[] = { /* ORDER LUA_T */
    "userdata", "number", "string", "table", "function", "function", "task",
    "nil", "function", "mark", "mark", "mark", "line", NULL
};


TObject luaO_nilobject = {LUA_T_NIL, {NULL}};



/* hash dimensions values */
static int32 dimensions[] =
 {5, 11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421,
  12853, 25717, 51437, 102811, 205619, 411233, 822433,
  1644817, 3289613, 6579211, 13158023, MAX_INT};


int32 luaO_redimension (int32 oldsize)
{
  int32 i;
  for (i=0; dimensions[i]<MAX_INT; i++) {
    if (dimensions[i] > oldsize)
      return dimensions[i];
  }
  lua_error("table overflow");
  return 0;  /* to avoid warnings */
}


int32 luaO_equalObj (TObject *t1, TObject *t2)
{
  if (ttype(t1) != ttype(t2)) return 0;
  switch (ttype(t1)) {
    case LUA_T_NIL: return 1;
    case LUA_T_NUMBER: return nvalue(t1) == nvalue(t2);
    case LUA_T_STRING: case LUA_T_USERDATA: return svalue(t1) == svalue(t2);
    case LUA_T_ARRAY: return avalue(t1) == avalue(t2);
    case LUA_T_PROTO: return tfvalue(t1)  == tfvalue(t2);
    case LUA_T_CPROTO: return fvalue(t1)  == fvalue(t2);
    case LUA_T_CLOSURE: return t1->value.cl == t2->value.cl;
    case LUA_T_TASK: return nvalue(t1) == nvalue(t2);
    default:
     LUA_INTERNALERROR("invalid type");
     return 0; /* UNREACHABLE */
  }
}


void luaO_insertlist (GCnode *root, GCnode *node)
{
  node->next = root->next;
  root->next = node;
  node->marked = 0;
}
