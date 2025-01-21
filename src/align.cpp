#include "align.hpp"



void Align::init(HSE_Config hse_config, bool hse_bypass){
    HAL_Init();
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_PLLInitTypeDef RCC_PLLInitStruct = {0};

    // Default settings over all configurations
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;

    // Some common settings for all the PLL configurations
    RCC_PLLInitStruct.PLLState = RCC_PLL_ON;

    // Here the differences occur
    if(hse_config == HSE_16MHz){
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_PLLInitStruct.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_PLLInitStruct.PLLM = RCC_PLLM_DIV4;
        RCC_PLLInitStruct.PLLN = 85;
        RCC_PLLInitStruct.PLLR = RCC_PLLR_DIV2;
        RCC_PLLInitStruct.PLLQ = RCC_PLLQ_DIV2;
        RCC_PLLInitStruct.PLLP = RCC_PLLP_DIV2;

    }else if(hse_config == HSE_20MHz){
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_PLLInitStruct.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_PLLInitStruct.PLLM = RCC_PLLM_DIV5;
        RCC_PLLInitStruct.PLLN = 85;
        RCC_PLLInitStruct.PLLR = RCC_PLLR_DIV2;
        RCC_PLLInitStruct.PLLQ = RCC_PLLQ_DIV2;
        RCC_PLLInitStruct.PLLP = RCC_PLLP_DIV2;
    }else{
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
        RCC_PLLInitStruct.PLLSource = RCC_PLLSOURCE_HSI;
        RCC_PLLInitStruct.PLLM = RCC_PLLM_DIV4;
        RCC_PLLInitStruct.PLLN = 85;
        RCC_PLLInitStruct.PLLR = RCC_PLLR_DIV2;
        RCC_PLLInitStruct.PLLQ = RCC_PLLQ_DIV2;
        RCC_PLLInitStruct.PLLP = RCC_PLLP_DIV2;
        
    }

    if(RCC_OscInitStruct.OscillatorType == RCC_OSCILLATORTYPE_HSE && hse_bypass){
        RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;        
    }
        
    RCC_OscInitStruct.PLL = RCC_PLLInitStruct;

    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);


    // Enable GPIO clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    

}