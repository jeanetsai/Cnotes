#include<fstream>//�B�z�ɮ׿�X�J�����Y��
#include<iostream>

using namespace std;
int main(){
	
	ifstream fin; //ifstream��Ū fin�إ߰�Ū�ɮת���
	fin.open("B_15_01_test.txt",ios::in);
	//�}�Ұ�Ū�ɮת���fin�ö}�ҳo��B_15_01_test.txt��
	
	if (!fin.is_open())
		cout<<"�ɮ׵L�k�}��"<<endl; 
	else
	{
		cout<<"�ɮ׶}��"<<endl;
		cout<<"������Ƭy..."<<endl;
		fin.close();
	}
	/*Output:
	�ɮ׶}��
	������Ƭy... 
	*/
	return 0;
} 
