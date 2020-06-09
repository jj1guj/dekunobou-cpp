#include "dekunobou.hpp"

void time_print(double elapsed){
	int year,month,day,hour,min,mod;
	double sec;
	elapsed=elapsed/1000000;
	mod=(int)elapsed;
	elapsed-=mod;
	year=(int)mod/31536000;
	mod=mod%31536000;
	month=(int)mod/2592000;
	mod=mod%2592000;
	day=(int)mod/864000;
	mod=mod%864000;
	hour=(int)mod/3600;
	mod=mod%3600;
	min=(int)mod/60;
	sec=mod%60+elapsed;
	printf("%d/%d/%d %d:%d:%lf\n",year,month,day,hour,min,sec);
};

void disp_nowtime(){
	time_t nowtime=time(nullptr);
	const tm* lt=localtime(&nowtime);
	printf("%04d/%02d/%02d %02d:%02d:%02d\n",
	lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,
	lt->tm_min,lt->tm_sec);
}