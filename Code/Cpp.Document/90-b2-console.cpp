/* 2152189 信04 汪林辉 */
#include <iostream>
#include "90-b2.h"
using namespace std;


/***************************************************************************
  函数名称：in_this_kuang_ma
  输入参数：数组坐标、鼠标坐标
  作    用：输入鼠标坐标判断是否在所给数组坐标里
  特    殊：无
***************************************************************************/
bool in_this_kuang_ma(int k, int i, int X, int Y)
{
	if (X <= Coord_X + 5 + 8 * i && X >= Coord_X + 8 * i && Y >= Coord_Y + 4 * k && Y <= Coord_Y + 2 + 4 * k)
		return 1;
	else
		return 0;
}
/***************************************************************************
  函数名称：in_kuang_ma
  输入参数：总行列数、鼠标坐标
  作    用：输入鼠标坐标判断是否在某个框里
  特    殊：无
***************************************************************************/
bool in_kuang_ma(int ROW, int COLUMN, int X, int Y)
{
	int k, i;
	for (k = 0; k < ROW; k++) {
		for (i = 0; i < COLUMN; i++) {
			if (in_this_kuang_ma(k, i, X, Y)) {
				return 1;
			}
		}
	}
	return 0;
}
/***************************************************************************
  函数名称：在哪个框？
  输入参数：总行列数、鼠标坐标、记录框横纵坐标的指针
  作    用：“在框里”之后进一步知道在哪个框
  特    殊：无
***************************************************************************/
void in_which_huang(int ROW, int COLUMN, int X, int Y, int* Record_X, int* Record_Y)
{
	int k, i;
	for (k = 0; k < ROW; k++) {
		for (i = 0; i < COLUMN; i++) {
			if (in_this_kuang_ma(k, i, X, Y)) {
				*Record_X = k;
				*Record_Y = i;
				return;
			}
		}
	}
	return;
}



/***************************************************************************
  函数名称：图形数组变色
  输入参数：主数组、待变色数组元素的坐标
  作    用：控制参数使该数字变不同的色
  特    殊：draw为0：变色刷；draw为1：恢复原色；draw为2：刷白
***************************************************************************/
void bian_se(int num, int X, int Y, int draw)
{
	if (draw == 0)              //选择时变色
		picture(num, Coord_X + 8 * Y, Coord_Y + 4 * X, num, COLOR_WHITE);
	else
		if (draw == 1)          //恢复原色
			picture(num, Coord_X + 8 * Y, Coord_Y + 4 * X, num, COLOR_BLACK);
		else                    //刷白
			picture(num, Coord_X + 8 * Y, Coord_Y + 4 * X, COLOR_HWHITE, COLOR_HWHITE);
	return;
}

