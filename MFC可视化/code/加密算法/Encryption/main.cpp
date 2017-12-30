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
	printf("加密后: %s\n", a);

	Write_reg_ID(a);
	printf("读取注册表_ID: %s\n", Read_reg_ID());

	strcpy_s(a, De(a));
	printf("解密后: %s\n", a);

	system("pause");
	return 0;
}
//
//《注册表内容》
//ID : 对cpuID用算法2加密写入注册表
//Identity: 对注册用户和试用用户的标识
//BeginTime: 首次的试用的时间记录（算法3加密）
//LatestTime: 最近一次使用的时间记录（算法3加密）
//注：时间以天为单位
//
//《安装与使用》
//1、软件首次启动（安装）时，将Identity设置为试用用户的标识，将此时系统时间写入注册表中BeginTime和LatestTime中
//2、安装完成后
//      注册用户，进行注册过程 (见下面《注册过程》)
//      试用用户，进行使用
//3、每次使用软件时，首先读取Identity
//      Identity为注册用户     从注册表读取ID,对ID进行算法2解密，
//      其结果与CPUID验证，相等则进入；否则退出。
//      Identity为试用用户     从注册表读取BeginTime（算法3解密）和LatestTime（算法3解密）。
//      判断此时系统时间NowTime与LatestTime，如果NowTime <=  LatestTime,退出；
//       否则，继续判断NowTime - BeginTime <  T(试用时间)，
//                 成立，则继续试用，并将NowTime覆盖掉注册表中LatestTime；
//                 否则，退出。
//
//    《注册过程》
//1、算法1加密CPUID得到A，显示客户端，客户线下送A到服务端
//2、服务端收到A,使用算法1解密A得到CPUID,再使用算法2加密CPUID得到B，线下发送B给客户
//3、客户收到B,然后进行注册，使用算法2解密B得到CPUID，并于客户CPUID比对，
//      相等则注册成功，修改注册表中Identity为注册用户；
//      不相等，注册失败，退出。
//         