#pragma once
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>
#include "consts.h"

//this funciton inits all pins in use on the device
void initPin(){
    //RX TX pins
    gpio_init(TX);
    gpio_init(RX);
    gpio_set_function(TX, GPIO_FUNC_UART);
    gpio_set_function(RX, GPIO_FUNC_UART);

    //Motor pins
    gpio_init(M1);
    gpio_init(M2);
    gpio_init(M3);
    gpio_init(M4);
    gpio_init(M5);
    gpio_init(M6);
    gpio_init(M7);
    gpio_init(M8);
    gpio_set_function(M1, GPIO_FUNC_PWM);
    gpio_set_function(M2, GPIO_FUNC_PWM);
    gpio_set_function(M3, GPIO_FUNC_PWM);
    gpio_set_function(M4, GPIO_FUNC_PWM);
    gpio_set_function(M5, GPIO_FUNC_PWM);
    gpio_set_function(M6, GPIO_FUNC_PWM);
    gpio_set_function(M7, GPIO_FUNC_PWM);
    gpio_set_function(M8, GPIO_FUNC_PWM);

    //encoder pins
    gpio_init(EN1);
    gpio_init(EN2);
    gpio_init(EN3);
    gpio_init(EN4);
    gpio_set_dir(EN1, GPIO_IN);
    gpio_set_dir(EN2, GPIO_IN);
    gpio_set_dir(EN3, GPIO_IN);
    gpio_set_dir(EN4, GPIO_IN);
    gpio_pull_down(EN1);
    gpio_pull_down(EN2);
    gpio_pull_down(EN3);
    gpio_pull_down(EN4);


    //I2C pins
    gpio_init(SDA);
    gpio_init(SCL);
    gpio_set_function(SDA, GPIO_FUNC_I2C);
    gpio_set_function(SCL, GPIO_FUNC_I2C);
    gpio_pull_up(SDA);
    gpio_pull_up(SCL);

    //mutiplexer pins
    gpio_init(MU1);
    gpio_init(MU2);
    gpio_init(MU3);
    gpio_set_dir(MU1, GPIO_OUT);
    gpio_set_dir(MU2, GPIO_OUT);
    gpio_set_dir(MU3, GPIO_OUT);

}

//this is the default blinky and is used for debug
void blink_task(void){
    int i =0;
    gpio_init(21);
    gpio_set_dir(21, GPIO_OUT);


    while(1){
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        gpio_put(21, HIGH);
        sleep_ms(1000);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        gpio_put(21, LOW);
        sleep_ms(1000);
        vTaskDelay(1000);

    }

}
