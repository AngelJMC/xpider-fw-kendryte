/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <devices.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "../kendryte-freertos-sdk/lib/bsp/include/sleep.h"
#include "project_cfg.h"

#include "led-control.h"


int main()
{

    ledControl_init(  );

    
    xTaskCreate(ledControl_task, "ledControl", 512, NULL, 1, NULL);

    for(;;);

    return 0;
}
