
/*
 bme280.h
 Created on: Dec 22, 2024
 */

#ifndef INC_BME280_H_
#define INC_BME280_H_

#include "main.h"

#define BME280_DEVICE_ADDRESS  0xEC

#define BME280_ID              0xD0
#define BME280_RESET           0xE0
#define BME280_CTRL_HUM        0xF2
#define BME280_STATUS          0xF3
#define BME280_CTRL_MEAS  	   0xF4
#define BME280_CONFIG     	   0xF5
#define BME280_PRESS_MSB  	   0xF7
#define BME280_PRESS_LSB  	   0xF8
#define BME280_PRESS_XLSB 	   0xF9
#define BME280_TEMP_MSB   	   0xFA
#define BME280_TEMP_LSB   	   0xFB
#define BME280_TEMP_XLSB  	   0xFC
#define BME280_HUM_MSB    	   0xFD
#define BME280_HUM_LSB    	   0xFE
#define BME280_CALIB00         0x88
#define BME280_CALIB26         0xE1

#define TIMEOUT                1000

typedef enum{
	READ_FAIL = 0,
	READ_SUCCESS = 1,
}BME280ReadStatus;

typedef enum{
	Write_FAIL = 0,
	Write_SUCCESS = 1,
}BME280WriteStatus;

typedef enum{
	INIT_FAIL = 0,
	INIT_SUCCESS = 1,
}BME280InitStatus;



int BME280_ScanDeviceID(I2C_HandleTypeDef *hi2cx);

BME280ReadStatus BME280_ReadRegisterData(I2C_HandleTypeDef *hi2cx, uint16_t registerAddress, uint16_t sizeofData, uint8_t *dataBuffer);

//BME280ReadStatus BME280_ReadRegister16Data(I2C_HandleTypeDef *hi2cx, uint16_t registerAddress, uint16_t sizeofData, uint16_t *dataBuffer);

BME280WriteStatus BME280_WriteRegisterData(I2C_HandleTypeDef *hi2cx, uint16_t registerAddress, uint16_t value);

BME280InitStatus BME280_Init(I2C_HandleTypeDef *hi2cx);


#endif /* INC_BME280_H_ */