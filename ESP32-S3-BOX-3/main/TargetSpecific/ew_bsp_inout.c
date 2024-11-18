/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   This template provides access to some LEDs and buttons of the board.
*
*******************************************************************************/

#include <stdio.h>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp32s3/rom/gpio.h"
#include "esp_attr.h"

#include "ewrte.h"

#include "ew_bsp_inout.h"

#define LEDC_TIMER            LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (GPIO_NUM_39) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#define LEDC_DUTY_OFF           (0) // Set duty to 50%. (2 ** 13) * 50% = 4096
#define LEDC_DUTY_ON            (4096) // Set duty to 50%. (2 ** 13) * 50% = 4096
#define LEDC_FREQUENCY          (4000) // Frequency in Hertz. Set frequency at 4 kHz

#define BUTTON_GPIO           0

static TButtonCallback        ButtonCallback = NULL;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
  if ( ButtonCallback )
    ButtonCallback( !gpio_get_level( BUTTON_GPIO ));
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutInitButton
*
* DESCRIPTION:
*   Configures one hardware button of the board used for demo applications.
*
* ARGUMENTS:
*   aButtonCallback - The button callback.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutInitButton( TButtonCallback aButtonCallback )
{
  gpio_config_t io_conf;

  /* configure gpio to detect falling and rising edge */
  io_conf.pull_down_en = 0;
  io_conf.pull_up_en   = 1;
  io_conf.intr_type    = GPIO_INTR_ANYEDGE;
  io_conf.pin_bit_mask = (1UL << BUTTON_GPIO);
  io_conf.mode         = GPIO_MODE_INPUT;
  gpio_config( &io_conf );
  
  /* Start the gpio isr service */
  gpio_install_isr_service(0);
  /* add to the gpio isr service */
  gpio_isr_handler_add( BUTTON_GPIO, gpio_isr_handler, (void*)0 );

  /* store the callback function */
  ButtonCallback = aButtonCallback;
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutInitLed
*
* DESCRIPTION:
*   Configures one LED of the board used for demo applications.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutInitLed( void )
{
  /* Prepare and then apply the LEDC PWM timer configuration */
  ledc_timer_config_t ledc_timer = {
      .speed_mode       = LEDC_MODE,
      .duty_resolution  = LEDC_DUTY_RES,
      .timer_num        = LEDC_TIMER,
      .freq_hz          = LEDC_FREQUENCY,  // Set output frequency at 4 kHz
      .clk_cfg          = LEDC_AUTO_CLK
  };
  ledc_timer_config(&ledc_timer);

  /* Prepare and then apply the LEDC PWM channel configuration */
  ledc_channel_config_t ledc_channel = {
      .speed_mode     = LEDC_MODE,
      .channel        = LEDC_CHANNEL,
      .timer_sel      = LEDC_TIMER,
      .intr_type      = LEDC_INTR_DISABLE,
      .gpio_num       = LEDC_OUTPUT_IO,
      .duty           = 0, // Set duty to 0%
      .hpoint         = 0
  };
  ledc_channel_config(&ledc_channel);
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutLedOn
*
* DESCRIPTION:
*   Switch LED on (used for demo applications).
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutLedOn( void )
{
  /* Set duty to 50% */
  ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY_ON);
  /* Update duty to apply the new value */
  ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutLedOff
*
* DESCRIPTION:
*   Switch LED off (used for demo applications).
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutLedOff( void )
{
  ledc_stop(LEDC_MODE, LEDC_CHANNEL, LEDC_DUTY_OFF);
}

/* psh */
