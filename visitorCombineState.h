#ifndef VCOMBOS_H
#define VCOMBOS_H


#include "visitorCombine.h"
#include <memory>

class visitorCombineState : public visitorCombine {
public:
    visitorCombineState() {}

	void visit(shared_ptr<demogData> obj) {
        if ( comboDemogData.find(obj->getState()) == comboDemogData.end() ){
             comboDemogData[obj->getState()] = make_shared<demogCombo>(obj->getState()); 
             comboDemogData[obj->getState()]->addDemogToAggregate(obj);
        }else{
          comboDemogData[obj->getState()]->addDemogToAggregate(obj);
        }
    }
    
    void visit(shared_ptr<psData> obj) {
        if ( comboPoliceData.find(obj->getState()) == comboPoliceData.end() ){
             comboPoliceData[obj->getState()] = make_shared<psCombo>(obj->getState()); 
             comboPoliceData[obj->getState()]->addPSToAggregate(obj);
        }else{
          comboPoliceData[obj->getState()]->addPSToAggregate(obj);
        }
    }

    private:
       //inherited
};

#endif