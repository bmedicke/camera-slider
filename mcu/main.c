#ifndef BAUD
  #define BAUD 115200
#endif

#include <avr/interrupt.h>
#include "commands.h"
#include "modes.h"
#include "settings.h"
#include "uart.h"

int main() {
  uart_init(BAUD);

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
    handle_mode(p.drive_mode);
  }
}

