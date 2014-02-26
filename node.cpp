#include <cstdlib>

class node {
friend class list;

public:
	node(int data = 0, node* next = NULL) 
		{ _data = data; _next = next; }
 
private:
	int   _data;
	node* _next;
};