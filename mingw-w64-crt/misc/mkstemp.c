#define _CRT_RAND_S
#define _MS_SOURCE
#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <io.h>
#include <fcntl.h>
#include <share.h>
#include <sys/stat.h>

/*
    The mkstemp() function generates a unique temporary filename from template,
    creates and opens the file, and returns an open file descriptor for the
    file.

    The template may be any file name with at least six trailing Xs, for example
    /tmp/temp.XXXXXXXX. The trailing Xs are replaced with a unique digit and
    letter combination that makes the file name unique. Since it will be
    modified, template must not be a string constant, but should be declared as
    a character array.

    The file is created with permissions 0600, that is, read plus write for
    owner only. The returned file descriptor provides both read and write access
    to the file.
 */
int __cdecl mkstemp(char *_Template)
{
    int j, fd, len, index;
    unsigned int i, r;

    /* These are the (62) characters used in temporary filenames. */
    static const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    /* The last six characters of template must be "XXXXXX" */
    if(_Template == NULL || (len = strlen(_Template)) < 6 || memcmp(_Template + (len - 6), "XXXXXX", 6))
    {
        errno = EINVAL;
        return -1;
    }

    /* User may supply more than six trailing Xs */
    for(index = len - 6; index > 0 && _Template[index - 1] == 'X'; index--);

    /* Like OpenBSD, mkstemp() will try 2 ** 31 combinations before giving up. */
    for(i = 0; i <= INT_MAX; i++)
    {
        for(j = index; j < len; j++)
        {
            if(rand_s(&r))
            {
                r = rand();
            }
            _Template[j] = letters[r % 62];
        }
        errno_t err = _sopen_s(&fd, _Template, _O_RDWR | _O_CREAT | _O_EXCL | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
        if(fd != -1 && err == 0)
        {
            return fd;
        }
        if(err != 0 && errno != EEXIST)
        {
            return -1;
        }
    }

    return -1;
}

int __cdecl mkstemp64(char *_Template) __attribute__((alias("mkstemp")));
