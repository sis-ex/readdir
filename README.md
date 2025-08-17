# readdir <!-- omit in toc -->

[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)
[![C/C++ CI](https://github.com/sis-ex/readdir/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/sis-ex/readdir/actions/workflows/c-cpp.yml)

Minimal example C program using Unix **readdir API** to list files in a directory.

## Table of contents <!-- omit in toc -->

- [Background](#background)
- [Program](#program)
  - [Running program](#running-program)
- [Resources and related material](#resources-and-related-material)


## Background

The **readdir API** is the fundamental file-system search API for Unix. It consists of a number of functions, including:

* `opendir()` starts directory search;
* `readdir()` obtain next entry in search;
* `closedir()` stops directory search, releasing all resources;

There are many use resources to explain in detail the semantics (see [Resources and related material](#resources-and-related-material)).


## Program

The full program source is shown below:

```C
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	char const* search_dir = (argc < 2) ? "." : argv[1];

	DIR* const dir = opendir(search_dir);

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
```

### Running program

```bash
$ ./readdir .
entries in '.':
	.
	..
	readdir
	Makefile
	README.md
	main.c
	.gitignore
	.gitattributes
	.vimrc
	.git
	.vscode
```


## Resources and related material

* [`readdir()` documentation (Linux)](https://man7.org/linux/man-pages/man3/readdir.3.html);
* [readdir API documentation (OpenBSD)](https://man.openbsd.org/readdir.3);
* **readdir API** for Windows, via [UNIXem library](https://github.com/synesissoftware/UNIXem);
* `unixstl::readdir_sequence` in the [**STLSoft** libraries](https://github.com/synesissoftware/STLSoft-1.11);
* Second 19.1.2 of "_Extension STL, volume 1_", Matthew Wilson, Addison-Wesley, 2007;


<!-- ########################### end of file ########################### -->