/***************************************************************************
  函数名称：deluxe_draw
  输入参数：主数组、附属数组、主数组的行数、主数组的列数
  作    用：传入数组打印奢华版图形界面
  特    殊：draw为0无分割线；否则有分割线
***************************************************************************/
void deluxe_draw(int a[8][10], int ROW, int COLUMN, int draw)
{
	int i, k;
	if (draw == 0) {
		/*屏幕准备*/
		if (1) {
			/*多两行为空白需要，多6行为上下黑底；多4列为白框需要，多5列为左右黑底*/
			cct_setconsoleborder(6 * COLUMN + 4 + 5, 3 * ROW + 2 + 6);
			cout << "屏幕当前设置为：" << 3 * ROW + 2 + 6 << "行" << 6 * COLUMN + 4 + 5 << "列" << endl;
		}
		/*打底*/
		if (1) {
			/*首行*/
			cout << ' ' << ' ';
			for (i = 0; i < COLUMN; i++)
				cout << setw(6) << i;
			cout << endl;
			/*二行*/
			cout << ' ' << ' ' << ' ';
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "┏";
			for (i = 1; i <= 3 * COLUMN; i++) {
				cout << "━";
				if (i % 3 == 0)
					Sleep(1);
			}
			cout << "┓";
			cct_setcolor();
			cout << endl;
			/*中间*/
			for (k = 1; k <= 3 * ROW; k++) {
				if (k % 3 == 2)
					cout << ' ' << (char)('A' + k / 3) << ' ';
				else
					cout << ' ' << ' ' << ' ';

				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
				cout << "┃";
				for (i = 1; i <= 3 * COLUMN; i++) {
					cout << ' ' << ' ';
					if (i % 3 == 0)
						Sleep(1);
				}
				cout << "┃";
				cct_setcolor();
				cout << endl;
			}
			/*末行*/
			cout << ' ' << ' ' << ' ';
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "┗";
			for (i = 1; i <= 3 * COLUMN; i++) {
				cout << "━";
				if (i % 3 == 0)
					Sleep(1);
			}
			cout << "┛";
			cct_setcolor();
			cout << endl;
		}
		/*画数字*/
		for (k = 0; k < ROW; k++)
			for (i = 0; i < COLUMN; i++)
				picture(a[k][i], Coord_X + 6 * i, Coord_Y + 3 * k, a[k][i], COLOR_BLACK);
	}
	else {
		/*屏幕准备*/
		if (1) {
			/*多两行为空白需要，多6行为上下黑底；多4列为白框需要，多5列为左右黑底*/
			cct_setconsoleborder(6 * COLUMN + 2 * (COLUMN - 1) + 4 + 5, 3 * ROW + (ROW - 1) + 2 + 6);
			cout << "屏幕当前设置为：" << 3 * ROW + (ROW - 1) + 2 + 6 << "行" << 6 * COLUMN + 2 * (COLUMN - 1) + 4 + 5 << "列" << endl;
		}
		/*打底*/
		if (1) {
			/*首行*/

			for (i = 0; i < COLUMN; i++)
				cout << setw(8) << i;
			cout << endl;
			/*二行*/
			cout << ' ' << ' ' << ' ';
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "┏";
			for (i = 1; i <= 3 * COLUMN + (COLUMN - 1); i++) {
				if (i % 4 == 0)
					cout << "┳";
				else
					cout << "━";
				if (i % 3 == 0)
					Sleep(1);
			}
			cout << "┓";
			cct_setcolor();
			cout << endl;

			/*中间*/
			for (k = 1; k <= 3 * ROW + (ROW - 1); k++) {
				if (k % 4 == 2)
					cout << ' ' << (char)('A' + k / 4) << ' ';
				else
					cout << ' ' << ' ' << ' ';

				cct_setcolor(COLOR_HWHITE, COLOR_BLACK);

				if (k % 4 == 0) {
					cout << "┣";
					/*此处要的是打几个横杠，不要管横杠占几个字节*/
					for (i = 1; i <= 3 * COLUMN + (COLUMN - 1); i++) {
						if (i % 4 == 0)
							cout << "╋";
						else
							cout << "━";
						if (i % 3 == 0)
							Sleep(1);
					}
					cout << "┫";
					cct_setcolor();
					cout << endl;
				}
				else {
					cout << "┃";
					for (i = 1; i <= 3 * COLUMN + (COLUMN - 1); i++) {
						if (i % 4 == 0)
							cout << "┃";
						else
							cout << ' ' << ' ';
						if (i % 3 == 0)
							Sleep(1);
					}
					cout << "┃";
					cct_setcolor();
					cout << endl;
				}
			}
			/*末行*/
			cout << ' ' << ' ' << ' ';
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "┗";
			for (i = 1; i <= 3 * COLUMN + (COLUMN - 1); i++) {
				if (i % 4 == 0)
					cout << "┻";
				else
					cout << "━";
				Sleep(1);
			}
			cout << "┛";
			cct_setcolor();
			cout << endl;
		}
		/*画数字*/
		for (k = 0; k < ROW; k++)
			for (i = 0; i < COLUMN; i++)
				picture(a[k][i], Coord_X + 8 * i, Coord_Y + 4 * k, a[k][i], COLOR_BLACK);
	}
	return;
}

