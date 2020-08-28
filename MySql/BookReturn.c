#include<stdio.h>
#include<stdlib.h>
#include</usr/include/mysql/mysql.h>

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;
int query_stat;
int mem_rfid, book_rfid;

int ReturnBook(int mem_rfid, int book_rfid) {
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
    char query[500];

    sprintf(query, "UPDATE book_loan set status = '%s', return_date = now() WHERE mem_id = (select mem_id from member where rfid = %d) and id_num = (select id_num from book_info where rfid = %d) and status = '%s'" ,"π›≥≥", mem_rfid, book_rfid, "¥Î√‚");

    query_stat = mysql_query(conn, query);
    if (query_stat != 0) {
        fprintf(stderr, "Mysql query error : %s", mysql_error(conn));
        return 1;
    }
    printf("query sucsess\n");
    mysql_close(conn);

    return 0;
}

int main(int argc, char** argv) {
    printf("main---\n");

    //int temp = mysql_test();
    int temp = ReturnBook(mem_rfid, book_rfid);

    return 0;
}
