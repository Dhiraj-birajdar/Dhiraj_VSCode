class Clock {
    private int hours;
    private int minutes;
    private int seconds;
    private boolean isAM;

    // Constructor to initialize the time and set the mode
    public Clock(int hours, int minutes, int seconds) {
        if (isValidTime(hours, minutes, seconds)) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
            this.isAM = true; // default to AM mode
            setAMPMMode();
        } else {
            System.out.println("Invalid time input. Please provide valid hours, minutes, and seconds.");
        }
    }

    // Method to check the validity of the time
    private boolean isValidTime(int hours, int minutes, int seconds) {
        return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
    }

    // Method to set the AM/PM mode based on the time
    private void setAMPMMode() {
        if (hours >= 12) {
            isAM = false;
        } else {
            isAM = true;
        }
    }

    // Method to display the time in 12-hour format with AM/PM
    public void displayTime() {
        int displayHours = (hours == 0 || hours == 12) ? 12 : hours % 12;
        String period = isAM ? "AM" : "PM";
        System.out.printf("%02d:%02d:%02d %s%n", displayHours, minutes, seconds, period);
    }

    // Getter methods
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

    // Setter methods to update the time
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
    // Main method for testing
    public static void main(String[] args) {
        // Example usage
        Clock clock = new Clock(14, 30, 45);
        clock.displayTime();

        // Update time
        clock.setHours(8);
        clock.setMinutes(15);
        clock.setSeconds(0);
        clock.displayTime();
    }
}
