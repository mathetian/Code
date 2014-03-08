#include <iostream>
#include <fstream>
using namespace std;

/*int main()
{
	ifstream ifs;
	ofstream ofs;
	ofs.open("hello1.txt");
	int a=3,b=4;
	ofs.write((char*)&a,sizeof(int));
	ofs.write((char*)&b,sizeof(int));
	ofs.close();
	ifs.open("hello1.txt");
	a=0;b=0;
	ifs.read((char*)(&a),sizeof(int));
	cout<<a<<endl;
}
*/
/*int main()
{
	ifstream ifs;
	ofstream ofs;
	ofs.open("hello.txt");
	int a=3123145,b=4;
	char * content = new char[sizeof(int)*2];
	content = (char*)&a; content += 4;
	content = (char*)&b; content -= 4;
	ofs.write(content,sizeof(content));
	ofs<<"hello"<<endl;
	ofs.close();

	ifs.open("hello.txt");
	a=0;b=0;
	char * content1 = new char[sizeof(int)*2];
	ifs.read(content1,sizeof(content1));
	a = (int)(*content1);
	cout<<a<<" "<<b<<endl;

	int a1[] ={1,2,3};
	char b1[]={'1','2','3'};
	cout<<sizeof(a1)<<" "<<sizeof(b1)<<endl;
}*/
#define PAGESIZE 25
#define SINT     sizeof(int)
#define SOFF     sizeof(off_t)	

typedef struct{
  int   pos;
  int   size;
}EmptyEle;

typedef struct{
  int       curPos;
  int       nextBlock;
  EmptyEle  eles[PAGESIZE];
}EmptyBlock;

typedef struct {
  int   hash_value;
  int   data_pointer; 
  int   key_size;   
  int   data_size; 
} PageElement;

class Page{
public:
	Page(){}
  ~ Page(){}

private:	
    bool   full(){}
    void   put(const string&key,const string&value){}
    string get(const string&key){}
    bool   remove(const string&key){}

private:
  int d, curNum;
  PageElement elements[PAGESIZE];

public:
  void readFromFile(istream & is)
  {
    is.read((char*)&d,SINT);
    is.read((char*)&curNum,SINT);
    is.read((char*)elements,sizeof(elements));
  }

  void writeToFile(ostream & os)
  {
    char * content = new char[SINT*2];
    content = (char*)&d; content += SINT;
    content = (char*)&curNum; content -= SINT;
    os.write(content,sizeof(content));
    os.write((char*)elements,sizeof(elements));
    delete [] content;
    content =  NULL;
  }
};

int main()
{
	Page page;
	cout<<sizeof(page)<<endl;
}