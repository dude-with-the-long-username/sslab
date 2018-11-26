/*


DECLARE
	S NUMBER;
BEGIN
	S:=5;
	S:=S+1;
	dbms_output.put_line(S);
END;
/



DECLARE 
   -- Global variables  
   num1 number := 95;  
   num2 number := 85;  
BEGIN  
   dbms_output.put_line('Outer Variable num1: ' || num1); 
   dbms_output.put_line('Outer Variable num2: ' || num2); 
   DECLARE  
      -- Local variables 
      num1 number := 195;  
      num2 number := 185;  
   BEGIN  
      dbms_output.put_line('Inner Variable num1: ' || num1); 
      dbms_output.put_line('Inner Variable num2: ' || num2); 
   END;  
   
   BEGIN  
	   dbms_output.put_line('Outer Variable num1: ' || num1); 
	   dbms_output.put_line('Outer Variable num2: ' || num2); 
	END;
END; 
/ 


IF(boolean_expression 1)THEN  
   S1; -- Executes when the boolean expression 1 is true  
ELSIF( boolean_expression 2) THEN 
   S2;  -- Executes when the boolean expression 2 is true  
ELSIF( boolean_expression 3) THEN 
   S3; -- Executes when the boolean expression 3 is true  
ELSE  
   S4; -- executes when the none of the above condition is true  
END IF; 


DECLARE 
   a number(2); 
BEGIN 
   FOR a in 10 .. 20 LOOP 
      dbms_output.put_line('value of a: ' || a); 
  END LOOP; 
END; 
/




DECLARE 
   i number(1); 
   j number(1); 
BEGIN 
   << outer_loop >> 
   FOR i IN 1..3 LOOP 
      << inner_loop >> 
      FOR j IN 1..3 LOOP 
         dbms_output.put_line('i is: '|| i || ' and j is: ' || j); 
      END loop inner_loop; 
   END loop outer_loop; 
END; 
/


--TAKE USER INPUT

accept x number prompt 'Please enter something: '

declare 
  a number;
begin
	a := &x;
	dbms_output.put_line('Number you entered is: ' || a);
end;
/



DECLARE 
   grade char(1) := 'A'; 
BEGIN 
   CASE grade 
      when 'A' then dbms_output.put_line('Excellent'); 
      when 'B' then dbms_output.put_line('Very good'); 
      when 'C' then dbms_output.put_line('Well done'); 
      when 'D' then dbms_output.put_line('You passed'); 
      when 'F' then dbms_output.put_line('Better try again'); 
      else dbms_output.put_line('No such grade'); 
   END CASE; 
END; 
/



*/











--1. FIND SUM OF SERIES 1+2+3+.........+NATIONAL

--ACCEPT X NUMBER PROMPT 'Enter number the limit to which we want to take sum till: ';

DECLARE
	N NUMBER;
	TOTAL NUMBER := 0;
	i NUMBER;
BEGIN 
	N := &N;
	
	FOR i IN 1 .. N LOOP
		TOTAL := TOTAL + i ;
	END LOOP;
	
	dbms_output.put_line('Sum of numbers from 1 to n is : ' || TOTAL);
END;
/


--2.FIND GREATEST NUMBER AMONG 2 NUMBERS
DECLARE	
	A NUMBER;
	B NUMBER;
	LARGER NUMBER;
	
BEGIN	
	A := &A;
	B := &B;
	
	IF (A > B) THEN
		LARGER := A;
		DBMS_OUTPUT.PUT_LINE('THE LARGER NUMBER IS: ' || LARGER);
	ELSIF (A < B) THEN
		LARGER := B;
		DBMS_OUTPUT.PUT_LINE('THE LARGER NUMBER IS: ' || LARGER);
	ELSE 
		DBMS_OUTPUT.PUT_LINE('BOTH NUMBERS ARE EQUAL ');
	END IF;
	
END;
/
	
	
--3.FIND THE LARGEST AMONG 3 NUMBERS
DECLARE	
	A NUMBER;
	B NUMBER;
	C NUMBER;
	LARGER NUMBER;
	LARGEST NUMBER;
	
BEGIN	
	A := &A;
	B := &B;
	C := &C;
	
	IF (A >= B) THEN
		LARGER := A;
	ELSE 
		LARGER := B;
	END IF;
	
	IF (C >= LARGER) THEN
		LARGEST := C;
	ELSE 
		LARGEST := LARGER;
	END IF;
	
	DBMS_OUTPUT.PUT_LINE('THE LARGEST NUMBER IS: ' || LARGEST);
	
END;
/


--4. READ 2 NUMBERS AND PRINT ALL NUMBERS BETWEEN THEM
DECLARE
	A NUMBER;
	B NUMBER;
	I NUMBER;
	SMALLER NUMBER;
	LARGER NUMBER;
	
BEGIN
	A := &A;
	B := &B;
	IF (A > B) THEN
		SMALLER := B;
		LARGER := A;
	ELSIF (A = B) THEN
		DBMS_OUTPUT.PUT_LINE('BOTH NUMBERS ARE EQUAL, SO THERE ARE NO NUMBERS IN BETWEEN THEM ');
	ELSE 
		SMALLER := A;
		LARGER := B;
	END IF;
	
	DBMS_OUTPUT.PUT_LINE('The numbers between the 2 numbers are: ');
	
	FOR I IN SMALLER+1 .. LARGER-1 LOOP
		DBMS_OUTPUT.PUT_LINE(I );
	END LOOP;
	
