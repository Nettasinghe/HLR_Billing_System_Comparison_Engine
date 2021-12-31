
///////////////////////////////////////////////////////////////////////////////////
//
// hlr_ccbs.cpp
// class implementation for HLR-CCBS Comparison Engine for Telco Revenue Assurance
// hlr_read class methods contain here
// developer - Chandika Nettasinghe
// code start - 2003-August
//
///////////////////////////////////////////////////////////////////////////////////

#include "data_containers.h"

extern	churn	*	gsm_churn;



// object lives for lifetime of program
hlr_read::hlr_read(int size)
{
	buffer_size = size;
	buffer = new unsigned char[buffer_size];
	if (!buffer)
	{
		cout<<"ERR: FATAL cant allocate "<<buffer_size/1024<<" KB  for HLR buffer"<<endl;
		//f_log<<"ERR: FATAL cant allocate "<<buffer_size/1024<<" KB  for HLR buffer"<<endl;
		exit(1);
	}

	end_of_buffer = buffer+buffer_size;

	int data_buffer_size = 1024*1024*5;

	data_buffer = new char[data_buffer_size];
	if (!data_buffer)
	{
		cout<<"ERR: FATAL cant allocate "<<data_buffer_size/1024<<" KB  for HLR data buffer"<<endl;
		//f_log<<"ERR: FATAL cant allocate "<<buffer_size/1024<<" KB  for HLR data buffer"<<endl;
		exit(1);
	}

	//init();
}


bool hlr_read::file_read(FILE* fp, char* path_file_name)
{
	cout << "path_file_name = " << path_file_name << endl;
	fp=fopen(path_file_name,"rb");
	if (fp==NULL)
	{
		cout<<"ERR: File "<< path_file_name <<" could not be opened "<<endl;
		exit(1);
	}

	bytes_read = fread(buffer, sizeof(unsigned char), buffer_size, fp);
	cout << "bytes_read : " << bytes_read << " bytes" << endl;
	buffer[bytes_read] = '\0';

	current = buffer;

	return true;

}

int hlr_read::extract_string_inbetween(char *extracted_value, unsigned char *buf, const char* begin_pattern, const char* end_pattern, int search_start, int search_length)
{
	extracted_value[0] = '\0';

	string_match s_target(begin_pattern);

	int value_start_pos = 0;
	int value_end_pos = 0;

	bool start_pos_found = false;
	bool end_pos_found = false;


	int i=0;
	while ( (buf[i+search_start] != '\0') && (i < search_length) )
	{
		if (s_target.match(buf[i+search_start]))
		{
			value_start_pos = i+search_start+1;
			// + 1 is to get rid of last character of start signature
			//cout << value_start_pos << endl;
			start_pos_found = true;
			break;
		}
		i++;
	}

	if (!start_pos_found)
	{
		//cout << begin_pattern << " start sig not found" << endl;
		return 0;
	}

	string_match e_target(end_pattern);

	i=0;
	while ( (buf[i+value_start_pos] != '\0') && (i < search_length-value_start_pos) )
	{
		if (e_target.match(buf[i+value_start_pos]))
		{
			value_end_pos = i+value_start_pos;
			//cout << value_end_pos << endl;
			end_pos_found = true;
			break;
		}
		i++;
	}

	if (!end_pos_found)
	{
		//cout << end_pattern << " end sig not found" << endl;
		return 0;
	}

	

	int value_size = value_end_pos-value_start_pos-strlen(end_pattern)+1;
	//cout << "value_size = " << value_size << endl;
	//char extracted_buf[10000];
	
	for (int k = 0; k<value_size;k++ )
	{
		//cout << buf[value_start_pos+k] ;
		extracted_value[k] = buf[value_start_pos+k];
	}

	extracted_value[value_size] = '\0';

	//extracted_value = extracted_buf;

	//cout << extracted_value << endl;

	return value_end_pos;

}

bool hlr_read::extract_string_right(char *extracted_value, unsigned char *buf, const char* token)
{
	extracted_value[0] = '\0';

	string_match target(token);

	int value_start_pos = 0;

	bool start_pos_found = false;

	int i=0;
	while (buf[i] != '\0') 
	{
		if (target.match(buf[i]))
		{
			value_start_pos = i+1;
			// + 1 is to get rid of last character of start signature
			//cout << value_start_pos << endl;
			start_pos_found = true;
			break;
		}
		i++;
	}

	if (!start_pos_found)
	{
		//cout << "token not found" << endl;
		return false;
	}

	int k=0;
	for (; buf[k+value_start_pos] != '\0';k++ )
	{
		//cout << buf[value_start_pos+k] ;
		extracted_value[k] = buf[value_start_pos+k];
	}

	extracted_value[k] = '\0';

	//extracted_value = extracted_buf;

	//cout << extracted_value << endl;

	return true;

}


