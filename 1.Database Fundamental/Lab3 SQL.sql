-- Part 1

-- 1. Display the department ID, department name, manager ID, and manager name.
select d.DeptID, d.DeptName, d.MgrEmpID, concat(e.FName, '', e.LName) as FullName from Employee e, Department d where e.EmpID = d.MgrEmpID;

-- 2. Display the name of each department together with the names of the flights it controls.
select d.DeptName, f.FlightName from Department d inner join Flight f on f.DeptID = d.DeptID;

-- 3. Display the full data of every CrewFamilyMember record together with the name of the employee they belong to.
select c.*, concat(e.FName, '', e.LName) as FullName from CrewFamilyMember c, Employee e where c.EmpID = e.EmpID;

-- 4. Using the UNION operator, display: (a) the name and gender of family members who are female and belong to a female employee, and (b) the name and gender of family members who are male and belong to a male employee.
select c.MemberName, c.Sex from CrewFamilyMember c join Employee e on c.EmpID = e.EmpID where c.Sex = 'F' and e.Sex = 'F';

-- 5. Display the ID, name, and destination of the flights that fly to Cairo or Hurghada.
select FlightNo, FlightName, Destination from Flight where Destination in ('Cairo', 'Hurghada');

-- 6. Display the full data of the flights whose name starts with the letter "S".
select * from Flight where FlightName Like 'S%';

-- 7. Display all employees in department 30 whose monthly salary is between 1,200 and 1,800 EGP.
select * from Employee where DeptID = 30 and Salary between 1200 and 1800;

-- 8. Retrieve the names of all employees in department 10 who work 10 or more hours per week on the "Red Sea Link" flight.
select concat(FName, '', LName) as FullName from employee where DeptID = 10 and EmpID = 
(select EmpID from FlightAssignment where HoursPerWeek >= 10 and FlightNo = 
(select FlightNo From Flight where FlightName = 'Red Sea Link'));

-- 9. Find the names of the employees who are directly supervised by Mostafa Hassan (EmpID = 100305).
select FName, LName from Employee where SuperEmpID = 100305;

-- 10. For each flight, list the flight name and the total hours per week (summed across all assigned employees).
select f.FlightName, sum(fa.HoursPerWeek) from Flight f inner join FlightAssignment fa on f.FlightNo = fa.FlightNo group by f.FlightName;

-- 11. Retrieve the names of all employees and the names of the flights they are assigned to, sorted by flight name.
select e.FName, e.LName, f.FlightName from Employee e inner join FlightAssignment fa on e.EmpID = fa.EmpID
inner join Flight f on fa.FlightNo = f.FlightNo order by f.FlightName;

-- 12. Display the data of the department that has the smallest manager EmpID among all departments.
select * from Department order by MgrEmpID limit 1;
select * from Department where MgrEmpID = (select min(MgrEmpID) from Department);

-- 13. For each department, retrieve the department name and the maximum, minimum, and average salary of its employees.
select d.DeptName, max(e.salary), min(e.salary), avg(e.salary) from Employee e right join Department d on e.DeptID = d.DeptID group by d.DeptID, d.DeptName;  

-- 14. List the last names of all managers who have no CrewFamilyMember records.              
select e.LName, e.empid from Employee e where not exists (select * from CrewFamilyMember c where e.EmpID = c.EmpID);    

-- 15. For each department, if its average salary is less than the average salary of all employees, display its department ID, name, and number of employees.
select d.DeptName, d.DeptID, count(e.EmpID) from employee e right join department d on e.DeptID = d.DeptID group by d.DeptID  
having avg(e.salary) > 
(select avg(salary) from Employee); 

-- 16. Retrieve a list of employees and the flights they are assigned to, ordered by department, and within each department, ordered alphabetically by last name then first name.
select e.*, Fa.* from employee e inner join flightassignment fa on e.empid = fa.empid order by e.deptid, e.lname, e.fname;

-- 17. For each flight destined for Aswan, find the flight number, the controlling department name, the department manager’s last name, address, and birth date.
select f.flightno, d.deptname, e.lname, e.address, e.bdate from flight f inner join department d on f.deptid = d.deptid 
inner join employee e on d.deptid = e.deptid;

---------------------

-- Part 2

-- 1
-- SELECT d.DeptName, f.Origin, COUNT(f.FlightNo) AS FlightCount FROM Department AS d INNER JOIN Flight AS f ON d.DeptID = f.DeptID GROUP BY d.DeptName;
SELECT d.DeptName, f.Origin, COUNT(f.FlightNo) AS FlightCount
FROM Department d
INNER JOIN Flight f
    ON d.DeptID = f.DeptID
GROUP BY d.DeptName, f.Origin;

-- 2
-- SELECT fa.EmpID, fa.FlightNo, DeptID FROM FlightAssignment AS fa INNER JOIN Employee AS e ON fa.EmpID = e.EmpID INNER JOIN Flight AS f ON fa.FlightNo = f.FlightNo;
SELECT fa.EmpID, fa.FlightNo, e.DeptID
FROM FlightAssignment fa
INNER JOIN Employee e
    ON fa.EmpID = e.EmpID
INNER JOIN Flight f
    ON fa.FlightNo = f.FlightNo;


-------------------------------

-- Part 3

-- 1 List every department together with the number of flights it controls, including departments that currently control no flights. 

SELECT d.DeptName, COUNT(f.FlightNo) AS FlightCount
FROM Department d
left JOIN Flight f
ON d.DeptID = f.DeptID
GROUP BY d.DeptName;

-- 2 Show the average monthly salary for each department. Any employee whose salary has not yet been finalized (stored as NULL, such as the friend inserted in Task 2) should be treated as earning 0 EGP, not excluded from the calculation.

SELECT DeptID, AVG(COALESCE(salary, 0)) As AvgSalary
FROM Employee
GROUP BY DeptID;
