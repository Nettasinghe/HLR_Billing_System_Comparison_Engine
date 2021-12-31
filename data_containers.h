
//////////////////////////////////////////////////////////////////////////////////////
//
// data_containers.h
// definitions for classes for HLR-CCBS Comparison Engine for Telco Revenue Assurance 
// developer - Chandika Nettasinghe
// code start - 2003-August
//
//////////////////////////////////////////////////////////////////////////////////////

#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
#include <fstream>

using namespace std;

#define MIN_YEAR 1949
#define MAX_YEAR 2051
#define BULK_INSERT_SIZE 5000


void	db_connect_cust_care(char *in_login); 
void	db_connect_rating(char *in_login); 
void	db_disconnect_cust_care();
void	db_disconnect_rating();

// -------------reng_date_time---------------------

class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool operator == (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);

// -------------reng_date_time-end---------------------



typedef map<int, string, less<int> > CONNECTION_TO_MOBILE_DEF;



// -------------churn_data----------------------------

class churn_data
{
//private:
public:
	int		package_contract_id;
	
	int		contract_id;		// number(10)		// (2)	BILLENQ_ACCT_NUM
	string	phone_no;			// varchar2(20)		// (1)	BILLENQ_MOB_NUM
	float	credit_limit;		// number(11,2)
	float	outstanding;		// number(11,2)
	int		connection_id;		// number(10)
	int		subscriber_node_id;
	string	is_payment_responsible;
	int		subscriber_profile_id;
	int		image_id;
	string	imsi_no;
	string	conn_type;			// (14)	BILLENQ_CON_TYPE
	string	status_reason_id;

	//--------------------------
	double brought_forward;
	double interim_bill_amount;	// (4)	BILLENQ_CURRENT
	double	last_billamt;		// (7)	BILLENQ_LAST_BILLAMT

	string	last_pay_date;		// (11)	BILLENQ_LAST_PAYDATE - fb_bill_transactions/fb_contract_balances
	reng_date	last_pay_date_rd;
	double	amount;				// (9)	BILLENQ_LAST_PAYAMT	- fb_bill_transactions/fb_contract_balances
	int		tran_no;

	string	last_paymode;		// (10)	BILLENQ_LAST_PAYMODE - fb_bill_receipts

	string	pin_no;				// (3)	BILLENQ_PIN
	double	total_outstanding;	// (interim_bill_amount+brought_forward) // (5) BILLENQ_OUTSTAND
	string	sys_date;			// (6)	BILLENQ_LAST_UPDATE
	string	last_bill_date;		// (8)	BILLENQ_LAST_BILLDATE
	reng_date	last_bill_date_rd;
	string	language_id;		// (12)	BILLENQ_LANG	- cam_subscriber_profile
	
	string	min_payment;		// (13)	BILLENQ_MIN_PAYMENT ????????
	double minimum_payment;

	string	switch_status;


/*
	(1)	BILLENQ_MOB_NUM
	(2)	BILLENQ_ACCT_NUM
  	(3)	BILLENQ_PIN
  	(4)	BILLENQ_CURRENT
  	(5)	BILLENQ_OUTSTAND
  	(6)	BILLENQ_LAST_UPDATE
  	(7)	BILLENQ_LAST_BILLAMT
  	(8)	BILLENQ_LAST_BILLDATE
  	(9)	BILLENQ_LAST_PAYAMT
  	(10)	BILLENQ_LAST_PAYMODE
  	(11)	BILLENQ_LAST_PAYDATE
  	(12)	BILLENQ_LANG
  	(13)	BILLENQ_MIN_PAYMENT
	(14)	BILLENQ_CON_TYPE
*/

public:
	bool	init();
	//bool	process_data(reng_date_time call_time);

};

// -------------churn_data-end----------------------------

// -------------churn----------------------------

class billenq
{
public:
	string	row_id;
	string	billenq_mob_num;
	string	billenq_acct_num;
	string	billenq_pin;
	string	billenq_current;
	string	billenq_outstand;
	string	billenq_last_update;
	string	billenq_last_billamt;
	string	billenq_last_billdate;
	string	billenq_last_payamt;
	string	billenq_last_paymode;
	string	billenq_last_paydate;
	string	billenq_lang;
	string	billenq_min_payment;
	string	billenq_con_type;

