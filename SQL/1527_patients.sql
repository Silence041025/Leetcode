\c Leetcode

Create table If Not Exists Patients (patient_id int, patient_name varchar(30), conditions varchar(100));

SELECT Patients.patient_id,Patients.patient_name,Patients.conditions
FROM Patients
WHERE conditions LIKE CONCAT('DIAB1','%') OR
      conditions LIKE CONCAT('%',' ','DIAB1','%');