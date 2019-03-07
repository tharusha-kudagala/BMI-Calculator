#include <stdio.h>
#include <math.h>

float f_i()
{   int ft;
    float in,v1,v2,cm;

    printf("\nHeight --> Units -->> (ft/inc)\n\n");
    printf("ft : ");
    scanf("%d",&ft);
    printf("inches : ");
    scanf("%f",&in);
    if(in>=12) ///12 inch = 1 foot
    {
        ft=ft+1;
        in=in-12;
    }

    v1 = ft*30.48; //ft to cm
    v2 = in*2.54; //in to cm
    cm = v1+v2;
    return cm/100; ///cm to m
}
float meter()
{
    float height;

    printf("\nHeight --> Units -->> meters (m)\n\n");
    printf("m : ");
    scanf("%f",&height);
    return height;

}
float cm_m()
{
    float cm;

    printf("\nHeight --> Units -->> (cm)\n\n");
    printf("cm : ");
    scanf("%f",&cm);
    return cm/100;
}

float kg()
{   float kg;
    printf("\nWeight --> Units -->> (kg)\n\n");
    printf("kg : ");
    scanf("%f",&kg);
    return kg;
}

float lbs()
{
    float po,kg;
    printf("\nWeight --> Units -->> Pound (lbs)\n\n");
    printf("lbs : ");
    scanf("%f",&po);
    kg = po*0.454;
    return kg;
}

float bmi(float weight,float height)
{
    float b_mi = weight/pow(height,2);
    return b_mi;
}

int main()
{
    printf("\nBody Mass Index (BMI) Calculator (Metric) Beta\n\nEACH TIME PRESS ENTER AFTER INPUTING VALUES\n");

    char choice_h,choice_w;

/// asking height to choose
    printf("\n-+-+-+-+-+ Units for Height? +-+-+-+-+-\n\n[1] ft/inch\t[2] m\t[3] cm\t(Select a number)\n\n");
    scanf(" %c",&choice_h);

    if(choice_h!='1' && choice_h!='2' && choice_h!='3')
    {   while(choice_h != '1' && choice_h !='2' && choice_h!='3')
        {
        printf("\n!!! Please make a valid selection !!!\n\n");
        printf("\nUnits for Height?\n\n[1] ft/inch\t[2] m\t[3] cm\t(Example : Press 1 to choose (ft/inc))\n\n");
        scanf(" %c",&choice_h);
        }
    }
//switch for height selection
    float m;
    switch(choice_h)
    {
    case '1':
       m = f_i();
       //printf("\n\t%.3f meters",m);
        break;
    case '2':
       m = meter();
       //printf("\n\t%.3f meters",m);
        break;
    case '3':
       m = cm_m();
       //printf("\n\t%.3f meters",m);
        break;
    }
    ///asking weight to choose
    printf("\n\n-+-+-+-+-+ Units for Weight? +-+-+-+-+-\n\n[1] kg\t[2] lbs\n\n");
    scanf(" %c",&choice_w);

    if(choice_w!='1' && choice_w!='2')
    {   while(choice_w != '1' && choice_w !='2')
        {
        printf("\n!!! Please make a valid selection !!!\n\n");
        printf("\nUnits for Weight?\n\n[1] kg\t[2] lbs\n\n");
        scanf(" %c",&choice_w);
        }
    }
    //switch for weight selection
    float k;
    switch(choice_w)
    {
    case '1':
        k = kg();
        //printf("\n\t%.3f kg",k);
        break;
    case '2':
        k = lbs();
        //printf("\n\t%.3f kg",k);
        break;
    }

    printf("\n >>> The Height is %.3f (m) <<<\n\n >>> The Weight is %.3f (kg) <<<\n\n",m,k);

   float rate = bmi(k,m);
   printf(" >>> The BMI Rate is : %.2f (kg/m^2)<<< \n\n",rate);

   printf("<------------------------------------------>\n\n");

   if (rate<15)
    printf("Very Severely Underweight [-!!]");
   else if (rate<16)
    printf("Severely Underweight [-!]");
   else if(rate<18.5)
        printf(" Under Weight [-]\n");
   else if(rate<=24.9)
        printf(" Normal Weight [=]\n");
   else if(rate<=29.9)
        printf(" Over Weight [+]\n");
   else if(rate<=34.9)
        printf(" Obesity (Class 1) [+!]\n");
   else if(rate<=39.9)
        printf(" Obesity (Class 2) [+!!]\n");
   else
        printf(" Obesity (Class 3) [+!!!]\n");
   printf("\n\n<------------------------------------------>\n\n");
    return 0;
}
