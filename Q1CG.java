import java.util.Scanner;
class Clock {
    private int hours, minutes, seconds;
    private boolean isAM;

    public Clock(int hours, int minutes, int seconds) {
        if (isValidTime(hours, minutes, seconds)) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
            this.isAM = true;
            setAMPMMode();
        } else {
            System.out.println("Invalid time input. Please provide valid hours, minutes, and seconds.");
        }
    }

    private boolean isValidTime(int hours, int minutes, int seconds) {
        return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
    }

    private void setAMPMMode() {
        if (hours >= 12) {
            isAM = false;
        } else {
            isAM = true;
        }
    }

    public void displayTime() {
        int displayHours = (hours == 0 || hours == 12) ? 12 : hours % 12;
        String period = isAM ? "AM" : "PM";
        System.out.printf("%02d:%02d:%02d %s%n", displayHours, minutes, seconds, period);
    }


    public int getHours() {
        return hours;
    }

    public int getMinutes() {
        return minutes;
    }

    public int getSeconds() {
        return seconds;
    }

    public boolean isAM() {
        return isAM;
    }


    public void setHours(int hours) {
        if (isValidTime(hours, this.minutes, this.seconds)) {
            this.hours = hours;
            setAMPMMode();
        } else {
            System.out.println("Invalid hours input. Please provide a valid value.");
        }
    }

    public void setMinutes(int minutes) {
        if (isValidTime(this.hours, minutes, this.seconds)) {
            this.minutes = minutes;
        } else {
            System.out.println("Invalid minutes input. Please provide a valid value.");
        }
    }

    public void setSeconds(int seconds) {
        if (isValidTime(this.hours, this.minutes, seconds)) {
            this.seconds = seconds;
        } else {
            System.out.println("Invalid seconds input. Please provide a valid value.");
        }
    }
}

class Q1CG
{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int h, m, s;
        System.out.println("Enter time in h m s format : ");
        h = sc.nextInt();
        m = sc.nextInt();
        s = sc.nextInt();

        Clock clock = new Clock(h, m, s);
        clock.displayTime();


        clock.setHours(8);
        clock.setMinutes(15);
        clock.setSeconds(0);
        clock.displayTime();
    }
}
