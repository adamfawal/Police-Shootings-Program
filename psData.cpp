#include <sstream>
#include "psData.h"
#include "visitor.h"

/* print police data */
std::ostream& operator<<(std::ostream &out, const psData &PD) {
    out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " << PD.name;
    out << "\nAge: " << PD.age;
    out << "\nGender: " << PD.gender;
    out << "\nRace:" << PD.race;
    out << "\nMental Illness:" << PD.mentalCount;
    out << "\nFleeing:"<< PD.flee ;
    return out;
}
void psData::accept(class Visitor &v){
        v.visit(shared_from_this());
        // v.visit(this);
    }