INSERT INTO Warehouses(code, location, capacity) VALUES(1, 'Chicago', 3);
INSERT INTO Warehouses(code, location, capacity) VALUES(2, 'Rocks', 4);
INSERT INTO Warehouses(code, location, capacity) VALUES(3, 'New York', 7);
INSERT INTO Warehouses(code, location, capacity) VALUES(4, 'Los Angeles', 2);
INSERT INTO Warehouses(code, location, capacity) VALUES(5, 'San Francisko', 8);

INSERT INTO Packs(code, contents, value, warehouses) VALUES ('0MN7', 'Rocks', 180, 3);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('4H8P', 'Rocks', 250, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('4RT3', 'Scissors', 190, 4);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('7G3H', 'Rocks', 200, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('8JN6', 'Papers', 75, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('8Y6U', 'Papers', 50, 3);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('9J6F', 'Papers', 175, 2);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('LL08', 'Rocks', 140, 4);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('P0H6', 'Scissors', 125, 1);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('P2T6', 'Scissors', 150, 2);
INSERT INTO Packs(code, contents, value, warehouses) VALUES ('TUSS', 'Papers', 90, 5);

-- 4
SELECT * FROM Packs;
-- 5
SELECT * FROM Packs
WHERE value > 190;

-- 6
SELECT DISTINCT ON(contents) *
FROM Packs;

-- 7
SELECT warehouses as code,
count(*) AS packs
FROM Packs
GROUP BY warehouses;

-- 8
SELECT warehouses as code,
count(*) AS packs
FROM Packs
GROUP BY warehouses
HAVING count(*) > 2;

-- 9
INSERT INTO Warehouses(code, location, capacity)
VALUES(6, 'Texas', 5);

-- 10
INSERT INTO Packs(code, contents, value, warehouses)
VALUES ('H5RT', 'Papers', 150, 2);

-- 11
UPDATE Packs
SET value = (value * 82)/100
WHERE value in(
    SELECT DISTINCT value from Packs
    ORDER BY value
    LIMIT 1
    OFFSET 2
    );

-- 12
DELETE FROM packs
WHERE value < 150;

-- 13
DELETE FROM packs
WHERE warehouses IN (
    SELECT code from warehouses
    WHERE location = 'Chicago'
    )
    RETURNING *;
