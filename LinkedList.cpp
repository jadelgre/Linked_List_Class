#include "LinkedList.h"

list::list() {
	_size = 0;
	_head = NULL;
	_tail = NULL;
}

list::list(const list& other){
  _size = 0;
  int* tmp = new int;
  *tmp = other.size();
  _head = NULL;
	_tail = NULL;  
  for( int i = 0; i < *tmp ; i++ ){
    add( other.get( i ) );
  }
  delete tmp;  
}

list::~list() {
  for( int i = 0; i < size() ; i++ )
  {
    erase(i);
  }
	_head = NULL;
	_tail = NULL;
}

void list::operator=(const list& other){
  _size = other._size;

}

int list::size() const{
  return _size;
}

int list::get(int position) const{
    if (position == 0) {
      return _head->_data;
		} else if( position < _size ){
			node* before = _head;
			for (int i = 0; i < position; i++) {
				before = before->_next;
			}
			return before->_data;
      delete before;
    }
    return 0;
}
void list::add(int n) {
	node* ptr = new node(n);
	if (_head == NULL) {
		_head = ptr;
		_tail = ptr;
	} else {
		_tail->_next = ptr;
		_tail = ptr;
	}
	_size++;
}

void list::insert(int n, int position){
		  if (position == 0) {
			node* ptr = new node( n );
      if (_head == NULL) {
		    _head = ptr;
		    _tail = ptr;
      } else {
        node* oldHead = new node;
        oldHead->_data = _head->_data;
        oldHead->_next = _head->_next;
			  delete _head;
        ptr->_next = oldHead;
			  _head = ptr;
      }
			if (_head == NULL) _tail = NULL;
		} else if ( position < _size ) {
			node* before = _head;
			for (int i = 0; i < position - 1; i++) {
				before = before->_next;
			}
			node* ptr = new node( n );
			if (before->_next == _tail){
				_tail = ptr;
      }
      ptr->_next = before->_next; 
			before->_next = ptr;
		} else if ( position = _size ){ // insert at end of list
      node* before = _head;
			for (int i = 0; i < _size - 1; i++) {
				before = before->_next;
			}
			node* ptr = new node( n );
			if (before->_next == _tail){
				_tail = ptr;
      }
      ptr->_next = before->_next; 
			before->_next = ptr;
    }
  _size++;
  }

void list::erase(int position) {
	if (position < _size) {
		if (position == 0) {
			node* ptr = _head->_next;
			delete _head;
			_head = ptr;
			if (_head == NULL) _tail = NULL;
		} else {
			node* before = _head;
			for (int i = 0; i < position - 1; i++) {
				before = before->_next;
			}
			node* ptr = before->_next->_next;
			if (before->_next == _tail)
				_tail = before;
			delete before->_next;
			before->_next = ptr;
			
		}
	}
  _size--;
}