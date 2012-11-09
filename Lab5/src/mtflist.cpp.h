#include "mtflist.h"

using namespace std;

template<class Object>
int MtfList<Object>::find( const Object &obj ) {
	DListNode<Object> *top = DList<Object>::header;
	DListNode<Object> *current = DList<Object>::header->next;
	for( ; current != NULL && current->item != obj; current = current->next ) {
		++DList<Object>::cost;
	}

	if (current == NULL) {
		return -1; //Item not found
	} else if (current->item == obj && current != top) { //item exists and not on top
		current->prev->next = current->next;
		if(current->next != NULL) {
			current->next->prev = current->prev;
		}
		//item is remvoved, so put on top
		current->next = top->next;
		current->prev = top;
		top->next->prev = current;
		top->next = current;
		return 0;
	} else { // item is on top
		return 1;
	}
}

