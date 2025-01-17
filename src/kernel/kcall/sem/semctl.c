/*
 * Copyright(c) 2011-2024 The Maintainers of Nanvix.
 * Licensed under the MIT License.
 */

/*============================================================================*
 * Imports                                                                    *
 *============================================================================*/

#include <nanvix/kernel/lib.h>
#include <nanvix/kernel/pm/process.h>
#include <nanvix/kernel/pm/semaphore.h>

/*============================================================================*
 * Public Functions                                                           *
 *============================================================================*/

/**
 * @details Manages Semaphores.
 */
int kcall_semctl(int id, int cmd, int val)
{
    switch (cmd) {
        case SEMAPHORE_GETVALUE:
            return (semaphore_getcount(id));
        case SEMAPHORE_SETVALUE:
            return (semaphore_set(id, val));
        case SEMAPHORE_DELETE:
            return (semaphore_delete(id));
        default:
            return (-ENOENT);
    }

    return (-EBADMSG);
}