/***************************************************************************
  函数名称：picture
  输入参数：待显示数字、待涂色坐标、背景颜色、前景颜色
  作    用：把数字用颜色框起来
  特    殊：前景颜色有默认参数
***************************************************************************/
void picture(int num, int X, int Y, int bg_color, int fg_color)
{
	cct_setcolor(bg_color, fg_color);
	cct_gotoxy(X, Y);
	cout << "┏━┓";
	cct_gotoxy(X, Y + 1);
	cout << "┃" << setw(2) << setiosflags(ios::left) << num << resetiosflags(ios::left) << "┃";
	cct_gotoxy(X, Y + 2);
	cout << "┗━┛";
	cct_setcolor();
	return;
}

/***************************************************************************
  函数名称：deluxe_fill
  输入参数：主数组、总行列数
  作    用：奢华版为图形填充数字
  特    殊：无
***************************************************************************/
void deluxe_fill(int a[8][10], int ROW, int COLUMN)
{
	int k, i;
	for (k = 0; k < ROW; k++) {
		for (i = 0; i < COLUMN; i++) {
			if (a[k][i] == 0) {
				a[k][i] = Generate_num(a_max(a));
				bian_se(a[k][i], k, i, 1);
			}
		}
	}
	return;
}

/***************************************************************************
  函数名称：disappear
  输入参数：主数组、附属数组、所选行列数
  作    用：将附近相等的框框刷白，自己闪烁
  特    殊：无
***************************************************************************/
void disappear(int a[8][10], char sub_a[8][10], int X, int Y)
{
	int k, i;
	/*刷白*/
	for (k = 0; k < 8; k++) {
		for (i = 0; i < 10; i++) {
			if (sub_a[k][i] == '*')
				bian_se(a[k][i], k, i, 2);
		}
		Sleep(1);
	}
	/*闪烁*/
	for (i = 1; i <= 30; i++) {
		bian_se(a[X][Y], X, Y, 1);
		Sleep(5);
		bian_se(a[X][Y], X, Y, 0);
		Sleep(5);
		bian_se(a[X][Y], X, Y, 1);
	}

	return;
}

void diao_xia_lai(int num, int row1, int row2, int col)
{
	int X;
	int Y = col;
	for (X = row1; X < row2; X++) {
		/*此时第一个参数不能再使用数组a啦！*/
		bian_se(num, X, Y, 2);
		bian_se(num, X + 1, Y, 1);
		Sleep(50);
	}
	return;
}

/***************************************************************************
  函数名称：deluxe_drop
  输入参数：主数组、总行列数
  作    用：营造下落美景
  特    殊：无
***************************************************************************/
void deluxe_drop(int a[8][10], int ROW, int COLUMN)
{
	int k1, k2, i;
	int row1, row2;
	for (i = 0; i < COLUMN; i++) {
		for (k1 = 0; k1 < ROW; k1++) {
			/*全0行是不存在的，但这样可以找到第一个非零对应的纵坐标，上面有0我不用管*/
			if (a[k1][i] != 0) {
				int count = 1;
				for (k2 = k1; k2 < ROW; k2++)
					count *= a[k2][i];
				//若正确，则已满足下落条件了
				if (count != 0)
					break;
				//若不正确，接着递，接着掉
				else {
					for (row2 = ROW - 1; row2 > k1; row2--) {
						if (a[row2][i] == 0)                             //找到那从下面数起第一个0（必然存在），作为下落终止点
							break;
					}

					for (row1 = row2; row1 >= k1; row1--) {              //找到从下往上第一个零上面的第一个非零（也必然存在），作为下落起始点
						if (a[row1][i] != 0)
							break;
					}
					diao_xia_lai(a[row1][i], row1, row2, i);

					/*手动赋了新值再递归*/
					a[row2][i] = a[row1][i];                            //函数里row1row2变换不影响外部，仍可以如此赋值
					a[row1][i] = 0;

					deluxe_drop(a, ROW, COLUMN);
				}
			}
		}
	}
	return;
}

