/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef CONCURRENCYSAL_H
#define CONCURRENCYSAL_H

#ifdef __cplusplus
extern "C" {
#endif

#define _Guarded_by_(lock)
#define _Write_guarded_by_(lock)
#define _Interlocked_
#define _Requires_lock_held_(lock)
#define _Requires_exclusive_lock_held_(lock)
#define _Requires_shared_lock_held_(lock)
#define _Requires_lock_not_held_(lock)
#define _Requires_no_locks_held_
#define _Acquires_lock_(lock)
#define _Acquires_exclusive_lock_(lock)
#define _Acquires_shared_lock_(lock)
#define _Releases_lock_(lock)
#define _Releases_exclusive_lock_(lock)
#define _Releases_shared_lock_(lock)
#define _Acquires_nonreentrant_lock_(lock)
#define _Releases_nonreentrant_lock_(lock)
#define _Post_same_lock_(lock1, lock2)
#define _Internal_set_lock_count_(lock, count)
#define _Create_lock_level_(level)
#define _Has_lock_level_(level)
#define _Internal_lock_level_order_(a, b)
#define _Csalcat1_(x, y)
#define _Csalcat2_(x, y)
#define _Lock_level_order_(a, b)
#define _No_competing_thread_
#define _Analysis_assume_lock_acquired_(lock)
#define _Analysis_assume_lock_released_(lock)
#define _Analysis_assume_lock_held_(lock)
#define _Analysis_assume_lock_not_held_(lock)
#define _Analysis_assume_same_lock_(lock1, lock2)
#define _Function_ignore_lock_checking_(lock)
#define _Analysis_suppress_lock_checking_(lock)
#define _Benign_race_begin_
#define _Benign_race_end_
#define _No_competing_thread_begin_
#define _No_competing_thread_end_
#define _Has_lock_kind_(kind)
#ifdef __cplusplus
# define _Analysis_assume_smart_lock_acquired_(lock)
# define _Analysis_assume_smart_lock_released_(lock)
#endif
#define _Detaches_lock_(detached, lock)
#define _Moves_lock_(target, source)
#define _Replaces_lock_(target, source)
#define _Swaps_locks_(left, right)
#define __guarded_by(lock)
#define __write_guarded_by(lock)
#define __interlocked
#define __requires_lock_held(lock)
#define __requires_exclusive_lock_held(lock)
#define __requires_shared_lock_held(lock)
#define __requires_lock_not_held(lock)
#define __requires_no_locks_held
#define __acquires_lock(lock)
#define __acquires_exclusive_lock(lock)
#define __acquires_shared_lock(lock)
#define __releases_lock(lock)
#define __releases_exclusive_lock(lock)
#define __releases_shared_lock(lock)
#define __has_lock_property(kind)
#define __declare_lock_level(level)
#define __has_lock_level(level)
#define __internal_lock_level_order(a, b)
#define CSALCAT1(x, y)
#define CSALCAT2(x, y)
#define __lock_level_order(a, b)
#define __no_competing_thread
#define __analysis_assume_lock_acquired(lock)
#define __analysis_assume_lock_released(lock)
#define __function_ignore_lock_checking(lock)
#define __analysis_suppress_lock_checking(lock)
#define BENIGN_RACE_BEGIN
#define BENIGN_RACE_END
#define NO_COMPETING_THREAD_BEGIN
#define NO_COMPETING_THREAD_END

#ifdef __cplusplus
}
#endif

#endif  /* CONCURRENCYSAL_H */
