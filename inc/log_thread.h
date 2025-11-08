#pragma once

struct log_info {
    int id;
    char time[32];
    char passed[8];
};

void write_log(int is_pass);
int read_log(struct log_info* info, int len, int start);
