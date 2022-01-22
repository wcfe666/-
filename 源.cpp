#include<stdlib.h>
#include<stdio.h>
//#include<time.h>
#include<Windows.h>
#define ZLONG 100  //数组长度

//void deng(long long wtime);
int main(void) {
	unsigned long wtime = 10 * 1000;  //等待时间。注意：这里是以毫秒为单位。1秒=1000毫秒
	char zhiling[ZLONG] = "adb shell input swipe 350 900 350 300 200";  //输入的指令。语法：adb shell input swipe 开始x轴 开始y轴 结束x轴 结束y轴 过程持续时间毫秒
	int sysret;  //返回值
	int tiao = 0;  //刷了几条视频
	int death = 0;  //失败次数

	printf("开始执行！\n");
	printf("等待时间：%lu秒\n", wtime/1000);  //默认将毫秒转换为秒
	printf("执行指令：");
	for (int i = 0; i < ZLONG; i++) {  //打印指令
		printf("%c", zhiling[i]);
	}
	printf("\n");
	//system("adb devices");  //最后一次检查设备是否连接。注意：此初仅会打印，不会作出任何处理

	while (true)  //死循环
	{
		//deng(wtime);  //等待
		Sleep(wtime);
		sysret = system(zhiling);  //执行命令
		if (sysret == 0) {
			tiao++;  //每刷一条都会加一
			printf("已刷%d条视频\n", tiao);  //正常情况返回值为0

		}
		else {
			printf("失败！指令返回值为：%d\n", sysret);
			death++;
		}

		if (death == 3) {
			printf("运行失败！强制停止\n");
			exit(EXIT_SUCCESS);
		}
	}
}
/*
void deng(long long wtime) {  //等待
	long long ltime = (long long)clock();  //获取开始时间
	while (true) {
		long long ntime = (long long)clock();  //获取当前时间
		if (ntime - ltime >= wtime) {  //达到特定时长后
			break;  //跳出循环
		}
		else {  //否则
			continue;  //继续
		}
	}
}
*/