/*
 * Copyright(C) 2014 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * <timer.h> - Timer library.
 */

#ifndef TIMER_H_
#define TIMER_H_
  
  #include <stdint.h>
  #include <mppaipc.h>

  /* Timing units. */
  #define MICROSEC 0.000001 /* Micro seconds. */
  
  #define MPPA_FREQUENCY 400

  // extern uint64_t ___k1_read_dsu_timestamp();
  /*
   * Computers the difference between two times
   */
  extern uint64_t timer_diff(uint64_t t1, uint64_t t2);
  
  /*
   * Gets the current timer value
   */
  extern uint64_t timer_get(void);  
  
  /*
   * Initializes the timer.
   */
  extern void timer_init(void);

#endif /* TIMER_H_ */
