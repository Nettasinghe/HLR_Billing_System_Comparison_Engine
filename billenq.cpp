

////////////////////////////////////////////////////////////////////////////////////////
//
// billenq.cpp
// implementation for classes for HLR-CCBS Comparison Engine for Telco Revenue Assurance 
// developer - Chandika Nettasinghe
// code start - 2003-August
//
////////////////////////////////////////////////////////////////////////////////////////


#include "data_containers.h"

extern	char		*LogFileName;

// -------------churn----------------------------

bool cam_contract::init()
{
	contract_id	= 0;							
	subscriber_node_id = 0;						
	finance_broker_id = "";						
	is_payment_responsible = "";	
	web_bill = "";									
	bill_format_code = "";						
	bill_dispatch_type_id = 0;					
	bill_run_code = "";							
	address_id = 0;								
	is_charity = "";								
	customer_category = "";						
	credit_type = "";							
	credit_limit = 0;							
	remarks = "";								
	pending_status = "";							
	contract_type = "";							
	auto_disconnect_date = "";					
	nexus_card_no = "";							
	nexus_card_type = "";						
	nexus_exp_date = "";							
	club_vision_type = "";					
	status = "";									
	start_date = "";							
	end_date = "";								
	created_user = "";							
	updated_user = "";											

	return true;
}

bool cam_connection::init()
{
	connection_id = 0;					
	package_contract_id = 0;
	package_service_id = 0;
	service_start_date = "";		
	rental_activation_date = "";
	rental = 0.0;
	status = "";
	status_reason_id = "";
	pending_status = "";
	image_id = 0;
	remarks = "";
	used_for_provisioning = "";
	is_used_for_rating = "";
	format_id = 0;
	auto_disconnect_date = "";
	start_date = "";
	end_date = "";
	created_user = "";
	updated_user = "";				

	return true;
}

bool dyn_1_connection::init()
{
	connection_id = 0;					
	service_id = 0;						
	format_id = 0;						
	status = "";							
	sim = "";							
	imsi = "";							
	imei = "";							
	mobile_no = "";						
	pre_post = "";						
	updated_user = "";				

	return true;
}

bool cam_subscriber_node::init()
{
	subscriber_node_id = 0 ;				
	subscriber_profile_id = 0 ;			
	parent_node_id = 0 ;					
	bill_despatch_type_id = 0 ;			
	address_id = 0 ;						

	finance_broker_id = "" ;				
	remarks = "" ;						
	description = "" ;					
	is_payment_responsible = "" ;		
	web_bill = "" ;						
	bill_format_code = "" ;				
	bill_run_code = "" ;					
	can_be_parent = "" ;					
	is_charity = "" ;						
	nexus_card_number = "" ;				
	nexus_card_type = "" ;				
	nexus_exp_date = "" ;			
	status = "" ;						
	start_date = "" ;					
	end_date = "" ;					
	created_user = "" ;					
	updated_user = "" ;			

	return true;
}

bool cam_contract_package::init()
{
	contract_package_id = 0;					
	contract_id = 0;							
	package_id = "" ;								
	status = "" ;									
	pending_status = "" ;							
	is_supplementary = "" ;						
	is_original_assignment = "" ;					
	agent_code = "" ;								
	branch_code = "" ;							
	phone_model = "" ;							
	purchase_type = "" ;							
	auto_disconnect_date = "" ;					
	original_package_start_date = "" ;			
	start_date = "" ;								
	end_date = "" ;								
	created_user = "" ;							
	updated_user = "" ;											

	return true;
}



// sets the current pointer to correct churn_data
bool churn::set_current(int image_id)
{
	i_current = churn_map.find(image_id);
	if(i_current !=churn_map.end())
	{
		current=&(*i_current).second;
		return true;
	}
	return false;
}

void churn::set_dates(char* p_start_date, char* p_end_date)
{
	start_date.set_date(p_start_date);
	end_date.set_date(p_end_date);
}

string	churn::get_mobile_no(int connection_id)
{
	CONNECTION_TO_MOBILE_DEF::iterator i=connection_to_mobile_map.find(connection_id);

	if (i==connection_to_mobile_map.end())
		return "UNDEF";
	else
		return (*i).second;
}


