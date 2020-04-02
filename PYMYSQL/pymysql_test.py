import pymysql
 
# MySQL Connection 연결 #dmu201820
conn = pymysql.connect(host='autobrary.ckz6fkudmcim.ap-northeast-2.rds.amazonaws.com', user='admin', password='dmu201820',
                       db='autobrary', charset='utf8')
 
# Connection 으로부터 Cursor 생성
curs = conn.cursor()
 
# SQL문 실행
sql = "select * from member"
curs.execute(sql)

# 데이타 Fetch
rows = curs.fetchall()
print(rows)     #전체 rows

##data = curs.fetchall()
##data[0] #첫번째 row
##data[1] #두번째 row
 
# Connection 닫기
conn.close()
