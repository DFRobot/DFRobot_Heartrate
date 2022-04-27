/*!
 * @file  DFRobot_Heartrate.h
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
#ifndef __DFRobot_HEARTRATE__H
#define __DFRobot_HEARTRATE__H

#include <Arduino.h>

// #define ENABLE_DBG   //!< Open this macro and you can see the details of the program
#ifdef ENABLE_DBG
  #define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
  #define DBG(...)
#endif

#define ANALOG_MODE 0
#define DIGITAL_MODE 1

#define SAMPLE_NUMBER 100

class DFRobot_Heartrate
{
public:

    /**
     * @fn DFRobot_Heartrate
     * @brief Constructor
     * @param mode - ANALOG_MODE, DIGITAL_MODE
     * @return None
     */
    DFRobot_Heartrate(char mode) { mode_ = mode; }

    /**
     * @fn getRate
     * @brief Get heart rate value
     * @n Sample ten times in a row beating heart rate value is computed
     * @return Rate
     */
    uint16_t getRate(void);

    /**
     * @fn getCnt
     * @brief Get the current location
     * @return Current location
     */
    uint8_t getCnt(void);

    /**
     * @fn getValue
     * @brief Get a Sample values
     * @param pin - Communication pins
     * @return Value
     */
    uint16_t getValue(uint8_t pin);

protected:

    /**
     * @fn maxNumber
     * @brief Points to a valid node of the wave rise
     * @n When the sampling point value increased 4 times in a row, considered to be a heartbeat
     * @param count - current location count
     * @return 0 or 1
     */
    char maxNumber(uint8_t count);

    /**
     * @fn minNumber
     * @brief Waveform down processing
     * @n When the sample values decreased four times in a row, clear the heartbeat
     * @param count - current location count
     * @return None
     */
    void minNumber(uint8_t count);

    /**
     * @fn analogGetRate
     * @brief Get heart rate value
     * @n Sample ten times in a row beating heart rate value is computed
     * @return Analog rate
     */
    uint16_t analogGetRate(void);

    /**
     * @fn digitalGetRate
     * @brief Get heart rate value
     * @n Sample ten times in a row beating heart rate value is computed
     * @return Digital rate
     */
    uint16_t digitalGetRate(void);

private:

    uint8_t mode_;
    uint8_t valueCount_=255;
    uint8_t valueFlag;
    uint32_t nowTim=0, lastTim=0;

};

#endif
