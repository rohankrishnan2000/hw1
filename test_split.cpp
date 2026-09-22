/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printlist(Node* head){
  while(head!= nullptr){
    cout<< head-> value <<" ";
    head = head->next;

  }
  cout << endl;
}
int main(int argc, char* argv[])
{
 Node* a = new Node{1, nullptr};
 a->next = new Node{2, nullptr};
 a->next->next = new Node{3, nullptr};
 a->next->next->next = new Node{4, nullptr};

 Node* odds = nullptr;
 Node* evens =nullptr;

 split(a, odds, evens);

 cout <<"Odds:";
 printlist(odds);

 cout << "Evens:";
 printlist(events);

 Node* b = new Node{2, nullptr};
b->next = new Node(4,nullptr);
b->next->next = new Node(6,nullptr);

odds = nullptr;
evens = nullptr

split(b, odds, evens);

cout <<"Odds: ";
printlist(odds);

cout << "Evens: ";

printlist(evens);

Node* c = new Node{7, nullptr}

odds = nullptr
evens = nullptr
split(c, odds, evens);

}
