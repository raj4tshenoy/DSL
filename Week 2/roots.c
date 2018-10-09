#include <stdio.h>
#include <math.h>

void getdata(float *a, float *b, float *c){
	printf("Enter coefficient of x^2, x and the value of constant: \n");
	scanf("%f%f%f",&*a,&*b,&*c); //inputting through pointers to variables in main. 
}

void quadratic(float* a, float* b, float* c, float* d, float* r1, float* r2, float* cpx){
	*d = (pow(*b,2)-4*(*a)*(*c));
	if(*d>0){
		//roots are real and distinct
		*r1 = ((-(*b))+sqrt(*d))/(2*(*a));
		*r2 = ((-(*b))-sqrt(*d))/(2*(*a));
	}
	else if(*d==0){
		//roots are real and equal
		*r1 = ((-(*b))+sqrt(*d))/(2*(*a)); //as roots are equal one computation is enough
	}
	else{
		//roots are imaginary
		*r1 = ((-(*b))/(2*(*a))); //real part
		*cpx = (sqrt(-(*d)))/(2*(*a)); //imaginary part
	}
}

void print_roots(float* r1, float* r2, float* cpx, float* d){
	if((*d)>0){
		printf("\n\nThe roots are real and distinct. \n");
		printf("Roots are %f and %f\n",*r1, *r2);
	}
	else if((*d)==0){
		printf("\n\nThe roots are real and equal. \n");
		printf("Roots are %f and %f\n",*r1, *r1);
	}
	else{
		printf("\n\nThe roots are imaginary \n");
		printf("Roots are %f+i%f and %f-i%f", *r1, *cpx, *r1, *cpx);
	}
}                                                

void main(){
	float a, b, c, d, r1, r2, cpx; //Variables declared in main as scope of main 
	getdata(&a, &b, &c);
	quadratic(&a, &b, &c, &d, &r1, &r2, &cpx);
	print_roots(&r1, &r2, &cpx, &d);
}