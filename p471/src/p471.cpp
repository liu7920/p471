#include <iostream>
#include <string>
using namespace std;

class UI{
	class GraphicEditor{
	public:
		string name;
		GraphicEditor* next;
	};
public:
	string Gra;
	GraphicEditor* Head = new GraphicEditor;
	UI(){
		Head->next = NULL;
	}
	string reLine(string str){
		this->Gra=str;
		return this->Gra;
	}
	string reCircle(string str){
		this->Gra=str;
		return this->Gra;
	}
	string reRect(string str){
		this->Gra=str;
		return this->Gra;
	}
	void add(){
		GraphicEditor* NewNode = new GraphicEditor;
		NewNode->name = this->Gra;
		NewNode->next = NULL;

		if(Head->next == NULL){
			Head->next = NewNode;
		}
		else{
			GraphicEditor* temp = Head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = NewNode;
		}
	}
};


class Shape{
public:

	string reLine(){
		return "Line";
	}
	string reCircle(){
		return "Circle";
	}
	string reRect(){
		return "Rect";
	}
};

class Line : public Shape{
	string str;
public:
	string getLine(){
		str=this->reLine();
		return str;
	}
};

class Circle : public Shape{
	string str;
public:
	string getCircle(){
		str=this->reCircle();
		return str;
	}
};

class Rect : public Shape{
	string str;
public:
	string getRect(){
		str=this->reRect();
		return str;
	}
};

int main() {

	int num,cnt,i;
	string str;

	UI test,temp,_temp;
	Line L;
	Circle C;
	Rect R;

	cout << "그래픽 에디터입니다." << endl;
	while(1){

		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> num;

		if(num==1){
			cout << "선:1, 원:2, 사각형:3 >> ";
			cin >> num;
			if(num==1){
				str=L.getLine();
				test.reLine(str);
				cout << test.Gra << endl;
				test.add();
			}
			else if(num==2){
				str=C.getCircle();
				test.reCircle(str);
				cout << test.Gra << endl;
				test.add();
			}
			else if(num==3){
				str=R.getRect();
				test.reRect(str);
				cout << test.Gra << endl;
				test.add();
			}
		}
		else if(num==2){
			cnt=0;
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> num;
			temp=test;
			while(temp.Head->next != NULL){
				_temp=temp;
				temp.Head = temp.Head->next;
				if(cnt == num){
					_temp.Head->next = temp.Head->next;
				}
				cnt++;
			}
		}
		else if(num==3){
			i=0;
			temp=test;
			while(temp.Head->next != NULL){
				temp.Head = temp.Head->next;
				cout << i++ << ": ";
				cout << temp.Head->name << endl;
			}
		}
		else if(num==4){
			break;
		}
		else{
			cout << "잘못된 입력" << endl;
		}

	}
	return 0;
}
