/*Q1) Define a Clock class that does the following ; 
 a. Accept Hours, Minutes and Seconds
 b. Check the validity of numbers
 c. Set the time to AM/PM mode
 Use the necessary constructors and methods to do the above task */

class Clock
{
    int hours, minutes, seconds;
    String mode;
    boolean isSet = false;

    public Clock(int h, int m, int s)
    {
        if (!setTime(h,m,s))
            System.out.println("Set valid time");
        // {
        //     hours = h;
        //     minutes = m;
        //     seconds = s;
        // }
        // else
    }
    public void setMode(String ap)
    {
        ap = ap.toUpperCase();
        if (ap == "AM" || ap == "PM")
            this.mode = ap;
        else
            System.out.println("set valid time");
    }
    public String getTime()
    {
        if (isSet)
            return hours+":"+minutes+":"+seconds+" "+mode;
        else
            return "Time not set";
    }
    public boolean setTime(int h, int m, int s)
    {
        if ((h<=12 && h>=1) && (m<=60 && m>=0) && (s<=60 && s>=0))
        {
            hours = h;
            minutes = m;
            seconds = s;
            isSet = true;
            mode = "AM";
            return true;
        }
        else
        {
            return false;
        }
    }
}
class Q1
{
    public static void main(String[] args)
    {
        Clock c = new Clock(12,56,45);
        System.out.println(c.getTime());
    }
}