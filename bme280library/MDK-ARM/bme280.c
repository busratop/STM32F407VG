/*
 * bme280.c
 * Created on: Dec 22, 2024
 */

#include "bme280.h"

int BME280_ScanDeviceID(I2C_HandleTypeDef *hi2cx){
	
		for (uint8_t address = 0; address < 255; address++) {
		if (HAL_I2C_IsDeviceReady(hi2cx, address, 1, TIMEOUT) == HAL_OK) {
			return address;
		}
	}

	return -1; // error

}

static BME280ReadStatus BME280_ReadRegisterData(I2C_HandleTypeDef *hi2cx,
		uint16_t registerAddress, uint16_t sizeofData, uint8_t *dataBuffer) {

	if (HAL_I2C_Mem_Read(hi2cx, BME280_DEVICE_ADDRESS, registerAddress, 1,
			dataBuffer, sizeofData, TIMEOUT) == HAL_OK) {
		return READ_SUCCESS;
	}
	return READ_FAIL;
}
		
static BME280WriteStatus BME280_WriteRegisterData(I2C_HandleTypeDef *hi2cx,
		uint16_t registerAddress, uint16_t value) {

	uint8_t data[2] = { 0 };
	data[0] = registerAddress;
	data[1] = value;

	if (HAL_I2C_Master_Transmit(hi2cx, BME280_DEVICE_ADDRESS, data,
			sizeof(data), TIMEOUT) == HAL_OK) {
		return Write_SUCCESS;
	}

	return Write_FAIL;

}