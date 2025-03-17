
#include <hardware/gpio.h>
#include <hardware/structs/io_bank0.h>
#include <pico/cyw43_arch.h>
#include <pico/time.h>

const char hello[13] = "hello world ";
const char name[4] = "robo";
const int LOW = 0;
const int HIGH = 1;

const int dir1 = 20;
const int dir2 = 18;
const int step1 = 21;
const int step2 = 19;

const int dc1 = 1;
const int dc2 = 2;
const int dc3 = 3;
const int dc4 = 4;



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
    gpio_put(dir2, 0);

    for(int j =0; j< 400;j++){
        gpio_put(step1, 1);
        gpio_put(step2, 1);
        sleep_ms(2);
        gpio_put(step1, 0);
        gpio_put(step2, 0);
        sleep_ms(2);
        //blink_loop();
    }

}
void motorMovback(){


    gpio_put(dir1, 0);
    gpio_put(dir2, 1);

    for(int j =0; j< 400;j++){
        gpio_put(step1, 1);
        gpio_put(step2, 1);
        sleep_ms(2);
        gpio_put(step1, 0);
        gpio_put(step2, 0);
        sleep_ms(2);
        //blink_loop();
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

void initDCM(){
    //this is for the gpio of the L298
    gpio_init(dc1);
    gpio_init(dc2);
    gpio_init(dc3);
    gpio_init(dc4);
    gpio_set_dir(dc1, GPIO_OUT);
    gpio_set_dir(dc2, GPIO_OUT);
    gpio_set_dir(dc3, GPIO_OUT);
    gpio_set_dir(dc4, GPIO_OUT);
}

void DC_forward_12(){
    //
    gpio_put(dc1, HIGH);
    gpio_put(dc2, LOW);
    //gpio_put(dc3, HIGH);
    //gpio_put(dc4, LOW);
}
void DC_backward_12(){
    gpio_put(dc1, LOW);
    gpio_put(dc2, HIGH);
    //gpio_put(dc3, LOW);
    //gpio_put(dc4, HIGH);
}

void DC_forward_34(){
    gpio_put(dc3, HIGH);
    gpio_put(dc4, LOW);
}

void DC_backward_34(){
    gpio_put(dc3, LOW);
    gpio_put(dc4, HIGH);
}

void READ12(){

}

void READ34(){

}

void DO_YA_THING(){
    sleep_ms(5000);
    printf("going forward\n");
    //DC_forward_12();
    DC_forward_34();
    sleep_ms(1000);
    printf("going backwords\n");
    //DC_backward_12();
    DC_backward_34();
    sleep_ms(1000);
    printf("completed motion\n");

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
    gpio_set_dir(dir1, GPIO_OUT);
    gpio_set_dir(dir2, GPIO_OUT);
    gpio_set_dir(step1, GPIO_OUT);
    gpio_set_dir(step2, GPIO_OUT);
    //this inits the dc motor.
    initDCM();

    int i =0;

    //task();
    while(1){
        //motorMov1();
        //blink_loop();
        //motorMovback();
        //sleep_ms(100);
        //motorMov2();
        //sleep_ms(1000);
        DO_YA_THING();
    }
    //task();


    return 0;
}
