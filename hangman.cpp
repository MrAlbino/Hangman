#include<iostream>
#include<conio.h>
#include<string>
#include<ctime>
#include<stdlib.h>

#define TRYCOUNT 5

using namespace std;

void draw_man(int try_count){
	
	cout<<endl<<endl;
	cout<<"  _____"<<endl;
	cout<<"  |   |"<<endl;
	cout<<"  |";if(try_count>=1) cout<<"   O   ";cout<<endl;
	cout<<"  |";if(try_count>=3) cout<<"  /|\\";cout<<endl;
	cout<<"  |";if(try_count>=5) cout<<"  / \\";cout<<endl;
	cout<<"  |"<<endl;
	cout<<"__|__"<<endl;
}

int main(){
	
	srand(time(NULL));
	
	string kelimeler[5]={"elma","armut","portakal","kiraz","mandalina"};
	
	string word;
	string guessed;
	
	word=kelimeler[rand()%5];
	
	int word_len=word.length();
	string display_word(word_len,'_');
	
	int found=0;
	char guess=' ';
	
	int remain=5;
	int flag_found=0;
	
	
	while(remain>=0){
		
		system("cls");
		
		cout<<"Meyve ismini bul."<<endl;
		
		for(int i=0;i<word_len;i++){
			cout<<" "<<display_word[i]<<" ";
		}
		cout<<endl<<endl;
		
		cout<<"Kalan Hak: "<<remain<<" / "<<TRYCOUNT<<endl;
		cout<<"Denenen Harfler: "<<guessed<<endl;
		
		draw_man(remain);
		
		if(found==word_len){
			cout<<endl;
			cout<<"**************"<<endl;
			cout<<"*  Kazandin  *"<<endl;
			cout<<"**************"<<endl;			
			break;
		}
		
		if(remain==0){
			break;
		}
		
		cout<<"Harf sec:";
		guess=getche();
		
		guessed=guessed+" "+guess;
		
		flag_found=0;
		
		for(int i=0;i<word_len;i++){
			
			if(word[i]==guess&&display_word[i]=='_'){
				display_word[i]=guess;
				found++;
				flag_found=1;
			}
		}
		
		if(!flag_found){
			remain--;
		}
	}
	if(found!=word_len){
		cout<<endl;
		cout<<"***************"<<endl;
		cout<<"*  Kaybettin  *"<<endl;
		cout<<"***************"<<endl;
	}
	return 0;
}
