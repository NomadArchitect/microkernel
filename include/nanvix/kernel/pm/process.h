/*
 * Copyright(c) 2011-2024 The Maintainers of Nanvix.
 * Licensed under the MIT License.
 */

#ifndef NANVIX_KERNEL_PM_PROCESS_H_
#define NANVIX_KERNEL_PM_PROCESS_H_

/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <nanvix/kernel/hal.h>
#include <nanvix/kernel/mm.h>
#include <stdnoreturn.h>

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

/**
 * @brief Maximum number of processes.
 */
#define PROCESS_MAX 16

/**
 * @name Process States
 */
/**@{*/
#define PROCESS_NOT_STARTED 0 /** Not Started */
#define PROCESS_STARTED 1     /** Started     */
#define PROCESS_READY 2       /** Ready       */
#define PROCESS_RUNNING 3     /** Running     */
#define PROCESS_TERMINATED 4  /** Terminated  */
/**@}*/

/*============================================================================*
 * Types                                                                      *
 *============================================================================*/

/**
 * @brief Process ID.
 */
typedef int pid_t;

/*============================================================================*
 * Structures                                                                 *
 *============================================================================*/

/**
 * @brief Process.
 */
struct process {
    /**
     * @name Control variables.
     */
    /**@{*/
    pid_t pid;    /** Process ID. */
    unsigned age; /** Age.       */
    short state;  /** State.     */
    /**@}*/

    /**
     * @name Memory Information
     */
    /**@{*/
    vmem_t vmem;       /** Virtuam memory map. */
    const void *image; /** Binary image.       */
    /**@}*/

    /**
     * @name Scheduling variables.
     */
    /**@{*/
    unsigned quantum;     /** Quantum.                */
    struct context ctx;   /** Execution context.      */
    byte_t *stack;        /** Stack.                  */
    struct process *next; /** Next process in a queue. */
    /**@}*/
};

/*============================================================================*
 * Functions                                                                  *
 *============================================================================*/

/**
 * @brief Checks whether a process is valid or not.
 *
 * @param pid PID of target process.
 *
 * @returns Upon successful completion, zero is returned. Upon failure, a
 * negative error code is returned instead.
 */
extern int process_is_valid(pid_t pid);

/**
 * @brief Gets the currently running process.
 *
 * The process_get() function returns a pointer to the process that is running
 * in the underlying core.
 *
 * @returns A pointer to the process that is running in the
 * underlying core.
 */
extern struct process *process_get_curr(void);

/**
 * @brief Creates a new process.
 *
 * @param image Binary image.
 *
 * @returns Upon successful completion, the ID of the newly created process is
 * returned. Upon failure, a negative number is returned instead.
 */
extern pid_t process_create(const void *image);

/**
 * @brief Yields the calling process.
 */
extern void process_yield(void);

/**
 * @brief Terminates the calling process.
 */
extern noreturn void process_exit(void);

/**
 * @brief Initializes the process system.
 *
 * @param root_vmem Root virtual memory space.
 */
extern void process_init(vmem_t root_vmem);

/**
 * @brief Puts the calling process to sleep.
 */
extern void process_sleep(void);

/**
 * @brief Wakes up a process.
 *
 * @param t Target process.
 */
extern void process_wakeup(struct process *t);

#endif /* NANVIX_KERNEL_PM_PROCESS_H_ */
