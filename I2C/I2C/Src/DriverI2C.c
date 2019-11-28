#include "DriverI2C.h"

void Read_Register16(I2C_TypeDef *I2Cx, uint8_t reg, uint16_t *data){
	LL_I2C_HandleTransfer(I2Cx, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 1, LL_I2C_MODE_SOFTEND, LL_I2C_GENERATE_START_WRITE);
	while(!LL_I2C_IsActiveFlag_TC(I2Cx)){
		if(LL_I2C_IsActiveFlag_TXIS(I2Cx))
		{
			LL_I2C_TransmitData8(I2Cx, reg);
		}
	}
	LL_I2C_HandleTransfer(I2Cx, (0x64)<<1, LL_I2C_ADDRSLAVE_7BIT, 2, I2C_CR2_AUTOEND, LL_I2C_GENERATE_RESTART_7BIT_READ);
  while(!LL_I2C_IsActiveFlag_STOP(I2Cx))
  {
    if(LL_I2C_IsActiveFlag_RXNE(I2Cx)){
			*data++ = LL_I2C_ReceiveData8(I2Cx);
		}	
	}	
	LL_I2C_ClearFlag_STOP(I2Cx);	
}
