/* log.h  -  Memory library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
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

/*! \file log.h
    Log output */

#include <foundation/platform.h>
#include <foundation/hashstrings.h>

#include <memory/types.h>

#if BUILD_ENABLE_MEMORY_SPAM_LOG
#  define log_memory_spamf( msg, ... ) log_debugf( HASH_MEMORY, msg, __VA_ARGS__ )
#else
#  define log_memory_spamf( msg, ... ) /*lint -save -e717 */ do { (void)sizeof( msg ); } while(0) /*lint -restore */
#endif

#if BUILD_ENABLE_MEMORY_DEBUG_LOG
#  define log_memory_debugf( msg, ... ) log_debugf( HASH_MEMORY, msg, __VA_ARGS__ )
#else
#  define log_memory_debugf( msg, ... ) /*lint -save -e717 */ do { (void)sizeof( msg ); } while(0) /*lint -restore */
#endif

#if BUILD_ENABLE_MEMORY_LOG
#  define log_memory_infof( format, ... ) log_infof( HASH_MEMORY, format, __VA_ARGS__ )
#  define log_memory_warnf( warn, format, ... ) log_warnf( HASH_MEMORY, warn, format, __VA_ARGS__ )
#  define log_memory_errorf( err, format, ... ) log_errorf( HASH_MEMORY, err, format, __VA_ARGS__ )
#  define log_memory_panicf( err, format, ... ) log_panicf( HASH_MEMORY, err, format, __VA_ARGS__ )
#else
#  define log_memory_infof(msg, ...) /*lint -save -e717 */ do { (void)sizeof( msg ); } while(0) /*lint -restore */
#  define log_memory_warnf(warn, msg, ...) /*lint -save -e717 */ do { (void)sizeof( warn ); (void)sizeof( msg ); } while(0) /*lint -restore */
#  define log_memory_errorf(err, msg, ...) /*lint -save -e717 */ do { error_report( ERRORLEVEL_ERROR, err ); (void)sizeof( msg ); } while(0) /*lint -restore */
#  define log_memory_panicf(err, msg, ...) /*lint -save -e717 */ do { error_report( ERRORLEVEL_PANIC, err ); (void)sizeof( msg ); } while(0) /*lint -restore */
#endif

#define log_memory_spam(...)  log_memory_spamf(HASH_MEMORY, "%.*s", __VA_ARGS__)
#define log_memory_debug(...) log_memory_debugf(HASH_MEMORY, "%.*s", __VA_ARGS__)
#define log_memory_info(...)  log_memory_infof(HASH_MEMORY, "%.*s", __VA_ARGS__)
#define log_memory_warn(...)  log_memory_warnf(HASH_MEMORY, "%.*s", __VA_ARGS__)
#define log_memory_error(...) log_memory_errorf(HASH_MEMORY, "%.*s", __VA_ARGS__)
#define log_memory_panic(...) log_memory_panicf(HASH_MEMORY, "%.*s", __VA_ARGS__)
