#include "align.hpp"

void Align::init(){
    HAL_Init();
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.HSI48State = RCC_HSI48_OFF;
    
    RCC_PLLInitTypeDef RCC_PLLInitStruct = {0};
    RCC_PLLInitStruct.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_PLLInitStruct.PLLM = 1;
    RCC_PLLInitStruct.PLLN = 20;
    RCC_PLLInitStruct.PLLP = RCC_PLLP_DIV7;
    RCC_PLLInitStruct.PLLQ = RCC_PLLQ_DIV2;
    RCC_PLLInitStruct.PLLR = RCC_PLLR_DIV2;
    RCC_PLLInitStruct.PLLState = RCC_PLL_ON;


    RCC_OscInitStruct.PLL = RCC_PLLInitStruct;

    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
}