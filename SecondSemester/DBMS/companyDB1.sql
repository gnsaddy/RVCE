# Tables creation
create database companyDB;
use companyDB;

create table Employee (ssn int primary key not null,
ename varchar(20) not null,
sex varchar(5) not null,
dob date not null,
salary int not null,
hire date not null,
superSSn int,
did int);

desc Employee;

create table Department (did int primary key not null,
dname varchar(30) not null,
startdate date not null,
ssn int,
foreign key (ssn) references Employee (ssn) ON UPDATE CASCADE ON DELETE CASCADE);

desc Department;

create table Project (pid int primary key not null,
pname varchar(30) not null,
ploc varchar(30) not null,
did int,
foreign key (did) references Department (did) ON UPDATE CASCADE ON DELETE CASCADE);

desc Project;

create table Dependent (ssn int,
name varchar(30) not null,
rel varchar(30) not null,
dob date not null,
foreign key (ssn) references Employee (ssn) ON UPDATE CASCADE ON DELETE CASCADE);

desc Dependent;

create table WorksIn (ssn int,
pid int,
hours time not null,
foreign key (ssn) references Employee (ssn) ON UPDATE CASCADE ON DELETE CASCADE,
foreign key (pid) references Project (pid) ON UPDATE CASCADE ON DELETE CASCADE);

desc WorksIn;

create table Dept_loc (did int,
dloc varchar(30) not null,
foreign key (did) references Department (did) ON UPDATE CASCADE ON DELETE CASCADE);

desc Dept_loc;

# Alteration in tables

Alter table Employee ADD foreign key (did) references Department (did) ON UPDATE CASCADE ON DELETE CASCADE;

Alter table Employee ADD foreign key (superSSN) references Employee (ssn) ON UPDATE CASCADE ON DELETE CASCADE;


-- # Alteration of columns

-- Alter table Employee change superSSn superSSN int;
-- Alter table Employee change did did int;
-- Alter table Department change ssn ssn int;
-- Alter table Project change did did int;
-- Alter table Dependent change ssn ssn int;
-- Alter table WorksIn change ssn ssn int;
-- Alter table WorksIn change pid pid int;
-- Alter table Dept_loc change did did int;





