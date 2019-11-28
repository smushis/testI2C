#ifndef __LTC_H
#define __LTC_H

#include "main.h"
#include "DriverI2c.h"

void Refresh_register(void);
void CheckControl_register(void);
void Read_Jauge_Courant(uint16_t *data);




#endif
