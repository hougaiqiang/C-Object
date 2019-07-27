/*****************************************************
*�ļ���: shape.h
*�ļ�������shape�ඨ��
*�汾��V0.1
*���ߣ����ǿ
*ʱ�䣺2019/02/15
*˵����ʵ��C��Զ���ı��
******************************************************/

#ifndef _SHAPE_H
#define _SHAPE_H

/*********************ͷ�ļ�����**********************/

/***********************�궨��************************/
#define PUBLIC 0
#define PRIVATE 1
#define PROTECT 2
/**********************���Ͷ���***********************/
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
/**********************��������***********************/


/*****************************************************
*�������ƣ�Init_struPlace
*��    ������ʼ������struPlace
*****************************************************/
void Init_struPlace(struPlace *self);


/*****************************************************
*�������ƣ�Init_struPlace
*��    ������ʼ�����ζ��󷽷�
*****************************************************/
void Init_Rectangle(Rectangle *self);


/********************�ⲿ��������*********************/


/********************�ⲿ��������*********************/

#endif // __SHAPE_H
