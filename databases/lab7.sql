create table dealer (
    id integer primary key ,
    name varchar(255),
    location varchar(255),
    commission float
);

INSERT INTO dealer (id, name, location, commission) VALUES (101, 'Oleg', 'Astana', 0.15);
INSERT INTO dealer (id, name, location, commission) VALUES (102, 'Amirzhan', 'Almaty', 0.13);
INSERT INTO dealer (id, name, location, commission) VALUES (105, 'Ademi', 'Taldykorgan', 0.11);
INSERT INTO dealer (id, name, location, commission) VALUES (106, 'Azamat', 'Kyzylorda', 0.14);
INSERT INTO dealer (id, name, location, commission) VALUES (107, 'Rahat', 'Satpayev', 0.13);
INSERT INTO dealer (id, name, location, commission) VALUES (103, 'Damir', 'Aktobe', 0.12);

create table client (
    id integer primary key ,
    name varchar(255),
    city varchar(255),
    priority integer,
    dealer_id integer references dealer(id)
);

INSERT INTO client (id, name, city, priority, dealer_id) VALUES (802, 'Bekzat', 'Satpayev', 100, 101);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (807, 'Aruzhan', 'Almaty', 200, 101);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (805, 'Али', 'Almaty', 200, 102);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (808, 'Yerkhan', 'Taraz', 300, 102);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (804, 'Aibek', 'Kyzylorda', 300, 106);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (809, 'Arsen', 'Taldykorgan', 100, 103);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (803, 'Alen', 'Shymkent', 200, 107);
INSERT INTO client (id, name, city, priority, dealer_id) VALUES (801, 'Zhandos', 'Astana', null, 105);

create table sell (
    id integer primary key,
    amount float,
    date timestamp,
    client_id integer references client(id),
    dealer_id integer references dealer(id)
);

INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (201, 150.5, '2021-10-05 00:00:00.000000', 805, 102);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (209, 270.65, '2021-09-10 00:00:00.000000', 801, 105);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (202, 65.26, '2021-10-05 00:00:00.000000', 802, 101);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (204, 110.5, '2021-08-17 00:00:00.000000', 809, 103);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (207, 948.5, '2021-09-10 00:00:00.000000', 805, 102);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (205, 2400.6, '2021-07-27 00:00:00.000000', 807, 101);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (208, 5760, '2021-09-10 00:00:00.000000', 802, 101);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (210, 1983.43, '2021-10-10 00:00:00.000000', 804, 106);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (203, 2480.4, '2021-10-10 00:00:00.000000', 809, 103);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (212, 250.45, '2021-06-27 00:00:00.000000', 808, 102);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (211, 75.29, '2021-08-17 00:00:00.000000', 803, 107);
INSERT INTO sell (id, amount, date, client_id, dealer_id) VALUES (213, 3045.6, '2021-04-25 00:00:00.000000', 802, 101);
-- JOINS
-- 1.a Find those clients with a priority less than 300
select *
from client c
join dealer d
on c.dealer_id = d.id
where priority < 300;

-- 1.b Combine each row of dealer table with each row of client table
select *
from dealer d
inner join client c
on d.id = c.dealer_id;

-- 1.c Find all dealers along with client name,city,priority,sell number,date,and amount

select c.name, c.city, c.priority, s.id, s.date, s.amount
from client c
left outer join sell s on c.id = s.client_id
order by s.date;

-- 1.d Find the dealer and client who reside in the same city

select d.name, c.name, c.city
from client c
join dealer d on d.location = c.city;

-- 1.e Find sell id, amount, client name, city those sells where sell amount exists between 200 and 500

select s.id, s.amount, c.name, c.city
from sell s
join client c on s.client_id = c.id
     and s.amount between 200 and 500;

-- 1.f Find dealers who works either for one or more client or not yet join under any of the clients
select * from dealer d
left join client c
on d.id = c.dealer_id;

-- 1.g Find the dealers and the clients he service,return client name, city,dealer name,commission.

select c.name, c.city, d.name, d.commission
from dealer d
join client c
on d.location = c.city;

-- 1.h Find client name,client city,dealer,commission those dealers who received a commission from the sell more than 13%

select c.name, c.city, d.name, d.commission
from client c
inner join dealer d on d.id = c.dealer_id
where d.commission > 0.13;

-- 1.i
select c.name, c.city, s.id, s.date, s.amount
from client c
left outer join sell s
on c.id = s.client_id
left outer join dealer d
on d.id = s.dealer_id;

-- 1.j
select c.name, c.city, c.priority, d.name , s.id , s.date, s.amount
from client c
right join dealer d on d.id = c.dealer_id
left outer join sell s on s.client_id = c.id
where s.amount >= 2000 and c.priority is not null;

-- VIEWS
-- 2.a Count the number of unique clients, compute average and total purchase amount of client orders by each date.
drop view client_view;
create view client_view as
select count(distinct c.client_id), avg(amount), sum(amount)
from sell c
group by date;

select * from client_view;

-- 2.b Find top 5 dates with the greatest total sell amount

create view top_5
as select date ,amount from sell
order by date limit 5;
select * from top_5;
drop view top_5;

--2.с Сount the number of sales, compute average and total amount ofallsales of each dealer
create view report_dealer_sales
as select a.name, avg(amount), sum(amount)
from dealer a, sell where sell.dealer_id = a.id
group by name;
select * from report_dealer_sales;

--2.d Compute how much all dealers earned from commission(total sell amount *commission) in each location
create or replace view local_commission as
select sum(comms.total_commision), location
from dealer join (select s.total_sum * d.commission as total_commision, d.id as dealer_id
from dealer d join (select sum(amount) as total_sum, sell.dealer_id
from sell group by sell.dealer_id) s on d.id = s.dealer_id) comms on comms.dealer_id = dealer.id
group by location;

select * from local_commission;

--2.e Compute number of sales, average and total amount of all sales dealersmade in each location
create view local_sales as
select location, sum(s.cnt) as number_of_sales, sum(sums) / sum(s.cnt) as average, sum(sums) as total_amount
from dealer
inner join (select dealer_id, count(*) as cnt, sum(amount) as sums from sell group by sell.dealer_id) s
on dealer.id = s.dealer_id
group by location;

select * from local_sales;

--2.f compute number of sales, average and total amount of expenses ineach city clients made.
create view city_sales as
select city, sum(s.cnt) as num_of_sales, sum(sums) / sum(s.cnt) as average, sum(sums) as total_amount
from client
inner join (select client_id, count(*) as cnt, sum(amount) as sums from sell group by client_id) s
on s.client_id = client.id
group by city;

select * from city_sales;

--2.g Find cities where total expenses more than total amount of sales in locations
create view expensed_cities as
select c.city from (select distinct client.city as city from client) c
inner join local_sales on c.city = local_sales.location
inner join city_sales on c.city = city_sales.city
where city_sales.total_amount > local_sales.total_amount;
select * from expensed_cities;