/* $Id: master.h,v 1.9 2004/01/07 21:50:21 jorge Exp $ */

#ifndef _MASTER_H_
#define _MASTER_H_

#include "database.h"

#define KEY_MASTER "%s/bin/master"	/* Key for shared memory and semaphores */

extern int phantom[2];

void master_get_options (int *argc,char ***argv, int *force);
void usage (void);

int get_shared_memory (int force);
int get_semaphores (int force);
void *attach_shared_memory (int shmid);

void set_signal_handlers (void);
void set_signal_handlers_child_conn_handler (void);
void set_signal_handlers_child_cchecks (void);

void clean_out (int signal, siginfo_t *info, void *data);
void sigalarm_handler (int signal, siginfo_t *info, void *data);
void sigpipe_handler (int signal, siginfo_t *info, void *data);
void sigsegv_handler (int signal, siginfo_t *info, void *data);
void set_alarm (void);

void master_consistency_checks (struct database *wdb); /* Main consistency checks function */
void check_lastconn_times (struct database *wdb);


#endif /* _MASTER_H_ */