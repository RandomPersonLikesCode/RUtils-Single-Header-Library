// RUtils Single Header Library

// Copyright (c) 2026 RandomPerson
// SPDX-License-Identifier: MIT-0

#include <stdio.h>

#ifndef RUTILS_H
#define RUTILS_H

// ANSI colors
#define RUTILS_COLOR_RED "\e[1;31m"
#define RUTILS_COLOR_YELLOW "\e[1;33m"
#define RUTILS_COLOR_GREEN "\e[1;32m"
#define RUTILS_COLOR_RESET "\e[0;0m"

// Log types
#define RUTILS_LOGGING_NORMAL 0
#define RUTILS_LOGGING_WARNING 1
#define RUTILS_LOGGING_ERROR 2

// Definition

void rutils_logging_log(const char *log_msg, int log_type);

#ifdef RUTILS_IMPLEMENTATION

// Implementation

void rutils_logging_log(const char *log_msg, int log_type) {
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

#endif // RUTILS_IMPLEMENTATION

#endif // RUTILS_H
