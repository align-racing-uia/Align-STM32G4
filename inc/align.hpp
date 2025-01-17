#ifndef ALIGN_HPP
#define ALIGN_HPP

#include <align_config.hpp>
#include <cstdint>

#define STM32G431xx   // Temporary to test the code
namespace LL {
    #define USE_FULL_LL_DRIVER
    #include <stm32g4xx_ll_gpio.h>
}


#define ALIGN_BEGIN namespace Align {
#define ALIGN_END }


ALIGN_BEGIN // Start of Align Namespace

typedef enum {
    A,
    B,
    C,
    D,
    E
} GPIO;

class Pin {
    
    public:
    Pin(GPIO gpio, uint8_t pinIdx){
        GPIO_InitStruct.Pin = 1 << pinIdx;
        GPIO_InitStruct.Mode = mode;
        GPIO_InitStruct.OutputType = output;
        GPIO_InitStruct.Pull = pupd;
        GPIO_InitStruct.Speed = LL::LL_GPIO_SPEED_FREQ_MEDIUM;
        LL::LL_GPIO_Init((GPIO_TypeDef*)gpio, &GPIO_InitStruct);
        
    }

}


ALIGN_END
#endif ALIGN_HPP