#include<fstream>//�B�z�ɮ׿�X�J�����Y��
#include<iostream>

using namespace std;
int main(){
	
	ofstream fileOutput; //ofstream�߼g fileOutput�إ߰߼g�ɮת��� fstreamŪ+�g 
	fileOutput.open("B_15_02_output.txt",ios::out);
	//�}�Ұ߼g�ɮת���fileOutput�ö}�ҳo��B_15_02_output.txt��
	
	if (!fileOutput.is_open())
	{
		cout<<"�ɮ׵L�k�}��"<<endl; 
		return 1;
	}
	else
	{
		fileOutput<<"This is a book"<<endl;
		fileOutput<<"That is a pen"<<endl;
		fileOutput.close();
	}
	/*Output:B_15_02_output.txt�X�{���e: 
	This is a book
	That is a pen 
	*/
	return 0;
} 
