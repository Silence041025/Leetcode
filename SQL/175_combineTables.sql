\c Leetcode

CREATE TABLE Person(
                       PersonId INT PRIMARY KEY,
                       FirstName VARCHAR(255),
                       LastName VARCHAR(255)
);

CREATE TABLE Address(
                        AddressId INT,
                        PersonId INT REFERENCES Person(PersonId),
                        City VARCHAR(255),
                        State VARCHAR(255)
);

SELECT Person.LastName,Person.FirstName,A.City,A.State
FROM Person LEFT JOIN Address A on Person.PersonId = A.PersonId;