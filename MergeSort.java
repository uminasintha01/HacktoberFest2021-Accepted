 static void merge(int[] array, int left,int mid ,int right){
   
    int[] temp;
    int i=left,j=mid+1,tempcount=left;
   
    while(i<=mid && j<=right){
      
      if(array[i]<=array[j]){
        temp[tempcount]=array[i];
        i++;
      }
      else{
        temp[k]=array[j];
        j++;
      }
      tempcount++;
    }
   
    if(i>mid){
      while(j<=right){
        temp[tempcount]=array[j];
        j++,tempcount++;
      }
    }
    else{
      while(i<=mid){
        temp[tempcount]=array[i];
        i++,tempcount++;
      }
    }
   
    for(tempcount=left;tempcount<=right;tempcount++){
      array[tempcount]=temp[tempcount];
    }
}


public static void mergeSort(int[] array, int left,int right){

    int mid;
    if(left<right){
    
          mid=(left+right)/2;
          mergeSort(array,left,mid);
          mergeSort(array,mid+1,right);
          merge(array,left,mid,right);
    }
  
}




        
      
    
