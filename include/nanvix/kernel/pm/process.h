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
#include <nanvix/kernel/iam.h>
#include <nanvix/kernel/lib.h>
#include <nanvix/kernel/limits.h>
#include <nanvix/kernel/mm.h>
#include <stdnoreturn.h>

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

/**
 * @brief Kernel process ID.
 */
#define KERNEL_PROCESS 0

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
    pid_t pid;           /** Process ID.     */
    tid_t tid;           /** Main Thread ID. */
    bool active;         /** Active?         */
    struct identity *id; /** Identity.       */
    /**@}*/

    /**
     * @name Memory Information
     */
    /**@{*/
    vmem_t vmem;        /** Virtual memory map. */
    const void *image;  /** Binary image.       */
    bitmap_t ustackmap; /** User stack map.     */
    /**@}*/

    /**
     * @name Scheduling variables.
     */
    /**@{*/
    struct process *next; /** Next process in a queue. */
    /**@}*/
};

/**
 * @brief Size of @p process_info structure.
 */
#define __SIZEOF_PROCESS_INFO 12

/**
 * @brief Process information.
 */
struct process_info {
    pid_t pid;   /** Process ID.         */
    tid_t tid;   /** Main Thread ID.     */
    vmem_t vmem; /** Virtual memory map. */
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
 * @brief Gets the process control block of a process.
 *
 * @param pid ID of the target process.
 *
 * @returns Upon successful completion, a pointer to the process control block
 * of the target process is returned. Upon failure, NULL is returned instead.
 */
extern struct process *process_get(pid_t pid);

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
 * @param p Target process.
 */
extern void process_wakeup(struct process *p);

#endif /* NANVIX_KERNEL_PM_PROCESS_H_ */
