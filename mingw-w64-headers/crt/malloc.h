/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _MALLOC_H_
#define _MALLOC_H_

#include <corecrt.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#define _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
/* Return codes for _heapwalk()  */
#define _HEAPEMPTY    (-1)
#define _HEAPOK       (-2)
#define _HEAPBADBEGIN (-3)
#define _HEAPBADNODE  (-4)
#define _HEAPEND      (-5)
#define _HEAPBADPTR   (-6)

/* Values for _heapinfo.useflag */
#define _FREEENTRY 0
#define _USEDENTRY 1

 /* The structure used to walk through the heap with _heapwalk.  */
  typedef struct _heapinfo
  {
    int *_pentry;
    size_t _size;
    int _useflag;
  } _HEAPINFO;

#define _mm_free(a)      _aligned_free(a)
#define _mm_malloc(a, b) _aligned_malloc(a, b)

#ifndef _CRT_ALLOCATION_DEFINED  /* Also in stdlib.h */
# define _CRT_ALLOCATION_DEFINED
# undef  _alloca
# define _alloca(x) __builtin_alloca((x))
# undef   alloca
# define  alloca _alloca

  _CRTIMP void *__cdecl _calloc_base(size_t _Count, size_t _Size);
  _CRTIMP void *__cdecl calloc(size_t _NumOfElements, size_t _SizeOfElements);
  _CRTIMP int __cdecl _callnewh(size_t _Size);
  _CRTIMP void *__cdecl _expand(void *_Memory, size_t _NewSize);
  _CRTIMP void __cdecl _free_base(void *_Block);
  _CRTIMP void __cdecl free(void *_Memory);
  _CRTIMP void *__cdecl _malloc_base(size_t _Size);
  _CRTIMP void *__cdecl malloc(size_t _Size);
  _CRTIMP size_t __cdecl _msize_base(void *_Block);
  _CRTIMP size_t __cdecl _msize(void *_Memory);
  _CRTIMP void *__cdecl _realloc_base(void *_Block, size_t _Size);
  _CRTIMP void *__cdecl realloc(void *_Memory, size_t _NewSize);
  _CRTIMP void *__cdecl _recalloc_base(void *_Block, size_t _Count, size_t _Size);
  _CRTIMP void *__cdecl _recalloc(void *_Memory, size_t _Count, size_t _Size);
  _CRTIMP void __cdecl _aligned_free(void *_Memory);
  _CRTIMP void *__cdecl _aligned_malloc(size_t _Size, size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP size_t __cdecl _aligned_msize(void *_Block, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_realloc(void *_Memory, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_realloc(void *_Memory, size_t _Size, size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment);
#endif  /* _CRT_ALLOCATION_DEFINED */

  _CRTIMP intptr_t __cdecl _get_heap_handle(void);
  _CRTIMP int __cdecl _heapmin(void);
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP int __cdecl _heapchk(void);
#endif
  _CRTIMP int __cdecl _resetstkoflw(void);

#define _ALLOCA_S_THRESHOLD    1024
#define _ALLOCA_S_STACK_MARKER 0xCCCC
#define _ALLOCA_S_HEAP_MARKER  0xDDDD

#define _ALLOCA_S_MARKER_SIZE 16

  static __inline void *_MarkAllocaS(void *_Ptr,unsigned int _Marker)
  {
    if(_Ptr)
    {
      *((unsigned int*)_Ptr) = _Marker;
      _Ptr = (char*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    return _Ptr;
  }

  static __inline size_t _MallocaComputeSize(size_t _Size)
  {
    size_t _MarkedSize = _Size + _ALLOCA_S_MARKER_SIZE;
    return _MarkedSize > _Size ? _MarkedSize : 0;
  }

#undef _malloca
#define _malloca(size) \
  (_MallocaComputeSize(size) != 0 \
    ? (((_MallocaComputeSize(size) <= _ALLOCA_S_THRESHOLD) \
      ? _MarkAllocaS(_alloca(_MallocaComputeSize(size)), _ALLOCA_S_STACK_MARKER) \
      : _MarkAllocaS(malloc(_MallocaComputeSize(size)), _ALLOCA_S_HEAP_MARKER))) \
    : NULL)

#undef _freea
  static __inline void __cdecl _freea(void *_Memory)
  {
    unsigned int _Marker;
    if(_Memory)
    {
      _Memory = (char*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(unsigned int *)_Memory;
      if(_Marker==_ALLOCA_S_HEAP_MARKER)
      {
        free(_Memory);
      }
#ifdef _ASSERTE
      else if(_Marker != _ALLOCA_S_STACK_MARKER)
      {
        _ASSERTE(("Corrupted pointer passed to _freea", 0));
      }
#endif
    }
  }

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#endif  /* _MALLOC_H_ */
