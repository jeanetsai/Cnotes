#include<fstream>//處理檔案輸出入的標頭檔
#include<iostream>

using namespace std;
int main(){
	
	ifstream fin; //ifstream唯讀 fin建立唯讀檔案物件
	fin.open("B_15_01_test.txt",ios::in);
	//開啟唯讀檔案物件fin並開啟這個B_15_01_test.txt檔
	
	if (!fin.is_open())
		cout<<"檔案無法開啟"<<endl; 
	else
	{
		cout<<"檔案開啟"<<endl;
		cout<<"關閉資料流..."<<endl;
		fin.close();
	}
	/*Output:
	檔案開啟
	關閉資料流... 
	*/
	return 0;
} 
