// Fig. 20.13: Stack.h
// Template Stack class definition derived from class List.
#ifndef cSTACK_H
#define cSTACK_H

#include "cList.h" // List class definition
//E94106216

class cStack : public cList
{
public:
   // push calls the List function insertAtFront
   void push( const char &data ) 
   { 
      cList::insertAtFront( data ); 
   } // end function push

   // pop calls the List function removeFromFront
   bool pop( char &data ) 
   { 
      return cList::removeFromFront( data ); 
   } // end function pop

   // isStackEmpty calls the List function isEmpty
   char stackTop() const // check the top value
   {
      return !cList::isEmpty() ? cList::firstPtr->getData() : static_cast< char >( 0 );
   }
   bool isStackEmpty() const 
   { 
      return this->isEmpty();
   } // end function isStackEmpty
 
   // printStack calls the List function print
   void printStack() const 
   { 
        if ( this->isEmpty() ) // List is empty
   		{
      		cout << "The stack is empty\n";
      		return;
   		} // end if
   		
		cout << "The stack is: ";
        this->print();

   cout << "\n";
   } // end function print 
}; // end class Stack

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
