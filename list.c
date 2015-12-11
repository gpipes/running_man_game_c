#include "list.h"


int init_list( list *l ) {

  *l = NULL;

  return 1;

}

node *new_node( void *data ) {

  node *ret_val = (node *)malloc(sizeof(node));

  if ( ret_val == NULL )
    return NULL;

  ret_val->data = data;

  ret_val->next = NULL;

  return ret_val;

}

int insert_node( list *l, void *data ) {

  node *ins_node = new_node( data );

  if ( ins_node == NULL )
    return 0;

  if ( l == NULL ) {

    *l = ins_node;
    return 1;

  }

  ins_node->next = *l;
  *l = ins_node;
  return 1;

}

int append_node( list *l, void *data ) {

  node *curr_node = *l;
  node *app_node = new_node( data );

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

void *delete_first_node( list *l ) {

  node *first_node;
  void *p_data;
  //if it is an empty list return null
  if ( *l == NULL )
    return NULL;

  first_node = *l;

  *l = first_node->next;

  p_data = first_node->data;

  free(first_node);

  return p_data;

}
