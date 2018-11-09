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

Card playerCheckCards(Player &p,Card heart, Card diamond, Card spade, Card club);

void CheckBook(Player &p);
int main( ) {
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    for (int i = 0; i < 2; i++) {


        CheckBook(p1);
        CheckBook(p2);

    }


    while (d.size() != 0 || p1.getHandSize() != 0 || p2.getHandSize() != 0) {

        Card temp1;
        Card temp2;
        Card waste;

        int rank;


        if (d.size() != 0 || p1.getHandSize() != 0) {

            if (p1.getHandSize() == 0 && d.size() != 0) {
                dealHand(d, p1, 1);

            }
            else
                {
                temp1 = p1.chooseCardFromHand();
                rank = temp1.getRank();
                cout << p1.getName() << " asks - Do you have a  " << rank << endl;
                if (p2.rankInHand(temp1)) {
                    cout << p2.getName() << " says - Yes. I have a " << rank;
                    Card heart(rank, (Card::hearts));
                    Card spade(rank, (Card::spades));
                    Card diamond(rank, (Card::diamonds));
                    Card club(rank, (Card::clubs));

                    temp2 = playerCheckCards(p2, heart, diamond, spade, club);

                    p1.bookCards(temp1, temp2);
                    cout<<endl<<p1.getName()<<" books "<< temp2.toString()<<" and his "<< temp1.toString()<<endl;
                    waste = p1.removeCardFromHand(temp1);
                    waste = p2.removeCardFromHand(temp2);
                    if (p1.getHandSize() == 0 && d.size() != 0) {
                        dealHand(d, p1, 1);
                    }

                }
                else
                {
                    cout << p2.getName() << " says - Go Fish! ";

                    if (d.size() != 0) {
                        dealHand(d, p1, 1);
                    }
                    CheckBook(p1);
                    if (p1.getHandSize() == 0 && d.size() != 0) {
                        dealHand(d, p1, 1);
                    }
                }

            if (d.size() != 0 || p2.getHandSize() != 0) {

                if (p2.getHandSize() == 0 && d.size() != 0) {
                    dealHand(d, p2, 1);

                } else {
                    temp1 = p2.chooseCardFromHand();
                    rank = temp1.getRank();
                    cout << p2.getName() << " asks - Do you have a  " << rank << endl;
                    if (p1.rankInHand(temp1)) {
                        cout << p1.getName() << " says - Yes. I have a " << rank;
                        Card heart(rank, (Card::hearts));
                        Card spade(rank, (Card::spades));
                        Card diamond(rank, (Card::diamonds));
                        Card club(rank, (Card::clubs));

                        temp2 = playerCheckCards(p1, heart, diamond, spade, club);

                        p2.bookCards(temp1, temp2);
                        cout<<endl<<p2.getName()<<" books "<< temp2.toString()<<" and hi    s "<< temp1.toString()<<endl;
                        waste = p1.removeCardFromHand(temp2);
                        waste = p2.removeCardFromHand(temp1);
                        if (p2.getHandSize() == 0 && d.size() != 0) {
                            dealHand(d, p2, 1);
                        }

                        }
                        else {
                            cout << p1.getName() << " says - Go Fish! ";

                            if (d.size() != 0) {
                                dealHand(d, p2, 1);
                            }
                            CheckBook(p2);
                            if (p2.getHandSize() == 0 && d.size() != 0) {
                                dealHand(d, p2, 1);
                            }
                        }


                    }


                }

            }


        }




























    }

    cout<<p1.showBooks();
    cout<<endl<<p2.showBooks();
    cout << "hi";
}




Card playerCheckCards(Player &p,Card heart, Card diamond, Card spade, Card club){
    if (p.cardInHand(club)){
        return (club);
    }
    if (p.cardInHand(heart)){
        return (heart);
    }
    if (p.cardInHand(spade)){
        return (spade);
    }
    if (p.cardInHand(diamond)){
        return (diamond);
    }

}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++){
        Card temp;
        temp=d.dealCard();
        cout<<endl<<p.getName()<<" drew "<<temp.toString()<<endl<<endl;
         p.addCard(temp);
}}

void CheckBook(Player &p1){
    Card temp3(0,Card::spades);
    Card temp4(0,Card::spades);
    if (p1.checkHandForPair(temp3,temp4))
    {
        p1.bookCards(temp3,temp4);
        cout<<endl<<p1.getName()<<" books "<< temp3.toString()<<" and his "<< temp4.toString()<<endl;
        p1.removeCardFromHand(temp3);
        p1.removeCardFromHand(temp4);
    }

}
