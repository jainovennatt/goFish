#include <iostream>
#include "deck.h"
#include <time.h>
#include <cstdlib>
#include <string>

void swapCard(int Card1, int Card2);


Deck :: Deck(){
    int index=0;
    for(int suit=0;suit<4;suit++){
        for(int rank=1;rank<14;rank++){
            Card var(rank,Card::Suit(suit));
            myCards[index]=var;
            index++;
        }

    }
    myIndex = 0;
    displayDeck();
}

void Deck ::shuffle(){
     //  for(int i=0;i<10;i++){
     //      dealCard();
     //  }

        time_t timer;
        if (size()==1||size()==0){
            return;
        }
        srand(time(&timer));

        
        for(int i=0; i<1000;i++){
            int numberOfCards;
            int Card1;
            int Card2;

            numberOfCards = (52 - myIndex);
            Card1=((rand() % (numberOfCards))+myIndex);
            Card2=((rand() % (numberOfCards))+myIndex);

            swapCard(Card1,Card2);

        }
        cout<<endl<<endl;
        displayDeck();

    }


void Deck ::displayDeck() {
    for (int index=0;index<SIZE;index++){
        cout<<"card-"<< myCards[index].toString()<<endl;
    }
} //done private function

Card Deck :: dealCard(){
    Card temp;
    temp=myCards[myIndex];
    myIndex=myIndex+1;
    return temp;
}

int Deck :: size() const{
    return(SIZE-myIndex);
}

void Deck ::swapCard(int Card1, int Card2) {
    Card temp;
    temp=myCards[Card1];
    myCards[Card1]=myCards[Card2];
    myCards[Card2]=temp;

} //done