bool hlr_read::extract_string_left(char *extracted_value, unsigned char *buf, const char* token)
{
	extracted_value[0] = '\0';

	string_match target(token);

	int value_start_pos = 0;

	bool start_pos_found = false;

	int i=0;
	while (buf[i] != '\0') 
	{
		if (target.match(buf[i]))
		{
			value_start_pos = i+1;
			// + 1 is to get rid of last character of start signature
			//cout << value_start_pos << endl;
			start_pos_found = true;
			break;
		}
		i++;
	}

	if (!start_pos_found)
	{
		//cout << "token not found" << endl;
		return false;
	}

	int size = value_start_pos- strlen(token);

	if ( size <= 0 )
		return false;

	int k=0;
	for (; k < size ;k++ )
	{
		//cout << buf[value_start_pos+k] ;
		extracted_value[k] = buf[k];
	}

	extracted_value[size] = '\0';

	//extracted_value = extracted_buf;

	//cout << extracted_value << endl;

	return true;

}


//------------------------------------------------------------------------------------------

// Make copy of string in a safe place
const char * save_string(const char * s, int slen = -1)
{
    if (s == 0) return 0;
    if (slen < 0) slen = strlen(s);
    char * new_s = new char[slen + 1];
    if (new_s == 0) return 0;
    memcpy(new_s, s, slen);
    new_s[slen] = '\0';
    return new_s;
}

// Make jump table for mismatches (the usual finite state automaton).
//
// The inner loop works by checking the prefixes the next character of
// the target can continue, longest first, chaining back by way of the
// previously filled retarget entries, until it either finds one that
// matches (the != clause) or runs out of prefixes (the > 0 clause).

static int * make_retarget(const char * target)
{
    if (target == 0) return 0;
    int * retarget = new int[strlen(target)+1];
    if (retarget == 0) return 0;
    retarget[0] = -1;		// set up for loop below; unused by match()

    for (int i = 0; target[i] != '\0'; i++) {
	retarget[i + 1] = retarget[i] + 1;
	while (retarget[i + 1] > 0 &&
	       target[i] != target[retarget[i + 1] - 1])
	    retarget[i + 1] = retarget[retarget[i + 1] - 1] + 1;
    }
    return retarget;
}


// Construct matcher

//string_match::string_match(const char * t, int tlen = -1)
string_match::string_match(const char * t, int tlen )
{
    target = save_string(t, tlen);
    retarget = make_retarget(target);
    index = 0;
}


// Do the search

int
string_match::match(const unsigned char c)
{
    if (retarget == 0) return 0;

    while (c != target[index]) 
	{
		if (index == 0) return 0; // fell all the way back, have to give up
		index = retarget[index]; // more positions to fall back to, keep trying
    }
    if (target[++index] != '\0') return 0;	// partial match
    else 
	{
		index = retarget[index]; // full match, but keep going
		return 1;
    }
}