	bool init()
	{
		row_id					= "";
		billenq_mob_num			= "";
		billenq_acct_num		= "";
		billenq_pin				= "";
		billenq_current			= "";
		billenq_outstand		= "";
		billenq_last_update		= "";
		billenq_last_billamt	= "";
		billenq_last_billdate	= "";
		billenq_last_payamt		= "";
		billenq_last_paymode	= "";
		billenq_last_paydate	= "";
		billenq_lang			= "";
		billenq_min_payment		= "";
		billenq_con_type		= "";
		return true;
	};
};

typedef map<string , billenq, less<string> > BILLENQ_DEF;		// key - billenq_mob_num

class hlr_ccbs_mismatch
{
public:
	string	imsi;
	string	msisdn;
	int		reason_id;

	bool init()
	{
		imsi		= "";
		msisdn		= "";
		reason_id	= 999;

		return true;
	};
};

typedef multimap<string , hlr_ccbs_mismatch, less<string> > MISMATCH_DEF;		// key - imsi


class prov_switch_image
{
public:
	int		image_id;
	string	imsi_no;
	string	conn_type;
	string	status_reason_id;

	bool	init() 
	{
		image_id		=0; 
		imsi_no			=""; 
		conn_type		=""; 
		status_reason_id="";
		return true;
	};
};

typedef map<int , prov_switch_image, less<int> > PROV_SWITCH_IMAGE_DEF;	// image_id of prov_switch_image
																	// is the key

class cam_contract
{
public:
	int		contract_id;							// number(10) - NN
	int		subscriber_node_id;						// number(10) - NN
	string	finance_broker_id;						// varchar2(20)
	string	is_payment_responsible;					// varchar2(1)
	string	web_bill;								// varchar2(1)
	string	bill_format_code;						// varchar2(10)
	int		bill_dispatch_type_id;					// number
	string	bill_run_code;							// varchar2(10)
	int		address_id;								// number(10)
	string	is_charity;								// varchar2(1)
	string	customer_category;						// varchar2(5)
	string	credit_type;							// varchar2(5) - NN
	float	credit_limit;							// number(11,2)
	string	remarks;								// varchar2(100)
	string	pending_status;							// varchar2(2)
	string	contract_type;							// varchar2(5) - NN
	string	auto_disconnect_date;					// date
	string	nexus_card_no;							// varchar2(25)
	string	nexus_card_type;						// varchar2(30)
	string	nexus_exp_date;							// date
	string	club_vision_type;						// varchar2(5)
	string	status;									// varchar2(2) - NN
	string	start_date;								// date
	string	end_date;								// date
	string	created_user;							// varchar2(20)
	string	updated_user;							// varchar2(20)

	bool init();
	bool operator == (const cam_contract  &s) const;
};

typedef map<int , cam_contract, less<int> > CONTRACT_DEF;	// key - contract_id

class cam_connection
{
public:
	int		connection_id;					// number(10) - NN
	int		package_contract_id;			// number(10) - NN
	int		package_service_id;				// number(10) 
	string	service_start_date;				// date
	string	rental_activation_date;			// date
	float	rental;							// number(14,2)
	string	status;							// varchar2(2) - NN
	string	status_reason_id;				// varchar2(5)
	string	pending_status;					// varchar2(2)
	int		image_id;						// number(10)
	string	remarks;						// varchar2(100)
	string	used_for_provisioning;			// varchar2(1)
	string	is_used_for_rating;				// varchar2(1)
	int		format_id;						// number(10)
	string	auto_disconnect_date;			// date
	string	start_date;						// date
	string	end_date;						// date
	string	created_user;					// varchar2(20)
	string	updated_user;					// varchar2(20)
 
	bool init();
	bool operator == (const cam_connection  &s) const;

};

typedef map<int , cam_connection, less<int> > CONNECTION_DEF;	// key - connection_id

class dyn_1_connection
{
public:
	int		connection_id;					// number(10) - NN
	int		service_id;						// number(3)
	int		format_id;						// number(10)
	string	status;							// varchar2(2) 
	string	sim;							// varchar2(16) - NN
	string	imsi;							// varchar2(20)
	string	imei;							// varchar2(15)
	string	mobile_no;						// varchar2(20)
	string	pre_post;						// varchar2(10)
	string	updated_user;					// varchar2(15)
 
	bool init();
	bool operator == (const dyn_1_connection  &s) const;

};

typedef map<int , dyn_1_connection, less<int> > DYN_1_CONNECTION_DEF;	// key - connection_id

class cam_subscriber_node
{
public:
	int		subscriber_node_id;				// number(10) - NN
	int		subscriber_profile_id;			// number(10) - NN
	int		parent_node_id;					// number(10) 
	int		bill_despatch_type_id;			// number(10)
	int		address_id;						// number(10)

