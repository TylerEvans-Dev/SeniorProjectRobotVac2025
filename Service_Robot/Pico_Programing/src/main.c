
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>

const char hello[13] = "hello world ";
const char name[4] = "robo";
const int HIGH =1;
const int LOW =0;


void task(void){
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

    }
}




int main(){
    //this inits the stdio
    stdio_init_all();

    //do not worry about printf as the function will still work
    cyw43_arch_init();


    task();




    return 0;
}
