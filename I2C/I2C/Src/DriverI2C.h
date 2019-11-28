#ifndef __i2c_H
#define __i2c_H

#include "main.h"

void Read_Register16(I2C_TypeDef *I2Cx, uint8_t reg, uint16_t *data);

#endif
