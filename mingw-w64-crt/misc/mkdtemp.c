#define _CRT_RAND_S
#define _MS_SOURCE
#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <direct.h>

char *__cdecl mkdtemp(char *_Template)
{
    int j, len, index;
    unsigned int i, r;

    /* These are the (62) characters used in temporary filenames. */
    static const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    /* The last six characters of template must be "XXXXXX" */
    if(_Template == NULL || (len = strlen(_Template)) < 6 || memcmp(_Template + (len - 6), "XXXXXX", 6))
    {
        errno = EINVAL;
        return NULL;
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
        int ret = _mkdir(_Template);
        if(ret == 0)
        {
            return _Template;
        }
        if(ret == -1 && errno != EEXIST)
        {
            return NULL;
        }
    }

    return NULL;
}
