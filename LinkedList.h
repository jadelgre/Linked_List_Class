#include "node.h"

class list {
public:
	list();
	list(const list&);
	~list();

	void operator=(const list&);
	
	int size() const;
	int get (int position) const;
	void add(int);
	void insert(int n, int position);
	void erase(int position);
	
private:
	node* _head;	
	node* _tail;	
	int _size;	
};	