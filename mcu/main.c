#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "commands.h"
#include "modes.h"
#include "settings.h"
#include "uart.h"
#include "timer.h"

#ifndef BAUD
  #define BAUD 115200
#endif

static uint32_t second;

ISR(TIMER1_OVF_vect) {
  reset_timer();
  second++;
}

int main() {
  uart_init(BAUD);
  timer_init();

  global_settings global = global_settings_get();
  if (global.uart_debug)
    global_settings_send();

  profile p;
  if (!profile_get(&p, global.active_profile))
    uart_send_string("profile id out of range!");

  if (global.uart_debug)
    profile_send(global.active_profile);

  sei();

  for (;;) {
    handle_commands();
    handle_mode(p.drive_mode, second);
  }
}

