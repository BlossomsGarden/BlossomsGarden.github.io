/* 2152189 信04 汪林辉 */
#include <iostream>
#include "90-b2.h"
using namespace std;



/***************************************************************************
  函数名称：draw
  输入参数：主数组、附属数组、主数组的行数、主数组的列数、画画参数
  作    用：传入数组打印基本界面(某处sub_a非'\0'，该处背景色彩填充)
  特    殊：draw为0输出sub_a；draw为1无色输出a；draw为2有色输出a；末尾额外换行
***************************************************************************/
void draw(int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int draw)
{
	int i, k;
	cout << ' ' << ' ' << '|';
	for (i = 0; i < COLUMN; i++)
		cout << setw(3) << i;
	cout << endl;
	cout << '-' << '-' << '+';
	for (i = 0; i < COLUMN; i++)
		cout << setw(3) << setfill('-') << '-' << setfill(' ');
	cout << '-' << endl;

	for (k = 0; k < ROW; k++) {
		cout << (char)('A' + k) << ' ' << '|';
		/*单纯的输出附属数组？还是需要填背景颜色？*/
		if (draw == 0) {
			for (i = 0; i < COLUMN; i++) {
				if (sub_a[k][i] == '\0')
					cout << setw(3) << (int)sub_a[k][i];
				else
					cout << "  *";
			}
		}

		if (draw == 1) {
			for (i = 0; i < COLUMN; i++) {
				cout << setw(3) << a[k][i];
			}
		}

		if (draw==2) {
			for (i = 0; i < COLUMN; i++) {
				if (sub_a[k][i] != '\0') {
					cout << ' ';
					if (a[k][i] / 10 == 0)
						cout << ' ';
					cct_setcolor(BG_COLOR, 0);
					cout << a[k][i];
					cct_setcolor();
				}
				else
					cout << setw(3) << a[k][i];
			}
		}
		
		cout << endl;
	}
	cout << endl;
}

/***************************************************************************
  函数名称：initialize_array
  输入参数：主数组、主数组的行数、主数组的列数
  作    用：对主数组随即赋值
  特    殊：无
***************************************************************************/
void initialize_array(int a[8][10], int ROW, int COLUMN)
{
	while (1) {
		int k, i;
		for (k = 0; k < ROW; k++) {
			for (i = 0; i < COLUMN; i++)
				a[k][i] = Generate_num(1);
		}

		/*此处是为了判断是否生成的数组本身就是该over的*/
		if (!over(a, ROW, COLUMN))
			break;
	}
	return;
}

/***************************************************************************
  函数名称：fill
  输入参数：主数组、附属数组
  作    用：对0进行新值填充
  特    殊：无可消则1，仍有则0
***************************************************************************/
void fill(int a[8][10],char sub_a[8][10])
{
	int i, k;
	for (k = 0; k < 8; k++)
		for (i = 0; i < 10; i++)
			if (sub_a[k][i] == '*')
				a[k][i] = Generate_num(a_max(a));
	return;
}

/***************************************************************************
  函数名称：over
  输入参数：主数组、主数组行列数
  作    用：判断游戏是否结束
  特    殊：无可消则1，仍有则0
***************************************************************************/
bool over(int a[8][10],int ROW,int COLUMN)
{
	int count = 0;
	int k, i;
	for (k = 0; k < ROW; k++) {
		for (i = 0; i < COLUMN; i++)
			if (check(a, k, i) == 0)
				count++;
	}

	if (count == 0)
		return 1;
	else
		return 0;
}

/***************************************************************************
  函数名称：choose_YNQ
  输入参数：输入的坐标位置
  作    用：读入键盘上输入的字符串对应矩阵中的坐标
  特    殊：无
***************************************************************************/
char choose_YNQ(int X,int Y)
{
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 'Y' || ch == 'y') {
			cout << ch << endl;
			break;
		}
		if (ch == 'N' || ch == 'n') {
			cout << ch << endl;
			break;
		}
		if (ch == 'q' || ch == 'Q') {
			cout << ch << endl;
			break;
		}
	}
	/*注意不要这里多换一行而ch输出后面没有，你跳进函数里了，还没执行到这呢*/
	return (ch > 90 ? (ch - 32) : ch);
}


