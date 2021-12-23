class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 9,10 3,12 7,17 4,18 10,19 5,20 10,19
        int n = (int)(courses.size());
        sort(courses.begin(), courses.end(), [](vector<int> &A, vector<int> &B) {
            if (A[1] != B[1]) return A[1] < B[1];
            return A[0] < B[0];
        });
        int ans = 0;
        int time_now = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            int time_required = courses[i][0], course_deadline = courses[i][1];
            pq.push(time_required);
            time_now += time_required;
            if (time_now > course_deadline) {
                time_now -= pq.top();
                pq.pop();
            }
            ans = max(ans, (int)(pq.size()));
        }
        ans = max(ans, (int)(pq.size()));
        return ans;

    }
};