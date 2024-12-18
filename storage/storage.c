#include "../includes/dbconstants.h"
#include "../includes/storage.h"
#include "sqlite3.h"
#include <stdio.h>

int create_storage_db(const char* database_name){
    sqlite3 *db;
    int create_storage = sqlite3_open(database_name, &db);
    if (!create_storage) {
        fprintf(stderr, _sqlite_open_err); 
        sqlite3_close(&db);
        return EXIT_FAILURE;
    }
    create_storage = sqlite3_exec(&db, _create_users_table, 0, 0, &_generic_err_msg);
    if (!create_storage) {
        fprintf(stderr, _sqlite_exec_err); 
        sqlite3_free(_generic_err_msg);
        sqlite3_close(&db);
        return EXIT_FAILURE;
    }
    sqlite3_close(&db);
    return EXIT_SUCCESS;
}