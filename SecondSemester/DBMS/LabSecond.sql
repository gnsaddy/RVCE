create database labsecond;
use labsecond;

create table Movie (mid varchar(10) primary key,title varchar(30), yor date, duration time, language varchar(20),startD date);
create table Actor (aid varchar(10) primary key,aname varchar(30),gender varchar(5),dob date);
create table Director (did varchar(10) primary key,fname varchar(10),lname varchar(10),gender varchar(5),address varchar(20));
create table Reviewer (rid varchar(10) primary key,rname varchar(20));
create table Genere (gid varchar(10) primary key,genereType varchar(20)); 


create table ActsIn (mid varchar(10) ,aid varchar(10) ,role varchar (20), foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (aid) references Actor (aid) on update cascade on delete cascade);

create table Review (mid varchar(10) ,rid varchar(10) ,rate int,rateStar int, foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (rid) references Reviewer (rid) on update cascade on delete cascade);

create table Direct (mid varchar(10) ,did varchar(10) ,foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (did) references Director (did) on update cascade on delete cascade);

create table BelongTo (mid varchar(10) ,gid varchar(10) ,foreign key (mid) references Movie(mid) on update cascade on delete cascade,
foreign key (gid) references Genere (gid) on update cascade on delete cascade);

alter table ActsIn add primary key(mid,aid);
alter table Review add primary key(mid,rid);
alter table Direct add primary key(mid,did);
alter table BelongTo add primary key(mid,gid);

drop table Review;

desc Movie;
desc ActsIn;
desc Review;
desc Direct;
desc BelongTo;
describe Actor;

-- ***************************

insert into Movie values("m101","Ra-one","2015-06-25","2:30","Hindi","2014-02-11"),("m102","Krish","2014-06-25","2:30","Hindi","2013-02-11"),
("m103","fast&furious1","2001-06-25","2:30","English","2000-02-11");
select * from Movie;
insert into Actor values("a101","Ritik","M","1985-05-28"),("a102","Skhan","M","1975-05-28"),("a103","John","M","1988-05-28")































  
