#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>
#include <math.h>
#include <cmath>



/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    out << std::setprecision(2) << std::fixed;
    //out << "key: " << ComboD.getName();
    out << "Combo Info: " << ComboD.printState();
    out << "\nNumber of Counties: " << (int)ComboD.countyNum << " County Demographics Info: comboData, many";
    //consider re-writing with getters....
    out << "\nPopulation info: \n(over 65): " << ComboD.popOver65Count/ComboD.totalPopulation2014*100.0<<"\%" ;
    out <<  " and total: " << (int) round(ComboD.popOver65Count);
    out << "\n(under 18): " << ComboD.popUnder18Count /ComboD.getPop()* 100.0 << "\% and total: " <<(int) round(ComboD.popUnder18Count) ;

    out << "\n(under 5): " << ComboD.popUnder5Count /ComboD.getPop()* 100 << "\% and total: " << (int) round(ComboD.popUnder5Count);

    out << "\nEducation info: \n(Bachelor or more): " << ComboD.undergradCount/ComboD.getPop()* 100.0 << "\% and total: " <<  (int) round(ComboD.undergradCount);

    out << "\n(high school or more): "<< ComboD.highschoolCount /ComboD.getPop()* 100.0 << "\% and total: " << (int) round(ComboD.highschoolCount);

    out << "\npersons below poverty: " << ComboD.getBelowPoverty() << "\% and total: " << (int) round(ComboD.getBelowPovertyCount());
    
    out << "\nTotal population: " << (int) ComboD.getPop() << std::endl;
    out <<ComboD.races;
    return out;

}

/*
State Info: UT
Number of Counties: 29
Population info: 
(over 65): 10.03% and total: 295146
(under 18): 30.71% and total: 903830
(under 5): 8.58% and total: 252378
Education info: 
(Bachelor or more): 30.54% and total: 898886
(high school or more): 91.01% and total: 2678412
persons below poverty: 12.67% and total: 372832
Total population: 2942902
*/
