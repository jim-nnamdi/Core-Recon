#include <stdio.h>

int _window_width = 600;
int _window_height = 600;

const char* Database_Name = "recon.db";
const char* _sqlite_open_err = "could not open database";
const char* _sqlite_exec_err = "could not execute query";
const char* _sqlite_insert_err = "error inserting data";
const char* _generic_err_msg = "generic error";

// Queries
const char* _create_users_table = "create table if not exist users(id INTEGER PRIMARY KEY, username TEXT, password TEXT, email_address TEXT, location TEXT, facial_recognition_id INTEGER, verified TEXT)";
const char* _check_user_data     = "select * from users where email = ?";
const char* _get_all_recon_users = "select * from users";