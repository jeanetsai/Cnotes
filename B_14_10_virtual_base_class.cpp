#include <iostream>

using namespace std;

class vehicle{
	//宣告基礎類別(爺)vihicle
	public:
		void start()
		{cout<<"運輸工具啟動"<<endl;
		 } 
		void shutdown()
		{cout<<"運輸工具停止"<<endl;
		 }
};

class aircraft: virtual public vehicle{
	//宣告基礎類別(父1) arcraft 以public方式繼承vehicle
	public:
		void fly()
		{cout<<"飛行器飛行"<<endl;
		 } 
		void land()
		{cout<<"飛行器著陸"<<endl;
		 }		
};

class car: virtual public vehicle{
	//宣告礎類別(父2) car 以public方式繼承vehicle
	public:
		void go()
		{cout<<"汽車啟動"<<endl;
		 } 
		void stop()
		{cout<<"汽車熄火"<<endl;
		 }		
};
//宣告衍生類別(孫) aircar 以public方式繼承自兩個父 
class aircar: public aircraft, public car{};

int main(){
	 
 	aircar ac;
 	ac.start();		//衍生函數 ac 呼叫上兩層基礎類別(爺)vehicle的成員函數
 	ac.go();		//父2 car 
 	ac.fly();		//父1 fly 
 	ac.land();		//父1 land 
 	ac.stop();		//父2 stop 
 	ac.shutdown();	//衍生函數 ac 呼叫上兩層基礎類別(爺)vehicle的成員函數
/*output: 
運輸工具啟動
汽車啟動
飛行器飛行
飛行器著陸
汽車熄火
運輸工具熄火*/
return 0;	 
}
