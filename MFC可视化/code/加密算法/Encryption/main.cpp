#include "AES.h"
#include "StdAfx.h"
#include "GetCpuID.h"
#include "Registry.h"
#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	char cpuID[32] = "popopopopopopopo";
	//char cpuID[32] = {'0'};
	char a[33];

	//memset(cpuID,0,sizeof(cpuID));
   
	printf("Time:%s\n",getTime());

	//getCpuID();
	//strcpy(cpuID,getCpuID());

	printf("cpuID:%s\n",cpuID);
	strcpy(a, getPlainText(cpuID));
	printf("���ܺ�: %s\n", a);

	Write_reg_ID(a);
	printf("��ȡע���_ID: %s\n", Read_reg_ID());

	strcpy_s(a, De(a));
	printf("���ܺ�: %s\n", a);

	system("pause");
	return 0;
}
//
//��ע������ݡ�
//ID : ��cpuID���㷨2����д��ע���
//Identity: ��ע���û��������û��ı�ʶ
//BeginTime: �״ε����õ�ʱ���¼���㷨3���ܣ�
//LatestTime: ���һ��ʹ�õ�ʱ���¼���㷨3���ܣ�
//ע��ʱ������Ϊ��λ
//
//����װ��ʹ�á�
//1������״���������װ��ʱ����Identity����Ϊ�����û��ı�ʶ������ʱϵͳʱ��д��ע�����BeginTime��LatestTime��
//2����װ��ɺ�
//      ע���û�������ע����� (�����桶ע����̡�)
//      �����û�������ʹ��
//3��ÿ��ʹ�����ʱ�����ȶ�ȡIdentity
//      IdentityΪע���û�     ��ע����ȡID,��ID�����㷨2���ܣ�
//      ������CPUID��֤���������룻�����˳���
//      IdentityΪ�����û�     ��ע����ȡBeginTime���㷨3���ܣ���LatestTime���㷨3���ܣ���
//      �жϴ�ʱϵͳʱ��NowTime��LatestTime�����NowTime <=  LatestTime,�˳���
//       ���򣬼����ж�NowTime - BeginTime <  T(����ʱ��)��
//                 ��������������ã�����NowTime���ǵ�ע�����LatestTime��
//                 �����˳���
//
//    ��ע����̡�
//1���㷨1����CPUID�õ�A����ʾ�ͻ��ˣ��ͻ�������A�������
//2��������յ�A,ʹ���㷨1����A�õ�CPUID,��ʹ���㷨2����CPUID�õ�B�����·���B���ͻ�
//3���ͻ��յ�B,Ȼ�����ע�ᣬʹ���㷨2����B�õ�CPUID�����ڿͻ�CPUID�ȶԣ�
//      �����ע��ɹ����޸�ע�����IdentityΪע���û���
//      ����ȣ�ע��ʧ�ܣ��˳���
//         