#ifndef MTFLIST_H
#define MTFLIST_H
#include <iostream>
#include "dlist.h"

using namespace std;

template<class Object>
class MtfList : public DList<Object> {
 public:
  int find( const Object &obj );
};

#include "mtflist.cpp.h"
#endif
