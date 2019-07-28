/*****************************************************
*文件名：main.c
*文件描述：程序入口，程序主流程
*版本：V0.1
*作者：侯改强
*时间：2019/02/15
*说明：实验C面对对象的编程
******************************************************/
/*********************头文件包含**********************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "shape.h"

/********************全局变量定义*********************/


/**********************函数声明***********************/
void *Thd_place(void *arg);
void *Thd_rectangle(void *arg);

/*****************************************************
*函数名称：main
*描    述：程序入口
*参    数：无
*参数描述：无
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
int main(void)
{
	pthread_t ProcessPlaceId;
	pthread_t ProcessRectId;
	pid_t pid;
	pthread_t mtid;

	mtid = pthread_self();

	if(0 == pthread_create(&ProcessPlaceId, NULL, Thd_place, NULL))
	{
		printf("create thread place start \n");	
	}
	else
	{
		printf("create thread place faile \n");
		exit(1);
	}
	

	if(0 == pthread_create(&ProcessRectId, NULL, Thd_rectangle, NULL))
	{
		printf("create thread rectangle start \n");	
	}
	else
	{
		printf("create thread rectangle faile \n");
		exit(1);
	}

	system("pause");
	return 0;
}

void *Thd_place(void *arg)
{
	struPlace struMyPlace;
	Init_struPlace(&struMyPlace);
	printf("struMyPlace\n");
	/*对象初始化*/
	struMyPlace.set(&struMyPlace, 10, 10);
	/*打印对象*/
	struMyPlace.print(&struMyPlace);
	/*操作对象成员*/
	struMyPlace.move(&struMyPlace, 10, -5);
	/*打印对象*/
	struMyPlace.print(&struMyPlace);

	while (1)
	{
		sleep(1);
	}
	return NULL;
}

void *Thd_rectangle(void *arg)
{
	Rectangle *pstruMyRectangle = malloc(sizeof(Rectangle));
	int RectArea = 0;

	printf("pstruMyRectangle\n");
	Init_Rectangle(pstruMyRectangle);
	pstruMyRectangle->set(pstruMyRectangle, 50, 50, 20, 30);

	RectArea = pstruMyRectangle->calc_area(pstruMyRectangle);
	printf("pstruMyRectangle area = %d ,\n", RectArea);

	pstruMyRectangle->place.print(&pstruMyRectangle->place);
	pstruMyRectangle->print(pstruMyRectangle);

	printf("dual\n");
	pstruMyRectangle->print = (void *)pstruMyRectangle->place.print;
	pstruMyRectangle->print((struct Rectangle *)&pstruMyRectangle->place);
	free(pstruMyRectangle);

	while (1)
	{
		sleep(1);
	}
	return NULL;
}

/**********************文件结束***********************/