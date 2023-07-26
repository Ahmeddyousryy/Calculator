/*
 * BitMath.h
 *
 *  Created on: Sep 6, 2022
 *      Author: HP
 */

#ifndef BITMATH_H_
#define BITMATH_H_
#include<util\/delay.h>
#define SET_BIT(REG,BIT)                           REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)                           REG &=~(1<<BIT)
#define GET_BIT(REG,BIT)                          ((REG >> BIT) & 1)
#define TOG_BIT(REG,BIT)                           REG^=(1<<BIT)

#endif /* BITMATH_H_ */
