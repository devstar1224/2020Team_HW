#include<stdio.h>
#include<stdlib.h>
#include</usr/include/mysql/mysql.h>

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;
int query_stat;

int LoanBook() {
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
    char mem_rfid[] = "90635800";
    char book_rfid[] = "90633F02";
    char query[500];

    sprintf(query, "insert into book_loan(mem_id, id_num) values((select mem_id from member where rfid = '%s'),(select id_num from book_info where rfid = '%s'))" , mem_rfid, book_rfid);

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
        return 1;
    }
    printf("query sucsess\n");
    mysql_close(conn);

    return 0;
}

int main(int argc, char** argv) {
    printf("main---\n");

    //int temp = mysql_test();
    int temp = LoanBook();

    return 0;
}
