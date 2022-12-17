#ifndef VCOMBOC_H
#define VCOMBOC_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include "demogCombo.h"
#include "visitorCombine.h"
#include "parse.h"
#include <memory>
#include <fstream>
#include <cassert>

class visitorCombineCounty : public visitorCombine {
public:
    visitorCombineCounty() {
    }

    //store demographic data by county name
	void visit(shared_ptr<demogData> obj) {
    string keyS;
    if(obj->getName().find(" County") < obj->getName().size())
    {
      keyS = (obj->getName().erase(obj->getName().find(" County"), 7))+obj->getState();
    }
    else
    {
      keyS = obj->getName() + obj->getState();
    }
        if ( comboDemogData.find(keyS) == comboDemogData.end() ){
             comboDemogData[keyS] = make_shared<demogCombo>(keyS); 
             comboDemogData[keyS]->addDemogToAggregate(obj);
        }else{
          comboDemogData[keyS]->addDemogToAggregate(obj);
        }
    }
    
    //aggregate police shooting data by county
    void visit(shared_ptr<psData> obj) {
      string keyS;
    if(obj->getCounty().find(" County") < obj->getCounty().size())
    {
      keyS = (obj->getCounty().erase(obj->getCounty().find(" County"), 7))+obj->getState();
    }
    else
    {
      keyS = obj->getCounty() + obj->getState();
    }
        if ( comboPoliceData.find(keyS) == comboPoliceData.end() ){
             comboPoliceData[keyS] = make_shared<psCombo>(keyS); 
             comboPoliceData[keyS]->addPSToAggregate(obj);
        }else{
          comboPoliceData[keyS]->addPSToAggregate(obj);
        }
    }

    private:
        //only inherited data at this point
};

#endif