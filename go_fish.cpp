// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards


    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


    while(d.size()!=0&p1.getHandSize()!=0&p2.getHandSize()!=0){
        Card temp;
        int rank;

        temp=p1.chooseCardFromHand();
        temp.getRank();
        cout << p1.getName()<<" asks - Do you have a  "<< p1.showHand()<<endl;






    }










    /*cout <<endl;

    cout << p1.getName()<<" has : "<< p1.showHand()<<endl;

    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    cout << p1.getName()<<" book's has : "<< p1.showBooks()<<endl;

    cout << p2.getName() <<" book's has : " << p2.showBooks() << endl;


    cout<<p1.getName()<<" has "<<p1.getHandSize()<<" cards"<<endl;
    cout<<p2.getName()<<" has "<<p2.getHandSize()<<" cards"<<endl;

    cout<<p1.getName()<<" has "<<p1.getBookSize()<<" cards in book"<<endl;
    cout<<p2.getName()<<" has "<<p2.getBookSize()<<" cards in book"<<endl;

    cout<<d.size()<<" cards in deck "<<endl;

    Card temp;
    temp=p1.chooseCardFromHand();
    if(p1.cardInHand(temp)){
        cout<<"true"<<endl<<"should be true"<<endl;
    }
    else {cout<<"false"<<endl<<"should be true"<<endl; }

    if(p2.cardInHand(temp)){
        cout<<"true"<<endl<<"should be false"<<endl;
    }
    else{cout<<"false"<<endl<<"should be false"<<endl; }

    p1.bookCards(temp,temp);
    cout << p1.getName()<<" book's has : "<< p1.showBooks()<<endl;
    cout<<p1.getName()<<" has "<<p1.getBookSize()<<" cards in book"<<endl;
    cout << p1.getName()<<" has : "<< p1.showHand()<<endl;
    p1.removeCardFromHand(temp);
    cout << p1.getName()<<" has : "<< p1.showHand()<<endl;

    */


}





void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
       p.addCard(d.dealCard());
}
   


