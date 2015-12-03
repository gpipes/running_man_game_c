#include "list.h"


int InitList( list *l ) {

  *l = NULL;

  return 1;
  
}

node *NewNode( void *data ) {

  node *ret_val = (node *)malloc(sizeof(node));

  if ( ret_val == NULL )
    return NULL;
  
  ret_val->data = data;

  ret_val->next = NULL;

  return ret_val;
  
}

int InsertNode( list *l, void *data ) {

  node *ins_node = NewNode( data );

  if ( ins_node == NULL )
    return 0;

  if ( *l == NULL ) {

    *l = ins_node;
    return 1;
    
  }

  ins_node->next = *l;
  *l = ins_node;
  return 1;

}

int AppendNode( list *l, void *data ) {

  node *curr_node = *l;
  node *app_node = NewNode( data );

  if ( app_node == NULL )
    return 0;

  if ( *l == NULL ) {

    *l = app_node;
    return 1;

  }

  while ( curr_node->next != NULL ) {

    curr_node = curr_node->next;

  }

  curr_node->next = app_node;
  return 1;

}

int DeleteNode( list *l, void *data ) {

  //curr_node is the address of a node
  node *curr_node = *l;
  node *prev_node = *l;

  //base case 0 nodes
  if ( *l == NULL )
    return 0;

  //base case 1 node
  if ( prev_node->next == NULL ) {

    if ( prev_node->data == data ) {

      free( prev_node->data );
      free( prev_node );
      *l = NULL;
      return 1;

    }

    return 0;
  }

  curr_node = prev_node->next;
  //base case 2 nodes
  if ( curr_node->next == NULL ) {

    if ( curr_node->data == data ) {

      free( curr_node->data );
      free( curr_node );
      prev_node->next = NULL;
      return 1;

    }

    return 0;

  }

  while ( curr_node != NULL ) {

    if ( curr_node->data == data ) {

      free( curr_node->data );
      prev_node->next = curr_node->next;
      free( curr_node );
      return 1;

    }

    prev_node = curr_node;
    curr_node = curr_node->next;

  }

  return 0;

}
