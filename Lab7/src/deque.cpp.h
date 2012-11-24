template <class Object>
Deque<Object>::Deque( ) {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque( ) {                         // the destructor
  clear( );
}

template <class Object>
bool Deque<Object>::isEmpty( ) const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size( ) const {                 // retrieves # deque nodes
  int i = 0;
  for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next ) // traverse que
    ++i;

  return i;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    // retrieve the tail node
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
  while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
    removeFront( );
}

template <class Object>
void Deque<Object>::addFront( const Object &obj ) {// add a new node to  front
  DequeNode *newPtr = new DequeNode;
  if (newPtr == NULL)
	  throw "out of memory";
  newPtr->item = obj;
  newPtr->next = front;
  newPtr->prev = NULL;
  if (isEmpty())
	  back = newPtr;
  else
	  front->prev = newPtr;
  front = newPtr;
}

template <class Object>
void Deque<Object>::addBack( const Object &obj ) { // add a new node to tail
	DequeNode *newPtr = new DequeNode;
	if (newPtr == NULL)
		throw "out of memory";
	newPtr->item = obj;
	newPtr->prev = back;
	newPtr->next = NULL;
	if (isEmpty())
		front = newPtr;
	else
		back->next = newPtr;
	back = newPtr;
}

template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
	if (isEmpty())
		return NULL;
	Object o = front->item;
	DequeNode *tmp = front;
	front = front->next;
	delete(tmp);
	if (front)
		front->prev = NULL;
	else
		back = NULL;
	return o;
}

template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node
	Object o = back->item;
	DequeNode *tmp = back;
	back = back->prev;
	delete(tmp);
	if (back)
		back->next = NULL;
	else
		front = NULL;
	return o;
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
  if ( this != &rhs ) { // avoid self assignment
    clear( );
    for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
      addBack( rptr->item );
  }
  return *this;
}


