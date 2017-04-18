/*
 * Copyright (c) 2009, Sven C. Koehler
 */

#ifndef _LMC_LOCK_H_
#define _LMC_LOCK_H_
#include <semaphore.h>
#include "lmc_error.h"

typedef struct {
  sem_t *sem;
  char namespace[1024];
} lmc_lock_t;

lmc_lock_t *lmc_lock_init(const char *namespace, int init, lmc_error_t *e);
lmc_lock_t *lmc_lock_init_and_lock(const char *namespace, int init, lmc_error_t *e);
void lmc_lock_free(lmc_lock_t *l);
int lmc_lock_obtain(const char *where, lmc_lock_t *l, lmc_error_t *e);
int lmc_lock_obtain_mandatory(const char *where, lmc_lock_t *l, lmc_error_t *e);
int lmc_lock_release(const char *where, lmc_lock_t *l, lmc_error_t *e);

int lmc_is_locked(lmc_lock_t *l, lmc_error_t *e);
int lmc_is_lock_working(lmc_lock_t *l, lmc_error_t *e);
void lmc_lock_repair(lmc_lock_t *l);
int lmc_lock_get_value(lmc_lock_t *l);
int lmc_clear_namespace_lock(const char *namespace);
#endif
