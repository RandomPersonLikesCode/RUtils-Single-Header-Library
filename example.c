/*
  RUtils Library Simple Example

  Copyright (c) 2026 RandomPerson
  SPDX-License-Identifier: MIT-0
*/

#include <stdio.h>

#define RUTILS_IMPLEMENTATION
#include "rutils.h"

int main(void) {
  rutils_logging_log("Hello Error", RUTILS_LOGGING_ERROR);
  rutils_logging_log("Hello Warning", RUTILS_LOGGING_WARNING);
  rutils_logging_log("Hello Normal", RUTILS_LOGGING_NORMAL);
  rutils_logging_log("Hello Undefined", 42);

  return 0;
}
