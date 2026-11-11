-- Part 1

-- 1. Insert your own personal data into the Employee table as a new employee in department 30 (Maintenance). Use EmpID = 200100, SuperEmpID = 100714 (Sherif Naguib)
Insert into Employee VALUES ('Sherif', 'Naguib', '200100', '5/3/1968', 'cairo' 'M', '10', '100714', '30');

-- 2. Insert a classmate or friend as a new employee in department 30, using EmpID = 200200, but do not enter any value for Salary or SuperEmpID.
Insert into Employee (Fname, Lname, EmpID, BDate, Address, sex, DeptID) VALUES ('yasser', 'aadel', '200200', '1/1/1', 'cairo', 'M', '10');

-- 3. Insert a classmate or friend as a new employee in department 30, using EmpID = 200200, but do not enter any value for Salary or SuperEmpID.
 Insert into Department VALUES ('Ground Handling', '40', '1100305', '1/11/2026');

 -- 4. Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new Ground Handling department (DeptID = 40). Update his record in the Department table for DeptID = 10 so that Dept 10 is managed instead by the employee you inserted in Task 1 (EmpID = 200100).
update Department Set MgrEmpID = '200100' where DeptID = '10';

-- 5. Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new Ground Handling department (DeptID = 40). Update his record in the Department table for DeptID = 10 so that Dept 10 is managed instead by the employee you inserted in Task 1 (EmpID = 200100).
update employee set DeptID = '10' where EmpID = '200100';
update department set MgrStartDate = '1/1/2026' where MgrEmpID = '200100';

-- 6. Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new Ground Handling department (DeptID = 40). Update his record in the Department table for DeptID = 10 so that Dept 10 is managed instead by the employee you inserted in Task 1 (EmpID = 200100).
 update employee set SuperEmpID = 200100 where EmpID = '200200';

-- 7. Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new Ground Handling department (DeptID = 40). Update his record in the Department table for DeptID = 10 so that Dept 10 is managed instead by the employee you inserted in Task 1 (EmpID = 200100).
update department set MgrEmpID = NULL where MgrEmpID = '100305';
delete from crawfamilymember where EmpID = '100305';
update employee set SuperEmpID = NULL where SuperEmpID = '100305'; 
delete from employee where EmpID = '100305';

-- 8. Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new Ground Handling department (DeptID = 40). Update his record in the Department table for DeptID = 10 so that Dept 10 is managed instead by the employee you inserted in Task 1 (EmpID = 200100).
update employee set Salary = (Salary*1.15) where EmpID = '200100';


-----------------
-- Part 2

-- 9. Display all employees’ data
select * from employee;

-- 10. Display each employee’s first name, last name, salary, and department ID.
select Fname, Lname, salary, DeptID from employee;

-- 11. Display all flight names, their origin, destination, and the department that controls each flight.
select FlightName, origin, destination, DeptID from flight;

-- 12. The company pays an annual bonus equal to 8 percent of an employee’s annual salary. Display each employee’s full name and their annual bonus in a column aliased ANNUAL_BONUS.
select Fname, Lname, (salary * 0.08) as ANNUAL_BONUS From employee; 

-- 13. Display the ID and name of employees who earn more than 1,500 EGP monthly.
select EmpID, Fname, Lname from employee where salary > '1500';

-- 14. Display the ID and name of employees who earn more than 18,000 EGP annually.
select EmpID, Fname, Lname from employee where (salary*12) > '18000';

-- 15. Display the names and salaries of the female employees
select Fname, Lname, salary from employee where sex = 'F';

-- 16. Display the department ID and name of the department managed by the employee with EmpID = 100714.
select deptname, DeptID from department where MgrEmpID = '100714';

-- 17. Display the ID, name, and destination of the flights controlled by department
select flightname, flightno, destination from flight where DeptID != NULL;

--------------------

-- Part 3 

-- Every query below fails to execute. Students must read the error message, locate the fault, and correct it so the query runs and answers the stated business requirement.
-- 1. SELECT FlightName, Origin FROM Flight WHERE f.Destination = 'Aswan';
select flightname, origin from flight as f where f.destination = 'Aswan'; 
-- add alias 
-- 2. SELECT FName, LName, Address, Salary, FROM Employee WHERE Salary > '2000';
SELECT FName, LName, Address, Salary FROM Employee WHERE Salary > '2000';
--remove comma after salary

--------------------

-- Part 4 

--Business Logic Validation:
-- Business Requirement:
-- 1. List all departments whose manager start date falls within 2016. MgrStartDate is stored as a DATETIME column, even though the sample data only contains pure dates.
-- SELECT DeptName, MgrStartDate FROM Department WHERE MgrStartDate >= '2016-01-01' AND MgrStartDate <= '2016-12-31';
-- Please write Corrected Query

SELECT DeptName, MgrStartDate FROM Department WHERE MgrStartDate >= '2016-01-01' AND MgrStartDate <= '2016-12-31';















