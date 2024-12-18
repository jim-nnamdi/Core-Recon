#include "../includes/dbconstants.h"
#include "../includes/storage.h"
#include "sqlite3.h"
#include <stdio.h>

int create_storage_db(const char* database_name){
    sqlite3 *db;
    int create_storage = sqlite3_open(database_name, &db);
    if (create_storage != SQLITE_OK) {
        fprintf(stderr, _sqlite_open_err); 
        sqlite3_close(&db);
        return EXIT_FAILURE;
    }
    create_storage = sqlite3_exec(&db, _create_users_table, 0, 0, &_generic_err_msg);
    if (create_storage != SQLITE_OK) {
        fprintf(stderr, _sqlite_exec_err); 
        sqlite3_free(_generic_err_msg);
        sqlite3_close(&db);
        return EXIT_FAILURE;
    }
    sqlite3_close(&db);
    return EXIT_SUCCESS;
}

int create_new_user(sqlite3* db, const char* username, const char* password, const char* email){
    const char* add_user_query = "insert into users(username, password, email_address) values(?,?,?)";
    sqlite3_stmt* stmt; int result_stmt;
    result_stmt = sqlite3_prepare_v2(&db, add_user_query, -1, &stmt, NULL);
    if (result_stmt != SQLITE_OK) fprintf(stderr, _sqlite_exec_err); sqlite3_errmsg(&db);

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email, -1, SQLITE_STATIC);

    result_stmt = sqlite3_step(&stmt);
    if (result_stmt != SQLITE_DONE) printf(_sqlite_exec_err);
    sqlite3_finalize(stmt);
    return result_stmt == SQLITE_DONE ? SQLITE_OK : result_stmt;
}