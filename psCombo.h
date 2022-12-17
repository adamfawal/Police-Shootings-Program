#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>

using namespace std;



class psCombo : public regionData/* , public std::enable_shared_from_this<psCombo> */ {
public:
    //write psCombo constructor
     psCombo(string state, int x):regionData{state, ""}{
         numMental=0;
         cases65=0;
         cases18=0;
         males=0;
         females=0;
         numFlee=0;
         cases=0;
    }
    psCombo(string state):regionData{"",state}{
         numMental=0;
         cases65=0;
         cases18=0;
         males=0;
         females=0;
         numFlee=0;
         cases=0;
    }

    void addPSToAggregate(shared_ptr<psData> psThing){

        numMental += psThing->getMental();
        // cout << numMental << " numMental number" << endl;
        
        if(psThing->getAge() > 65){
            cases65++;
        }
        else if(psThing->getAge() < 18){
            cases18++;
        }
         if (psThing->getGender() == "M"){
             males++;
         }else{
             females++;
         }
         if(psThing->getFlee() == "Foot" ||
            psThing->getFlee() == "Car" ||
            psThing->getFlee() == "Other"){
            numFlee++;
        }
        races += psThing->getRaces();
        cases++;
    }
    // psCombo(vector<shared_ptr<psData>> thing){
    //     cases = 0;
    //     for (auto psDataLooper : thing)
    //     {
    //         if(psDataLooper->getSigns() == "True"){
    //             numMental++;
    //         }
    //         if(psDataLooper->getFlee() == "Foot" ||
    //             psDataLooper->getFlee() == "Car" ||
    //             psDataLooper->getFlee() == "Other"){
    //             numFlee++;
    //         }
    //         if(psDataLooper->getAge() > 65){
    //             cases65++;
    //         }
    //         else if(psDataLooper->getAge() < 18){
    //             cases18++;
    //         }
    //         if(psDataLooper->getGender() == "M"){
    //             males++;
    //         }
    //         else
    //         {
    //             females++;
    //         }
    //         cases++;
    //     }
    // }
   
    int getNumMentalI() const{ return numMental;}
    int getFleeingCount()const {return numFlee;}
    int getCasesOver65()const{ return cases65;}
    int getCasesUnder18()const {return cases18;}
    raceDemogData getRace()const {return races;}
    raceDemogData getRacialData()const {return races;}
    int getnumMales() const{return males;}
    int getnumFemales() const{return females;}
    int getNumberOfCases() const{return cases;}
    // string getState() const {return state;} 
    

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

    void accept(class Visitor &v)
    {}

protected:
    
    // string state;
    int numMental;
    int cases65;
    int cases18;
    raceDemogData races;
    int males;
    int females;
    int numFlee;
    int cases;
};

#endif