/***************************************************************************
  函数名称：prepare
  输入参数：输入的菜单数1~4
  作    用：主要框架的搭建
  特    殊：无
***************************************************************************/
void prepare(int menu,int a[8][10],char sub_a[8][10], int ROW, int COLUMN, int goal)
{
	int X, Y;                  //XY表示某个具体数的坐标
	int fenshu = 0;
	int zongfen = 0;

	while (1) {
		/*伪全局变量内部初始化！！！！！*/
		int k, i;
		for (k = 0; k < 8; k++) {
			for (i = 0; i < COLUMN; i++) {
				sub_a[k][i] = '\0';
			}
		}

		cout << endl << "当前数组：" << endl;
		draw(a, sub_a, ROW, COLUMN, 1);

		/*判断游戏结束*/
		if (over(a, ROW, COLUMN)) {
			cct_setcolor(BG_COLOR, COLOR_RED);
			cout << "真可惜，没有可合并的项了，游戏结束！" << endl;
			cct_setcolor();
			End();
			break;
		}

		/*判断输入是否可操作*/
		while (1) {
			input_COORD(&X, &Y, ROW, COLUMN);
			if (check(a, X, Y))
				break;
			else
				cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		}

		cout << endl << "查找结果数组" << endl;

		if (menu == 1)
			seek_same_1(a, sub_a, ROW, COLUMN, X, Y);
		else
			seek_same_2(a, sub_a, X, Y);

		draw(a, sub_a, ROW, COLUMN, 0);

		cout << endl << "当前数组(不同色标识)：" << endl;
		draw(a, sub_a, ROW, COLUMN, 2);

		if (menu == 1 || menu == 2) {
			End();
			break;
		}
		else {
			cout << "请确认是否把相邻的相同值合并到" << (char)('A' + X) << Y << "中(Y/N/Q)：";
			char ch = choose_YNQ(X, Y);
			if (ch == 'Y') {
				cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
				fenshu = score(a, sub_a, X, Y);
				zongfen += fenshu;
				draw(a, sub_a, ROW, COLUMN, 2);
				cout << "本次得分：" << fenshu << ' ' << "总得分：" << zongfen << ' ' << "合成目标：" << goal << endl;
				cout << endl;

				Enter("按回车键进行数组下落除0操作");

				cout << "除0后的数组(不同色标识)：" << endl;
				drop(a, sub_a, ROW, COLUMN, X, Y);
				draw(a, sub_a, ROW, COLUMN, 2);

				Enter("按回车键进行新值填充");

				cout << "新值填充后的数组(不同色标识)：" << endl;
				fill(a, sub_a);
				draw(a, sub_a, ROW, COLUMN, 2);

				if (menu == 3) {
					End();
					break;
				}

				else {
					Enter("本次合成结束，按回车键继续新一次的合成");

					if (a_max(a) == goal) {
						cct_setcolor(BG_COLOR, COLOR_RED);
						cout << "恭喜你！你已经圆满完成了自己预订的目标" << goal++ << endl;
						cct_setcolor();
						Enter("按回车键继续向更高目标进发叭");
					}
				}
			}
			if (ch == 'N') {
				if (menu == 3) {
					End();
					break;
				}
				else {
					for (k = 0; k < ROW; k++) {
						for (i = 0; i < COLUMN; i++)
							sub_a[k][i] = '\0';
					}
					continue;
				}
			}
			if (ch == 'Q') {
				cout << endl;
				End();
				break;
			}

		}//end of if(3)
	}//end of while
	return;
}
