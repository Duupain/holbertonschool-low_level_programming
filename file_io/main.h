#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error(int exit_code, const char *message, const char *filename);
int main(int argc, char *argv[]);

#endif /* MAIN_H */
