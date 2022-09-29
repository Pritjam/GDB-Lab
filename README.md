How to use this demo:

First, run `make all`, to get everything ready.

Next, try running `_broken`, the first executable binary. What happens? Does it run correctly?
    Of course, given the name, it's broken. Let's see if we can find out how to fix it. Take a look at 
    `gdb_lab.c`, the source code for this executable, to see if we can find out what's going wrong.
    
    Next, run the code through `gdb` to see if we can pinpoint where an error occurs. You may find it useful to break
    on the indicated lines, where there's a comment of `BREAK HERE`.

Now, once we've fixed those, we should have a running executable. That's what `gdb_lab_memleaks.c` has, and you can see the differences.

Optionally, you can take things a step further and use `valgrind` to identify another bug, called a memory leak. This happens when we 
don't `free` memory that we've allocated previously.
    To get started, run `valgrind _memleaks` to run Valgrind on the `_memleaks` binary. This will allow you to see how many bytes are being lost.
    Then, you can run valgrind with the `--leak-check=full` option to see exactly where memory is being allocated, to help pin things down. Use
    `valgrind --leak-check=full _memleaks` for that.
    Can you figure out how to free the leaking memory? Some of it will be easy, some of it will not be.