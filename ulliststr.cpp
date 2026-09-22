#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std:: string& val){
  if(head_ == nullptr){
    Item* temp = new Item;
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;


    head_ = temp;
    tail_ = temp;
  }
  else if(tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else{
    Item* temp = new Item;
    temp->val[0] =val;
    temp->first = 0;
    temp->last = 1;

    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    Item* temp = new Item;
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;

    head_ = temp;
    tail_ = temp;
  }
  else if( head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;

  }
  else{
    Item* temp = new Item;

    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
  }
  size_++;
}



void ULListStr::pop_back()
{
  if(size_==0){
    return;
  }

  tail_->last--;
  size_--;
  if(tail_->first == tail_->last){
    Item* temp = tail_;

    if(head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }
    else{
      tail_ = tail_->prev;
      tail_->next = nullptr;

    }
    delete temp;
  }
}

void ULListStr::pop_front(){
  if(size_==0){
    return;
  }

  head_->first++;
  size_--;

  if(head_->first == head_->last){
    Item* temp = head_;
    if(head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }
    else{
      head_ = head_->next;
      head_->prev = nullptr;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const{
  if(size_ == 0){
    throw std::invalid_argument("Empty list");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  if(size_ == 0){
    throw std::invalid_argument("Empty list");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return nullptr;
  }
  
  Item* curr = head_;
  while(curr != nullptr){
    size_t numValues = curr->last - curr->first;

    if(loc <numValues){
      return &(curr->val[curr->first + loc]);
    }
    loc -= numValues;
    curr = curr->next;
  }
  return nullptr;
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