bool churn::insert_to_database()
{
	cout << endl;
	cout << "rows to insert = " << mismatch_map.size() << endl;

	div_t div_result;

	div_result = div( mismatch_map.size(), bulk_insert_size );
   
	remainder_insert_size	= div_result.rem;
	insert_iterations		= div_result.quot;

	i_db_insert = mismatch_map.begin();

	if ( (insert_iterations > 0) && (i_db_insert != mismatch_map.end()) )
	{
		db_insert_churn_data();
		db_insert_churn_data_remainder();
	}
	else if ( (i_db_insert != mismatch_map.end()) &&  (remainder_insert_size > 0) )
	{
		db_insert_churn_data_remainder();
	}

	if (i_db_insert == mismatch_map.end())
	{
		cout << "Iterotor @ map end after database insertion" << endl;
		return true;
	}
	else
	{
		cout << "ERROR - Iterotor not @ map end after database insertion" << endl;
		return false;
	}
}


// -------------churn-end----------------------------

// -------------churn_data--------------------------------

/*
bool reject_data::process_data(reng_date_time call_time)
{
	count++;

	if (max_call_time < call_time)
		max_call_time = call_time;

	if (call_time < min_call_time)
		min_call_time = call_time;

	return true;
}
*/

bool churn_data::init()
{
	contract_id		=0;
	connection_id	=0;
	phone_no		="";
	credit_limit	=0;
	outstanding		=0;
	subscriber_node_id	=0;
	is_payment_responsible = "";
	subscriber_profile_id=0;
	amount			= 0.0;
	last_billamt	= 0.0;
	brought_forward = 0.0;
	interim_bill_amount = 0.0;
	minimum_payment = 0.0;

	return true;
}


// -------------churn_data-end------------------------------

bool cam_subscriber_profile::init()
{
	title					= "";				
	name1					= "";				
	name2					= "";	
	identification_number	= "";
	communication_language_id="";
	
	return true;
}



