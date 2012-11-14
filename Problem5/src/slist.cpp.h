template<class Object>
SList<Object>::SList( ) {
	init( );
}

template<class Object>
SList<Object>::SList( const SList &rhs ) {
	init( );
	*this = rhs;                                   // then assign rhs to this.
}

template<class Object> 
void SList<Object>::init( ) {
	for ( int i = 0; i < LEVEL; i++ ) {  // for each level
		// create the left most dummy nodes;
		header[i] = new SListNode<Object>;
		header[i]->prev = NULL;
		header[i]->down = ( i > 0 ) ? header[i - 1] : NULL;
		header[i]->up = NULL;
		if ( i > 0 ) header[i - 1]->up = header[i];

		// create the right most dummy nodes;
		header[i]->next = new SListNode<Object>;
		header[i]->next->next = NULL;
		header[i]->next->prev = header[i];
		header[i]->next->down = ( i > 0 ) ? header[i - 1]->next : NULL;
		header[i]->next->up = NULL;
		if ( i > 0 ) header[i - 1]->next->up = header[i]->next;
	}

	// reset cost.
	cost = 0;
}

template<class Object>
SList<Object>::~SList( ) {
	clear( );                                      // delete items starting 1st
	for ( int i = 0; i < LEVEL; i++ ) {
		delete header[i]->next;                      // delete the right most dummy
		delete header[i];                            // delete the left most dummy
	}
}

template<class Object>
bool SList<Object>::isEmpty( ) const {
	return ( header[0]->next->next == NULL );
}

template<class Object>
int SList<Object>::size( ) const {
	SListNode<Object> *p = header[0]->next; // at least the right most dummy
	int size = 0;

	for ( ; p->next != NULL; p = p->next, ++size );
	return size;
}

template<class Object>
void SList<Object>::clear( ) {
	for ( int i = 0; i < LEVEL; i++ ) {        // for each level
		SListNode<Object> *p = header[i]->next;  // get the 1st item
		while ( p->next != NULL ) {              // if this is not the left most
			SListNode<Object> *del = p;
			p = p->next;                           // get the next item
			delete del;                            // delete the current item
		}

		header[i]->next = p;                     // p now points to the left most
	}                                          // let the right most point to it
}

template<class Object>  // Implement the rest by yourself /////////////////////////////////////////
void SList<Object>::insert( const Object &obj ) {
	// right points to the level-0 item before which a new object is inserted.
	SListNode<Object> *right = searchPointer( obj );
	SListNode<Object> *up = NULL;
	int level = 0;

	if ( right->next != NULL && right->item == obj )
		// there is an identical object
		return;

	//Insert new node at level-0
	SListNode<Object> * newNode = new SListNode<Object>;
	newNode->item = obj;

	newNode->next = right;
	newNode->prev = right->prev;
	newNode->prev->next = newNode;
	right->prev = newNode;
	while(rand()%2 && level < LEVEL) { //50% chance of adding new node one level up
		up = right;
		while(up->up == NULL) {
			up = up->prev;
		}
		up = up->up;
		if(up->next != NULL)
			up = up->next;
		newNode = new SListNode<Object>;
		newNode->item = obj;

		newNode->next = up;
		newNode->prev = up->prev;
		newNode->prev->next = newNode;
		up->prev = newNode;
		up->prev->down = right->prev; //connect vertically
		up->prev->down->up = up->prev;
		right = up;
		level++;
	}

}

template<class Object> 
bool SList<Object>::find( const Object &obj ) {
	// p oints to the level-0 item close to a given object
	SListNode<Object> *p = searchPointer( obj );

	return ( p->next != NULL && p->item == obj );     // true if obj was found
}

template<class Object>
SListNode<Object> *SList<Object>::searchPointer( const Object &obj ) {
	SListNode<Object> *p = header[LEVEL - 1];     // start from the top left
	while ( p->down != NULL ) {                   // toward level 0
		p = p->down;                                // shift down once
		cost++;

		if ( p->prev == NULL ) {                    // at the left most item
			if ( p->next->next == NULL )              // no intermediate items
				continue;
			else {                                    // some intermadiate items
				if ( p->next->item <= obj )             // if 1st item <= obj
					p = p->next;                          // shift right to item 1
				cost++;
			}
		}

		while ( p->next->next != NULL && p->next->item <= obj ) {
			// shift right through intermediate items as far as the item value <= obj
			p = p->next;
			cost++;
		}
	}

	// now reached the bottom. shift right once if the current item < obj
	if ( p->prev == NULL || p->item < obj ) {
		p = p->next;
		cost++;
	}
	return p; // return the pointer to an item >= a given object.
}

template<class Object>
void SList<Object>::remove( const Object &obj ) {
	// p points to the level-0 item to delete
	SListNode<Object> *p = searchPointer( obj );

	// validate if p is not the left most or right most and exactly contains the
	// item to delete
	if ( p->prev == NULL || p->next == NULL || p->item != obj )
		return;

	// Implement the rest by yourself /////////////////////////////////////////
}

template<class Object>
const SList<Object> &SList<Object>::operator=( const SList &rhs ) {
	if ( this != &rhs ) { // avoid self-assignment
		clear( );           // deallocate old items

		int index;
		SListNode<Object> *rnode;
		for ( index = 0, rnode = rhs.header[0]->next; rnode->next != NULL;
				rnode = rnode->next, ++index )
			insert( rnode->item );

		cost = rhs.cost;
	}
	return *this;
}

template<class Object>
int SList<Object>::getCost( ) const {
	return cost;
}

template<class Object>
void SList<Object>::show( ) const {
	cout << "contents:" << endl;
	for ( SListNode<Object> *col = header[0]; col != NULL; col = col->next ) {
		SListNode<Object> *row = col;
		for ( int level = 0; row != NULL && level < LEVEL; level++ ) {
			if ( row->prev == NULL )
				cout << "-inf\t";
			else if ( row->next == NULL )
				cout << "+inf\t";
			else
				cout << row->item << "\t";
			row = row->up;
		}
		cout << endl;
	}
}

