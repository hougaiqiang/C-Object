/*****************************************************
*�ļ���: shape.c
*�ļ�������shape�෽��ʵ��
*�汾��V0.1
*���ߣ����ǿ
*ʱ�䣺2019/02/15
*˵����ʵ��C��Զ���ı��
******************************************************/

/*********************ͷ�ļ�����**********************/
#include "shape.h"
#include <stdio.h>



/********************ȫ�ֱ�������*********************/


/**********************��������***********************/

/*****************************************************
*�������ƣ�Place_Set
*��    �������ö���λ��
*��    ����(struPlace *self, int x, int y)
*����������(����ָ�룬       ����x������y)
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Place_Set(struPlace *self, int x, int y)
{
	self->x = x;
	self->y = y;
}

/*****************************************************
*�������ƣ�Place_Move
*��    �����ƶ�����λ��
*��    ����(struPlace *self, int x, int y)
*����������(����ָ�룬       ����x������y)
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Place_Move(struPlace *self, int x, int y)
{
	self->x += x;
	self->y += y;
}

/*****************************************************
*�������ƣ�Print_Place
*��    ������ӡ������Ϣ
*��    ����(struPlace *self)
*����������(����ָ�룬     )
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Print_Place(struPlace *self)
{
	printf("λ����Ϣ:\n");
	printf("x = %d ,\n", self->x);
	printf("y = %d ,\n", self->y);
}

/*****************************************************
*�������ƣ�Init_struPlace
*��    ������ʼ��λ�ö��󷽷�
*��    ����(struPlace *self)
*����������(����ָ�룬     )
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Init_struPlace(struPlace *self)
{
	self->move = Place_Move;
	self->print = Print_Place;
	self->set = Place_Set;
}

/*****************************************************
*�������ƣ�Print_RectInfo
*��    ������ӡ������Ϣ
*��    ����(Rectangle *self)
*����������(����ָ�룬     )
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Print_Rectangle(Rectangle *self)
{
	printf("������Ϣ:\n");
	self->place.print(&self->place);
	printf("width = %d ,\n", self->width);
	printf("high = %d ,\n", self->high);
	printf("area = %d ,\n", self->area);
}

/*****************************************************
*�������ƣ�area_Rectangle
*��    ������������������
*��    ����(Rectangle *self)
*����������(����ָ�룬     )
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
int Calc_Area_Rectangle(Rectangle *self)
{
	self->area = self->high * self->width;
	return self->area;
}

/*****************************************************
*�������ƣ�Set_Rectangle
*��    ������ʼ�����ζ���
*��    ����(Rectangle *self��int x, int y, int width, int high)
*����������(����ָ�룬       λ��x, λ��y, ���width���߶�high)
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Set_Rectangle(Rectangle *self, int x, int y, int width, int high)
{
	self->high = high;
	self->width = width;
	self->place.set(&self->place, x, y);
}

/*****************************************************
*�������ƣ�Init_struPlace
*��    ������ʼ�����ζ��󷽷�
*��    ����(struPlace *self)
*����������(����ָ�룬     )
*��    �ڣ�2019/02/16
*��    �ߣ����ǿ
*****************************************************/
void Init_Rectangle(Rectangle *self)
{
	Init_struPlace(&self->place);
	self->width_property = PUBLIC;
	self->high_property = PUBLIC;
	self->area_property = PRIVATE;
	self->calc_area = Calc_Area_Rectangle;
	self->set = Set_Rectangle;
	self->print = Print_Rectangle;
}