#ifndef VCOMBO_H
#define VCOMBO_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include "demogCombo.h"
#include "visitor.h"
#include <memory>
#include <map>

//The shared combo data
class visitorCombine : public Visitor {
public:
    visitorCombine() {}

    //hust a helper to print out various fields
    void printAllCombo(int (demogData::*f1)() const, int (psCombo::*f2)() const) {
    }

    shared_ptr<demogCombo> getComboDemogData(string regionName) { 
        for (auto const& region: comboDemogData){
            if (region.first == regionName){
                return region.second;
            }
        }
        //return make_shared<demogCombo>("null");
        return NULL;
    } 
    
    shared_ptr<psCombo> getComboPoliceData(string regionName) { 
        for (auto const& region: comboPoliceData){
            if (region.first == regionName){
                return region.second;
            }
        }
        //return make_shared<psCombo>("null");
        return NULL;
    } 

	std::map<string, shared_ptr<demogCombo> >& getComboDemog()  { return comboDemogData; } 
    std::map<string, shared_ptr<psCombo> > & getComboPolice() { return comboPoliceData; } 

    protected:
    	//combo maps
       //store aggregated data here
       std::map<string, shared_ptr<demogCombo> > comboDemogData;
       std::map<string, shared_ptr<psCombo> > comboPoliceData;
       shared_ptr<demogCombo> temp1;
       shared_ptr<psCombo> temp2;
};

#endif