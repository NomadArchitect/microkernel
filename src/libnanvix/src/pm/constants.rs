/*
 * Copyright(c) 2011-2024 The Maintainers of Nanvix.
 * Licensed under the MIT License.
 */

//==============================================================================
// Imports
//==============================================================================

use super::Pid;

//==============================================================================
// Constants
//==============================================================================

/// Special PID for a process to refer to itself.
pub const PID_SELF: Pid = -1;