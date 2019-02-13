
#include<stdio.h>

#include<math.h>

float simple_i(float p, float t, float r) {

	return (p*t*r*0.01);

}

float compound_i(float p, float t, float r) {

	return p*pow((1 + r*0.01), t);

}

void main() {

	float princi_amt = 500000;

	float r, s, c;

	printf("Enter the rate");
	scanf_s("%f", &r);

	s = simple_i(princi_amt, 1.0, r); c = compound_i(princi_amt, 1.0, r);

	printf(" Annually \n SI : %f\n CI : %f\n Total for 10years:%f\n ", s, c, s + c);

	s = simple_i(princi_amt, 0.5, r); c = compound_i(princi_amt, 0.5, r);

	printf(" Semi-Annually \n SI : %f\n CI : %f\n Total for 10years:%f\n ", s, c, s + c);

	s = simple_i(princi_amt, 0.25, r); c = compound_i(princi_amt, 0.25, r);

	printf(" Quarterly \n SI : %f\n CI : %f\n Total for 10years:%f\n ", s, c, s + c);

	s = simple_i(princi_amt, 1/12, r); c = compound_i(princi_amt, 1/12, r);

	printf(" Monthly \n SI : %f\n CI : %f\n Total for 10years:%f\n ", s, c, s + c);

	s = simple_i(princi_amt, 1/365, r); c = compound_i(princi_amt, 1/365, r);

	printf(" Daily \n SI : %f\n CI : %f\n Total for 10years:%f\n ", s, c, s + c);

	printf("Enter X to exit");
	scanf_s("%f", &c);
	getchar();
}