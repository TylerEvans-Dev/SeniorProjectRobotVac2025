
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>

const char hello[13] = "hello world ";
const char name[4] = "robo";

const int dir1 = 20;
const int dir2 = 18;
const int step1 = 21;
const int step2 = 19;



void task(void){
    int i =0;
    while(1){
        i += 1;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(700);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(700);

    }
}



void pwm(void){
    //inits the gpio for use
    gpio_init(1);
    gpio_init(2);
    gpio_init(3);
    //sets the three them
    gpio_set_function(1, GPIO_FUNC_PWM);
    gpio_set_function(2, GPIO_FUNC_PWM);
    gpio_set_function(3, GPIO_FUNC_PWM);


}
void blink_loop(){
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(700);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(700);
}
void motorMov1(){


    gpio_put(dir1, 1);
    gpio_put(dir2, 1);

    for(int j =0; j< 400;j++){
        gpio_put(step1, 1);
        sleep_us(700);
        gpio_put(step1, 0);
        sleep_us(700);
        blink_loop();
    }

}
void motorMov2(){
    gpio_init(dir2);
    gpio_init(step2);
    gpio_put(dir2, 1);

    for(int j =0; j< 400;j++){

        gpio_put(step2, 2%j);
    }
}

int main(){
    //this inits the stdio
    stdio_init_all();

    //do not worry about printf as the function will still work
    cyw43_arch_init();
    gpio_init(dir1);
    gpio_init(step1);
    gpio_init(dir2);
    gpio_init(step2);

    int i =0;

    //task();
    while(1){
        motorMov1();
        sleep_ms(100);
        //motorMov2();
        //sleep_ms(1000);
    }
    //task();


    return 0;
}
