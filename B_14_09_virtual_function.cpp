#include <iostream>

using namespace std;

class vehicle{
	//宣告基礎類別(父)vihicle
	public:
	virtual void start()=0;
	virtual void stop()=0; 
};

class aircraft: public vehicle{
	//宣告衍生類別(子1) arcraft 以public方式繼承vehicle
	public:
		virtual void start()
		{cout<<"飛行器啟動"<<endl;
		 } 
		virtual void stop()
		{cout<<"飛行器停止"<<endl;
		 }		
};

class car: public vehicle{
	//宣告衍生類別(子2) car 以public方式繼承vehicle
	public:
		virtual void start()
		{cout<<"汽車啟動"<<endl;
		 } 
		virtual void stop()
		{cout<<"汽車停止"<<endl;
		 }		
};

int main(){
	vehicle* ve;//宣告基礎類別vehicle指標，抽象基礎類別不可實體化故不是 vehicle* ve=new vehicle();
	aircraft af;
	car cr;
	
	ve=&af;
	ve->start();
	ve->stop();
	ve=&cr;
	ve->start();
	ve->stop();	 
/*output: 
飛行器啟動
飛行器停止
汽車啟動
汽車停止*/
return 0;	 
}






