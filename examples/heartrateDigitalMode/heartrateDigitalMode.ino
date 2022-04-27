
/*!
 * @file  heartrateAnalogMode.h
 * @brief  This is written for the heart rate sensor the company library. Mainly used for real 
 * @n  time measurement of blood oxygen saturation, based on measured values calculate heart rate values.
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license  The MIT License (MIT)
 * @author  [linfeng](Musk.lin@dfrobot.com)
 * @maintainer  [qsjhyy](yihuan.huang@dfrobot.com)
 * @version  V1.0
 * @date  2022-04-26
 * @url  https://github.com/DFRobot/DFRobot_Heartrate
 */
#include "DFRobot_Heartrate.h"
#define heartratePin A1

DFRobot_Heartrate heartrate(DIGITAL_MODE);   // ANALOG_MODE or DIGITAL_MODE

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t rateValue;
  heartrate.getValue(heartratePin);   // A1 foot sampled values
  rateValue = heartrate.getRate();   // Get heart rate value 
  if(rateValue)  {
    Serial.println(rateValue);
  }
  delay(20);
}
