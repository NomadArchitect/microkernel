/*
 * MIT License
 *
 * Copyright(c) 2018 Pedro Henrique Penna <pedrohenriquepenna@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NANVIX_HAL_INTERRUPT_H_
#define NANVIX_HAL_INTERRUPT_H_

/**
 * @addtogroup kernel-hal-interrupts Interrupt
 * @ingroup kernel-hal
 *
 * @brief Hardware and Software Interrupts
 */
/**@{*/

	#include <nanvix/hal/target.h>
	#include <nanvix/const.h>

	#ifndef _HAL_INT_NR
	#error "_HAL_INT_NR not defined"
	#endif

	#ifndef __hal_disable_interrupts
	#error "hal_disable_interrupts() not defined?"
	#endif

	#ifndef __hal_enable_interrupts
	#error "hal_enable_interrupts() not defined?"
	#endif

#ifdef XXX
	#ifndef __hal_interrupt_ack
	#error "hal_interrupt_ack() not defined?"
	#endif
#endif

	#ifndef __hal_interrupt_set_handler
	#error "hal_interrupt_set_handler() not defined?"
	#endif

	#ifndef __hal_intlvl_raise
	#error "hal_intlvl_raise() not defined?"
	#endif

	#ifndef __hal_intlvl_drop
	#error "hal_intlvl_hal_drop() not defined?"
	#endif

	/**
	 * @brief Number of hardware interrupts.
	 */
	#define HAL_INT_NR _HAL_INT_NR

	/**
	 * @brief Hardware interrupt handler.
	 */
	typedef void (*hal_interrupt_handler_t)(int);

	/**
	 * @brief Disables all hardware interrupts.
	 */
	EXTERN void hal_disable_interrupts(void);

	/**
	 * @brief Enables all hardware interrupts.
	 */
	EXTERN void hal_enable_interrupts(void);

	/**
	 * @brief Sets a handler for an interrupt.
	 *
	 * @param num     Number of the target interrupt.
	 * @param handler Handler.
	 *
	 * @note This function does not check if a handler is already
	 * set for the target hardware interrupt.
	 */
	EXTERN void hal_interrupt_set_handler(int num, hal_interrupt_handler_t handler);

	/**
	 * @brief Raises an interrupt.
	 *
	 * @param num Number of the target interrupt.
	 *
	 * @returns Upon successful completion, zero is returned. Upon
	 * failure, a negative error number is returned instead.
	 */
	EXTERN int hal_interrupt_raise(int num);

	/**
	 * @brief Acknowledges an interrupt.
	 *
	 * @param num Number of the target interrupt.
	 *
	 * @returns Upon successful completion, zero is returned. Upon
	 * failure, a negative error number is returned instead.
	 */
	EXTERN int hal_interrupt_ack(int num);

	/**
	 * @brief Masks an interrupt.
	 *
	 * @param num number of the target interrupt.
	 *
	 * @returns Upon successful completion, zero is returned. Upon
	 * failure, a negative error number is returned instead.
	 */
	EXTERN int hal_interrupt_mask(int num);

	/**
	 * @brief Unmasks an interrupt.
	 *
	 * @param num Number of the target interrupt.
	 *
	 * @returns Upon successful completion, zero is returned. Upon
	 * failure, a negative error number is returned instead.
	 */
	EXTERN int hal_interrupt_unmask(int num);

	/**
	 * @brief Registers an interrupt handler.
	 *
	 * @param num     Number of the interrupt.
	 * @param handler Interrupt handler.
	 *
	 * @returns upon successful completion, zero is returned. Upon
	 * failure, a negative error code is returned instead.
	 */
	EXTERN int interrupt_register(int num, hal_interrupt_handler_t handler);

	/**
	 * @brief Setups hardware interrupts.
	 */
	EXTERN void interrupt_setup(void);

/**@}*/

#endif /* NANVIX_HAL_INTERRUPT_H_ */