	string	finance_broker_id;				// varchar2(20)
	string	remarks;						// varchar2(100)
	string	description;					// varchar2(100)
	string	is_payment_responsible;			// varchar2(1)
	string	web_bill;						// varchar2(1)
	string	bill_format_code;				// varchar2(10)
	string	bill_run_code;					// varchar2(10)
	string	can_be_parent;					// varchar2(1)
	string	is_charity;						// varchar2(1)
	string	nexus_card_number;				// varchar2(25)
	string	nexus_card_type;				// varchar2(30)
	string	nexus_exp_date;					// date

	string	status;							// varchar2(2) - NN
	string	start_date;						// date
	string	end_date;						// date
	string	created_user;					// varchar2(20)
	string	updated_user;					// varchar2(20)
 
	bool init();
	bool operator == (const cam_subscriber_node  &s) const;

};

typedef map<int , cam_subscriber_node, less<int> > CAM_SUBSCRIBER_NODE_DEF;	// key - subscriber_node_id


class cam_contract_package
{
public:
	int		contract_package_id;					// number(10) - NN
	int		contract_id;							// number(10)
	string	package_id;								// varchar2(15)
	string	status;									// varchar2(2) - NN
	string	pending_status;							// varchar2(2)
	string	is_supplementary;						// varchar2(1)
	string	is_original_assignment;					// varchar2(1)
	string	agent_code;								// varchar2(5) - NN
	string	branch_code;							// varchar2(5) - NN
	string	phone_model;							// varchar2(20)
	string	purchase_type;							// varchar2(5)
	string	auto_disconnect_date;					// date
	string	original_package_start_date;			// date
	string	start_date;								// date
	string	end_date;								// date
	string	created_user;							// varchar2(20)
	string	updated_user;							// varchar2(20)

	bool init();
	bool operator == (const cam_contract_package  &s) const;
};

typedef map<int , cam_contract_package, less<int> > CAM_CONTRACT_PACKAGE_DEF;	// key - contract_package_id


typedef map<int , churn_data, less<int> > CHURN_DEF;	// image_id of prov_switch_image
															// is the key




typedef map<int , cam_subscriber_node, less<int> > SUBSCRIBER_DEF;	// key - subscriber_node_id

typedef map<int, string, less<int> > CONNECTION_TO_MOBILE_DEF;





class cam_subscriber_profile
{
public:
	string	title;					// varchar2(10)
	string	name1;					// varchar2(100)
	string	name2;					// varchar2(100)
	string	identification_number;	// varchar2(20)
	string	communication_language_id;	// varchar2(5)

	bool init();
};

typedef map<int , cam_subscriber_profile, less<int> > PROFILE_DEF;	// key - subscriber_profile_id

class bill_i_pr_master
{
public:
	double brought_fwd;
	double interim_bill_amount;

	bool init()
	{
		brought_fwd	= 0.0;
		interim_bill_amount	= 0.0;
		return true;
	};
};

typedef map<int , bill_i_pr_master, less<int> > BILL_I_PR_MASTER_DEF;	// key - node_id
																		// node_type "C" only (see loadup)

class bill_i_nonpr_contract_master
{
public:
	double brought_forward_outstanding;
	double interim_bill_amount;

	bool init()
	{
		brought_forward_outstanding	= 0.0;
		interim_bill_amount	= 0.0;
		return true;
	};
};

typedef map<int , bill_i_nonpr_contract_master, less<int> > BILL_I_NONPR_CONTRACT_MASTER_DEF;	// key - node_id

typedef map<int , double, less<int> > BILL_BILL_MASTER_SUMMARY_DEF;	// key - node_id
																	// value - amount

typedef map<int , double, less<int> > BILL_BILL_STATEMENT_SUMMARY_DEF;	// key - node_id
																	// value - amount

class fb_bill_transactions
{
public:
	string	tran_date;
	reng_date_time	tran_date_rdt;
	double	amount;
	int		tran_no;

	bool init()
	{
		tran_date	= "";
		tran_date_rdt.date.init();
		tran_date_rdt.time.init();

		amount		= 0.0;
		tran_no		= 0;
		return true;
	};
};

typedef map<int , fb_bill_transactions, less<int> > FB_BILL_TRANSACTIONS_DEF;	// key - node_id

class fb_contract_balances
{
public:
	string	tran_date;
	reng_date_time	tran_date_rdt;
	double	tran_amount;
	double	contract_balance;
	int		tran_no;

