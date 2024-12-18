#include <stdio.h>
#include <stdlib.h>
#include "../storage/sqlite3.h"

sqlite3* create_storage_db(const char* database_name);
int create_new_user(sqlite3* db, const char* username, const char* password, const char* email);