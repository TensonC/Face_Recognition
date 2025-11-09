#include "log_thread.h"

#include <stdio.h>
#include <sqlite3.h>
#include <time.h>
#include <string.h>

#define DATABASE_FILE "recognition.db"

static int get_time(struct tm* ti) {
    time_t current;

    time(&current);

    ti = localtime(&current);
    (*ti).tm_year += 1900;

    return 0;
}

static int create_table(sqlite3 *db) {
    const char* sql = 
            "CREATE TABLE IF NOT EXISTS recognition ("  \
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"     \
            "TIME TEXT,"                                \
            "PASSED TEXT"                               \
            ");";

    char* errmsg = NULL;
    if(sqlite3_exec(db,sql,0,0,&errmsg) != SQLITE_OK) {
        printf("Create table failed: %s\n",errmsg);
        sqlite3_free(errmsg);
        return -1;
    }

    return 0;
}

static int insert_log(sqlite3* db,int is_pass) {
    char sql[256];
    char *errmsg = NULL;
    struct tm ti;
    char time_str[32];
    char passed[8]; 

    strcpy(passed, is_pass ? "PASS" : "UNPASS");

    get_time(&ti);
    strftime(time_str,sizeof(time_str),"%Y-%m-%d %H:%M:%S",&ti);

    snprintf(sql,sizeof(sql),
             "INSERT INTO recognition (TIME, PASSED) VALUES ('%s', '%s');",
             time_str,passed);

    if (sqlite3_exec(db, sql, 0, 0, &errmsg) != SQLITE_OK) {
        printf("Insert failed: %s\n",errmsg);
        sqlite3_free(errmsg);
        return -1;
    }

    return 0;
}

int read_log(struct log_info* info, int len, int start) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char sql[128];
    int size = 0;

    snprintf(sql, sizeof(sql), 
            "SELECT ID,TIME,PASSED FROM recognition LIMIT %d OFFSET %d;",
            len, start);

    if (sqlite3_open(DATABASE_FILE,&db) != SQLITE_OK) {
        printf("Can't open database: %s\n",sqlite3_errmsg(db));
        return -1;
    }

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("SQL prepare failed: %s\n",sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        info->id = sqlite3_column_int(stmt,0);
        strcpy(info->time,(const char*)sqlite3_column_text(stmt,1));
        strcpy(info->passed,(const char*)sqlite3_column_text(stmt,2));
        
        info++;
        size++;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return size;
}

void write_log(int is_pass) {
    sqlite3* db;

    if (sqlite3_open(DATABASE_FILE,&db) != SQLITE_OK) {
        printf("Can't open database: %s\n",sqlite3_errmsg(db));
        return;
    }

    create_table(db);

    insert_log(db,is_pass);

    sqlite3_close(db);
    return;
}