void choose_what_coord(int a[8][10], int ROW, int COLUMN, int Record_X, int Record_Y, int times, int* finally_choice_X, int* finally_choice_Y, int* Q_or_not)
{
	int X1, Y1;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int disable_LEFT_CLICK = 0;

	while (loop) {
		X1 = 0;
		Y1 = 0;

		ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			if (times == 1) {
				if (in_kuang_ma(ROW, COLUMN, X1, Y1)) {
					bian_se(a[0][0], 0, 0, 1);
					in_which_huang(ROW, COLUMN, X1, Y1, &Record_X, &Record_Y);
					times++;
					continue;
				}
			}
			else {
				if (in_kuang_ma(ROW, COLUMN, X1, Y1)) {
					bian_se(a[Record_X][Record_Y], Record_X, Record_Y, 1);
					in_which_huang(ROW, COLUMN, X1, Y1, &Record_X, &Record_Y);
					cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
					cout << "[当前鼠标] " << (char)('A' + Record_X) << "行" << Record_Y << "列";
					bian_se(a[Record_X][Record_Y], Record_X, Record_Y, 0);
					disable_LEFT_CLICK = 0;
				}
				else {
					bian_se(a[Record_X][Record_Y], Record_X, Record_Y, 1);
					cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
					cout << "[当前鼠标] 位置非法";
					disable_LEFT_CLICK = 1;
				}
			}

			/*为防止在非法位置左键会按上一次的按键进行框框变色，引入是否使左键失效按钮*/
			if (!disable_LEFT_CLICK) {
				if (maction == MOUSE_LEFT_BUTTON_CLICK) {			//按下左键
					if (times == 0) {
						cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
						cct_setcolor(COLOR_BLACK, COLOR_HCYAN);
						cout << "选中了" << (char)('A' + Record_X) << "行" << Record_Y << "列";
						cct_setcolor();
					}
					loop = 0;
				}
			}
		}
		else
			if (ret == CCT_KEYBOARD_EVENT) {
				int tmp_X = Record_X;
				int tmp_Y = Record_Y;

				switch (keycode1) {
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:         //上箭头
								if (Record_X > 0)
									Record_X--;
								else
									Record_X = ROW - 1;
								break;
							case KB_ARROW_DOWN:       //下箭头
								if (Record_X < ROW - 1)
									Record_X++;
								else
									Record_X = 0;
								break;
							case KB_ARROW_LEFT:       //左箭头
								if (Record_Y > 0)
									Record_Y--;
								else
									Record_Y = COLUMN - 1;
								break;
							case KB_ARROW_RIGHT:      //右箭头
								if (Record_Y < COLUMN - 1)
									Record_Y++;
								else
									Record_Y = 0;
								break;
						}
						/*目的就是真正读到了移动键盘才覆盖上一次，防止瞎按都变色或下面check时不通过跳回该函数后所指向行的变色会莫名消失*/
						bian_se(a[tmp_X][tmp_Y], tmp_X, tmp_Y, 1);
						cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
						cout << "[当前键盘] " << (char)('A' + Record_X) << "行" << Record_Y << "列";
						bian_se(a[Record_X][Record_Y], Record_X, Record_Y, 0);
						break;

					case 13:	                      //回车键
						if (times == 0) {
							cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
							cct_setcolor(COLOR_BLACK, COLOR_HCYAN);
							cout << "选中了" << (char)('A' + Record_X) << "行" << Record_Y << "列";
							cct_setcolor();
						}
						loop = 0;
						break;

					case 81:
					case 113:
						loop = 0;
						*Q_or_not = 1;
						break;
					default:
						break;
				}
			}
	}

	*finally_choice_X = Record_X;
	*finally_choice_Y = Record_Y;
}

