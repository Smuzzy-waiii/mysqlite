#pragma once
#include "../repl_helper/repl_helper.h"
#include <string.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { 
  PREPARE_SUCCESS, 
  PREPARE_SYNTAX_ERROR,
  PREPARE_STRING_TOO_LONG,
  PREPARE_ID_NEGATIVE,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef struct {
	uint32_t id;
	char username[COLUMN_USERNAME_SIZE+1]; //Adding 1 coz strings are NULL terminated
	char email[COLUMN_EMAIL_SIZE+1]; //which takes up one char and therefore otherwise
	// will be able to store max 31 and 254 chars respectively only
} Row;

typedef enum { 
	STATEMENT_INSERT, 
	STATEMENT_SELECT 
} StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement);