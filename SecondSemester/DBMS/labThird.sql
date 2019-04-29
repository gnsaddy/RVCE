create database Hospital;
use Hospital;
-- *********************************************
CREATE TABLE Physician (
  phid varchar(10) PRIMARY KEY NOT NULL,
  pname varchar(20),
  pos varchar(20),
  contact bigint
); 

-- ****************************
create table Department (
	depid varchar(10) primary key not null,
    dname varchar(20),
    dhead varchar(20),
    phid varchar(10), constraint fk_dept foreign key(phid) references Physician (phid) on delete cascade
    on update cascade
);

CREATE TABLE Affiliated_With (
  phid varchar(10),
  depid varchar(10),
  affilication BOOLEAN,
  PRIMARY KEY(phid, depid),
  constraint fk_aff_ph foreign key(phid) references Physician (phid) on delete cascade on update cascade,
  constraint fk_aff_dep foreign key(depid) references Department (depid) on delete cascade on update cascade
);
desc Affiliated_With;
-- **************************
CREATE TABLE Procedures (
  prid varchar(10) PRIMARY KEY NOT NULL,
  Name varchar(20) ,
  cost int
);
-- ********************
CREATE TABLE Trained_In (
  phid varchar(10),
  prid varchar(10),
  CertificationDate datetime,
  CertificationExpires datetime,
  PRIMARY KEY(phid, prid),
  constraint fk_train_ph foreign key(phid) references Physician(phid) on delete cascade on update cascade,
  constraint fk_train_pr foreign key(prid) references Procedures(prid) on delete cascade on update cascade
);
-- *********************
CREATE TABLE Patient (
  ptid varchar(10) PRIMARY KEY NOT NULL,
  ptname varchar(20),
  contact bigint,
  phid varchar(10),
  age int,
  constraint fk_pat_ph foreign key(phid) references Physician(phid) on delete cascade on update cascade
);
-- ***********************
CREATE TABLE Nurse (
  nrid varchar(10) PRIMARY KEY NOT NULL,
  nrname varchar(20),
  pos varchar(10),
  registered BOOLEAN
);
-- ***************************
CREATE TABLE Appointment (
  appid varchar(10) PRIMARY KEY NOT NULL,
  ptid varchar(10),phid varchar(10),nrid varchar(10),
  start DATETIME,
  end DATETIME,
  examinationRoom varchar(10),
  constraint fk_app_ph foreign key(phid) references Physician(phid) on delete cascade on update cascade,
  constraint fk_app_pt foreign key(ptid) references Patient(ptid) on delete cascade on update cascade,
  constraint fk_app_nr foreign key(nrid) references Nurse(nrid) on delete cascade on update cascade
);
-- **********************************
CREATE TABLE Medication (
  mcode varchar(10) PRIMARY KEY NOT NULL,
  mname varchar(20),
  brand varchar(20),
  description TEXT 
);
-- ***********************
CREATE TABLE Prescribes (
  phid varchar(10),ptid varchar(10),mcode varchar(10),
  pdate datetime,dose varchar(10),PRIMARY KEY(phid, ptid, mcode),
    CONSTRAINT fk_pre_ph foreign key(phid) REFERENCES Physician(phid),
    CONSTRAINT fk_pre_pt foreign key(ptid) REFERENCES Patient(ptid),
    CONSTRAINT fk_pre_code foreign key(mcode) REFERENCES Medication(mcode)  
);
-- *************************
CREATE TABLE Block (
  floor varchar(10),
  bcode varchar(10),
  PRIMARY KEY(floor, bcode)
); 
-- *****************************










