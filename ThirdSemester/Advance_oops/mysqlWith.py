import MySQLdb as ms


class TestDB(object):
    ''' mysql connection '''

    def __init__(self, host='localhost', user='root', passwd='', database='testpymysql'):
        self.host = host
        self.user = user
        self.passwd = passwd
        self.database = database
        self.con = None
        self.cur = None

    def __enter__(self):
        self.con = ms.connect(self.host, self.user, self.passwd, self.database)
        self.cur = self.con.cursor()

    def __exit__(self, exe_type, exe_val, exe_tb):
        self.con.close()


tdb = TestDB()

with tdb:
    v = tdb.cur.execute("select * from st")
    print(tdb.cur.fetchall())
