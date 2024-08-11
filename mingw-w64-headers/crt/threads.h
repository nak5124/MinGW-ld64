/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _THREADS_H
#define _THREADS_H

#include <corecrt.h>
#include <stdint.h>
#include <time.h>

__MINGW_BEGIN_C_DECLS

#if (!defined(__STDC_VERSION__) || __STDC_VERSION__ <= 201710L || !__MINGW_GNUC_PREREQ(13, 0)) && !defined(__cplusplus)
# define thread_local _Thread_local
#endif

  enum
  {
    mtx_plain     = 0,
    mtx_recursive = 1,
    mtx_timed     = 2,
  };

  typedef struct mtx_t
  {
    uintptr_t  _Type;
    void      *_Ptr;
    void      *_Cv;
    uint32_t   _Owner;
    uint32_t   _Cnt;
  } mtx_t;

  _CRTIMP void __cdecl  mtx_destroy(mtx_t *_Mtx);
  _CRTIMP int  __cdecl  mtx_init(mtx_t *_Mtx, int _Type);
  _CRTIMP int  __cdecl  mtx_lock(mtx_t *_Mtx);
  _CRTIMP int  __cdecl _mtx_timedlock32(mtx_t *__restrict _Mtx, const struct _timespec32 *__restrict _Ts);
  _CRTIMP int  __cdecl _mtx_timedlock64(mtx_t *__restrict _Mtx, const struct _timespec64 *__restrict _Ts);
  _CRTIMP int  __cdecl  mtx_timedlock(mtx_t *__restrict _Mtx, const struct timespec *__restrict _Ts) __MINGW_ASM_CALL(_mtx_timedlock64);
  _CRTIMP int  __cdecl  mtx_trylock(mtx_t *_Mtx);
  _CRTIMP int  __cdecl  mtx_unlock(mtx_t *_Mtx);

  typedef struct cnd_t
  {
    void *_Ptr;
  } cnd_t;

  _CRTIMP int  __cdecl  cnd_broadcast(cnd_t *_Cond);
  _CRTIMP void __cdecl  cnd_destroy(cnd_t *_Cond);
  _CRTIMP int  __cdecl  cnd_init(cnd_t *_Cond);
  _CRTIMP int  __cdecl  cnd_signal(cnd_t *_Cond);
  _CRTIMP int  __cdecl _cnd_timedwait32(cnd_t *_Cond, mtx_t *_Mtx, const struct _timespec32 *_Ts);
  _CRTIMP int  __cdecl _cnd_timedwait64(cnd_t *_Cond, mtx_t *_Mtx, const struct _timespec64 *_Ts);
  _CRTIMP int  __cdecl  cnd_timedwait(cnd_t *_Cond, mtx_t *_Mtx, const struct timespec *_Ts) __MINGW_ASM_CALL(_cnd_timedwait64);
  _CRTIMP int  __cdecl  cnd_wait(cnd_t *_Cond, mtx_t *_Mtx);

  typedef struct thrd_t
  {
      void     *_Handle;
      uint32_t  _Tid;
  } thrd_t;

  enum
  {
    thrd_success  = 0,
    thrd_nomem    = 1,
    thrd_timedout = 2,
    thrd_busy     = 3,
    thrd_error    = 4
  };

  typedef int (__cdecl *thrd_start_t)(void *);

  _CRTIMP int    __cdecl  thrd_create(thrd_t *_Thr, thrd_start_t _Func, void *_Arg);
  _CRTIMP thrd_t __cdecl  thrd_current(void);
  _CRTIMP int    __cdecl  thrd_detach(thrd_t _Thr);
  _CRTIMP int    __cdecl  thrd_equal(thrd_t _Thr0, thrd_t _Thr1);
  _CRTIMP void   __cdecl  thrd_exit(int _Res) __MINGW_NORETURN;
  _CRTIMP int    __cdecl  thrd_join(thrd_t _Thr, int* _Res);
  _CRTIMP int    __cdecl _thrd_sleep32(const struct _timespec32 *__time_point, struct _timespec32 *__remaining);
  _CRTIMP int    __cdecl _thrd_sleep64(const struct _timespec64 *__time_point, struct _timespec64 *__remaining);
  _CRTIMP int    __cdecl  thrd_sleep(const struct timespec *__time_point, struct timespec *__remaining) __MINGW_ASM_CALL(_thrd_sleep64);
  _CRTIMP void   __cdecl  thrd_yield(void);

#ifndef __CRT__NO_INLINE
  __CRT_INLINE
  int __cdecl thrd_equal(thrd_t _Thr0, thrd_t _Thr1)
  {
    return _Thr0._Tid == _Thr1._Tid;
  }
#endif

#define TSS_DTOR_ITERATIONS 1
  typedef struct tss_t
  {
    uint32_t _Idx;
  } tss_t;

  typedef void (*tss_dtor_t)(void *);

  _CRTIMP int   __cdecl tss_create(tss_t *_Key, tss_dtor_t _Dtor);
  _CRTIMP void  __cdecl tss_delete(tss_t _Key);
  _CRTIMP void *__cdecl tss_get(tss_t _Key);
  _CRTIMP int   __cdecl tss_set(tss_t _Key, void* _Val);

  typedef struct once_flag
  {
    void *_Opaque;
  } once_flag;

  _CRTIMP void __cdecl call_once(once_flag *_Flag, void (*_Func)(void));

#define ONCE_FLAG_INIT { 0 }

__MINGW_END_C_DECLS

#endif  /* _THREADS_H */
