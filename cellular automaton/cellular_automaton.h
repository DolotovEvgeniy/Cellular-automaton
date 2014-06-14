#include "polish_notation.h"
#define stop 0
#define pause 1
#define play 2
#define NULL 0
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
class Automaton
{
	public:
	int width,height;
	char** now,**last;
	char state;
	int step;
	virtual void Paint(Panel^ panel1,PictureBox ^ pictureBox1,int zoom)
	{
int a;
					if(panel1->Width/width>(panel1->Height)/height)
						a=(panel1->Height)/height;
					else
						a=panel1->Width/width;
					if(a<1)
					{
						a=1;
					}
					a*=zoom;
				/*pictureBox1->Height=height*a;
						 pictureBox1->Width=width*a;
						 pictureBox1->Left=(Width-pictureBox1->Width)/2;
						 if(pictureBox1->Left<0)
							 pictureBox1->Left=0;
						 pictureBox1->Top=(Height-pictureBox1->Height)/2;
						 if(pictureBox1->Top<0)
							 pictureBox1->Top=0;*/
						 Bitmap^ bmp = gcnew Bitmap(width*a,height*a,System::Drawing::Imaging::PixelFormat::Format8bppIndexed);
					 // Draw the modified image.
					 Rectangle rect = Rectangle(0,0,bmp->Width,bmp->Height);
					 System::Drawing::Imaging::BitmapData^ bmpData = bmp->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, bmp->PixelFormat );

					 // Get the address of the first line.
					 IntPtr ptr = bmpData->Scan0;
					 // Declare an array to hold the bytes of the bitmap.
					 // This code is specific to a bitmap with 24 bits per pixels.
					 int bytes = Math::Abs(bmpData->Stride) * bmp->Height;
					 array<Byte>^rgbValues = gcnew array<Byte>(bytes);
					 // Copy the RGB values into the array.
					 System::Runtime::InteropServices::Marshal::Copy( ptr, rgbValues, 0, bytes );
					 // Set every third value to 255.  
					for(int i=0;i<height;i++)
						 for(int j=0;j<width;j++)
						 {
								 for(int k=i*a;k<(i+1)*a;k++)
									 for(int p=j*a;p<(j+1)*a;p++)
									 {
										 rgbValues[ k*Math::Abs(bmpData->Stride)+p ] = 30*now[i][j]*now[i][j];
									 }
						 }
						 if(width<120 && height<120)
						 {
						 for ( int counter = 0; counter <bmp->Width ; counter += a )
							 for(int j=0;j<bmp->Height;j++)
								 rgbValues[ counter+j*Math::Abs(bmpData->Stride) ] = 155;
						 for ( int counter = 0; counter <bmp->Height ; counter += a )
							 for(int j=0;j<bmp->Width;j++)
								 rgbValues[ counter*Math::Abs(bmpData->Stride)+j ] = 155;
						 }
						 // Copy the RGB values back to the bitmap
						 System::Runtime::InteropServices::Marshal::Copy( rgbValues, 0, ptr, bytes );

