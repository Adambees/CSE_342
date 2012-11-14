#ifndef TRANSPOSELIST_H
#define TRANSPOSELIST_H
#include <iostream>
#include "dlist.h"

using namespace std;

template<class Object>
class TransposeList : public DList<Object> {
 public:
  int find( const Object &obj );
};

#include "transposelist.cpp.h"
#endif
