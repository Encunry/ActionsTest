/*
 * Copyright (c) 2024-2025, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "platform.h"
#include "McuRTOS.h"
#include <stdio.h>
#if PL_CONFIG_USE_GCOV
  #include "McuCoverage.h"
#endif
#include "gcov_test.h"

int main(void) {
  PL_Init();
  vTaskStartScheduler();
#if PL_CONFIG_USE_GCOV
  gcov_test(1);
  gcov_test(0);
  McuCoverage_WriteFiles(); /* write coverage data files */
#endif /* PL_CONFIG_USE_GCOV */

  for(;;) {
    /* do not return from main() */
  }
  return 0;
}
