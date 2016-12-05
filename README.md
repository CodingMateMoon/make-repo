# em (Easy Makefile)  - advprog term project

## A program for easy use of 'GNU make' for C language

### usage
        em [-p] [--print] [-s <file_name>] [--source <file_name>]
           [-o <file_name>] [--output <file_name>]
           [-a <file_name>] [--add <file_name>]
           [-d <file_name>] [--delete <file_name>]
           [-l <library>] [--lib <library>]
           [-f <option>] [--flag <option>]
           [-c] [--clean] [-v] [--version] [-h] [--help]

### Details about options
        -p, --print      : print Makefile's context.
        -s, --source <file_name> : print Makefile's source files. --all is print all source files.
        -o, --output <file_name> : modify Makefile's output(target) file name
        -a, --add <file_name>    : Add Makefile's source files
        -d, --delete <file_name> : Delete Makefile's source files
        -l, --lib <library>      : Add Makefile's libraries
        -f, --flag <option>      : Add Makefile's compile options
        -c, --clean      : execute make's clean
        -v, --version    : print version of em.
        -h, --help       : print Usage for em. (This Page.)
