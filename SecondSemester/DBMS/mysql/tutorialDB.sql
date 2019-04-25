use testdb;
show tables;
select * from Department;
select * from Employee;
select * from SalaryGrade;

-- 1) 
select distinct(designation) from Employee e,Department d where e.deptid=d.deptid;

-- 2)
select e.ename from Employee e where length(ename)>6;
-- 3)

-- 4)
select e.ename,(e.salary*12),d.deptid,d.dname,e.sgrade from Employee e,Department d
where e.deptid=d.deptid and e.salary>60000 or not e.designation="Analyst";
-- 5)

-- 6)
select e.* from Employee e,Department d where e.deptid=d.deptid and dname="Production" and dloc in ("Banglore","Manglore") 
and sgrade in("B","D");
-- *******************************************
-- tutorial third
-- 1)


-- 2)
select e.* from Employee e where e.sgrade IN("A","C") and e.designation IN ("Analyst","Manager");
-- 3)

-- 4)
select e.ename,e.designation,d.dname,d.dloc from Employee e INNER JOIN Department d on e.deptid=d.deptid
and e.designation="Manager";

-- 5)

select dname from Department where length(dname)=ANY (select count(e.ename) from 
Employee e,Department d where e.deptid=d.deptid group by d.dname);