/*
bool hlr_read::decode_hlr_dump()
{
	hlr_profile_start = 0;

	int hlr_profile_count = 0;
	int hlr_profile_start = 0;
	int file_position = 0;

	char *extracted_value = new char[1000];
	char *imsi = new char[1000];
	char *speech = new char[1000];
	char *sms = new char[1000];
	char *ts60 = new char[1000];
	char *bs20 = new char[1000];
	char *bs30 = new char[1000];
	char *bs40 = new char[1000];

	hlr_profile hlr_p;
	
	while ( (hlr_profile_start= extract_string_inbetween(data_buffer, current, "IMSI,4", "END", hlr_profile_start, bytes_read) )!= 0 )
	{
		hlr_p.init();
			hlr_profile_count++;
			
			//cout << endl << endl;
			///cout << "hlr_profile_start = " << hlr_profile_start << endl;
			//cout << "data_buffer =" << data_buffer << "END" << endl;

			extracted_value[0] = '\0';
			imsi[0]		= '\0';
			imsi[0]		= '4';
			speech[0]	= '\0';
			sms[0]		= '\0';
			ts60[0]		= '\0';
			bs20[0]		= '\0';
			bs30[0]		= '\0';
			bs40[0]		= '\0';

			extract_string_left(imsi+1, (unsigned char*)data_buffer, ",");

			hlr_p.imsi = imsi;

			extract_string_right(extracted_value, (unsigned char*)data_buffer, "BSG");

			//cout << "imsi = " << hlr_p.imsi << "------------------------" << endl;
			//cout << "ev =" << extracted_value << endl;

			speech[0]	= extracted_value[1];
			sms[0]		= extracted_value[3];
			ts60[0]		= extracted_value[5];
			bs20[0]		= extracted_value[7];
			bs30[0]		= extracted_value[9];
			bs40[0]		= extracted_value[11];

			hlr_p.bsg[0]	= extracted_value[1];
			hlr_p.bsg[1]	= extracted_value[3];
			hlr_p.bsg[2]	= extracted_value[5];
			hlr_p.bsg[3]	= extracted_value[7];
			hlr_p.bsg[4]	= extracted_value[9];
			hlr_p.bsg[5]	= extracted_value[11];


			//cout << speech[0] << sms[0] << ts60[0] << bs20[0] << bs30[0] << bs40[0] << endl;

			//int  k;
			//cin >> k;

			gsm_churn->hlr_profile_map.insert(HLR_PROFILE_DEF::value_type(imsi, hlr_p));
	}
	cout << "hlr_profile_count = " << hlr_profile_count << endl << endl;
	return true;
}
*/
bool hlr_read::decode_hlr_dump()
{
	hlr_profile_start = 0;

	int hlr_profile_count = 0;
	int hlr_profile_start = 0;
	int file_position = 0;
	
	char *extracted_value = new char[1000];
	char *imsi = new char[1000];
	char *msisdn = new char[200];
	/*
	char *speech = new char[1000];
	char *sms = new char[1000];
	char *ts60 = new char[1000];
	char *bs20 = new char[1000];
	char *bs30 = new char[1000];
	char *bs40 = new char[1000];
	*/

	hlr_profile hlr_p;

	HLR_PROFILE_DEF::iterator	i_hlr;

	//"IMSI,4"
	
	while ( (hlr_profile_start= extract_string_inbetween(data_buffer, current, "IMSI,4", "END", hlr_profile_start, bytes_read) )!= 0 )
	{
		hlr_p.init();
			hlr_profile_count++;
			
			//cout << endl << endl;
			///cout << "hlr_profile_start = " << hlr_profile_start << endl;
			//cout << "data_buffer =" << data_buffer << "END" << endl;

			extracted_value[0] = '\0';
			imsi[0]		= '\0';
			imsi[0]		= '4';
			/*
			speech[0]	= '\0';
			sms[0]		= '\0';
			ts60[0]		= '\0';
			bs20[0]		= '\0';
			bs30[0]		= '\0';
			bs40[0]		= '\0';
			*/

			extract_string_left(imsi+1, (unsigned char*)data_buffer, ",");

			
			imsi[15]		= '\0';

			hlr_p.imsi		= imsi;
			

			if ( extract_string_right(extracted_value, (unsigned char*)data_buffer, "SN,") )
			{
				msisdn[0]	= '\0';

				msisdn[0]	= extracted_value[0];
				msisdn[1]	= extracted_value[1];
				msisdn[2]	= extracted_value[2];
				msisdn[3]	= extracted_value[3];
				msisdn[4]	= extracted_value[4];
				msisdn[5]	= extracted_value[5];
				msisdn[6]	= extracted_value[6];
				msisdn[7]	= '\0';


				/*
				msisdn[7]	= extracted_value[7];
				msisdn[8]	= extracted_value[8];
				msisdn[9]	= extracted_value[9];
				msisdn[10]	= extracted_value[10];
				msisdn[11]	= '\0';
				*/
				
				hlr_p.msisdn	= msisdn;
			}



			//cout << "imsi = " << hlr_p.imsi << "------------------------" << endl;
			//cout << "msisdn =" << msisdn << "|" << endl;
			//cout << "hlr_p.msisdn =" << hlr_p.msisdn << "|" << endl;

			/*
			speech[0]	= extracted_value[1];
			sms[0]		= extracted_value[3];
			ts60[0]		= extracted_value[5];
			bs20[0]		= extracted_value[7];
			bs30[0]		= extracted_value[9];
			bs40[0]		= extracted_value[11];

			hlr_p.bsg[0]	= extracted_value[1];
			hlr_p.bsg[1]	= extracted_value[3];
			hlr_p.bsg[2]	= extracted_value[5];
			hlr_p.bsg[3]	= extracted_value[7];
			hlr_p.bsg[4]	= extracted_value[9];
			hlr_p.bsg[5]	= extracted_value[11];
			*/


			//cout << speech[0] << sms[0] << ts60[0] << bs20[0] << bs30[0] << bs40[0] << endl;

			//int  k;
			//cin >> k;

			gsm_churn->hlr_profile_map.insert(HLR_PROFILE_DEF::value_type(imsi, hlr_p));

			/*
			for(i_hlr =gsm_churn->hlr_profile_map.begin(); i_hlr!=gsm_churn->hlr_profile_map.end(); i_hlr++)
			{
				cout <<  (*i_hlr).first << "," << (*i_hlr).second.msisdn << endl;
			}

			int  k;
			cin >> k;
			*/


	}
	cout << "hlr_profile_count = " << hlr_profile_count << endl << endl;
	return true;
}


