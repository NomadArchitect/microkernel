/*
 * MIT License
 *
 * Copyright(c) 2011-2018 Pedro Henrique Penna <pedrohenriquepenna@gmail.com>
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

#ifndef ARCH_I386_PAGING_H_
#define ARCH_I386_PAGING_H_

/**
 * @addtogroup i386-paging Paging
 * @ingroup i386
 *
 * @brief Interface for dealing with paging.
 */
/**@{*/

	/**
	 * @name Page shifts and Masks
	 */
	/**@{*/
	#define PAGE_SHIFT  12                  /**< Page shift.       */
	#define PGTAB_SHIFT 22                  /**< Page table shift. */
	#define PAGE_MASK   (~(PAGE_SIZE - 1))  /**< Page mask.        */
	#define PGTAB_MASK  (~(PGTAB_SIZE - 1)) /**< Page table mask.  */
	/**@}*/

	/**
	 * @name Size of Pages and Page Tables
	 */
	/**@{*/
	#define PAGE_SIZE  (1 << PAGE_SHIFT)  /**< Page size.                 */
	#define PGTAB_SIZE (1 << PGTAB_SHIFT) /**< Page table size.           */
	#define PTE_SIZE   4                  /**< Page table entry size.     */
	#define PDE_SIZE   4                  /**< Page directory entry size. */
	/**@}*/

/**@}*/

#endif /* ARCH_I386_PAGING_H_ */