	bool init()
	{
		tran_date	= "";
		tran_date_rdt.date.init();
		tran_date_rdt.time.init();
		tran_amount	= 0.0;
		contract_balance	= 0.0;
		tran_no		= 0;
		return true;
	};
};

typedef map<int , fb_contract_balances, less<int> > FB_CONTRACT_BALANCES_DEF;	// key - contract_id

typedef map<int , string, less<int> > FB_BILL_RECEIPTS_DEF;	// key - receipt_tran_no
															// value - payment_mode

//New maps for RA

typedef map<int , string, less<int> > PSI_DEF;	// key - image_id
												// value - imsi_no
												// prov_switch_image

typedef multimap<int , int, less<int> > CC_DEF;	// key - image_id
											// value - connection_id
											// cam_connection


typedef map<int , int, less<int> > DOC_DEF;	// key - connection_id
											// value - service_id
											// dyn_1_connection

/*
class ccbs_profile
{
public:
	string	imsi;
	bool	hlr_profile_found;
	int		image_id;
	//int		connection_id;
	int		services[100];
	
	bool init()
	{
		imsi				= "";
		hlr_profile_found	= false;
		image_id			= 0;
		//connection_id	= 0;

		for (int k=0; k<100; k++)
		{
			services[k] = 0;
		}

		return true;
	};
};
*/

class ccbs_profile
{
public:
	string	imsi;
	bool	hlr_profile_found;
	
	bool init()
	{
		imsi				= "";
		hlr_profile_found	= false;
		
		return true;
	};
};


typedef map<string , ccbs_profile, less<string> > CCBS_PROFILE_DEF;	// key - imsi

/*
class hlr_profile
{
public:
	string	imsi;
	string	sub_category;

	int		bs[100];	// TEL,SMSMT,SMSMO,GPRS
						// 0	1		2	3
	int		ss[100];
	int		bsg[100];
	
	bool init()
	{
		imsi			= "";
		sub_category	= "";
		
		for (int j=0; j<100; j++)
		{
			bs[j] = 999;
		}

		for (int k=0; k<100; k++)
		{
			ss[k] = 999;
		}

		for (int l=0; l<100; l++)
		{
			bsg[l] = 999;
		}

		return true;
	};
};
*/

class hlr_profile
{
public:
	string	imsi;
	string	msisdn;
	
	bool init()
	{
		imsi			= "";
		msisdn			= "";

		return true;
	};
};


typedef map<string , hlr_profile, less<string> > HLR_PROFILE_DEF;	// key - imsi


class churn
{
public:
	char*	check_date;
	//string	sys_date;
	string	last_bill_date;
	bool	transition;

	reng_date	start_date;
	reng_date	end_date;

	//string	sys_date;

	//---------------------------

	PSI_DEF					psi_map;	
	CC_DEF					cc_multimap;
	DOC_DEF					doc_map;	
	CCBS_PROFILE_DEF		ccbs_profile_map;

	HLR_PROFILE_DEF			hlr_profile_map;

	MISMATCH_DEF			mismatch_map;

	//----------------------------


	BILLENQ_DEF					billenq_map;		// entries not in db (inserted to db)
	BILLENQ_DEF					billenq_db_map;		// entries already in db (updated db)

	PROV_SWITCH_IMAGE_DEF		image_map;
	CONTRACT_DEF				cam_contract_map;
	CONNECTION_DEF				cam_connection_map;
	CAM_SUBSCRIBER_NODE_DEF		cam_subscriber_node_map;
	CAM_CONTRACT_PACKAGE_DEF	cam_contract_package_map;
	DYN_1_CONNECTION_DEF		dyn_1_connection_map;
	BILL_I_PR_MASTER_DEF		bill_i_pr_master_map;
	BILL_I_NONPR_CONTRACT_MASTER_DEF	bill_i_nonpr_contract_master_map;
	BILL_BILL_MASTER_SUMMARY_DEF	bill_bill_master_summary_map;
	BILL_BILL_STATEMENT_SUMMARY_DEF	bill_bill_statement_summary_map;

	FB_BILL_TRANSACTIONS_DEF	fb_bill_transactions_bill_map;
	FB_BILL_TRANSACTIONS_DEF	fb_bill_transactions_pay_map;

	FB_CONTRACT_BALANCES_DEF	fb_contract_balances_bill_map;
	FB_CONTRACT_BALANCES_DEF	fb_contract_balances_pay_map;

	FB_BILL_RECEIPTS_DEF		fb_bill_receipts_map;

