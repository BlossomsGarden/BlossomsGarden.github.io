/* 2152189 信04 汪林辉 */
#include <iostream>
#include "90-b2.h"
using namespace std;


/***************************************************************************
  函数名称：tj_strupr
  输入参数：字符串
  作    用：求长度
  特    殊：无
***************************************************************************/
int tj_strlen(const char str[])
{
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

/***************************************************************************
  函数名称：tj_strupr
  输入参数：待转换字符串
  作    用：转小写为大写
  特    殊：无
***************************************************************************/
void tj_strupr(char str[])
{
	int length = tj_strlen(str);
	for (int i = 0; i < length; i++) {
		int n = str[i];
		if (n >= 97 && n <= 122)
			str[i] = (char)(n - 32);
	}
	return;
}

/***************************************************************************
  函数名称：Generate_num
  输入参数：数组的最大值
  作    用：解决了随机值的产生
  特    殊：无
***************************************************************************/
int Generate_num(int maxium)
{
	/*为了无间隔输出随机值，不生成伪随机数的种子*/
	
	int Generated;
	int tmp;
	switch (maxium) {
		case 1:
		case 2:
		case 3:
			Generated = rand() % 3 + 1;
			break;
		case 4:
			tmp = rand() % 10;
			if (tmp == 0)
				Generated = 4;
			else
				Generated = rand() % 3 + 1;
			break;
		case 5:
			tmp = rand() % 20;
			if (tmp == 0 || tmp == 1)  //2除以20的概率
				Generated = 5;
			else {
				if (tmp ==2 || tmp == 3 || tmp == 4)   //3除以20的概率
					Generated = 4;
				else
					Generated = rand() % 3 + 1;
			}
			break;
		case 6:
			tmp = rand() % 20;
			if (tmp == 0)
				Generated = 6;
			else {
				if (tmp == 1||tmp == 2 || tmp == 3)
					Generated = 5;
				else
					Generated = rand()%4+1;
			}
			break;
		default:
			tmp = rand() % 20;
			if (tmp == 0)
				Generated = maxium;
			else {
				if (tmp == 1)
					Generated = maxium - 1;
				else {
					if (tmp == 2 || tmp == 3)
						Generated = maxium - 2;
					else
						Generated = rand() % (maxium - 3) + 1;
				}
			}
	}

	return Generated;
}

/***************************************************************************
  函数名称：a_max
  输入参数：主数组
  作    用：求数组中最大的数
  特    殊：无
***************************************************************************/
int a_max(int a[8][10])
{
	int i, k;
	int max = 0;
	for (k = 0; k < 8; k++)
		for (i = 0; i < 10; i++)
			if (a[k][i] > max)
				max = a[k][i];
	return max;
}

/***************************************************************************
  函数名称：seek_same_1
  输入参数：主数组、附属数组、元素行列坐标(X、Y表示)
  作    用：寻找元素周围相邻且相同的并仅仅进行标记
  特    殊：为菜单1打造的非递归函数
***************************************************************************/
void seek_same_1(int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int X, int Y)
{
	sub_a[X][Y] = '*';
	int big_a[10][12] = { 0 };     //扩张a以便避免边边角角上的XY不能普遍性判断带来的麻烦
	int i, k;
	for (k = 1; k < 9; k++) {
		big_a[k][0] = 0;
		for (i = 1; i < 11; i++)
			big_a[k][i] = a[k - 1][i - 1];
		big_a[k][11] = 0;
	}
	while (1) {
		int count = 0;
		for (k = 0; k < 8; k++) {
			for (i = 1; i < 10; i++) {
				/*跑遍整个附加数组，如果遇到*则执行判断，注意大小数组的坐标不一样，不能混谈*/
				if (sub_a[k][i] == '*') {
					if (big_a[(k+1)+1][i+1] == big_a[k+1][i+1] && sub_a[k + 1][i] != '*') {
						sub_a[k+1][i] = '*';
						count++;
					}
					if (big_a[(k+1)-1][i+1] == big_a[k+1][i+1] && sub_a[k - 1][i] != '*') {
						sub_a[k- 1][i] = '*';
						count++;
					}
					if (big_a[k+1][(i + 1)+1] == big_a[k+1][i+1] && sub_a[k][i + 1] != '*') {
						sub_a[k][i + 1] = '*';
						count++;
					}
					if (big_a[k+1][(i+1) - 1] == big_a[k+1][i+1] && sub_a[k][i - 1] != '*') {
						sub_a[k][i - 1] = '*';
						count++;
					}
				}
			}
		}
		/*说明每个该有*的位置都有了*，即结束*/
		if (count == 0)
			break;
	}
}

/***************************************************************************
  函数名称：seek_same_2
  输入参数：主数组、附属数组、元素行列坐标(X、Y表示)
  作    用：寻找元素周围相邻且相同的并仅仅进行标记
  特    殊：递归函数
***************************************************************************/
void seek_same_2(int a[8][10], char sub_a[8][10], int X, int Y)
{
	sub_a[X][Y] = '*';
	int big_a[10][12] = { 0 };     //扩张a以便避免边边角角上的XY不能普遍性判断带来的麻烦
	int i, k;
	for (k = 1; k < 9; k++) {
		big_a[k][0] = 0;
		for (i = 1; i < 11; i++)
			big_a[k][i] = a[k - 1][i - 1];
		big_a[k][11] = 0;
	}
	/*同时，扩张后记得坐标的不对应性*/
	if (big_a[(X + 1) + 1][Y + 1] == big_a[X + 1][Y + 1] && sub_a[X + 1][Y] != '*')
		seek_same_2(a, sub_a, X + 1, Y);
	if (big_a[(X + 1) - 1][Y + 1] == big_a[X + 1][Y + 1] && sub_a[X - 1][Y] != '*')
		seek_same_2(a, sub_a, X - 1, Y);
	if (big_a[X + 1][(Y + 1) + 1] == big_a[X + 1][Y + 1] && sub_a[X][Y + 1] != '*')
		seek_same_2(a, sub_a, X, Y + 1);
	if (big_a[X + 1][(Y + 1) - 1] == big_a[X + 1][Y + 1] && sub_a[X][Y - 1] != '*')
		seek_same_2(a, sub_a, X, Y - 1);
	return;
}

/***************************************************************************
  函数名称：在框里吗？
  输入参数：数组元素坐标、鼠标坐标
  作    用：寻找元素周围相邻且相同的并仅仅进行标记
  特    殊：递归函数
***************************************************************************/
bool zai_kuang_li_ma(int k,int i,int X,int Y)
{
	if (X <= Coord_X + 5 + 8 * i && X >= Coord_X + 8 * i && Y >= Coord_Y + 4 * k && Y <= Coord_Y + 2 + 4 * k)
		return 1;
	else
		return 0;
}

/***************************************************************************
  函数名称：drop
  输入参数：主数组、附属数组、总行列数、输入的坐标位置
  作    用：将主、副数组跳过0自然下落
  特    殊：无
***************************************************************************/
void drop(int a[8][10], char sub_a[8][10], int ROW, int COLUMN, int X, int Y)
{
	int tmp[8] = { 0 };

	/*类似全局变量的stack在循环中要注意啊！！！！！！，很可能下一次就没置0直接用了！*/
	/*此处不可以（int stack = 0; ）*/
	/*算是二次体会到全局变量为什么不能用了！*/
	/*也因此，为防止for中的循环变量再次使用，在for前一行才定义是个好习惯*/

	int sub_k, i;
	for (i = 0; i < COLUMN; i++) {
		/*两个for必须分开！毕竟你为了提效率用了break!要是同一个for下并列，则sub_a必然执行不到*/

		/*该for语句操作的是a*/
		for (sub_k = 0; sub_k < ROW; sub_k++) {
			int stack = 0;

			if (sub_a[sub_k][i] == '*') {
				int k1;
				for (k1 = 0; k1 < ROW; k1++)
					if (a[k1][i] != 0)
						tmp[stack++] = a[k1][i];
				for (k1 = 0; k1 < ROW; k1++)
					if (k1 < ROW - stack)
						a[k1][i] = 0;
					else
						a[k1][i] = tmp[k1 - (ROW - stack)];
				break;
			}
		}

		/*该for语句操作的是sub_a*/
		for (sub_k = 0; sub_k < ROW; sub_k++) {
			if (sub_a[sub_k][i] == '*') {
				int count = 0;
				/*此k2循环找的是该列*的个数*/
				int k2;
				for (k2 = 0; k2 < ROW; k2++) {
					if (!(k2 == X && i == Y)) {
						if (sub_a[k2][i] == '*')
							count++;
					}
				}
				/*此k3循环是重新赋值sub_a*/
				int k3;
				for (k3 = 0; k3 < ROW; k3++)
					if (k3 < count)
						sub_a[k3][i] = '*';
					else
						sub_a[k3][i] = '\0';

				break;
			}
		}
	}
	return;
}

/***************************************************************************
  函数名称：check
  输入参数：主数组、待查找坐标位置
  作    用：寻找该位置上下左右有几个符合条件
  特    殊：无
***************************************************************************/
int check(int a[8][10], int X, int Y)
{
	int big_a[10][12] = { 0 };     //扩张a以便避免边边角角上的XY不能普遍性判断带来的麻烦
	int i, k;
	for (k = 1; k < 9; k++) {
		big_a[k][0] = 0;
		for (i = 1; i < 11; i++)
			big_a[k][i] = a[k - 1][i - 1];
		big_a[k][11] = 0;
	}

	int count = 0;
	/*同时，扩张后记得坐标的不对应性*/
	if (big_a[(X + 1) + 1][Y + 1] == big_a[X + 1][Y + 1])
		count++;
	if (big_a[(X + 1) - 1][Y + 1] == big_a[X + 1][Y + 1])
		count++;
	if (big_a[X + 1][(Y + 1) + 1] == big_a[X + 1][Y + 1])
		count++;
	if (big_a[X + 1][(Y + 1) - 1] == big_a[X + 1][Y + 1])
		count++;

	return count;
}

/***************************************************************************
  函数名称：score
  输入参数：主数组、附属数组、输入的坐标位置
  作    用：生成归并数组并判断本次合并得分
  特    殊：无
***************************************************************************/
int score(int a[8][10], char sub_a[8][10], int X, int Y)
{
	int k, i;
	int count = 1;     //表示已经提前计算了(X,Y)位置处的那个
	for (k = 0; k < 8; k++) {
		for (i = 0; i < 10; i++) {
			if (!(k == X && i == Y)) {
				if (sub_a[k][i] == '*') {
					a[k][i] = 0;
					count++;
				}
			}
		}
	}
	return count * (a[X][Y]++) * 3;
}

/***************************************************************************
  函数名称：input_RC
  输入参数：矩阵总行数、总列数的地址、目标分数、菜单
  作    用：输入矩阵的总行数、总列数
  特    殊：无
***************************************************************************/
void input_RCG(int* ROW, int* COLUMN, int* goal, int menu)
{
	while (1) {
		cout << "请输入行数(5-8)：" << endl;
		cin >> *ROW;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			if (*ROW <= 8 && *ROW >= 5) {
				cin.ignore(65536, '\n');
				break;
			}
	}

	while (1) {
		cout << "请输入列数(5-10)：" << endl;
		cin >> *COLUMN;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			if (*COLUMN <= 10 && *COLUMN >= 5) {
				cin.ignore(65536, '\n');
				break;
			}
	}

	if (menu == 3 || menu == 4 || menu == 8 || menu == 9) {
		while (1) {
			cout << "请输入合成目标(5-20)：" << endl;
			cin >> *goal;
			if (!cin.good()) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else
				if (*goal <= 20 && *goal >= 5) {
					cin.ignore(65536, '\n');
					break;
				}
		}
	}
	return;
}

/***************************************************************************
  函数名称：input_COORD
  输入参数：行列坐标的地址、总行数、总列数
  作    用：读入键盘上输入的字符串对应矩阵中的坐标
  特    殊：无
***************************************************************************/
void input_COORD(int* rows, int* cols, int ROW, int COLUMN)
{
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	while (1) {
		/*使用的是cin.get,读入时末尾会多加尾零，因此多留一位*/
		/*另外由于有循环使用，好习惯是定义在内部，每次循环开始赋初值为'\0'*/
		char coord[3] = { '\0' };

		/*看似读入了3个字符，实则2个，还有一个'\0'*/
		cin.get(coord, 3, '\n');   
		
		/********************************************************************************************************
		事实：没有这句话，慢慢输入错误无恙，快速输入错误则迅速进入死循环
		猜想：cin.get不会将'\n'读走，因此一旦上一次读入失败，即cin.good9()为0，那么cin.ignore()将罢工，下一次
		      cin.get()一来发现缓冲区里是回车，当即中止，表现为读到EOF且将coord[0]归为'\0',coord[1]不变
		*********************************************************************************************************/
		cin.clear();

		cin.ignore(65536, '\n');
		tj_strupr(coord);
		
		
		*rows = coord[0] - 'A';     //已经有'A'了，字符'0'不减的好啊！
		*cols = coord[1] - '0';     //字符'0'减的好啊！

		if (*rows<0 || *rows>ROW - 1 || *cols<0 || *cols>COLUMN - 1) {
			cout << "输入错误，请重新输入.";
			
			/*下面取光标当前所在位置，目的是不清屏使其重回coord数组的输入部分*/
			int X, Y;
			cct_getxy(X, Y);
			cct_gotoxy(39, Y - 1);
			cout << "                     ";
			cct_gotoxy(39, Y - 1);
		}
		else {
			cout << "输入为" << coord[0] << "行" << coord[1] << "列" << endl;
			break;
		}
	}
	
	return;
}



/***************************************************************************
  函数名称：cover
  输入参数：输入起始坐标
  作    用：每次输出前大一层空格覆盖原有输入
  特    殊：无
***************************************************************************/
void cover(int x, int y)
{
	cct_gotoxy(x, y);
	cout << "                                                                                         ";
	cct_gotoxy(x, y);
}

/***************************************************************************
  函数名称：Enter
  输入参数：提示语
  作    用：提示按回车进行下一步
  特    殊：输入正确后有清屏
***************************************************************************/
void Enter(const char* prompt)
{
	cout << prompt << "...";
	while (_getch() != '\r')
		;
	cout << endl;
}

/***************************************************************************
  函数名称：End
  输入参数：无
  作    用：若输入为End(不分大小写)则退出，否则提示错误并重输
  特    殊：输入正确后有清屏
***************************************************************************/
void End()
{
	cout << "本小题结束，请输入End继续...";

	while (1) {
		char coord[4] = { '\0' };
		cin.get(coord, 4, '\n');
		cin.clear();
		tj_strupr(coord);

		if (coord[0] == 'E' && coord[1] == 'N' && coord[2] == 'D') {
			cin.ignore(65536, '\n');
			cct_cls();
			break;
		}
		else {
			cout << "输入错误，请重新输入.";
			/*下面取光标当前所在位置，目的是不清屏使其重回coord数组的输入部分*/
			int X, Y;
			cct_getxy(X, Y);
			cct_gotoxy(28, Y - 1);
			cout << "                 ";
			cct_gotoxy(28, Y - 1);
			cin.ignore(65536, '\n');
		}
	}
	return;
}
