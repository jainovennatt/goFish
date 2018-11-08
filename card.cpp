//
// Created by CAROLYN SHEEHY on 11/4/2018.
//
#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card :: Card() {
    myRank = 1;
    mySuit  = spades;
}                                   //done

Card :: Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}                    //done

string Card :: toString() const{
    string suit;
    string rank;
    suit=suitString(mySuit);
    rank=rankString(myRank);
    suit=rank+suit;              //rank.append(suit);
    return(suit);
}                   //done

bool Card :: sameSuitAs(const Card &c) const{
    if (mySuit==c.mySuit){
        return (true);
    }
    return(false);
}      //done

int Card ::  getRank() const{
    return myRank;
}                      //done

string Card :: suitString(Suit s) const{
    if (s==spades){
        return "s";
    }
    if (s==hearts){
        return "h";
    }
    if (s==diamonds){
        return "d";
    }
    if (s==clubs){
        return "c";
    }

}           //done

string Card :: rankString(int r) const { //return "A", "2", ..."Q"
    string str;
    if (r > 1 & r < 11) {
        str = to_string(r);
        return (str);
    }
    else if (r==1){
        return("A");
    }
    else if (r==11){
        return("J");
    }
    else if (r==12){
        return("Q");
    }
    else if (r==13){
        return("K");
    }
}           //done

bool Card :: operator == (const Card& rhs) const{
    if(myRank == rhs.myRank){
        return (true);
    }
    else{
        return (false);
    }
}  //done

bool Card :: operator != (const Card& rhs) const{
    if(myRank!= rhs.myRank){
        return(true);
    }
    else{
        return (false);
    }
}   //done
