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
int init_list( list *l );

// returns the location of a new node with data
// return null on failure
node *new_node( void *data );

//inserts a node with data and returns a success
int insert_node( list *l, void *data );

//appends the node with data and returns a success
int append_node( list *l, void *data );

//returns the data of the first_node
void *delete_first_node( list *l );

#endif
