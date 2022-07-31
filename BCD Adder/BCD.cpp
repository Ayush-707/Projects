#include <iostream>
#include <cmath>
using namespace std;



int *hexToBinary (int hex);
void singleBitAdd(int in1, int in2, int cin, int &sum, int &cout);
void nibbleAdder(int *nibble1, int *nibble2, int cin, int *nibbleout, int &cout);
void nibbleBCDAdder(int *nibble1, int *nibble2, int cin, int *nibbleout, int &cout);

int main (void)
{   
    unsigned int num1, num2;
    int a = 0,l=0;
    int cout = 0,cin=0,array[5]; 
    int nibble1[50],nibble2[50];
    int *nibbleout  = (int *)malloc(40*sizeof(int));

    scanf ("%x", &num1);
    scanf ("%x", &num2);

    int *result1 = hexToBinary(num1);
    int *result2 = hexToBinary(num2);

   
    for (int i = 0; i < 5; i++)
    {
        array[i] = 0;
    }
    for(int x = 0; x < 16; x++)
    {
        nibble1[x] = result1[15-x];
        nibble2[x] = result2[15-x];
    }

    printf("Input1 = " );

    for (int i = 15; i >=0; i--)
    {
        printf("%d",nibble1[i]);
        if(i % 4 == 0)
        {   printf(" ");}
    }

    printf("\n");
    printf("Input2 = " );

    for (int g = 15; g >= 0; g--)
    {
        printf("%d",nibble2[g]);
        if(g % 4 == 0)
        {   printf(" ");}
    }
    printf("\n");

    nibbleBCDAdder( nibble1, nibble2, cin, nibbleout, cout);

    printf("Output = ");
    
    
        for (int i = 0; i < 16; i++)
        {   
            array[l] += nibbleout[15-i]*(1 << (3-a));
            a++;
            if ( i % 4 == 3 )
            {
                l++;
                a = 0;
                
            }
            
        }
    
    
    for (int j=15; j >= 0; j--)
    {
        printf( "%d" ,nibbleout[j] );
        if(j % 4 == 0)
        {   printf(" ");}
    }
    
    printf("\n");

    printf("Output = 0x");

    for (int f=0; f < 4; f++)
    {
        printf("%d",array[f]);
    }
    printf("\n");

    if ( cout == 2 )
    {
       std::cout << "carryout = "<< cout - 1 << endl; 
    }
    else
    {   printf("carryout = %d \n",cout);    }

    free(nibbleout);

}


void nibbleBCDAdder(int *nibble1, int *nibble2, int cin, int *nibbleout, int &cout)
{
    int *nibble3 = (int *)malloc(40*sizeof(int));

    for (int h=0; h < 16; h += 4)
    {
        nibble3[h] = 0; nibble3[h+1] = 1;
        nibble3[h+2] = 1; nibble3[h+3] = 0;
    }

    for (int i = 0; i < 16; i+=4) 
    {   
        int decimal[10],check = 0;
        

        nibbleAdder ( (nibble1 + i), (nibble2 + i), cin, (nibbleout + i), cout );
        cin = cout;

        
        for (int j=0; j < 5; j++)
        {
            decimal[j] = nibbleout[i+j]*pow(2,(j));
            
            check += decimal[j];
            
        }

    
        if ( check > 9 || cout == 1)
        {   
            
            cin = 0;
            nibbleAdder((nibbleout + i), (nibble3 + i), cin, (nibbleout + i), cout);
            cin = cout = 1;
            
        }
        
        
       
    }

     free(nibble3);
}

void nibbleAdder(int *nibble1, int *nibble2, int cin, int *nibbleout, int &cout)
{  
  
  for (int k = 0; k < 4; k++) 
  {
    int sum = 0; 

    
    singleBitAdd( nibble1[k], nibble2[k], cin, sum, cout ); // Do the bit addition
    nibbleout[k] = sum; // Store sum in the output
    cin = cout; // Propagate carry to next bit
    
  }

}

void singleBitAdd(int in1, int in2, int cin, int &sum, int &cout)
{   
    sum  = (in1 ^ in2) ^ cin;
    cout = (in1 & in2) | (cin & (in1 ^ in2));
    
  
    return;
}


int *hexToBinary (int hex)
{
    int arr[10],k=0;

    int *binary = (int *)malloc(40*sizeof(int));

    for (int i=0; i<4; i++)
    {
        arr[i] =  hex %  16 ;
        hex /= 16;
        
    }
    
    while ( k < 16 )
    {
        binary[k] = 0;
        k++;
    }

    int p = 0xf;

    int q = 0;

    while (p>=0)        
    {   
        
        while ( q < 4 )
        {   
          switch (arr[q])
          {
              case 0:
              /* code */
              break;

              case 1:
              binary[p] = 1;
              break;

              case 2:
              binary[p-1] = 1;
              break;

              case 3:
              binary[p] = binary[p-1] = 1;
              break;

              case 4:
              binary[p-2] = 1;
              break;

              case 5:
              binary[p-2] = binary[p] = 1;
              break;

              case 6:
              binary[p-2] = binary[p-1] = 1;
              break;

              case 7:
              binary[p-2] = binary[p-1] = binary[p] = 1;
              break;

              case 8:
              binary[p-3] = 1;
              break;

              case 9:
              binary[p-3] = binary[p] = 1;
              break;

              default:
              throw invalid_argument("INVALID INPUT");
              break;
          
                
          }

          q++;
          break;
        }

        p -= 4;
        
    }
   
    
    return binary;
}
