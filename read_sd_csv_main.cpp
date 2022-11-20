#include<vector>
#include<string>
#include<iostream>

#include <sstream>
#include <fstream>
#include <algorithm>

#include<stdlib.h>
#include<malloc.h>

////

#include "platform.h"
#include "xil_printf.h"
#include "ff.h"
#include "xil_cache.h"
#include "xil_io.h"
#include "xsdps.h"
#include <random>

using namespace std;

#define ROW_MAX 2250
#define LINE_LEN 150000
vector<vector<string> > ReadCsvFile(string filename);
vector<string> split_str(string str);

int main(int argc, char *argv[])
{
	static FATFS FS_instance;
    init_platform();
    printf("Mounting SD Card\n\r");
	FRESULT result = f_mount(&FS_instance,"0:", 1);
    if (result != 0) {
	printf("Couldn't mount SD Card. Try again later.\n");
	}
    FIL test_data_inputs_pointer;
    char cfilename[] = "0.csv";
    FRESULT open_result = f_open(&test_data_inputs_pointer, cfilename, FA_OPEN_ALWAYS | FA_READ);
    if(open_result != 0){
    	printf("Open CSV Error!\n");
    }
    else{
    	printf("Open CSV success!\n");
    	char* line_buffer = NULL;
    	printf("Begin read line!\n");
    	while(!f_eof(&test_data_inputs_pointer)){
    		f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer);
    		printf("Line content:%s\n", line_buffer);
    	}
/*
    	f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer);
    	printf("1 Line content:%s\n", line_buffer);
    	f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer);
    	printf("2 Line content:%s\n", line_buffer);
    	f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer);
    	printf("3 Line content:%s\n", line_buffer);
*/
    }
//    char* read_buffer = NULL;
//    UINT read_size = 1000;
//    UINT* read_ptr = NULL;
//    FRESULT read_result = f_read(&test_data_inputs_pointer, (void*)read_buffer, read_size, read_ptr);
//    if(read_result != 0){
//    	printf("Read CSV Error! Read status is %d.\n", read_result);
//    }
//    else{
//    	printf("Read CSV success!\n");
//    	printf("Read content:%s", read_buffer);
//    }
/*    char* line_buffer = NULL;
    printf("Begin read line!\n");
//    UINT lineNo = 0;
    while(f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer) != NULL){
//    	lineNo++;
        printf("Line content:%s\n", line_buffer);
        printf("Read Next Line!");
    }*/
//    f_gets(line_buffer, LINE_LEN, &test_data_inputs_pointer);
//    printf("Line content:%s\n", line_buffer);
/*    vector<vector<string> > read_csv_content;
    printf("Starting to read CSV.\n");
    read_csv_content = ReadCsvFile("0.csv");
    printf("End reading CSV.\n");
    for(unsigned int i=0; i < read_csv_content.size(); i++){
    	printf("line : %d\n",i);
    	for(unsigned int j=0; j < read_csv_content[i].size(); j++){
    		printf("%s ,",read_csv_content[i][j].c_str());
    	}
    	cout << endl;
    }
    printf("finish output!");*/
    f_close(&test_data_inputs_pointer);
    cleanup_platform();
    return 0;
}

/*vector<string> split_str(string str)
{
    string word = "";
    vector<string> temp;
    for (auto x : str)
    {
        if (x == ' ')
        {
            temp.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    return temp;
}
*/
/*vector<vector<string> > ReadCsvFile(string filename){
    const char* cfilename = filename.data();
    string temp;
    vector<string> v_temp;
    vector<vector<string> > vv_temp;
//    char* line = NULL; //for reading every line in file
//    char* value = NULL;
    FIL test_data_inputs_pointer;
    FRESULT result = f_open(&test_data_inputs_pointer, cfilename, FA_OPEN_ALWAYS | FA_READ);
    if(result != 0){
    	printf("Open CSV Error!\n");
    }
    else{
    	printf("Open CSV success!\n");
    }
    //char* buf = {0};
    char buf[LINE_LEN];
    u32 file_size = 2250*15000;
    UINT num_bytes_read;
    char* destination_addr = NULL;
    int lineNo = 0;
    int line_len = 0;
//    FRESULT read_result = f_read(&test_data_inputs_pointer, (void*)destination_addr, file_size, &num_bytes_read);
//    if(read_result !=0){
//    	printf("Read ERROR!\n");
//    	printf("read status:%d\n", read_result);
//    }
//    else{
//    	printf("READ SUCCESS!");
//    }

    printf("BEGIN Get lines!\n");
    f_gets(buf, LINE_LEN, &test_data_inputs_pointer);
    printf("End Get lines!\n");
//    buf = f_gets(buf, LINE_LEN, &test_data_inputs_pointer);
    printf("BUF:%s\n", buf);
//   while (f_gets(buf, ROW_MAX, &test_data_inputs_pointer))
//    {
//        lineNo++;
//        if(buf != NULL){
//        if ('\n' == buf[line_len - 1]) {
//			buf[line_len - 1] = '\0';
//			line_len--;
//            temp = buf;
//           printf("get line: %p \n", buf);
//            v_temp = split_str(temp);
//            vv_temp.push_back(v_temp);
//			if (0 == line_len) {
//				continue;
//			}
//		}
//        }
//        else{
//        	printf("BUF is NULL!");
//        }
//    }
    f_close(&test_data_inputs_pointer);
    return vv_temp;
}
*/
