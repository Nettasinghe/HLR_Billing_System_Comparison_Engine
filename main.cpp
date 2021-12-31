/////////////////////////////////////////////////////////////////////////
//
// HLR and Billing System Comparison Engine for Telco Revenue Assurance –
// ---------------------------------------------------------------------
//
// Home Location Register(HLR) is a database that contains data regarding
// authorized subscribers using a global system for mobile communication
// (GSM) core network. If there is a discrepancy of subscriber profiles and
// eligible services between HLRand Billing System of a Telco, there exists
// a possibility of a revenue leakage. The functionality of this software 
// module is to decodeand extract the proprietary format data from Alcatel 
// HLRs (there are 4 of them in Dialog Axiata PLC core-network) and fetch 
// customer service data from the database of the Billing System to compare
// those in memory and write back the discrepancies to a database.
//
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//
// main.cpp
// main program for HLR-CCBS Comparison Engine for Telco Revenue Assurance
// main method contains here
// developer - Chandika Nettasinghe
// code start - 2003-August
//
///////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <time.h>

#include "data_containers.h"

	churn		*gsm_churn;
	char		*LogFileName;
	
#define BUFFER_SIZE	1024*1024*350		// 350 MB buffer for hlr file

	hlr_read	*h_read;
	FILE		*fp;

	//ofstream f_log("./logs/HLR_CCBS_Comparison_Engine.log", ios::out | ios::app);
	

int main(int argc,char *argv[])
{
	char *ver = "1.0.0";

	cout<<"HLR-CCBS Comparison Engine for RA  "<<ver<<endl
	<<"Build Time "<<__DATE__<<" at "<<__TIME__<<endl
	<<"Dialog Telekom"<<endl
	<<"Colombo, Sri Lanka"<<endl<<endl;

	// Log file
	char zTime[30];
	/*------- get time -------*/
	time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	LogFileName = new char[100];
	//sprintf(LogFileName, "./hlr_ccbs_mismatch_%s.csv",zTime);
	// Log file -end

	//+++++++++++++++++++++++++++

	gsm_churn				= new churn( (const char*)LogFileName);

	h_read = new hlr_read(BUFFER_SIZE);
	cout << "buffer_size = " << h_read->buffer_size / 1024 << " KB" << endl;
	//h_read->file_read(fp, "E:/Work/ESDAT/HLR3_SN_35");

	//h_read->decode_hlr_dump();

	//=============================


	//gsm_churn				= new churn( (const char*)LogFileName);

	FILE *login;
	char cust_care_login[128];
	char first_hlr_dump[128];
	char second_hlr_dump[128];
	char third_hlr_dump[128];
	char fourth_hlr_dump[128];
	//char rating_login[128];

	// get config data
	if( (login  = fopen( "./hlr_ccbs.config", "r" )) == NULL )
	{
		printf( "The file 'hlr_ccbs.config' was not opened\n" );
		exit(0);
	}

	//fscanf( login, "%s", cust_care_login );
	strcpy(cust_care_login, "ccbs2/10sthope@cam");
	fscanf( login, "%s", first_hlr_dump );
	fscanf( login, "%s", second_hlr_dump );
	fscanf( login, "%s", third_hlr_dump );
	fscanf( login, "%s", fourth_hlr_dump );
	fscanf( login, "%s", gsm_churn->check_date );
	//fscanf( login, "%s", rating_login );


	if( fclose( login ) )
		printf( "The file 'hlr_ccbs.config' was not closed\n" );

	sprintf(LogFileName, "./hlr_ccbs_mismatch_%s%s.csv",zTime, gsm_churn->check_date );

	cout << "Check date = " << gsm_churn->check_date << endl << endl;

	cout << "Reading first HLR dump" << endl << endl;
	h_read->file_read(fp, first_hlr_dump);
	h_read->decode_hlr_dump();
	cout << "hlr_profile_map.size() = " << gsm_churn->hlr_profile_map.size() << endl;

	cout << "Reading second HLR dump" << endl << endl;
	h_read->file_read(fp, second_hlr_dump);
	h_read->decode_hlr_dump();
	cout << "hlr_profile_map.size() = " << gsm_churn->hlr_profile_map.size() << endl;

	cout << "Reading third HLR dump" << endl << endl;
	h_read->file_read(fp, third_hlr_dump);
	h_read->decode_hlr_dump();
	cout << "hlr_profile_map.size() = " << gsm_churn->hlr_profile_map.size() << endl;

	cout << "Reading fourth HLR dump" << endl << endl;
	h_read->file_read(fp, fourth_hlr_dump);
	h_read->decode_hlr_dump();
	cout << "hlr_profile_map.size() = " << gsm_churn->hlr_profile_map.size() << endl;
	


	db_connect_cust_care(cust_care_login);

	gsm_churn->db_read_dyn_1_connection();
	cout << "ccbs_profile_map.size() = " << gsm_churn->ccbs_profile_map.size() << endl;
	
	//gsm_churn->db_read_cam_connection();
	//cout << "cc_multimap.size() = " << gsm_churn->cc_multimap.size() << endl;
	
	//gsm_churn->db_read_prov_switch_image();
	//cout << "ccbs_profile_map.size() = " << gsm_churn->ccbs_profile_map.size() << endl;
	

	gsm_churn->hlr_ccbs_compare();

	gsm_churn->db_get_sysdate();
	gsm_churn->insert_to_database();

	 

	delete gsm_churn;

	return 0;
}


