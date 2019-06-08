create database moviedb;
use moviedb;

create table Movie(mid varchar(5),constraint pk_mid primary key(mid),
title varchar(25)not null,duration int not null,yor int not null,language varchar(20));

create table Actor(aid varchar(5),constraint pk_aid primary key(aid),
fname varchar(20) not null,lname varchar(20),gender varchar(15));

create table Director(did varchar(5),constraint pk_did primary key(did),
fname varchar(20) not null,lname varchar(20),gender varchar(15));

create table Reviewer(rid varchar(5),constraint pk_rid primary key(rid),rname varchar(20) not null);

create table Genre(gid varchar(5),constraint pk_gid primary key(gid),type varchar(20) not null);


create table Review(rid varchar(5),constraint rfk_rid foreign key(rid) references Reviewer(rid)
 on delete cascade on update cascade,mid varchar(5),
 constraint rfk_mid foreign key(mid) references Movie(mid) on delete cascade on update cascade);

create table BelongTo(gid varchar(5),constraint bfk_gid foreign key(gid) references Genre(gid) 
on delete cascade on update cascade,
mid varchar(5),constraint bfk_mid foreign key(mid) references Movie(mid) on delete cascade on update cascade);

create table Act(aid varchar(5),constraint afk_aid foreign key(aid) references Actor(aid) 
on delete cascade on update cascade,
mid varchar(5),constraint afk_mid foreign key(mid) references Movie(mid) on delete cascade on update cascade);

create table Direct(did varchar(5),constraint dfk_did foreign key(did) references Director(did) 
on delete cascade on update cascade,
mid varchar(5),constraint dfk_mid foreign key(mid) references Movie(mid) on delete cascade on update cascade);

Alter table Act add role varchar(20) not null;
Alter table Review add rate int(1);

-- insert 

insert into Movie values('mov01','Mouse Hunt',150,1990,'English');
insert into Movie values('mov02','Silver Line',140,2000,'English');
insert into Movie values('mov03','Eyes Wide Shut',120,2005,'English');
insert into Movie values('mov04','Up',160,2010,'English');

insert into Actor values('act01','Robert','Downey','male');
insert into Actor values('act02','Stoney','Lane','male');
insert into Actor values('act03','Angelina','Jolie','female');
insert into Actor values('act04','Diana','Lenon','female');

insert into Director values('dir01','Zoya','Aktar','female');
insert into Director values('dir02','Stoney','Lane','male');

insert into Reviewer values('rev01','Karan');
insert into Reviewer values('rev02','Shyam');

insert into Genre values('gen01','Thriller');
insert into Genre values('gen02','Comedy');

insert into Act values('act01','mov01','Hero');
insert into Act values('act02','mov02','Hero');
insert into Act values('act02','mov03','Hero');
insert into Act values('act03','mov01','Heroine');
insert into Act values('act04','mov03','Heroine');
insert into Act values('act01','mov04','Hero');

insert into Direct values('dir01','mov01');
insert into Direct values('dir01','mov02');
insert into Direct values('dir02','mov03');
insert into Direct values('dir02','mov04');

insert into Review values('rev01','mov01',4);
insert into Review values('rev01','mov02',5);
insert into Review values('rev01','mov03',3);
insert into Review values('rev02','mov01',5);

insert into BelongTo values('gen01','mov01');
insert into BelongTo values('gen02','mov01');
insert into BelongTo values('gen02','mov02'); 

-- query 1

select title from Movie where yor<1998; 
-- query 2
select d.fname,d.lname from Director d,Direct dt,Movie m,Actor a,Act t where 
d.fname=a.fname and d.lname=a.lname and d.did=dt.did and dt.mid=m.mid and a.aid=t.aid 
and t.mid=m.mid and title='Eyes Wide Shut';
-- query 3  
  select rv.rname,m.title,r.rate from Review r join Reviewer rv on rv.rid = r.rid join Movie m on m.mid = r.mid where 
  r.rid = ANY(select rv.rid from Review rv join Reviewer r on rv.rid=r.rid group by r.rid having count(rv.rid)>1);
  -- query 4
  select distinct(yor),r.rate from Movie m join Review r on m.mid=r.mid where r.rate>3;
  -- query 5
  select a.fname,m.title,m.yor from Act at join Actor a on a.aid=at.aid join Movie m on at.mid=m.mid
  where yor not between 1990 and 2000;
  -- query 6
select type as GenreTitle,avg(duration) as AverageTime,count(b.mid) as NoOfMovies from 
Genre g join BelongTo b on g.gid=b.gid join Movie m on m.mid=b.mid group by b.gid;
  
  
  
  
  
  