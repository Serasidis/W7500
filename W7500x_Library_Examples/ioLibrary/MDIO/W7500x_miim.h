/*******************************************************************************************************************************************************
 * Copyright �� 2016 <WIZnet Co.,Ltd.> 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the ��Software��), 
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED ��AS IS��, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*********************************************************************************************************************************************************/
#ifndef __MIIM_H__ 
#define __MIIM_H__
#include "W7500x_gpio.h"

#define MDIO    GPIO_Pin_14
#define MDC     GPIO_Pin_15

//#define PHY_ADDR_RLT8201 0x1F //AD[4:0] <= 0x1F (0x1F)
#define PHY_ADDR_IP101G 0x07 // //AD[3:0] <= 0x0F (0x07)
#define PHY_ADDR PHY_ADDR_IP101G

#define SVAL 0x2 //right shift val = 2 
#define PHYREG_CONTROL  0x0//Control Register address (Contorl basic register)
#define PHYREG_STATUS   0x1//Status Register address (Status basic register)
#define CNTL_DUPLEX     (0x01ul<< 7)
#define CNTL_AUTONEGO   (0x01ul<<11)
#define CNTL_SPEED      (0x01ul<<12)
typedef enum
{
    HalfDuplex10 = 0x0000,
    FullDuplex10 = CNTL_DUPLEX,
    AUTONEGO = CNTL_AUTONEGO,
    HalfDuplex100 = CNTL_SPEED,
    FullDuplex100 = (CNTL_SPEED|CNTL_DUPLEX)
}SetLink_Type;

#define IS_SETLINK_TYPE(Mode) (((Mode)==HalfDuplex10) || ((Mode)==FullDuplex10) || ((Mode)==AUTONEGO) || \
                               ((Mode)==HalfDuplex100) || ((Mode)==FullDuplex100))

void mdio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_MDC, uint16_t GPIO_Pin_MDIO);
void mdio_write(GPIO_TypeDef* GPIOx, uint32_t PhyRegAddr, uint32_t val);
uint32_t mdio_read(GPIO_TypeDef* GPIOx, uint32_t PhyRegAddr);
uint32_t link(void);
void set_link(SetLink_Type mode);


#endif
