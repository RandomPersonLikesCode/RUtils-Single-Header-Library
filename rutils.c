/*
  RUtils Single Source Library

  Copyright (c) 2026 RandomPerson
  SPDX-License-Identifier: MIT-0
*/

#include <stdio.h>

/* Variables */
/* ANSI Colors */

const char *RUTILS_COLOR_RED = "\x1b[1;31m";
const char *RUTILS_COLOR_YELLOW = "\x1b[1;33m";
const char *RUTILS_COLOR_GREEN = "\x1b[1;32m";
const char *RUTILS_COLOR_RESET = "\x1b[0;0m";

/* Enums */
/* Log Types */

enum RUtilsLogtype {
  RUTILS_LOGGING_NORMAL,
  RUTILS_LOGGING_WARNING,
  RUTILS_LOGGING_ERROR
};

/* Functions */
/* Function To Log Messages To stdout/stderr */

void rutils_logging_log(const char *log_msg, enum RUtilsLogtype log_type) {
  switch (log_type) {
    case RUTILS_LOGGING_ERROR:
      fprintf(stderr,
              "%s[E]: %s%s\n",
              RUTILS_COLOR_RED,
              log_msg,
              RUTILS_COLOR_RESET);

      break;
    case RUTILS_LOGGING_WARNING:
      fprintf(stdout,
              "%s[W]: %s%s\n",
              RUTILS_COLOR_YELLOW,
              log_msg,
              RUTILS_COLOR_RESET);

      break;
    case RUTILS_LOGGING_NORMAL:
      fprintf(stdout,
              "%s[N]: %s%s\n",
              RUTILS_COLOR_GREEN,
              log_msg,
              RUTILS_COLOR_RESET);

      break;
    default:
      fprintf(stdout,
              "%s[W]: Log type %d is invalid, actual log message will not be shown!%s\n",
              RUTILS_COLOR_YELLOW,
              log_type,
              RUTILS_COLOR_RESET);
  }
}
