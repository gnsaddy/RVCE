show databases;
create database expenseManagement;
use expenseManagement;

create table Admin(adminId varchar(20) primary key,fname varchar(15),lname varchar(15),email varchar(30),age int,contact long,address varchar(40));
desc Admin;

create table User(userId varchar(20) primary key,adminId varchar(20), fname varchar(15),
lname varchar(15),email varchar(30),age int,contact long,address varchar(40),
netIncome long,otherIncome long,foreign key (adminId) references Admin (adminId) on delete cascade on update cascade);
desc User;

create table UserType(userId varchar(20),uType varchar(30),foreign key (userId) references User (userId));
alter table UserType add constraint primary key(userId,uType);
desc UserType;

create table Expense(expenseId varchar(20) primary key,expenseDate date,miscelleneous long);
desc Expense;

create table HasExpense (userID varchar(20), expenseId varchar(20),
foreign key (userId) references User(userId) on update cascade on delete cascade,
foreign key (expenseId) references Expense (expenseId) on delete cascade on update cascade);
alter table HasExpense add primary key(userId,expenseId);
desc HasExpense;

create table FlexibleExpense(expenseId varchar(20),flexibleType varchar(30),amount long,
foreign key (expenseId) references Expense (expenseId) on update cascade on delete cascade);
alter table FlexibleExpense add constraint primary key(expenseId,flexibleType);
desc FlexibleExpense;

create table FixedExpense(expenseId varchar(20),fixedType varchar(30),amount long,
foreign key (expenseId) references Expense (expenseId) on update cascade on delete cascade);
alter table FixedExpense add constraint primary key(expenseId,fixedType);
desc FixedExpense;


-- ********************************* insert to table ***************************

insert into Admin values("admin01","Aditya","Raj","aditya123@gmail.com",21,8271388851,"Banglore");

-- **************************************
insert into User values("user01","admin01","Bhaskar","U","bhaskar123@gmail.com",20,123456789,"Kolkata",22400,2000),
("user02","admin01","Akash","p","akash123@gmail.com",20,456321789,"Banglore",6500,1000);
insert into User values("user03","admin01","Ajith","gv","ajith123@gmail.com",21,789654123,"Sirsi",15000,500),
("user04","admin01","Akhil","S","akhil123@gmail.com",22,852369147,"Kengeri",9500,4500),
("user05","admin01","Arun","GA","arun123@gmail.com",22,456258741,"Shimoga",26500,2500),
("user06","admin01","Shrikant","p","shrikant123@gmail.com",23,95123546,"Bidar",4500,5500);
insert into User values("user07","admin01","Amit","S","amit123@gmail.com",23,963987412,"Delhi",42000,1550),
("user08","admin01","Alok","t","alok123@gmail.com",20,753159852,"Banglore",7500,1500),
("user09","admin01","Adarsh","t","adarsh123@gmail.com",21,125896321,"Noida",45000,1250),
("user10","admin01","Suman","Du","suman123@gmail.com",21,26598741,"Noida",35000,2500);

-- **************************************
insert into UserType values("user01","salaried"),("user02","unsalaried"),("user03","salaried"),
("user04","unsalaried"),("user05","salaried"),("user06","unsalaried"),("user07","salaried"),
("user08","unsalaried"),("user09","salaried"),("user10","salaried");

-- ******************************************
INSERT INTO Expense VALUES ('exp01', '2019-02-11', '1500');
INSERT INTO Expense VALUES ('exp02', '2019-01-15', 'NULL');
INSERT INTO Expense VALUES ('exp03', '2019-02-20', '1000');
INSERT INTO Expense VALUES ('exp04', '2019-03-01', '500');
INSERT INTO Expense VALUES ('exp05', '2019-04-10', '600');
INSERT INTO Expense VALUES ('exp06', '2019-04-02', 'NULL');
INSERT INTO Expense VALUES ('exp07', '2019-03-15', '1800');
INSERT INTO Expense VALUES ('exp08', '2019-03-20', '2200');
INSERT INTO Expense VALUES ('exp09', '2019-02-25', '1500');
INSERT INTO Expense VALUES ('exp10', '2019-02-27', '1400');
-- **************************************
insert into HasExpense values("user01","exp01"),("user02","exp02"),("user03","exp03"),("user04","exp04"),
("user05","exp05"),("user06","exp06"),("user07","exp07"),("user08","exp08"),("user09","exp09"),("user10","exp10");
-- **************************************
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp01', 'food', '500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp01', 'travel', '2000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp02', 'travel', '5000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp02', 'food', '600');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp02', 'medical', '1000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp03', 'food', '1500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp03', 'travel', '2000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp04', 'medical', '500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp04', 'food', '2000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp05', 'clothing', '4500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp05', 'food', '1500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp06', 'travel', '1000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp07', 'food', '2000');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp08', 'clothing', '1500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp09', 'medical', '500');
INSERT INTO `expenseManagement`.`FlexibleExpense` (`expenseId`, `flexibleType`, `amount`) VALUES ('exp10', 'food', '2000');
-- *************************
INSERT INTO FixedExpense VALUES ('exp01', 'rent', '5000');
INSERT INTO FixedExpense VALUES ('exp01', 'bills', '1500');
INSERT INTO FixedExpense VALUES ('exp02', 'bills', '4000');
INSERT INTO FixedExpense VALUES ('exp02', 'rent', '5000');
INSERT INTO FixedExpense VALUES ('exp03', 'rent', '5500');
INSERT INTO FixedExpense VALUES ('exp03', 'bills', '2000');
INSERT INTO FixedExpense VALUES ('exp04', 'rent', '7500');
INSERT INTO FixedExpense VALUES ('exp04', 'transport', '400');
INSERT INTO FixedExpense VALUES ('exp04', 'subscription', '250');
INSERT INTO FixedExpense VALUES ('exp05', 'rent', '7000');
INSERT INTO FixedExpense VALUES ('exp05', 'bills', '2000');
INSERT INTO FixedExpense VALUES ('exp06', 'rent', '5500');
INSERT INTO FixedExpense VALUES ('exp06', 'transport', '6000');
INSERT INTO FixedExpense VALUES ('exp07', 'bills', '1500');
INSERT INTO FixedExpense VALUES ('exp08', 'subscription', '1000');
INSERT INTO FixedExpense VALUES ('exp09', 'transport', '4000');
INSERT INTO FixedExpense VALUES ('exp09', 'rent', '5000');
INSERT INTO FixedExpense VALUES ('exp09', 'bills', '2000');
INSERT INTO FixedExpense VALUES ('exp10', 'transport', '2000');
INSERT INTO FixedExpense VALUES ('exp10', 'rent', '7000');
-- ********************************************************
 
select * from Admin;
SELECT * FROM expenseManagement.User;
select * from UserType;
SELECT * FROM expenseManagement.Expense;
SELECT * FROM expenseManagement.HasExpense;
select * from FlexibleExpense;
SELECT * FROM expenseManagement.FixedExpense;

-- *************************************











