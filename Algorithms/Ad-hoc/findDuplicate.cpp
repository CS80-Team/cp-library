int findDuplicate(int arr[] , int n)
{
    int answer=0;
      //XOR all the elements with 0
    for(int i=0; i<n; i++){
       answer=answer^arr[i];
    }
      //XOR all the elements with no from 1 to n
      // i.e   answer^0 = answer
    for(int i=1; i<n; i++){
       answer=answer^i;
    }
    return answer;
}