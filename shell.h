#ifndef CUSTOM_SHELL_H
#define CUSTOM_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ENV_VARS 100
#define MAX_INPUT_LENGTH 1024

extern int num_custom_env_vars;
extern char **custom_environ;

/**
 * struct CustomEnvVar - Structure to represent an environment variable.
 * @name: The name of the environment variable.
 * @value: The value associated with the environment variable.
 */
struct CustomEnvVar
{
    char *name;
    char *value;
};

void strip_comments(char *input);
void execute_custom_setenv(const char *variable, const char *value);
void execute_custom_unsetenv(const char *variable, const char *shell_name);
int my_custom_setenv(const char *name, const char *value, int overwrite);
int my_custom_unsetenv(const char *name);
char *int_to_string_custom(int num);
void display_custom_prompt(void);
void execute_custom_exit(char **args);
void execute_custom_env(void);
int execute_custom_command(const char *shell_name, const char *command, char *args[]);
void tokenize_custom_input_line(char *input, char **command, char *args[], int *num_args);
void execute_command_in_custom_path(const char *shell_name, const char *command, char *args[]);
int read_custom_input_line(char **input, size_t *input_length, const char *shell_name);
void execute_custom_cd(char *args[]);
void copy_custom_string(char *destination, const char *source);
int compare_custom(const char *a1, const char *a2);
int my_custom_Atoi(const char *string);
size_t my_custom_strcspn(const char *str, const char *str2);
size_t custom_string_len(const char *w);
char *sub_custom_string(const char *longstring, const char *single);
int custom_string_cmp(const char *a1, const char *a2, size_t b);
char *concat_custom(char *dt, const char *source);
char *duplicate_custom(const char *string);
void execute_individual_custom_command(char *shell_name, char *command, char *args[]);
char *handle_custom_variables(const char *input, const char *shell_name, pid_t pid);
char *my_custom_path(const char *command);
void process_custom_command(const char *command, char **args, int num_args, const char *shell_name);
char *my_custom_strchr(const char *str, int c);
char *my_custom_strncpy(char *dest, const char *src, size_t n);
char *my_custom_strstr(const char *haystack, const char *needle);

#endif

