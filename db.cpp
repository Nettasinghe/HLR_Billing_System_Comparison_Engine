
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[25];
};
static const struct sqlcxp sqlfpn =
{
    24,
    "e:\\src\\billenq_tab\\db.pc"
};


static unsigned int sqlctx = 1183865451;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[15];
   unsigned int   sqhstl[15];
            int   sqhsts[15];
            void  *sqindv[15];
            int   sqinds[15];
   unsigned int   sqharm[15];
   unsigned int   *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0010 = 
"select ROWID ,BILLENQ_MOB_NUM ,BILLENQ_ACCT_NUM ,BILLENQ_PIN ,BILLENQ_CURREN\
T ,BILLENQ_OUTSTAND ,BILLENQ_LAST_UPDATE ,BILLENQ_LAST_BILLAMT ,BILLENQ_LAST_B\
ILLDATE ,BILLENQ_LAST_PAYAMT ,BILLENQ_LAST_PAYMODE ,BILLENQ_LAST_PAYDATE ,BILL\
ENQ_LANG ,BILLENQ_MIN_PAYMENT ,BILLENQ_CON_TYPE  from BILLENQ_TAB            ";

 static const char *sq0011 = 
"select IMAGE_ID ,IMSI_NO ,CONN_TYPE ,STATUS_REASON_ID ,SWITCH_STATUS  from P\
ROV_SWITCH_IMAGE            ";

 static const char *sq0012 = 
"select CONTRACT_ID ,SUBSCRIBER_NODE_ID ,IS_PAYMENT_RESPONSIBLE ,CREDIT_LIMIT\
 ,CONTRACT_TYPE ,STATUS  from CAM_CONTRACT            ";

 static const char *sq0013 = 
"select CONNECTION_ID ,PACKAGE_CONTRACT_ID ,STATUS ,IMAGE_ID  from CAM_CONNEC\
TION            ";

 static const char *sq0014 = 
"select IMSI ,START_DATE ,END_DATE ,STATUS  from DYN_1_CONNECTION_H where SER\
VICE_ID in (1,2,3)           ";

 static const char *sq0015 = 
"select SUBSCRIBER_NODE_ID ,SUBSCRIBER_PROFILE_ID ,IS_PAYMENT_RESPONSIBLE ,ST\
ATUS  from CAM_SUBSCRIBER_NODE            ";

 static const char *sq0016 = 
"select CONTRACT_PACKAGE_ID ,CONTRACT_ID ,STATUS  from CAM_CONTRACT_PACKAGE  \
          ";

 static const char *sq0017 = 
"select SUBSCRIBER_PROFILE_ID ,COMMUNICATION_LANGUAGE_ID  from CAM_SUBSCRIBER\
_PROFILE            ";

 static const char *sq0018 = 
"select NODE_ID ,NODE_TYPE ,BROUGHT_FWD ,INTERIM_BILL_AMOUNT  from BILL_I_PR_\
MASTER            ";

 static const char *sq0019 = 
"select CONTRACT_ID ,BROUGHT_FORWARD_OUTSTANDING ,INTERIM_BILL_AMOUNT  from B\
ILL_I_NONPR_CONTRACT_MASTER            ";

 static const char *sq0020 = 
"select NODE_ID ,NODE_TYPE ,AMOUNT  from BILL_BILL_MASTER_SUMMARY where ITEM_\
CODE='BILLAMT'           ";

 static const char *sq0021 = 
"select NODE_ID ,NODE_TYPE ,AMOUNT  from BILL_BILL_STATEMENT_SUMMARY where IT\
EM_CODE='BILLAMT'           ";

 static const char *sq0022 = 
"select TRAN_NO ,NODE_ID ,NODE_TYPE ,AMOUNT ,TRAN_DATE ,TRAN_TYPE  from FB_BI\
LL_TRANSACTIONS            ";

 static const char *sq0023 = 
"select TRAN_NO ,CONTRACT_ID ,TRAN_AMOUNT ,CONTRACT_BALANCE ,TRAN_DATE ,TRAN_\
TYPE  from FB_CONTRACT_BALANCES            ";

 static const char *sq0024 = 
"select RECEIPT_TRAN_NO ,PAYMENT_MODE  from FB_BILL_RECEIPTS            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4146,178,0,0,
5,0,0,1,0,0,32,55,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,71,0,0,4,4,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,5,0,
0,1,10,0,0,1,10,0,0,1,10,0,0,
64,0,0,3,54,0,1,72,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
92,0,0,4,0,0,27,88,0,0,4,4,0,3,6,82,65,84,73,78,71,1,5,0,0,1,10,0,0,1,10,0,0,1,
10,0,0,
129,0,0,5,54,0,1,89,0,0,0,0,0,3,6,82,65,84,73,78,71,
150,0,0,6,0,0,30,98,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
178,0,0,7,0,0,30,104,0,0,0,0,0,3,6,82,65,84,73,78,71,
199,0,0,8,55,0,4,118,0,0,1,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,5,
0,0,
231,0,0,9,75,0,4,138,0,0,1,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,5,
0,0,
263,0,0,10,309,0,9,229,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
291,0,0,10,0,0,13,234,0,0,15,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
379,0,0,10,0,0,15,293,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
407,0,0,11,104,0,9,349,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
435,0,0,11,0,0,13,354,0,0,5,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
483,0,0,11,0,0,15,398,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
511,0,0,12,130,0,9,457,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
539,0,0,12,0,0,13,464,0,0,6,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,3,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,
591,0,0,12,0,0,15,500,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
619,0,0,13,92,0,9,554,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
647,0,0,13,0,0,13,562,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
691,0,0,13,0,0,15,604,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
719,0,0,14,105,0,9,672,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
747,0,0,14,0,0,13,677,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
791,0,0,14,0,0,15,744,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
819,0,0,15,118,0,9,795,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
847,0,0,15,0,0,13,802,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
891,0,0,15,0,0,15,832,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
919,0,0,16,86,0,9,880,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
947,0,0,16,0,0,13,887,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,3,0,0,2,5,0,0,
987,0,0,16,0,0,15,913,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1015,0,0,17,96,0,9,961,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1043,0,0,17,0,0,13,968,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,
1079,0,0,17,0,0,15,991,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1107,0,0,18,94,0,9,1042,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1135,0,0,18,0,0,13,1049,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,2,4,0,0,2,4,0,0,
1179,0,0,18,0,0,15,1078,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1207,0,0,19,115,0,9,1126,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1235,0,0,19,0,0,13,1133,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,4,0,0,2,4,0,0,
1275,0,0,19,0,0,15,1157,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1303,0,0,20,101,0,9,1206,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1331,0,0,20,0,0,13,1212,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,2,4,0,0,
1371,0,0,20,0,0,15,1233,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1399,0,0,21,104,0,9,1282,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1427,0,0,21,0,0,13,1287,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,2,4,0,0,
1467,0,0,21,0,0,15,1308,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1495,0,0,22,103,0,9,1366,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1523,0,0,22,0,0,13,1375,0,0,6,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,3,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,
1575,0,0,22,0,0,15,1466,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1603,0,0,23,119,0,9,1527,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1631,0,0,23,0,0,13,1536,0,0,6,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,5,0,0,
1683,0,0,23,0,0,15,1626,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1711,0,0,24,71,0,9,1671,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1739,0,0,24,0,0,13,1677,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,
1775,0,0,24,0,0,15,1697,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1803,0,0,25,35,0,4,1710,0,0,1,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,
1835,0,0,26,82,0,3,1775,0,0,3,3,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,3,0,0,1,5,0,0,
1875,0,0,27,0,0,29,1782,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1903,0,0,28,82,0,3,1842,0,0,3,3,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,3,0,0,1,5,0,0,
1943,0,0,29,0,0,29,1849,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1971,0,0,30,275,0,5,1917,0,0,11,11,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,
69,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,
2043,0,0,31,0,0,29,1941,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2071,0,0,32,0,0,29,1945,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2099,0,0,33,26,0,1,1955,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2127,0,0,34,93,0,4,2030,0,0,3,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,2,4,0,0,
};




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>
#include <sqlda.h>
#include <sqlca.h>


#ifndef ORA_PROC
#include "data_containers.h"
#include <fstream>
#endif


extern	churn	*gsm_churn;

#define FETCH_SIZE	5000
#define BUF_LEN	100		


/* EXEC SQL DECLARE CUSTOMER_CARE DATABASE; */ 
 
/* EXEC SQL DECLARE RATING DATABASE; */ 
 

/* EXEC SQL BEGIN DECLARE SECTION; */ 

char *login_cust_care;
char *login_rating;
/* EXEC SQL END DECLARE SECTION; */ 



