class MyCalendarTwo {
    map<int,int>bookings;
    int maxOverlappedBooking;
public:
    MyCalendarTwo() {
        maxOverlappedBooking=2;
    }
    
    bool book(int startTime, int endTime) {
        bookings[startTime]++;
        bookings[endTime]--;
        int overlappedBooking=0;
        for(auto booking:bookings){
            overlappedBooking+=booking.second;
            if(overlappedBooking>maxOverlappedBooking){
                bookings[startTime]--;
                bookings[endTime]++;
                if(bookings[startTime]==0){
                    bookings.erase(startTime);
                }
                if(bookings[endTime]==0){
                    bookings.erase(endTime);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */