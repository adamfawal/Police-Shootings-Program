#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include "raceDemogData.h"
#include "regionData.h"

using namespace std;

class Visitor;
class psData : public regionData, public std::enable_shared_from_this<psData> {
   public:
    psData(string inState, string inName, int inAge, string inGender, string inRace, string inSigns,
    string inFlee) : regionData{inName,inState}, state(inState), name(inName), age(inAge), gender(inGender), race(inRace),
        signsOfMentalIllness(inSigns), flee(inFlee), county(""){
          if(race == "A")
            races.addAsianCount(1);
          else if (race == "B")
            races.addBlackCount(1);
          else if(race == ""|| race == "O")
            races.addOtherCount(1);
          else if(race == "H"){
            races.addLatinxCount(1);
            races.addWhiteCount(1);
          }
          else if(race == "W"){
            races.addWhiteNHCount(1);
            races.addWhiteCount(1);
          }
          else if(race == "N"){
            races.addFirstNationCount(1);
          }
          mentalCount = 0;
          if(signsOfMentalIllness == "True")
          {
            mentalCount = 1;
          }
        }
    psData(string inState, string inName, int inAge, string inGender, string inRace, string inSigns,
    string inFlee, string city) : regionData{city,inState}, state(inState), name(inName), age(inAge), gender(inGender), race(inRace),
        signsOfMentalIllness(inSigns), flee(inFlee), county(city){
          if(race == "A")
            races.addAsianCount(1);
          else if (race == "B")
            races.addBlackCount(1);
          else if(race == ""|| race == "O")
            races.addOtherCount(1);
          else if(race == "H"){
            races.addLatinxCount(1);
            races.addWhiteCount(1);
          }
          else if(race == "W"){
            races.addWhiteNHCount(1);
            races.addWhiteCount(1);
          }
          else if(race == "N"){
            races.addFirstNationCount(1);
          }
          mentalCount = 0;
          if(signsOfMentalIllness == "True")
          {
            mentalCount = 1;
          }
        }


    string getState() const { return state; }
    string getName() const { return name;}
    int getAge() const { return age;}
    string getGender() const { return gender;}
    string getRace() const {return race;}
    raceDemogData getRaces() const { return races;}
    string getSigns() const { return signsOfMentalIllness;}
    int getMental() const { return mentalCount;}
    string getFlee() const { return flee;}
    string getCounty() const {return county;}
    //add getters

   friend std::ostream& operator<<(std::ostream &out, const psData &PD);

   void accept(class Visitor &v);

private:
    const string state;
    const string name;
    const int age;
    const string gender;
    const string race;
    raceDemogData races;
    //const string state;
    const string signsOfMentalIllness;
    int mentalCount;
    const string flee;
    const string county;
    //add others
};

#endif