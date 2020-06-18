
#include <devices.h>
#include "led-control.h"
#include <stdio.h>
#include "task.h"
#include "../kendryte-freertos-sdk/lib/bsp/include/sleep.h"


handle_t gio;


void ledControl_init(  ) {

    gio = io_open("/dev/gpio0");
    configASSERT(gio);

    
    gpio_set_drive_mode(gio, 1, GPIO_DM_OUTPUT);
    gpio_set_pin_value(gio, 1, 1 );      
    

    gpio_set_drive_mode(gio, 2, GPIO_DM_OUTPUT);
    gpio_set_pin_value(gio, 2, 1 );
    
    gpio_set_drive_mode(gio, 3, GPIO_DM_OUTPUT); 
    gpio_set_pin_value(gio, 3, 1 );

}


void ledControl_task( ) {

    static int b = 0;
    static int g = 1;
    static int r = 1;

    for(;;) 
    {


        gpio_set_pin_value(gio, 1, b = !b );
        gpio_set_pin_value(gio, 2, g = !g );
        gpio_set_pin_value(gio, 3, r = !r );
        
        puts("Hello World\n\r");
        vTaskDelay( 40 );

        
    }
}