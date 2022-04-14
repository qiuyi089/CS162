/*Dung Nguyen
student ID: 976412641 
Program #3 */

/*The purpose of this program is to have the user enter in a job describtion and the 
interview. Then store it all in a external file so that the next time the program run
the information that the user enter will be retain and show to the user. The user will 
enter a maximum of 20 jobs and interview. */ 
#include<iostream> 
#include<cstring> 
#include<fstream> 
#include<cctype> 

using namespace std;
//constant variable.
const char job_text[] = "jobs.txt";
const char interview_text[] = "interviews.txt";
//Structure that will store the data.
struct jobs 
{

  char job_title[20];
  char company_name[20];
  char interview[100];
  int hours_work; 
  char start_date[20]; 
  char end_date[20]; 

}; 


//Prototype that will be use.
void display(jobs new_job[], int & counter); 
void get_job_info(jobs new_job[], int & counter);
void get_inter(jobs interview[], int & counter);
void save_interview(jobs new_interview[], int & counter);
void save_job(jobs new_job[],int & counter); 
int read_in(jobs array1[],bool interview);


int main()
{
//make the variable for response
  char response;
  char response2;
  char response3;  
  jobs jobs_avai[20];
  jobs interviews[20];
  int count_job = read_in(jobs_avai, false);
  int count_inter = read_in(interviews, true);
//Tell the user what the programs is about.
  cout<<"Welcome user. This program will let you input in a job describtion and "<<endl;
  cout<<"the opinion/interview you have on the job. The maximum job can be record is "<<endl;
  cout<<"20 can be enter in the memeory."<<endl; 
//Make struct variable.
  //jobs new_job;
  //jobs interview;
//while loops to ask the user if they want to enter in the infor or display the jobs.
  do{
   cout<<"What do you want to do (A)Enter in a job, (B)Enter in a interview, (C)Display the content: ";
   cin>>response;
   cin.ignore(100,'\n'); 
  
     if(tolower(response) == 'a')
     {  

       do
       {
          get_job_info(jobs_avai, count_job);
          cout<<"Do you want to continue(Y/N): ";
          cin>>response2;
          cin.ignore(100,'\n'); 
          cout<<" "<<endl;
       }while(tolower(response2) != 'n' && count_job < 20); 
     }
     else if(tolower(response) == 'b')
     {  
       do
       {
          get_inter(interviews, count_inter); 
          cout<<"Do you want to continue(Y/N): ";
          cin>>response2;
          cin.ignore(100,'\n'); 
          cout<<" "<<endl;
       }while(tolower(response2) != 'n' && count_inter < 20); 


     }
//display the job for the user. 
     else if(tolower(response) == 'c'){
       display(jobs_avai, count_job);
       display(interviews, count_inter);
    }
   cout<<"Would you like to continue edit(Y/N): ";
   cin>>response3;
   cin.ignore(100,'\n');
 }while(tolower(response3) !='n');
//save the job and the interviews in the .txt file.
 save_job(interviews,count_job);
 save_interview(interviews,count_inter);
 return 0;
}

//Read in what is inside the .txt file
int read_in(jobs array1[], bool interview)
{
//open the file.
  ifstream file_in;
//check if the interview is true or false.
  if(interview)
    file_in.open(interview_text);
  else
    file_in.open(job_text);
  
  int i = 0;

  if(file_in)
  {
// read in everything and check the pump.
    file_in.get(array1[i].company_name,20,'\n');
    file_in.ignore(100,'\n');
    while(i < 20 && file_in && !file_in.eof())
    {
    
      file_in.get(array1[i].company_name,20,'\n');
      file_in.ignore(100,'\n');

      file_in.get(array1[i].job_title,20,'\n');
      file_in.ignore(100,'\n');
      
      file_in >>array1[i].hours_work;
      file_in.ignore(100,'\n');
   
      file_in.get(array1[i].start_date,20,'\n');
      file_in.ignore(100,'\n');

      file_in.get(array1[i].end_date,20,'\n');
      file_in.ignore(100,'\n');
      if(interview)
      {  
        file_in.get(array1[i].interview,100,'\n');
        file_in.ignore(100,'\n');
      
      }
      ++i;
    }

  }  
//close the file and return i.
  file_in.close();
  file_in.clear();
  return i;

}
//get the job information from the user.
void get_job_info(jobs new_job[], int & counter)
{

  cout<<"Please enter in the company name: ";
  cin.get(new_job[counter].company_name,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the job name: "; 
  cin.get(new_job[counter].job_title,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the hours your work: ";
  cin>>new_job[counter].hours_work;
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the date you start: ";
  cin.get(new_job[counter].start_date,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter the date you end: ";
  cin.get(new_job[counter].end_date,20,'\n');
  cin.ignore(100,'\n'); 
  
  ++counter;


} 
//get the interview from the user and the jobs infor again.
void get_inter(jobs interview[],int & counter)
{
  cout<<"Please enter in the company name: ";
  cin.get(interview[counter].company_name,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the job name: "; 
  cin.get(interview[counter].job_title,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the hours your work: ";
  cin>>interview[counter].hours_work;
  cin.ignore(100,'\n'); 

  cout<<"Please enter in the date you start: ";
  cin.get(interview[counter].start_date,20,'\n'); 
  cin.ignore(100,'\n'); 

  cout<<"Please enter the date you end: ";
  cin.get(interview[counter].end_date,20,'\n');
  cin.ignore(100,'\n'); 
 
  cout<<"Please enter in one of your interview question: "<<endl;
  cin.get(interview[counter].interview,100,'\n'); 
  cin.ignore(100,'\n'); 

  ++counter;

}
//read out the information that user give 
void save_job(jobs new_job[],int & counter)
{
  
  ofstream file_out;
  
  file_out.open(job_text);
  
  for( int i = 0; i < counter; ++i)
  {

    file_out<<new_job[i].company_name<<endl;
    
    file_out<<new_job[i].job_title<<endl;
   
    file_out<<new_job[i].hours_work<<endl;
 
    file_out<<new_job[i].start_date<<endl;

    file_out<<new_job[i].end_date<<endl;
    
    file_out.clear();

  }
  file_out.close(); 
 
  
}
//read out the interview information that the user give
void save_interview(jobs new_interview[],int & counter)
{

  ofstream file_out;

  file_out.open(interview_text);

  for(int i = 0; i < counter; ++i)
  {

    file_out<<new_interview[i].interview<<endl;
    file_out.clear();
  }

  file_out.close();
 
}
//display the job for the user.
void display(jobs new_job[], int & counter)
{

  for(int i = 0; i < counter; ++i)
  {
    cout << "Company name: " << new_job[i].company_name << endl;

    cout  << endl << "Job name: " << new_job[i].job_title << endl;

    cout << endl << "Hours worked: " << new_job[i].hours_work << endl;

    cout << endl << "Date Start: " << new_job[i].start_date << endl;
  
    cout<< endl << "Date end: " << new_job[i].end_date << endl;

    cout << endl <<"The interview question is "<< new_job[i].interview << endl;
 
    cout << endl <<"----------------------------------"<<endl;
  
  }   


} 
























