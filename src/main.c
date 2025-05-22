/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Esteban Volentini <evolentini@herrera.unt.edu.ar>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include "digital.h"
#include "chip.h"
#include "board.h"
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

int main(void) {

    int divisor = 0;

    BoardOutputInit();
    BoardInputInit();
    
    digital_output_t led_RGB_blue = DigitalOutputCreate(LED_B_GPIO, LED_B_BIT);

    /******************/
    
    digital_output_t led_red = DigitalOutputCreate(LED_1_GPIO, LED_1_BIT);

    
    digital_output_t led_yellow = DigitalOutputCreate(LED_2_GPIO, LED_2_BIT);

    
    digital_output_t led_green = DigitalOutputCreate(LED_3_GPIO, LED_3_BIT);

    /******************/
    
    digital_input_t tec_push = DigitalInputCreate(TEC_1_GPIO, TEC_1_BIT, true);

    
    digital_input_t tec_toggle = DigitalInputCreate(TEC_2_GPIO, TEC_2_BIT, true);

    
    digital_input_t tec_turn_on = DigitalInputCreate(TEC_3_GPIO, TEC_3_BIT, true);

    
    digital_input_t tec_turn_off = DigitalInputCreate(TEC_4_GPIO, TEC_4_BIT, true);

    while (true) {
        if (DigitalInputGetIsActive(tec_push)) {
            DigitalOutputActivate(led_RGB_blue);
        } else {
            DigitalOutputDeactivate(led_RGB_blue);
        }

        if (DigitalWasActive(tec_toggle)) {
            DigitalOutputToggle(led_red);
        }

        if (DigitalInputGetIsActive(tec_turn_on)) {
            DigitalOutputActivate(led_yellow);
        }
        if (DigitalInputGetIsActive(tec_turn_off)) {
            DigitalOutputDeactivate(led_yellow);
        }

        divisor++;
        if (divisor == 5) {
            divisor = 0;
            DigitalOutputToggle(led_green);
        }

        for (int index = 0; index < 100; index++) {
            for (int delay = 0; delay < 25000; delay++) {
                __asm("NOP");
            }
        }
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
