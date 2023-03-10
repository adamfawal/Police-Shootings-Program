#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;

int main() {

    // dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data

    std::vector<shared_ptr<regionData>> pileOfData;

    std::vector<shared_ptr<regionData> > theDemogData = read_csv(
            pileOfData,"county_demographics.csv", DEMOG);

    std::vector<shared_ptr<regionData> > thePoliceData = read_csv(
            pileOfData,"police_shootings_cleaned.csv", POLICE);

    // std::vector<shared_ptr<demogData>> theDemogData = read_csv(
    //         "county_demographics.csv", DEMOG);

    // std::vector<shared_ptr<psData>> thePoliceData = read_csvPolice(
    //         "police_shootings_cleaned.csv", POLICE);

    // for (const auto &obj : theDemogData){
    //     // if (std::static_pointer_cast<demogData>(obj)->getState().compare("many") == 0)
    //         std::cout << *std::static_pointer_cast<demogData>(obj) << std::endl;
    // } 
    
    // for (const auto &obj : thePoliceData) {
    //     std::cout << *std::static_pointer_cast<psData>(obj) << std::endl;
    // } 
    
    
    // theAnswers.createComboPoliceData((std::vector<shared_ptr<psData> >&)thePoliceData);
    // theAnswers.createComboDemogData((std::vector<shared_ptr<demogData> >&)theDemogData);
   // theAnswers.createComboPoliceData((std::vector<shared_ptr<psData> >&)thePoliceData);
    //  cout << *(theAnswers.getComboDemogData("AK")) << endl;
    //theAnswers.comboReport(92);
//cout << *(theAnswers.getComboPoliceData("KeyAsianVictim")) << endl;

    // cout << "*** the state that needs the most pre-schools**" << endl;
    // string needPK = theAnswers.youngestPop();
    // cout << *(theAnswers.getStateData(needPK)) << endl;
    // cout << "*** the state that needs the most high schools**" << endl;
    // string needHS = theAnswers.teenPop();
    // cout << *(theAnswers.getStateData(needHS)) << endl;
    // cout << "*** the state that needs the most vaccines**" << endl;
    // string needV = theAnswers.wisePop();
    // cout << *(theAnswers.getStateData(needV)) << endl;

    // cout << "*** the state that needs the most help with education**" << endl;
    // string noHS = theAnswers.underServeHS();
    // cout << *(theAnswers.getStateData(noHS)) << endl;
    // cout << "*** the state with most college grads**" << endl;
    // string grads = theAnswers.collegeGrads();
    // cout << *(theAnswers.getStateData(grads)) << endl;

    // cout << "*** the state with most population below the poverty line**" << endl;
    // string belowPov = theAnswers.belowPoverty();
    // cout << *(theAnswers.getStateData(belowPov)) << endl;
    
    return 0;
}
