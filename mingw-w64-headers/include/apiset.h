/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _API_SET_H_
#define _API_SET_H_

#include <_mingw.h>


#define API_SET_OVERRIDE(X)            X##Implementation
#define API_SET_LEGACY_OVERRIDE_DEF(X) X = API_SET_OVERRIDE(X)
#define API_SET_OVERRIDE_DEF(X)        API_SET_LEGACY_OVERRIDE_DEF(X) PRIVATE

#define API_SET_CHPE_GUEST

#undef API_SET
#undef API_SET_DIR
#undef API_SET_BY_ORDINAL
#undef API_SET_BY_ORDINAL_DIR
#undef API_SET_WITH_OPTIONAL_ORDINAL
#undef API_SET_WITH_OPTIONAL_ORDINAL_DIR
#undef API_SET_LEGACY
#undef API_SET_LEGACY_DIR
#undef API_SET_LEGACY_BY_ORDINAL
#undef API_SET_LEGACY_BY_ORDINAL_DIR
#undef API_SET_LEGACY_WITH_OPTIONAL_ORDINAL
#undef API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR

#ifdef _API_SET_HOST
# undef  API_SET_LIBRARY
# define API_SET_LIBRARY(X)
# define API_SET(X)                                                 X PRIVATE
# define API_SET_DIR(X, DIR)                                        X DIR PRIVATE
# define API_SET_BY_ORDINAL(X, O, PO)                               X @##O NONAME PRIVATE
# define API_SET_BY_ORDINAL_DIR(X, O, PO, DIR)                      X @##O NONAME DIR PRIVATE
# define API_SET_WITH_OPTIONAL_ORDINAL(X, O, PO)                    X @##O PRIVATE
# define API_SET_WITH_OPTIONAL_ORDINAL_DIR(X, O, PO, DIR)           X @##O DIR PRIVATE
# define API_SET_LEGACY(X, L)                                       X PRIVATE
# define API_SET_LEGACY_DIR(X, L, DIR)                              X DIR PRIVATE
# define API_SET_LEGACY_BY_ORDINAL(X, L, O, PO)                     X @##O NONAME PRIVATE
# define API_SET_LEGACY_BY_ORDINAL_DIR(X, L, O, PO, DIR)            X @##O NONAME DIR PRIVATE
# define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL(X, L, O, PO)          X @##O PRIVATE
# define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR(X, L, O, PO, DIR) X @##O DIR PRIVATE
#else
# if defined(_API_SET_LEGACY_TARGET)
#   define API_SET(X)                                                 X = _API_SET_LEGACY_TARGET##.##X
#   define API_SET_DIR(X, DIR)                                        X = _API_SET_LEGACY_TARGET##.##X DIR
#   define API_SET_BY_ORDINAL(X, O, PO)                               X = _API_SET_LEGACY_TARGET##.##PO @##O NONAME
#   define API_SET_BY_ORDINAL_DIR(X, O, PO, DIR)                      X = _API_SET_LEGACY_TARGET##.##PO @##O NONAME DIR
#   define API_SET_WITH_OPTIONAL_ORDINAL(X, O, PO)                    X = _API_SET_LEGACY_TARGET##.##PO @##O
#   define API_SET_WITH_OPTIONAL_ORDINAL_DIR(X, O, PO, DIR)           X = _API_SET_LEGACY_TARGET##.##PO @##O DIR
#   define API_SET_LEGACY(X, L)                                       X = L##.##X
#   define API_SET_LEGACY_DIR(X, L, DIR)                              X = L##.##X DIR
#   define API_SET_LEGACY_BY_ORDINAL(X, L, O, PO)                     X = L##.##PO @##O NONAME
#   define API_SET_LEGACY_BY_ORDINAL_DIR(X, L, O, PO, DIR)            X = L##.##PO @##O NONAME DIR
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL(X, L, O, PO)          X = L##.##PO @##O
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR(X, L, O, PO, DIR) X = L##.##PO @##O DIR
# elif defined(_API_SET_FORWARDER_TARGET)
#   define API_SET(X)                                                 X = _API_SET_FORWARDER_TARGET##.##X
#   define API_SET_DIR(X, DIR)                                        X = _API_SET_FORWARDER_TARGET##.##X DIR
#   define API_SET_BY_ORDINAL(X, O, PO)                               X = _API_SET_FORWARDER_TARGET##.##PO @##O NONAME
#   define API_SET_BY_ORDINAL_DIR(X, O, PO, DIR)                      X = _API_SET_FORWARDER_TARGET##.##PO @##O NONAME DIR
#   define API_SET_WITH_OPTIONAL_ORDINAL(X, O, PO)                    X = _API_SET_FORWARDER_TARGET##.##PO @##O
#   define API_SET_WITH_OPTIONAL_ORDINAL_DIR(X, O, PO, DIR)           X = _API_SET_FORWARDER_TARGET##.##PO @##O DIR
#   define API_SET_LEGACY(X, L)                                       X = _API_SET_FORWARDER_TARGET##.##X
#   define API_SET_LEGACY_DIR(X, L, DIR)                              X = _API_SET_FORWARDER_TARGET##.##X DIR
#   define API_SET_LEGACY_BY_ORDINAL(X, L, O, PO)                     X = _API_SET_FORWARDER_TARGET##.##PO @##O NONAME
#   define API_SET_LEGACY_BY_ORDINAL_DIR(X, L, O, PO, DIR)            X = _API_SET_FORWARDER_TARGET##.##PO @##O NONAME DIR
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL(X, L, O, PO)          X = _API_SET_FORWARDER_TARGET##.##PO @##O
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR(X, L, O, PO, DIR) X = _API_SET_FORWARDER_TARGET##.##PO @##O DIR
# else
#   define API_SET(X)                                                 X
#   define API_SET_DIR(X, DIR)                                        X DIR
#   define API_SET_BY_ORDINAL(X, O, PO)                               X @##O NONAME
#   define API_SET_BY_ORDINAL_DIR(X, O, PO, DIR)                      X @##O NONAME DIR
#   define API_SET_WITH_OPTIONAL_ORDINAL(X, O, PO)                    X @##O
#   define API_SET_WITH_OPTIONAL_ORDINAL_DIR(X, O, PO, DIR)           X @##O DIR
#   define API_SET_LEGACY(X, L)                                       X
#   define API_SET_LEGACY_DIR(X, L, DIR)                              X DIR
#   define API_SET_LEGACY_BY_ORDINAL(X, L, O, PO)                     X @##O NONAME
#   define API_SET_LEGACY_BY_ORDINAL_DIR(X, L, O, PO, DIR)            X @##O NONAME DIR
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL(X, L, O, PO)          X @##O
#   define API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR(X, L, O, PO, DIR) X @##O DIR
# endif
# define API_SET_LIBRARY(X) LIBRARY X
#endif

#endif  /* _API_SET_H_ */
