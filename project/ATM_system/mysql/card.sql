create database card;

use card;

create table card_info(_id_num char(20) primary key not null, _name char(20) not null, _card_num char(20), _pswd char(8), _money bigint);
