// RUtils Single Header Library

// Copyright (c) 2026 RandomPerson
// SPDX-License-Identifier: MIT-0

#include <stdio.h>
#include <string.h>

#ifndef RUTILS_H
#define RUTILS_H

// Macros

// Macros for colored text
#define RUTILS_COLOR_RED "\e[1;31m"
#define RUTILS_COLOR_YELLOW "\e[1;33m"
#define RUTILS_COLOR_GREEN "\e[1;32m"
#define RUTILS_COLOR_RESET "\e[0;0m"

// Macros for log types
#define RUTILS_LOGGING_NORMAL 0
#define RUTILS_LOGGING_WARNING 1
#define RUTILS_LOGGING_ERROR 2

// Library definition
// Logging

// Function to log message to stdout/stderr
void rutils_logging_log(const char *log_msg, int log_type);

// String

// Function to truncate string (from beginning to trunc_num)
const char *rutils_string_truncate(const char *original_str, size_t trunc_num);

// Library implementation
#ifdef RUTILS_IMPLEMENTATION

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
    default: // Default if log_type is invalid
      fprintf(stdout,
              "%s[W]: Log type %d is invalid, actual log message will not be shown!%s\n",
              RUTILS_COLOR_YELLOW,
              log_type,
              RUTILS_COLOR_RESET);
  }
}

const char *rutils_string_truncate(const char *original_str, size_t trunc_num) {
  if (trunc_num > strlen(original_str)) { // To prevent buffer overread
    return "";
  }

  return original_str + trunc_num;
}

#endif // RUTILS_IMPLEMENTATION

#endif // RUTILS_H
