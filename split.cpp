

#include "split.h"


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
if(in == nullptr){
  odds = nullptr;
  evens = nullptr;
  return;
}

if(in->value % 2 != 0){
  odds = in;
  in = in->next;
  split(in, odds->next, evens);
}
else{
  evens = in;
  in = in->next;
  split(in, odds,evens->next);
}
}

/* If you needed a helper function, write it here */
