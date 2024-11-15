#define _CRT_RAND_S
#define _MS_SOURCE
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <sys/stat.h>

int __cdecl mkstemps (char *template_name, int suffixlen)
{
    int j, fd, len, index;
    unsigned int i, r;

    /* These are the (62) characters used in temporary filenames. */
    static const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    /* The last six characters of template must be "XXXXXX" */
    if (template_name == NULL || (len = strlen (template_name)) < suffixlen + 6
            || memcmp (template_name + (len - suffixlen - 6), "XXXXXX", 6)) {
        errno = EINVAL;
        return -1;
    }

    /* User may supply more than six trailing Xs */
    for (index = len - suffixlen - 6; index > 0 && template_name[index - 1] == 'X'; index--);

    /* Like OpenBSD, mkstemp() will try 2 ** 31 combinations before giving up. */
    for (i = 0; i <= INT_MAX; i++) {
        for(j = index; j < len - suffixlen; j++) {
            if (rand_s(&r))
                r = rand();
            template_name[j] = letters[r % 62];
        }
        errno_t err = _sopen_s(&fd, template_name,
                _O_RDWR | _O_CREAT | _O_EXCL | _O_BINARY,
                _SH_DENYNO, _S_IREAD | _S_IWRITE);
        if (fd != -1 && err == 0) return fd;
        if (err != 0 && errno != EEXIST) return -1;
    }

    return -1;
}

int __cdecl mkstemps64 (char *template_name, int suffixlen) __attribute__((alias("mkstemps")));