						 // Unlock the bits.
						 bmp->UnlockBits( bmpData );
						 pictureBox1->BackgroundImage=bmp;
	}

	virtual void NextStep()=0;
	virtual void ShowDescription()=0;
};
class Game_Life:public Automaton
{
public:
	void ShowDescription()
	{
		MessageBox::Show( "Вы выбрали автомат типа \"игра жизнь\" \n"+"Высота поля="+Convert::ToString(height)+"\n"+"Ширина поля="+Convert::ToString(width), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	Game_Life()
	{
		state=pause;
		step=0;
		width=20;
		height=20;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 now[2][15]=1;
					 now[2][16]=1;
					 now[3][15]=1;
					 now[3][16]=1;
					 now[6][5]=1;
					 now[7][6]=1;
					 now[8][4]=1;
					 now[8][5]=1;
					 now[8][6]=1;
					 now[9][14]=1;
					 now[10][15]=1;
					 now[11][16]=1;
					 for(int i=0;i<20;i++)
						 now[17][i]=1;
	}
	Game_Life(int _width,int _height,bool generator=true)
	{
		state=pause;
		step=0;
		width=_width;
		height=_height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 if(generator)
					 {
		Random^ rnd = gcnew Random();
		int time=(rnd->Next()%(width*height));
					 for(int j=0;j<time;j++)
					 {
						 now[rnd->Next()%height][rnd->Next()%width]=rnd->Next()%2;
					 }
					 }
		
	}
	Game_Life& operator=(const Game_Life& newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
		return *this;
	}
	Game_Life(const Game_Life & newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
	}
	~Game_Life()
	{
		if(now!=NULL)
		delete [] now;
		if(last!=NULL)
		delete [] last;
	}
	void NextStep()
	{
		//step++;
		char** temp=last;
		last=now;
		now=temp;
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			{
				int count=0;
				count+=last[(height+i-1)%height][(width+j-1)%width];
				count+=last[(height+i-1)%height][(width+j)%width];
				count+=last[(height+i-1)%height][(width+j+1)%width];
				count+=last[(height+i)%height][(width+j-1)%width];
				count+=last[(height+i)%height][(width+j+1)%width];
				count+=last[(height+i+1)%height][(width+j-1)%width];
				count+=last[(height+i+1)%height][(width+j)%width];
				count+=last[(height+i+1)%height][(width+j+1)%width];
				if(last[i][j]==0 && count==3)
				{
					now[i][j]=1;
				}
				if(last[i][j]==0 && count!=3)
				{
					now[i][j]=0;
				}


				if(last[i][j]==1 && (count==3 || count==2 ))
				{
					now[i][j]=1;
				}
				if(last[i][j]==1 && (count>3 || count<2 ))
				{
					now[i][j]=0;
				}
			}
	}
};

class Cyclical_Automaton:public Automaton
	{
	public:
		void ShowDescription()
	{
		MessageBox::Show( "Вы выбрали циклический автомат \n"+"Высота поля="+Convert::ToString(height)+"\n"+"Ширина поля="+Convert::ToString(width), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	Cyclical_Automaton()
	{
		state=pause;
		step=0;
		width=20;
		height=20;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 now[1][1]=0;
					 now[1][2]=1;
					 now[1][3]=2;
					 now[1][4]=3;
					 now[1][5]=4;
					 now[1][6]=5;
					 now[1][7]=6;
					 now[1][8]=7;
	}
	Cyclical_Automaton(int _width,int _height,bool generator=true)
	{

		state=pause;
		step=0;
		width=_width;
		height=_height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 if(generator)
					 {
						 Random^ rnd = gcnew Random();
						 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=rnd->Next()%8;
					 }
					 }
					 else
					 {
						 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 }
		
	}
		void NextStep()
	{
		//step++;
		char** temp=last;
		last=now;
		now=temp;
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			{
				char k=(last[(height+i)%height][(width+j)%width]+1)%8;
				int w=width,h=height;
				if(last[(h+i-2)%h][(w+j)%w]==k)
				{
					now[i][j]=k;
					continue;
				}
				if(last[(h+i-1)%h][(w+j-1)%w]==k||last[(h+i-1)%h][(w+j)%w]==k||last[(h+i-1)%h][(w+j+1)%w]==k)
				{
					now[i][j]=k;
					continue;
				}
				if(last[(h+i)%h][(w+j-2)%w]==k||last[(h+i)%h][(w+j-1)%w]==k||last[(h+i)%h][(w+j+1)%w]==k||last[(h+i)%h][(w+j+2)%w]==k)
				{
					now[i][j]=k;
					continue;
				}
				if(last[(h+i+1)%h][(w+j-1)%w]==k||last[(h+i+1)%h][(w+j)%w]==k||last[(h+i+1)%h][(w+j+1)%w]==k)
				{
					now[i][j]=k;
					continue;
				}
				if(last[(h+i+2)%h][(w+j)%w]==k)
				{
					now[i][j]=k;
					continue;
				}
				now[i][j]=last[i][j];
			}
	}

};

class Binary_Automaton:public Automaton
{
public:
	polishNotation str;
	void ShowDescription()
	{
		MessageBox::Show( "Вы выбрали бинарный автомат, поведение которого задается формулой \n"+"Высота поля="+Convert::ToString(height)+"\n"+"Ширина поля="+Convert::ToString(width), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	Binary_Automaton()
	{
		if(!str.makeNotation("(y[0,0]^((y[-1,0]&y[1,0])|(y[0,-1]&y[0,1])))"))
			MessageBox::Show( "Dequeue is empty!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		state=pause;
		step=0;
		width=20;
		height=20;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 now[2][15]=1;
					 now[2][16]=1;
					 now[3][15]=1;
					 now[3][16]=1;
					 now[6][5]=1;
					 now[7][6]=1;
					 now[8][4]=1;
					 now[8][5]=1;
					 now[8][6]=1;
					 now[9][14]=1;
					 now[10][15]=1;
					 now[11][16]=1;
					 for(int i=0;i<20;i++)
						 now[17][i]=1;
	}
	Binary_Automaton(int _width,int _height,String^ mystr,bool generator=true)
	{
		str.makeNotation(mystr);
		state=pause;
		step=0;
		width=_width;
		height=_height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 if(generator)
					 {
		Random^ rnd = gcnew Random();
		int time=(rnd->Next()%(width*height));
					 for(int j=0;j<time;j++)
					 {
						 now[rnd->Next()%height][rnd->Next()%width]=rnd->Next()%2;
					 }
					 }
		
	}
	Binary_Automaton& operator=(const Binary_Automaton& newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
		return *this;
	}
	Binary_Automaton(const Binary_Automaton& newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
	}
	~Binary_Automaton()
	{
		if(now!=NULL)
		delete [] now;
		if(last!=NULL)
		delete [] last;
	}
	void NextStep()
	{
		//step++;
		char** temp=last;
		last=now;
		now=temp;
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			{
				now[i][j]=str.Calculate(last,width,height,j,i);
			}
	}
};
class AutomatonWithSpecialRule:public Automaton
{
public:
	void ShowDescription()
	{
		MessageBox::Show( "Вы выбрали автомат со следующим правилом: \nКлетка переходит в состояние 1, только если в её окрестности есть ровно одна клетка в состоянии 1.\n"+"Высота поля="+Convert::ToString(height)+"\n"+"Ширина поля="+Convert::ToString(width), "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	AutomatonWithSpecialRule()
	{
		state=pause;
		step=0;
		width=20;
		height=20;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
					 }
					 now[2][15]=1;
					 now[2][16]=1;
					 now[3][15]=1;
					 now[3][16]=1;
					 now[6][5]=1;
					 now[7][6]=1;
					 now[8][4]=1;
					 now[8][5]=1;
					 now[8][6]=1;
					 now[9][14]=1;
					 now[10][15]=1;
					 now[11][16]=1;
					 for(int i=0;i<20;i++)
						 now[17][i]=1;
	}
	AutomatonWithSpecialRule(int _width,int _height,bool generator=true)
	{
		state=pause;
		step=0;
		width=_width;
		height=_height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=0;
						 last[i][j]=0;
					 }
					 if(generator)
					 {
		Random^ rnd = gcnew Random();
		int time=(rnd->Next()%(width*height));
					 for(int j=0;j<time;j++)
					 {
						 int y=rnd->Next()%height;
						 int x=rnd->Next()%width;
						 now[y][x]=last[y][x]=rnd->Next()%2;
						 
					 }
					 }
		
	}
	AutomatonWithSpecialRule& operator=(const AutomatonWithSpecialRule& newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
		return *this;
	}
	AutomatonWithSpecialRule(const AutomatonWithSpecialRule& newlife)
	{
		step=newlife.step;
		state=newlife.state;
		delete [] now;
		delete [] last;
		width=newlife.width;
		height=newlife.height;
		now=new char*[height];
		for(int i=0;i<height;i++)
			now[i]=new char[width];
		last=new char*[height];
		for(int i=0;i<height;i++)
			last[i]=new char[width];
		 for(int i=0;i<height;i++)
					 for(int j=0;j<width;j++)
					 {
						 now[i][j]=newlife.now[i][j];
						 last[i][j]=newlife.last[i][j];
					 }
	}
	~AutomatonWithSpecialRule()
	{
		if(now!=NULL)
		delete [] now;
		if(last!=NULL)
		delete [] last;
	}
	void NextStep()
	{
		//step++;
		char** temp=last;
		last=now;
		now=temp;
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			{
				int w=width,h=height;
				int sum=last[(h+i-2)%h][(w+j)%w]+last[(h+i-1)%h][(w+j-1)%w]+last[(h+i-1)%h][(w+j)%w]+last[(h+i-1)%h][(w+j+1)%w]+last[(h+i)%h][(w+j-2)%w]+last[(h+i)%h][(w+j-1)%w]+last[(h+i)%h][(w+j)%w]+last[(h+i)%h][(w+j+1)%w]+last[(h+i)%h][(w+j+2)%w]+last[(h+i+1)%h][(w+j-1)%w]+last[(h+i+1)%h][(w+j)%w]+last[(h+i+1)%h][(w+j+1)%w]+last[(h+i+2)%h][(w+j)%w];
				if(sum==1)
					now[i][j]=1;
				else
					now[i][j]=last[i][j];

			}
	}
};