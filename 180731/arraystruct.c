#include <stdio.h>
#include <string.h>

struct std{
	int rollno;
	char name[100];
};

void srt(struct std s[], int n){
	for(int i=0; i<n-1; i++){ //sort loop
		for(int j=0; j<n-1; j++){
			if(s[j].rollno>s[j+1].rollno){
				int temp;
				temp = s[j].rollno; //sorting number
				s[j].rollno = s[j+1].rollno;
				s[j+1].rollno = temp;
				
				char str[100]; //sorting name with number
				strcpy(str,s[j].name);
				strcpy(s[j].name,s[j+1].name);
				strcpy(s[j+1].name,str);
			}
		}
	}
	//print result
	printf("PRINTING SORTED NAMELIST\n Roll no: \t Name:\n");
	for(int i=0; i<n; i++){
		printf("%d \t %s \n",s[i].rollno, s[i].name);
	}
}

void main(){
	int n;
	printf("Enter number of students: ");
	scanf("%d",&n);
	struct std s[n];
	printf("Enter Student data: \n");
	//Input Data
	for(int i=0; i<n; i++){
		printf("%d. Enter student roll no. and first name: ", i+1);
		scanf("%d",&s[i].rollno);
		scanf("%s",s[i].name);	
	}
	//Sort
	srt(s, n);
}