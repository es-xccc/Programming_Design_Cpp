// Fig. 20.4: List.h
// Template List class definition.
#ifndef iLIST_H
#define iLIST_H

#include <iostream>
#include <new>
#include "iListNode.h" // ListNode class definition
//E94106216
using namespace std;

class iList 
{
public:
   iList(); // constructor
   ~iList(); // destructor
   void insertAtFront( const int & );
   void insertAtBack( const int & );
   bool removeFromFront( int & );
   bool removeFromBack( int & );
   bool isEmpty() const;
   void print() const;
protected:
   iListNode *firstPtr; // pointer to first node
   iListNode *lastPtr; // pointer to last node

   // utility function to allocate new node
   iListNode *getNewNode( const int & );
}; // end class List

// default constructor
iList::iList() 
   : firstPtr( 0 ), lastPtr( 0 ) 
{ 
   // empty body
} // end List constructor

// destructor
iList::~iList()
{
   if ( !isEmpty() ) // List is not empty
   {    
      cout << "Destroying nodes ...\n";

      iListNode *currentPtr = firstPtr;
      iListNode *tempPtr;

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
void iList::insertAtFront( const int &value )
{
   iListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr; // new list has only one node
   else // List is not empty
   {
      newPtr->nextPtr = firstPtr; // point new node to previous 1st node
      firstPtr = newPtr; // aim firstPtr at new node
   } // end else
} // end function insertAtFront

// insert node at back of list
void iList::insertAtBack( const int &value )
{
   iListNode *newPtr = getNewNode( value ); // new node

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr; // new list has only one node
   else // List is not empty
   {
      lastPtr->nextPtr = newPtr; // update previous last node
      lastPtr = newPtr; // new last node
   } // end else
} // end function insertAtBack

// delete node from front of list
bool iList::removeFromFront( int &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      iListNode *tempPtr = firstPtr; // hold tempPtr to delete

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
bool iList::removeFromBack( int &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      iListNode *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr ) // List has one element
         firstPtr = lastPtr = 0; // no nodes remain after removal
      else 
      {
         iListNode *currentPtr = firstPtr;

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
bool iList::isEmpty() const 
{ 
   return firstPtr == 0; 
} // end function isEmpty

// return pointer to newly allocated node
iListNode *iList::getNewNode( 
   const int &value )
{
   return new iListNode( value );
} // end function getNewNode

// display contents of List
void iList::print() const
{
   if ( isEmpty() ) // List is empty
   {
//      cout << "The list is empty\n\n";
      return;
   } // end if

   iListNode *currentPtr = firstPtr;

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
