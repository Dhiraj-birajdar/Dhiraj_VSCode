-- Active: 1710342347852@@127.0.0.1@3306@college
SHOW DATABASES;

CREATE DATABASE ems;

-- Create the simplified employee table
CREATE TABLE employee (
    id int,
    deptname VARCHAR(50),
    ename VARCHAR(50),
    hiredate VARCHAR(10)
);

CREATE TABLE employeecopy (
    id int,
    deptname VARCHAR(50),
    ename VARCHAR(50),
    hiredate VARCHAR(10)
);

DROP TABLE employee;

-- Insert dummy data into the simplified employee table
USE ems;

INSERT INTO
    employee (id, deptname, ename, hiredate)
VALUES (
        1,
        'IT',
        'Suraj',
        '2020-01-15'
    ),
    (
        2,
        'HR',
        'Akash',
        '2019-03-23'
    ),
    (
        3,
        'Finance',
        'Lankesh',
        '2021-06-01'
    ),
    (
        4,
        'Sales',
        'Raj',
        '2018-11-12'
    ),
    (
        5,
        'Marketing',
        'Amar',
        '2017-08-25'
    );

SELECT * FROM employee;

SELECT * FROM employeecopy;

TRUNCATE TABLE employeecopy;