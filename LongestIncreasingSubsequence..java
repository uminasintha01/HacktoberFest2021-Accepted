class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lastint=-10000, cnt=0;
        for (int i=1;i<nums.size();i++){
            int count=0,c=i;
            while(c<=nums.size()){
            if(max(nums[i-1],lastint)<=nums[c]){
                lastint=nums[c];
                count++; c++;
                cnt = max(count,cnt);
            }
            else{
                lastint=max(nums[i-1],lastint);
                if(count<=0){count=0;
                }
                c++;
                continue;
            }} lastint=nums[i-1];
        } return cnt+1;
    }
};
