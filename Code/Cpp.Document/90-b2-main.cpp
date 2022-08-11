/* 2152189 信04 汪林辉 */
#include <iostream>
#include "90-b2.h"
using namespace std;

/************************************************************************
做出规定：
1、i统一表示横向循环打印，k统一表示纵向循环打印；
2、ROW表示总行数，row或者X用来表示数组中的坐标；
*************************************************************************/

/***************************************************************************
  函数名称：menu
  输入参数：空
  作    用：菜单界面+做出选择
  特    殊：有清屏
***************************************************************************/
int menu()
{
	cout << setfill('-') << setw(39) << '-' << setfill(' ') << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版(支持鼠标)" << endl;
	cout << "0.退出" << endl;
	cout << setfill('-') << setw(39) << '-' << setfill(' ') << endl;
	cout << "[请选择:] ";

	char menu;
	while (1) {
		menu = _getch();
		if (menu >= '0' && menu <= '9') {
			cout << menu;
			break;
		}
	}

	cct_cls();
	return menu - '0';
}


/**********************************************
如choose_YNQ,函数中尽量不要出现提示词语，看不清
细小的如打回车、回复颜色：严谨性
不要想微秒级，你i%3才执行不就快了？
***********************************************/
int main()
{
	srand((unsigned int)(time(0)));

	while (1) {
		int choice = menu();     //为了保证End()在清屏后回到菜单界面，menu应该放在里面

		if (choice == 0)         //0是退出循环的唯一方式
			break;

		int ROW, COLUMN, goal;                 //大写为总行列数
		int a[8][10] = { 0 };                  //相较于while是全局变量为什么要初始化！！！！
		char sub_a[8][10] = { '\0' };          //相较于while是全局变量为什么要初始化！！！！
		input_RCG(&ROW, &COLUMN, &goal, choice);
		initialize_array(a, ROW, COLUMN);

		if (choice<5)
			prepare(choice, a, sub_a, ROW, COLUMN, goal);
		else
			deluxe_pre(choice, a, sub_a, ROW, COLUMN, goal);
	}
	return 0;
}
