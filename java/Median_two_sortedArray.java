class Median_two_sortedArray{
  public static void main(String args[]){
    int num1[]={1,5,6};
    int num2[]={2,4,10};
    Solution s = new Solution();
   int res= s.findMedianSortedArrays(num1,num2);
    printf(res);
  }
}

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int [] num = new int[2000];
        int i=0,j=0,k=0;
        float res;
        while(i<nums1.length && j<nums2.length)
        {
            if(nums1[i]<nums2[j])
            {  num[k]=nums1[i];i++;k++;}
            else if(nums1[i]>nums2[j])
            {num[k]=nums2[j];j++;k++;
            }
            else
            {  num[k]=nums1[i];k++;num[k]=nums2[j];i++;j++;k++;}
            
        }
        while(i<nums1.length)
              {
                  num[k]=nums1[i];i++;k++;
              }
        while(j<nums2.length)
              {
                  num[k]=nums2[j];j++;k++;
              }
        if(k%2==0)
        {res=(num[k/2]+num[(k/2)-1])/(float)2;}
        else
        { res = num[(k/2)];//System.out.println("value of res "+res);}
        }
        return res;
    }
}
