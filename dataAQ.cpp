/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";

  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getBelowPoverty() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }

  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {
  string theKey = "Key"; 
  if (theData->getRace() == "W") {
    theKey += "WhiteVictim";
  } else if (theData->getRace() == "A") {
    theKey += "AsianVictim";
  } else if (theData->getRace() == "H") {
    theKey += "HispanicVictim";
  } else if (theData->getRace() == "N") {
    theKey += "NativeAmericanVictim";
  } else if (theData->getRace() == "B") {
    theKey += "AfricanAmericanVictim";
  } else if (theData->getRace() == "O") {
    theKey += "OtherRaceVictim";
  } else {
    theKey += "RaceUnspecifiedVictim";
  }
  
  
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

for (auto const& x: theData)
{
  allComboDemogData[makeKeyExample(x)] = make_shared<demogCombo>(makeKeyExample(x),0);
  
}
for (auto const& x: theData){
    
    if (x->getBelowPoverty() < 10) {
    std::set<string> y = allComboDemogData["KeyBelowPovLessTenPer"]->getSet();
    allComboDemogData["KeyBelowPovLessTenPer"]->setName("KeyBelowPovLessTenPer");
    if (allComboDemogData["KeyBelowPovLessTenPer"]->getSet().find(x->getState()) != allComboDemogData["KeyBelowPovLessTenPer"]->getSet().end())
      allComboDemogData["KeyBelowPovLessTenPer"]->addState(x->getState());
    allComboDemogData["KeyBelowPovLessTenPer"]->addDemogToAggregate(x);
  } else if (x->getBelowPoverty() < 20) {
    std::set<string> y = allComboDemogData["KeyBelowPovLessTwentyPer"]->getSet();
    allComboDemogData["KeyBelowPovLessTwentyPer"]->setName("KeyBelowPovLessTwentyPer");
     if (allComboDemogData["KeyBelowPovLessTwentyPer"]->getSet().find(x->getState()) != allComboDemogData["KeyBelowPovLessTwentyPer"]->getSet().end())
      allComboDemogData["KeyBelowPovLessTwentyPer"]->addState(x->getState());
    allComboDemogData["KeyBelowPovLessTwentyPer"]->addDemogToAggregate(x);
  } else if (x->getBelowPoverty() < 30) {
    std::set<string> y = allComboDemogData["KeyBelowPovLessThirtyPer"]->getSet();
    allComboDemogData["KeyBelowPovLessThirtyPer"]->setName("KeyBelowPovLessThirtyPer");
    if (allComboDemogData["KeyBelowPovLessThirtyPer"]->getSet().find(x->getState()) != allComboDemogData["KeyBelowPovLessThirtyPer"]->getSet().end())
      allComboDemogData["KeyBelowPovLessThirtyPer"]->addState(x->getState());
    allComboDemogData["KeyBelowPovLessThirtyPer"]->addDemogToAggregate(x);
  } else {
    std::set<string> y = allComboDemogData["KeyBelowPovAboveThirtyPer"]->getSet();
    allComboDemogData["KeyBelowPovAboveThirtyPer"]->setName("KeyBelowPovAboveThirtyPer");
    if (allComboDemogData["KeyBelowPovAboveThirtyPer"]->getSet().find(x->getState()) != allComboDemogData["KeyBelowPovAboveThirtyPer"]->getSet().end())
      allComboDemogData["KeyBelowPovAboveThirtyPer"]->addState(x->getState());
    allComboDemogData["KeyBelowPovAboveThirtyPer"]->addDemogToAggregate(x);
   }
  }

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {

for (auto const& x: theData)
{
  allComboPoliceData[makeKeyExample(x)] = make_shared<psCombo>(makeKeyExample(x),0);
}
for (auto const& x: theData){
  
  if (x->getRace() == "W") {
  allComboPoliceData["KeyWhiteVictim"]->setName("KeyWhiteVictim");
    if (allComboPoliceData["KeyWhiteVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyWhiteVictim"]->getSet().end())
      allComboPoliceData["KeyWhiteVictim"]->addState(x->getState());
    allComboPoliceData["KeyWhiteVictim"]->addPSToAggregate(x);
  } else if (x->getRace() == "A") {
    allComboPoliceData["KeyAsianVictim"]->setName("KeyAsianVictim");
    if (allComboPoliceData["KeyAsianVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyAsianVictim"]->getSet().end())
      allComboPoliceData["KeyAsianVictim"]->addState(x->getState());
    allComboPoliceData["KeyAsianVictim"]->addPSToAggregate(x);
  } else if (x->getRace() == "H") {
    //theKey += "HispanicVictim";
    allComboPoliceData["KeyHispanicVictim"]->setName("KeyHispanicVictim");
    if (allComboPoliceData["KeyHispanicVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyHispanicVictim"]->getSet().end())
      allComboPoliceData["KeyHispanicVictim"]->addState(x->getState());
    allComboPoliceData["KeyHispanicVictim"]->addPSToAggregate(x);
  } else if (x->getRace() == "N") {
    //theKey += "NativeAmericanVictim";
     allComboPoliceData["KeyNativeAmericanVictim"]->setName("KeyNativeAmericanVictim");
    if (allComboPoliceData["KeyNativeAmericanVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyNativeAmericanVictim"]->getSet().end())
      allComboPoliceData["KeyNativeAmericanVictim"]->addState(x->getState());
    allComboPoliceData["KeyNativeAmericanVictim"]->addPSToAggregate(x);
  } else if (x->getRace() == "B") {
    //theKey += "AfricanAmericanVictim";
     allComboPoliceData["KeyAfricanAmericanVictim"]->setName("KeyAfricanAmericanVictim");
    if (allComboPoliceData["KeyAfricanAmericanVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyAfricanAmericanVictim"]->getSet().end())
      allComboPoliceData["KeyAfricanAmericanVictim"]->addState(x->getState());
    allComboPoliceData["KeyAfricanAmericanVictim"]->addPSToAggregate(x);
  } else if (x->getRace() == "O") {
    //theKey += "OtherRaceVictim";
     allComboPoliceData["KeyOtherRaceVictim"]->setName("KeyOtherRaceVictim");
    if (allComboPoliceData["KeyOtherRaceVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyOtherRaceVictim"]->getSet().end())
      allComboPoliceData["KeyOtherRaceVictim"]->addState(x->getState());
    allComboPoliceData["KeyOtherRaceVictim"]->addPSToAggregate(x);
  } else {
    //theKey += "RaceUnspecifiedVictim";
     allComboPoliceData["KeyRaceUnspecifiedVictim"]->setName("KeyRaceUnspecifiedVictim");
    if (allComboPoliceData["KeyRaceUnspecifiedVictim"]->getSet().find(x->getState()) != allComboPoliceData["KeyRaceUnspecifiedVictim"]->getSet().end())
      allComboPoliceData["KeyRaceUnspecifiedVictim"]->addState(x->getState());
    allComboPoliceData["KeyRaceUnspecifiedVictim"]->addPSToAggregate(x);
  }

}
}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
  //createComboDemogDataKey(theData);
  for (auto const &counties : theData){
        // NameToStates[counties->getState()].push_back(counties);
        if ( allComboDemogData.find(counties->getState()) == allComboDemogData.end() ){
             allComboDemogData[counties->getState()] = make_shared<demogCombo>(counties->getState()); 
             allComboDemogData[counties->getState()]->addDemogToAggregate(counties);
        }else{
          allComboDemogData[counties->getState()]->addDemogToAggregate(counties);
        }
        
    }

  


}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
  for (auto const &counties : theData){
        // NameToStates[counties->getState()].push_back(counties);
        
        if ( allComboPoliceData.find(counties->getState()) == allComboPoliceData.end() ){
             allComboPoliceData[counties->getState()] = make_shared<psCombo>(counties->getState()); 
             allComboPoliceData[counties->getState()]->addPSToAggregate(counties);
        }else{
          allComboPoliceData[counties->getState()]->addPSToAggregate(counties);
        }
        
    }

}

