#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i;
        int arr[26] = {0};
        int maxi = 1;
        char ch;
        scanf("%d", &n);
        char nums[n];
        for (i = 0; i < n; i++)
        {
            scanf("%c", &nums[i]);
            scanf("%c", &nums[i]);
        }
        for (i = 0; i < n; i++)
        {
            arr[nums[i] - 'a'] += 1;
            if (arr[nums[i] - 'a'] > maxi)
            {
                ch = nums[i];
                maxi = arr[nums[i]-'a'];
            }
        }
        if(maxi == 1){
            printf("No Duplicate Present\n");
        }
        else{
            printf("%c - %d\n",ch,maxi);
        }
    }
    return 0;
}
