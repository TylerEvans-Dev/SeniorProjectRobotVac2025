
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>

const char hello[13] = "hello world ";
const char name[4] = "robo";


void task(void){
    int i =0;
    while(1){
        i += 1;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(100);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(100);

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

int main(){
    //this inits the stdio
    stdio_init_all();

    //do not worry about printf as the function will still work
    cyw43_arch_init();

    int i =0;

    task();




    return 0;
}