END;
/


--5. READ SUBJECT MARK & DISPLAY GRADE.
DECLARE 
	MARK FLOAT;
	
BEGIN
	MARK := &MARK;
	IF (MARK < 40) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS F ');
	ELSIF (40 <= MARK AND MARK < 45) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS P ');
	ELSIF (45 <= MARK AND MARK < 50) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS E ');
	ELSIF (50 <= MARK AND MARK < 60) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS D ');
	ELSIF (60 <= MARK AND MARK < 70) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS C ');
	ELSIF (70 <= MARK AND MARK < 80) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS B ');	
	ELSIF (80 <= MARK AND MARK < 90) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS A ');
	ELSIF (90 <= MARK AND MARK <= 100) THEN
		DBMS_OUTPUT.PUT_LINE('GRADE IS O ');
	END IF;
	
END;
/

--------------------6.PL SQL PROGRAM TO REVERT A STRING
DECLARE 
	ORIGINAL VARCHAR2(50);
	REVERTED VARCHAR2(50);
	I NUMBER :=1;
	
BEGIN
	ORIGINAL := '&STRING';		---------------------------------------------PUT QUOTES HERE
	FOR I IN 1 .. LENGTH(ORIGINAL) LOOP
		REVERTED := CONCAT(REVERTED,SUBSTR(ORIGINAL,-I,1));   -------------------  '-I' INDEXES STRING FROM BACK
															---------------------or we can use || instead of concat operation
	END LOOP;
	
	DBMS_OUTPUT.PUT_LINE('REVERTED STRING IS: ' || REVERTED);
	
END;
/


--7.create trigger to perform audit trail whenever salary is modified.  emp_id, old salary, new salary, updation date should be inserted into audit trail.

/*CREATE TABLE AUDIT_TRAIL(EMP_ID CHAR(5) NOT NULL,
            OLD_SALARY INTEGER,
			NEW_SALARY INTEGER,
            UPDATION_DATE DATE);

CREATE OR REPLACE TRIGGER SALARY_DIFF
BEFORE DELETE OR INSERT OR UPDATE OF BASIC_PAY ON EMP1
FOR EACH ROW
--WHEN (NEW.ID > 0)
DECLARE
	SAL_DIFF NUMBER;
BEGIN
	SAL_DIFF := :NEW.BASIC_PAY - :OLD.BASIC_PAY;
	DBMS_OUPUT.PUT_LINE('Employee ID is: ' || :OLD.ID);
	DBMS_OUTPUT.PUT_LINE('Old salary is: ' || :OLD.BASIC_PAY);
	DBMS_OUTPUT.PUT_LINE('New salary is: ' || :NEW.BASIC_PAY);
	DBMS_OUTPUT.PUT_LINE('Salary difference is: ' || SAL_DIFF);
	DBMS_OUTPUT.PUT_LINE('Updation date is: ' || SYSDATE);
	INSERT INTO AUDIT_TRAIL VALUES(:OLD.ID,OLD:BASIC_PAY,:NEW.BASIC_PAY,SYSDATE);
END;
/


CREATE OR REPLACE TRIGGER AUDIT_TRAIL
BEFORE DELETE OR INSERT OR UPDATE OF BASIC_PAY ON EMP1
FOR EACH ROW
--WHEN (NEW.ID > 0)
DECLARE
 SAL_DIFF NUMBER;
BEGIN
 SAL_DIFF := :NEW.BASIC_PAY - :OLD.BASIC_PAY;
 DBMS_OUTPUT.PUT_LINE('Old salary is: ' || :OLD.BASIC_PAY);
 DBMS_OUTPUT.PUT_LINE('New salary is: ' || :NEW.BASIC_PAY);
 DBMS_OUTPUT.PUT_LINE('Salary difference is: ' || SAL_DIFF);
END;
/




CREATE OR REPLACE TRIGGER SALARY_DIFF
AFTER 
UPDATE OF BASIC_PAY ON EMP1
FOR EACH ROW
--WHEN (NEW.ID > 0)
DECLARE
	SAL_DIFF NUMBER;
BEGIN
	SAL_DIFF := :NEW.BASIC_PAY - :OLD.BASIC_PAY;
	--DBMS_OUPUT.PUT_LINE('Employee ID is: ' || :OLD.ID);
	DBMS_OUTPUT.PUT_LINE('Old salary is: ' || :OLD.BASIC_PAY);
	DBMS_OUTPUT.PUT_LINE('New salary is: ' || :NEW.BASIC_PAY);
	--DBMS_OUTPUT.PUT_LINE('Salary difference is: ' || SAL_DIFF);
--	DBMS_OUTPUT.PUT_LINE('Updation date is: ' || SYSDATE);
	NSERT INTO AUDIT_TRAIL VALUES (:OLD.ID, :OLD.BASIC_PAY, :NEW.BASIC_PAY, SYSDATE);
END;
/ */



CREATE TABLE AUDIT_TRAIL(EMP_ID CHAR(5), OLD_SAL DECIMAL(7,2), NEW_SAL DECIMAL(7,2), UPDATION_DATE DATE);



CREATE OR REPLACE TRIGGER SAL_CHANGES
AFTER
UPDATE OF BASIC_PAY
ON EMP1
FOR EACH ROW
BEGIN
INSERT INTO AUDIT_TRAIL
VALUES
(:old.ID,
 :old.BASIC_PAY,
 :new.BASIC_PAY,
 sysdate);
END;
/