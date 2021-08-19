#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Interval {
public:
    int start, end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
    	sort(begin(intervals), end(intervals),
    			[](Interval lhs, Interval rhs) {
    		return lhs.start < rhs.start;
    	});

    	for (int i = 0; i < intervals.size() - 1; i++) {
    		if (intervals[i].end > intervals[i + 1].start) {
    			return false;
    		}
    	}

    	return true;
    }
};

ostream& operator<<(ostream& os, Interval interval) {
	os << "(" << interval.start << ", " << interval.end << ")";
	return os;
}

ostream& operator<<(ostream& os, const vector<Interval>& v) {
	os << "{";
	bool flag = false;
	for (auto n : v) {
		if (flag) {
			os << ", ";
		}
		os << n;
		flag = true;
	}
	return os << "}";
}


int main() {

	vector<Interval> intervals;
	for (int i = 1; i < 4; i++) {
		Interval interval(i, i+1);
		intervals.push_back(interval);
	}
	cout << intervals << "\n";

	Solution solution;
	cout << solution.canAttendMeetings(intervals) << "\n";

	cout << endl;
	intervals[1].start = 5;
	intervals[1].end = 30;
	intervals[2].start = 15;
	intervals[2].end = 20;
	cout << intervals << "\n";
	cout << solution.canAttendMeetings(intervals) << "\n";

	return 0;
}












