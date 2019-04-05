#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


#include "../includes/read_file.h"
#include "../includes/parser.h"
#include "../includes/gen_code.h"
#include "../includes/buffer.h"

int     main(int argc, char const* argv[])
{
    if (argc < 1)
        return (EXIT_FAILURE);
    for (int i = 1; argv[i]; ++i) {
        size_t len = ft_strlen(argv[i]);
        bool fail = false;

        if ((len <= 2) || (ft_strcmp(argv[i] + (len-2), ".s"))) {
            errorf(0, "Bad file name (%s).", argv[i]);
            continue;
        }

        pendingf(true, "Trying to open '%s'.", argv[i]);
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            errorf(0, "Unable to open '%s'.", argv[i]);
            continue;
        }
        completef(true, "Open '%s' with success.", argv[i]);

        char* stream = read_file(fd);
        if (!stream) {
            errorf(0, "The file '%s' cannot be read.", argv[i]);
            fail = true;
        }
 
        pendingf(!fail, "Trying to parse '%s'.", argv[i]);
        program_rep* prog = parse(stream);

        if (prog) {
            completef(true, "Parsing of '%s' succeed.", argv[i]);
            buffer_t* buff = gen_program_rep(prog);

            if (buff) {
                completef(true, "Semantic of '%s' succeed.", argv[i]);

                char* new_filename = (char*)malloc(sizeof(char)*(len+3));            
                if (!new_filename) {
                    errorf(0, "Not enough memory.");
                    exit(EXIT_FAILURE);
                }

                ft_strcpy(new_filename, argv[i]);
                ft_strcpy(new_filename + (len-2), ".cor");

                pendingf(true, "Trying to open '%s'.", new_filename);
                int fd = open(new_filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);

                if (fd == -1) {
                    errorf(0, "Unable to open '%s'.", new_filename);
                    fail = true;
                } else
                    { completef(true, "Open '%s' with success.", new_filename); }

                if (write_file_buffer(buff, fd) == -1) {
                    errorf(0, "The file '%s' cannot be read.", new_filename);
                    fail = true;
                }
                completef(!fail, "Code generation of '%s' succeed.", argv[i]);

                free((void*)new_filename);
                close(fd);
            }
            del_buffer(buff);
        }
        else
            { errorf(0, "Parsing of '%s' failed.", argv[i]); }
        clean_parser();
        close(fd);
    }
    return (EXIT_SUCCESS);
}
