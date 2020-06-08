
int* findScali(int *prev,int part, int *tmp,int pos){


    if(prev[part]!= -1 ){
        tmp[pos]=prev[part];
        part = prev[part];
        pos++;
        tmp= findScali(prev,part,tmp,pos);


    }else{

        return tmp;
    }



}



int findMin (int* array , int n){
    int i=0;
    int min = 0;
    for ( i= 0;i <n ; i++){
        if(array[min]> array[i]){
            min = i;
        }
    }
    return min;
}






