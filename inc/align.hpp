#include <align_config.hpp>
#include <stm32g4xx.h>

#ifndef ALIGN_HPP
#define ALIGN_HPP

#define ALIGN_BEGIN namespace Align {
#define ALIGN_END }


ALIGN_BEGIN // Start of Align Namespace


typedef enum {
    Input = (uint8_t) 0b00,
    Analog = (uint8_t) 0b11,
    Output = (uint8_t) 0b01,
    Alternate = (uint8_t) 0b10
} PinMode;

// TODO Find good values to configure PushPull and OpenDrain
typedef enum {
    PushPull = (uint8_t) 0b00,
    OpenDrain = (uint8_t) 0b01,
    PullUp = (uint8_t) 0b01,
    PullDown = (uint8_t) 0b10,
    Floating = (uint8_t) 0b00

} PinConfig;

class Pin {
    private:

        GPIO_TypeDef* pinReg;
        PinMode pinMode;
        PinConfig pinConfig;
        uint8_t pinIndex;
        bool isSet;
        

    public:
        Pin(GPIO_TypeDef*, uint8_t, PinMode, PinConfig);
        void toggle();
        void set(bool state);

};

typedef enum {
    HSI,
    HSE,
    PLL
} SysClockSource;

typedef enum {
    Div1 = 0b000,
    Div2 = 0b100,
    Div4 = 0b101,
    Div8 = 0b110,
    Div16 = 0b111
} APBPrescale;

typedef struct {
    bool hsi = true;
    bool hse = false;
    bool hse_bypass = false;
    APBPrescale apb1_prescaler = APBPrescale::Div1;
    APBPrescale apb2_prescaler = APBPrescale::Div1;
} RCC_Config;

class RCC_Controller {
    public:
        RCC_TypeDef* rccReg;
        RCC_Config rccCfg;
        uint32_t hsFreq;
        uint32_t sysclkFreq;
        RCC_Controller(RCC_TypeDef* rccReg, RCC_Config rccCfg);
        void enable_gpio();
        void delay_ms(uint32_t);
};

ALIGN_END
#endif ALIGN_HPP