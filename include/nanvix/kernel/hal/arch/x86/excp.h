/*
 * Copyright(c) 2011-2024 The Maintainers of Nanvix.
 * Licensed under the MIT License.
 */

#ifndef NANVIX_KERNEL_HAL_ARCH_X86_EXCP_H_
#define NANVIX_KERNEL_HAL_ARCH_X86_EXCP_H_

#include <arch/x86.h>
#include <nanvix/cc.h>

/*============================================================================*
 * Constants                                                                  *
 *============================================================================*/

/**
 * @brief Exception information size (in bytes).
 */
#define EXCEPTION_SIZE 16

/**
 * @name Offsets to the Exception Information Structure
 *
 * @see exception
 */
/**@{*/
#define EXCEPTION_NR 0    /** Offset to Exception Number     */
#define EXCEPTION_ERR 4   /** Offset to Error COde           */
#define EXCEPTION_DATA 8  /** Offset to Faulting Address     */
#define EXCEPTION_CODE 12 /** Offset to Faulting Instruction */
/**@}*/

/*============================================================================*
 * Structures                                                                 *
 *============================================================================*/

#ifndef _ASM_FILE_

/**
 * @brief Exception information.
 */
struct exception {
    word_t num;         /** Exception number.     */
    word_t code;        /** Error code.           */
    word_t addr;        /** Faulting address.     */
    word_t instruction; /** Faulting instruction. */
} __attribute__((packed));

#endif /* _ASM_FILE_ */

/*============================================================================*
 * Functions                                                                  *
 *============================================================================*/

#ifndef _ASM_FILE_

/**
 * @brief Gets the address of a page fault.
 *
 * @returns The linear address that incurred a page fault.
 */
static inline word_t get_page_fault_addr(void)
{
    return (x86_read_cr2());
}

#endif /* _ASM_FILE_ */

/*============================================================================*/

#endif /* NANVIX_KERNEL_HAL_ARCH_X86_CTX_H_ */
