#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    char const* const search_dir = (argc < 2) ? "." : argv[1];

    DIR* const	dir	=	opendir(search_dir);

    if (NULL == dir)
    {
        int const e = errno;

        fprintf(stderr, "%s: failed to search in '%s': %s\n", argv[0], search_dir, strerror(e));

        return EXIT_FAILURE;
    }
    else
    {
        printf("entries in '%s':\n", search_dir);

        for (struct dirent* de; NULL != (de = readdir(dir)); )
        {
            printf("\t%s\n", de->d_name);
        }

        closedir(dir);

        return EXIT_SUCCESS;
    }
}
