#include<stdio.h>
#include<stdlib.h>
#include</usr/include/mysql/mysql.h>

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;
int query_stat;

int mysql_test() {
    conn = mysql_init(NULL);

    if (!conn) {
        printf("error");
        exit(0);
    }
    else {
        printf("debug!\n");
    }

    conn = mysql_real_connect(conn, "slobrary.com", "slo", "legoslo2020", "slo", 0, NULL, 0);
    if (conn) {
        printf("Success!\n");
    }
    else {
        printf("connect error!\n");
    }

    if (mysql_query(conn, "select status from book_info")) {
        printf("query fail\n");
        exit(1);
    }

    printf("query sucsess\n");
    res = mysql_store_result(conn);
    printf("res suc\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s %s\n", row[0], row[1]);
    }

    mysql_close(conn);

    return 0;
}


int main(int argc, char** argv) {
    printf("main---\n");

    int temp = mysql_test();
    return 0;
}
