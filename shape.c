/*****************************************************
*文件名: shape.c
*文件描述：shape类方法实现
*版本：V0.1
*作者：侯改强
*时间：2019/02/15
*说明：实验C面对对象的编程
******************************************************/

/*********************头文件包含**********************/
#include "shape.h"
#include <stdio.h>



/********************全局变量定义*********************/


/**********************函数声明***********************/

/*****************************************************
*函数名称：Place_Set
*描    述：设置对象位置
*参    数：(struPlace *self, int x, int y)
*参数描述：(对象指针，       坐标x，坐标y)
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Place_Set(struPlace *self, int x, int y)
{
	self->x = x;
	self->y = y;
}

/*****************************************************
*函数名称：Place_Move
*描    述：移动对象位置
*参    数：(struPlace *self, int x, int y)
*参数描述：(对象指针，       坐标x，坐标y)
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Place_Move(struPlace *self, int x, int y)
{
	self->x += x;
	self->y += y;
}

/*****************************************************
*函数名称：Print_Place
*描    述：打印对象信息
*参    数：(struPlace *self)
*参数描述：(对象指针，     )
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Print_Place(struPlace *self)
{
	printf("位置信息:\n");
	printf("x = %d ,\n", self->x);
	printf("y = %d ,\n", self->y);
}

/*****************************************************
*函数名称：Init_struPlace
*描    述：初始化位置对象方法
*参    数：(struPlace *self)
*参数描述：(对象指针，     )
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Init_struPlace(struPlace *self)
{
	self->move = Place_Move;
	self->print = Print_Place;
	self->set = Place_Set;
}

/*****************************************************
*函数名称：Print_RectInfo
*描    述：打印对象信息
*参    数：(Rectangle *self)
*参数描述：(对象指针，     )
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Print_Rectangle(Rectangle *self)
{
	printf("矩形信息:\n");
	self->place.print(&self->place);
	printf("width = %d ,\n", self->width);
	printf("high = %d ,\n", self->high);
	printf("area = %d ,\n", self->area);
}

/*****************************************************
*函数名称：area_Rectangle
*描    述：矩形面积对象面积
*参    数：(Rectangle *self)
*参数描述：(对象指针，     )
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
int Calc_Area_Rectangle(Rectangle *self)
{
	self->area = self->high * self->width;
	return self->area;
}

/*****************************************************
*函数名称：Set_Rectangle
*描    述：初始化矩形对象
*参    数：(Rectangle *self，int x, int y, int width, int high)
*参数描述：(对象指针，       位置x, 位置y, 宽度width，高度high)
*日    期：2019/02/16
*作    者：侯改强
*****************************************************/
void Set_Rectangle(Rectangle *self, int x, int y, int width, int high)
{
	self->high = high;
	self->width = width;
	self->place.set(&self->place, x, y);
}

/*****************************************************
*函数名称：Init_struPlace
*描    述：初始化矩形对象方法
*参    数：(struPlace *self)
*参数描述：(对象指针，     )
*日    期：2019/02/16
*作    者：侯改强
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