void sql_error(char *msg)
{
	cout << endl << msg << endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout << sqlca.sqlerrm.sqlerrmc << endl;
	cout << "in " << oraca.orastxt.orastxtc << endl;
	cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		<< endl << endl;
	
	//-- Roll back any pending changes and disconnect from Oracle.
	//EXEC SQL ROLLBACK RELEASE;
	exit(1);
}

void not_found_error(char *msg)
{
    cout << endl << msg << endl;
   
  //-- Roll back any pending changes and disconnect from Oracle.

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    exit(1);
}



//-- Connect to ORACLE as customer care. 
void db_connect_cust_care(char *in_login)
{
	login_cust_care = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 


	//ut<<"\nConnecting to ORACLE  as: "<<login_cust_care<<endl;
 	cout<<"\nConnecting to ORACLE  "<< endl;

    /* EXEC SQL CONNECT :login_cust_care AT CUSTOMER_CARE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login_cust_care;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	/* EXEC SQL AT CUSTOMER_CARE ALTER SESSION SET NLS_DATE_FORMAT="YYYYMMDDHH24MISS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"YYYYMMDDHH24MISS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )64;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	cout<<"Connected  to Database"<<endl<<endl; 

}


//-- Connect to ORACLE as rating. 
void db_connect_rating(char *in_login)
{
	login_rating = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 


	cout<<"\nConnecting to ORACLE  as: "<<login_rating<<endl;
 	cout<<"\nConnecting to ORACLE  "<< endl;

    /* EXEC SQL CONNECT :login_rating AT RATING; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )92;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login_rating;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	/* EXEC SQL AT RATING ALTER SESSION SET NLS_DATE_FORMAT="YYYYMMDDHH24MISS"; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"YYYYMMDDHH24MISS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )129;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	cout<<"Connected  to Database"<<endl<<endl; 

}


void db_disconnect_cust_care()
{
	cout<<"\nORACLE  customer care database: DISCONNECT"<<endl;
	/* EXEC SQL AT CUSTOMER_CARE COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}

void db_disconnect_rating()
{
	cout<<"\nORACLE  rating database: DISCONNECT"<<endl;
	/* EXEC SQL AT RATING COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )178;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
}


void churn::get_db_sysdate()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		 char	br_system_date[20];	

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL WHENEVER NOT FOUND DO not_found_error("not_found_error in get_db_sysdate()"); */ 
 

	/* EXEC SQL 
	AT customer_care
	SELECT	to_char(sysdate,'YYYYMMDD')
	INTO	:br_system_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(sysdate,'YYYYMMDD') into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )199;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("not_found_error in get_db_sysdate()");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	sys_date	= br_system_date;
	transition	= true;
}

void churn::get_db_last_bill_date()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		 char	br_last_bill_date[20];	

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL WHENEVER NOT FOUND DO transition_error("transition false"); */ 


	/* EXEC SQL 
	AT customer_care
	SELECT END_DATE 
		INTO : br_last_bill_date
		FROM bill_run_detail
	WHERE BR_STATUS = 'TRANSITION'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select END_DATE into :b0  from bill_run_detail where BR_STAT\
US='TRANSITION'";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )231;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_last_bill_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) transition_error("transition false");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	last_bill_date	= br_last_bill_date;
}

void churn::db_read_billenq_tab()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{ 
		char	row_id[BUF_LEN];
		char	billenq_mob_num[BUF_LEN];		// varchar2(10)	- NN
		char	billenq_acct_num[BUF_LEN];		// varchar2(10)	- NN
		char	billenq_pin[BUF_LEN];			// varchar2(6)	- NN
		char	billenq_current[BUF_LEN];		// varchar2(15)
		char	billenq_outstand[BUF_LEN];		// varchar2(15)
		char	billenq_last_update[BUF_LEN];	// varchar2(14)
		char	billenq_last_billamt[BUF_LEN];	// varchar2(15)
		char	billenq_last_billdate[BUF_LEN];	// varchar2(14)
		char	billenq_last_payamt[BUF_LEN];	// varchar2(15)
		char	billenq_last_paymode[BUF_LEN];	// varchar2(3)
		char	billenq_last_paydate[BUF_LEN];	// varchar2(14)
		char	billenq_lang[BUF_LEN];			// varchar2(1)
		char	billenq_min_payment[BUF_LEN];	// varchar2(15)
		char	billenq_con_type[BUF_LEN];		// varchar2(1)
	} *a;

	struct psi_ind
	{
		short	row_id_ind; 
 		short	billenq_mob_num_ind;
		short	billenq_acct_num_ind;
		short	billenq_pin_ind;
		short	billenq_current_ind;
		short	billenq_outstand_ind;
		short	billenq_last_update_ind;
 		short	billenq_last_billamt_ind;
		short	billenq_last_billdate_ind;
		short	billenq_last_payamt_ind;
		short	billenq_last_paymode_ind;
		short	billenq_last_paydate_ind;
		short	billenq_lang_ind;
		short	billenq_min_payment_ind;
		short	billenq_con_type_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for billenq_tab fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_billenq_tab CURSOR FOR 
	SELECT	ROWID,
		BILLENQ_MOB_NUM,
		BILLENQ_ACCT_NUM, 
		BILLENQ_PIN, 
		BILLENQ_CURRENT, 
		BILLENQ_OUTSTAND, 
		BILLENQ_LAST_UPDATE, 
		BILLENQ_LAST_BILLAMT, 
		BILLENQ_LAST_BILLDATE, 
		BILLENQ_LAST_PAYAMT, 
		BILLENQ_LAST_PAYMODE, 
		BILLENQ_LAST_PAYDATE, 
		BILLENQ_LANG, 
		BILLENQ_MIN_PAYMENT, 
		BILLENQ_CON_TYPE
	//FROM	BILLENQ_TAB_TEST;
	FROM	BILLENQ_TAB; */ 


 
	/* EXEC SQL AT customer_care  OPEN c_billenq_tab; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )263;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_billenq_tab INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )291;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)a->row_id;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->row_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->billenq_mob_num;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->billenq_mob_num_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->billenq_acct_num;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->billenq_acct_num_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->billenq_pin;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->billenq_pin_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->billenq_current;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->billenq_current_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->billenq_outstand;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->billenq_outstand_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->billenq_last_update;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->billenq_last_update_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->billenq_last_billamt;
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->billenq_last_billamt_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->billenq_last_billdate;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->billenq_last_billdate_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->billenq_last_payamt;
  sqlstm.sqhstl[9] = (unsigned int  )100;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->billenq_last_payamt_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->billenq_last_paymode;
  sqlstm.sqhstl[10] = (unsigned int  )100;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->billenq_last_paymode_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)a->billenq_last_paydate;
  sqlstm.sqhstl[11] = (unsigned int  )100;
  sqlstm.sqhsts[11] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->billenq_last_paydate_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)a->billenq_lang;
  sqlstm.sqhstl[12] = (unsigned int  )100;
  sqlstm.sqhsts[12] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->billenq_lang_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)a->billenq_min_payment;
  sqlstm.sqhstl[13] = (unsigned int  )100;
  sqlstm.sqhsts[13] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[13] = (         void  *)&a_ind->billenq_min_payment_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)a->billenq_con_type;
  sqlstm.sqhstl[14] = (unsigned int  )100;
  sqlstm.sqhsts[14] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[14] = (         void  *)&a_ind->billenq_con_type_ind;
  sqlstm.sqinds[14] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" billenq_tab=%d \n", rows_before);

		billenq	bt;
		
		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			strcpy(a[i].billenq_current,
				  ((a_ind[i].billenq_current_ind < 0) ? "UNDEF":a[i].billenq_current));
			strcpy(a[i].billenq_outstand,
				  ((a_ind[i].billenq_outstand_ind < 0) ? "UNDEF":a[i].billenq_outstand));
			strcpy(a[i].billenq_last_update,
				  ((a_ind[i].billenq_last_update_ind < 0) ? "UNDEF":a[i].billenq_last_update));
			strcpy(a[i].billenq_last_billamt,
				  ((a_ind[i].billenq_last_billamt_ind < 0) ? "UNDEF":a[i].billenq_last_billamt));
			strcpy(a[i].billenq_last_billdate,
				  ((a_ind[i].billenq_last_billdate_ind < 0) ? "UNDEF":a[i].billenq_last_billdate));
			strcpy(a[i].billenq_last_payamt,
				  ((a_ind[i].billenq_last_payamt_ind < 0) ? "UNDEF":a[i].billenq_last_payamt));
			strcpy(a[i].billenq_last_paymode,
				  ((a_ind[i].billenq_last_paymode_ind < 0) ? "UNDEF":a[i].billenq_last_paymode));
			strcpy(a[i].billenq_last_paydate,
				  ((a_ind[i].billenq_last_paydate_ind < 0) ? "UNDEF":a[i].billenq_last_paydate));
			strcpy(a[i].billenq_lang,
				  ((a_ind[i].billenq_lang_ind < 0) ? "UNDEF":a[i].billenq_lang));
			strcpy(a[i].billenq_min_payment,
				  ((a_ind[i].billenq_min_payment_ind < 0) ? "UNDEF":a[i].billenq_min_payment));
			strcpy(a[i].billenq_con_type,
				  ((a_ind[i].billenq_con_type_ind < 0) ? "UNDEF":a[i].billenq_con_type));
			
			bt.init();

			bt.row_id				= a[i].row_id;
			bt.billenq_mob_num		= a[i].billenq_mob_num;
			bt.billenq_acct_num		= a[i].billenq_acct_num;
			bt.billenq_pin			= a[i].billenq_pin;
			bt.billenq_current		= a[i].billenq_current;
			bt.billenq_outstand		= a[i].billenq_outstand;
			bt.billenq_last_update	= a[i].billenq_last_update;
			bt.billenq_last_billamt	= a[i].billenq_last_billamt;
			bt.billenq_last_billdate= a[i].billenq_last_billdate;
			bt.billenq_last_payamt	= a[i].billenq_last_payamt;
			bt.billenq_last_paymode	= a[i].billenq_last_paymode;
			bt.billenq_last_paydate	= a[i].billenq_last_paydate;
			bt.billenq_lang			= a[i].billenq_lang;
			bt.billenq_min_payment	= a[i].billenq_min_payment;
			bt.billenq_con_type		= a[i].billenq_con_type;

			billenq_db_map.insert(BILLENQ_DEF::value_type(a[i].billenq_mob_num, bt));
		}
	} 

	/* EXEC SQL AT customer_care CLOSE c_billenq_tab; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )379;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  billenq_tab data read.\n\n",rows_before);
}


void churn::db_read_prov_switch_image()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct psi_t
	{ 
		int		image_id;							// number(10)
		char	imsi_no[BUF_LEN];					// varchar2(15)
		char	conn_type[BUF_LEN];					// varchar2(10)
		char	status_reason_id[BUF_LEN];			// varchar2(5)
		char	switch_status[BUF_LEN];				// varchar2(2)
	} *a;

	struct psi_ind
	{ 
 		short	image_id_ind;
		short	imsi_no_ind;
		short	conn_type_ind;
		short	status_reason_id_ind;	
		short	switch_status_ind;		
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new psi_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for prov_switch_image fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_psi CURSOR FOR 
	SELECT	IMAGE_ID,
			IMSI_NO,
			CONN_TYPE,
			STATUS_REASON_ID,
			SWITCH_STATUS
	FROM	PROV_SWITCH_IMAGE; */ 


 
	/* EXEC SQL AT customer_care  OPEN c_psi; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )407;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_psi INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )435;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->image_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->image_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->imsi_no;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->imsi_no_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->conn_type;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->conn_type_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->status_reason_id;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->status_reason_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->switch_status;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct psi_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->switch_status_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct psi_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" prov_switch_image=%d \n", rows_before);

		prov_switch_image	psi;
		churn_data			cd;
		ccbs_profile		ccbs_p;

		DOC_DEF::iterator i_doc;

		
		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].image_id = (a_ind[i].image_id_ind < 0) ? 0 : a[i].image_id;
			strcpy(a[i].imsi_no,
				  ((a_ind[i].imsi_no_ind < 0) ? "UNDEF":a[i].imsi_no));
			strcpy(a[i].conn_type,
				  ((a_ind[i].conn_type_ind < 0) ? "UNDEF":a[i].conn_type));
			strcpy(a[i].status_reason_id,
				  ((a_ind[i].status_reason_id_ind < 0) ? "UNDEF":a[i].status_reason_id));
			strcpy(a[i].switch_status,
				  ((a_ind[i].switch_status_ind < 0) ? "UNDEF":a[i].switch_status));
			
			//if ( ( strncmp(a[i].conn_type, "VOICEPRE", 8) != 0 ) && ( strncmp(a[i].switch_status, "D", 1) != 0 ) )
			if ( strncmp(a[i].switch_status, "D", 1) != 0 )
			{
				ccbs_p.init();
				ccbs_p.imsi		= a[i].imsi_no;
				//ccbs_p.image_id	= a[i].image_id;

				//psi_map.insert(PSI_DEF::value_type(a[i].image_id, a[i].imsi_no));

				ccbs_profile_map.insert(CCBS_PROFILE_DEF::value_type(a[i].imsi_no, ccbs_p));

			}
		}
	} 

	/* EXEC SQL AT customer_care CLOSE c_psi; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )483;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  prov_switch_image data read.\n\n",rows_before);
}


void churn::db_read_cam_contract()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct contract_t
	{ 
		int		contract_id;							// number(10) - NN
		int		subscriber_node_id;						// number(10) - NN
		char	is_payment_responsible[BUF_LEN];		// varchar2(1)
		float	credit_limit;							// number(11,2)
		char	contract_type[BUF_LEN];					// varchar2(5) - NN
		char	status[BUF_LEN];						// varchar2(2) - NN
	} *a;

	struct contract_ind
	{ 
		short	contract_id_ind;							
		short	subscriber_node_id_ind;						
		short	is_payment_responsible_ind;		
		short	credit_limit_ind;							
		short	contract_type_ind;					
		short	status_ind;						
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
 
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new contract_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for cam_contract fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_contract CURSOR FOR 
	SELECT	CONTRACT_ID, 
			  SUBSCRIBER_NODE_ID, 
			  IS_PAYMENT_RESPONSIBLE, 
			  CREDIT_LIMIT, 
			  CONTRACT_TYPE, 
			  STATUS 
	FROM	CAM_CONTRACT; */ 


 
	/* EXEC SQL AT customer_care  OPEN c_contract; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )511;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	cam_contract cc;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_contract INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )539;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->contract_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->contract_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->subscriber_node_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->subscriber_node_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->is_payment_responsible;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->is_payment_responsible_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->credit_limit;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->credit_limit_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->contract_type;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->contract_type_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->status;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct contract_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct contract_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" cam_contract=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].contract_id = (a_ind[i].contract_id_ind < 0) ? 0 : a[i].contract_id;
			a[i].subscriber_node_id = (a_ind[i].subscriber_node_id_ind < 0) ? 0 : a[i].subscriber_node_id;

			strcpy(a[i].is_payment_responsible,
				  ((a_ind[i].is_payment_responsible_ind < 0) ? "UNDEF":a[i].is_payment_responsible));
			a[i].credit_limit = (a_ind[i].credit_limit_ind < 0) ? 0 : a[i].credit_limit;
			strcpy(a[i].contract_type,
				  ((a_ind[i].contract_type_ind < 0) ? "UNDEF":a[i].contract_type));
			strcpy(a[i].status,
				  ((a_ind[i].status_ind < 0) ? "UNDEF":a[i].status));

			cc.init();

			cc.contract_id				= a[i].contract_id;							
			cc.subscriber_node_id		= a[i].subscriber_node_id;						
			cc.is_payment_responsible	= a[i].is_payment_responsible;	
			cc.credit_limit				= a[i].credit_limit;							
			cc.contract_type			= a[i].contract_type;							
			cc.status					= a[i].status;									

			cam_contract_map.insert(CONTRACT_DEF::value_type(a[i].contract_id, cc));
		}
	} 

	/* EXEC SQL AT customer_care CLOSE c_contract; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )591;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cam_contract data read.\n\n",rows_before);
}


void churn::db_read_cam_connection()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_t
	{ 
		int		connection_id;						// number(10) - NN
		int		package_contract_id;					// number(10)
		char	status[BUF_LEN];					// varchar2(2) - NN
		int		image_id;							// number(10)
	} *a;

	struct connection_ind
	{ 
		short	connection_id_ind;
		short	package_contract_id_ind;					
		short	status_ind;							
		short	image_id_ind;						
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
 
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for cam_connection fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_connection CURSOR FOR 
	SELECT	CONNECTION_ID,
			PACKAGE_CONTRACT_ID, 
			  STATUS, 
			  IMAGE_ID 
	FROM	CAM_CONNECTION; */ 

	//FROM	CAM_CONNECTION_ivr_v;

 
	/* EXEC SQL AT customer_care  OPEN c_connection; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )619;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	
	cam_connection cc;

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_connection INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )647;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->connection_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->connection_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->package_contract_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->package_contract_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->status;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->image_id;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->image_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" cam_connection=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].connection_id = (a_ind[i].connection_id_ind < 0) ? 0 : a[i].connection_id;
			a[i].package_contract_id = (a_ind[i].package_contract_id_ind < 0) ? 0 : a[i].package_contract_id;
			strcpy(a[i].status,
				  ((a_ind[i].status_ind < 0) ? "UNDEF":a[i].status));
			a[i].image_id = (a_ind[i].image_id_ind < 0) ? 0 : a[i].image_id;
			
			/*
			cc.init();

			cc.connection_id			= a[i].connection_id;
			cc.package_contract_id		= a[i].package_contract_id;					
			cc.status					= a[i].status;
			cc.image_id					= a[i].image_id;

			cam_connection_map.insert(CONNECTION_DEF::value_type(a[i].connection_id, cc));

			if(set_current(a[i].image_id))
			{
				current->connection_id			= a[i].connection_id;
				current->package_contract_id	= a[i].package_contract_id;
			}
			*/

			if ( strncmp(a[i].status, "D", 1) != 0 )
			{
				cc_multimap.insert(CC_DEF::value_type(a[i].image_id, a[i].connection_id));
			}
		}
	} 

	/* EXEC SQL AT customer_care CLOSE c_connection; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )691;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cam_connection data read.\n\n",rows_before);
}



void churn::db_read_dyn_1_connection()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_t
	{ 
		char	imsi[BUF_LEN];					// varchar2(20)
		char	start_date[BUF_LEN];			// date - NN
		char	end_date[BUF_LEN];				// date
		char	status[BUF_LEN];				// varchar2(2)
	} *a;

	struct connection_ind
	{ 
		short	imsi_ind;			
		short	start_date_ind;	
		short	end_date_ind;
		short	status_ind;		
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	char	b_check_date[20];

	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(b_check_date, check_date);

	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for dyn_1_connection fetch"<<endl;
		exit(0);
	}

	cout << "b_check_date = " << b_check_date << "|" << endl;

	ccbs_profile ccbs_p;

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_conn CURSOR FOR 
	SELECT	IMSI,
			START_DATE,
			END_DATE,
			STATUS
	FROM	DYN_1_CONNECTION_H
	WHERE	SERVICE_ID IN(1,2,3); */ 


	//AND		to_date(to_char(START_DATE, 'YYYYMMDDHH24MISS'),'YYYYMMDDHH24MISS') < to_date (to_char(:b_check_date, 'YYYYMMDDHH24MISS'),'YYYYMMDDHH24MISS');

	//AND		STATUS NOT IN('D');

	//AND		to_date (to_char(:b_check_date, 'YYYYMMDDHH24MISS')) BETWEEN to_date(to_char(START_DATE, 'YYYYMMDDHH24MISS')) AND to_date(to_char(NVL(END_DATE, '20500101000000'),'YYYYMMDDHH24MISS'));
	

	/* EXEC SQL AT customer_care  OPEN c_conn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0014;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )719;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_conn INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )747;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)a->imsi;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->imsi_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->start_date;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->start_date_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->end_date;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->end_date_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->status;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" dyn_1_connection=%d \n", rows_before);

		//dyn_1_connection cc;
		reng_date_time c_date, s_date, e_date;

		check_date[14] = '\0';
		c_date.set_date_time(check_date);



		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			strcpy(a[i].imsi,
				  ((a_ind[i].imsi_ind < 0) ? "UNDEF":a[i].imsi));
			strcpy(a[i].start_date,
				  ((a_ind[i].start_date_ind < 0) ? "19490101000000":a[i].start_date));
			strcpy(a[i].end_date,
				  ((a_ind[i].end_date_ind < 0) ? "20500101000000":a[i].end_date));
			strcpy(a[i].status,
				  ((a_ind[i].status_ind < 0) ? "UNDEF":a[i].status));

			a[i].start_date[14] = '\0';
			s_date.set_date_time(a[i].start_date);

			a[i].end_date[14] = '\0';
			e_date.set_date_time(a[i].end_date);


			/*
			cout << "a[i].start_date = " << a[i].start_date << endl;
			cout << "a[i].end_date = " << a[i].end_date << endl;
			cout << "a[i].status = " << a[i].status << endl;
			*/

			

			//if ( ( db_first_minus_second(check_date, a[i].start_date) > 0 ) && ( 
			//db_first_minus_second(a[i].end_date, check_date) > 0 ) )
			
			
			//if ( ( strncmp(a[i].status, "D", 1) != 0 ) && ( db_first_minus_second(check_date, a[i].start_date) > 0 ) && ( 
			//db_first_minus_second(a[i].end_date, check_date) > 0 ) )
			
			if ( ( strncmp(a[i].status, "D", 1) != 0 ) && ( s_date < c_date ) && ( 
			c_date < e_date ) )
			{
				ccbs_p.init();
				ccbs_p.imsi		= a[i].imsi;

				ccbs_profile_map.insert(CCBS_PROFILE_DEF::value_type(a[i].imsi, ccbs_p));
				//cout << "put to map" << endl;
			}

			//int jj;

			//cin >> jj;
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_conn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )791;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  dyn_1_connection data read.\n\n",rows_before);
}


