#include<fstream>//�B�z�ɮ׿�X�J�����Y��
#include<iostream>

using namespace std;
int main(){
	
	//Ū�� 
	string str;
	char data[200];
	char oneChar;
	
	ifstream fin; //ifstream��Ū fin�إ߰�Ū�ɮת���
	fin.open("B_15_03_input.txt");
	//��Ū�ɮת���fin��open�禡�}�ҳo��B_15_03_input.txt��
	
	if (!fin.is_open())
		cout<<"�ɮ׵L�k�}��"<<endl; 
	else
	{
		
		//Ū��12�Ӧr��
		/*for(int i=0;i<120;i++)
		{
			//Ū���@�Ӧr��
			fin.get(oneChar);//�ϥ�get�禡Ū���r��
			cout<<oneChar; 
		}
		//Ū���@�����
		/*
		fin.getline(data,sizeof(data));//�ϥ�getline()�禡Ū����C���
		cout<<data<<endl<<endl;
		*/
		//�ϥ�">>"Ū����� 
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
