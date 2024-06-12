/**
 ******************************************************************************
 * @author: Nark
 * @date:   29/05/2024
 ******************************************************************************
**/

#include "io_cfg.h"

#include "py32f002ax5.h"
#include "py32f0xx_ll_gpio.h"
#include "py32f0xx_ll_rcc.h"
#include "py32f0xx_ll_bus.h"
#include "py32f0xx_ll_usart.h"

#include "sys_ctrl.h"
#include "console.h"

void led_life_init() {
    LL_GPIO_InitTypeDef GPIO_InitStructure;

    LL_IOP_GRP1_EnableClock(LED_LIFE_IO_CLOCK);

    GPIO_InitStructure.Pin = LED_LIFE_IO_PIN;
    GPIO_InitStructure.Mode = LL_GPIO_MODE_OUTPUT; 
    GPIO_InitStructure.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStructure.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(LED_LIFE_IO_PORT, &GPIO_InitStructure);
}

void led_life_on() {
    LL_GPIO_ResetOutputPin(LED_LIFE_IO_PORT, LED_LIFE_IO_PIN);
}

void led_life_off() {
    LL_GPIO_SetOutputPin(LED_LIFE_IO_PORT, LED_LIFE_IO_PIN);
}

void usart1_init() {
    LL_APB1_GRP2_EnableClock(CONSOLE_USART_CLOCK);

    /* USART Init */
    LL_USART_SetBaudRate(CONSOLE_USART_PORT, SystemCoreClock, LL_USART_OVERSAMPLING_16, CONSOLE_BAUD_SPEED);
    LL_USART_SetDataWidth(CONSOLE_USART_PORT, LL_USART_DATAWIDTH_8B);
    LL_USART_SetStopBitsLength(CONSOLE_USART_PORT, LL_USART_STOPBITS_1);
    LL_USART_SetParity(CONSOLE_USART_PORT, LL_USART_PARITY_NONE);
    LL_USART_SetHWFlowCtrl(CONSOLE_USART_PORT, LL_USART_HWCONTROL_NONE);
    LL_USART_SetTransferDirection(CONSOLE_USART_PORT, LL_USART_DIRECTION_TX_RX);
    LL_USART_Enable(CONSOLE_USART_PORT);
    LL_USART_ClearFlag_TC(CONSOLE_USART_PORT);

    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

    LL_GPIO_SetPinMode(CONSOLE_GPIO_PORT, CONSOLE_TX_PIN, LL_GPIO_MODE_ALTERNATE);
    LL_GPIO_SetPinSpeed(CONSOLE_GPIO_PORT, CONSOLE_TX_PIN, LL_GPIO_SPEED_FREQ_VERY_HIGH);
    LL_GPIO_SetPinPull(CONSOLE_GPIO_PORT, CONSOLE_TX_PIN, LL_GPIO_PULL_UP);
    LL_GPIO_SetAFPin_0_7(CONSOLE_GPIO_PORT, CONSOLE_TX_PIN, CONSOLE_AF);

    LL_GPIO_SetPinMode(CONSOLE_GPIO_PORT, CONSOLE_RX_PIN, LL_GPIO_MODE_ALTERNATE);
    LL_GPIO_SetPinSpeed(CONSOLE_GPIO_PORT, CONSOLE_RX_PIN, LL_GPIO_SPEED_FREQ_VERY_HIGH);
    LL_GPIO_SetPinPull(CONSOLE_GPIO_PORT, CONSOLE_RX_PIN, LL_GPIO_PULL_UP);
    LL_GPIO_SetAFPin_0_7(CONSOLE_GPIO_PORT, CONSOLE_RX_PIN, CONSOLE_AF);
}

void usart1_put_char(uint8_t _char) {
    while(LL_USART_IsActiveFlag_TXE(CONSOLE_USART_PORT) == RESET);

    LL_USART_TransmitData8(CONSOLE_USART_PORT, _char);

    while(LL_USART_IsActiveFlag_TC(CONSOLE_USART_PORT) == RESET);
}

void ssd1306_clk_init() {
    LL_GPIO_InitTypeDef GPIO_InitStructure;

    LL_IOP_GRP1_EnableClock(SSD1306_CLK_IO_CLOCK);

    GPIO_InitStructure.Pin = SSD1306_CLK_IO_PIN;
    GPIO_InitStructure.Mode = LL_GPIO_MODE_OUTPUT; 
    GPIO_InitStructure.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStructure.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(SSD1306_CLK_IO_PORT, &GPIO_InitStructure); 
}

void ssd1306_sda_init() {
    LL_GPIO_InitTypeDef GPIO_InitStructure;

    LL_IOP_GRP1_EnableClock(SSD1306_SDA_IO_CLOCK);

    GPIO_InitStructure.Pin = SSD1306_SDA_IO_PIN;
    GPIO_InitStructure.Mode = LL_GPIO_MODE_OUTPUT; 
    GPIO_InitStructure.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStructure.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(SSD1306_SDA_IO_PORT, &GPIO_InitStructure); 
}

void ssd1306_clk_digital_write_low() {
	LL_GPIO_ResetOutputPin(SSD1306_CLK_IO_PORT, SSD1306_CLK_IO_PIN);
}

void ssd1306_clk_digital_write_high() {
	LL_GPIO_SetOutputPin(SSD1306_CLK_IO_PORT, SSD1306_CLK_IO_PIN);
}

void ssd1306_data_digital_write_low() {
	LL_GPIO_ResetOutputPin(SSD1306_SDA_IO_PORT, SSD1306_SDA_IO_PIN);
}

void ssd1306_data_digital_write_high() {
	LL_GPIO_SetOutputPin(SSD1306_SDA_IO_PORT, SSD1306_SDA_IO_PIN);
}

void io_init() {
    /* led life */
    led_life_init();
    
    /* ssd1306 io init */
    ssd1306_clk_init();
    ssd1306_sda_init();
}


