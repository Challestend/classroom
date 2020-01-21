# include <bits/stdc++.h>
# include <windows.h>
# define R register int
# define r(a,b) rand()%((b)-(a)+1)+(a)

using namespace std;

const int Max_R=21;
const int Max_C=30;
const int my_x=8;
const int my_y=9;
const int N=100;
int now_x,now_y,s_len,bie_cnt,times,beat_bie_cnt,limit_bie;
int loli_cnt,exist_bie,people_cnt;
int peop[N][N];
char cr[N][N],st[N];
string saying,bie[N],loli[N];

struct people
{
	int rate,cnt;
	int x,y;
	string name;
}p[100];

void get_map()
{
	freopen("map.in","r",stdin);
	scanf("%d",&people_cnt);
	for (R i=1;i<=people_cnt;++i)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		peop[ p[i].x ][ p[i].y ]=i;
		cin>>p[i].name;
	}
    for (R i=1;i<=Max_R;++i)
        scanf("%s",cr[i]+1);
	freopen("CON","r",stdin);
}

void write_map()
{
    for (R i=1;i<=Max_R;++i)
    {
        for (R j=1;j<=Max_C;++j)
        {
            if(i==now_x&&j==now_y) putchar('@');
            else if(cr[i][j]=='$') putchar(' ');
            else if(cr[i][j]=='B') printf("B"); 
            else printf("%c",cr[i][j]);
        }
        printf("\n");
    }
}

void get_bieyu()
{
	freopen("bieyu.in","r",stdin);
	scanf("%d",&bie_cnt);
    for (R i=1;i<=bie_cnt;++i)
		cin>>bie[i];
	freopen("CON","r",stdin);
}

void get_loli()
{
	freopen("loli.in","r",stdin);
	scanf("%d",&loli_cnt);
    for (R i=1;i<=loli_cnt;++i)
		cin>>loli[i];
	freopen("CON","r",stdin);
}

void get_xy (int &x,int &y)
{
	x=r(2,Max_R-1); y=r(2,Max_C-1);
	while((cr[x][y]=='$')||(x==my_x&&y==my_y))
		x=r(2,Max_R-1),y=r(2,Max_C-1);
}

void make_new_bie()
{
	if(exist_bie)
	{
		cout<<"您还没有打完现有的这只鳖呢~"<<endl;
		Sleep(2000);
		return;
	}
	exist_bie=1;
	limit_bie=r(3,5);
	int x,y; get_xy(x,y);
	cr[x][y]='B';
	beat_bie_cnt=0;
	cout<<"您创造了一只新的鳖，开始快乐地打鳖吧！"<<endl; 
	Sleep(2000);
}

void move()
{
	if(cr[ now_x ][ now_y ]=='B')
	{
		cr[ now_x ][ now_y ]='$';
		beat_bie_cnt++;
		int r=r(1,bie_cnt-1);
		if(beat_bie_cnt==limit_bie) r=bie_cnt;
		saying=bie[r];
		cout<<saying<<endl<<endl;
		if(r==bie_cnt) system("bie_1.jpg"),exist_bie=0;
		Sleep(2000);
		if(beat_bie_cnt<limit_bie)
		{
			int x,y; get_xy(x,y);
			cr[x][y]='B';
		}
	}
	else
	{
		int p=r(1,10);
		if(p==1)
		{
			get_loli();
			int r=r(1,loli_cnt);
			cout<<loli[r]<<endl;
			cout<<"路遇loli，您只好回到座位上学习。"<<endl;
			Sleep(2000);
			now_x=my_x; now_y=my_y;
		}
	}
}

int main()
{
	now_x=my_x; now_y=my_y;
    get_map();
    write_map();
    get_bieyu();
    get_loli();
    while(1)
    {
    	int x=0,y=0;
    	scanf("%s",st+1);
		if(st[1]=='w'||st[1]=='a'||st[1]=='s'||st[1]=='d') 
			scanf("%d",&times);
    	if(st[1]=='w') x=now_x-times,y=now_y;
		if(st[1]=='a') x=now_x,y=now_y-times;
		if(st[1]=='s') x=now_x+times,y=now_y;
		if(st[1]=='d') x=now_x,y=now_y+times;
		if(st[1]=='b'&&st[2]=='i'&&st[3]=='e') make_new_bie();
		if(1<x&&x<Max_R&&1<y&&y<Max_C)
		{
			if(cr[x][y]=='$'||cr[x][y]=='_')
			{
				now_x=x,now_y=y,move();
				write_map();
			}
			if(cr[x][y]=='-')
				cout<<"不要在桌子上走."<<endl;
			if(peop[x][y])
				cout<<p[ peop[x][y] ].name<<":\"这是我的位置.\""<<endl; 
		}
		else
		{
			puts("再走就走出去了...");
			Sleep(1000);
		}
	}
    return 0;
}
