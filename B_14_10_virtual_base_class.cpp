#include <iostream>

using namespace std;

class vehicle{
	//�ŧi��¦���O(��)vihicle
	public:
		void start()
		{cout<<"�B��u��Ұ�"<<endl;
		 } 
		void shutdown()
		{cout<<"�B��u�㰱��"<<endl;
		 }
};

class aircraft: virtual public vehicle{
	//�ŧi��¦���O(��1) arcraft �Hpublic�覡�~��vehicle
	public:
		void fly()
		{cout<<"���澹����"<<endl;
		 } 
		void land()
		{cout<<"���澹�۳�"<<endl;
		 }		
};

class car: virtual public vehicle{
	//�ŧi¦���O(��2) car �Hpublic�覡�~��vehicle
	public:
		void go()
		{cout<<"�T���Ұ�"<<endl;
		 } 
		void stop()
		{cout<<"�T������"<<endl;
		 }		
};
//�ŧi�l�����O(�]) aircar �Hpublic�覡�~�Ӧۨ�Ӥ� 
class aircar: public aircraft, public car{};

int main(){
	 
 	aircar ac;
 	ac.start();		//�l�ͨ�� ac �I�s�W��h��¦���O(��)vehicle���������
 	ac.go();		//��2 car 
 	ac.fly();		//��1 fly 
 	ac.land();		//��1 land 
 	ac.stop();		//��2 stop 
 	ac.shutdown();	//�l�ͨ�� ac �I�s�W��h��¦���O(��)vehicle���������
/*output: 
�B��u��Ұ�
�T���Ұ�
���澹����
���澹�۳�
�T������
�B��u�㺶��*/
return 0;	 
}
