/*!
* @file HeartMap.ino
* @brief Print heart rate value
*
*  This is Print heart rate value
* @author linfeng(Musk.lin@dfrobot.com)
* @version  V1.0
* @date  2016-8-16
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
/******************************************************************************
  Copyright (C) <2015>  <linfeng>
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  Contact: Musk.lin@dfrobot.com
 ******************************************************************************/
