#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdint.h>

#define GLOBAL_SETTINGS_START_ADDRESS 0
#define GLOBAL_SETTINGS_SIZE 20
#define PROFILE_START_ADDRESS GLOBAL_SETTINGS_SIZE + 1

/* global settings */
typedef struct {
  uint8_t version;
  uint8_t autostart;
  uint8_t status_led;
  uint8_t uart_debug;
  uint8_t active_profile;
  uint32_t authentication_token;
} global_settings;

/* profile */
typedef struct {
  uint8_t drive_mode;
} profile;

#endif /* _STRUCTS_H_ */