bool churn::process()
{
	cout << "processing " << endl;

	churn_data	*data;
	billenq		*billenq_data;
	billenq		new_billenq_data;
	char buf[100];

	for (CHURN_DEF::iterator i = churn_map.begin(); i != churn_map.end(); i++)
	{
		data = &(*i).second;

		CAM_CONTRACT_PACKAGE_DEF::iterator it = cam_contract_package_map.find((*i).second.package_contract_id);
		if ( it != cam_contract_package_map.end() )
		{
			data->contract_id	= (*it).second.contract_id;
		}

		CONTRACT_DEF::iterator ite = cam_contract_map.find((*i).second.contract_id);		
		if ( ite != cam_contract_map.end() )
		{
			data->subscriber_node_id	= (*ite).second.subscriber_node_id;
			data->credit_limit			= (*ite).second.credit_limit;
			data->is_payment_responsible= (*ite).second.is_payment_responsible;
		}

		data->phone_no = get_mobile_no((*i).second.connection_id);

		SUBSCRIBER_DEF::iterator iter = cam_subscriber_node_map.find((*i).second.subscriber_node_id);
		if ( iter != cam_subscriber_node_map.end() )
		{
			data->subscriber_profile_id	= (*iter).second.subscriber_profile_id;		
		}

		
		PROFILE_DEF::iterator k = cam_subscriber_profile_map.find((*i).second.subscriber_profile_id);
		if ( k != cam_subscriber_profile_map.end() )
		{
			data->language_id	= (*k).second.communication_language_id;		
		}

		BILL_I_PR_MASTER_DEF::iterator i_pr = bill_i_pr_master_map.find((*i).second.contract_id);
		if ( i_pr != bill_i_pr_master_map.end() )
		{
			data->brought_forward		= (*i_pr).second.brought_fwd;		
			data->interim_bill_amount	= (*i_pr).second.interim_bill_amount;
		}

		BILL_I_NONPR_CONTRACT_MASTER_DEF::iterator i_npr = bill_i_nonpr_contract_master_map.find((*i).second.contract_id);
		if ( i_npr != bill_i_nonpr_contract_master_map.end() )
		{
			data->brought_forward		= (*i_npr).second.brought_forward_outstanding;		
			data->interim_bill_amount	= (*i_npr).second.interim_bill_amount;
		}

		if (transition)
		{
			data->last_bill_date	= last_bill_date;
			data->last_bill_date_rd.set_date((char *)data->last_bill_date.c_str());

			BILL_BILL_MASTER_SUMMARY_DEF::iterator i_master_summary = bill_bill_master_summary_map.find((*i).second.contract_id);
			if ( i_master_summary != bill_bill_master_summary_map.end() )
			{
				data->last_billamt		= (*i_master_summary).second;
			}

			BILL_BILL_STATEMENT_SUMMARY_DEF::iterator i_statement_summary = bill_bill_statement_summary_map.find((*i).second.contract_id);
			if ( i_statement_summary != bill_bill_statement_summary_map.end() )
			{
				data->last_billamt		= (*i_statement_summary).second;		
			}
		}
		else
		{
			FB_BILL_TRANSACTIONS_DEF::iterator i_bill_transactions_b = fb_bill_transactions_bill_map.find((*i).second.contract_id);
			if ( i_bill_transactions_b != fb_bill_transactions_bill_map.end() )
			{
					data->last_billamt		= (*i_bill_transactions_b).second.amount;
					data->last_bill_date	= (*i_bill_transactions_b).second.tran_date;
					data->last_bill_date_rd.set_date((char *)data->last_bill_date.c_str());
			}

			FB_CONTRACT_BALANCES_DEF::iterator i_contract_balances_b = fb_contract_balances_bill_map.find((*i).second.contract_id);
			if ( i_contract_balances_b != fb_contract_balances_bill_map.end() )
			{
					data->last_billamt		= (*i_contract_balances_b).second.tran_amount;
					data->last_bill_date	= (*i_contract_balances_b).second.tran_date;
					data->last_bill_date_rd.set_date((char *)data->last_bill_date.c_str());
			}
		}

		FB_BILL_TRANSACTIONS_DEF::iterator i_bill_transactions_p = fb_bill_transactions_pay_map.find((*i).second.contract_id);
		if ( i_bill_transactions_p != fb_bill_transactions_pay_map.end() )
		{
			data->amount			= (-1)*(*i_bill_transactions_p).second.amount;
			data->last_pay_date		= (*i_bill_transactions_p).second.tran_date;
			data->last_pay_date_rd.set_date((char *)data->last_pay_date.c_str());
			data->tran_no			= (*i_bill_transactions_p).second.tran_no;
		}

		FB_CONTRACT_BALANCES_DEF::iterator i_contract_balances_p = fb_contract_balances_pay_map.find((*i).second.contract_id);
		if ( i_contract_balances_p != fb_contract_balances_pay_map.end() )
		{
			data->amount			= (-1)*(*i_contract_balances_p).second.tran_amount;
			data->last_pay_date		= (*i_contract_balances_p).second.tran_date;
			data->last_pay_date_rd.set_date((char *)data->last_pay_date.c_str());
			data->tran_no			= (*i_contract_balances_p).second.tran_no;
		}

		FB_BILL_RECEIPTS_DEF::iterator i_bill_receipts = fb_bill_receipts_map.find((*i).second.tran_no);
		if ( i_bill_receipts != fb_bill_receipts_map.end() )
		{
			data->last_paymode	= (*i_bill_receipts).second;
		}

		if ( ( data->switch_status == "B" ) || ( data->switch_status == "T" ) ) 
		{
			if ( ( data->status_reason_id == "BB" ) || ( data->status_reason_id == "BT" ) || ( data->status_reason_id == "NP" ) ) 
			{
				data->minimum_payment = get_reminder_balance(data->contract_id);
			}
			else if ( data->status_reason_id == "CLE" )
			{
				data->minimum_payment = get_interim_balance(data->contract_id);
			}
		}


		BILLENQ_DEF::iterator i_billenq = billenq_db_map.find((*i).second.phone_no);
		if ( i_billenq != billenq_db_map.end() )
		{
			billenq_data = &(*i_billenq).second;

			buf[0] = '\0';
			memset(buf,0,100);
			sprintf(buf, "%d",data->contract_id);
			billenq_data->billenq_acct_num	= buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%15.02f",data->interim_bill_amount);
			billenq_data->billenq_current = buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			double outstand = data->interim_bill_amount + data->brought_forward;
			sprintf(buf, "%15.02f",outstand);
			billenq_data->billenq_outstand = buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			//strncpy(buf, sys_date.c_str(), 8);
			billenq_data->billenq_last_update = buf;

			if ( (data->last_billamt < 0.001 ) && (data->last_billamt > -0.001 ) ) 
			{
				billenq_data->billenq_last_billamt	= "";
				billenq_data->billenq_last_billdate	= "";
			}
			else
			{
				buf[0] = '\0';
				memset(buf,0,100); 
				sprintf(buf, "%15.02f",data->last_billamt);
				billenq_data->billenq_last_billamt = buf;

				buf[0] = '\0';
				memset(buf,0,100); 
				//sprintf(buf,"%02d/%02d/%04d",data->last_bill_date_rd.day,data->last_bill_date_rd.month,data->last_bill_date_rd.year); 
				sprintf(buf,"%04d%02d%02d",data->last_bill_date_rd.year,data->last_bill_date_rd.month,data->last_bill_date_rd.day); 
				billenq_data->billenq_last_billdate = buf;
			}
			
			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%15.02f",data->minimum_payment);
			billenq_data->billenq_min_payment = buf;

			if ( (data->amount < 0.001 ) && (data->amount > -0.001 ) ) 
			{
				billenq_data->billenq_last_paymode = "";
				billenq_data->billenq_last_paydate = "";
				billenq_data->billenq_last_payamt  = "";
			}
			else
			{
				billenq_data->billenq_last_paymode = decode_payment_mode(data->last_paymode);

				buf[0] = '\0';
				memset(buf,0,100); 
				//sprintf(buf,"%02d/%02d/%04d",data->last_pay_date_rd.day,data->last_pay_date_rd.month,data->last_pay_date_rd.year); 
				sprintf(buf,"%04d%02d%02d",data->last_pay_date_rd.year,data->last_pay_date_rd.month,data->last_pay_date_rd.day); 
				billenq_data->billenq_last_paydate = buf;

				buf[0] = '\0';
				memset(buf,0,100); 
				sprintf(buf, "%15.02f",data->amount);
				billenq_data->billenq_last_payamt = buf;
			}

			billenq_data->billenq_con_type = data->conn_type;
		}
		else
		{
			new_billenq_data.init();

			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%d",data->contract_id);
			new_billenq_data.billenq_acct_num	= buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%15.02f",data->interim_bill_amount);
			new_billenq_data.billenq_current = buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			double outstand = data->interim_bill_amount + data->brought_forward;
			sprintf(buf, "%15.02f",outstand);
			new_billenq_data.billenq_outstand = buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			//strncpy(buf, sys_date.c_str(), 8);
			new_billenq_data.billenq_last_update = buf;

			
			if ( (data->last_billamt < 0.001 ) && (data->last_billamt > -0.001 ) )
			{
				new_billenq_data.billenq_last_billamt	="";
				new_billenq_data.billenq_last_billdate	= "";
			}
			else
			{
				buf[0] = '\0';
				memset(buf,0,100); 
				sprintf(buf, "%15.02f",data->last_billamt);
				new_billenq_data.billenq_last_billamt = buf;

				buf[0] = '\0';
				memset(buf,0,100); 
				//sprintf(buf,"%02d/%02d/%04d",data->last_bill_date_rd.day,data->last_bill_date_rd.month,data->last_bill_date_rd.year); 
				sprintf(buf,"%04d%02d%02d",data->last_bill_date_rd.year,data->last_bill_date_rd.month,data->last_bill_date_rd.day); 
				new_billenq_data.billenq_last_billdate = buf;
			}

			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%15.02f",data->amount);
			new_billenq_data.billenq_last_payamt = buf;

			buf[0] = '\0';
			memset(buf,0,100); 
			sprintf(buf, "%15.02f",data->minimum_payment);
			new_billenq_data.billenq_min_payment = buf;

			if ( (data->amount < 0.001 ) && (data->amount > -0.001 ) ) 
			{
				new_billenq_data.billenq_last_paymode = "";
				new_billenq_data.billenq_last_paydate = "";
				new_billenq_data.billenq_last_payamt  = "";
			}
			else
			{
				new_billenq_data.billenq_last_paymode = decode_payment_mode(data->last_paymode);

				buf[0] = '\0';
				memset(buf,0,100); 
				//sprintf(buf,"%02d/%02d/%04d",data->last_pay_date_rd.day,data->last_pay_date_rd.month,data->last_pay_date_rd.year); 
				sprintf(buf,"%04d%02d%02d",data->last_pay_date_rd.year,data->last_pay_date_rd.month,data->last_pay_date_rd.day); 
				new_billenq_data.billenq_last_paydate = buf;

				buf[0] = '\0';
				memset(buf,0,100); 
				sprintf(buf, "%15.02f",data->amount);
				new_billenq_data.billenq_last_payamt = buf;
			}

			new_billenq_data.billenq_con_type = data->conn_type;

			//-----
			new_billenq_data.billenq_mob_num	= (*i).second.phone_no;
			new_billenq_data.billenq_pin		= "678678";
			new_billenq_data.billenq_lang		= data->language_id;

			billenq_map.insert(BILLENQ_DEF::value_type((*i).second.phone_no, new_billenq_data));
		}
		cout <<".";
	}

	cout << "processing end" << endl;

	return true;
}

