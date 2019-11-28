#include "LTC2944_I2C.h"

uint8_t Read_Jauge_Status(){
	uint8_t data = 0x00 ;
	LL_I2C_HandleTransfer(I2C3, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 1, LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_START_WRITE);
	while(!LL_I2C_IsActiveFlag_TC(I2C3)){
		if(LL_I2C_IsActiveFlag_TXIS(I2C3))
		{
			LL_I2C_TransmitData8(I2C3, 0x00);
		}
	}
	while(!LL_I2C_IsActiveFlag_TXIS(I2C3)){}	
	LL_I2C_HandleTransfer(I2C3, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 1, I2C_CR2_AUTOEND, LL_I2C_GENERATE_RESTART_7BIT_READ);
  while(!LL_I2C_IsActiveFlag_STOP(I2C3))
  {
    if(LL_I2C_IsActiveFlag_RXNE(I2C3)){
			data = LL_I2C_ReceiveData8(I2C3);
		}	
	}	
	LL_I2C_ClearFlag_STOP(I2C3);	
}

void Read_Jauge_Voltage(uint16_t *data){
	LL_I2C_HandleTransfer(I2C3, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 1, LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_START_WRITE);
	while(!LL_I2C_IsActiveFlag_TC(I2C3)){
		if(LL_I2C_IsActiveFlag_TXIS(I2C3))
		{
			LL_I2C_TransmitData8(I2C3, 0x08);
		}
	}
	while(!LL_I2C_IsActiveFlag_TXIS(I2C3)){}	
	LL_I2C_HandleTransfer(I2C3, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 2, I2C_CR2_AUTOEND, LL_I2C_GENERATE_RESTART_7BIT_READ);
  while(!LL_I2C_IsActiveFlag_STOP(I2C3))
  {
    if(LL_I2C_IsActiveFlag_RXNE(I2C3)){
			*data++ = LL_I2C_ReceiveData8(I2C3);
		}	
	}	
	LL_I2C_ClearFlag_STOP(I2C3);	
}