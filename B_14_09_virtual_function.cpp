#include <iostream>

using namespace std;

class vehicle{
	//�ŧi��¦���O(��)vihicle
	public:
	virtual void start()=0;
	virtual void stop()=0; 
};

class aircraft: public vehicle{
	//�ŧi�l�����O(�l1) arcraft �Hpublic�覡�~��vehicle
	public:
		virtual void start()
		{cout<<"���澹�Ұ�"<<endl;
		 } 
		virtual void stop()
		{cout<<"���澹����"<<endl;
		 }		
};

class car: public vehicle{
	//�ŧi�l�����O(�l2) car �Hpublic�覡�~��vehicle
	public:
		virtual void start()
		{cout<<"�T���Ұ�"<<endl;
		 } 
		virtual void stop()
		{cout<<"�T������"<<endl;
		 }		
};

int main(){
	vehicle* ve;//�ŧi��¦���Ovehicle���СA��H��¦���O���i����ƬG���O vehicle* ve=new vehicle();
	aircraft af;
	car cr;
	
	ve=&af;
	ve->start();
	ve->stop();
	ve=&cr;
	ve->start();
	ve->stop();	 
/*output: 
���澹�Ұ�
���澹����
�T���Ұ�
�T������*/
return 0;	 
}






