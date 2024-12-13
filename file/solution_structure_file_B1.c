#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct courseInfo{
    char courseName[20];
    float credit;
};

struct studentInfo{
    long studentId;
    float *courseGp;
};

int main()
{
    FILE *fp;
    int i,n,numStds;
    struct courseInfo *courses;
    struct studentInfo *students;

    fp=fopen("course_info.txt","r");
    if(fp!=NULL)
    {

        fscanf(fp,"%d",&n);

        courses = (struct courseInfo*) malloc(sizeof(struct courseInfo)*n);

        for(i=0;i<n;i++)
        {
            char name[20];
            float credit;
            fscanf(fp,"%s %f",name,&credit);

            strcpy(courses[i].courseName,name);
            courses[i].credit = credit;
        }
        fclose(fp);
    }
    else{
        printf("Error opening file\n");
    }



    FILE *f;
    f=fopen("student_info.txt","r");
    if(f!=NULL)
    {
        int j;
        fscanf(f,"%d",&numStds);
        students = (struct studentInfo*) malloc(sizeof(struct studentInfo)*numStds);

        for(i=0;i<numStds;i++)
        {
            long id;
            float gp[n];
            fscanf(f,"%ld",&id);
            students[i].studentId = id;
            students[i].courseGp = (float*) malloc(sizeof(float)*n);
            for(j=0;j<n;j++)
            {
                fscanf(f,"%f",&gp[j]);
                students[i].courseGp[j] = gp[j];
            }
        }
    }
    else
    {
        printf("Error opening file\n");
    }

    FILE *result;
    result = fopen("result.txt","w");
    for(i=0;i<numStds;i++)
    {
        float totalGP =0;
        float totalCredits = 0;
        int j;
        for (j=0;j<n;j++)
        {
            if(students[i].courseGp[j]!=0)
            {
                totalGP+=(students[i].courseGp[j]*courses[j].credit);
                totalCredits+=courses[j].credit;
            }
        }
        fprintf(result,"%ld\t%f\t%f\n",students[i].studentId,totalGP/totalCredits,totalCredits);
    }
    fclose(result);

    return 0;
}
