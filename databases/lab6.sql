create database assignment6;

create table locations
(
    location_id serial primary key,
    street_address varchar(25),
    postal_code varchar(12),
    city varchar(30),
    state_province varchar(12)
);

create table departments
(
    department_id serial primary key ,
    department_name varchar(50) unique ,
    budget integer,
    location_id integer references locations
);

create table employees
(
    employee_id serial primary key ,
    first_name varchar(50),
    last_name varchar(50),
    email varchar(50),
    phone_number varchar(20),
    salary integer,
    department_id integer references departments
);

-- 3
INSERT INTO locations (location_id, street_address, postal_code, city, state_province)
VALUES (1, 'Tole bi', '123tt', 'Almaty', 'KZ');
INSERT INTO locations (location_id, street_address, postal_code, city, state_province)
VALUES (2, 'Panfilova', '456pp', 'Almaty', 'KZ');
INSERT INTO locations (location_id, street_address, postal_code, city, state_province)
VALUES (3, 'Kenesary', '234kk', 'Astana', 'KZ');
INSERT INTO locations (location_id, street_address, postal_code, city, state_province)
VALUES (4, 'Broadway', '566bb', 'Los-Angeles', 'USA');
INSERT INTO locations (location_id, street_address, postal_code, city, state_province)
VALUES (5, 'Dolores', '678dd', 'San-Francisco', 'USA');

INSERT INTO departments (department_id, department_name, budget, location_id)
VALUES (30, 'FIT', 900000, 1);
INSERT INTO departments (department_id, department_name, budget, location_id)
VALUES (50, 'BS', 800000, 3);
INSERT INTO departments (department_id, department_name, budget, location_id)
VALUES (60, 'SITI', 700000, 2);
INSERT INTO departments (department_id, department_name, budget, location_id)
VALUES (70, 'NGD', 850000, 5);
INSERT INTO departments (department_id, department_name, budget, location_id)
VALUES (80, 'CHEM', 750000, 4);

INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, salary, department_id)
VALUES (1, 'Sam', 'Smith', 'sam@kbtu.kz', '87778',50000, 30);
INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, salary, department_id)
VALUES (2, 'Shawn', 'Mendes', 'shawn@kbtu.kz', '12345',20000, 50);
INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, salary, department_id)
VALUES (3, 'Charlie', 'Puth', 'puth@kbtu.kz', '98765', 25000, 80);
INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, salary, department_id)
VALUES (4, 'Ed', 'Sheeran', 'ed@kbtu.kz', '45678', 40000, 70);
INSERT INTO employees (employee_id, first_name, last_name, email, phone_number, salary, department_id)
VALUES (5, 'Jung', 'Kook', 'kook@kbtu.kz', '98765', 60000, 60);

-- 4
SELECT first_name, last_name, d.department_name,d.department_id
FROM employees e
JOIN departments d
ON e.department_id = d.department_id;

-- 5
SELECT first_name, last_name, d.department_name, d.department_id
FROM employees e
JOIN departments d
ON e.department_id = d.department_id
WHERE d.department_id IN (80, 30);

-- 6
SELECT first_name, last_name, d.department_id, l.city, l.state_province
FROM employees e
INNER JOIN departments d
ON d.department_id = e.department_id
INNER JOIN locations l
ON l.Location_id = d.location_id;

-- 7
SELECT *
FROM departments d
LEFT JOIN employees e
ON d.department_id = e.department_id;

-- 8
SELECT e.first_name, e.last_name, d.department_id, d.department_name
FROM employees e
LEFT JOIN departments d
ON d.department_id = e.department_id;

-- 9
SELECT last_name, first_name
FROM employees e
INNER JOIN departments d
ON d.department_id = e.department_id
INNER JOIN locations l
ON l.Location_id = d.location_id
WHERE d.location_id IN (3);