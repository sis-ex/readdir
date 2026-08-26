# readdir <!-- omit in toc -->

Minimal example C program using Unix **readdir API** to list files in a directory.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/sis-ex/readdir.svg)](https://github.com/sis-ex/readdir/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/sis-ex/readdir)](https://github.com/sis-ex/readdir/commits/master)
[![CI](https://github.com/sis-ex/readdir/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/sis-ex/readdir/actions/workflows/c-cpp.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Program](#program)
  - [Examples](#examples)
- [Resources and related material](#resources-and-related-material)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [License](#license)


## Introduction

**readdir** is a minimal example C program that uses the Unix **readdir API** to list files in a directory.

The **readdir API** is the fundamental file-system search API for Unix. It consists of a number of functions, including:

* `opendir()` starts directory search;
* `readdir()` obtain next entry in search;
* `closedir()` stops directory search, releasing all resources;

There are many useful resources to explain in detail the semantics (see [Resources and related material](#resources-and-related-material)).


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
```

### Examples

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
* Section 19.1.2 of "_Extension STL, volume 1_", Matthew Wilson, Addison-Wesley, 2007;


## Project Information


### Where to get help

[GitHub Page](https://github.com/sis-ex/readdir "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on [the **readdir** GitHub page](https://github.com/sis-ex/readdir).


### License

**readdir** is released under the 3-clause BSD license.


<!-- ########################### end of file ########################### -->
