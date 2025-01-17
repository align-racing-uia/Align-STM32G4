#ifndef ALIGN_HPP
#define ALIGN_HPP

#include <cstdint>

#define STM32G431xx   // Temporary to test the code
namespace LL {
    #define USE_FULL_LL_DRIVER
    #include <stm32g4xx_ll_gpio.h>
}

namespace HAL {
    #include <stm32g4xx_hal.h>
}


namespace Align {
    void init();
}

#endif ALIGN_HPP