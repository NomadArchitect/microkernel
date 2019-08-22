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

#include <nanvix/const.h>
#include <nanvix/mm.h>
#include <nanvix/signal.h>
#include <errno.h>

/*============================================================================*
 * sys_sigctl()                                                               *
 *============================================================================*/

/**
 * The sigctl() function modifies the treatment of a signal.
 */
PUBLIC int sys_sigctl(int signum, struct ksigaction *sigact)
{
	if (sigact == NULL)
		return (-EAGAIN);

	/* Bad struct location. */
	if (!mm_check_area(VADDR(sigact), sizeof(struct ksigaction), UMEM_AREA))
		return (-EFAULT);

	/* Bad handler address. */
	if (!mm_check_area(VADDR(sigact->handler), 0, UMEM_AREA))
		return (-EFAULT);

	return (signal_control(signum, sigact));
}

/*============================================================================*
 * sys_alarm()                                                                *
 *============================================================================*/

/**
 * The alarm() function schedule an alarm signal to trigger when
 * the @seconds seconds pass.
 *
 * @todo: TODO check parameters.
 */
PUBLIC int sys_alarm(int seconds)
{
	return signal_alarm(seconds);
}

/*============================================================================*
 * sys_sigsend()                                                              *
 *============================================================================*/

/**
 * The sigsend() function sends a signal @signum to another thread @tid.
 *
 * @todo: TODO check parameters.
 */
PUBLIC int sys_sigsend(int signum, int tid)
{
	return signal_send(signum, tid);
}

/*============================================================================*
 * sys_sigwait()                                                              *
 *============================================================================*/

/**
 * The sigwait() function waits for the receipt of a @signum signal.
 *
 * @todo: TODO check parameters.
 */
PUBLIC int sys_sigwait(int signum)
{
	return signal_wait(signum);
}

/*============================================================================*
 * sys_sigreturn()                                                            *
 *============================================================================*/

/**
 * The sigreturn() function returns from a signal handler, restoring the
 * execution stream.
 */
PUBLIC void sys_sigreturn(void)
{
	signal_return();
}
