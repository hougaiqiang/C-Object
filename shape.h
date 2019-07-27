/*****************************************************
*文件名: shape.h
*文件描述：shape类定义
*版本：V0.1
*作者：侯改强
*时间：2019/02/15
*说明：实验C面对对象的编程
******************************************************/

#ifndef _SHAPE_H
#define _SHAPE_H

/*********************头文件包含**********************/

/***********************宏定义************************/
#define PUBLIC 0
#define PRIVATE 1
#define PROTECT 2
/**********************类型定义***********************/
typedef struct{
	int x;
	int y;
	void(*set)(struct struPlace*, int, int);
	void(*move)(struct struPlace*, int, int);
	void(*print)(struct struPlace*);
}struPlace;

typedef struct{
	struPlace place;
	int width;
	int high;
	int area;
	unsigned int width_property : 2;
	unsigned int high_property  : 2;
	unsigned int area_property  : 2;
	unsigned int : 26;
	void(*print)(struct Rectangle *self);
	int (*calc_area)(struct Rectangle *self);
	void(*set)(struct Rectangle *self, int x, int y, int width, int high);
}Rectangle;
/**********************函数声明***********************/


/*****************************************************
*函数名称：Init_struPlace
*描    述：初始化对象struPlace
*****************************************************/
void Init_struPlace(struPlace *self);


/*****************************************************
*函数名称：Init_struPlace
*描    述：初始化矩形对象方法
*****************************************************/
void Init_Rectangle(Rectangle *self);


/********************外部变量声明*********************/


/********************外部函数声明*********************/

#endif // __SHAPE_H
