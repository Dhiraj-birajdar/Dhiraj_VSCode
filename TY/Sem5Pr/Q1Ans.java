import java.util.*;

class Clock 
{
  
int hours, minutes, seconds;
  
Clock () 
  {
    
System.out.println ("enter the time in HH MM SS format");
    
Scanner sc = new Scanner (System.in);
    
this.hours = sc.nextInt ();
    
this.minutes = sc.nextInt ();
    
this.seconds = sc.nextInt ();
  
} 
void isTimeValid () 
  {
    
if (hours >= 0 && hours < 24 && minutes > 0 && minutes < 60 
	 &&seconds > 0 && seconds < 60)
      
System.out.println ("time is valid");
    
    else
      
System.out.println ("time is not valid");
  
}
  
void setTimeMode () 
  {
    
if (hours < 12)
      
      {
	
System.out.println ("time =" 
			     +hours + ":" + minutes + ":" + seconds + " AM");
      
}
    
    else
      
hours = hours - 12;
    
System.out.println ("time =" 
			 +hours + ":" + minutes + ":" + seconds + " PM");
  
}

 
}


class Q1Ans 
{
  
public static void main (String args[]) 
  {
    
 
Clock c = new Clock ();
    
c.isTimeValid ();
    
c.setTimeMode ();

} 
}
