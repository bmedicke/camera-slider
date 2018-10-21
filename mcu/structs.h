#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <stdint.h>

#define GLOBAL_SETTINGS_START_ADDRESS 0
#define GLOBAL_SETTINGS_SIZE 24

#define PROFILE_START_ADDRESS GLOBAL_SETTINGS_SIZE - 1
#define PROFILE_SIZE 50
#define NUMBER_OF_PROFILES 20

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
  uint32_t startup_delay;   /* in seconds */
  uint8_t drive_mode;       /* continous, step-shoot-step, bulb */
  uint8_t step_count;
  uint8_t cooldown;
  uint8_t step_delay;
  uint8_t direction;
  uint8_t dynamic_curve;
  uint8_t profile_version;
  uint8_t CRC;
} profile;

#endif /* _STRUCTS_H_ */
