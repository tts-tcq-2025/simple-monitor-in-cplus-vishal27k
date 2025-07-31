#include <assert.h>
#include <iostream>
using namespace std;

// Pure functions for individual checks
bool TemperatureCheck(float temperature) {
  return temperature < 0 || temperature > 45;
}

bool SocCheck(float soc) {
  return soc < 20 || soc > 80;
}

bool ChargeRateCheck(float chargeRate) {
  return chargeRate > 0.8;
}

bool reportOutofrange(const string& name, bool status){
if(status){
  cout << name << " out of range!" << endl;
  return false;
}
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool tempNotOk = reportOutofrange("Temperature",TemperatureCheck(temperature));
  bool socNotOk = reportOutofrange("SOC",SocCheck(soc));
  bool chargeRateNotOk = reportOutofrange("Charge Rate",ChargeRateCheck(chargeRate));
  return !tempNotOk && !socNotOk && !chargeRateNotOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
