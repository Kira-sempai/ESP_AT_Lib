/**
 * \file            lwesp_ll_stm32f205vg_swk.c
 * \brief           Low-level communication with ESP device for STM32F429ZI-Nucleo using DMA
 */

/*
 * Default UART configuration is:
 *
 * UART:                USART2
 * STM32 TX (ESP RX):   GPIOD, GPIO_PIN_5
 * STM32 RX (ESP TX):   GPIOD, GPIO_PIN_6
 * RESET:               GPIOD, GPIO_PIN_10
 * GPIO0:               GPIOD, GPIO_PIN_4
 * GPIO2:               GPIOD, GPIO_PIN_11
 * CH_PD:               GPIOD, GPIO_PIN_7
 *
 * USART_DMA:           DMA1
 * USART_DMA_STREAM:    DMA_STREAM_5
 * USART_DMA_CHANNEL:   DMA_CHANNEL_4
 */

#if !__DOXYGEN__

#include <hardware/mcu.h>

#include <drivers/mcu/stm32f2xx_hal_driver/Inc/stm32f2xx_ll_dma.h>
#include <drivers/mcu/stm32f2xx_hal_driver/Inc/stm32f2xx_ll_usart.h>
#include <drivers/mcu/stm32f2xx_hal_driver/Inc/stm32f2xx_ll_gpio.h>
#include <drivers/mcu/stm32f2xx_hal_driver/Inc/stm32f2xx_ll_bus.h>


/* USART */
#define LWESP_USART                           USART2
#define LWESP_USART_CLK                       LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2)
#define LWESP_USART_IRQ                       USART2_IRQn
#define LWESP_USART_IRQHANDLER                USART2_IRQHandler
#define LWESP_USART_RDR_NAME                  DR

/* DMA settings */
#define LWESP_USART_DMA                       DMA1
#define LWESP_USART_DMA_CLK                   LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1)
#define LWESP_USART_DMA_RX_STREAM             LL_DMA_STREAM_5
#define LWESP_USART_DMA_RX_CH                 LL_DMA_CHANNEL_4
#define LWESP_USART_DMA_RX_IRQ                DMA1_Stream5_IRQn
#define LWESP_USART_DMA_RX_IRQHANDLER         DMA1_Stream5_IRQHandler

/* DMA flags management */
#define LWESP_USART_DMA_RX_IS_TC              LL_DMA_IsActiveFlag_TC5(LWESP_USART_DMA)
#define LWESP_USART_DMA_RX_IS_HT              LL_DMA_IsActiveFlag_HT5(LWESP_USART_DMA)
#define LWESP_USART_DMA_RX_CLEAR_TC           LL_DMA_ClearFlag_TC5(LWESP_USART_DMA)
#define LWESP_USART_DMA_RX_CLEAR_HT           LL_DMA_ClearFlag_HT5(LWESP_USART_DMA)

/* USART TX PIN */
#define LWESP_USART_TX_PORT_CLK               LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_USART_TX_PORT                   GPIOD
#define LWESP_USART_TX_PIN                    LL_GPIO_PIN_5
#define LWESP_USART_TX_PIN_AF                 LL_GPIO_AF_7

/* USART RX PIN */
#define LWESP_USART_RX_PORT_CLK               LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_USART_RX_PORT                   GPIOD
#define LWESP_USART_RX_PIN                    LL_GPIO_PIN_6
#define LWESP_USART_RX_PIN_AF                 LL_GPIO_AF_7

/* RESET PIN */
#define LWESP_RESET_PORT_CLK                  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_RESET_PORT                      GPIOD
#define LWESP_RESET_PIN                       LL_GPIO_PIN_10

/* GPIO0 PIN */ //programmable output
#define LWESP_GPIO0_PORT_CLK                  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_GPIO0_PORT                      GPIOD
#define LWESP_GPIO0_PIN                       LL_GPIO_PIN_4

/* GPIO2 PIN */  //programmable output, also use for boot options
#define LWESP_GPIO2_PORT_CLK                  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_GPIO2_PORT                      GPIOD
#define LWESP_GPIO2_PIN                       LL_GPIO_PIN_11

/* CH_PD PIN */ //EN? power on/off
#define LWESP_CH_PD_PORT_CLK                  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD)
#define LWESP_CH_PD_PORT                      GPIOD
#define LWESP_CH_PD_PIN                       LL_GPIO_PIN_7

/* Include STM32 generic driver */
#include "../system/lwesp_ll_stm32.c"

#endif /* !__DOXYGEN__ */
