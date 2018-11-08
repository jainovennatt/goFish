//
// Created by CAROLYN SHEEHY on 11/4/2018.
//
#include "player.h"
#include <time.h>
#include <vector>
#include <iostream>

Player ::Player() {
    myName = "";
    myHand.clear();
    myBook.clear();
}//DONE



void Player :: addCard(Card c){
    myHand.push_back(c);
}//DONE-WORKS

void Player :: bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}//DONE-WORKS



bool Player :: checkHandForBook(Card &c1, Card &c2){        //OPTIONAL

} //OPTIONAL

bool Player :: rankInHand(Card c) const {                    //OPTIONAL
}//OPTIONAL





Card Player :: chooseCardFromHand() const{
    int Card;
    time_t timer;
    srand(time(&timer));
    Card=(rand()%myHand.size());
    return(myHand[Card]);
}          //DONE

bool Player :: cardInHand(Card c) const{
    int numOfCards;
    numOfCards=myHand.size();

    for(int i=0;i<numOfCards;i++){
        if(c==myHand[i]){
            return(true);
        }
    }
    return (false);
}            //DONE-WORKS

Card Player :: removeCardFromHand(Card c){
    int numOfCards;
    numOfCards=myHand.size();

    for(int i=0;i<numOfCards;i++){
        if(c==myHand[i]){
            Card a;
            a=myHand[i];
            myHand.erase(myHand.begin()+i);
            return a;
        }

    }

}          //DONE


string Player :: showHand() const{
    int size = myHand.size();
    string hand;

    for (int index = 0; index<size; index++){
        string app;
        string space="  card- ";
        app=myHand[index].toString();
        hand=hand+space;
        hand=hand+app;


    }
    return(hand);

}                //DONE-WORKS

string Player :: showBooks() const{
    int size = myBook.size();
    string book;

    for (int index = 0; index<size; index++){
        string app;
        string space="  card- ";
        app=myBook[index].toString();
        book=book+space;
        book=book+app;


    }
    return(book);
}              //DONE-WORKS

int Player :: getHandSize() const{
    int size = myHand.size();
    return (size);
}                 //DONE-WORKS

int Player :: getBookSize() const{
    int size = myBook.size();
    return (size);
}                 //DONE-WORKS

bool Player :: checkHandForPair(Card &c1, Card &c2){            //OPTIONAL

}

bool Player :: sameRankInHand(Card c) const{                    //OPTIONAL

}