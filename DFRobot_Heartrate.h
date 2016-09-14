

/*!
* @file DFRobot_Heartrate.h
* @brief Heartrate.h detailed description for Heartrate.cpp 
*
*  This is written for the heart rate sensor the company library. Mainly used for real 
*  time measurement of blood oxygen saturation, based on measured values calculate heart rate values.
* 
* @author linfeng(490289303@qq.com)
* @version  V1.0
* @date  2015-12-24
*/

#ifndef __DFRobot_HEARTRATE__H
#define __DFRobot_HEARTRATE__H
          

#include "Arduino.h"


#define ANALOG_MODE 0
#define DIGITAL_MODE 1


#define SAMPLE_NUMBER 100


class DFRobot_Heartrate
{
public:
    DFRobot_Heartrate(char mode) { mode_ = mode; }
	char maxNumber(uint8_t count);
	void minNumber(uint8_t count);
	uint16_t analogGetRate(void);
	uint16_t digitalGetRate(void);
	uint16_t getRate(void);
    uint8_t getCnt(void); 
	uint16_t getValue(uint8_t pin);	
	
private:	
	
	uint8_t mode_;	
	uint8_t valueCount_=255;
	uint8_t valueFlag;	
    uint32_t nowTim=0,lastTim=0;
	
};

#endif

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
  Contact: 490289303@qq.com
 ******************************************************************************/
 
 