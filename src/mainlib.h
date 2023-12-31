#include "stdio.h"
#include <stddef.h>

typedef struct {
    long long pointer;
    int *machine;
} Context;

/// @brief Gets the 8-bit value at the current `pointer` position in the current machine
/// @param ctx The context in question
/// @return The value pointed by the internal pointer
int get(Context *ctx);

/// @brief Gets a reference to the 8-bit value at the current `pointer` position in the current machine
/// @param ctx The context in question
/// @return A reference to the value pointed by the internal pointer (might be mutated thus)
int *get_pt(Context *ctx);


typedef struct {
    char *looping_instr;
    size_t len;
} Loop;

/// @brief Sets the loop status when encountering an opening bracket
/// @param loop The loop context
/// @param instructions Flow of instructions
/// @param from The starting point of the loop
/// @param len The length of the instruction flow
/// @return The index of the closing bracket (propagation is useful sometimes :))
long set_loop(Loop *loop, char *instructions, long from, size_t len);


/// @brief Initialise the main context (machine + pointer)
/// @param ctx The context to initialize
/// @param machine_len The length of the internal machine
void context_init(Context *ctx, long long machine_len);

/// @brief Processes the flow of instructions
/// @param ctx The context, which may vary during the program execution
/// @param instructions The flow of instructions to follow
/// @param len The length of the flow
/// @return 
void execute(Context *ctx, char *instructions, size_t len);

/// @brief Checks the validity  of the instructions flow (in terms of loop(s) arrangement)
/// @param instructions The intructions flow
/// @param len The length of the flow
/// @return 
int check_validity(char *instructions, size_t len);// Check loop validity (wrapper arounf total_count_relative)

/// @brief For handling loops (capture inbetween instructions and return to flow after execution)
/// @param instructions The flow of instructions
/// @param len The length of the flow
/// @param start The starting point of the loop
/// @param ctx The context
long handle_loop(char *instructions, size_t len, size_t start, Context *ctx);


//Utils
long seek(char *flow, long beg, size_t len, char pred);
long long file_len(FILE* fp); // Gets file_len (util function)
int read_sequence(FILE *fp, char buff[], size_t buf_len); // Stores the flow of instructions into tokens into buff
char *substr(char *str, size_t len, size_t idx_pro, size_t idx_post);
int clamp(int value, int min, int max);
long total_count_relative(char *str, char pred_plus, char pred_minus, size_t len);
//long long relative_offset_count(char *instructions, size_t machine_len);