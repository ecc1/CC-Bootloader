/*
 * CC Bootloader - Hardware Abstraction Layer 
 *
 * Fergus Noble (c) 2011
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

#include "cc1111.h"
#include "hal.h"

void setup_led() {
  // Setup LED and turn it off
  P1DIR |= LED_MASK;
  LED = 0;
}

void setup_button() {
  #ifdef RFCAT_DONSDONGLE
  P1DIR &= ~4;
  #endif
  #ifdef RFCAT_CHRONOS
  P2DIR &= ~4;
  #endif
}

void led_on() {
  LED = 1;
}

void led_off() {
  LED = 0;
}

void usb_up() {
  // Bring up the USB link
  P1DIR |= USB_MASK;
  USB_ENABLE = 1;
}

void usb_down() {
  // Bring down the USB link
  USB_ENABLE = 0;
  P1DIR &= ~USB_MASK;
}