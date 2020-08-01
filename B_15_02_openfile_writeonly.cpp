#include<fstream>//處理檔案輸出入的標頭檔
#include<iostream>

using namespace std;
int main(){
	
	ofstream fileOutput; //ofstream唯寫 fileOutput建立唯寫檔案物件 fstream讀+寫 
	fileOutput.open("B_15_02_output.txt",ios::out);
	//開啟唯寫檔案物件fileOutput並開啟這個B_15_02_output.txt檔
	
	if (!fileOutput.is_open())
	{
		cout<<"檔案無法開啟"<<endl; 
		return 1;
	}
	else
	{
		fileOutput<<"This is a book"<<endl;
		fileOutput<<"That is a pen"<<endl;
		fileOutput.close();
	}
	/*Output:B_15_02_output.txt出現內容: 
	This is a book
	That is a pen 
	*/
	return 0;
} 
