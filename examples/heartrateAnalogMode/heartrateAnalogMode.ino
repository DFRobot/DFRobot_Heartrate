/*!
 * @file  heartrateAnalogMode.ino
 * @brief  Print heart rate value
 * @details  This is Print heart rate value
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license  The MIT License (MIT)
 * @author  [linfeng](Musk.lin@dfrobot.com)
 * @maintainer  [qsjhyy](yihuan.huang@dfrobot.com)
 * @version  V1.0
 * @date  2022-04-26
 * @url  https://github.com/DFRobot/DFRobot_Heartrate
 */
#define heartPin A1

void setup() {
  Serial.begin(115200);
}
void loop() {
  int heartValue = analogRead(heartPin);
  Serial.println(heartValue);
  delay(20);
}
