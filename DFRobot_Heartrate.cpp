/*!
 * @file  DFRobot_Heartrate.cpp
 * @brief  DFRobot_Heartrate.h detailed description for DFRobot_Heartrate.cpp
 * @details  This is written for the heart rate sensor the company library. Mainly used for real 
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

uint16_t value[SAMPLE_NUMBER]={0};   // Initialize sampling point value

uint16_t DFRobot_Heartrate::getValue(uint8_t pin)
{
    valueCount_++;
    if(valueCount_ >= SAMPLE_NUMBER){
        valueCount_ = 0;
    }
    value[valueCount_] = analogRead(pin);
    return(value[valueCount_]);
}

uint8_t DFRobot_Heartrate::getCnt(void)
{
    return(valueCount_);
}

char DFRobot_Heartrate::maxNumber(uint8_t count)
{
    uint16_t temp1,temp2;
    for(int i=0;i<4;i++){
        if(count<i){
            temp1 = SAMPLE_NUMBER+count-i;
        }else{
            temp1 = count-i;
        }
        if(count<i+1){
            temp2 = SAMPLE_NUMBER+(count-1)-i;
        }else{
            temp2 = (count-1)-i;
        }
        if(value[temp1]<=value[temp2])return(0);
    }
    if(valueFlag){
        valueFlag=1;
        return(0);
    }else{
        valueFlag=1;
        return(1);   // Continuous increase
    }
}

void DFRobot_Heartrate::minNumber(uint8_t count)
{
    uint16_t temp1,temp2;
    for(int i=0;i<4;i++){
        if(count<i){
            temp1 = SAMPLE_NUMBER+count-i;
        }else{
            temp1 = count-i;
        }
        if(count<i+1){
            temp2 = SAMPLE_NUMBER+(count-1)-i;
        }else{
            temp2 = (count-1)-i;
        }
        if(value[temp1]>=value[temp2])return;
    }
    valueFlag = 0;   // Continuous decrease
}

uint16_t DFRobot_Heartrate::analogGetRate(void)
{
    static uint8_t timeFlag;
    static unsigned long sampleTime[10];
    unsigned long valueTime_;
    minNumber(valueCount_);
    if(maxNumber(valueCount_)){
        nowTim = millis();
        uint32_t difTime =  nowTim - lastTim;
        lastTim = nowTim;

        if(difTime>300 || difTime<2000){
            sampleTime[timeFlag++] = difTime;
            if(timeFlag > 9)timeFlag=0;
        }
        if(0 == sampleTime[9]){
            Serial.println("Wait for valid data !");
            return(0);
        }

        uint32_t Arrange[10]={0};
        for(int i=0;i<10;i++){
            Arrange[i] = sampleTime[i];
        }
        uint32_t Arrange_=0;
        for(int i=9;i>0;i--){
            for(int j=0;j<i;j++){
                if(Arrange[j] > Arrange[j+1]){
                Arrange_ = Arrange[j];
                Arrange[j] = Arrange[j+1];
                Arrange[j+1] = Arrange_;
                }
            }
        }
        if((Arrange[7]-Arrange[3])>150){
            Serial.println("Wait for valid data !");
            return(0);
        }
        
        Arrange_ = 0;
        for(int i=3;i<=7;i++){
            Arrange_ += Arrange[i];
        }

        valueTime_ = 300000/Arrange_;   // 60*1000*(7-2)
        return((uint16_t)valueTime_);
    }
    return(0);
}

uint16_t DFRobot_Heartrate::digitalGetRate(void)
{

    static uint8_t timeFlag;
    static unsigned long sampleTime[10];
    unsigned long valueTime_;
    uint8_t count_;
    
    if(valueCount_){
        count_ = valueCount_-1;
    }else{
        count_ = SAMPLE_NUMBER-1;
    }
    if((value[valueCount_]>1000)&&(value[count_]<20)){
        nowTim = millis();
        uint32_t difTime =  nowTim - lastTim;
        lastTim = nowTim;
        
        if(difTime>300 || difTime<2000){
            sampleTime[timeFlag++] = difTime;
            if(timeFlag > 9)timeFlag=0;
        }       
        if(0 == sampleTime[9]){
            Serial.println("Wait for valid data !");
            return(0);
        }

        uint32_t Arrange[10]={0};
        for(int i=0;i<10;i++){
            Arrange[i] = sampleTime[i];
        }
        uint32_t Arrange_=0;
        for(int i=9;i>0;i--){
            for(int j=0;j<i;j++){
                if(Arrange[j] > Arrange[j+1]){
                Arrange_ = Arrange[j];
                Arrange[j] = Arrange[j+1];
                Arrange[j+1] = Arrange_;
                }
            }
        }
        if((Arrange[7]-Arrange[3])>120){
            Serial.println("Wait for valid data !");
            return(0);
        }

        Arrange_ = 0;
        for(int i=3;i<=7;i++){
            Arrange_ += Arrange[i];
        }

        valueTime_ = 300000/Arrange_;   // 60*1000*(7-2)
        return((uint16_t)valueTime_);
    }
    return(0);

}

uint16_t DFRobot_Heartrate::getRate(void)
{
    if(mode_ == DIGITAL_MODE) {
        return(digitalGetRate());
    } else {
        return(analogGetRate());
    }
}
