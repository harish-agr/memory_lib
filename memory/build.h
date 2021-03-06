/* build.h  -  Memory library build setup  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform memory allocation library in C11 providing a lock-free
 * implementation of memory allocation and deallocation for projects based on our foundation library.
 * The latest source code is always available at
 *
 * https://github.com/rampantpixels/memory_lib
 *
 * This library is built on top of the foundation library available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#pragma once

/*! \file build.h
    Build setup */

#include <foundation/platform.h>


// Configurable choices

#ifndef BUILD_ENABLE_MEMORY_LOG
#define BUILD_ENABLE_MEMORY_LOG                  0 //BUILD_ENABLE_LOG
#endif

#ifndef BUILD_ENABLE_MEMORY_DEBUG_LOG
#define BUILD_ENABLE_MEMORY_DEBUG_LOG            0 //BUILD_ENABLE_DEBUG_LOG
#endif

#ifndef BUILD_ENABLE_MEMORY_SPAM_LOG
#define BUILD_ENABLE_MEMORY_SPAM_LOG             0
#endif

#ifndef BUILD_ENABLE_DETAILED_MEMORY_STATISTICS
#define BUILD_ENABLE_DETAILED_MEMORY_STATISTICS  0
#endif

#ifndef BUILD_USE_HEAP_PENDING_SUPERBLOCK
#define BUILD_USE_HEAP_PENDING_SUPERBLOCK        1
#endif

#ifndef BUILD_USE_PRE_ALIGN
#define BUILD_USE_PRE_ALIGN                      1
#endif


// Allocation sizes
