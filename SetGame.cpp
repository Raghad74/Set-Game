#include "Set.h"
#include <iostream>
#include <vector>


bool checkSol(Set* card1,Set* card2,Set* card3)
{
    bool cflag=false,nflag=false,fflag=false,sflag=false;
    //checking color
    
    if((card1->getC()==card2->getC())&&(card1->getC()==card3->getC())&&(card2->getC()==card3->getC()))
    {
        cflag=true;
    }
    if((card1->getC()!=card2->getC())&&(card1->getC()!=card3->getC())&&(card2->getC()!=card3->getC()))
    {
        cflag=true;
    }
    if(cflag==false)
    return false;
    //checking number
    if((card1->getN()==card2->getN())&&(card1->getN()==card3->getN())&&(card2->getN()==card3->getN()))
    {
        nflag=true;
    }
    if((card1->getN()!=card2->getN())&&(card1->getN()!=card3->getN())&&(card2->getN()!=card3->getN()))
    {
        nflag=true;
    }
    if(nflag==false)
    return false;
   
    //checking filling
    if((card1->getF()==card2->getF())&&(card1->getF()==card3->getF())&&(card2->getF()==card3->getF()))
    {
        fflag=true;
    }
    if((card1->getF()!=card2->getF())&&(card1->getF()!=card3->getF())&&(card2->getF()!=card3->getF()))
    {
        fflag=true;
    }
    if(fflag==false)
    return false;
   
    //checking shape
    if((card1->getS()==card2->getS())&&(card1->getS()==card3->getS())&&(card2->getS()==card3->getS()))
    {
        sflag=true;
    }
    if((card1->getS()!=card2->getS())&&(card1->getS()!=card3->getS())&&(card2->getS()!=card3->getS()))
    {
        sflag=true;
    }
    return sflag;

}

int main()
{
    std::vector<Set*> game;
    int n,f;
    string s,c;
    for(int i=0;i<12;i++)
    {
        std::cout<<"info of card"<<i<<std::endl;
        std::cout<<"num"<<std::endl;
        std::cin>>n;
        std::cout<<"filling"<<std::endl;
        std::cin>>f;
        std::cout<<"color"<<std::endl;
        std::cin>>c;
        std::cout<<"shape"<<std::endl;
        std::cin>>s;
        
       
        game.push_back(new Set(n,f,c,s)) ;
        std::cout<<game[i]->getC()<<" "<<game[i]->getF()<<" "<<game[i]->getN()<<" "<<game[i]->getS()<<std::endl;
    }
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
       {
         if(i==j)
         continue;
         for(int k=0;k<12;k++)
         {
            if(k==i || k==j)continue;
            
            if(checkSol(game[i],game[j],game[k]))
            {
                std::cout<<"Solution found: "<<i<<" "<<j<<" "<<k<<std::endl;
                return 0;
            }
         }
       }

    }
     std::cout<<"Solution not found"<<std::endl;
    return 0;
}
