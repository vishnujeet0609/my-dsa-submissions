class MyCalendar {
    map<int,int>scheduledMeetings;
public:
    
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = scheduledMeetings.lower_bound(startTime);
        if(it!=scheduledMeetings.end() && it->first<endTime){
            
            return false;
        }
        if(it!=scheduledMeetings.begin() && prev(it)->second>startTime){
            return false;

        }
        scheduledMeetings[startTime]=endTime;
        return true;
        
    } 
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */