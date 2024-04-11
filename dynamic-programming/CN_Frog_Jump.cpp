//https://www.naukri.com/code360/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


/* ========================== RECURSIVE ===================================*/

int frogJump(int n, vector<int> &heights)
{
    if(n==0)
        return 0;
    int oneJump = frogJump(n-1,heights) + abs(heights[n]-heights[n-1]);
    int twoJump = 0;
    if(n>1)
        twoJump = frogJump(n-2,heights) + abs(heights[n]-heights[n-2]);
    return min(oneJump,twoJump);
}