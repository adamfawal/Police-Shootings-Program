#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>
#include "raceDemogData.h"
#include "regionData.h"
#include <cmath>
#include <memory>

using namespace std;


class demogData : public regionData, public std::enable_shared_from_this<demogData>  {
  public:
    demogData():regionData(){}
    // demogData(string inN, string inS, double in65, double in18,
    //     double in5, double bp, int totPop14, raceDemogData race) : regionData{inN,inS,totPop14},
    //         /*name(inN), */state(inS), popOver65(in65), popUnder18(in18),
    //         popUnder5(in5),belowPoverty(bp), totalPopulation2014(totPop14), undergrad(0), highschool(0), races(race) {}
    demogData(string inN, string inS, double in65, double in18,
        double in5, double bach, double high, double bp, int totPop14, raceDemogData race) :  regionData{inN,inS} {
             totalPopulation2014 = totPop14;
             popOver65Count = round((in65 * totalPopulation2014 * .01));
             popUnder18Count = round((in18 * totalPopulation2014 * .01));
             popUnder5Count = round((in5 * totalPopulation2014 * .01));
             undergradCount = round((bach * totalPopulation2014 * .01));
             highschoolCount = round((high * totalPopulation2014 * .01));
             belowPovertyCount = bp;
             races = race;
            }
    demogData(string inN, string inS, double in65, double in18,
        double in5, double bach, double high, double bp, int totPop14) :  regionData{inN,inS}
            // /*name(inN), state(inS),*/ popOver65(in65), popUnder18(in18),
            // popUnder5(in5),belowPoverty(bp), totalPopulation2014(totPop14), undergrad(bach), highschool(high) 
            {
               popOver65Count = 0;
               popUnder18Count = 0;
               popUnder5Count = 0;
               undergradCount = 0;
               highschoolCount = 0;
               totalPopulation2014 = 0;
               belowPovertyCount = 0;
            }

    // string getName() const { return name; }
    string getName() const { return regionName; }
    string getState() const  { return *(stateS.begin()); }
    // set<string> getStates(){return stateS}
    // string getState() const  { return getState(); }
    // string getState() const  { return state; }
    int getHSupCount()const  { return highschoolCount; }
    int getBAupCount()const  { return undergradCount;}
    int getpopUnder5Count() const { return popUnder18Count; }
    int getpopUnder18Count() const { return popUnder18Count; }
    int getpopOver65Count() const { return popOver65Count; }
    double getHSup() const { 
      return (double)highschoolCount/totalPopulation2014 * 100; }
    double getBAup() const { return (double)undergradCount/totalPopulation2014 * 100; }
    double getpopUnder5()const  { return (double)popUnder5Count/totalPopulation2014 * 100; }
    double getpopUnder18() const { return (double)popUnder18Count/totalPopulation2014 * 100; }
    double getpopOver65() const { return (double)popOver65Count/totalPopulation2014 * 100; }
    double getBelowPoverty()const  { /*return belowPoverty;*/ return 100.0f*((double)(belowPovertyCount))/totalPopulation2014; }
    int getBelowPovertyCount()const  {  /*return round((belowPoverty * totalPopulation2014 * .01));*/ return belowPovertyCount; }
    int getPop() const { return totalPopulation2014; }
    raceDemogData getRace() const { return races;}
    raceDemogData getCommunityRaceMix() const { return races;}

   friend std::ostream& operator<<(std::ostream &out,  const demogData &DD);

   void accept(class Visitor &v);

protected:
     string name;
     string state;
    //  double popOver65;
    //  double popUnder18;
    //  double popUnder5;
    //  double undergrad;
    //  double highschool;
     int totalPopulation2014;
    //  double belowPoverty;
     raceDemogData races;

     int popOver65Count;
     int popUnder18Count;
     int popUnder5Count;
     int undergradCount;
     int highschoolCount;
     int belowPovertyCount;
};
#endif