// Fig. 20.4: List.h
// Template List class definition.
#ifndef cLIST_H
#define cLIST_H

#include <iostream>
#include <new>
#include "cListNode.h" // ListNode class definition
//E94106216

using namespace std;

class cList 
{
public:
   cList(); // constructor
   ~cList(); // destructor
   void insertAtFront( const char & );
   void insertAtBack( const char & );
   bool removeFromFront( char & );
   bool removeFromBack( char & );
   bool isEmpty() const;
   void print() const;
protected:
   cListNode *firstPtr; // pointer to first node
   cListNode *lastPtr; // pointer to last node

   // utility function to allocate new node
   cListNode *getNewNode( const char & );
}; // end class List

// default constructor
cList::cList() 
   : firstPtr( 0 ), lastPtr( 0 ) 
{ 
   // empty body
} // end List constructor

// destructor
cList::~cList()
{
   if ( !isEmpty() ) // List is not empty
   {    
      cout << "Destroying nodes ...\n";

      cListNode *currentPtr = firstPtr;
      cListNode *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
      {  
         tempPtr = currentPtr;
         cout << tempPtr->data << '\n';
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      } // end while
   } // end if

   cout << "All nodes destroyed\n\n";
} // end List destructor

// insert node at front of list
void cList::insertAtFront( const char &value )
{
   cListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr; // new list has only one node
   else // List is not empty
   {
      newPtr->nextPtr = firstPtr; // point new node to previous 1st node
      firstPtr = newPtr; // aim firstPtr at new node
   } // end else
} // end function insertAtFront

// insert node at back of list
void cList::insertAtBack( const char &value )
{
   cListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr; // new list has only one node
   else // List is not empty
   {
      lastPtr->nextPtr = newPtr; // update previous last node
      lastPtr = newPtr; // new last node
   } // end else
} // end function insertAtBack

// delete node from front of list
bool cList::removeFromFront( char &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      cListNode *tempPtr = firstPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0; // no nodes remain after removal
      else
         firstPtr = firstPtr->nextPtr; // point to previous 2nd node

      value = tempPtr->data; // return data being removed
      delete tempPtr; // reclaim previous front node
      return true; // delete successful
   } // end else
} // end function removeFromFront

// delete node from back of list
bool cList::removeFromBack( char &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      cListNode *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr ) // List has one element
         firstPtr = lastPtr = 0; // no nodes remain after removal
      else 
      {
         cListNode *currentPtr = firstPtr;

         // locate second-to-last element            
         while ( currentPtr->nextPtr != lastPtr )    
            currentPtr = currentPtr->nextPtr; // move to next node

         lastPtr = currentPtr; // remove last node
         currentPtr->nextPtr = 0; // this is now the last node
      } // end else

      value = tempPtr->data; // return value from old last node
      delete tempPtr; // reclaim former last node
      return true; // delete successful
   } // end else
} // end function removeFromBack

// is List empty?
bool cList::isEmpty() const 
{ 
   return firstPtr == 0; 
} // end function isEmpty

// return pointer to newly allocated node
cListNode *cList::getNewNode( 
   const char &value )
{
   return new cListNode( value );
} // end function getNewNode

// display contents of List
void cList::print() const
{
   if ( isEmpty() ) // List is empty
   {
//      cout << "The list is empty\n\n";
      return;
   } // end if

   cListNode *currentPtr = firstPtr;

//   cout << "The list is: ";

   while ( currentPtr != 0 ) // get element data
   {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
   } // end while

//   cout << "\n";
} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
