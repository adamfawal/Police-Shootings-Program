#include <iomanip>
#include "psCombo.h"
#include "visitor.h"



/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.cases65 << " \%: " << ((double)PD.cases65/PD.cases) * 100.0;
    out << "\n(19 to 64): "  << (PD.cases - PD.cases65 - PD.cases18)<<" \%: " <<  ((double)(PD.cases - PD.cases65 - PD.cases18)/PD.cases) * 100.0;
    out << "\n(under 18): " << PD.cases18<< " \%: " <<  ((double)PD.cases18/PD.cases) * 100.0;
    out << "\nIncidents involving fleeing: " <<  PD.numFlee<< " \%: " <<  ((double)PD.numFlee/PD.cases) * 100.0;
    out << "\nIncidents involving mental illness: " << PD.numMental<< " \%: " << ((double)PD.numMental/PD.cases) * 100.0;
    out << "\nMale incidents: "<< PD.males <<  " female incidents: " << PD.females;
    out << "\nRacial demographics of state incidents: " << PD.races;
    return out;
}
