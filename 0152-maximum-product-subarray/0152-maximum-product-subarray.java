class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int maxi = Integer.MIN_VALUE;
        int prefixProduct = 1, suffixProduct = 1;

        for(int i = 0;i < n;i++){
            if(prefixProduct == 0) prefixProduct = 1;
            if(suffixProduct == 0) suffixProduct = 1;
            
            prefixProduct *= nums[i];
            suffixProduct *= nums[n-i-1];

            maxi = Math.max(maxi, Math.max(prefixProduct, suffixProduct));
        }

        return maxi;
    }
}