void churn::db_read_cam_subscriber_node()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct subscriber_t
	{ 
		int		subscriber_node_id;				// number(10) - NN
		int		subscriber_profile_id;			// number(10) - NN
		char	is_payment_responsible[BUF_LEN];	// varchar2(1)
		char	status[BUF_LEN];				// varchar2(2) - NN
	} *a;

	struct subscriber_ind
	{ 
		short	subscriber_node_id_ind;			
		short	subscriber_profile_id_ind;		
		short	is_payment_responsible_ind;		
		short	status_ind;						
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new subscriber_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for cam_subscriber_node fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_subscriber CURSOR FOR 
	SELECT	SUBSCRIBER_NODE_ID, 
		  SUBSCRIBER_PROFILE_ID, 
		  IS_PAYMENT_RESPONSIBLE, 
		  STATUS
	FROM	CAM_SUBSCRIBER_NODE; */ 


	/* EXEC SQL AT customer_care  OPEN c_subscriber; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )819;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	cam_subscriber_node cc;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_subscriber INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )847;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->subscriber_node_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct subscriber_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->subscriber_node_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct subscriber_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->subscriber_profile_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct subscriber_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->subscriber_profile_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct subscriber_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->is_payment_responsible;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct subscriber_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->is_payment_responsible_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct subscriber_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->status;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct subscriber_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct subscriber_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" cam_subscriber_node=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].subscriber_node_id = (a_ind[i].subscriber_node_id_ind < 0) ? 0 : a[i].subscriber_node_id;
			a[i].subscriber_profile_id = (a_ind[i].subscriber_profile_id_ind < 0) ? 0 : a[i].subscriber_profile_id;
			strcpy(a[i].is_payment_responsible,
				  ((a_ind[i].is_payment_responsible_ind < 0) ? "UNDEF":a[i].is_payment_responsible));
			strcpy(a[i].status,
				  ((a_ind[i].status_ind < 0) ? "UNDEF":a[i].status));
			
			cc.init();

			cc.subscriber_node_id		= a[i].subscriber_node_id ;				
			cc.subscriber_profile_id	= a[i].subscriber_profile_id ;			
			cc.is_payment_responsible	= a[i].is_payment_responsible ;		
			cc.status					= a[i].status ;						

			cam_subscriber_node_map.insert(CAM_SUBSCRIBER_NODE_DEF::value_type(a[i].subscriber_node_id, cc));
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_subscriber; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )891;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cam_subscriber_node data read.\n\n",rows_before);
}


void churn::db_read_cam_contract_package()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct contract_package_t
	{ 
		int		contract_package_id;					// number(10) - NN
		int		contract_id;							// number(10)
		char	status[BUF_LEN];						// varchar2(2) - NN
	} *a;

	struct contract_package_ind
	{ 
		short	contract_package_id_ind;					
		short	contract_id_ind;							
		short	status_ind;									
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new contract_package_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for cam_contract_package fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_ccp CURSOR FOR 
	SELECT	CONTRACT_PACKAGE_ID, 
		  CONTRACT_ID, 
		  STATUS 
	FROM	CAM_CONTRACT_PACKAGE; */ 


	/* EXEC SQL AT customer_care  OPEN c_ccp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )919;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	cam_contract_package cc;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_ccp INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )947;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->contract_package_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct contract_package_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->contract_package_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct contract_package_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->contract_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct contract_package_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->contract_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct contract_package_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->status;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct contract_package_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->status_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct contract_package_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" cam_contract_package =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			a[i].contract_package_id = (a_ind[i].contract_package_id_ind < 0) ? 0 : a[i].contract_package_id;
			a[i].contract_id = (a_ind[i].contract_id_ind < 0) ? 0 : a[i].contract_id;
			strcpy(a[i].status,
				  ((a_ind[i].status_ind < 0) ? "UNDEF":a[i].status));

			cc.init();

			cc.contract_package_id		= a[i].contract_package_id;
			cc.contract_id				= a[i].contract_id;
			cc.status					= a[i].status;

			cam_contract_package_map.insert(CAM_CONTRACT_PACKAGE_DEF::value_type(a[i].contract_package_id, cc));
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_ccp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )987;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cam_contract_package data read.\n\n",rows_before);
}





void churn::db_read_cam_subscriber_profile()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct profile_t
	{ 
		int		subscriber_profile_id;			// number(10)
		char	communication_language_id[BUF_LEN];	// varchar2(5)
	} *a;

	struct profile_ind
	{ 
		short	subscriber_profile_id_ind;
		short	communication_language_id_ind;		
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new profile_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for cam_subscriber_profile fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_profile CURSOR FOR 
	SELECT	SUBSCRIBER_PROFILE_ID,
			COMMUNICATION_LANGUAGE_ID
	FROM	CAM_SUBSCRIBER_PROFILE; */ 


	/* EXEC SQL AT customer_care  OPEN c_profile; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1015;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	cam_subscriber_profile csp;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_profile INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1043;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->subscriber_profile_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->subscriber_profile_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->communication_language_id;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->communication_language_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" cam_subscriber_profile =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].subscriber_profile_id = (a_ind[i].subscriber_profile_id_ind < 0) ? 0 : a[i].subscriber_profile_id;
			strcpy(a[i].communication_language_id,
				  ((a_ind[i].communication_language_id_ind < 0) ? "ENG":a[i].communication_language_id));
			
			csp.init();
			csp.communication_language_id=a[i].communication_language_id;

			cam_subscriber_profile_map.insert(PROFILE_DEF::value_type(a[i].subscriber_profile_id, csp));
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_profile; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1079;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cam_subscriber_profile data read.\n\n",rows_before);
}


void churn::db_read_bill_i_pr_master()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct profile_t
	{ 
		int		node_id;				// number(10)
		char	node_type[BUF_LEN];		// varchar2(2)
		float	brought_fwd;			// number(14,2)
		float	interim_bill_amount;	// number(14,2)
	} *a;

	struct profile_ind
	{ 
		short	node_id_ind;
		short	node_type_ind;
		short	brought_fwd_ind;
		short	interim_bill_amount_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new profile_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_i_pr_master fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_bill_i_pr_master CURSOR FOR 
	SELECT	NODE_ID,
			NODE_TYPE,
			BROUGHT_FWD,
			INTERIM_BILL_AMOUNT
	FROM	BILL_I_PR_MASTER; */ 


	/* EXEC SQL AT customer_care  OPEN c_bill_i_pr_master; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0018;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1107;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	bill_i_pr_master bipm;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_bill_i_pr_master INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1135;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->node_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->node_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->node_type;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->node_type_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->brought_fwd;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->brought_fwd_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->interim_bill_amount;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->interim_bill_amount_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" bill_i_pr_master =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].node_id = (a_ind[i].node_id_ind < 0) ? 0 : a[i].node_id;
			strcpy(a[i].node_type,
				  ((a_ind[i].node_type_ind < 0) ? "UNDEF":a[i].node_type));
			a[i].brought_fwd = (a_ind[i].brought_fwd_ind < 0) ? 0.0 : a[i].brought_fwd;
			a[i].interim_bill_amount = (a_ind[i].interim_bill_amount_ind < 0) ? 0.0 : a[i].interim_bill_amount;

			if ( strncmp(a[i].node_type, "C", 1) == 0 )
			{
				bipm.init();
				bipm.brought_fwd			= a[i].brought_fwd;
				bipm.interim_bill_amount	= a[i].interim_bill_amount;

				bill_i_pr_master_map.insert(BILL_I_PR_MASTER_DEF::value_type(a[i].node_id, bipm));
			}
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_bill_i_pr_master; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1179;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_i_pr_master data read.\n\n",rows_before);
}


void churn::db_read_bill_i_nonpr_contract_master()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct profile_t
	{ 
		int		contract_id;					// number(10)
		float	brought_forward_outstanding;	// number(14,2)
		float	interim_bill_amount;			// number(14,2)
	} *a;

	struct profile_ind
	{ 
		short	contract_id_ind;
		short	brought_forward_outstanding_ind;
		short	interim_bill_amount_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new profile_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_i_nonpr_contract_master fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_bill_i_nonpr_contract_master CURSOR FOR 
	SELECT	CONTRACT_ID,
			BROUGHT_FORWARD_OUTSTANDING,
			INTERIM_BILL_AMOUNT
	FROM	BILL_I_NONPR_CONTRACT_MASTER; */ 


	/* EXEC SQL AT customer_care  OPEN c_bill_i_nonpr_contract_master; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1207;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	bill_i_nonpr_contract_master binpcm;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_bill_i_nonpr_contract_master INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1235;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->contract_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->contract_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->brought_forward_outstanding;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->brought_forward_outstanding_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->interim_bill_amount;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct profile_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->interim_bill_amount_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct profile_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" bill_i_nonpr_contract_master =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].contract_id = (a_ind[i].contract_id_ind < 0) ? 0 : a[i].contract_id;
			a[i].brought_forward_outstanding = (a_ind[i].brought_forward_outstanding_ind < 0) ? 0.0 : a[i].brought_forward_outstanding;
			a[i].interim_bill_amount = (a_ind[i].interim_bill_amount_ind < 0) ? 0.0 : a[i].interim_bill_amount;

			binpcm.init();
			binpcm.brought_forward_outstanding			= a[i].brought_forward_outstanding;
			binpcm.interim_bill_amount	= a[i].interim_bill_amount;

			bill_i_nonpr_contract_master_map.insert(BILL_I_NONPR_CONTRACT_MASTER_DEF::value_type(a[i].contract_id, binpcm));
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_bill_i_nonpr_contract_master; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1275;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_i_nonpr_contract_master data read.\n\n",rows_before);
}


void churn::db_read_bill_bill_master_summary()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct contract_balances_t
	{ 
		int		node_id;					// number(10)
		char	node_type[BUF_LEN];			// varchar2(1)
		float	amount;						// number(14,2)
	} *a;

	struct contract_balances_ind
	{ 
		short	node_id_ind;					
		short	node_type_ind;				
		short	amount_ind;					
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new contract_balances_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_bill_master_summary fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_contract_balances CURSOR FOR 
	SELECT		NODE_ID,          
				NODE_TYPE,       
				AMOUNT       
	FROM	BILL_BILL_MASTER_SUMMARY
	WHERE	ITEM_CODE = 'BILLAMT'; */ 


	/* EXEC SQL AT customer_care  OPEN c_contract_balances; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1303;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 


	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_contract_balances INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1331;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->node_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->node_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->node_type;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->node_type_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->amount;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->amount_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" fb_contract_balances =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].amount = (a_ind[i].amount_ind < 0) ? 0.0 : a[i].amount;

			if ( strncmp(a[i].node_type, "C", 1) == 0 )
			{
				bill_bill_master_summary_map.insert(BILL_BILL_MASTER_SUMMARY_DEF::value_type(a[i].node_id, a[i].amount));
			}
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_contract_balances; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1371;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_bill_master_summary data read.\n\n",rows_before);
}

void churn::db_read_bill_bill_statement_summary()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct contract_balances_t
	{ 
		int		node_id;					// number(10)
		char	node_type[BUF_LEN];			// varchar2(1)
		float	amount;						// number(14,2)
	} *a;

	struct contract_balances_ind
	{ 
		short	node_id_ind;					
		short	node_type_ind;			
		short	amount_ind;					
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new contract_balances_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_bill_statement_summary fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_bill_bill_statement_summary CURSOR FOR 
	SELECT		NODE_ID,          
				NODE_TYPE,         
				AMOUNT       
	FROM	BILL_BILL_STATEMENT_SUMMARY
	WHERE	ITEM_CODE = 'BILLAMT'; */ 



	/* EXEC SQL AT customer_care  OPEN c_bill_bill_statement_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1399;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_bill_bill_statement_summary INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1427;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->node_id;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->node_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->node_type;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->node_type_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->amount;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct contract_balances_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->amount_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct contract_balances_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" bill_bill_statement_summary =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].amount = (a_ind[i].amount_ind < 0) ? 0 : a[i].amount;

			if ( strncmp(a[i].node_type, "C", 1) == 0 )
			{
				bill_bill_statement_summary_map.insert(BILL_BILL_STATEMENT_SUMMARY_DEF::value_type(a[i].node_id, a[i].amount));
			}
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_bill_bill_statement_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1467;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_bill_statement_summary data read.\n\n",rows_before);
}


void churn::db_read_fb_bill_transactions()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_transactions_t
	{
		int		tran_no;					// number(16)
		int		node_id;					// number(10)
		char	node_type[BUF_LEN];			// varchar2(1) 
		float	amount;						// number(14,2)
		char	tran_date[BUF_LEN];			// date
		char	tran_type[BUF_LEN];			// varchar2(10) 
	} *a;

	struct bill_transactions_ind
	{ 
  		short	tran_no_ind;				
		short	node_id_ind;
		short	node_type_ind;
		short	amount_ind;	
		short	tran_date_ind;
		short	tran_type_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_transactions_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for fb_bill_transactions fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_bill_transactions CURSOR FOR 
	SELECT	TRAN_NO,
			NODE_ID,
			NODE_TYPE,
			AMOUNT,
			TRAN_DATE,
			TRAN_TYPE
	FROM	FB_BILL_TRANSACTIONS; */ 

	//WHERE	TRAN_TYPE = 'BILL';

	/* EXEC SQL AT customer_care  OPEN c_bill_transactions; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0022;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1495;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	fb_bill_transactions fbt;
	FB_BILL_TRANSACTIONS_DEF::iterator i_fbt;
	reng_date_time rdt;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_bill_transactions INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1523;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->tran_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->tran_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->node_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->node_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->node_type;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->node_type_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->amount;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->amount_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->tran_date;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->tran_date_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->tran_type;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->tran_type_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" fb_bill_transactions =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			a[i].amount = (a_ind[i].amount_ind < 0) ? 0 : a[i].amount;
			strcpy(a[i].tran_type,
				  ((a_ind[i].tran_type_ind < 0) ? "UNDEF":a[i].tran_type));
	
			if ( strncmp(a[i].node_type, "C", 1) == 0 )		// only PR contracts
															// non PR contracts are loaded in
															// db_read_fb_contract_balances()
			{
				if ( strncmp(a[i].tran_type, "BILL", 4) == 0 )
				{
					if ( ( i_fbt = fb_bill_transactions_bill_map.find(a[i].node_id) ) == fb_bill_transactions_bill_map.end() )
					{
						fbt.init();
						fbt.amount		= a[i].amount;					
						fbt.tran_date	= a[i].tran_date;
						fbt.tran_no		= a[i].tran_no;
						a[i].tran_date[14] = '\0';
						fbt.tran_date_rdt.set_date_time(a[i].tran_date); 
							
						fb_bill_transactions_bill_map.insert(FB_BILL_TRANSACTIONS_DEF::value_type(a[i].node_id, fbt));
					}
					else
					{
						rdt.date.init();
						rdt.time.init();
						a[i].tran_date[14] = '\0';
						rdt.set_date_time(a[i].tran_date); 
						if ( (*i_fbt).second.tran_date_rdt < rdt )
						{
							fbt.init();
							fbt.amount		= a[i].amount;					
							fbt.tran_date	= a[i].tran_date;
							fbt.tran_no		= a[i].tran_no;
							fbt.tran_date_rdt.set_date_time(a[i].tran_date); 

							fb_bill_transactions_bill_map.erase(i_fbt);

							fb_bill_transactions_bill_map.insert(FB_BILL_TRANSACTIONS_DEF::value_type(a[i].node_id, fbt));
						}
					}
				}
				if ( strncmp(a[i].tran_type, "PAY", 3) == 0 )
				{

					if ( ( i_fbt = fb_bill_transactions_pay_map.find(a[i].node_id) ) == fb_bill_transactions_pay_map.end() )
					{
						fbt.init();
						fbt.amount		= a[i].amount;					
						fbt.tran_date	= a[i].tran_date;
						fbt.tran_no		= a[i].tran_no;
						a[i].tran_date[14] = '\0';
						fbt.tran_date_rdt.set_date_time(a[i].tran_date); 
							
						fb_bill_transactions_pay_map.insert(FB_BILL_TRANSACTIONS_DEF::value_type(a[i].node_id, fbt));
					}
					else
					{
						rdt.date.init();
						rdt.time.init();
						rdt.set_date_time(a[i].tran_date); 
						if ( (*i_fbt).second.tran_date_rdt < rdt )
						{
							fbt.init();
							fbt.amount		= a[i].amount;					
							fbt.tran_date	= a[i].tran_date;
							fbt.tran_no		= a[i].tran_no;
							a[i].tran_date[14] = '\0';
							fbt.tran_date_rdt.set_date_time(a[i].tran_date);

							fb_bill_transactions_pay_map.erase(i_fbt);

							fb_bill_transactions_pay_map.insert(FB_BILL_TRANSACTIONS_DEF::value_type(a[i].node_id, fbt));
						}
					}
				}
			}
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_bill_transactions; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1575;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  fb_bill_transactions data read.\n\n",rows_before);
}





void churn::db_read_fb_contract_balances()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_transactions_t
	{
		int		tran_no;					// number(16)
		int		contract_id;				// number(10)
		float	tran_amount;				// number(14,2)
		float	contract_balance;			// number(14,2)
		char	tran_date[BUF_LEN];			// date
		char	tran_type[BUF_LEN];			// varchar2(10)
	} *a;

	struct bill_transactions_ind
	{ 
		short	tran_no_ind;
  		short	contract_id_ind;				
		short	tran_amount_ind;
		short	contract_balance_ind;
		short	tran_date_ind;
		short	tran_type_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_transactions_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for fb_bill_transactions fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_fb_contract_balances CURSOR FOR 
	SELECT	TRAN_NO,	
			CONTRACT_ID,
			TRAN_AMOUNT,
			CONTRACT_BALANCE,
			TRAN_DATE,
			TRAN_TYPE
	FROM	FB_CONTRACT_BALANCES; */ 

	//WHERE	TRAN_TYPE = 'BILL';

	/* EXEC SQL AT customer_care  OPEN c_fb_contract_balances; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1603;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	fb_contract_balances fcb;
	FB_CONTRACT_BALANCES_DEF::iterator i_fcb;
	reng_date_time rdt;
	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_fb_contract_balances INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1631;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->tran_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->tran_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->contract_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->contract_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->tran_amount;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->tran_amount_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->contract_balance;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->contract_balance_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->tran_date;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->tran_date_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->tran_type;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->tran_type_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" fb_contract_balances =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches
			strcpy(a[i].tran_type,
				  ((a_ind[i].tran_type_ind < 0) ? "UNDEF":a[i].tran_type));

			if ( strncmp(a[i].tran_type, "BILL", 4) == 0 )
			{
				if ( ( i_fcb = fb_contract_balances_bill_map.find(a[i].contract_id) ) == fb_contract_balances_bill_map.end() )
				{
					fcb.init();
					fcb.tran_amount		= a[i].tran_amount;	
					fcb.contract_balance= a[i].contract_balance;					
					fcb.tran_date	= a[i].tran_date;
					fcb.tran_no		= a[i].tran_no;
					a[i].tran_date[14] = '\0';
					fcb.tran_date_rdt.set_date_time(a[i].tran_date); 
							
					fb_contract_balances_bill_map.insert(FB_CONTRACT_BALANCES_DEF::value_type(a[i].contract_id, fcb));
				}
				else
				{
					rdt.date.init();
					rdt.time.init();
					rdt.set_date_time(a[i].tran_date); 

					if ( (*i_fcb).second.tran_date_rdt < rdt )
					{
						fcb.init();
						fcb.tran_amount		= a[i].tran_amount;	
						fcb.contract_balance= a[i].contract_balance;					
						fcb.tran_date	= a[i].tran_date;
						fcb.tran_no		= a[i].tran_no;
						a[i].tran_date[14] = '\0';
						fcb.tran_date_rdt.set_date_time(a[i].tran_date);

						fb_contract_balances_bill_map.erase(i_fcb);
							
						fb_contract_balances_bill_map.insert(FB_CONTRACT_BALANCES_DEF::value_type(a[i].contract_id, fcb));
					}
				}
			}

			if ( strncmp(a[i].tran_type, "PAY", 3) == 0 )
			{
				if ( ( i_fcb = fb_contract_balances_pay_map.find(a[i].contract_id) ) == fb_contract_balances_pay_map.end() )
				{
					fcb.init();
					fcb.tran_amount		= a[i].tran_amount;	
					fcb.contract_balance= a[i].contract_balance;					
					fcb.tran_date	= a[i].tran_date;
					fcb.tran_no		= a[i].tran_no;
					a[i].tran_date[14] = '\0';
					fcb.tran_date_rdt.set_date_time(a[i].tran_date); 
							
					fb_contract_balances_pay_map.insert(FB_CONTRACT_BALANCES_DEF::value_type(a[i].contract_id, fcb));
				}
				else
				{
					rdt.date.init();
					rdt.time.init();
					rdt.set_date_time(a[i].tran_date); 

					if ( (*i_fcb).second.tran_date_rdt < rdt )
					{
						fcb.init();
						fcb.tran_amount		= a[i].tran_amount;	
						fcb.contract_balance= a[i].contract_balance;					
						fcb.tran_date	= a[i].tran_date;
						fcb.tran_no		= a[i].tran_no;
						a[i].tran_date[14] = '\0';
						fcb.tran_date_rdt.set_date_time(a[i].tran_date); 

						fb_contract_balances_pay_map.erase(i_fcb);
							
						fb_contract_balances_pay_map.insert(FB_CONTRACT_BALANCES_DEF::value_type(a[i].contract_id, fcb));
					}
				}
			}
		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_fb_contract_balances; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1683;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  fb_contract_balances data read.\n\n",rows_before);
}


void churn::db_read_fb_bill_receipts()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_transactions_t
	{
		int		receipt_tran_no;				// number(16)
		char	payment_mode[BUF_LEN];			// varchar2(5)
	} *a;

	struct bill_transactions_ind
	{ 
		short	receipt_tran_no_ind;
  		short	payment_mode_ind;				
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_transactions_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for fb_bill_transactions fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT customer_care 
	DECLARE  c_fb_bill_receipts CURSOR FOR 
	SELECT	RECEIPT_TRAN_NO,	
			PAYMENT_MODE
	FROM	FB_BILL_RECEIPTS; */ 


	/* EXEC SQL AT customer_care  OPEN c_fb_bill_receipts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0024;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1711;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	
	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT customer_care FOR :rows_to_fetch FETCH c_fb_bill_receipts INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1739;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&a->receipt_tran_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->receipt_tran_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->payment_mode;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_transactions_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->payment_mode_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_transactions_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" fb_bill_receipts =%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{

			//handling null fetches

			strcpy(a[i].payment_mode,
				  ((a_ind[i].payment_mode_ind < 0) ? "UNDEF":a[i].payment_mode));

			fb_bill_receipts_map.insert(FB_BILL_RECEIPTS_DEF::value_type(a[i].receipt_tran_no, a[i].payment_mode));

		}
	}
	
	/* EXEC SQL AT customer_care CLOSE c_fb_bill_receipts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1775;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  fb_bill_receipts data read.\n\n",rows_before);
}

void churn::db_get_sysdate()
{
	// YYYYMMDDHH24MISS

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char	b_sysdate[20];			
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL
	AT customer_care
	SELECT SYSDATE
	INTO	:b_sysdate	
	FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select SYSDATE into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1803;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_sysdate;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	strcpy(sys_date, b_sysdate);
}


void churn::db_insert_churn_data()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_churn
	{
		char	imsi[BUF_LEN];			// varchar2(20)	
		//char	msisdn[BUF_LEN];		// varchar2(20)
		int		reason_id;				// number(3)
		char	insert_date[BUF_LEN];	// date
	} *a; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	
	rows_to_insert = bulk_insert_size;
	
	if((a = new db_churn[bulk_insert_size])==NULL)
	{
		cout<<" cant allocate memory for churn data insert"<<endl;
		exit(0);
	}

	for(int j=0; j<insert_iterations; j++)
	{

		for(int n=0; n<rows_to_insert; n++)
		{
			a[n].imsi[0]		='\0';
			//a[n].msisdn[0]		='\0';
			a[n].reason_id		= 0;
			a[n].insert_date[0]	='\0';
		}
		
		for(int i=0; i<rows_to_insert; i++, i_db_insert++)
		{
			//a[i].imsi[0]		='\0';
			//a[i].msisdn[0]		='\0';
			//a[i].insert_date[0]	='\0';

			strncpy(a[i].imsi,			( (*i_db_insert).first).c_str(), 15 );
			//strncpy(a[i].msisdn,		( (*i_db_insert).second.msisdn).c_str(), 7 );
			a[i].reason_id				= (*i_db_insert).second.reason_id;
			strncpy(a[i].insert_date,	 sys_date, 16 );
			
			a[i].imsi[15]		='\0';
			//a[i].msisdn[7]		='\0';
			a[i].insert_date[17]='\0';

			//cout << (*i_db_insert).second.msisdn << "---" << endl;
			//cout << a[i].msisdn << "-=+++" << endl;
		} 


		/* EXEC SQL  AT customer_care  FOR :rows_to_insert  INSERT INTO HLR_CCBS_MISMATCH (
			imsi,
			//msisdn,
			reason_id,
			insert_date
		) VALUES (:a); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into HLR_CCBS_MISMATCH (imsi,reason_id,insert_date) \
values (:s1 ,:s2 ,:s3 )";
  sqlstm.iters = (unsigned int  )rows_to_insert;
  sqlstm.offset = (unsigned int  )1835;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->imsi;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct db_churn);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->reason_id;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct db_churn);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->insert_date;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct db_churn);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
		/* EXEC SQL AT customer_care  COMMIT; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1875;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	}
	
	delete a;
}


void churn::db_insert_churn_data_remainder()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	static struct db_churn
	{
		char	imsi[BUF_LEN];			// varchar2(20)	
		//char	msisdn[BUF_LEN];		// varchar2(20)
		int		reason_id;				// number(3)
		char	insert_date[BUF_LEN];	// date
	} *a; 
	
	int rows_to_insert;
	
	/* EXEC SQL END DECLARE SECTION; */ 

	rows_to_insert = remainder_insert_size;
	
	if((a = new db_churn[remainder_insert_size])==NULL)
	{
		cout<<" cant allocate memory for churn data insert"<<endl;
		exit(0);
	}

	for(int n=0; n<rows_to_insert; n++)
	{
			a[n].imsi[0]		='\0';
			//a[n].msisdn[0]		='\0';
			a[n].reason_id		= 0;
			a[n].insert_date[0]	='\0';
	}


	for(int i=0; i<rows_to_insert; i++, i_db_insert++)
	{
			//a[i].imsi[0]		='\0';
			//a[i].msisdn[0]		='\0';
			//a[i].insert_date[0]	='\0';

			strncpy(a[i].imsi,			( (*i_db_insert).first).c_str(), 15 );
			//strncpy(a[i].msisdn,		( (*i_db_insert).second.msisdn).c_str(), 7 );
			a[i].reason_id				= (*i_db_insert).second.reason_id;
			strncpy(a[i].insert_date,	sys_date, 16 );
			
			a[i].imsi[15]		='\0';
			//a[i].msisdn[7]		='\0';
			a[i].insert_date[17]='\0';

			//cout << (*i_db_insert).second.msisdn << "---" << endl;
			//cout << a[i].msisdn << "-=+++" << endl;
		
	} 


	/* EXEC SQL  AT customer_care  FOR :rows_to_insert  INSERT INTO HLR_CCBS_MISMATCH (
			imsi,
			//msisdn,
			reason_id,
			insert_date
	) VALUES (:a); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into HLR_CCBS_MISMATCH (imsi,reason_id,insert_date) v\
alues (:s1 ,:s2 ,:s3 )";
 sqlstm.iters = (unsigned int  )rows_to_insert;
 sqlstm.offset = (unsigned int  )1903;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)a->imsi;
 sqlstm.sqhstl[0] = (unsigned int  )100;
 sqlstm.sqhsts[0] = (         int  )sizeof(struct db_churn);
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&a->reason_id;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )sizeof(struct db_churn);
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)a->insert_date;
 sqlstm.sqhstl[2] = (unsigned int  )100;
 sqlstm.sqhsts[2] = (         int  )sizeof(struct db_churn);
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL AT customer_care  COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1943;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	delete a;
}

void churn::db_update_billenq_tab()
{
	printf("\n updating billenq_tab \n ");

	cout << "rows to update = " << billenq_db_map.size() << endl;

	int	rows_inserted = 0;

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		char	row_id[BUF_LEN];
		//char	billenq_mob_num[BUF_LEN];		// varchar2(10)	- NN
		char	billenq_acct_num[BUF_LEN];		// varchar2(10)	- NN
		//char	billenq_pin[BUF_LEN];			// varchar2(6)	- NN
		char	billenq_current[BUF_LEN];		// varchar2(15)
		char	billenq_outstand[BUF_LEN];		// varchar2(15)
		char	billenq_last_update[BUF_LEN];	// varchar2(14)
		char	billenq_last_billamt[BUF_LEN];	// varchar2(15)
		char	billenq_last_billdate[BUF_LEN];	// varchar2(14)
		char	billenq_last_payamt[BUF_LEN];	// varchar2(15)
		char	billenq_last_paymode[BUF_LEN];	// varchar2(3)
		char	billenq_last_paydate[BUF_LEN];	// varchar2(14)
		//char	billenq_lang[BUF_LEN];			// varchar2(1)
		char	billenq_min_payment[BUF_LEN];	// varchar2(15)
		char	billenq_con_type[BUF_LEN];		// varchar2(1)
	
	/* EXEC SQL END DECLARE SECTION; */ 


	for(BILLENQ_DEF::iterator i_db_insert =billenq_db_map.begin(); i_db_insert!=billenq_db_map.end(); i_db_insert++)
	{
		strncpy(row_id,					( (*i_db_insert).second.row_id).c_str(), 18 );
		//strncpy(billenq_mob_num,		( (*i_db_insert).second.billenq_mob_num).c_str(), 10 );
		strncpy(billenq_acct_num,		( (*i_db_insert).second.billenq_acct_num).c_str(), 10 );
		//strncpy(billenq_pin,			( (*i_db_insert).second.billenq_pin).c_str(), 6 );
		strncpy(billenq_current,		( (*i_db_insert).second.billenq_current).c_str(), 15 );
		strncpy(billenq_outstand,		( (*i_db_insert).second.billenq_outstand).c_str(), 15 );
		strncpy(billenq_last_update,	( (*i_db_insert).second.billenq_last_update).c_str(), 14 );
		strncpy(billenq_last_billamt,	( (*i_db_insert).second.billenq_last_billamt).c_str(), 15 );
		strncpy(billenq_last_billdate,	( (*i_db_insert).second.billenq_last_billdate).c_str(), 10 );
		strncpy(billenq_last_payamt,	( (*i_db_insert).second.billenq_last_payamt).c_str(), 15 );
		strncpy(billenq_last_paymode,	( (*i_db_insert).second.billenq_last_paymode).c_str(), 3 );
		strncpy(billenq_last_paydate,	( (*i_db_insert).second.billenq_last_paydate).c_str(), 10 );
		//strncpy(billenq_lang,			( (*i_db_insert).second.billenq_lang).c_str(), 1 );
		strncpy(billenq_min_payment,	( (*i_db_insert).second.billenq_min_payment).c_str(), 15 );
		strncpy(billenq_con_type,		( (*i_db_insert).second.billenq_con_type).c_str(), 1 );

		
		row_id[18]				='\0';
		//billenq_mob_num[10]	='\0';
		billenq_acct_num[10]	='\0';
		//billenq_pin[6]		='\0';
		billenq_current[15]		='\0';
		billenq_outstand[15]	='\0';
		billenq_last_update[14]	='\0';
		billenq_last_billamt[15]='\0';
		billenq_last_billdate[10]='\0';
		billenq_last_payamt[15]	='\0';
		billenq_last_paymode[3]	='\0';
		billenq_last_paydate[10]='\0';
		//billenq_lang[1]		='\0';
		billenq_min_payment[15]	='\0';
		billenq_con_type[1]		='\0';


		/* EXEC SQL 
		AT customer_care 
		UPDATE  BILLENQ_TAB
		//UPDATE  BILLENQ_TAB_TEST
		SET
			//BILLENQ_MOB_NUM			= :billenq_mob_num, 
			BILLENQ_ACCT_NUM		= :billenq_acct_num, 
			//BILLENQ_PIN				= :billenq_pin, 
			BILLENQ_CURRENT			= :billenq_current, 
			BILLENQ_OUTSTAND		= :billenq_outstand, 
			BILLENQ_LAST_UPDATE		= :billenq_last_update, 
			BILLENQ_LAST_BILLAMT	= :billenq_last_billamt, 
			BILLENQ_LAST_BILLDATE	= :billenq_last_billdate, 
			BILLENQ_LAST_PAYAMT		= :billenq_last_payamt, 
			BILLENQ_LAST_PAYMODE	= :billenq_last_paymode, 
			BILLENQ_LAST_PAYDATE	= :billenq_last_paydate, 
			//BILLENQ_LANG			= :billenq_lang, 
			BILLENQ_MIN_PAYMENT		= :billenq_min_payment 
		WHERE
		  ROWID = :row_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update BILLENQ_TAB  set BILLENQ_ACCT_NUM=:b0,BILLENQ_CURREN\
T=:b1,BILLENQ_OUTSTAND=:b2,BILLENQ_LAST_UPDATE=:b3,BILLENQ_LAST_BILLAMT=:b4,BI\
LLENQ_LAST_BILLDATE=:b5,BILLENQ_LAST_PAYAMT=:b6,BILLENQ_LAST_PAYMODE=:b7,BILLE\
NQ_LAST_PAYDATE=:b8,BILLENQ_MIN_PAYMENT=:b9 where ROWID=:b10";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1971;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)billenq_acct_num;
  sqlstm.sqhstl[0] = (unsigned int  )100;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)billenq_current;
  sqlstm.sqhstl[1] = (unsigned int  )100;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)billenq_outstand;
  sqlstm.sqhstl[2] = (unsigned int  )100;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)billenq_last_update;
  sqlstm.sqhstl[3] = (unsigned int  )100;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)billenq_last_billamt;
  sqlstm.sqhstl[4] = (unsigned int  )100;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)billenq_last_billdate;
  sqlstm.sqhstl[5] = (unsigned int  )100;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)billenq_last_payamt;
  sqlstm.sqhstl[6] = (unsigned int  )100;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)billenq_last_paymode;
  sqlstm.sqhstl[7] = (unsigned int  )100;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)billenq_last_paydate;
  sqlstm.sqhstl[8] = (unsigned int  )100;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)billenq_min_payment;
  sqlstm.sqhstl[9] = (unsigned int  )100;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)row_id;
  sqlstm.sqhstl[10] = (unsigned int  )100;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		rows_inserted++;
		if( !(rows_inserted%500))
		{
			/* EXEC SQL AT customer_care  COMMIT; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 15;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2043;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


		}
	}

	/* EXEC SQL AT customer_care  COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2071;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	printf("billenq_tab updated ");
}

//-- truncate billenq_tab
void churn::db_truncate_billenq_tab()
{
	printf("truncating billenq_tab");
	
    /* EXEC SQL 
	AT customer_care 
	TRUNCATE TABLE BILLENQ_TAB; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "truncate TABLE BILLENQ_TAB";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2099;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

				
			
	printf("\n billenq_tab truncated");
}



double churn::get_reminder_balance(int contract_id)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		float	b_min_payment;
		int		b_contract_id;		// number(10)
	
	/* EXEC SQL END DECLARE SECTION; */ 


	b_contract_id	= contract_id;

/*
	EXEC SQL AT customer_care
	EXECUTE
	BEGIN
	:b_min_payment := FB_BILL_TRAN_API.GET_INTERIM_BALANCE(:b_contract_id);
	END;
	END-EXEC;

	*/

	return b_min_payment;
}




double churn::get_interim_balance(int contract_id)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		float	b_min_payment;
		int		b_contract_id;		// number(10)
	
	/* EXEC SQL END DECLARE SECTION; */ 


	b_contract_id	= contract_id;

/*
	EXEC SQL AT customer_care
	EXECUTE
	BEGIN
	:b_min_payment := FB_BILL_TRAN_API.GET_INTERIM_BALANCE(:b_contract_id);
	END;
	END-EXEC;
*/
	return b_min_payment;
}


float churn::db_first_minus_second(char* first_date, char* second_date)
{
	// YYYYMMDDHH24MISS

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	b_first_date[20];			
	char	b_second_date[20];		
	float	b_difference;				
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(b_first_date, first_date);
	strcpy(b_second_date, second_date);
	//b_difference = 0;
	
	
	/* EXEC SQL
	AT customer_care
	SELECT to_date(:b_first_date,'YYYYMMDDHH24MISS') - to_date(:b_second_date,'YYYYMMDDHH24MISS')
	INTO	:b_difference	
	FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select (to_date(:b0,'YYYYMMDDHH24MISS')-to_date(:b1,'YYYYMMD\
DHH24MISS')) into :b2  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2127;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_first_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)b_second_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&b_difference;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	//cout << b_difference << endl;
	
	return b_difference;

}

