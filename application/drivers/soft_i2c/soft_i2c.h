/**
 ******************************************************************************
 * @author: Nark
 * @date:   17/05/2024
 ******************************************************************************
**/

#ifndef __SOFT_I2C_H__
#define __SOFT_I2C_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/* software i2c protocol function prototype */
extern void i2c_start();
extern void i2c_stop();
extern void i2c_write_byte(uint8_t u8data);

#ifdef __cplusplus
}
#endif

#endif /* __SOFT_I2C_H__ */