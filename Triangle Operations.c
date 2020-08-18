#include <stdio.h> 
#include<math.h>
struct triangle
{
	float a_113,b_113,c_113;
}t;

int check (struct triangle t)
{  
    if (t.a_113 <= 0 || t.b_113 <= 0 || t.c_113 <= 0 ||(t.a_113 + t.b_113 <= t.c_113) ||( t.a_113 + t.c_113 <=t.b_113 )|| (t.b_113 + t.c_113 <= t.a_113) )   
    {  
       printf("Not a valid triangle\n");
	   return 0;  
    }                   
	else
	{
	printf("The triangle is a valid triangle \n");
	return 1;
	}

}  
void triangletype(struct triangle t)
{
	if( ((t.a_113 * t.a_113) + (t.b_113 * t.b_113) == (t.c_113 * t.c_113)) || ((t.a_113 * t.a_113) + (t.c_113 * t.c_113) == (t.b_113 * t.b_113)) || ((t.c_113 * t.c_113) + (t.b_113 * t.b_113) == (t.a_113 * t.a_113)) ) {
                
				printf("This is a right-angled triangle.\n");
            } else if( ( ((t.a_113 * t.a_113) + (t.b_113 * t.b_113) < (t.c_113 * t.c_113)) || ((t.a_113 * t.a_113) + (t.c_113 * t.c_113) < (t.b_113 * t.b_113)) || ((t.c_113 * t.c_113) + (t.b_113 * t.b_113) < (t.a_113 * t.a_113)) ) || ( ( t.a_113<=t.c_113 && t.b_113<=t.c_113 ) || ( t.a_113<=t.b_113 && t.c_113<=t.b_113 ) || ( t.b_113<=t.a_113 && t.c_113<=t.a_113 ) ) ) {
                printf("This is an acute-angled triangle.\n");
            } else if( ( ((t.a_113 * t.a_113) + (t.b_113 * t.b_113) > (t.c_113 * t.c_113)) || ((t.a_113 * t.a_113) + (t.c_113 * t.c_113) > (t.b_113 * t.b_113)) || ((t.c_113 * t.c_113) + (t.b_113 * t.b_113) > (t.a_113 * t.a_113)) ) || ( ( t.a_113>t.c_113 && t.b_113>t.c_113 ) || ( t.a_113>t.b_113 && t.c_113>t.b_113 ) || ( t.b_113>t.a_113 && t.c_113>t.a_113 ) ) ) {
                printf("This is an obtuse-angled triangle.\n");
            } else {
                printf("Not a triangle \n");
			}        
}
  
int main()  
{  
    float side,area;
    printf("Enter the length of side A\n");
    scanf("%f",&t.a_113);
    printf("Enter the length of side B\n");
    scanf("%f",&t.b_113);
    printf("Enter the length of side C\n");
    scanf("%f",&t.c_113);
    if(check(t))
    {
    	triangletype(t);
	}
    side=((t.a_113+t.b_113+t.c_113)/2);
	area=sqrt(side*(side-t.a_113)*(side-t.b_113)*(side-t.c_113));
    printf("\n AREA OF TRIANGLE IS %f\n",area);
	printf("\n PERIMETER OF THE TRIANGLE IS %f",2*side);  
} 
