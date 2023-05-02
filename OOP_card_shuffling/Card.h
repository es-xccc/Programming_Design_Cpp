// Exercise 10.10 Solution: Card.h
// Class Card represents the face and suit of a card.
#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std; 

class Card
{
public:
	static const int totalFaces = 13; // total number of faces
	static const int totalSuits = 4; // total number of suits
	static const string faces[13];
	static const string suits[4];
	
	Card( int cardFace, int cardSuit ){
		face=cardFace;
		suit=cardSuit;
	}; // initialize face and suit
	
	string toString(int cardFace, int cardSuit) const{
		return faces[cardFace]+" of "+suits[cardSuit];
	}; // returns a string representation of a Card
	
	// get the card's face
	int getFace() const
	{
	  return face;
	} // end function getFace
	
	// get the card's suit
	int getSuit() const
	{
	  return suit;
	} // end function getSuit

private:
	int face;
	int suit;
	
	static const string faceNames[ totalFaces ];
	static const string suitNames[ totalSuits ];
}; // end class Card

const string Card::faces[13]={ "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const string Card::suits[4]={ "Hearts", "Diamonds", "Clubs", "Spades" };

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
