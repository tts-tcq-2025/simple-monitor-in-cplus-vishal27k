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

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  if(TemperatureCheck(temperature)) {
    cout << "Temperature out of range!\n";
  } else if(SocCheck(soc)) {
    cout << "State of Charge out of range!\n";
  } else if(ChargeRateCheck(chargeRate)) {
    cout << "Charge Rate out of range!\n";
  }
  return (!TemperatureCheck(temperature)) && (!SocCheck(soc)) && (!ChargeRateCheck(chargeRate));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
