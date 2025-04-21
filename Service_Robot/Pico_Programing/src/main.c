
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>
#include "functions.c"

#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE


int main(){
    //this inits the stdio this is a lib function
    //it will run errors typically do not worry about them.
    stdio_init_all();
    cyw43_arch_init();
    initPin();
    blink_task();





    return 0;
}
