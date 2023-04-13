#pragma once
#include "../SQLCompiler/SQLCompiler.h"
#include <fcntl.h>
#include <unistd.h>

typedef enum {
  EXECUTE_TABLE_FULL,
  EXECUTE_SUCCESS
} ExecuteResult;

// defining Table --------------------------------------------------
#define TABLE_MAX_PAGES 100

typedef struct {
  int file_descriptor;
  uint32_t file_length;
  void* pages[TABLE_MAX_PAGES];
} Pager;

typedef struct {
  uint32_t num_rows;
  Pager *pager;
} Table;

Table* new_table();
void free_table(Table* table);
//-----------------------------------------------------------------

void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

ExecuteResult execute_statement(Statement* statement, Table* table);
