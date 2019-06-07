use labFirst;

-- query 1
select  ename,concat("$",salary*1.25) as "Incremented Salary" from Employee;
-- query 2
select desig,avg(salary) from Employee where desig='analyst' ;
-- query 3
select * from Employee e natural join Department d where e.did=d.did and d.dname != "Finance"; 
-- query 4
select d.*,count(e.did) from Employee e,Department d where d.did=e.did group by e.did having count(e.did) >= 
ALL(select count(did) from Employee group by did); 
-- query 5
select ename,salary,commi from Employee where (select max(salary+commi) from Employee) >= ANY(select salary from Employee);
-- query 6
select d.* from Department d left join Employee e on d.did=e.did where e.did is null;
  
