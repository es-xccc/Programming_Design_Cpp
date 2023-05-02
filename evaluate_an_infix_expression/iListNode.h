// Fig. 20.3: ListNode.h
// Template ListNode class definition.
#ifndef iLISTNODE_H
#define iLISTNODE_H
//E94106216

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 13
class iList;                            

class iListNode 
{
   friend class iList; // make List a friend

public:
   iListNode( const int & ); // constructor
   int getData() const; // return data in node
protected:
   int data; // data
   iListNode *nextPtr; // next node in list
}; // end class ListNode

// constructor
iListNode::iListNode( const int &info )
   : data( info ), nextPtr( 0 ) 
{ 
   // empty body
} // end ListNode constructor

// return copy of data in node
int iListNode::getData() const 
{ 
   return data; 
} // end function getData

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
