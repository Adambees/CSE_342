template<class Object>
DList<Object>::DList( ) {
  header = new DListNode<Object>;                 // 0th node is a dummy.
  header->next = NULL;
  header->prev = NULL;
  cost = 0;
}

template<class Object>
DList<Object>::DList( const DList &rhs ) {
  header = new DListNode<Object>;                 // create a dummy
  header->next = NULL;                            
  header->prev = NULL;                            
  cost = 0;
  *this = rhs;                                    // then assign rhs to this.
}

template<class Object>
DList<Object>::~DList( ) {
  clear( );                                       // delete items starting 1st
  delete header;                                  // delete a dummy (at 0th).
}

template<class Object>
bool DList<Object>::isEmpty( ) const {
  return header->next == NULL;
}

template<class Object>
int DList<Object>::size( ) const {
  DListNode<Object> *p = header->next;
  int size = 0;

  for ( ; p != NULL; p = p->next, ++size );       // postfix ++ doesn't count
  return size;                                    // dummy
}

template<class Object>
void DList<Object>::clear( ) {
  while ( !isEmpty( ) ) {
    DListNode<Object> *node = findByIndex( 1 );    // find the 1st object
    remove( node->item );                          // remove it
  }
}

template<class Object>
void DList<Object>::insert( const Object &obj, const int index ) {
  DListNode<Object> *current = findByIndex( index );  // find an indexed object

  DListNode<Object> *newPtr = new DListNode<Object>;  // allocate space
  newPtr->item = obj;                                 // fix pointers
  newPtr->next = current->next;
  if ( newPtr->next != NULL )
    newPtr->next->prev = newPtr;
  newPtr->prev = current;
  current->next = newPtr;
}

template<class Object>
int DList<Object>::find( const Object &obj ) {
  DListNode<Object> *p = header->next;

  int i = 0;
  for ( ; p != NULL && p->item != obj; p = p->next, ++i )
    ++cost;

  return ( p == NULL ) ? -1 : i;  // -1 if not found
}

template<class Object>
void DList<Object>::remove( const Object &obj ) {
  DListNode<Object> *del = header->next;

  for ( ; del != NULL && del->item != obj; del = del->next );

  if ( del == NULL )
    return;
 
  if ( del->prev != NULL )   // fix poinsters
    del->prev->next = del->next;
  if ( del->next != NULL )
    del->next->prev = del->prev;
  delete del;            // deallocate

}

template<class Object>
const DList<Object> &DList<Object>::operator=( const DList &rhs ) {
  if ( this != &rhs ) { // avoid self-assignment
    clear( );           // deallocate old items
    
    int index;
    DListNode<Object> *rnode;
    for ( index = 0, rnode = rhs.header->next; rnode != NULL;
	  rnode = rnode->next, ++index )
      insert( rnode->item, index );

    cost = rhs.cost;
  }
  return *this;
}

template<class Object>
Object DList<Object>::retrieve( const int index ) const {
  DListNode<Object> *obj = findByIndex( index + 1 ); // index 0 == dummy
  return ( obj != NULL ) ? obj->item : NULL;
}

template<class Object>
int DList<Object>::getCost( ) const {
  return cost;
}

template<class Object>
DListNode<Object> *DList<Object>::findByIndex( const int index ) const {
  if ( index < 0 ) // verify index
    return NULL;

  DListNode<Object> *p = header;
  for ( int i = 0; p != NULL; p = p->next, i++ )
    if ( i == index )
      break;
  return p;
}
