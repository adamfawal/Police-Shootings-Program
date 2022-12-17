#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
      //using demogData::regionData;
        //write demogCombo constructor
        demogCombo(string regionNameee, int check):
        demogData{ regionNameee,  "",  0,  0, 0,  0,  0, 0, 0} {
          countyNum = 0;
        }
        demogCombo(string state):
        demogData{ "",  state,  0,  0, 0,  0,  0, 0, 0} {
          countyNum = 0;
        }
    

      void addDemogToAggregate(shared_ptr<demogData> county){
            races += county->getRace();
            totalPopulation2014 += county->getPop();
            highschoolCount += county->getHSupCount();
            undergradCount += county->getBAupCount();
            popUnder5Count += county->getpopUnder5Count();
            popUnder18Count += county->getpopUnder18Count();
            popOver65Count += county->getpopOver65Count();
            belowPovertyCount += county->getBelowPovertyCount();   
            countyNum++;
  }


  int getCountyNum(){
    return countyNum;
  }

  friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
    
    int countyNum ;

};
#endif