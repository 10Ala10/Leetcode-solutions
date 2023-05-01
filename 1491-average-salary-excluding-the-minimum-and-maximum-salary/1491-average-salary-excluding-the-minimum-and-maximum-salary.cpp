class Solution {
public:
    double average(vector<int>& salarys) {
        int sum = 0;
        double avgSalary;
        int n = (int)salarys.size();
        int minSalary = *min_element(salarys.begin(), salarys.end());
        int maxSalary = *max_element(salarys.begin(), salarys.end());

        for(auto salary : salarys){
            sum += salary;
        }

        sum -= (minSalary + maxSalary);
        
        avgSalary = (double)sum / (n - 2);

        return avgSalary;
    }
};