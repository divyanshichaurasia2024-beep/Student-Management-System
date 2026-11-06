#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Student{
    private:
    int rollNo;
    string name;
    int age;
    float marks;
     
    public:
    void addStudent(){
        cout<<"enter roll number:";
        cin>>rollNo;
        cin.ignore(20,'\n');
        cout<<"enter name:";
        getline(cin,name);
        cout<<"enter age:";
        cin>>age;
        cout<<"enter marks:";
        cin>>marks;
        cout<<"\nStudent Added successfully!\n";
    }
    void displayStudent(){
        cout<<"\nRoll Number:"<<rollNo;
        cout<<"\nName:"<<name;
        cout<<"\nAge:"<<age;
        cout<<"\nMarks:"<<marks<<endl;
    }

    int getrollNo(){
        return rollNo;
    } 

    void searchStudent(Student s[], int n)
    {
        int searchRoll;
        int found=0;
        cout<<"\nenter roll number to search:";
        cin>>searchRoll;
        for(int i=0; i<n; i++)
        {
        if(s[i].getrollNo()==searchRoll)
        {
            cout<<"Student found!\n";
            s[i].displayStudent();
            found=1;
            break;
        }
        if(found=0){
            cout<<"\nStudent Not found!\n";
        }
    }
  }
   void updateStudent(Student s[], int n){
    int searchRoll;
    int found=0;
     cout<<"\nEnter Roll Number to Update:";
     cin>>searchRoll;
     for(int i=0; i<n; i++){
        if(s[i].getrollNo()== searchRoll){
            cout<<"\nStudent Found!";
            cout<<"\nEnter New Details:\n";
            cin.ignore(1000,'\n');

            cout<<"Enter New Name:";
            getline(cin, s[i].name);

            cout<<"Enter New Age:";
            cin>>s[i].age;

            cout<<"enter New Marks:";
            cin>>s[i].marks;

            cout<<"\nStudent Information Update Successfully!\n";
            found=1;
            break;
        }
     }
     if(found==0){
        cout<<"\nStudent Not Found!\n";
     }
   }
    
   void deleteStudent(Student s[], int &n){
    int searchRoll;
    int found= 0;
    cout<<"\n enter Roll Number to Delete:";
    cin>>searchRoll;
    for(int i=0; i<n; i++){
        if(s[i].getrollNo()==searchRoll){
            for(int j=i; j<n-1; j++){
                s[j]=s[j+1];
            }
            n--;
            cout<<"\nStudent Record Deleted Successfuly!";
            found=1;
            break;
        }
    }
    if(found== 0){
        cout<<"\nStudent Not Found!\n";
    }
   }

   string calculateGrade(){
    if(marks>=90)
    return "A+";
    else if(marks>=80)
    return "A";
    else if(marks>=70)
    return "B";
    else if(marks>=60)
    return "C";
    else if(marks>=50)
    return "D";
    else return "F";
   } 


   void gradeStudent(Student s[], int n){
    int searchRoll;
    int found=0;
    cout<<"\nEnter Roll Number:";
    cin>>searchRoll;
    for(int i=0; i<n; i++){
        if(s[i].getrollNo()==searchRoll){
            cout<<"\nStudent Nmae:"<<s[i].name;
            cout<<"\nMarks: "<<s[i].marks;
            cout<<"\n Grade:"<<s[i].calculateGrade()<<endl;
            found=1;
            break;
        }
    }
    if(found==0)
    cout<<"\n Student Not Found!\n";
  }

  void saveRecords(Student s[], int n){
    ofstream fout("student.txt");
    if(!fout){
        cout<<"\nFile could not be opened!\n";
        return;
    }
    for(int i=0; i<n; i++){
        fout<<s[i].rollNo <<endl;
        fout<<quoted(s[i].name) <<endl;
        fout<<s[i].age <<endl;
        fout<<s[i].marks <<endl;
    }
    fout.close();
    cout<<"\n Records Saved Successfully!\n";
  }
  void loadRecords(Student s[], int &n){
    ifstream fin("student.txt");
    if(!fin){
        n=0;
        return;
    }
    n=0;
    while(n<100 && 
        fin>> s[n].rollNo
        >>quoted(s[n].name)
        >>s[n].age
        >>s[n].marks)
        {
            n++;
        }
        fin.close();
        cout<<"\n Records Loaded:"<<n<<endl;
  }
};

 int main(){
    Student s[100];
    int n=0;
    int choice;
    s[0].loadRecords(s, n);
    do{
        cout<<"\n===== STUDENT MANAGEMENT SYSTEM ======\n";
        cout<<"1.Add Student\n";
        cout<<"2.Display Students\n";
        cout<<"3.Search Student\n";
        cout<<"4.Update Student\n";
        cout<<"5.Delete Student\n";
        cout<<"6.Calculate Grade\n";
        cout<<"7. Save Records\n";
        cout<<"8.Exit\n";

        cout<<"\n Enter Your Choice:";
        cin>>choice;

        switch(choice){
            case 1:
            if(n<100){
                s[n].addStudent();
                n++;
            }else
            cout<<"\n Student Limit Reached!\n";
            break;

            case 2:
            if(n==0)
            cout<<"\n No Student Records Found!\n";
            for(int i=0; i<n; i++)
            s[i].displayStudent();
            break;

            case 3:
            s[0].searchStudent(s,n);
            break;

            case 4:
            s[0].updateStudent(s,n);
            break;

            case 5:
            s[0].deleteStudent(s,n);
            break;

            case 6:
            s[0].gradeStudent(s,n);
            break;

            case 7:
            s[0].saveRecords(s,n);
            break;

            case 8:
            cout<<"\nExiting Program...\n";
            break;

            default:
            cout<<"\n Invalid Choice!\n";
        }
    }
    while(choice!=8);
    return 0;
 }