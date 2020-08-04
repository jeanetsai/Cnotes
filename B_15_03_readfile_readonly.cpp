#include<fstream>//處理檔案輸出入的標頭檔
#include<iostream>

using namespace std;
int main(){
	
	//讀檔 
	string str;
	char data[200];
	char oneChar;
	
	ifstream fin; //ifstream唯讀 fin建立唯讀檔案物件
	fin.open("B_15_03_input.txt");
	//唯讀檔案物件fin的open函式開啟這個B_15_03_input.txt檔
	
	if (!fin.is_open())
		cout<<"檔案無法開啟"<<endl; 
	else
	{
		
		//讀取12個字元
		/*for(int i=0;i<120;i++)
		{
			//讀取一個字元
			fin.get(oneChar);//使用get函式讀取字元
			cout<<oneChar; 
		}
		//讀取一筆資料
		/*
		fin.getline(data,sizeof(data));//使用getline()函式讀取整列資料
		cout<<data<<endl<<endl;
		*/
		//使用">>"讀取資料 
		fin>>str;
		while(!fin.eof())
		{	cout<<str<<ends;
			fin>>str;
		}		
		fin.close();
		
	}
	/*Output:
	This is a book That is a pen Those are desks
	*/
	return 0;
} 