	CHURN_DEF				churn_map;
	PROFILE_DEF				cam_subscriber_profile_map;


	churn_data	*current;
	CHURN_DEF::iterator i_current;
	//CHURN_DEF::iterator i_db_insert;

	//BILLENQ_DEF::iterator i_db_insert;
	MISMATCH_DEF::iterator i_db_insert;

	CONNECTION_TO_MOBILE_DEF	connection_to_mobile_map;
	
	int	bulk_insert_size;
	int	remainder_insert_size;
	int insert_iterations;

	char*		sys_date;		// hlr_ccbs

public:
	FILE *log_to_file;
	
	churn(const char* LogFileName)
	{
		current=NULL;

		bulk_insert_size		= BULK_INSERT_SIZE;
		remainder_insert_size	= 0;
		insert_iterations		= 0;

		sys_date		= new char[128];		// hlr_ccbs

		check_date		= new char[128];		// hlr_ccbs

		/*
		if ((log_to_file = fopen(LogFileName, "w"))==NULL)
		{
			cout << "Can't create log file " << LogFileName << endl;
			exit (0);
		}
		*/
		
	}

	~churn()
	{
		//cout << "Distructor called" << endl;
		
		/*
		if( fclose( log_to_file ) )
			cout <<  "The log file was not closed\n" << endl;
			*/
			
	}

	void set_dates(char* start_date, char* end_date);

	bool set_current(int image_id);
	string	get_mobile_no(int connection_id);
	bool insert_to_database();
	void db_insert_churn_data();
	void db_insert_churn_data_remainder();

	void	get_db_sysdate();

	void	db_get_sysdate();		// for hlr_ccbs
	bool	hlr_ccbs_compare();		// for hlr_ccbs
	float	db_first_minus_second(char* first_date, char* second_date);	// for hlr_ccbs

	void	get_db_last_bill_date();

	void	db_read_billenq_tab();

	void	db_read_prov_switch_image();
	void	db_read_cam_contract();
	void	db_read_cam_connection();
	void	db_read_dyn_1_connection();
	void	db_read_cam_subscriber_node();
	void	db_read_cam_contract_package();
	void	db_read_cam_subscriber_profile();

	void	db_read_bill_i_pr_master();
	void	db_read_bill_i_nonpr_contract_master();

	void	db_read_bill_bill_master_summary();
	void	db_read_bill_bill_statement_summary();

	void	db_read_fb_bill_transactions();
	void	db_read_fb_contract_balances();

	void	db_read_fb_bill_receipts();
	void	db_truncate_billenq_tab();

	bool	process();
	void	transition_error(char *msg);
	char*	decode_payment_mode(string pay_mode);
	double	get_reminder_balance(int contract_id);
	double	get_interim_balance(int contract_id);
	void	db_update_billenq_tab();
};

// -------------rejected_call-end----------------------------

// ---------------- hlr_read

class hlr_read
{
//private:
public:
	int				buffer_size;		// size of buffer in bytes
	

public:
	int				bytes_read;
	char			*data_buffer;		// to hold hlr profile
	unsigned char	*buffer;			// start of cdr buffer 
	unsigned char	*current;			// read pointer {buffer <= current <= (buffer+length)}
	unsigned char	*data_end;			// the end of the requested data sequence { buffer <= data_end <= (buffer+length)}
										// used for walking current pointer only
	unsigned char	*end_of_buffer;		// end of allocated space for buffer. used for verifcation only
	int				hlr_profile_start;
	
public:

	hlr_read(int size);
	bool	file_read(FILE* fp, char* path_file_name);
	int		extract_string_inbetween(char *extracted_value, unsigned char *buf, const char* begin_pattern, const char* end_pattern, int search_start, int search_length);
	bool	extract_string_right(char *extracted_value, unsigned char *buf, const char* token);
	bool	extract_string_left(char *extracted_value, unsigned char *buf, const char* token);
	bool	decode_hlr_dump();
	//bool	hlr_ccbs_compare();
};


class string_match {
    const char * target;	// string we are looking for
    int index;			// index into target; how much matched so far
    int * retarget;		// what to set match to when mismatch found

 public:
    string_match(const char *, int = -1);
	// set up to start matching target string given in first arg
	// second arg is length of string, default whole string up to null

    //~string_match() { delete target; delete retarget; }	// not used - hence commented

    void reset() { index = 0; }
    //int match(char c);		// adds c to match; returns nz if all matched
    int match(const unsigned char c);		// adds c to match; returns nz if all matched

};


