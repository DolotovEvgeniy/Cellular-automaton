#include <string>
#include "operand.h"
using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	void donumber(int &x,wchar_t num)
	{

		x*=10;
		switch (num) {
		case '0':
			x+=0;
			break;
		case '1':
			x+=1;
			break;
		case '2':
			x+=2;
			break;
		case '3':
			x+=3;
			break;
		case '4':
			x+=4;
			break;
		case '5':
			x+=5;
			break;
		case '6':
			x+=6;
			break;
		case '7':
			x+=7;
			break;
		case '8':
			x+=8;
			break;
		case '9':
			x+=9;
			break;
		default:
			int i=-1;
			throw i;
			break;
		}
	}
	bool IsMySymbol(wchar_t one)
	{
		switch (one) {
		case '0':
		return true;
			case '-':
			return true;
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		case 'y':
			return true;
		case '[':
			return true;
		case ']':
			return true;
		case '(':
			return true;
		case ')':
			return true;
		case '&':
			return true;
		case '|':
			return true;
		case '^':
			return true;
		case '~':
			return true;
			case ',':
			return true;
			case 8:
			return true;
		default:
			return false;
		}
	}
	bool IsNumber(wchar_t one)
	{
		switch (one) {
		case '0':
			return true;
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		default:
			return false;
		}
	}
	bool IsBadUnion(wchar_t one,wchar_t two)
	{
		if(one=='~'&&two=='~')
			return false;
		if((one=='^'||one=='|'||one=='&'||one=='~')&&(two=='^'||two=='|'||two=='&'))
			return true;
		if(one=='y'&&two!='[')
			return true;
		if(one=='['&&!IsNumber(two)&&two!='-')
			return true;
		if((IsNumber(one)||one=='-')&&two=='-')
			return true;
		if(one=='-'&&!IsNumber(two))
			return true;
		if(!IsNumber(one)&&two==']')
			return true;
		return false;
	}
	bool IsOnlyContentOfBracket(wchar_t one)
	{
		switch (one) {
		case '2':
			return true;
			case '-':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		case ',':
			return true;
		default:
			return false;
		}
	}
	bool IsOnlyLogic(wchar_t one)
	{
	switch (one) {
		case '(':
			return true;
		case ')':
			return true;
		case '&':
			return true;
		case '|':
			return true;
		case '^':
			return true;
		case '~':
			return true;
		default:
			return false;
	}
	}
	class polishNotation
	{public:
	int strsize;
	Operand* str;
	polishNotation(const polishNotation & notat)
	{
		strsize=notat.strsize;
		str=new Operand[strsize];
		for(int i=0;i<strsize;i++)
		{
			str[i]=notat.str[i];
		}
	}
	polishNotation()
	{
		strsize=0;
	}
	bool makeNotation(String^ mystring)
	{
		int size=mystring->Length;
		MyStack<Operand> opstack;
		str=new Operand[size];
		strsize=0;
		if(mystring[0]=='^'||mystring[0]=='&'||mystring[0]=='|')
			return false;
		if(mystring[size-1]=='^'||mystring[size-1]=='&'||mystring[size-1]=='|'||mystring[size-1]=='~')
			return false;
		bool isopenquadbracket=false;
		int countcommas=0;
		int countropen=0,countrclose=0,countqopen=0,countqclose=0;
		for(int i=0;i<size-1;i++)
		{
			if(IsBadUnion(mystring[i],mystring[i+1]))
				return false;
			if(mystring[i]=='[')
			{
				isopenquadbracket=true;
				countqopen++;
			}
			if(mystring[i]==']')
			{
				isopenquadbracket=false;
				countcommas=0;
				countqclose++;
			}
			if(mystring[i]=='(')
			{
				countropen++;
			}
			if(mystring[i]==')')
			{
				countrclose++;
			}
			if(isopenquadbracket==false&&  (IsOnlyContentOfBracket(mystring[i])||( IsNumber(mystring[i]) && IsNumber(mystring[i+1]) )))
				return false;
			if(isopenquadbracket==true&&IsOnlyLogic(mystring[i]))
				return false;
			if(mystring[i]==',')
			{
				countcommas++;
				if(countcommas>1)
					return false;
			}
		}
		if(mystring[size-1]==')')
			{
				countrclose++;
			}
		if(mystring[size-1]==']')
			{
				countqclose++;
			}
		if(countropen!=countrclose||countqopen!=countqclose)
			return false;
		for(int i=0;i<size;i++)
		{
			wchar_t symbol=mystring[i];
			if(symbol=='1')
			{
				Operand op;
				op.type=myconst;
				op.x=1;
				str[strsize]=op;
				strsize++;
				continue;
			}
			if(symbol=='0')
			{
				Operand op;
				op.type=myconst;
				op.x=0;
				str[strsize]=op;
				strsize++;
				continue;
			}
			if(symbol=='~')
			{
				Operand op;
				op.type=myno;
				if(opstack.IsEmpty()||opstack.top().type==open||opstack.top().type<op.type)
					opstack.push(op);
				else
				{ while(!opstack.IsEmpty()&&opstack.top().type>=op.type&&opstack.top().type!=open)
				{
					str[strsize]=opstack.top();
					opstack.pop();
					strsize++;
				}
				opstack.push(op);
				}
				continue;
			}
			if(symbol=='&')
			{
				Operand op;
				op.type=myand;
				if(opstack.IsEmpty()||opstack.top().type==open||opstack.top().type<op.type)
					opstack.push(op);
				else
				{ while(!opstack.IsEmpty()&&opstack.top().type>=op.type&&opstack.top().type!=open)
				{
					str[strsize]=opstack.top();
					opstack.pop();
					strsize++;
				}
				opstack.push(op);
				}
				continue;
			}
			if(symbol=='|')
			{
				Operand op;
				op.type=myor;
				if(opstack.IsEmpty()||opstack.top().type==open||opstack.top().type<op.type)
					opstack.push(op);
				else
				{ while(!opstack.IsEmpty()&&opstack.top().type>=op.type&&opstack.top().type!=open)
				{
					str[strsize]=opstack.top();
					opstack.pop();
					strsize++;
				}
				opstack.push(op);
				}
				continue;
			}
			if(symbol=='^')
			{
				Operand op;
				op.type=myxor;
				if(opstack.IsEmpty()||opstack.top().type==open||opstack.top().type<op.type)
					opstack.push(op);
				else
				{ while(!opstack.IsEmpty()&&opstack.top().type>=op.type&&opstack.top().type!=open)
				{
					str[strsize]=opstack.top();
					opstack.pop();
					strsize++;
				}
				opstack.push(op);
				}
				continue;
			}
			if(symbol=='(')
			{
				Operand op;
				op.type=open;
				opstack.push(op);
				continue;
			}
			if(symbol==')')
			{
				while(opstack.top().type!=open)
				{
					str[strsize]=opstack.top();
					opstack.pop();
					strsize++;
				}
				opstack.pop();
				continue;
			}
			if(symbol==' '||symbol=='y')
			{
				continue;
			}
			if(symbol=='[')
			{
				i++;
				Operand op;
				op.type=myvar;
				bool mines=false;
				if(mystring[i]=='-')
				{
					mines=true;
					i++;
				}
				while(mystring[i]!=',')
				{
					donumber(op.x,mystring[i]);
					i++;
				}
				if(mines)
				{
					op.x=-op.x;
				}
				i++;
				mines=false;
				if(mystring[i]=='-')
				{
					mines=true;
					i++;
				}
				while(mystring[i]!=']')
				{
					donumber(op.y,mystring[i]);
					i++;
				}
				if(mines)
				{
					op.y=-op.y;
				}
				str[strsize]=op;
				strsize++;
			}
		}
		while(!opstack.IsEmpty())
		{
			str[strsize]=opstack.top();
			opstack.pop();
			strsize++;
		}
		return true;
	}
	int TestCalculate()
	{
		int i=0;
		MyStack<Operand> number;
		for(int i=0;i<strsize;i++)
		{
			if(str[i].type==myconst)
			{
				number.push(str[i]);
				continue;
			}
			if(str[i].type==myvar)
			{
                Operand op;
				op.type=myconst;
				op.x=1;
				number.push(op);
				continue;
			}
			if(str[i].type==myand)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=X&&Y;
				number.push(op);
			}
			if(str[i].type==myor)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=X||Y;
				number.push(op);
			}
			if(str[i].type==myxor)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=(X+Y)%2;
				number.push(op);
			}
			if(str[i].type==myno)
			{
				int X=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=(X+1)%2;
				number.push(op);
			}
		}
		if(number.size!=1)
		{
			int i=-1;
			throw i;
		}

		return number.top().x;
	}
	int Calculate(char **field,int &width,int &height,int x,int y)
	{
		int i=0;
		MyStack<Operand> number;
		for(int i=0;i<strsize;i++)
		{
			if(str[i].type==myconst)
			{
				number.push(str[i]);
				continue;
			}
			if(str[i].type==myvar)
			{
				Operand op;
				op.type=myconst;
				op.x=field[(str[i].x+y+100*height)%height][(str[i].y+x+100*width)%width];
				number.push(op);
				continue;
			}
			if(str[i].type==myand)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=X&&Y;
				number.push(op);
			}
			if(str[i].type==myor)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=X||Y;
				number.push(op);
			}
			if(str[i].type==myxor)
			{
				int X=number.top().x;
				number.pop();
				int Y=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=(X+Y)%2;
				number.push(op);
			}
			if(str[i].type==myno)
			{
				int X=number.top().x;
				number.pop();
				Operand op;
				op.type=myconst;
				op.x=(X+1)%2;
				number.push(op);
			}
		}
		if(number.size!=1)
		{
			int i=-1;
			throw i;
		}

		return number.top().x;
	}
	};