void churn::transition_error(char *msg)
{
    cout << endl << msg << endl;
	transition = false;
}

char* churn::decode_payment_mode(string pay_mode)
{
	char *m;

	if ( strncmp(pay_mode.c_str(), "CARD", 4) == 0 )
	{
		m = "CC";
	}
	else if ( strncmp(pay_mode.c_str(), "CASH", 4) == 0 )
	{
		m = "CSH";
	}
	else if ( strncmp(pay_mode.c_str(), "CHEQ", 4) == 0 )
	{
		m = "CHQ";
	}
	else
	{
		m = "DD";
	}

	return m;
}

bool churn::hlr_ccbs_compare()
{
	CCBS_PROFILE_DEF::iterator	i_ccbs;
	HLR_PROFILE_DEF::iterator	i_hlr;
	hlr_ccbs_mismatch			mismatch;

	int hlr_count = 0;

	ofstream f_log(LogFileName, ios::out | ios::app);

	for(i_hlr =hlr_profile_map.begin(); i_hlr!=hlr_profile_map.end(); i_hlr++)
	{
		//cout <<  (*i_hlr).first << "," << (*i_hlr).second.msisdn << endl;

		//hlr_count ++;
		//cout << "hlr_count = " << hlr_count << endl;
		i_ccbs = ccbs_profile_map.find( (*i_hlr).first );

		if ( i_ccbs == ccbs_profile_map.end() )
		{
			mismatch.init();
			mismatch.imsi		= (*i_hlr).first;
			mismatch.msisdn		= (*i_hlr).second.msisdn;
			mismatch.reason_id	= 1;		// No matching profile in CCBS

			//cout << "No matching profile in CCBS for IMSI " << (*i_hlr).first << endl;
			f_log <<  (*i_hlr).first << "," << (*i_hlr).second.msisdn << endl;
		hlr_count ++;

			mismatch_map.insert(MISMATCH_DEF::value_type((*i_hlr).first, mismatch));
		}
		else
		{
			(*i_ccbs).second.hlr_profile_found	= true;
		}
	}

	cout <<  hlr_count << " profiles in HLR without matching CCBS profiles" << endl;

	/*

	for(i_ccbs = ccbs_profile_map.begin(); i_ccbs!=ccbs_profile_map.end(); i_ccbs++)
	{
		i_hlr = hlr_profile_map.find( (*i_ccbs).first );

		if ( i_hlr == hlr_profile_map.end() )
		{
			mismatch.init();
			mismatch.imsi		= (*i_ccbs).first;
			mismatch.reason_id	= 2;		// No matching profile in HLR

			mismatch_map.insert(MISMATCH_DEF::value_type((*i_hlr).first, mismatch));
		}
		else
		{
			//(*i_hlr).second.ccbs_profile_found	= true;
		}
	}
*/

	return true;
}