/***************************************************************************
  函数名称：pause
  输入参数：总行数、提示语句、键码
  作    用：按左键或键盘继续（缺省为回车）
  特    殊：“回车”为13，“C”为67
***************************************************************************/
void pause(int ROW, const char* prompt, bool Enter)
{
	cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
	cout << prompt;

	int X1, Y1;
	int ret, maction;
	int keycode1, keycode2;

	while (1) {
		ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			if (maction == MOUSE_LEFT_BUTTON_CLICK) {			//按下左键
				break;
			}
		}
		else
			if (ret == CCT_KEYBOARD_EVENT)
				if (Enter) {
					if (keycode1 == 13)
						break;
				}
				else
					if (keycode1 == 67 || keycode1 == 99)
						break;
	}
	return;
}

/***************************************************************************
  函数名称：deluxe_pre
  输入参数：输入的菜单数5~9
  作    用：主要框架的搭建
  特    殊：无
***************************************************************************/
void deluxe_pre(int menu, int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int goal)
{
	int Record_X = 0, Record_Y = 0;             //用以记录落在数组哪个元素框内

	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);

	deluxe_draw(a, ROW, COLUMN, menu - 5);      //菜单5参数为0,其余均非0

	if (menu < 7) {
		int position_X = (menu == 5 ? (3 * ROW + 2 + 3) : (3 * ROW + ROW - 1 + 2 + 3));
		cover(0, position_X);
		End();
	}
	else {
		int choose_X = 0, choose_Y = 0;
		int Q_or_not = 0;
		int times = 1;
		bian_se(a[Record_X][Record_Y], Record_X, Record_Y, 0);
		cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
		cout << "箭头键/鼠标移动，回车键/单击鼠标左键选择并结束";

		if (menu == 7) {
			choose_what_coord(a, ROW, COLUMN, Record_X, Record_Y, 0, &choose_X, &choose_Y, &Q_or_not);
			cct_gotoxy(0, 3 * ROW + (ROW - 1) + 2 + 3);
			End();
		}
		else {
			int fenshu = 0;
			int zongfen = 0;


			while (!Q_or_not) {
				int k, i;
				for (k = 0; k < ROW; k++)
					for (i = 0; i < COLUMN; i++)
						sub_a[k][i] = '\0';


				/*判断游戏结束*/
				if (over(a, ROW, COLUMN)) {
					cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
					cct_setcolor(BG_COLOR, COLOR_RED);
					cout << "真可惜，没有可合并的项了，游戏结束！" << endl;
					cct_setcolor();
					End();
					break;
				}

				while (1) {
					choose_what_coord(a, ROW, COLUMN, Record_X, Record_Y, times, &choose_X, &choose_Y, &Q_or_not);
					times++;

					if (Q_or_not) {
						cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
						cover(0, 3 * ROW + (ROW - 1) + 2 + 3);
						End();
						return;
					}
					else {
						if (check(a, choose_X, choose_Y)) {
							seek_same_2(a, sub_a, choose_X, choose_Y);
							int k, i;
							for (k = 0; k < ROW; k++) {
								for (i = 0; i < COLUMN; i++) {
									if (sub_a[k][i] == '*') {
										bian_se(a[k][i], k, i, 0);
									}
								}
								Sleep(1);
							}

							cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
							cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";

							int out = 0;
							int loop = 1;
							int press_keyboard = 0;

							/*loop的使用为内循环跳出外循环提供了一个解决的好办法*/
							while (loop) {
								int X1, Y1;
								int ret, maction;
								int keycode1, keycode2;

								ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);

								if (ret == CCT_MOUSE_EVENT) {
									if (in_this_kuang_ma(choose_X, choose_Y, X1, Y1)) {

										if (maction == MOUSE_LEFT_BUTTON_CLICK) {
											loop = 0;
											out = 1;     //又在框里又点了左键，跳出两个循环
											break;
										}

									}
									else {
										loop = 0;      //移出框框，跳出loop循环continue
										break;
									}
								}
								else
									/*我估摸着Record_X即使针对整个main但完成choose函数后依然清零了,因此不用Record_来计步*/
									if (ret == CCT_KEYBOARD_EVENT) {
										switch (keycode1) {
											case 224:
												switch (keycode2) {
													case KB_ARROW_UP:         //上箭头
														if (choose_X > 0)
															choose_X--;
														else
															choose_X = ROW - 1;
														break;
													case KB_ARROW_DOWN:       //下箭头
														if (choose_X < ROW - 1)
															choose_X++;
														else
															choose_X = 0;
														break;
													case KB_ARROW_LEFT:       //左箭头
														if (choose_Y > 0)
															choose_Y--;
														else
															choose_Y = COLUMN - 1;
														break;
													case KB_ARROW_RIGHT:      //右箭头
														if (choose_Y < COLUMN - 1)
															choose_Y++;
														else
															choose_Y = 0;
														break;
												}
												/*表示按下后以正常方式对待，但立即跳出loop循环contiue*/
												cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
												cout << "[当前键盘] " << (char)('A' + choose_X) << "行" << choose_Y << "列";
												bian_se(a[choose_X][choose_Y], choose_X, choose_Y, 0);

												/*为保证循环性，此处赋这次移动的值给Record，以无缝进行下一次循环*/
												Record_X = choose_X;
												Record_Y = choose_Y;

												press_keyboard = 1;
												loop = 0;
												break;

											case 13:	                      //回车键
												loop = 0;
												out = 1;     //没有其他动作的按下回车，认为是选定了，跳出两个循环
												break;

											case 81:
											case 113:
												cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
												cover(0, 3 * ROW + (ROW - 1) + 2 + 3);
												End();
												return;
										}
									}
							}

							if (out)
								break;
							else {
								/*先恢复颜色，再全部置零*/
								for (k = 0; k < ROW; k++)
									for (i = 0; i < COLUMN; i++) {
										bian_se(a[k][i], k, i, 1);
										sub_a[k][i] = '\0';
									}
								/*此时即使键盘移动，也被刷掉了，补回来*/
								if (press_keyboard)
									bian_se(a[choose_X][choose_Y], choose_X, choose_Y, 0);
								continue;
							}
						}

						else {         //没相同值，check不过的情况
							cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
							cct_setcolor(COLOR_BLACK, COLOR_HCYAN);
							cout << "当前数字周围无相同值哦，请再试一次叭~";
							cct_setcolor();

							/*为保证循环性，此处赋这次移动的值给Record，以无缝进行下一次循环*/
							Record_X = choose_X;
							Record_Y = choose_Y;

							/*为保证“无相同值哦”留住直到下一次操作，times==1*/
							times = 1;
						}
					}
				}

				fenshu = score(a, sub_a, choose_X, choose_Y);
				zongfen += fenshu;
				cover(0, 0);
				cout << "本次得分:" << fenshu << ' ' << "总分:" << zongfen << ' ' << "合成目标:" << goal;

				disappear(a, sub_a, choose_X, choose_Y);

				if (menu == 8)
					pause(ROW, "合成完成，回车键/单击左键下落", 1);

				deluxe_drop(a, ROW, COLUMN);

				if (menu == 8)
					pause(ROW, "下落完成，回车键/单击左键填充新值", 1);

				deluxe_fill(a, ROW, COLUMN);

				if (menu == 8)
					pause(ROW, "本次合成结束按C键/单击左键进行新一次的合成", 0);

				if (menu == 8) {
					cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
					cct_gotoxy(0, 3 * ROW + (ROW - 1) + 2 + 3);
					End();
					break;
				}


				if (a_max(a) == goal) {
					cover(0, 3 * ROW + (ROW - 1) + 2 + 2);
					cct_setcolor(BG_COLOR, COLOR_RED);
					cout << "恭喜你！你已经圆满完成了自己预订的目标" << goal++ << endl;
					cct_setcolor();
					Enter("按回车键继续向更高目标进发叭");
					cover(0, 3 * ROW + (ROW - 1) + 2 + 3);
				}
			}
		}
	}
	return;
}