bool compare(shared_ptr<psCombo> PD,shared_ptr<psCombo> PD2){
    return (PD->getNumberOfCases() > PD2->getNumberOfCases());
}


//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  
  
  vector <shared_ptr<psCombo> > fiftyStates;
    for (auto stateIterator: allComboPoliceData){
        shared_ptr<psCombo> temp = stateIterator.second;
        fiftyStates.push_back(temp);
    }

    string currentState = "";
    std::sort(fiftyStates.begin(), fiftyStates.end(), compare);

    cout << std::setprecision(2) << std::fixed;
    for(int i = 0; i < 10; i++)
    {
        
        currentState = fiftyStates[i]->getState();
        
        cout << currentState << endl;
  
      
        cout << "Total population: " << allComboDemogData[currentState]->getPop() << endl;

        cout << "Police shooting incidents: " << allComboPoliceData[currentState]->getNumberOfCases() << endl;

        cout << "Percent below poverty: " << allComboDemogData[currentState]->getBelowPoverty()/allComboDemogData[currentState]->getPop() * 100.0 << endl;
    }
    cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:" << endl;
    for(int j = 0; j < 3; j++)
    {
        currentState = fiftyStates[j]->getState();
        cout << *allComboDemogData[currentState];
        cout << "**Police shooting incidents:";
        cout << *allComboDemogData[currentState];
    }

}

