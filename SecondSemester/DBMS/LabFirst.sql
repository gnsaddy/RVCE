create database labFirst;
use labFirst;

create table Department(did varchar(20) primary key,dname varchar(20));
create table SalaryGrade(grade varchar(5) primary key,maxSal int,minSal int);

create table Employee(ssn varchar(20) primary key,ename varchar(20),address varchar(20),
desig varchar(20),commi int,salary int,did varchar(20),hssn varchar(20),salGrade varchar(5),
foreign key (did) references Department (did) on update cascade on delete cascade,
foreign key (hssn) references Employee (ssn) on update cascade on delete cascade,
foreign key (salGrade) references SalaryGrade (grade) on update cascade on delete cascade);

insert into Department values('ML101','Machine Learning');
insert into Department values('MEAN301','MEAN stack developer');
insert into Department values('MERN401','MERN developer');
insert into Department values('AI201','AI');
select * from Department;
select * from SalaryGrade;
select * from Employee;

insert into SalaryGrade values('A',20001,35000);
insert into SalaryGrade values('B',35001,50000);
insert into SalaryGrade values('C',50001,70000);
insert into SalaryGrade values('D',70001,85000);

insert into Employee values('CEO07','Sataya Nagar','Delhi','CEO',25000,82000,null,null,'D');
insert into Employee values('MLHEAD008','Sundar Desai','Banglore','ML Head',22000,68000,'ML101','CEO07','C');
insert into Employee values('ML01','Suman','Delhi','ML engineer',18000,32000,'ML101','MLHEAD008','A');
insert into Employee values('ML02','Tanya Sharma','Delhi','Analyst',18000,45000,'ML101','MLHEAD008','B');
insert into Employee values('ML03','Saurav','Delhi','Content Writer',12000,25000,'ML101','MLHEAD008','A');

insert into Employee values('AIHEAD009','Akash Suri','Delhi','AI Head',22000,68000,'AI201','CEO07','C');
insert into Employee values('AI01','Alok','Delhi','AI engineer',18000,34000,'AI201','AIHEAD009','A');
insert into Employee values('AI02','Kush Sharma','Banglore','Analyst',18000,43000,'AI201','AIHEAD009','B');


-- Query 
select ename, salary,concat("$",salary*1.25) as dollar_salary from Employee;
select desig, avg(salary) from Employee where desig = 'Analyst';
select * from Employee as E, Department as D where E.did = D.did and D.dname != 'AI';
select D.*, count(E.did) as Max_occurence from Employee as E, Department as D where E.did = D.did group by 
E.did having count(E.did) >= ALL (select count(did) from Employee group by did);














