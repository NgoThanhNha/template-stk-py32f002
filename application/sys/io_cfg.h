/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#ifndef __IO_CFG_H__
#define __IO_CFG_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

/*-----------------------------------------------------------------*/
/*                       led life io pin map                       */
/*-----------------------------------------------------------------*/
#define LED_LIFE_IO_PORT                (GPIOA)
#define LED_LIFE_IO_PIN                 (LL_GPIO_PIN_4) 
#define LED_LIFE_IO_CLOCK               (LL_IOP_GRP1_PERIPH_GPIOA)

/*-----------------------------------------------------------------*/
/*                         buttons pin map                         */
/*-----------------------------------------------------------------*/
#define BUTTON_UP_IO_PIN				(LL_GPIO_PIN_8)
#define BUTTON_UP_IO_PORT				(GPIOA)
#define BUTTON_UP_IO_CLOCK			    (LL_IOP_GRP1_PERIPH_GPIOA)

#define BUTTON_DOWN_IO_PIN				(LL_GPIO_PIN_0)
#define BUTTON_DOWN_IO_PORT				(GPIOB)
#define BUTTON_DOWN_IO_CLOCK			(LL_IOP_GRP1_PERIPH_GPIOB)

#define BUTTON_MODE_IO_PIN			    (LL_GPIO_PIN_5)
#define BUTTON_MODE_IO_PORT				(GPIOA)
#define BUTTON_MODE_IO_CLOCK			(LL_IOP_GRP1_PERIPH_GPIOA)


/*-----------------------------------------------------------------*/
/*                          console pin map                        */
/*-----------------------------------------------------------------*/
#define CONSOLE_USART_PORT              (USART1)
#define CONSOLE_GPIO_PORT               (GPIOA)
#define CONSOLE_BAUD_SPEED              (115200)
#define CONSOLE_USART_CLOCK             (LL_APB1_GRP2_PERIPH_USART1)
#define CONSOLE_GPIO_CLOCK              (LL_IOP_GRP1_PERIPH_GPIOA)

#define CONSOLE_TX_PIN                  (LL_GPIO_PIN_2)
#define CONSOLE_RX_PIN                  (LL_GPIO_PIN_3)
#define CONSOLE_AF                      (LL_GPIO_AF_1)

/*-----------------------------------------------------------------*/
/*                         ssd1306 pin map                         */
/*-----------------------------------------------------------------*/
#define SSD1306_CLK_IO_PORT             (GPIOA)
#define SSD1306_CLK_IO_PIN              (LL_GPIO_PIN_7)
#define SSD1306_CLK_IO_CLOCK            (LL_IOP_GRP1_PERIPH_GPIOA)

#define SSD1306_SDA_IO_PORT             (GPIOA)
#define SSD1306_SDA_IO_PIN              (LL_GPIO_PIN_6)
#define SSD1306_SDA_IO_CLOCK            (LL_IOP_GRP1_PERIPH_GPIOA)

/* led life functions */
extern void led_life_on();
extern void led_life_off();

/* button functions */
extern uint8_t button_up_read();
extern uint8_t button_down_read();
extern uint8_t button_mode_read();

/* usart functions */
extern void usart1_init();
extern void usart1_put_char(uint8_t _char);
extern void usart1_put_string(const char *str);

/* ssd 1306 io functions */
extern void ssd1306_clk_digital_write_low();
extern void ssd1306_clk_digital_write_high();
extern void ssd1306_data_digital_write_low();
extern void ssd1306_data_digital_write_high();

/* io init function */
extern void io_init();

#ifdef __cplusplus
}
#endif

#endif /* __IO_CFG_H__ */