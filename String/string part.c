#include<stdio.h>
#include<string.h>

void replaceSubstring(char [],char[],char[]);


main()
{
char string[100],sub[100],new_str[100];
printf("\nEnter a string: \n");
gets(string);
printf("\nEnter the substring: \n");
gets(sub);
printf("\nEnter the new substring: \n");
gets(new_str);
replaceSubstring(string,sub,new_str);
printf("\nThe string after replacing : %s\n",string);
}

void replaceSubstring(char string[],char sub[],char new_str[])
{
int stringLen,subLen,newLen,strLenNew;
int i=0,j,k;
int flag=0,start,end;
stringLen=strlen(string);
subLen=strlen(sub);
newLen=strlen(new_str);



    for(i=0; i<= strLenNew; i++)      //matching substring
    {
        if(string[i] == sub[0])
        {
            for(j=1; j< subLen ; j++)
            {
                if(string[i+j] != sub[j])
                    break;
                if(j+1 == subLen){
                    flag = 1 ;

                }

            }



        if(flag==1)           //moving string
        {
            strLenNew = stringLen - subLen + newLen ;

            if(subLen > newLen)
            {
                for(j=i+newLen, k=i+subLen  ; j<strLenNew  ; j++ , k++ )
                    {
                        string[j] = string[k] ;
                    }

            }

            if(subLen < newLen)
            {
                for(j= strLenNew-1 , k= (stringLen)-1  ; j>= i+newLen ; j--,k-- )
                    {
                       string[j] = string[k];
                    }
            }
                for(k=0 ; k<newLen ; k++)  //replacing string
            {
                string[i+k] = new_str[k];
            }
            flag=0 ;
            i = i+newLen ;

        }
        }
    }
        string[strLenNew] ='\0';


        return 0 ;


}
