#pragma once
#include "../SQLCompiler/SQLCompiler.h"

typedef enum {
  EXECUTE_TABLE_FULL,
  EXECUTE_SUCCESS
} ExecuteResult;

// defining Table --------------------------------------------------
#define TABLE_MAX_PAGES 100

typedef struct {
  uint32_t num_rows;
  void* pages[TABLE_MAX_PAGES];
} Table;

Table* new_table();
void free_table(Table* table);
//-----------------------------------------------------------------

void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);

ExecuteResult execute_statement(Statement* statement, Table* table);
