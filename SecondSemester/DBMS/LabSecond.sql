create database labsecond;
use labsecond;

create table Movie (mid int primary key,title varchar(30), yor date, duration time, language varchar(20));
create table Actor (aid int primary key,aname varchar(30),gender varchar(5),dob date);
create table Director (did int primary key,fname varchar(10),lname varchar(10),gender varchar(5),address varchar(20));
create table Reviewer (rid int primary key,rname varchar(20));
create table Genere (gid int primary key,genereType varchar(20)); 
create table ActsIn (mid int,aid int,role varchar (20), foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (aid) references Actor (aid) on update cascade on delete cascade);

create table Review (mid int,rid int,rate int, foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (rid) references Reviewer (rid) on update cascade on delete cascade);

create table Direct (mid int,did int,foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (did) references Director (did) on update cascade on delete cascade);

create table BelongTo (mid int,gid int,foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (gid) references Genere (gid) on update cascade on delete cascade);

desc Movie;
desc ActsIn;