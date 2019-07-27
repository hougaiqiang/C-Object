/*****************************************************
*�ļ�����main.c
*�ļ�������������ڣ�����������
*�汾��V0.1
*���ߣ����ǿ
*ʱ�䣺2019/02/15
*˵����ʵ��C��Զ���ı��
******************************************************/
/*********************ͷ�ļ�����**********************/
#include <stdio.h>
#include <stdlib.h>
#include <thr/xthreads.h>
#include "shape.h"

/********************ȫ�ֱ�������*********************/


/**********************��������***********************/
void Thd_place(void);
void Thd_rectangle(void);

/*****************************************************
*�������ƣ�main
*��    �����������
*��    ������
*������������
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
int main(void)
{
	_Thrd_t ProcessPlaceId;
	_Thrd_t ProcessRectId;

	switch (_Thrd_create(&ProcessPlaceId, Thd_place, NULL))
	{
	case _Thrd_success:
		printf("create thread place start \n");
		break;
	case _Thrd_nomem:
		printf("malloc thread place mem faild \n");
		break;
	case _Thrd_error:
		printf("create thread place faile \n");
		exit(1);
	}

	switch (_Thrd_create(&ProcessRectId, Thd_rectangle, NULL))
	{
	case _Thrd_success:
		printf("create thread rectangle start \n");
		break;
	case _Thrd_nomem:
		printf("malloc thread rectangle mem faild \n");
		break;
	case _Thrd_error:
		printf("create thread rectangle faile \n");
		exit(1);
	}
	_Thrd_join(ProcessPlaceId, NULL);
	_Thrd_join(ProcessRectId, NULL);

	system("pause");
	return 0;
}

void Thd_place(void)
{
	struPlace struMyPlace;
	Init_struPlace(&struMyPlace);
	printf("struMyPlace\n");
	/*�����ʼ��*/
	struMyPlace.set(&struMyPlace, 10, 10);
	/*��ӡ����*/
	struMyPlace.print(&struMyPlace);
	/*���������Ա*/
	struMyPlace.move(&struMyPlace, 10, -5);
	/*��ӡ����*/
	struMyPlace.print(&struMyPlace);

	while (1);
}

void Thd_rectangle(void)
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
	pstruMyRectangle->print = pstruMyRectangle->place.print;
	pstruMyRectangle->print(&pstruMyRectangle->place);
	free(pstruMyRectangle);

	while (1);
}

/**********************�ļ�����***********************/