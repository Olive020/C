#include <iostream>
#include <string>
#include<cstdlib>
#include <vector>
#include<ctime>
using namespace std;

struct score { 
 string name;
 int math,english,nature,society,chinese,total;
};

int main(){
    char str[6];
    double M=15,m=0;
    vector<score>syw;
    score temp;
    srand(time(NULL));
    for (int  i =0;i< 1000; i++) {
    	for(int j=0;j<6;j++){
    		temp.name+='a'+rand()%26;
		}
        
        temp.math=(M-m)*rand()/(RAND_MAX+1.0)+m;
        temp.english=(M-m)*rand()/(RAND_MAX+1.0)+m;
        temp.nature=(M-m)*rand()/(RAND_MAX+1.0)+m;
        temp.society=(M-m)*rand()/(RAND_MAX+1.0)+m;
        temp.chinese=(M-m)*rand()/(RAND_MAX+1.0)+m;

        temp.total=temp.chinese+temp.english+temp.math+temp.nature+temp.society;
        syw.push_back(temp);
//        cout<<syw[i].name<<"  "<<syw[i].math<<"  "<<syw[i].english<<"  "<<syw[i].nature<<"  "<<syw[i].society<<"  "<<syw[i].chinese<<"  "<<syw[i].total<<endl;
        temp.name="\0";
        
        
    }
    //選擇排序法 
    /*
    for(int i=0;i<1000;i++){
    	for(int j=0;j<1000;j++){
    		if(syw[i].total>syw[j].total){
    			temp=syw[i];
    			syw[i]=syw[j];
    			syw[j]=temp;
			}
		}
	}
	*/
	//插入排序法 
    for(int i=0;i<1000;i++){
    	int j=i;
    	while(j>0&&syw[j-1].total<syw[j].total){
    		temp=syw[j];
			syw[j]=syw[j-1];
			syw[j-1]=temp;
			j--;
		}
	}
	
	for(int i=0;i<1000;i++){
    	
    	cout<<"\t"<<syw[i].name<<"    ";
    	cout<<"\t"<<syw[i].math<<"   ";
    	cout<<"\t"<<syw[i].english<<"   ";
    	cout<<"\t"<<syw[i].nature<<"   ";
    	cout<<"\t"<<syw[i].society<<"   ";
    	cout<<"\t"<<syw[i].chinese<<"   ";
    	cout<<"\t"<<syw[i].total<<endl;
    }
}