bool compareBP(shared_ptr<demogCombo> PD,shared_ptr<demogCombo> PD2){
    return (PD->getBelowPovertyCount() > PD2->getBelowPovertyCount());
}

    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
  int x = 0;
  std::shared_ptr<demogCombo> temp;
  int index;
  vector <shared_ptr<demogCombo>> fiftyStates;
    for (auto const& stateIterator: allComboDemogData){
        shared_ptr<demogCombo> temp = stateIterator.second;
        fiftyStates.push_back(temp);
    }

    string currentState = "";
    //std::sort(fiftyStates.begin(), fiftyStates.end(), compareBP);

    for(int i = 0; i< fiftyStates.size()-1; i++){
    index = i;
    for(int j = i +1; j< fiftyStates.size(); j++){
      if(fiftyStates.at(j)->getBelowPoverty()/fiftyStates.at(j)->getPop() >fiftyStates.at(index)->getBelowPoverty()/fiftyStates.at(index)->getPop()){
        index = j;
      }
    }
    
    temp = fiftyStates.at(i);
    fiftyStates.at(i) = fiftyStates.at(index);
    fiftyStates.at(index) = temp;
    }


    cout << std::setprecision(2) << std::fixed;
    cout << "Top ten states sorted on Below Poverty data & the associated police shooting Data:" << endl;
    for(int i = 0; i < 10; i++)
    {
        currentState = fiftyStates[i]->getState();
        cout << currentState << endl;
        cout << "Total population: " << allComboDemogData[currentState]->getPop() << endl;

        cout << "Percent below poverty: " << allComboDemogData[currentState]->getBelowPoverty()/allComboDemogData[currentState]->getPop() * 100.0  << endl;
        cout << "Police shooting incidents: " << allComboPoliceData[currentState]->getNumberOfCases() << endl;

    }
    cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:" << endl;
    for(int j = 0; j < 3; j++)
    {
        currentState = fiftyStates[j]->getState();
        cout << *allComboDemogData[currentState];
        cout << "**Police shooting incidents:";
        cout << *allComboDemogData[currentState];
    }
    
}
/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  return out;
}

void dataAQ::comboReport(double thresh){
  visitorReport report;
  std::vector<shared_ptr<regionData>> pileData;

  for (auto const& stateIterator: allComboDemogData){
        shared_ptr<demogCombo> temp = stateIterator.second;
        if((stateIterator.second->getHSup()/stateIterator.second->getPop() * 100)> thresh){
          pileData.push_back(temp);
          shared_ptr<psCombo> temp2 = allComboPoliceData[temp->getState()];
          pileData.push_back(temp2);
        }
    }

    for (const auto &obj : pileData) {
        obj->accept(report);
    }
}