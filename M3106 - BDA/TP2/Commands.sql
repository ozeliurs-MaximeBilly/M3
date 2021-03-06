/* EXO1 Q1 */
CREATE OR REPLACE TRIGGER CTRL
BEFORE INSERT OR UPDATE
ON CONTROLE
FOR EACH ROW
BEGIN
    IF :NEW.TYPEC IN ('TESTS', 'TESTSRATTRAPAGE', 'INTERROGATIONS') OR :NEW.DATEFIN IS NULL THEN
        :NEW.DATEFIN = :NEW.DATEDEB;
    END IF;

    IF :NEW.NOTEMAX IS NULL THEN
        :NEW.NOTEMAX := 20;
    END IF; 
END;

/* EXO1 Q2 */
CREATE OR REPLACE TRIGGER NOTE
BEFORE INSERT OR UPDATE
ON NOTATION
FOR EACH ROW
DECLARE 
    NOTEMAX NUMBER(3,0);
BEGIN
    SELECT NOTEMAX FROM CONTROLE INTO NOTEMAX WHERE :NEW.IDC = CONTROLE.IDC;
    :NEW.NOTEDEF = :NEW.NOTE/NOTEMAX*20;
END;

/* EXO2 Q1 */
CREATE OR REPLACE TRIGGER EMPRT
BEFORE INSERT
ON EMPRUNT
FOR EACH ROW
DECLARE
    TOTAL NUMBER(3,0);
BEGIN
    SELECT COUNT(*) INTO TOTAL FROM EMPRUNT WHERE DATERET IS NULL AND :NEW.IDA = EMPRUNT.IDA
    IF TOTAL > 5 THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Trop de livres empruntes !');
    END IF;
END;

/* EXO2 Q2 */
CREATE OR REPLACE TRIGGER NBEMPRT
BEFORE INSERT
ON EMPRUNT
FOR EACH ROW
BEGIN
    FOR P IN (SELECT COUNT(*) TOTAL, EMPRUNT FROM EMPRUNT WHERE DATERET IS NULL AND :NEW.IDA = EMPRUNT.IDA)
    LOOP
        UPDATE ABONNE SET NBEMPRUNT = P.TOTAL WHERE :NEW.IDA = EMPRUNT.IDA;
    END LOOP;
END;

/* EXO2 Q3 */
CREATE OR REPLACE TRIGGER RESA
BEFORE UPDATE
ON EMPRUNT
FOR EACH ROW
DECLARE
    IDA NUMBER(3,0);
BEGIN
    SELECT IDA FROM RESERV INTO IDA WHERE RESERV.IDL = :NEW.IDL ORDER BY DATER WHERE ROWNUM = 1;
    UPDATE RESERV SET CONTACT='Oui' WHERE IDA=RESERV.IDA;
END;

