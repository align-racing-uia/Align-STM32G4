#ifndef ALIGN_HPP
#define ALIGN_HPP

#include <cstdint>

// Simple failsafe
#if !defined (STM32G431xx) && !defined (STM32G441xx) && !defined (STM32G471xx) && \
    !defined (STM32G473xx) && !defined (STM32G474xx) && !defined (STM32G484xx) && \
    !defined (STM32GBK1CB) && !defined (STM32G491xx) && !defined (STM32G4A1xx) && \
    !defined (STM32G411xB) && !defined (STM32G411xC) && !defined (STM32G414xx)
  /* #define STM32G411xB */   /*!< STM32G411xB Devices */
  /* #define STM32G411xC */   /*!< STM32G411xC Devices */
  /* #define STM32G414xx */   /*!< STM32G414xx Devices */
// #define STM32G431xx  /*!< STM32G431xx Devices */
  /* #define STM32G441xx */   /*!< STM32G441xx Devices */
  /* #define STM32G471xx */   /*!< STM32G471xx Devices */
  /* #define STM32G473xx */   /*!< STM32G473xx Devices */
  /* #define STM32G483xx */   /*!< STM32G483xx Devices */
  /* #define STM32G474xx */   /*!< STM32G474xx Devices */
  /* #define STM32G484xx */   /*!< STM32G484xx Devices */
  /* #define STM32G491xx */   /*!< STM32G491xx Devices */
  /* #define STM32G4A1xx */   /*!< STM32G4A1xx Devices */
  /* #define STM32GBK1CB */   /*!< STM32GBK1CB Devices */
#endif

#include <stm32g4xx.h>
#include <stm32g4xx_hal.h>


namespace Align {
    void init();
}

#endif // ALIGN_HPP