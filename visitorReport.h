#ifndef VISITREP_H
#define VISITREP_H

#include "psData.h"
#include "demogData.h"
#include "visitor.h"

class visitorReport : public Visitor {
public:
    visitorReport() : numVisited(0) {}

	void visit(demogData *e) {
    
    }
    
    void visit(psData *e) {
        
    }

    private:
    	int numVisited;
};

#endif