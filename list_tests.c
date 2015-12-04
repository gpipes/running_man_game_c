#include <assert.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char **argv ) {

  list l;
  int *data1, *data2, *data3, *data4;

  data1 = ( int * )malloc( sizeof( int ) );
  *data1 = 3;
  data2 = ( int * )malloc( sizeof( int ) );
  *data2 = 10;
  data3 = ( int * )malloc( sizeof( int ) );
  *data3 = 20;

  //data for later
  //data4 = ( int * )malloc( sizeof( int ) );
  //*data4 = 40;
  
  //initializes test list to null
  InitList( &l );

  assert( l == NULL );

  InsertNode( &l, (void *)data2 );
  // l->data2->NULL
  
  assert( l->data == data2 );
  assert( *( (int *) (l->data) ) == 10 );
  assert( l->next == NULL );
  
  InsertNode( &l, (void *)data1 );
  // l->data1->data2->NULL
  
  assert( l->data == data1 );
  assert( *( (int *) (l->data) ) == 3 );
  assert( l->next->data == data2 );
  assert( *( (int *) (l->next->data) ) == 10 );
  assert( l->next->next == NULL );

  AppendNode( &l, data3 );
  // l->data1->data2->data3->NULL
  
  assert( *( (int *) (l->next->next->data) ) == 20 );
  assert( l->next->next->next == NULL );

  DeleteNode( &l, data2 );
  // l->data1->data3->NULL

  assert( l->next->data == data3 );
  assert( *( (int *) (l->data) ) == 3 );
  assert( l->next->next == NULL );
  assert( *data2 != 10 );

  free( l->next );
  free( l );
  free( data1 );
  free( data3 );
  

  return 0;

}
  
