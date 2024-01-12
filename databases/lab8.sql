-- 1.Create a function that:
-- a. Increments given values by 1 and returns it.
create function inc(n integer)
returns integer as
$$
BEGIN
    return n + 1;
END;
$$
language plpgsql;
select inc(3);

-- b. returns cube of number
create function cube(n integer)
returns integer as
$$
BEGIN
    return n * n * n;
end;
$$ language plpgsql;

select cube(3);


-- c. returns sum of 2 numbers.
create function sum_of_two (n integer, m integer)
returns integer as
$$
BEGIN
    return n + m;
END;
$$
language plpgsql;

select sum_of_two(5, 6);

-- d.true or false if numbers are divisible by 2:
create function is_even(n integer)
returns boolean as
$$
BEGIN
    return 1 - n%2;
END;
$$
language plpgsql;
select is_even(5);

-- e returns average sum of numbers
create function avg_sum(VARIADIC list int[], out total int, out average numeric)
as $$
BEGIN
select into average sum(list[i])
    from generate_subscripts(list, 1) g(i);
select into average avg(list[i])
    from generate_subscripts(list, 1) g(i);
end;
$$ language plpgsql;

select avg_sum(4, 5, 6);
-- f. returns count of numbers

create function cnt_num(variadic list int[], out cnt int) as
$$
BEGIN
    select into cnt count(list[i])
        from generate_subscripts(list, 1) g(i);
end;
$$ language plpgsql;

select cnt_num(1, 2, 4 , 6 , 7);


-- g. checks some password validity

create or replace function valid(password text)
returns boolean as
$$
BEGIN
    if (password like '2______A' ) then
        return true;
    else
        return false;
    end if;
END;
$$
language plpgsql;

select valid('2asdffaA');

-- j. returns 2 outputs but has one output
create or replace function
    two_outs(n integer, out a integer, out b integer) as
$$
BEGIN
    a = n - 5;
    b = n * n;
END;
$$ language plpgsql;

select two_outs(10);


-- 2 Create a trigger that:
CREATE TABLE person(
    id INT PRIMARY KEY,
    name VARCHAR,
    last_name VARCHAR,
    date_of_birth DATE,
    age INT,
    insertion_time timestamp,
    discount int,
    salart int
);

CREATE TABLE item(
    item_id INT PRIMARY KEY,
    item_name VARCHAR,
    price_initial NUMERIC,
    price_final NUMERIC
);
CREATE TABLE accounts(
    acc_id INT PRIMARY KEY,
    acc_name VARCHAR,
    password VARCHAR
);
-- a.
CREATE FUNCTION trig_func()
    RETURNS TRIGGER AS
    $$
    BEGIN
        new.insertion_time = now();
        RETURN new;
        END;$$
    LANGUAGE PLPGSQL;

CREATE TRIGGER time_of_action
    BEFORE INSERT OR UPDATE
    ON person
    FOR EACH ROW
    EXECUTE PROCEDURE trig_func();

DROP TRIGGER time_of_action
    ON person;

-- 2b
create function calc_age()
    returns trigger as
    $$
    declare year_c INT;
    begin
    select date_part('year', age(new.date_of_birth))
        into year_c;
    new.age=year_c;
    return new;
    end;
    $$
    language plpgsql;

create trigger calc_age
    before insert or update on person
    for each row execute procedure calc_age();

DROP TRIGGER calc_age
    ON person;

DROP FUNCTION calc_age;

INSERT INTO person VALUES(1,'Adam','Walker','2000-10-10');

DELETE FROM person WHERE id = 1;
-- 2c
create function add_tack()
    returns trigger as $$
    begin
    new.price_final = new.price_initial*1.12;
    return new;
    end;
    $$
    language plpgsql;

create trigger add_tack
    before insert or update
    on item
    for each row execute procedure add_tack();

INSERT INTO item VALUES(3,'smth',1234);
INSERT INTO item VALUES(4,'smth',1234);

-- d.Prevents deletion of any row from only one table.
create function prevent_deleting() returns trigger as
$$
begin
    raise exception 'Delete prevented';
    end;
$$ language plpgsql;
create trigger prevent_deleting_trigger
before delete on item
for each row execute function prevent_deleting();
alter table item
enable trigger prevent_deleting_trigger;
delete from item where item_id = 2;

-- e. Launches functions  1.d and 1.e.
create table accounts(
    id integer,
    username varchar(10),
    password varchar(10)
);

create or replace function launch_functions() returns trigger as
$$
begin
raise notice '%', valid(new.password);
raise notice '%', two_outs(new.acc_id);
return new;
end;
$$
LANGUAGE plpgsql;

create trigger launch_trigger
before insert    on accounts
for each row execute procedure launch_functions();
alter table accounts
enable trigger launch_trigger;
insert into accounts values (1, 'Asds', '2sdfA');

create table users (
    id   integer primary key not null,
    name   varchar  not null,
    date_of_birth  timestamp not null,
    age integer not null,
    salary  integer,
    workexperience integer,
    discount   integer
);

insert into users values (1, 'Aruzhan', '2004-03-03', 18, 500000, 3, 0);
insert into users values (2, 'Tomi', '2003-12-15', 19, 500000, 2, 0);
insert into users values (3, 'Dilya', '2004-01-21', 18, 600000, 5, 0);

-- 3.Create procedures that:

-- a)Increases salary by 10% for every 2 years of work experience and provides
-- 10% discount and after 5 years adds 1% to the discount.
create or replace procedure increase_and_provide_features(experience integer)
language plpgsql as
$$
declare cnt int;begin        cnt = experience / 2;
    for i in 0..cnt loop
        update person
        set discount = discount * 1.01;
    end loop;
commit ;
end;
$$;

-- b)After reaching 40 years, increase salary by 15%. If work experience is more
-- morethan 8 years, increase salary for 15% of the already increased value for work
-- experience and provide a constant 20% discount.

create procedure increase_and_provide(experience integer)
language plpgsql as
$$
    declare cnt int;
begin
    cnt = experience/40;
    for i in 0..cnt loop
        update users  set salary = salary * 1.15 where salary = salary;
    end loop;    cnt = experience/5;
    if(experience > 8) then
        update users set salary = salary * 1.15,
        discount = 20 where salary = salary;
    end if;
commit ;
end;
$$