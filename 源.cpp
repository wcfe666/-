#include<stdlib.h>
#include<stdio.h>
//#include<time.h>
#include<Windows.h>
#define ZLONG 100  //���鳤��

//void deng(long long wtime);
int main(void) {
	unsigned long wtime = 10 * 1000;  //�ȴ�ʱ�䡣ע�⣺�������Ժ���Ϊ��λ��1��=1000����
	char zhiling[ZLONG] = "adb shell input swipe 350 900 350 300 200";  //�����ָ��﷨��adb shell input swipe ��ʼx�� ��ʼy�� ����x�� ����y�� ���̳���ʱ�����
	int sysret;  //����ֵ
	int tiao = 0;  //ˢ�˼�����Ƶ
	int death = 0;  //ʧ�ܴ���

	printf("��ʼִ�У�\n");
	printf("�ȴ�ʱ�䣺%lu��\n", wtime/1000);  //Ĭ�Ͻ�����ת��Ϊ��
	printf("ִ��ָ�");
	for (int i = 0; i < ZLONG; i++) {  //��ӡָ��
		printf("%c", zhiling[i]);
	}
	printf("\n");
	//system("adb devices");  //���һ�μ���豸�Ƿ����ӡ�ע�⣺�˳������ӡ�����������κδ���

	while (true)  //��ѭ��
	{
		//deng(wtime);  //�ȴ�
		Sleep(wtime);
		sysret = system(zhiling);  //ִ������
		if (sysret == 0) {
			tiao++;  //ÿˢһ�������һ
			printf("��ˢ%d����Ƶ\n", tiao);  //�����������ֵΪ0

		}
		else {
			printf("ʧ�ܣ�ָ���ֵΪ��%d\n", sysret);
			death++;
		}

		if (death == 3) {
			printf("����ʧ�ܣ�ǿ��ֹͣ\n");
			exit(EXIT_SUCCESS);
		}
	}
}
/*
void deng(long long wtime) {  //�ȴ�
	long long ltime = (long long)clock();  //��ȡ��ʼʱ��
	while (true) {
		long long ntime = (long long)clock();  //��ȡ��ǰʱ��
		if (ntime - ltime >= wtime) {  //�ﵽ�ض�ʱ����
			break;  //����ѭ��
		}
		else {  //����
			continue;  //����
		}
	}
}
*/