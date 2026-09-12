#include <iostream>
#include <iomanip>
using namespace std;

class Student {
public:
    int roll, m[5];
    string name;

    float avg() {
        int sum = 0;
        for(int i=0;i<5;i++) sum += m[i];
        return sum/5.0;
    }

    char grade() {
        float a=avg();
        if(a>=90) return 'A';
        if(a>=80) return 'B';
        if(a>=70) return 'C';
        if(a>=60) return 'D';
        if(a>=50) return 'E';
        return 'F';
    }
};

int main() {
    Student s[50], temp;
    int n=0, ch, r;

    do {
        cout<<"\n Student Grades \n";
        cout<<"student grade management details";
        cout<<"Enter choice: ";
        cin>>ch;

        if(ch==1) {
            cout<<"Roll No: "; cin>>r;

            for(int i=0;i<n;i++)
                if(s[i].roll==r) {
                    cout<<"Roll number already exists\n";
                    r=-1;
                    break;
                }

            if(r!=-1) {
                s[n].roll=r;
                cout<<"Name: "; cin>>s[n].name;
                cout<<"Marks (5 subjects): ";
                for(int i=0;i<5;i++) cin>>s[n].m[i];
                n++;
                cout<<"Student added.\n";
            }
        }

        else if(ch==2) {
            cout<<"Roll No: "; cin>>r;
            int i;
            for(i=0;i<n;i++)
                if(s[i].roll==r) break;

            if(i==n) cout<<"Student not found\n";
            else
                cout<<fixed<<setprecision(2)
                    <<s[i].name<<" - Average: "<<s[i].avg()
                    <<" - Grade: "<<s[i].grade()<<endl;
        }

        else if(ch==3) {
            if(n==0) continue;

            float high=s[0].avg();
            for(int i=1;i<n;i++)
                if(s[i].avg()>high) high=s[i].avg();

            for(int i=0;i<n;i++)
                if(s[i].avg()==high)
                    cout<<"Topper: "<<s[i].name<<" ("<<fixed
                        <<setprecision(2)<<high<<")\n";
        }

        else if(ch==4) {
            for(int i=0;i<n-1;i++)
                for(int j=i+1;j<n;j++)
                    if(s[i].avg()<s[j].avg()) {
                        temp=s[i]; s[i]=s[j]; s[j]=temp;
                    }

            for(int i=0;i<n;i++)
                cout<<s[i].roll<<" "<<s[i].name
                    <<" - Average: "<<fixed<<setprecision(2)
                    <<s[i].avg()<<" - Grade: "<<s[i].grade()<<endl;
        }

    } while(ch!=5);

    cout<<"Exiting\n";
    return 0;
}
