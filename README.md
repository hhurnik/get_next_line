*This project has been created as part of the 42 curriculum by hhurnik.*

# get_next_line

## Description

get_next_line is a C function that reads and returns one line at a time from a file descriptor.

The project focuses on file descriptor handling, buffered input, dynamic memory management and the use of static variables to preserve unread data between function calls.

Each call returns the next available line, including the terminating newline character when one is present.

## Function

```c
char *get_next_line(int fd);
```

The function:

- reads from the given file descriptor
- returns one line per call
- preserves unread data between calls
- includes `\n` in the returned line when present
- returns the final line even if it does not end with `\n`
- returns `NULL` when there is nothing left to read or when a read error occurs

The returned string is dynamically allocated and should be freed by the caller.

## BUFFER_SIZE

The amount of data read at a time is controlled by `BUFFER_SIZE`.

A default value is defined in the header:

```c
#define BUFFER_SIZE 1024
```

It can be overridden during compilation:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
main.c get_next_line.c get_next_line_utils.c -o gnl
```

## Usage

Include the header:

```c
#include "get_next_line.h"
```

Example:

```c
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    line = get_next_line(fd);
    while (line)
    {
        write(1, line, ft_strlen(line));
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}
```

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
main.c get_next_line.c get_next_line_utils.c -o gnl
```

Then run:

```bash
./gnl
```

## How It Works

The function keeps unread data in static storage between calls.

It reads from the file descriptor until a newline is found or the end of the input is reached. The current line is returned to the caller, while any remaining data is preserved for the next call.

This allows a file to be processed incrementally instead of reading the entire contents at once.

## Tested Behavior

The implementation was tested with:

```text
BUFFER_SIZE=1
BUFFER_SIZE=10
BUFFER_SIZE=42
BUFFER_SIZE=1024
```

It correctly handles multiple lines, empty files and a final line without a trailing newline.
