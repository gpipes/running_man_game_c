#ifndef ___LIST_DATA_TYPE
#define ___LIST_DATA_TYPE

#include <stdlib.h>

typedef struct NODE {

  void *data;
  struct NODE* next;

} node;

typedef node *list;

//all functions that take list *l should be passed with &list in
//any situation they are used

//initializes list to null returns a success
int InitList( list *l );

// returns the location of a new node with data
// return null on failure
node *NewNode( void *data );

//inserts a node with data and returns a success
int InsertNode( list *l, void *data );

//appends the node with data and returns a success
int AppendNode( list *l, void *data );

//deletes node in list with data and returns a success if it is found
int DeleteNode( list *l, void *data );

#endif
